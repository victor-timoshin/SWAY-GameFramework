#include "../../../SDK/Core/Utils/File.h"

namespace Core
{
	namespace Utils
	{
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

		/// <summary>Получает расширение файла.</summary>
		/// <param name="name">Имя файла.</param>
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