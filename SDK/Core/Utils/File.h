#ifndef FILE_H
#define FILE_H

#include "../../Platform.h"

namespace Core
{
	namespace Utils
	{
		CORE_API void ToLowercase(std::string& str);

		CORE_API bool FileExists(const std::string& name);

		/// <summary>Получает расширение файла.</summary>
		/// <param name="name">Имя файла.</param>
		CORE_API std::string GetFileExtension(std::string name);
	}
}

#endif // FILE_H