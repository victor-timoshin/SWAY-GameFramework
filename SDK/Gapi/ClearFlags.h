#ifndef CLEARFLAGS_H
#define CLEARFLAGS_H

namespace Gapi
{
	typedef enum ClearFlags
	{
		ECF_COLOR = 0xBAB5,
		ECF_DEPTH = 0x5068,
		ECF_STENCIL = 0xB435
	} CLEARFLAGS;

	inline ClearFlags operator|(ClearFlags l, ClearFlags r)
	{
		return static_cast<ClearFlags>(static_cast<int>(l) | static_cast<int>(r));
	}

	inline bool operator&(ClearFlags l, ClearFlags r)
	{
		return (static_cast<int>(l) & static_cast<int>(r)) != 0;
	}
}

#endif // CLEARFLAGS_H