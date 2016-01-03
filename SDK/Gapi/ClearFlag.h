#ifndef CLEARFLAG_H
#define CLEARFLAG_H

namespace Gapi
{
	typedef enum class ClearFlag
	{
		Color   = 0xBAB5,
		Depth   = 0x5068,
		Stencil = 0xB435
	} CLEAR_FLAG;

	inline CLEAR_FLAG operator | (CLEAR_FLAG l, CLEAR_FLAG r)
	{
		return static_cast<CLEAR_FLAG>(static_cast<int>(l) | static_cast<int>(r));
	}

	inline bool operator & (CLEAR_FLAG l, CLEAR_FLAG r)
	{
		return (static_cast<int>(l) & static_cast<int>(r)) != 0;
	}
}

#endif // CLEARFLAG_H