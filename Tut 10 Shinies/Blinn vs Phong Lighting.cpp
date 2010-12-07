#include <string>
#include <vector>
#include <stack>
#include <math.h>
#include <glloader/gl_3_2_comp.h>
#include <GL/freeglut.h>
#include "../framework/framework.h"
#include "../framework/Mesh.h"
#include "../framework/MatrixStack.h"
#include "../framework/MousePole.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#define ARRAY_COUNT( array ) (sizeof( array ) / (sizeof( array[0] ) * (sizeof( array ) != sizeof(void*) || sizeof( array[0] ) <= sizeof(void*))))

struct ProgramData
{
	GLuint theProgram;

	GLuint cameraToClipMatrixUnif;
	GLuint modelToCameraMatrixUnif;

	GLuint lightIntensityUnif;
	GLuint ambientIntensityUnif;

	GLuint normalModelToCameraMatrixUnif;
	GLuint cameraSpaceLightPosUnif;
	GLuint clipToCameraMatrixUnif;
	GLuint windowSizeUnif;
	GLuint depthRangeUnif;
	GLuint lightAttenuationUnif;
	GLuint shininessFactorUnif;

	void SetWindowData(const glm::mat4 cameraToClip, const glm::mat4 clipToCamera, int w, int h)
	{
		glUseProgram(theProgram);
		glUniformMatrix4fv(cameraToClipMatrixUnif, 1, GL_FALSE,
			glm::value_ptr(cameraToClip));
		glUniform2i(windowSizeUnif, w, h);
		glUniformMatrix4fv(clipToCameraMatrixUnif, 1, GL_FALSE,
			glm::value_ptr(clipToCamera));
		glUseProgram(0);
	}
};

struct UnlitProgData
{
	GLuint theProgram;

	GLuint objectColorUnif;
	GLuint cameraToClipMatrixUnif;
	GLuint modelToCameraMatrixUnif;

	void SetWindowData(const glm::mat4 cameraToClip)
	{
		glUseProgram(theProgram);
		glUniformMatrix4fv(cameraToClipMatrixUnif, 1, GL_FALSE,
			glm::value_ptr(cameraToClip));
		glUseProgram(0);
	}

};

float g_fzNear = 1.0f;
float g_fzFar = 1000.0f;

ProgramData g_WhitePhong;
ProgramData g_ColorPhong;

ProgramData g_WhitePhongOnly;
ProgramData g_ColorPhongOnly;

ProgramData g_WhiteBlinn;
ProgramData g_ColorBlinn;

ProgramData g_WhiteBlinnOnly;
ProgramData g_ColorBlinnOnly;

UnlitProgData g_Unlit;

UnlitProgData LoadUnlitProgram(const std::string &strVertexShader, const std::string &strFragmentShader)
{
	std::vector<GLuint> shaderList;

	shaderList.push_back(Framework::LoadShader(GL_VERTEX_SHADER, strVertexShader));
	shaderList.push_back(Framework::LoadShader(GL_FRAGMENT_SHADER, strFragmentShader));

	UnlitProgData data;
	data.theProgram = Framework::CreateProgram(shaderList);
	data.modelToCameraMatrixUnif = glGetUniformLocation(data.theProgram, "modelToCameraMatrix");
	data.cameraToClipMatrixUnif = glGetUniformLocation(data.theProgram, "cameraToClipMatrix");
	data.objectColorUnif = glGetUniformLocation(data.theProgram, "objectColor");

	return data;
}

ProgramData LoadLitProgram(const std::string &strVertexShader, const std::string &strFragmentShader)
{
	std::vector<GLuint> shaderList;

	shaderList.push_back(Framework::LoadShader(GL_VERTEX_SHADER, strVertexShader));
	shaderList.push_back(Framework::LoadShader(GL_FRAGMENT_SHADER, strFragmentShader));

	ProgramData data;
	data.theProgram = Framework::CreateProgram(shaderList);
	data.modelToCameraMatrixUnif = glGetUniformLocation(data.theProgram, "modelToCameraMatrix");
	data.cameraToClipMatrixUnif = glGetUniformLocation(data.theProgram, "cameraToClipMatrix");
	data.lightIntensityUnif = glGetUniformLocation(data.theProgram, "lightIntensity");
	data.ambientIntensityUnif = glGetUniformLocation(data.theProgram, "ambientIntensity");

	data.normalModelToCameraMatrixUnif = glGetUniformLocation(data.theProgram, "normalModelToCameraMatrix");
	data.cameraSpaceLightPosUnif = glGetUniformLocation(data.theProgram, "cameraSpaceLightPos");
	data.clipToCameraMatrixUnif = glGetUniformLocation(data.theProgram, "clipToCameraMatrix");
	data.windowSizeUnif = glGetUniformLocation(data.theProgram, "windowSize");
	data.depthRangeUnif = glGetUniformLocation(data.theProgram, "depthRange");
	data.lightAttenuationUnif = glGetUniformLocation(data.theProgram, "lightAttenuation");
	data.shininessFactorUnif = glGetUniformLocation(data.theProgram, "shininessFactor");

	return data;
}

