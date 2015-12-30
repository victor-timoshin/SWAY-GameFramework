#ifndef CLEARFLAG_H
#define CLEARFLAG_H

namespace Gapi
{
	typedef enum class ClearFlag
	{
		Color   = 0xBAB5,
		Depth   = 0x5068,
		Stencil = 0xB435
	} CLEARFLAG;

	inline CLEARFLAG operator | (CLEARFLAG l, CLEARFLAG r)
	{
		return static_cast<CLEARFLAG>(static_cast<int>(l) | static_cast<int>(r));
	}

	inline bool operator & (CLEARFLAG l, CLEARFLAG r)
	{
		return (static_cast<int>(l) & static_cast<int>(r)) != 0;
	}
}

#endif // CLEARFLAG_H