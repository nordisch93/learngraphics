require "SvgWriter"
require "vmath"

local imageWidth = 600;
local imageHeight = 500;
local imageSize = vmath.vec2(imageWidth, imageHeight);

local worldBox = 4;

local worldExtents = {-worldBox / 2, worldBox / 2}

local function TransformPoint(tPoint)
	if(vmath.vtype(tPoint) == "table") then
		local ret = {}
		for i, realPoint in ipairs(tPoint) do
			ret[i] = TransformPoint(realPoint)
		end
		return ret;
	end

	local final = vmath.vec2(tPoint);
	final.y = -final.y;
	final = final - worldExtents[1];
	if(imageWidth > imageHeight) then
		final = final * (imageHeight / worldBox);
		final = final + vmath.vec2((imageWidth - imageHeight) / 2, 0.0); --Allow for centering a rectangular image size.
	else
		final = final * (imageWidth / worldBox);
		final = final + vmath.vec2(0.0, (imageHeight - imageWidth) / 2); --Allow for centering a rectangular image size.
		print(tPoint, final)
	end

	return final;
end

local function ProjectPoint(tPoint, projection)
	if(vmath.vtype(tPoint) == "table") then
		local ret = {}
		for i, realPoint in ipairs(tPoint) do
			ret[i] = ProjectPoint(realPoint, projection)
		end
		return ret;
	end

	return vmath.vec2(tPoint.x, projection.lineLoc.y);
end


----------------------------------
-- Styles
local styleLib = SvgWriter.StyleLibrary();

styleLib:AddStyle(nil, "black",
	SvgWriter.Style():stroke("black"));
	
styleLib:AddStyle(nil, "red",
	SvgWriter.Style():stroke("red"));
	
styleLib:AddStyle(nil, "line_of_proj",
	SvgWriter.Style():stroke("red"):stroke_width("1px"):stroke_dasharray({4, 8}));
	
styleLib:AddStyle(nil, "object",
	SvgWriter.Style():stroke("#00C000"):stroke_width("1px"));
	
styleLib:AddStyle(nil, "object_projected",
	SvgWriter.Style():stroke("#00C000"):stroke_width("8px"));
	
styleLib:AddStyle(nil, "line_standard",
	SvgWriter.Style():stroke_width("1px"));
	
styleLib:AddStyle(nil, "projected",
	SvgWriter.Style():stroke_width("8px"));
	
styleLib:AddStyle(nil, "dashed",
	SvgWriter.Style():stroke_dasharray({4, 8}));
	
	
styleLib:AddStyle(nil, "fill_black",
	SvgWriter.Style():fill("black"));
	
styleLib:AddStyle(nil, "fill_transluscent",
	SvgWriter.Style():fill("blue"):fill_opacity(0.1));

styleLib:AddStyle(nil, "fill_none",
	SvgWriter.Style():fill("none"));
	
styleLib:AddStyle(nil, "background",
	SvgWriter.Style():fill("#E0E0E0"):stroke("none"));
	

----------------------------------
-- Point setup.

local lineProjection = {}
lineProjection.lineLoc = vmath.vec2(0.0, worldExtents[1] * 0.5);
lineProjection.lineWidth = 2.0;
lineProjection.lineEndPts =
{
	vmath.vec2(-lineProjection.lineWidth / 2, lineProjection.lineLoc.y),
	vmath.vec2(lineProjection.lineWidth / 2, lineProjection.lineLoc.y),
}
lineProjection.finalEndPts = TransformPoint(lineProjection.lineEndPts)

local sideProjLines = {}
sideProjLines[1] = vmath.vec2(lineProjection.lineEndPts[1])
sideProjLines[1].x = worldExtents[1];
sideProjLines[2] = vmath.vec2(lineProjection.lineEndPts[2])
sideProjLines[2].x = worldExtents[2];

sideProjLines = TransformPoint(sideProjLines);

local projectRect =
{
	vmath.vec2(lineProjection.finalEndPts[1].x, 0),
	vmath.vec2(lineProjection.finalEndPts[2].x - lineProjection.finalEndPts[1].x, lineProjection.finalEndPts[2].y),
}


local rectShape =
{
	vmath.vec2(0.8, 0.0),
	vmath.vec2(0.5, 1.5),
}

local rectProj = ProjectPoint(rectShape, lineProjection)

rectShape = TransformPoint(rectShape);
rectProj = TransformPoint(rectProj);

local rectProjOffset = {}
for i, tPoint in ipairs(rectProj) do
	rectProjOffset[i] = tPoint + vmath.vec2(0, -1);
end

local lineShape =
{
	vmath.vec2(-0.3, -0.25),
	vmath.vec2(-1.75, 1.25),
}

local lineProj = ProjectPoint(lineShape, lineProjection)

lineShape = TransformPoint(lineShape)
lineProj = TransformPoint(lineProj);


----------------------------------------
-- The SVG itself
local writer = SvgWriter.SvgWriter("Ortho2DProjection.svg", {imageWidth .."px", imageHeight .. "px"});
	writer:StyleLibrary(styleLib);
	writer:BeginDefinitions();
	writer:EndDefinitions();
	
	--Background
	writer:Rect(projectRect[1], projectRect[2], nil, {"background"});
	--Projection
	writer:Line(rectProj[1], rectShape[1], {"line_of_proj"});
	writer:Line(rectProj[2], vmath.vec2(rectShape[2].x, rectShape[1].y), {"line_of_proj"});
	writer:Line(rectProj[1], rectProj[2], {"object_projected"});
	
	writer:Line(lineShape[1], lineProj[1], {"line_of_proj"});
	writer:Line(lineShape[2], lineProj[2], {"line_of_proj"});
	writer:Line(lineProj[1], lineProj[2], {"object_projected"});

	--Draw shapes.
	writer:Rect(rectShape[2], rectShape[1] - rectShape[2], nil, {"object", "fill_none"});
	writer:Line(lineShape[1], lineShape[2], {"object"});
	
	
	--Draw the projection plane.
	writer:Line(lineProjection.finalEndPts[1], lineProjection.finalEndPts[2], {"black", "line_standard"});
	writer:Line(lineProjection.finalEndPts[1], sideProjLines[1], {"black", "line_standard", "dashed"});
	writer:Line(lineProjection.finalEndPts[2], sideProjLines[2], {"black", "line_standard", "dashed"});

--[[	
	--Debug: Box around the world.
	local tempPt = TransformPoint(vmath.vec2(worldExtents[1], worldExtents[2]));
	writer:Rect(tempPt, TransformPoint(vmath.vec2(worldExtents[2], worldExtents[1])) - tempPt,
		nil, {"black", "line_standard", "fill_none"});
		]]
writer:Close();

	
	
	
