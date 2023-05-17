#pragma once

#include "Cicala/Input.h"

namespace Cicala {
	
	class WindowsInput :  public Input
	{
	protected:
		virtual bool IsKeyPressedImp1(int keycode) override;

		virtual bool IsMouseButtonPressedImp1(int button) override;
		virtual float GetMouseXImp1() override;
		virtual float GetMouseYImp1() override;
		virtual std::pair<float, float> GetMousePositionImp1() override;
	};
}


