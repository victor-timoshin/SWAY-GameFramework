#ifndef SPRITEBATCH_H
#define SPRITEBATCH_H

#include "../../../Math/Inc/Rect.h"
#include "../../../SDK/Gapi/DeviceBase.h"
#include "../../../SDK/Gapi/TextureBase.h"
#include "../../../SDK/Gapi/TextureSamplerBase.h"
#include "../../../SDK/Platform.h"

#include "../Resource/Resource.h"
#include "Image.h"

namespace Core
{
	namespace Render
	{
		class SpriteBatch
		{
			DECL_PROPERTY_INLINE(float, Width, _width) // Ширина спрайта в пикселях.
			DECL_PROPERTY_INLINE(float, Height, _height) // Высота спрайта в пикселях.
			DECL_PROPERTY_INLINE(float, X, _x)
			DECL_PROPERTY_INLINE(float, Y, _y) 
			DECL_PROPERTY_INLINE(float, Scale, _scale)
			DECL_PROPERTY_INLINE(float, Angle, _angle) // Угол поворота в радианах.
			DECL_PROPERTY_INLINE(Math::Rect, Rect, _rect)
			DECL_PROPERTY_INLINE(Image, Texture, _texture)
			DECL_PROPERTY_INLINE(bool, FlipHorizontal, _flipHorizontal)
			DECL_PROPERTY_INLINE(bool, FlipVertical, _flipVertical)

		public:
			/// <summary>Конструктор класса.</summary>
			SpriteBatch(void* library, Gapi::IDeviceBase* device);

			/// <summary>Деструктор класса.</summary>
			virtual ~SpriteBatch(void);

		private:
			Image* _image;
		};
	}
}

#endif // SPRITEBATCH_H