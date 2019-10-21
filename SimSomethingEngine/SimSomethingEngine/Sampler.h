#pragma once
#include "Bindable.h"

//The sampler determines how pixels are written onto the polygon. It describes how each function should act. e.g. wrap etc.


class Sampler : public Bindable
{
public:
	Sampler(Graphics& gfx);
	void Bind(Graphics& gfx) noexcept override;
protected:
	Microsoft::WRL::ComPtr<ID3D11SamplerState> pSampler;
};