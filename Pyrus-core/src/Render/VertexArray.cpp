#include "VertexArray.h"

#include <GL/glew.h>

VertexArray::VertexArray()
{
	glCreateVertexArrays(1, &m_BufferID);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &m_BufferID);
}

void VertexArray::Bind() const
{
	glBindVertexArray(m_BufferID);
}

void VertexArray::UnBind() const
{
	glBindVertexArray(0);
}

void VertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer)
{
	// Not done 
}

void VertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)
{
	glBindVertexArray(m_BufferID);
	indexBuffer->Bind();

	m_IndexBuffer = indexBuffer;
}
