#include "../Inc/SceneNode.h"

namespace Scene
{
	/// <summary>Конструктор класса.</summary>
	/// <param name="name">Имя узла.</param>
	SceneNode::SceneNode(std::string name) : ISceneNodeBase(name)
	{
		_matrixWorld.SetIdentity();

		_orientation.Identity();
		_rotation.Identity();

		_position = VEC3F_ZERO;
		_scale = VEC3F_ONE;
	}

	ISceneNodeBase* SceneNode::CreateChild(const char* name)
	{
		SceneNode* child = new SceneNode(name);
		AddChild(child);

		return child;
	}

	void SceneNode::Attach(ISceneComponentBase* subscriber)
	{
		subscriber->Notify(this);
		_components.insert(IComponentMap::value_type(subscriber->GetComponentName(), subscriber));
	}

	void SceneNode::Detach(ISceneComponentBase* subscriber)
	{
		IComponentMap::iterator i = _components.find(subscriber->GetComponentName());
		if (i != _components.end() && i->second == subscriber)
		{
			_components.erase(i);
			subscriber->Notify(nullptr);
		}
	}

	void SceneNode::DetachAll(void)
	{
		for (IComponentMap::iterator i = _components.begin(); i != _components.end(); ++i)
		{
			ISceneComponentBase* subscriber = i->second;
			subscriber->Notify(nullptr);
		}

		_components.clear();
	}

	ISceneComponentBase* SceneNode::GetAttachedComponentByName(const char* name)
	{
		IComponentMap::iterator i = _components.find(name);
		if (i != _components.end())
			return i->second;

		return nullptr;
	}

	void SceneNode::CascadeUpdate(void)
	{
		for (ICollectionMap::iterator i = children.begin(); i != children.end(); ++i)
		{
			ISceneNodeBase* child = i->second;
			child->CascadeUpdate();
		}
	}

	void SceneNode::SetPosition(const Math::Vector3F& position, TransformSpace relativeTo)
	{
		switch (relativeTo)
		{
		case TRANSFORM_PARENT:
			_position = position;
			break;
		case TRANSFORM_WORLD:
			_position = position;
			break;
		case TRANSFORM_LOCAL:
			_position = position;
			break;
		}

		// TODO: update
	}

	void SceneNode::SetPosition(float x, float y, float z, TransformSpace relativeTo)
	{
		SetPosition(Math::Vector3F(x, y, z), relativeTo);
	}

	void SceneNode::SetTranslate(const Math::Vector3F& translate, TransformSpace relativeTo)
	{
		switch (relativeTo)
		{
		case TRANSFORM_PARENT:
			_position += translate;
			break;
		case TRANSFORM_WORLD:
			_position += translate;
			break;
		case TRANSFORM_LOCAL:
			//_position += orientation * translate;
			break;
		}

		// TODO: update
	}

	void SceneNode::SetTranslate(float x, float y, float z, TransformSpace relativeTo)
	{
		SetTranslate(Math::Vector3F(x, y, z), relativeTo);
	}

	void SceneNode::SetRotation(Math::Vector3F axis, float angle, TransformSpace relativeTo)
	{
		_rotation.FromAxisAngle(axis, Math::DegreesToRadians(angle));

		switch (relativeTo)
		{
		case TRANSFORM_PARENT:
			_orientation = _rotation * _orientation;
			break;
		case TRANSFORM_WORLD:
			_orientation = _orientation * _rotation;
			break;
		case TRANSFORM_LOCAL:
			_orientation = _orientation * _rotation;
			break;
		}

		// TODO: update
	}

	void SceneNode::SetScale(float x, float y, float z)
	{
		_scale = Math::Vector3F(x, y, z);

		// TODO: update
	}

	void SceneNode::SetOrientation(float w, float x, float y, float z)
	{
		_orientation = Math::Quaternion(w, x, y, z);

		// TODO: update
	}

	void SceneNode::SetOrientation(const Math::Quaternion& orientationQ)
	{
		_orientation = orientationQ;

		// TODO: update
	}

	Math::Matrix4F SceneNode::GetWorldMatrix(void)
	{
		SceneNode* parent = static_cast<SceneNode*>(GetParentNode());
		if (parent)
			Math::Matrix4F::Multiply(parent->GetWorldMatrix(), GetMatrix(), &_matrixWorld);
		else
			_matrixWorld = GetMatrix();

		return _matrixWorld;
	}

	Math::Matrix4F SceneNode::GetMatrix(void)
	{
		_orientation.Normalize();
		_orientation.ToRotationMatrix(_matrixWorld);

		Math::Matrix4F positionMatrix;
		positionMatrix.SetIdentity();

		positionMatrix.Set(3, 0, _position._x);
		positionMatrix.Set(3, 1, _position._y);
		positionMatrix.Set(3, 2, _position._z);

		_matrixWorld.Multiply(positionMatrix);

		Math::Matrix4F scaleMatrix;
		scaleMatrix.SetIdentity();

		scaleMatrix.Set(0, 0, _scale._x);
		scaleMatrix.Set(1, 1, _scale._y);
		scaleMatrix.Set(2, 2, _scale._z);

		_matrixWorld.Multiply(scaleMatrix);

		return _matrixWorld;
	}

	const Math::Quaternion& SceneNode::GetOrientation(void) const
	{
		return _orientation;
	}

	const Math::Vector3F& SceneNode::GetPosition(void) const
	{
		return _position;
	}

	Math::Vector3F SceneNode::GetScale(void)
	{
		return _scale;
	}

	ISceneNodeBase* RegisterSceneNode(std::string name)
	{
		return new SceneNode(name);
	}
}