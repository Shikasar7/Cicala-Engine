#include "ccpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Cicala {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}