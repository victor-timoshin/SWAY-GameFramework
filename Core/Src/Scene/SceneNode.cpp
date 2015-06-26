#include "../../../Core/Inc/Scene/SceneNode.h"

namespace Scene
{
	/** Constructor. */
	SceneNode::SceneNode(std::string name)
		: ISceneNodeBase(name) {}

	/** Destructor. */
	SceneNode::~SceneNode() {}

	ISceneNodeBase* SceneNode::CreateChild(const char* name)
	{
		SceneNode* child = new SceneNode(name);
		AddChild(child);

		return child;
	}

	void SceneNode::Attach(ISceneComponentBase* subscriber)
	{
		subscriber->Notify(this);
		components.insert(IComponentMap::value_type(subscriber->GetComponentName(), subscriber));
	}

	void SceneNode::Detach(ISceneComponentBase* subscriber)
	{
		IComponentMap::iterator i = components.find(subscriber->GetComponentName());
		if (i != components.end() && i->second == subscriber)
		{
			components.erase(i);
			subscriber->Notify(0L);
		}
	}

	void SceneNode::DetachAll()
	{
		for (IComponentMap::iterator i = components.begin(); i != components.end(); ++i)
		{
			ISceneComponentBase* subscriber = i->second;
			subscriber->Notify(0L);
		}

		components.clear();
	}

	ISceneNodeBase* RegisterSceneNode(std::string name)
	{
		return new SceneNode(name);
	}
}