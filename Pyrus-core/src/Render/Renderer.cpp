#include "Renderer.h"

CRenderer::CRenderer(ERenderType _Type)
{
	switch (_Type)
	{
	default:
	case ERenderType::RENDER_WINDOW:
		m_pDrawList = ImGui::GetWindowDrawList();
		break;
	case ERenderType::RENDER_FOREGROUND:
		m_pDrawList = ImGui::GetForegroundDrawList();
		break;
	case ERenderType::RENDER_BACKGROUND:
		m_pDrawList = ImGui::GetBackgroundDrawList();
		break;
	}

	m_Type = _Type;
}

void CRenderer::Rect(const Vector2& _start, const Vector2& _end, Color _clr, float _rounding, float _thickness)
{
	ImVec2 start = _start.ToImVec2();
	ImVec2 end = _end.ToImVec2();
	ImColor clr = _clr.ToImColor();

	//assert(m_pDrawList == nullptr, "Invalid m_pDrawList pointer!");

	m_pDrawList->AddRect(start, end, clr, _rounding, 0, _thickness);
}

void CRenderer::RectFilled(const Vector2& _start, const Vector2& _end, Color _clr, float _rounding)
{
	ImVec2 start = _start.ToImVec2();
	ImVec2 end = _end.ToImVec2();
	ImColor clr = _clr.ToImColor();

	//assert(m_pDrawList == nullptr, "Invalid m_pDrawList pointer!");

	m_pDrawList->AddRectFilled(start, end, clr, _rounding);
}

void CRenderer::Line(const Vector2& _start, const Vector2& _end, Color _clr, float _thickness)
{
	ImVec2 start = _start.ToImVec2();
	ImVec2 end = _end.ToImVec2();
	ImColor clr = _clr.ToImColor();

	//assert(m_pDrawList == nullptr, "Invalid m_pDrawList pointer!");

	m_pDrawList->AddLine(start, end, clr, _thickness);
}

void CRenderer::Triangle(const Vector2& _p1, const Vector2& _p2, const Vector2& _p3, Color _clr, float _thickness)
{
	ImVec2 p1 = _p1.ToImVec2();
	ImVec2 p2 = _p2.ToImVec2();
	ImVec2 p3 = _p3.ToImVec2();
	ImColor clr = _clr.ToImColor();

	//assert(m_pDrawList == nullptr, "Invalid m_pDrawList pointer!");

	m_pDrawList->AddTriangle(p1, p2, p3, clr, _thickness);
}

void CRenderer::TriangleFilled(const Vector2& _p1, const Vector2& _p2, const Vector2& _p3, Color _clr)
{
	ImVec2 p1 = _p1.ToImVec2();
	ImVec2 p2 = _p2.ToImVec2();
	ImVec2 p3 = _p3.ToImVec2();
	ImColor clr = _clr.ToImColor();

	//assert(m_pDrawList == nullptr, "Invalid m_pDrawList pointer!");

	m_pDrawList->AddTriangleFilled(p1, p2, p3, clr);
}

void CRenderer::Text(const Vector2& _pos, Color _clr, const char* _text)
{
	ImVec2 pos = _pos.ToImVec2();
	ImColor clr = _clr.ToImColor();

	//assert(m_pDrawList == nullptr, "Invalid m_pDrawList pointer!");

	m_pDrawList->AddText(pos, clr, _text);
}