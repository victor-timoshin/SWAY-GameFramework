#ifndef FILE_H
#define FILE_H

#include "../../Platform.h"

namespace Core
{
	namespace Utils
	{
		CORE_API void ToLowercase(std::string& str);

		CORE_API bool FileExists(const std::string& name);

		/// <summary>�������� ���������� �����.</summary>
		/// <param name="name">��� �����.</param>
		CORE_API std::string GetFileExtension(std::string name);
	}
}

#endif // FILE_H