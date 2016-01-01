#include "../../../Core/Inc/Utils/FileDirectory.h"

namespace Core
{
	namespace Utils
	{
		const char* FileDirectory::DefaultRootPath = "Assets/";

		bool FileDirectory::Create(const char* name)
		{
			if (IsExist(name))
				return false;
			else
			{
				CreateDirectory(name, nullptr);
				return true;
			}
		}

		bool FileDirectory::IsExist(const char* name)
		{
			if (GetFileAttributes(name) == -1)
				return false;
			else
				return true;
		}

		void FileDirectory::SetDefaultPath(const char* subPath)
		{
			defaultPath.append(DefaultRootPath);
			defaultPath.append(subPath);
			defaultPath.append("/");
		}
	}
}