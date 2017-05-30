#pragma once
#include<optional>
#include<string>
#include<functional>
#include"KeyCode.h"

namespace Bugs
{
	class Circle;
	class BoundingBox;
	class Vector2;
	class Camera;
	using KeyMap = std::map<KeyCode, std::function<void()>>;

	struct IInputRenderer
	{
		//Constructors
		virtual ~IInputRenderer() = default;

		//General methodes
		virtual void Init() = 0;
		virtual void Shutdown() = 0;
		virtual bool IsWindowOpen() = 0;

		//Rendering methodes
		virtual void BeginFrame(const Camera& camera) = 0;
		virtual void EndFrame() = 0;
		virtual bool LoadTexture(const std::string& fileName, const std::string& id) = 0;
		virtual void UnLoadTexture(const std::string& id) = 0;
		virtual void RenderTexture(const std::string& id, const Vector2& position) = 0;
		virtual std::optional<Vector2> GetHightWidthRetio() const = 0;
		virtual void Render(const BoundingBox& box) = 0;
		virtual void Render(const Circle& circle) = 0;

		//Input methodes
		virtual void SetKeyMap(const KeyMap& keyMap) = 0;
		virtual void ProcessKeys() = 0;
	};
}