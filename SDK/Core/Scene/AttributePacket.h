#ifndef ATTRIBUTEPACET_H
#define ATTRIBUTEPACET_H

#include "../../Math/BoundingVolume.h"
#include "../../Math/Matrix4.h"

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