void InitializePrograms()
{
	g_WhitePhong = LoadLitProgram("PN.vert", "PhongLighting.frag");
	g_ColorPhong = LoadLitProgram("PCN.vert", "PhongLighting.frag");

	g_WhitePhongOnly = LoadLitProgram("PN.vert", "PhongOnly.frag");
	g_ColorPhongOnly = LoadLitProgram("PCN.vert", "PhongOnly.frag");

	g_WhiteBlinn = LoadLitProgram("PN.vert", "BlinnLighting.frag");
	g_ColorBlinn = LoadLitProgram("PCN.vert", "BlinnLighting.frag");

	g_WhiteBlinnOnly = LoadLitProgram("PN.vert", "BlinnOnly.frag");
	g_ColorBlinnOnly = LoadLitProgram("PCN.vert", "BlinnOnly.frag");

	g_Unlit = LoadUnlitProgram("PosTransform.vert", "UniformColor.frag");
}

Framework::Mesh *g_pCylinderMesh = NULL;
Framework::Mesh *g_pPlaneMesh = NULL;
Framework::Mesh *g_pCubeMesh = NULL;

Framework::RadiusDef radiusDef = {5.0f, 3.0f, 200.0f, 1.5f, 0.5f};
Framework::MousePole g_mousePole(glm::vec3(0.0f, 0.5f, 0.0f), radiusDef);

namespace
{
	void MouseMotion(int x, int y)
	{
		g_mousePole.GLUTMouseMove(glm::ivec2(x, y));
		glutPostRedisplay();
	}

	void MouseButton(int button, int state, int x, int y)
	{
		g_mousePole.GLUTMouseButton(button, state, glm::ivec2(x, y));
		glutPostRedisplay();
	}

	void MouseWheel(int wheel, int direction, int x, int y)
	{
		g_mousePole.GLUTMouseWheel(direction, glm::ivec2(x, y));
		glutPostRedisplay();
	}
}

//Called after the window and OpenGL are initialized. Called exactly once, before the main loop.
void init()
{
	InitializePrograms();

	try
	{
		g_pCylinderMesh = new Framework::Mesh("UnitCylinder.xml");
		g_pPlaneMesh = new Framework::Mesh("LargePlane.xml");
		g_pCubeMesh = new Framework::Mesh("UnitCube.xml");
	}
	catch(std::exception &except)
	{
		printf(except.what());
	}

 	glutMouseFunc(MouseButton);
 	glutMotionFunc(MouseMotion);
	glutMouseWheelFunc(MouseWheel);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CW);

	const float depthZNear = 0.0f;
	const float depthZFar = 1.0f;

	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glDepthFunc(GL_LEQUAL);
	glDepthRange(depthZNear, depthZFar);
	glEnable(GL_DEPTH_CLAMP);

	glUseProgram(g_WhitePhong.theProgram);
	glUniform2f(g_WhitePhong.depthRangeUnif,depthZNear, depthZFar);
	glUseProgram(g_WhiteBlinn.theProgram);
	glUniform2f(g_WhiteBlinn.depthRangeUnif,depthZNear, depthZFar);
	glUseProgram(g_WhitePhongOnly.theProgram);
	glUniform2f(g_WhitePhongOnly.depthRangeUnif,depthZNear, depthZFar);
	glUseProgram(g_WhiteBlinnOnly.theProgram);
	glUniform2f(g_WhiteBlinnOnly.depthRangeUnif,depthZNear, depthZFar);

	glUseProgram(g_ColorPhong.theProgram);
	glUniform2f(g_ColorPhong.depthRangeUnif,depthZNear, depthZFar);
	glUseProgram(g_ColorBlinn.theProgram);
	glUniform2f(g_ColorBlinn.depthRangeUnif,depthZNear, depthZFar);
	glUseProgram(g_ColorPhongOnly.theProgram);
	glUniform2f(g_ColorPhongOnly.depthRangeUnif,depthZNear, depthZFar);
	glUseProgram(g_ColorBlinnOnly.theProgram);
	glUniform2f(g_ColorBlinnOnly.depthRangeUnif,depthZNear, depthZFar);
	glUseProgram(0);
}

