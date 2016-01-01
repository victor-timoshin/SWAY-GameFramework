#ifndef FILEDIRECTORY_H
#define FILEDIRECTORY_H

#include "../../../SDK/Platform.h"

namespace Core
{
	namespace Utils
	{
		class FileDirectory
		{
		public:
			static const char* DefaultRootPath;

			/// <summary>Конструктор класса.</summary>
			FileDirectory(void) {}

			/// <summary>Деструктор класса.</summary>
			virtual ~FileDirectory(void) {}

			virtual bool Create(const char* name);

			virtual bool IsExist(const char* name);

			void SetDefaultPath(const char* subPath);

		private:
			std::string defaultPath;
		};
	}
}

#endif // FILEDIRECTORY_H