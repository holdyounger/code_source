#pragma once
#include <Windows.h>
#include <string>

namespace BaseFlow
{
	namespace Attribute
	{
		bool	GetFileDescription(const std::string& szModuleName, std::string& RetStr);
		bool	GetFileVersion(const std::string& szModuleName, std::string& RetStr);
		bool	GetInternalName(const std::string& szModuleName, std::string& RetStr);
		bool	GetCompanyName(const std::string& szModuleName, std::string& RetStr);
		bool	GetLegalCopyright(const std::string& szModuleName, std::string& RetStr);
		bool	GetOriginalFilename(const std::string& szModuleName, std::string& RetStr);
		bool	GetProductName(const std::string& szModuleName, std::string& RetStr);
		bool	GetProductVersion(const std::string& szModuleName, std::string& RetStr);
	}
}