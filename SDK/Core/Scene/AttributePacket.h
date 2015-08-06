#ifndef ATTRIBUTEPACET_H
#define ATTRIBUTEPACET_H

#include "../../../Math/Inc/BoundingVolume.h"
#include "../../../Math/Inc/Matrix4.h"

namespace Scene
{
	typedef struct AttributePacket
	{
		Math::Matrix4 modelMatrix;
		Math::BoundingVolume boundingBox;

		bool IsValue()
		{
			return true;
		}

	} LATTRIBUTEPACKET, *PATTRIBUTEPACKET;
}

#endif // ATTRIBUTEPACET_H