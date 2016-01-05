#ifndef FILE_H
#define FILE_H

#include "../../Platform.h"

namespace Core
{
	namespace Utils
	{
#pragma region StringHelper

		CORE_API std::string ToLower(const std::string& text);

		CORE_API std::string ToUpper(const std::string& text);

		CORE_API bool Compare(const char* const str1, const char* const str2);

		CORE_API bool CompareCaseInsensitive(std::string str1, std::string str2);

		CORE_API int ToInt(const std::string& text);

		CORE_API UInt ToUInt(const std::string& text);

		CORE_API float ToFloat(const std::string& text);

		CORE_API std::string IntToString(const int& number);

		CORE_API std::string UIntToString(const UInt& number);

		CORE_API std::string FloatToString(const float& number);

#pragma endregion

		CORE_API bool FileExists(const std::string& name);

		/// <summary>Получает расширение файла.</summary>
		/// <param name="name">Имя файла.</param>
		CORE_API std::string GetFileExtension(std::string name);
	}
}

#endif // FILE_H