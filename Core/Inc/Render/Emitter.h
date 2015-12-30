#ifndef EMITTER_H
#define EMITTER_H

#include "../../../Math/Inc/Vector3.h"
#include "../../../Math/Inc/Color.h"

#include "../../../SDK/Platform.h"

#define MAX_PARTICLES 20

namespace Core
{
	namespace Render
	{
		typedef struct Particle
		{
			Math::Vector3F position; // Позиция.
			Math::Vector3F rotation;
			Math::Vector3F scale; // Размер.

			Math::Vector3F velocity; // Ускорение.

			Math::Color color; // Цвет.
			
			float lifetime; // Время жизни.
		} LPARTICLE, *PPARTICLE;

		class Emitter
		{
		public:
			/// <summary>Конструктор класса.</summary>
			Emitter(void);

			/// <summary>Деструктор класса.</summary>
			virtual ~Emitter(void);

			virtual void Create(void);

			virtual void Destroy(void);

		private:
			int _numParticles;
		};
	}
}

#endif // EMITTER_H