static float g_fLightHeight = 1.5f;
static float g_fLightRadius = 1.0f;
static bool g_bRotateLight = true;

static float g_fRotateTime = 0.0f;
static float g_fPrevTime = 0.0f;

glm::vec4 CalcLightPosition()
{
	const float fLoopDuration = 5.0f;
	const float fScale = 3.14159f * 2.0f / fLoopDuration;

	float fCurrTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
	float fDeltaTime = fCurrTime - g_fPrevTime;
	g_fPrevTime = fCurrTime;

	if(g_bRotateLight)
		g_fRotateTime += fDeltaTime;

	float fCurrTimeThroughLoop = fmodf(g_fRotateTime, fLoopDuration);

	glm::vec4 ret(0.0f, g_fLightHeight, 0.0f, 1.0f);

	ret.x = cosf(fCurrTimeThroughLoop * fScale) * g_fLightRadius;
	ret.z = sinf(fCurrTimeThroughLoop * fScale) * g_fLightRadius;

	return ret;
}

static float g_CylYaw = 0.0f;
static float g_CylPitch = -90.0f;
static float g_CylRoll = 0.0f;

enum LightingModel
{
	LM_PHONG_SPECULAR = 0,
	LM_PHONG_ONLY,
	LM_BLINN_SPECULAR,
	LM_BLINN_ONLY,

	LM_MAX_LIGHTING_MODEL,
};

static int g_eLightModel = LM_PHONG_SPECULAR;

static bool g_bUseFragmentLighting = true;
static bool g_bDrawColoredCyl = false;
static bool g_bDrawLight = false;
static bool g_bScaleCyl = false;

const float g_fLightAttenuation = 1.2f;

class MaterialParams
{
public:
	MaterialParams()
		: m_fPhongExponent(4.0f)
		, m_fBlinnExponent(4.0f)
	{}

	operator float() const
	{
		return GetSpecularValue();
	}

	MaterialParams &operator +=(float fValue)
	{
		float &theParam = GetSpecularValue();
		theParam += fValue;

		if(theParam <= 0.0f)
			theParam = 0.0001f;

		return *this;
	}

	MaterialParams &operator -=(float fValue)
	{
		float &theParam = GetSpecularValue();
		theParam -= fValue;

		if(theParam <= 0.0f)
			theParam = 0.0001f;

		return *this;
	}

private:
	float m_fPhongExponent;
	float m_fBlinnExponent;

	float &GetSpecularValue()
	{
		switch(g_eLightModel)
		{
		case LM_PHONG_SPECULAR:
		case LM_PHONG_ONLY:
			return m_fPhongExponent;
		case LM_BLINN_SPECULAR:
		case LM_BLINN_ONLY:
			return m_fBlinnExponent;
		}

		static float fStopComplaint = 0.0f;
		return fStopComplaint;
	}

	const float &GetSpecularValue() const
	{
		switch(g_eLightModel)
		{
		case LM_PHONG_SPECULAR:
		case LM_PHONG_ONLY:
			return m_fPhongExponent;
		case LM_BLINN_SPECULAR:
		case LM_BLINN_ONLY:
			return m_fBlinnExponent;
		}

		static float fStopComplaint = 0.0f;
		return fStopComplaint;
	}
};

static MaterialParams g_matParams;

//Called to update the display.
//You should call glutSwapBuffers after all of your rendering to display what you rendered.
//If you need continuous updates of the screen, call glutPostRedisplay() at the end of the function.

