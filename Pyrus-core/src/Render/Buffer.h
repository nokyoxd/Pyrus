#pragma once

#include <memory>

class VertexBuffer
{
public:
	virtual ~VertexBuffer() = default;

	virtual void Bind() const = 0;
	virtual void UnBind() const = 0;

	virtual void SetData(const void* data, uint32_t size) = 0;

	static std::unique_ptr<VertexBuffer> Create(uint32_t size);
	static std::unique_ptr<VertexBuffer> Create(float* verts, uint32_t size);
};

class IndexBuffer
{
public:
	virtual ~IndexBuffer() = default;

	virtual void Bind() const = 0;
	virtual void UnBind() const = 0;

	virtual uint32_t GetCount() const = 0;

	static std::unique_ptr<IndexBuffer> Create(uint32_t* inds, uint32_t count);
};

class UniformBuffer
{

};
