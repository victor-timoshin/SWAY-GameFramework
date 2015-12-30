#ifndef FRUSTUMSIDE_H
#define FRUSTUMSIDE_H

#define MAX_NUM_FRUSTUM_PLANES 6

namespace Math
{
	typedef enum class FrustumSide
	{
		Right  = 0,
		Left   = 1,
		Bottom = 2,
		Top    = 3,
		Far    = 4,
		Near   = 5
	} FRUSTUM_SIDE;
}

#endif // FRUSTUMSIDE_H