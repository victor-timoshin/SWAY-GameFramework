#ifndef FEATURETYPE_H
#define FEATURETYPE_H

namespace Gapi
{
	typedef enum FeatureType
	{
		Culling        = 0x7FB4,
		Blending       = 0xC5BC,
		DepthTesting   = 0x23C7,
		StencilTesting = 0x4597
	} FEATURE_TYPE;
}

#endif // FEATURETYPE_H