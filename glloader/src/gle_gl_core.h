#ifndef GLE_GL_CORE_H
#define GLE_GL_CORE_H


#ifdef __cplusplus
extern "C" {
#endif //__cplusplus



typedef struct GLeStandardCoreStruct_s
{
	void *gleVarCullFace;
	void *gleVarFrontFace;
	void *gleVarHint;
	void *gleVarLineWidth;
	void *gleVarPointSize;
	void *gleVarPolygonMode;
	void *gleVarScissor;
	void *gleVarTexParameterf;
	void *gleVarTexParameterfv;
	void *gleVarTexParameteri;
	void *gleVarTexParameteriv;
	void *gleVarTexImage1D;
	void *gleVarTexImage2D;
	void *gleVarDrawBuffer;
	void *gleVarClear;
	void *gleVarClearColor;
	void *gleVarClearStencil;
	void *gleVarClearDepth;
	void *gleVarStencilMask;
	void *gleVarColorMask;
	void *gleVarDepthMask;
	void *gleVarDisable;
	void *gleVarEnable;
	void *gleVarFinish;
	void *gleVarFlush;
	void *gleVarBlendFunc;
	void *gleVarLogicOp;
	void *gleVarStencilFunc;
	void *gleVarStencilOp;
	void *gleVarDepthFunc;
	void *gleVarPixelStoref;
	void *gleVarPixelStorei;
	void *gleVarReadBuffer;
	void *gleVarReadPixels;
	void *gleVarGetBooleanv;
	void *gleVarGetDoublev;
	void *gleVarGetError;
	void *gleVarGetFloatv;
	void *gleVarGetIntegerv;
	void *gleVarGetString;
	void *gleVarGetTexImage;
	void *gleVarGetTexParameterfv;
	void *gleVarGetTexParameteriv;
	void *gleVarGetTexLevelParameterfv;
	void *gleVarGetTexLevelParameteriv;
	void *gleVarIsEnabled;
	void *gleVarDepthRange;
	void *gleVarViewport;
	void *gleVarNewList;
	void *gleVarEndList;
	void *gleVarCallList;
	void *gleVarCallLists;
	void *gleVarDeleteLists;
	void *gleVarGenLists;
	void *gleVarListBase;
	void *gleVarBegin;
	void *gleVarBitmap;
	void *gleVarColor3b;
	void *gleVarColor3bv;
	void *gleVarColor3d;
	void *gleVarColor3dv;
	void *gleVarColor3f;
	void *gleVarColor3fv;
	void *gleVarColor3i;
	void *gleVarColor3iv;
	void *gleVarColor3s;
	void *gleVarColor3sv;
	void *gleVarColor3ub;
	void *gleVarColor3ubv;
	void *gleVarColor3ui;
	void *gleVarColor3uiv;
	void *gleVarColor3us;
	void *gleVarColor3usv;
	void *gleVarColor4b;
	void *gleVarColor4bv;
	void *gleVarColor4d;
	void *gleVarColor4dv;
	void *gleVarColor4f;
	void *gleVarColor4fv;
	void *gleVarColor4i;
	void *gleVarColor4iv;
	void *gleVarColor4s;
	void *gleVarColor4sv;
	void *gleVarColor4ub;
	void *gleVarColor4ubv;
	void *gleVarColor4ui;
	void *gleVarColor4uiv;
	void *gleVarColor4us;
	void *gleVarColor4usv;
	void *gleVarEdgeFlag;
	void *gleVarEdgeFlagv;
	void *gleVarEnd;
	void *gleVarIndexd;
	void *gleVarIndexdv;
	void *gleVarIndexf;
	void *gleVarIndexfv;
	void *gleVarIndexi;
	void *gleVarIndexiv;
	void *gleVarIndexs;
	void *gleVarIndexsv;
	void *gleVarNormal3b;
	void *gleVarNormal3bv;
	void *gleVarNormal3d;
	void *gleVarNormal3dv;
	void *gleVarNormal3f;
	void *gleVarNormal3fv;
	void *gleVarNormal3i;
	void *gleVarNormal3iv;
	void *gleVarNormal3s;
	void *gleVarNormal3sv;
	void *gleVarRasterPos2d;
	void *gleVarRasterPos2dv;
	void *gleVarRasterPos2f;
	void *gleVarRasterPos2fv;
	void *gleVarRasterPos2i;
	void *gleVarRasterPos2iv;
	void *gleVarRasterPos2s;
	void *gleVarRasterPos2sv;
	void *gleVarRasterPos3d;
	void *gleVarRasterPos3dv;
	void *gleVarRasterPos3f;
	void *gleVarRasterPos3fv;
	void *gleVarRasterPos3i;
	void *gleVarRasterPos3iv;
	void *gleVarRasterPos3s;
	void *gleVarRasterPos3sv;
	void *gleVarRasterPos4d;
	void *gleVarRasterPos4dv;
	void *gleVarRasterPos4f;
	void *gleVarRasterPos4fv;
	void *gleVarRasterPos4i;
	void *gleVarRasterPos4iv;
	void *gleVarRasterPos4s;
	void *gleVarRasterPos4sv;
	void *gleVarRectd;
	void *gleVarRectdv;
	void *gleVarRectf;
	void *gleVarRectfv;
	void *gleVarRecti;
	void *gleVarRectiv;
	void *gleVarRects;
	void *gleVarRectsv;
	void *gleVarTexCoord1d;
	void *gleVarTexCoord1dv;
	void *gleVarTexCoord1f;
	void *gleVarTexCoord1fv;
	void *gleVarTexCoord1i;
	void *gleVarTexCoord1iv;
	void *gleVarTexCoord1s;
	void *gleVarTexCoord1sv;
	void *gleVarTexCoord2d;
	void *gleVarTexCoord2dv;
	void *gleVarTexCoord2f;
	void *gleVarTexCoord2fv;
	void *gleVarTexCoord2i;
	void *gleVarTexCoord2iv;
	void *gleVarTexCoord2s;
	void *gleVarTexCoord2sv;
	void *gleVarTexCoord3d;
	void *gleVarTexCoord3dv;
	void *gleVarTexCoord3f;
	void *gleVarTexCoord3fv;
	void *gleVarTexCoord3i;
	void *gleVarTexCoord3iv;
	void *gleVarTexCoord3s;
	void *gleVarTexCoord3sv;
	void *gleVarTexCoord4d;
	void *gleVarTexCoord4dv;
	void *gleVarTexCoord4f;
	void *gleVarTexCoord4fv;
	void *gleVarTexCoord4i;
	void *gleVarTexCoord4iv;
	void *gleVarTexCoord4s;
	void *gleVarTexCoord4sv;
	void *gleVarVertex2d;
	void *gleVarVertex2dv;
	void *gleVarVertex2f;
	void *gleVarVertex2fv;
	void *gleVarVertex2i;
	void *gleVarVertex2iv;
	void *gleVarVertex2s;
	void *gleVarVertex2sv;
	void *gleVarVertex3d;
	void *gleVarVertex3dv;
	void *gleVarVertex3f;
	void *gleVarVertex3fv;
	void *gleVarVertex3i;
	void *gleVarVertex3iv;
	void *gleVarVertex3s;
	void *gleVarVertex3sv;
	void *gleVarVertex4d;
	void *gleVarVertex4dv;
	void *gleVarVertex4f;
	void *gleVarVertex4fv;
	void *gleVarVertex4i;
	void *gleVarVertex4iv;
	void *gleVarVertex4s;
	void *gleVarVertex4sv;
	void *gleVarClipPlane;
	void *gleVarColorMaterial;
	void *gleVarFogf;
	void *gleVarFogfv;
	void *gleVarFogi;
	void *gleVarFogiv;
	void *gleVarLightf;
	void *gleVarLightfv;
	void *gleVarLighti;
	void *gleVarLightiv;
	void *gleVarLightModelf;
	void *gleVarLightModelfv;
	void *gleVarLightModeli;
	void *gleVarLightModeliv;
	void *gleVarLineStipple;
	void *gleVarMaterialf;
	void *gleVarMaterialfv;
	void *gleVarMateriali;
	void *gleVarMaterialiv;
	void *gleVarPolygonStipple;
	void *gleVarShadeModel;
	void *gleVarTexEnvf;
	void *gleVarTexEnvfv;
	void *gleVarTexEnvi;
	void *gleVarTexEnviv;
	void *gleVarTexGend;
	void *gleVarTexGendv;
	void *gleVarTexGenf;
	void *gleVarTexGenfv;
	void *gleVarTexGeni;
	void *gleVarTexGeniv;
	void *gleVarFeedbackBuffer;
	void *gleVarSelectBuffer;
	void *gleVarRenderMode;
	void *gleVarInitNames;
	void *gleVarLoadName;
	void *gleVarPassThrough;
	void *gleVarPopName;
	void *gleVarPushName;
	void *gleVarClearAccum;
	void *gleVarClearIndex;
	void *gleVarIndexMask;
	void *gleVarAccum;
	void *gleVarPopAttrib;
	void *gleVarPushAttrib;
	void *gleVarMap1d;
	void *gleVarMap1f;
	void *gleVarMap2d;
	void *gleVarMap2f;
	void *gleVarMapGrid1d;
	void *gleVarMapGrid1f;
	void *gleVarMapGrid2d;
	void *gleVarMapGrid2f;
	void *gleVarEvalCoord1d;
	void *gleVarEvalCoord1dv;
	void *gleVarEvalCoord1f;
	void *gleVarEvalCoord1fv;
	void *gleVarEvalCoord2d;
	void *gleVarEvalCoord2dv;
	void *gleVarEvalCoord2f;
	void *gleVarEvalCoord2fv;
	void *gleVarEvalMesh1;
	void *gleVarEvalPoint1;
	void *gleVarEvalMesh2;
	void *gleVarEvalPoint2;
	void *gleVarAlphaFunc;
	void *gleVarPixelZoom;
	void *gleVarPixelTransferf;
	void *gleVarPixelTransferi;
	void *gleVarPixelMapfv;
	void *gleVarPixelMapuiv;
	void *gleVarPixelMapusv;
	void *gleVarCopyPixels;
	void *gleVarDrawPixels;
	void *gleVarGetClipPlane;
	void *gleVarGetLightfv;
	void *gleVarGetLightiv;
	void *gleVarGetMapdv;
	void *gleVarGetMapfv;
	void *gleVarGetMapiv;
	void *gleVarGetMaterialfv;
	void *gleVarGetMaterialiv;
	void *gleVarGetPixelMapfv;
	void *gleVarGetPixelMapuiv;
	void *gleVarGetPixelMapusv;
	void *gleVarGetPolygonStipple;
	void *gleVarGetTexEnvfv;
	void *gleVarGetTexEnviv;
	void *gleVarGetTexGendv;
	void *gleVarGetTexGenfv;
	void *gleVarGetTexGeniv;
	void *gleVarIsList;
	void *gleVarFrustum;
	void *gleVarLoadIdentity;
	void *gleVarLoadMatrixf;
	void *gleVarLoadMatrixd;
	void *gleVarMatrixMode;
	void *gleVarMultMatrixf;
	void *gleVarMultMatrixd;
	void *gleVarOrtho;
	void *gleVarPopMatrix;
	void *gleVarPushMatrix;
	void *gleVarRotated;
	void *gleVarRotatef;
	void *gleVarScaled;
	void *gleVarScalef;
	void *gleVarTranslated;
	void *gleVarTranslatef;
	void *gleVarDrawArrays;
	void *gleVarDrawElements;
	void *gleVarGetPointerv;
	void *gleVarPolygonOffset;
	void *gleVarCopyTexImage1D;
	void *gleVarCopyTexImage2D;
	void *gleVarCopyTexSubImage1D;
	void *gleVarCopyTexSubImage2D;
	void *gleVarTexSubImage1D;
	void *gleVarTexSubImage2D;
	void *gleVarBindTexture;
	void *gleVarDeleteTextures;
	void *gleVarGenTextures;
	void *gleVarIsTexture;
	void *gleVarArrayElement;
	void *gleVarColorPointer;
	void *gleVarDisableClientState;
	void *gleVarEdgeFlagPointer;
	void *gleVarEnableClientState;
	void *gleVarIndexPointer;
	void *gleVarInterleavedArrays;
	void *gleVarNormalPointer;
	void *gleVarTexCoordPointer;
	void *gleVarVertexPointer;
	void *gleVarAreTexturesResident;
	void *gleVarPrioritizeTextures;
	void *gleVarIndexub;
	void *gleVarIndexubv;
	void *gleVarPopClientAttrib;
	void *gleVarPushClientAttrib;
	void *gleVarUniformMatrix2x3fv;
	void *gleVarUniformMatrix3x2fv;
	void *gleVarUniformMatrix2x4fv;
	void *gleVarUniformMatrix4x2fv;
	void *gleVarUniformMatrix3x4fv;
	void *gleVarUniformMatrix4x3fv;
	void *gleVarActiveTexture;
	void *gleVarSampleCoverage;
	void *gleVarCompressedTexImage3D;
	void *gleVarCompressedTexImage2D;
	void *gleVarCompressedTexImage1D;
	void *gleVarCompressedTexSubImage3D;
	void *gleVarCompressedTexSubImage2D;
	void *gleVarCompressedTexSubImage1D;
	void *gleVarGetCompressedTexImage;
	void *gleVarClientActiveTexture;
	void *gleVarMultiTexCoord1d;
	void *gleVarMultiTexCoord1dv;
	void *gleVarMultiTexCoord1f;
	void *gleVarMultiTexCoord1fv;
	void *gleVarMultiTexCoord1i;
	void *gleVarMultiTexCoord1iv;
	void *gleVarMultiTexCoord1s;
	void *gleVarMultiTexCoord1sv;
	void *gleVarMultiTexCoord2d;
	void *gleVarMultiTexCoord2dv;
	void *gleVarMultiTexCoord2f;
	void *gleVarMultiTexCoord2fv;
	void *gleVarMultiTexCoord2i;
	void *gleVarMultiTexCoord2iv;
	void *gleVarMultiTexCoord2s;
	void *gleVarMultiTexCoord2sv;
	void *gleVarMultiTexCoord3d;
	void *gleVarMultiTexCoord3dv;
	void *gleVarMultiTexCoord3f;
	void *gleVarMultiTexCoord3fv;
	void *gleVarMultiTexCoord3i;
	void *gleVarMultiTexCoord3iv;
	void *gleVarMultiTexCoord3s;
	void *gleVarMultiTexCoord3sv;
	void *gleVarMultiTexCoord4d;
	void *gleVarMultiTexCoord4dv;
	void *gleVarMultiTexCoord4f;
	void *gleVarMultiTexCoord4fv;
	void *gleVarMultiTexCoord4i;
	void *gleVarMultiTexCoord4iv;
	void *gleVarMultiTexCoord4s;
	void *gleVarMultiTexCoord4sv;
	void *gleVarLoadTransposeMatrixf;
	void *gleVarLoadTransposeMatrixd;
	void *gleVarMultTransposeMatrixf;
	void *gleVarMultTransposeMatrixd;
	void *gleVarGenQueries;
	void *gleVarDeleteQueries;
	void *gleVarIsQuery;
	void *gleVarBeginQuery;
	void *gleVarEndQuery;
	void *gleVarGetQueryiv;
	void *gleVarGetQueryObjectiv;
	void *gleVarGetQueryObjectuiv;
	void *gleVarBindBuffer;
	void *gleVarDeleteBuffers;
	void *gleVarGenBuffers;
	void *gleVarIsBuffer;
	void *gleVarBufferData;
	void *gleVarBufferSubData;
	void *gleVarGetBufferSubData;
	void *gleVarMapBuffer;
	void *gleVarUnmapBuffer;
	void *gleVarGetBufferParameteriv;
	void *gleVarGetBufferPointerv;
	void *gleVarGetInteger64i_v;
	void *gleVarGetBufferParameteri64v;
	void *gleVarFramebufferTexture;
	void *gleVarDrawArraysInstanced;
	void *gleVarDrawElementsInstanced;
	void *gleVarTexBuffer;
	void *gleVarPrimitiveRestartIndex;
	void *gleVarBlendColor;
	void *gleVarBlendEquation;
	void *gleVarDrawRangeElements;
	void *gleVarTexImage3D;
	void *gleVarTexSubImage3D;
	void *gleVarCopyTexSubImage3D;
	void *gleVarColorTable;
	void *gleVarColorTableParameterfv;
	void *gleVarColorTableParameteriv;
	void *gleVarCopyColorTable;
	void *gleVarGetColorTable;
	void *gleVarGetColorTableParameterfv;
	void *gleVarGetColorTableParameteriv;
	void *gleVarColorSubTable;
	void *gleVarCopyColorSubTable;
	void *gleVarConvolutionFilter1D;
	void *gleVarConvolutionFilter2D;
	void *gleVarConvolutionParameterf;
	void *gleVarConvolutionParameterfv;
	void *gleVarConvolutionParameteri;
	void *gleVarConvolutionParameteriv;
	void *gleVarCopyConvolutionFilter1D;
	void *gleVarCopyConvolutionFilter2D;
	void *gleVarGetConvolutionFilter;
	void *gleVarGetConvolutionParameterfv;
	void *gleVarGetConvolutionParameteriv;
	void *gleVarGetSeparableFilter;
	void *gleVarSeparableFilter2D;
	void *gleVarGetHistogram;
	void *gleVarGetHistogramParameterfv;
	void *gleVarGetHistogramParameteriv;
	void *gleVarGetMinmax;
	void *gleVarGetMinmaxParameterfv;
	void *gleVarGetMinmaxParameteriv;
	void *gleVarHistogram;
	void *gleVarMinmax;
	void *gleVarResetHistogram;
	void *gleVarResetMinmax;
	void *gleVarBlendEquationSeparate;
	void *gleVarDrawBuffers;
	void *gleVarStencilOpSeparate;
	void *gleVarStencilFuncSeparate;
	void *gleVarStencilMaskSeparate;
	void *gleVarAttachShader;
	void *gleVarBindAttribLocation;
	void *gleVarCompileShader;
	void *gleVarCreateProgram;
	void *gleVarCreateShader;
	void *gleVarDeleteProgram;
	void *gleVarDeleteShader;
	void *gleVarDetachShader;
	void *gleVarDisableVertexAttribArray;
	void *gleVarEnableVertexAttribArray;
	void *gleVarGetActiveAttrib;
	void *gleVarGetActiveUniform;
	void *gleVarGetAttachedShaders;
	void *gleVarGetAttribLocation;
	void *gleVarGetProgramiv;
	void *gleVarGetProgramInfoLog;
	void *gleVarGetShaderiv;
	void *gleVarGetShaderInfoLog;
	void *gleVarGetShaderSource;
	void *gleVarGetUniformLocation;
	void *gleVarGetUniformfv;
	void *gleVarGetUniformiv;
	void *gleVarGetVertexAttribdv;
	void *gleVarGetVertexAttribfv;
	void *gleVarGetVertexAttribiv;
	void *gleVarGetVertexAttribPointerv;
	void *gleVarIsProgram;
	void *gleVarIsShader;
	void *gleVarLinkProgram;
	void *gleVarShaderSource;
	void *gleVarUseProgram;
	void *gleVarUniform1f;
	void *gleVarUniform2f;
	void *gleVarUniform3f;
	void *gleVarUniform4f;
	void *gleVarUniform1i;
	void *gleVarUniform2i;
	void *gleVarUniform3i;
	void *gleVarUniform4i;
	void *gleVarUniform1fv;
	void *gleVarUniform2fv;
	void *gleVarUniform3fv;
	void *gleVarUniform4fv;
	void *gleVarUniform1iv;
	void *gleVarUniform2iv;
	void *gleVarUniform3iv;
	void *gleVarUniform4iv;
	void *gleVarUniformMatrix2fv;
	void *gleVarUniformMatrix3fv;
	void *gleVarUniformMatrix4fv;
	void *gleVarValidateProgram;
	void *gleVarVertexAttrib1d;
	void *gleVarVertexAttrib1dv;
	void *gleVarVertexAttrib1f;
	void *gleVarVertexAttrib1fv;
	void *gleVarVertexAttrib1s;
	void *gleVarVertexAttrib1sv;
	void *gleVarVertexAttrib2d;
	void *gleVarVertexAttrib2dv;
	void *gleVarVertexAttrib2f;
	void *gleVarVertexAttrib2fv;
	void *gleVarVertexAttrib2s;
	void *gleVarVertexAttrib2sv;
	void *gleVarVertexAttrib3d;
	void *gleVarVertexAttrib3dv;
	void *gleVarVertexAttrib3f;
	void *gleVarVertexAttrib3fv;
	void *gleVarVertexAttrib3s;
	void *gleVarVertexAttrib3sv;
	void *gleVarVertexAttrib4Nbv;
	void *gleVarVertexAttrib4Niv;
	void *gleVarVertexAttrib4Nsv;
	void *gleVarVertexAttrib4Nub;
	void *gleVarVertexAttrib4Nubv;
	void *gleVarVertexAttrib4Nuiv;
	void *gleVarVertexAttrib4Nusv;
	void *gleVarVertexAttrib4bv;
	void *gleVarVertexAttrib4d;
	void *gleVarVertexAttrib4dv;
	void *gleVarVertexAttrib4f;
	void *gleVarVertexAttrib4fv;
	void *gleVarVertexAttrib4iv;
	void *gleVarVertexAttrib4s;
	void *gleVarVertexAttrib4sv;
	void *gleVarVertexAttrib4ubv;
	void *gleVarVertexAttrib4uiv;
	void *gleVarVertexAttrib4usv;
	void *gleVarVertexAttribPointer;
	void *gleVarVertexAttribDivisor;
	void *gleVarMinSampleShading;
	void *gleVarBlendEquationi;
	void *gleVarBlendEquationSeparatei;
	void *gleVarBlendFunci;
	void *gleVarBlendFuncSeparatei;
	void *gleVarBlendFuncSeparate;
	void *gleVarMultiDrawArrays;
	void *gleVarMultiDrawElements;
	void *gleVarPointParameterf;
	void *gleVarPointParameterfv;
	void *gleVarPointParameteri;
	void *gleVarPointParameteriv;
	void *gleVarFogCoordf;
	void *gleVarFogCoordfv;
	void *gleVarFogCoordd;
	void *gleVarFogCoorddv;
	void *gleVarFogCoordPointer;
	void *gleVarSecondaryColor3b;
	void *gleVarSecondaryColor3bv;
	void *gleVarSecondaryColor3d;
	void *gleVarSecondaryColor3dv;
	void *gleVarSecondaryColor3f;
	void *gleVarSecondaryColor3fv;
	void *gleVarSecondaryColor3i;
	void *gleVarSecondaryColor3iv;
	void *gleVarSecondaryColor3s;
	void *gleVarSecondaryColor3sv;
	void *gleVarSecondaryColor3ub;
	void *gleVarSecondaryColor3ubv;
	void *gleVarSecondaryColor3ui;
	void *gleVarSecondaryColor3uiv;
	void *gleVarSecondaryColor3us;
	void *gleVarSecondaryColor3usv;
	void *gleVarSecondaryColorPointer;
	void *gleVarWindowPos2d;
	void *gleVarWindowPos2dv;
	void *gleVarWindowPos2f;
	void *gleVarWindowPos2fv;
	void *gleVarWindowPos2i;
	void *gleVarWindowPos2iv;
	void *gleVarWindowPos2s;
	void *gleVarWindowPos2sv;
	void *gleVarWindowPos3d;
	void *gleVarWindowPos3dv;
	void *gleVarWindowPos3f;
	void *gleVarWindowPos3fv;
	void *gleVarWindowPos3i;
	void *gleVarWindowPos3iv;
	void *gleVarWindowPos3s;
	void *gleVarWindowPos3sv;
	void *gleVarColorMaski;
	void *gleVarGetBooleani_v;
	void *gleVarGetIntegeri_v;
	void *gleVarEnablei;
	void *gleVarDisablei;
	void *gleVarIsEnabledi;
	void *gleVarBeginTransformFeedback;
	void *gleVarEndTransformFeedback;
	void *gleVarBindBufferRange;
	void *gleVarBindBufferBase;
	void *gleVarTransformFeedbackVaryings;
	void *gleVarGetTransformFeedbackVarying;
	void *gleVarClampColor;
	void *gleVarBeginConditionalRender;
	void *gleVarEndConditionalRender;
	void *gleVarVertexAttribIPointer;
	void *gleVarGetVertexAttribIiv;
	void *gleVarGetVertexAttribIuiv;
	void *gleVarVertexAttribI1i;
	void *gleVarVertexAttribI2i;
	void *gleVarVertexAttribI3i;
	void *gleVarVertexAttribI4i;
	void *gleVarVertexAttribI1ui;
	void *gleVarVertexAttribI2ui;
	void *gleVarVertexAttribI3ui;
	void *gleVarVertexAttribI4ui;
	void *gleVarVertexAttribI1iv;
	void *gleVarVertexAttribI2iv;
	void *gleVarVertexAttribI3iv;
	void *gleVarVertexAttribI4iv;
	void *gleVarVertexAttribI1uiv;
	void *gleVarVertexAttribI2uiv;
	void *gleVarVertexAttribI3uiv;
	void *gleVarVertexAttribI4uiv;
	void *gleVarVertexAttribI4bv;
	void *gleVarVertexAttribI4sv;
	void *gleVarVertexAttribI4ubv;
	void *gleVarVertexAttribI4usv;
	void *gleVarGetUniformuiv;
	void *gleVarBindFragDataLocation;
	void *gleVarGetFragDataLocation;
	void *gleVarUniform1ui;
	void *gleVarUniform2ui;
	void *gleVarUniform3ui;
	void *gleVarUniform4ui;
	void *gleVarUniform1uiv;
	void *gleVarUniform2uiv;
	void *gleVarUniform3uiv;
	void *gleVarUniform4uiv;
	void *gleVarTexParameterIiv;
	void *gleVarTexParameterIuiv;
	void *gleVarGetTexParameterIiv;
	void *gleVarGetTexParameterIuiv;
	void *gleVarClearBufferiv;
	void *gleVarClearBufferuiv;
	void *gleVarClearBufferfv;
	void *gleVarClearBufferfi;
	void *gleVarGetStringi;
	void *gleVarVertexAttribL1d;
	void *gleVarVertexAttribL2d;
	void *gleVarVertexAttribL3d;
	void *gleVarVertexAttribL4d;
	void *gleVarVertexAttribL1dv;
	void *gleVarVertexAttribL2dv;
	void *gleVarVertexAttribL3dv;
	void *gleVarVertexAttribL4dv;
	void *gleVarVertexAttribLPointer;
	void *gleVarGetVertexAttribLdv;
	void *gleVarDrawElementsBaseVertex;
	void *gleVarDrawRangeElementsBaseVertex;
	void *gleVarDrawElementsInstancedBaseVertex;
	void *gleVarMultiDrawElementsBaseVertex;
	void *gleVarUseProgramStages;
	void *gleVarActiveShaderProgram;
	void *gleVarCreateShaderProgramv;
	void *gleVarBindProgramPipeline;
	void *gleVarDeleteProgramPipelines;
	void *gleVarGenProgramPipelines;
	void *gleVarIsProgramPipeline;
	void *gleVarGetProgramPipelineiv;
	void *gleVarProgramUniform1i;
	void *gleVarProgramUniform1iv;
	void *gleVarProgramUniform1f;
	void *gleVarProgramUniform1fv;
	void *gleVarProgramUniform1d;
	void *gleVarProgramUniform1dv;
	void *gleVarProgramUniform1ui;
	void *gleVarProgramUniform1uiv;
	void *gleVarProgramUniform2i;
	void *gleVarProgramUniform2iv;
	void *gleVarProgramUniform2f;
	void *gleVarProgramUniform2fv;
	void *gleVarProgramUniform2d;
	void *gleVarProgramUniform2dv;
	void *gleVarProgramUniform2ui;
	void *gleVarProgramUniform2uiv;
	void *gleVarProgramUniform3i;
	void *gleVarProgramUniform3iv;
	void *gleVarProgramUniform3f;
	void *gleVarProgramUniform3fv;
	void *gleVarProgramUniform3d;
	void *gleVarProgramUniform3dv;
	void *gleVarProgramUniform3ui;
	void *gleVarProgramUniform3uiv;
	void *gleVarProgramUniform4i;
	void *gleVarProgramUniform4iv;
	void *gleVarProgramUniform4f;
	void *gleVarProgramUniform4fv;
	void *gleVarProgramUniform4d;
	void *gleVarProgramUniform4dv;
	void *gleVarProgramUniform4ui;
	void *gleVarProgramUniform4uiv;
	void *gleVarProgramUniformMatrix2fv;
	void *gleVarProgramUniformMatrix3fv;
	void *gleVarProgramUniformMatrix4fv;
	void *gleVarProgramUniformMatrix2dv;
	void *gleVarProgramUniformMatrix3dv;
	void *gleVarProgramUniformMatrix4dv;
	void *gleVarProgramUniformMatrix2x3fv;
	void *gleVarProgramUniformMatrix3x2fv;
	void *gleVarProgramUniformMatrix2x4fv;
	void *gleVarProgramUniformMatrix4x2fv;
	void *gleVarProgramUniformMatrix3x4fv;
	void *gleVarProgramUniformMatrix4x3fv;
	void *gleVarProgramUniformMatrix2x3dv;
	void *gleVarProgramUniformMatrix3x2dv;
	void *gleVarProgramUniformMatrix2x4dv;
	void *gleVarProgramUniformMatrix4x2dv;
	void *gleVarProgramUniformMatrix3x4dv;
	void *gleVarProgramUniformMatrix4x3dv;
	void *gleVarValidateProgramPipeline;
	void *gleVarGetProgramPipelineInfoLog;
	void *gleVarGetProgramBinary;
	void *gleVarProgramBinary;
	void *gleVarProgramParameteri;
	void *gleVarDrawArraysIndirect;
	void *gleVarDrawElementsIndirect;
	void *gleVarVertexP2ui;
	void *gleVarVertexP2uiv;
	void *gleVarVertexP3ui;
	void *gleVarVertexP3uiv;
	void *gleVarVertexP4ui;
	void *gleVarVertexP4uiv;
	void *gleVarTexCoordP1ui;
	void *gleVarTexCoordP1uiv;
	void *gleVarTexCoordP2ui;
	void *gleVarTexCoordP2uiv;
	void *gleVarTexCoordP3ui;
	void *gleVarTexCoordP3uiv;
	void *gleVarTexCoordP4ui;
	void *gleVarTexCoordP4uiv;
	void *gleVarMultiTexCoordP1ui;
	void *gleVarMultiTexCoordP1uiv;
	void *gleVarMultiTexCoordP2ui;
	void *gleVarMultiTexCoordP2uiv;
	void *gleVarMultiTexCoordP3ui;
	void *gleVarMultiTexCoordP3uiv;
	void *gleVarMultiTexCoordP4ui;
	void *gleVarMultiTexCoordP4uiv;
	void *gleVarNormalP3ui;
	void *gleVarNormalP3uiv;
	void *gleVarColorP3ui;
	void *gleVarColorP3uiv;
	void *gleVarColorP4ui;
	void *gleVarColorP4uiv;
	void *gleVarSecondaryColorP3ui;
	void *gleVarSecondaryColorP3uiv;
	void *gleVarVertexAttribP1ui;
	void *gleVarVertexAttribP1uiv;
	void *gleVarVertexAttribP2ui;
	void *gleVarVertexAttribP2uiv;
	void *gleVarVertexAttribP3ui;
	void *gleVarVertexAttribP3uiv;
	void *gleVarVertexAttribP4ui;
	void *gleVarVertexAttribP4uiv;
	void *gleVarMapBufferRange;
	void *gleVarFlushMappedBufferRange;
	void *gleVarReleaseShaderCompiler;
	void *gleVarShaderBinary;
	void *gleVarGetShaderPrecisionFormat;
	void *gleVarDepthRangef;
	void *gleVarClearDepthf;
	void *gleVarTexImage2DMultisample;
	void *gleVarTexImage3DMultisample;
	void *gleVarGetMultisamplefv;
	void *gleVarSampleMaski;
	void *gleVarFenceSync;
	void *gleVarIsSync;
	void *gleVarDeleteSync;
	void *gleVarClientWaitSync;
	void *gleVarWaitSync;
	void *gleVarGetInteger64v;
	void *gleVarGetSynciv;
	void *gleVarCopyBufferSubData;
	void *gleVarUniform1d;
	void *gleVarUniform2d;
	void *gleVarUniform3d;
	void *gleVarUniform4d;
	void *gleVarUniform1dv;
	void *gleVarUniform2dv;
	void *gleVarUniform3dv;
	void *gleVarUniform4dv;
	void *gleVarUniformMatrix2dv;
	void *gleVarUniformMatrix3dv;
	void *gleVarUniformMatrix4dv;
	void *gleVarUniformMatrix2x3dv;
	void *gleVarUniformMatrix2x4dv;
	void *gleVarUniformMatrix3x2dv;
	void *gleVarUniformMatrix3x4dv;
	void *gleVarUniformMatrix4x2dv;
	void *gleVarUniformMatrix4x3dv;
	void *gleVarGetUniformdv;
	void *gleVarProvokingVertex;
	void *gleVarBindVertexArray;
	void *gleVarDeleteVertexArrays;
	void *gleVarGenVertexArrays;
	void *gleVarIsVertexArray;
	void *gleVarGetUniformIndices;
	void *gleVarGetActiveUniformsiv;
	void *gleVarGetActiveUniformName;
	void *gleVarGetUniformBlockIndex;
	void *gleVarGetActiveUniformBlockiv;
	void *gleVarGetActiveUniformBlockName;
	void *gleVarUniformBlockBinding;
	void *gleVarIsRenderbuffer;
	void *gleVarBindRenderbuffer;
	void *gleVarDeleteRenderbuffers;
	void *gleVarGenRenderbuffers;
	void *gleVarRenderbufferStorage;
	void *gleVarGetRenderbufferParameteriv;
	void *gleVarIsFramebuffer;
	void *gleVarBindFramebuffer;
	void *gleVarDeleteFramebuffers;
	void *gleVarGenFramebuffers;
	void *gleVarCheckFramebufferStatus;
	void *gleVarFramebufferTexture1D;
	void *gleVarFramebufferTexture2D;
	void *gleVarFramebufferTexture3D;
	void *gleVarFramebufferRenderbuffer;
	void *gleVarGetFramebufferAttachmentParameteriv;
	void *gleVarGenerateMipmap;
	void *gleVarBlitFramebuffer;
	void *gleVarRenderbufferStorageMultisample;
	void *gleVarFramebufferTextureLayer;
	void *gleVarViewportArrayv;
	void *gleVarViewportIndexedf;
	void *gleVarViewportIndexedfv;
	void *gleVarScissorArrayv;
	void *gleVarScissorIndexed;
	void *gleVarScissorIndexedv;
	void *gleVarDepthRangeArrayv;
	void *gleVarDepthRangeIndexed;
	void *gleVarGetFloati_v;
	void *gleVarGetDoublei_v;
	void *gleVarDrawTransformFeedbackStream;
	void *gleVarBeginQueryIndexed;
	void *gleVarEndQueryIndexed;
	void *gleVarGetQueryIndexediv;
	void *gleVarQueryCounter;
	void *gleVarGetQueryObjecti64v;
	void *gleVarGetQueryObjectui64v;
	void *gleVarBindFragDataLocationIndexed;
	void *gleVarGetFragDataIndex;
	void *gleVarPatchParameteri;
	void *gleVarPatchParameterfv;
	void *gleVarGenSamplers;
	void *gleVarDeleteSamplers;
	void *gleVarIsSampler;
	void *gleVarBindSampler;
	void *gleVarSamplerParameteri;
	void *gleVarSamplerParameteriv;
	void *gleVarSamplerParameterf;
	void *gleVarSamplerParameterfv;
	void *gleVarSamplerParameterIiv;
	void *gleVarSamplerParameterIuiv;
	void *gleVarGetSamplerParameteriv;
	void *gleVarGetSamplerParameterIiv;
	void *gleVarGetSamplerParameterfv;
	void *gleVarGetSamplerParameterIuiv;
	void *gleVarBindTransformFeedback;
	void *gleVarDeleteTransformFeedbacks;
	void *gleVarGenTransformFeedbacks;
	void *gleVarIsTransformFeedback;
	void *gleVarPauseTransformFeedback;
	void *gleVarResumeTransformFeedback;
	void *gleVarDrawTransformFeedback;
	void *gleVarGetSubroutineUniformLocation;
	void *gleVarGetSubroutineIndex;
	void *gleVarGetActiveSubroutineUniformiv;
	void *gleVarGetActiveSubroutineUniformName;
	void *gleVarGetActiveSubroutineName;
	void *gleVarUniformSubroutinesuiv;
	void *gleVarGetUniformSubroutineuiv;
	void *gleVarGetProgramStageiv;
}GLeStandardCoreStruct;

extern GLeStandardCoreStruct gle_CoreStruct;

void gleIntCoreInit();

#ifdef __cplusplus
}
#endif //__cplusplus


#endif //GLE_GL_CORE_H


