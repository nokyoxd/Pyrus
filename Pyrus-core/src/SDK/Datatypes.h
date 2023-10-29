#pragma once

#include <imgui/imgui.h>

struct Vector2
{
	constexpr Vector2() : x(0.f), y(0.f) { }
	constexpr Vector2(float _x, float _y) : x(_x), y(_y) { }

	Vector2 operator+(const Vector2& _vec) const
	{
		return Vector2(x + _vec.x, y + _vec.y);
	}

	Vector2 operator-(const Vector2& _vec) const
	{
		return Vector2(x - _vec.x, y - _vec.y);
	}

	Vector2 operator*(const Vector2& _vec) const
	{
		return Vector2(x * _vec.x, y * _vec.y);
	}

	Vector2 operator/(const Vector2& _vec) const
	{
		return Vector2(x / _vec.x, y / _vec.y);
	}

	ImVec2 ToImVec2() const { return ImVec2(x, y); }

	float x, y;
};

struct Vector3
{
	constexpr Vector3() : x(0.f), y(0.f), z(0.f) { }
	constexpr Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) { }

	Vector3 operator+(const Vector3& _vec) const
	{
		return Vector3(x + _vec.x, y + _vec.y, z + _vec.z);
	}

	Vector3 operator-(const Vector3& _vec) const
	{
		return Vector3(x - _vec.x, y - _vec.y, z + _vec.z);
	}

	Vector3 operator*(const Vector3& _vec) const
	{
		return Vector3(x * _vec.x, y * _vec.y, z + _vec.z);
	}

	Vector3 operator/(const Vector3& _vec) const
	{
		return Vector3(x / _vec.x, y / _vec.y, z + _vec.z);
	}

	float x, y, z;
};

struct Color
{
	constexpr Color() : r(0.f), g(0.f), b(0.f), a(1.f) { }

	constexpr Color(float _r, float _g, float _b, float _a = 1.f) : r(_r), g(_g), b(_b), a(_a) { }
	constexpr Color(int _r, int _g, int _b, int _a = 255) :
		r(_r / 255), g(_g / 255), b(_b / 255), a(_a / 255) { }

	ImColor ToImColor() const { return ImColor(r, g, b, a); }

	float r, g, b, a;
};