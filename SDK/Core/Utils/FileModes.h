#ifndef FILEMODES_H
#define FILEMODES_H

namespace Core
{
	namespace Utils
	{
		typedef enum FileModes
		{
			EFM_READ = 0x7641,
			EFM_WRITE = 0xD97F
		} FILEMODES;
	}
}

#endif // FILEMODES_H