#pragma once


// TODO: Implement the other functions of the class
namespace Bloxy
{
	enum class FileType
	{
		None = 0,
		Read = 0x01,
		Write = 0x02,
		Append = 0x08,
		Binary = 0x20,
	};

	class File
	{
	public:
		File(std::string_view filepath, FileType type = FileType::Read);
		~File();

		std::string Read();

		static bool Exist(std::string_view filepath);
	private:
		std::string m_Path;
		FileType m_Type;

		std::unique_ptr<std::fstream> m_Buffer;
	};
}