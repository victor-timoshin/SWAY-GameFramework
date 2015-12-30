#include "../../../Core/Inc/Render/SpriteBatch.h"

namespace Core
{
	namespace Render
	{
		/// <summary>Конструктор класса.</summary>
		SpriteBatch::SpriteBatch(void* library, Gapi::IDeviceBase* device)
		{
			_image = new Image(library, device);
		}

		/// <summary>Деструктор класса.</summary>
		SpriteBatch::~SpriteBatch(void)
		{
			SAFE_DELETE(_image);
		}
	}
}