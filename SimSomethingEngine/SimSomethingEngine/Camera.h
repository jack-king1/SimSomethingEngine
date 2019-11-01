#pragma once
#include "Graphics.h"

class Camera
{

public:
	enum ZoomType
	{
		ZOOMIN,
		ZOOMOUT
	};
	enum Direction
	{
		LEFT,
		RIGHT,
		UP,
		DOWN
	};
	//Gets local parameters and returns transformation matrix.
	DirectX::XMMATRIX GetMatrix() const noexcept;
	void Reset() noexcept;
	void Zoom(float dt, ZoomType zoomType);
	void Pitch(float dt, Direction d);
	void Yaw(float dt, Direction d);
	void Roll(float dt, Direction d);
	void Rotate(float dt, Direction d);
	void UpDown(float dt, Direction d);
private:
	//R = Distance from origin
	float r = 20.0f;
	float x = 0.0f;
	float y = 10.0f;
	float z = 10.0f;

	//Rotating around origin
	float theta = 0.0f; //Rotation around equator
	float phi = 0.0f;//Rotation towards north/.south pole.

	float pitch = -0.8f;
	float yaw = 0.0f;
	float roll = 0.0f;
};