void display()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if(g_pPlaneMesh && g_pCylinderMesh && g_pCubeMesh)
	{
		Framework::MatrixStack modelMatrix;
		modelMatrix.SetMatrix(g_mousePole.CalcMatrix());

		const glm::vec4 &worldLightPos = CalcLightPosition();
		const glm::vec4 &lightPosCameraSpace = modelMatrix.Top() * worldLightPos;

		ProgramData *pWhiteProg = NULL;
		ProgramData *pColorProg = NULL;

		switch(g_eLightModel)
		{
		case LM_PHONG_SPECULAR:
			pWhiteProg = &g_WhitePhong;
			pColorProg = &g_ColorPhong;
			break;
		case LM_PHONG_ONLY:
			pWhiteProg = &g_WhitePhongOnly;
			pColorProg = &g_ColorPhongOnly;
			break;
		case LM_BLINN_SPECULAR:
			pWhiteProg = &g_WhiteBlinn;
			pColorProg = &g_ColorBlinn;
			break;
		case LM_BLINN_ONLY:
			pWhiteProg = &g_WhiteBlinnOnly;
			pColorProg = &g_ColorBlinnOnly;
			break;
		}

		glUseProgram(pWhiteProg->theProgram);
		glUniform4f(pWhiteProg->lightIntensityUnif, 0.8f, 0.8f, 0.8f, 1.0f);
		glUniform4f(pWhiteProg->ambientIntensityUnif, 0.2f, 0.2f, 0.2f, 1.0f);
		glUniform3fv(pWhiteProg->cameraSpaceLightPosUnif,1, glm::value_ptr(lightPosCameraSpace));
		glUniform1f(pWhiteProg->lightAttenuationUnif, g_fLightAttenuation);
		glUniform1f(pWhiteProg->shininessFactorUnif, g_matParams);

		glUseProgram(pColorProg->theProgram);
		glUniform4f(pColorProg->lightIntensityUnif, 0.8f, 0.8f, 0.8f, 1.0f);
		glUniform4f(pColorProg->ambientIntensityUnif, 0.2f, 0.2f, 0.2f, 1.0f);
		glUniform3fv(pColorProg->cameraSpaceLightPosUnif, 1, glm::value_ptr(lightPosCameraSpace));
		glUniform1f(pColorProg->lightAttenuationUnif, g_fLightAttenuation);
		glUniform1f(pColorProg->shininessFactorUnif, g_matParams);
		glUseProgram(0);

		{
			Framework::MatrixStackPusher push(modelMatrix);

			//Render the ground plane.
			{
				Framework::MatrixStackPusher push(modelMatrix);

				glm::mat3 normMatrix(modelMatrix.Top());
				normMatrix = glm::transpose(glm::inverse(normMatrix));

				glUseProgram(pWhiteProg->theProgram);
				glUniformMatrix4fv(pWhiteProg->modelToCameraMatrixUnif, 1, GL_FALSE,
					glm::value_ptr(modelMatrix.Top()));

				glUniformMatrix3fv(pWhiteProg->normalModelToCameraMatrixUnif, 1, GL_FALSE,
					glm::value_ptr(normMatrix));
				g_pPlaneMesh->Render();
				glUseProgram(0);
			}

			//Render the Cylinder
			{
				Framework::MatrixStackPusher push(modelMatrix);

				modelMatrix.Translate(0.0f, 0.5f, 0.0f);

				modelMatrix.RotateX(g_CylPitch);
				modelMatrix.RotateY(g_CylYaw);
				modelMatrix.RotateZ(g_CylRoll);

				if(g_bScaleCyl)
					modelMatrix.Scale(1.0f, 1.0f, 0.2f);

				glm::mat3 normMatrix(modelMatrix.Top());
				normMatrix = glm::transpose(glm::inverse(normMatrix));

				ProgramData *pProg = g_bDrawColoredCyl ? pColorProg : pWhiteProg;
				glUseProgram(pProg->theProgram);
				glUniformMatrix4fv(pProg->modelToCameraMatrixUnif, 1, GL_FALSE,
					glm::value_ptr(modelMatrix.Top()));

				glUniformMatrix3fv(pProg->normalModelToCameraMatrixUnif, 1, GL_FALSE,
					glm::value_ptr(normMatrix));

				if(g_bDrawColoredCyl)
					g_pCylinderMesh->Render("tint");
				else
					g_pCylinderMesh->Render("flat");

				glUseProgram(0);
			}

			//Render the light
			if(g_bDrawLight)
			{
				Framework::MatrixStackPusher push(modelMatrix);

				modelMatrix.Translate(glm::vec3(worldLightPos));
				modelMatrix.Scale(0.1f, 0.1f, 0.1f);

				glUseProgram(g_Unlit.theProgram);
				glUniformMatrix4fv(g_Unlit.modelToCameraMatrixUnif, 1, GL_FALSE,
					glm::value_ptr(modelMatrix.Top()));
				glUniform4f(g_Unlit.objectColorUnif, 0.8078f, 0.8706f, 0.9922f, 1.0f);
				g_pCubeMesh->Render("flat");
			}
		}
	}

	glutPostRedisplay();
	glutSwapBuffers();
}


