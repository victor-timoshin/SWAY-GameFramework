#ifndef SOUNDBASE_H
#define SOUNDBASE_H

#include "../../Math/Inc/Vector3.h"
#include "../Platform.h"

namespace Sapi
{
	class IBufferBase;
	class ISoundBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		ISoundBase(void) {}

		/// <summary>Деструктор класса.</summary>
		virtual ~ISoundBase(void) {}

		virtual void SetALBuffer(IBufferBase* buffer) = 0;

		/// <summary>Запускает воспроизведение звука.</summary>
		virtual void Play(void) = 0;

		virtual bool HasPlaying(void) const = 0;

		/// <summary>Останавливает воспроизведение звука.</summary>
		virtual void Stop(void) = 0;

		virtual bool HasStopped(void) const = 0;

		/// <summary>Ставит на паузу воспроизведение.</summary>
		virtual void Pause(void) = 0;

		virtual bool HasPaused(void) const = 0;

		virtual void Rewind(void) = 0;

		/// <summary>Использование циклического воспроизведение.</summary>
		virtual void UseLooping(bool looping) = 0;

		virtual bool HasLooping(void) const = 0;

		/// <summary>Устанавливает координаты источника звука.</summary>
		virtual void SetSourcePosition(float x, float y, float z) = 0;

		/// <summary>Устанавливает координаты источника звука.</summary>
		virtual void SetSourcePosition(Math::Vec3F position) = 0;

		virtual void SetSourceVelocity(float x, float y, float z) = 0;

		virtual void SetSourceVelocity(Math::Vec3F velocity) = 0;

		/// <summary>Устанавливает координаты слушателя.</summary>
		virtual void SetListenerPosition(float x, float y, float z) = 0;

		/// <summary>Устанавливает координаты слушателя.</summary>
		virtual void SetListenerPosition(Math::Vec3F position) = 0;

		virtual void SetListenerVelocity(float x, float y, float z) = 0;

		virtual void SetListenerVelocity(Math::Vec3F velocity) = 0;
	};

	CORE_API ISoundBase* RegisterSound(void);
}

#endif // SOUNDBASE_H