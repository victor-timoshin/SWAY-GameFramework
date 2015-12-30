#ifndef MODIFIER_H
#define MODIFIER_H

namespace OIS
{
	typedef enum Modifier
	{
		None       = 0,
		LeftAlt    = 0x01,
		RightAlt   = 0x02,
		LeftCtrl   = 0x04,
		RightCtrl  = 0x08,
		LeftShift  = 0x10,
		RightShift = 0x20,
		LeftMeta   = 0x40,
		RightMeta  = 0x80
	};
}

#endif // MODIFIER_H