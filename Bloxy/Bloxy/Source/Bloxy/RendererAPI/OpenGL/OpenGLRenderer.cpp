#include "pchBloxy.h"
#include "OpenGLRenderer.h"

#include "Renderer/Vertex.h"
#include "OpenGLBufferLayout.h"
#include "OpenGLVertexArray.h"
#include "OpenGLShaderprogram.h"

#include <glad/glad.h>

#define MAX_VERTEX_COUNT 1024
#define MAX_INDEX_COUNT 2 * MAX_VERTEX_COUNT

namespace Bloxy
{
	struct OpenGLRendererData
	{
		std::array<Vertex, MAX_VERTEX_COUNT> Vertices = {};
		uint32_t VertexCount = 0;
		std::array<uint32_t, MAX_INDEX_COUNT> Indices = {};
		uint32_t IndexCount = 0;
	};
	static OpenGLRendererData RendererData = {};

	OpenGLRenderer::OpenGLRenderer()
	{
		OpenGLBufferLayout layout;
		layout.PushFloat(3);
		layout.PushFloat(4);

		m_VertexArray = std::make_unique<OpenGLVertexArray>(layout, MAX_VERTEX_COUNT * sizeof(Vertex), MAX_INDEX_COUNT * sizeof(uint32_t));

		m_ShaderProgram = std::make_unique<OpenGLShaderProgram>("Assets/OpenGL/Shaders/VertexShader.glsl", "Assets/OpenGL/Shaders/FragmentShader.glsl");
	}

	OpenGLRenderer::~OpenGLRenderer()
	{
		
	}

	void OpenGLRenderer::Begin()
	{
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGLRenderer::End()
	{
		Flush();
	}

	void OpenGLRenderer::Flush()
	{
		m_ShaderProgram->Use();

		m_VertexArray->Bind();
		m_VertexArray->GetIndexBuffer()->SetData(RendererData.Indices, RendererData.IndexCount);
		m_VertexArray->GetVertexBuffer()->SetData(RendererData.Vertices, RendererData.VertexCount);

		glDrawElements(GL_TRIANGLES, RendererData.IndexCount, GL_UNSIGNED_INT, nullptr);
	
		RendererData.VertexCount = 0;
		RendererData.IndexCount = 0;
	}

	void OpenGLRenderer::_DrawQuad()
	{
		RendererData.Indices[RendererData.IndexCount++] = RendererData.VertexCount;
		RendererData.Indices[RendererData.IndexCount++] = RendererData.VertexCount + 1;
		RendererData.Indices[RendererData.IndexCount++] = RendererData.VertexCount + 2;
		RendererData.Indices[RendererData.IndexCount++] = RendererData.VertexCount + 2;
		RendererData.Indices[RendererData.IndexCount++] = RendererData.VertexCount + 1;
		RendererData.Indices[RendererData.IndexCount++] = RendererData.VertexCount + 3;

		RendererData.Vertices[RendererData.VertexCount++] = Vector3(-0.5f, -0.5f, 0.0f);
		RendererData.Vertices[RendererData.VertexCount++] = Vector3( 0.5f, -0.5f, 0.0f);
		RendererData.Vertices[RendererData.VertexCount++] = Vector3(-0.5f,  0.5f, 0.0f);
		RendererData.Vertices[RendererData.VertexCount++] = Vector3( 0.5f,  0.5f, 0.0f);
	}
}