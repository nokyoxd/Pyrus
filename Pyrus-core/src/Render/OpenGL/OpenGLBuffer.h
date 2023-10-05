#pragma once

#include "Render/Buffer.h"

#include <cstdint>

class OpenGLVertexBuffer : public VertexBuffer
{
public:
	OpenGLVertexBuffer(uint32_t size);
	OpenGLVertexBuffer(float* verts, uint32_t size);
	~OpenGLVertexBuffer();

	void Bind() const;
	void UnBind() const;

	void SetData(const void* data, uint32_t size);
private:
	uint32_t m_BufferID;
};

class OpenGLIndexBuffer : public IndexBuffer
{
public:
	OpenGLIndexBuffer(uint32_t* inds, uint32_t count);
	~OpenGLIndexBuffer();

	void Bind() const;
	void UnBind() const;

	uint32_t GetCount() const { return m_Count; }
private:
	uint32_t m_BufferID;
	uint32_t m_Count;
};

class OpenGLUniformBuffer : public UniformBuffer
{
public:
	OpenGLUniformBuffer(uint32_t size, uint32_t binding);
	~OpenGLUniformBuffer();

	void SetData(const void* data, uint32_t size, uint32_t offset = 0);
private:
	uint32_t m_BufferID = 0;
};