#include "Camera.h"

namespace dx = DirectX;

DirectX::XMMATRIX Camera::GetMatrix() const noexcept
{
	const auto pos = dx::XMVector3Transform(
		dx::XMVectorSet(x, y, -r, 0.0f),
		dx::XMMatrixRotationRollPitchYaw(phi, -theta, 0.0f)
	);
	return dx::XMMatrixLookAtLH(
		pos, dx::XMVectorSet(x, y, 0, 0),dx::XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f)) * dx::XMMatrixRotationRollPitchYaw(pitch, -yaw, roll);
}

void Camera::Zoom(float dt, ZoomType zoomType)
{
	switch (zoomType)
	{
		case ZoomType::ZOOMIN:
		{
			r -= 10 * dt;
		}
		break;
		case ZoomType::ZOOMOUT:
		{
			r += 10 * dt;
		}
		break;
		default:
			break;
	}
	
}

void Camera::Pitch(float dt, Direction d)
{
	if (d == Direction::DOWN)
	{
		pitch -= 1 * dt;
	}
	else if (d == Direction::UP)
	{
		pitch += 1 * dt;
	}
}

void Camera::Yaw(float dt, Direction d)
{
	if (d == Direction::LEFT)
	{
		yaw -= 10 * dt;
	}
	else if (d == Direction::RIGHT)
	{
		yaw += 10 * dt;
	}
}

void Camera::Roll(float dt, Direction d)
{
	if (d == Direction::LEFT)
	{
		roll -= 10 * dt;
	}
	else if (d == Direction::RIGHT)
	{
		roll += 10 * dt;
	}
}

void Camera::Rotate(float dt, Direction d)
{
	switch (d)
	{
		case Camera::LEFT:
		{
			//theta -= 1 * dt;
			x -= 10 * dt;
		}
		break;
		case Camera::RIGHT:
		{
			//theta += 1 * dt;
			x += 10 * dt;
		}
		break;
		case Camera::UP:
		{
			z += 10 * dt;
		}
		break;
		case Camera::DOWN:
		{
			z -= 10 * dt;
		}
		break;
	}
}

void Camera::UpDown(float dt, Direction d)
{
	if (d == Direction::UP)
	{
		y += 10 * dt;
	}
	else if (d == Direction::DOWN)
	{
		y -= 10 * dt;
	}
}

void Camera::Reset() noexcept
{
	r = 20.0f;
	theta = 0.0f;
	phi = 0.0f;
	pitch = 0.0f;
	yaw = 0.0f;
	roll = 0.0f;
}
