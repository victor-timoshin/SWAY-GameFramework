#ifndef CULLFORMAT_H
#define CULLFORMAT_H

namespace Gapi
{
	typedef enum CullFormat
	{
		ECF_CW   = 0xCBA3,
		ECF_CCW  = 0x391D,
		ECF_NONE = 0x602F
	} CULL_FORMAT;
}

#endif // CULLFORMAT_H