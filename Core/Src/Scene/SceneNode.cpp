#include "../../../Core/Inc/Scene/SceneNode.h"

namespace Scene
{
	/** Constructor. */
	SceneNode::SceneNode(std::string name)
		: ISceneNodeBase(name)
	{
		matrixWorld.Identity();

		orientation.Identity();
		rotation.Identity();

		position = Core::Math::Vector3(0.0f, 0.0f, 0.0f);
		scale = Core::Math::Vector3(1.0f, 1.0f, 1.0f);
	}

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

	void SceneNode::SetPosition(float x, float y, float z)
	{
		position = Core::Math::Vector3(x, y, z);
	}

	void SceneNode::SetRotation(Core::Math::Vector3 axis, float angle, TransformSpace relativeTo)
	{
		rotation.FromAxisAngle(axis, Core::Math::RadiansToDegrees(angle));

		switch (relativeTo)
		{
		case TRANSFORM_PARENT:
			orientation = rotation * orientation;
			break;
		case TRANSFORM_WORLD:
			break;
		case TRANSFORM_LOCAL:
			orientation = orientation * rotation;
			break;
		}
	}

	void SceneNode::SetScale(float x, float y, float z)
	{
		scale = Core::Math::Vector3(x, y, z);
	}

	void SceneNode::SetOrientation(float w, float x, float y, float z)
	{
		orientation = Core::Math::Quaternion(w, x, y, z);
	}

	void SceneNode::SetOrientation(const Core::Math::Quaternion& o)
	{
		orientation = o;
	}

	Core::Math::Matrix4 SceneNode::GetMatrixWorldTransform()
	{
		Core::Math::Quaternion temp;

		temp *= orientation;
		orientation.Normalize();

		orientation.ToRotationMatrix(matrixWorld);

		Core::Math::Matrix4 scaleMatrix;
		scaleMatrix.Identity();

		scaleMatrix[0][0] = scale._x;
		scaleMatrix[1][1] = scale._y;
		scaleMatrix[2][2] = scale._z;

		matrixWorld *= scaleMatrix;

		matrixWorld[3][0] = position._x;
		matrixWorld[3][1] = position._y;
		matrixWorld[3][2] = position._z;

		return matrixWorld;
	}

	const Core::Math::Quaternion& SceneNode::GetOrientation() const
	{
		return orientation;
	}

	const Core::Math::Vector3& SceneNode::GetPosition() const
	{
		return position;
	}

	Core::Math::Vector3 SceneNode::GetScale()
	{
		return scale;
	}

	ISceneNodeBase* RegisterSceneNode(std::string name)
	{
		return new SceneNode(name);
	}
}