#ifndef ATTRIBUTEPACET_H
#define ATTRIBUTEPACET_H

#include "../../../Math/Inc/Matrix4F.h"
#include "../../../Math/Inc/BoundingBox.h"

namespace Scene
{
	typedef struct AttributePacket
	{
		Math::Matrix4F modelMatrix;
		Math::BoundingBox aabb;

		bool IsValue(void)
		{
			return true;
		}

	} LATTRIBUTE_PACKET, *PATTRIBUTE_PACKET;
}

#endif // ATTRIBUTEPACET_H