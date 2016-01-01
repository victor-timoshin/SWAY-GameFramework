#ifndef FILETYPE_H
#define FILETYPE_H

namespace Core
{
	namespace Utils
	{
		typedef enum FileType
		{
			Text   = 0x3B1C, // Бинарный файл.
			Binary = 0xE0AA  // Текстовый файл.
		} FILE_TYPE;
	}
}

#endif // FILETYPE_H