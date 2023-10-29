#include "Buffer.h"

#include "OpenGL/OpenGLBuffer.h"

std::unique_ptr<VertexBuffer> VertexBuffer::Create(uint32_t size)
{
	return std::make_unique<OpenGLVertexBuffer>(size);
}

std::unique_ptr<VertexBuffer> VertexBuffer::Create(float* verts, uint32_t size)
{
	return std::make_unique<OpenGLVertexBuffer>(verts, size);
}

std::unique_ptr<IndexBuffer> IndexBuffer::Create(uint32_t* inds, uint32_t count)
{
	return std::make_unique<OpenGLIndexBuffer>(inds, count);
}