#pragma once
#include "DrawableBase.h"

class Floor : public DrawableBase<Floor>
{
public:
	Floor(Graphics& gfx);
	void Update(float dt) noexcept override;
	DirectX::XMMATRIX GetTransformXM() const noexcept override;
private:
	// positional
	float r;
	float roll = 0.0f;
	float pitch = 0.0f;
	float yaw = 0.0f;
	float theta;
	float phi;
	float chi;
	// speed (delta/s)
	float droll;
	float dpitch;
	float dyaw;
	float dtheta;
	float dphi;
	float dchi;

	// model transform
	DirectX::XMFLOAT3X3 mt;

	//float xScale = 1;
	//float yScale = 1;
	//float zScale = 1;

	////Position
	//float xPos;
	//float yPos;
	//float zPos;
};