//Called whenever the window is resized. The new window size is given, in pixels.
//This is an opportunity to call glViewport or glScissor to keep up with the change in size.
void reshape (int w, int h)
{
	Framework::MatrixStack persMatrix;
	persMatrix.Perspective(45.0f, (h / (float)w), g_fzNear, g_fzFar);
	const glm::mat4 &invMat = glm::inverse(persMatrix.Top());

	g_WhitePhong.SetWindowData(persMatrix.Top(), invMat, w, h);
	g_WhiteBlinn.SetWindowData(persMatrix.Top(), invMat, w, h);
	g_WhitePhongOnly.SetWindowData(persMatrix.Top(), invMat, w, h);
	g_WhiteBlinnOnly.SetWindowData(persMatrix.Top(), invMat, w, h);

	g_ColorPhong.SetWindowData(persMatrix.Top(), invMat, w, h);
	g_ColorBlinn.SetWindowData(persMatrix.Top(), invMat, w, h);
	g_ColorPhongOnly.SetWindowData(persMatrix.Top(), invMat, w, h);
	g_ColorBlinnOnly.SetWindowData(persMatrix.Top(), invMat, w, h);

	g_Unlit.SetWindowData(persMatrix.Top());

	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glutPostRedisplay();
}

static const char *strLightModelNames[] =
{
	"Phong Specular.",
	"Phong Only",
	"Blinn Specular.",
	"Blinn Only",
};


//Called whenever a key on the keyboard was pressed.
//The key is given by the ''key'' parameter, which is in ASCII.
//It's often a good idea to have the escape key (ASCII value 27) call glutLeaveMainLoop() to 
//exit the program.
void keyboard(unsigned char key, int x, int y)
{
	bool bChangedShininess = false;
	bool bChangedLightModel = false;
	switch (key)
	{
	case 27:
		delete g_pPlaneMesh;
		delete g_pCylinderMesh;
		delete g_pCubeMesh;
		glutLeaveMainLoop();
		break;
	case 'w': g_CylPitch -= 11.25f; break;
	case 's': g_CylPitch += 11.25f; break;
	case 'd': g_CylRoll -= 11.25f; break;
	case 'a': g_CylRoll += 11.25f; break;
	case 'e': g_CylYaw -= 11.25f; break;
	case 'q': g_CylYaw += 11.25f; break;
	case 'W': g_CylPitch -= 4.0f; break;
	case 'S': g_CylPitch += 4.0f; break;
	case 'D': g_CylRoll -= 4.0f; break;
	case 'A': g_CylRoll += 4.0f; break;
	case 'E': g_CylYaw -= 4.0f; break;
	case 'Q': g_CylYaw += 4.0f; break;
		
	case 32:
		g_bDrawColoredCyl = !g_bDrawColoredCyl;
		printf("Yaw: %f, Pitch: %f, Roll: %f\n", g_CylYaw, g_CylPitch, g_CylRoll);
		break;

	case 'i': g_fLightHeight += 0.2f; break;
	case 'k': g_fLightHeight -= 0.2f; break;
	case 'l': g_fLightRadius += 0.2f; break;
	case 'j': g_fLightRadius -= 0.2f; break;
	case 'I': g_fLightHeight += 0.05f; break;
	case 'K': g_fLightHeight -= 0.05f; break;
	case 'L': g_fLightRadius += 0.05f; break;
	case 'J': g_fLightRadius -= 0.05f; break;

	case 'o': g_matParams += 0.5f; bChangedShininess = true; break;
	case 'u': g_matParams -= 0.5f; bChangedShininess = true; break;
	case 'O': g_matParams += 0.1f; bChangedShininess = true; break;
	case 'U': g_matParams -= 0.1f; bChangedShininess = true; break;

	case 'y': g_bDrawLight = !g_bDrawLight; break;
	case 't': g_bScaleCyl = !g_bScaleCyl; break;
	case 'b': g_bRotateLight = !g_bRotateLight; break;
	case 'h':
		g_eLightModel += 2;
		g_eLightModel %= LM_MAX_LIGHTING_MODEL;
		bChangedLightModel = true;
		break;
	case 'H':
		if(g_eLightModel % 2)
			g_eLightModel -= 1;
		else
			g_eLightModel += 1;
		g_eLightModel %= LM_MAX_LIGHTING_MODEL;
		bChangedLightModel = true;
		break;
	}

	if(g_fLightRadius < 0.2f)
		g_fLightRadius = 0.2f;

	if(bChangedShininess)
		printf("Shiny: %f\n", (float)g_matParams);

	if(bChangedLightModel)
		printf("%s\n", strLightModelNames[g_eLightModel]);

	glutPostRedisplay();
}


