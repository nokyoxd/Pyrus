#pragma once

#include <ImGui/imgui.h>
#include <ImGui/imgui_internal.h>
#include <ImGui/opengl3/imgui_impl_opengl3.h>
#include <ImGui/win32/imgui_impl_win32.h>

#include "SDK/Macros.h"
#include "SDK/Datatypes.h"

enum class ERenderType : int
{
	RENDER_WINDOW = 0,
	RENDER_FOREGROUND,
	RENDER_BACKGROUND
};

class CRenderer
{
public:
	PS_API CRenderer(ERenderType _Type = ERenderType::RENDER_BACKGROUND);

	PS_API void Rect(const Vector2& _start, const Vector2& _end, Color _clr, float _rounding = 0.f, float _thickness = 1.f);
	PS_API void RectFilled(const Vector2& _start, const Vector2& _end, Color _clr, float _rounding = 0.f);
	PS_API void Line(const Vector2& _start, const Vector2& _end, Color _clr, float _thickness = 1.f);
	PS_API void Triangle(const Vector2& _p1, const Vector2& _p2, const Vector2& _p3, Color _clr, float _thickness = 1.f);
	PS_API void TriangleFilled(const Vector2& _p1, const Vector2& _p2, const Vector2& _p3, Color _clr);
	PS_API void Text(const Vector2& _pos, Color _clr, const char* _text);
private:
	ImDrawList* m_pDrawList = nullptr;
	ERenderType m_Type = ERenderType::RENDER_BACKGROUND;
};

