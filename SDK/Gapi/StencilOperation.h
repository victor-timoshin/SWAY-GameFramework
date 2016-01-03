#ifndef STENCILOPERATION_H
#define STENCILOPERATION_H

namespace Gapi
{
	typedef enum class StencilOperation
	{
		Keep          = 0xAF20,
		Zero          = 0xEDF4,
		Replace       = 0x4CBC,
		Increment     = 0x656A,
		IncrementWrap = 0x8076,
		Decrement     = 0x9070,
		DecrementWrap = 0x36A8,
		Invert        = 0xD737
	} STENCIL_OPERATION;
}

#endif // STENCILOPERATION_H