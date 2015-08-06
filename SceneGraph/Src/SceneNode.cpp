﻿#include "../Inc/SceneNode.h"

namespace Scene
{
	/// <summary>Конструктор класса.</summary>
	/// <param name="name">Имя узла.</param>
	SceneNode::SceneNode(std::string name) : ISceneNodeBase(name)
	{
		matrixWorld.Identity();

		orientation.Identity();
		rotation.Identity();

		position = Math::Vector3(0.0f, 0.0f, 0.0f);
		scale = Math::Vector3(1.0f, 1.0f, 1.0f);
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
		components.insert(IComponentMap::value_type(subscriber->GetComponentName(), subscriber));
	}

	void SceneNode::Detach(ISceneComponentBase* subscriber)
	{
		IComponentMap::iterator i = components.find(subscriber->GetComponentName());
		if (i != components.end() && i->second == subscriber)
		{
			components.erase(i);
			subscriber->Notify(nullptr);
		}
	}

	void SceneNode::DetachAll(void)
	{
		for (IComponentMap::iterator i = components.begin(); i != components.end(); ++i)
		{
			ISceneComponentBase* subscriber = i->second;
			subscriber->Notify(nullptr);
		}

		components.clear();
	}

	ISceneComponentBase* SceneNode::GetAttachedComponentByName(const char* name)
	{
		IComponentMap::iterator i = components.find(name);
		if (i != components.end())
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

	void SceneNode::SetPosition(const Math::Vector3& positionV, TransformSpace relativeTo)
	{
		switch (relativeTo)
		{
		case TRANSFORM_PARENT:
			position = positionV;
			break;
		case TRANSFORM_WORLD:
			position = positionV;
			break;
		case TRANSFORM_LOCAL:
			position = positionV;
			break;
		}

		// TODO: update
	}

	void SceneNode::SetPosition(float x, float y, float z, TransformSpace relativeTo)
	{
		SetPosition(Math::Vector3(x, y, z), relativeTo);
	}

	void SceneNode::SetTranslate(const Math::Vector3& translate, TransformSpace relativeTo)
	{
		switch (relativeTo)
		{
		case TRANSFORM_PARENT:
			position += translate;
			break;
		case TRANSFORM_WORLD:
			position += translate;
			break;
		case TRANSFORM_LOCAL:
			//position += orientation * translate;
			break;
		}

		// TODO: update
	}

	void SceneNode::SetTranslate(float x, float y, float z, TransformSpace relativeTo)
	{
		SetTranslate(Math::Vector3(x, y, z), relativeTo);
	}

	void SceneNode::SetRotation(Math::Vector3 axis, float angle, TransformSpace relativeTo)
	{
		rotation.FromAxisAngle(axis, Math::DegreesToRadians(angle));

		switch (relativeTo)
		{
		case TRANSFORM_PARENT:
			orientation = rotation * orientation;
			break;
		case TRANSFORM_WORLD:
			orientation = orientation * rotation;
			break;
		case TRANSFORM_LOCAL:
			orientation = orientation * rotation;
			break;
		}

		// TODO: update
	}

	void SceneNode::SetScale(float x, float y, float z)
	{
		scale = Math::Vector3(x, y, z);

		// TODO: update
	}

	void SceneNode::SetOrientation(float w, float x, float y, float z)
	{
		orientation = Math::Quaternion(w, x, y, z);

		// TODO: update
	}

	void SceneNode::SetOrientation(const Math::Quaternion& orientationQ)
	{
		orientation = orientationQ;

		// TODO: update
	}

	Math::Matrix4 SceneNode::GetWorldMatrixTransform(void)
	{
		Math::Quaternion temp;

		temp *= orientation;
		orientation.Normalize();

		orientation.ToRotationMatrix(matrixWorld);

		Math::Matrix4 scaleMatrix;
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

	const Math::Quaternion& SceneNode::GetOrientation(void) const
	{
		return orientation;
	}

	const Math::Vector3& SceneNode::GetPosition(void) const
	{
		return position;
	}

	Math::Vector3 SceneNode::GetScale(void)
	{
		return scale;
	}

	ISceneNodeBase* RegisterSceneNode(std::string name)
	{
		return new SceneNode(name);
	}
}