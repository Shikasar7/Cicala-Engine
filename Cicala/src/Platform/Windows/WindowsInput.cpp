#include "ccpch.h"
#include "WindowsInput.h"

#include "Cicala/Core/Application.h"
#include <GLFW/glfw3.h>


namespace Cicala{

	Input* Input::s_Instance = new WindowsInput();


	bool WindowsInput::IsKeyPressedImp1(int keycode)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}
	bool WindowsInput::IsMouseButtonPressedImp1(int button)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, button);
		return state == GLFW_PRESS;
	}
	float WindowsInput::GetMouseXImp1()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		return (float)xpos;

		//in C++ 17 , it can be like:
		/*
		auto[x,y] = GetMousePositionImp1();
		return x;
		*/
	}
	float WindowsInput::GetMouseYImp1()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		return (float)ypos;
	}
	std::pair<float, float> WindowsInput::GetMousePositionImp1()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		return { (float)xpos,(float)ypos };
	}
}