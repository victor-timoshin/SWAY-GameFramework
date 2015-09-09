#ifndef SCENENODEQUEUE_H
#define SCENENODEQUEUE_H

#include "../../SDK/SceneGraph/SceneNodeBase.h"
#include "../../SDK/Platform.h"

#include <vector>
#include <set>

namespace Scene
{
	class SceneNodeQueue
	{
	public:
		/// <summary>Конструктор класса.</summary>
		SceneNodeQueue(void);

		/// <summary>Деструктор класса.</summary>
		virtual ~SceneNodeQueue(void) {}

		virtual void CascadeUpdate(void);

	private:
		typedef std::set<ISceneNodeBase*> ChildUpdateSet;
		mutable ChildUpdateSet childrenToUpdate;

		typedef std::vector<ISceneNodeBase*> QueuedUpdates;
		static QueuedUpdates queuedUpdates;
	};
}

#endif // SCENENODEQUEUE_H