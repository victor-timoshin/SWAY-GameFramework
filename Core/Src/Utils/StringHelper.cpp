#include "../../../SDK/Core/Utils/File.h"

#include <algorithm> // std::transform

namespace Core
{
	namespace Utils
	{
		std::string ToLower(const std::string& text)
		{
			std::string buffer(text);
			std::transform(buffer.begin(), buffer.end(), buffer.begin(), ::tolower);

			return buffer;
		}

		std::string ToUpper(const std::string& text)
		{
			std::string buffer(text);
			std::transform(buffer.begin(), buffer.end(), buffer.begin(), ::toupper);

			return buffer;
		}

		bool Compare(const char* const str1, const char* const str2)
		{
			return (std::strcmp(str1, str2) == 0);
		}

		bool CompareCaseInsensitive(std::string str1, std::string str2)
		{
			return (ToLower(str1) == ToLower(str2));
		}

		int ToInt(const std::string& text)
		{
			std::istringstream str(text);
			int number;

			str >> std::dec >> number;

			return number;
		}

		UInt ToUInt(const std::string& text)
		{
			std::istringstream str(text);
			UInt number;

			str >> std::dec >> number;

			return number;
		}

		float ToFloat(const std::string& text)
		{
			std::istringstream str(text);
			float number;

			str >> std::dec >> number;

			return number;
		}

		std::string IntToString(const int& number)
		{
			return std::to_string(number);
		}

		std::string UIntToString(const UInt& number)
		{
			return std::to_string(number);
		}

		std::string FloatToString(const float& number)
		{
			return std::to_string(number);
		}
	}
}