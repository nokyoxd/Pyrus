#pragma once

#include "OpenGLBuffer.h"

#include <memory>
#include <vector>

class OpenGLVertexArray
{
public:
	OpenGLVertexArray();
	~OpenGLVertexArray();

	void Bind() const;
	void UnBind() const;

	void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer);
	void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer);

	// hella long
	using VertexBufferVector = std::vector<std::shared_ptr<VertexBuffer>>;

	const VertexBufferVector& GetVertexBuffers() const { return m_VertexBuffers; }
	const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const { return m_IndexBuffer; }
private:
	uint32_t m_BufferID;
	uint32_t m_VertexBufferIndex = 0;

	VertexBufferVector m_VertexBuffers;
	std::shared_ptr<IndexBuffer> m_IndexBuffer;
};
