#pragma once


namespace Bloxy
{
	class IndexBuffer
	{
	public:
		IndexBuffer() = default;
		virtual ~IndexBuffer() = default;

		virtual void Bind() = 0;

		template <size_t SIZE>
		void SetData(std::array<uint32_t, SIZE> data, uint32_t count);
	protected:
		virtual void SetRawData(uint32_t* data, uint32_t size) = 0;
	};

	template<size_t SIZE>
	inline void IndexBuffer::SetData(std::array<uint32_t, SIZE> data, uint32_t count)
	{
		SetRawData(data.data(), count * sizeof(uint32_t));
	}
}