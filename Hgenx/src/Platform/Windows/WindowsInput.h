#pragma once

#include "Hgenx/Input.h"

namespace Hgenx
{
	class WindowsInput : public Input
	{
	public:
		virtual ~WindowsInput() = default;

	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;
		virtual bool IsMouseButtonPressedImpl(int button) override;
		virtual std::pair<float, float> GetMousePositionImpl() override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
	};

} // end of namespace
