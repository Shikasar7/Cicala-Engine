#include "ccpch.h"
#include "OpenGLContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <GL/GL.h>

namespace Cicala {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		CC_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		CC_CORE_ASSERT(status, "Failed to initialize Glad!")

		CC_CORE_INFO("OpenGL Info:");

		CC_CORE_INFO("  Vendor: {0}", std::string(reinterpret_cast<const char*>(glGetString(GL_VENDOR))));
		CC_CORE_INFO("  Renderer: {0}", std::string(reinterpret_cast<const char*>(glGetString(GL_RENDERER))));
		CC_CORE_INFO("  Version: {0}", std::string(reinterpret_cast<const char*>(glGetString(GL_VERSION))));
		/*
		CC_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		CC_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		CC_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
		*/

#ifdef CC_ENABLE_ASSERTS
		int versionMajor;
		int versionMinor;
		glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
		glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

		CC_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "Hazel requires at least OpenGL version 4.5!");
#endif
	}
	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}

