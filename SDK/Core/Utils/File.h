#ifndef FILE_H
#define FILE_H

#include <string>

namespace Core
{
	namespace Utils
	{
		void ToLowercase(std::string& str)
		{
			for (size_t i = 0; i < str.size(); i++)
				str.at(i) = tolower(str.at(i));
		}

		bool FileExists(const std::string& name)
		{
			std::ifstream file(name.c_str());
			if (file.good())
			{
				file.close();
				return true;
			}

			file.close();
			return false;
		}

		std::string GetFileExtension(std::string name)
		{
			//return name.substr(name.length() - 3);

			size_t dotPosition = name.find_last_of(".");
			if (dotPosition == std::string::npos)
				return std::string("");

			return name.substr(dotPosition + 1);
		}
	}
}

#endif // FILE_H