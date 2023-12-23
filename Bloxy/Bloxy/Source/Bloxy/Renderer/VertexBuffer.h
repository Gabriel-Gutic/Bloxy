#pragma once


namespace Bloxy
{
	class VertexBuffer
	{
	public:
		VertexBuffer() = default;
		virtual ~VertexBuffer() = default;

		virtual void Bind() = 0;

		template <typename T, size_t SIZE>
		void SetData(std::array<T, SIZE> data, uint32_t count);
	protected:
		virtual void SetRawData(void* data, uint32_t size) = 0;
	};

	template<typename T, size_t SIZE>
	inline void VertexBuffer::SetData(std::array<T, SIZE> data, uint32_t count)
	{
		SetRawData(data.data(), count * sizeof(T));
	}
}