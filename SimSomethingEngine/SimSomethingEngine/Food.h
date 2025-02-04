#pragma once

#pragma once
#include "DrawableBase.h"

class Food : public DrawableBase<Food>
{
public:
	Food(Graphics& gfx, std::mt19937& rng,
		std::uniform_real_distribution<float>& adist,
		std::uniform_real_distribution<float>& ddist,
		std::uniform_real_distribution<float>& odist,
		std::uniform_real_distribution<float>& rdist);
	Food(Graphics& gfx);
	void Update(float dt) noexcept override;
	DirectX::XMMATRIX GetTransformXM() const noexcept override;
private:
	// positional
	float r;
	float x;
	float y;
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
	float xScale = 5;
	float yScale = 5;
	float zScale = 5;

	//Position
	float xPos = -15;
	float yPos;
	float zPos;
};