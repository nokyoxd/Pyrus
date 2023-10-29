#include "OpenGLVertexArray.h"

#include <GL/glew.h>

OpenGLVertexArray::OpenGLVertexArray()
{
	glCreateVertexArrays(1, &m_BufferID);
}

OpenGLVertexArray::~OpenGLVertexArray()
{
	glDeleteVertexArrays(1, &m_BufferID);
}

void OpenGLVertexArray::Bind() const
{
	glBindVertexArray(m_BufferID);
}

void OpenGLVertexArray::UnBind() const
{
	glBindVertexArray(0);
}

void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer)
{
	// Not done 
}

void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)
{
	glBindVertexArray(m_BufferID);
	indexBuffer->Bind();

	m_IndexBuffer = indexBuffer;
}
