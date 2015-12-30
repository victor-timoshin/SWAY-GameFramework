#ifndef FILEMODE_H
#define FILEMODE_H

namespace Core
{
	namespace Utils
	{
		typedef enum FileMode
		{
			Read  = 0x7641,
			Write = 0xD97F
		} FILE_MODE;
	}
}

#endif // FILEMODE_H