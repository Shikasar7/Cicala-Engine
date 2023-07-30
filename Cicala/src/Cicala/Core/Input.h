#pragma once

#include "Cicala/Core/Core.h"

namespace Cicala {

	class CICALA_API Input
	{
	protected:
		Input() = default;
	public:
		Input(const Input&) = delete;
		Input& operator=(const Input&) = delete;

		inline static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedImp1(keycode); }
		
		inline static bool IsMouseButtonPressed(int button) { return s_Instance->IsMouseButtonPressedImp1(button); }
		inline static float GetMouseX() { return s_Instance->GetMouseXImp1(); }
		inline static float GetMouseY() { return s_Instance->GetMouseYImp1(); }
		inline static std::pair<float,float> GetMousePosition() { return s_Instance->GetMousePositionImp1(); }

	protected:
		virtual bool IsKeyPressedImp1(int keycode) = 0;

		virtual bool IsMouseButtonPressedImp1(int button) = 0;
		virtual float GetMouseXImp1() = 0;
		virtual float GetMouseYImp1() = 0;
		virtual std::pair<float, float> GetMousePositionImp1() = 0;

	private:
		static Input* s_Instance;
	};
}