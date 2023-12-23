#include "pchBloxy.h"
#include "File.h"


namespace Bloxy
{
	File::File(std::string_view filepath, FileType type)
		:m_Path(filepath), m_Type(type)
	{
		m_Buffer = std::make_unique<std::fstream>(filepath.data(), (int)type);
		BLOXY_ASSERT(m_Buffer->good(), "File '{0}' was not found!", filepath.data());
	}

	File::~File()
	{
		m_Buffer->close();
	}

	std::string File::Read()
	{
		BLOXY_ASSERT(m_Type == FileType::Read, "You can not read from file '{0}'", m_Path);

		std::stringstream ss;
		ss << m_Buffer->rdbuf();

		return ss.str();
	}

	bool File::Exist(std::string_view filepath)
	{
		std::ifstream file(filepath.data());
		return file.good();
	}
}