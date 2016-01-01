#include "../../../SDK/Core/Utils/File.h"

namespace Core
{
	namespace Utils
	{
		void ToLowercase(std::string& str)
		{
			for (size_t i = 0; i < str.size(); i++)
				str.at(i) = tolower(str.at(i));
		}
	}
}