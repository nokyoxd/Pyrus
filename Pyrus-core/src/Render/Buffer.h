#pragma once
#include <cstdint>

class VertexBuffer
{
public:
	VertexBuffer(uint32_t size);
	VertexBuffer(float* verts, uint32_t size);
	~VertexBuffer();

	void Bind() const;
	void UnBind() const;

	void SetData(const void* data, uint32_t size);
private:
	uint32_t m_BufferID;
};

class IndexBuffer
{
public:
	IndexBuffer(uint32_t* inds, uint32_t count);
	~IndexBuffer();

	void Bind() const;
	void UnBind() const;

	uint32_t GetCount() const { return m_Count; }
private:
	uint32_t m_BufferID;
	uint32_t m_Count;
};

class UniformBuffer
{
public:
	UniformBuffer(uint32_t size, uint32_t binding);
	~UniformBuffer();

	void SetData(const void* data, uint32_t size, uint32_t offset = 0);
private:
	uint32_t m_BufferID = 0;
};