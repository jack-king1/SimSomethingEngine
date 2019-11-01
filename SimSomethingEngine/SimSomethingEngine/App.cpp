#include "App.h"
#include "Box.h"
#include <memory>
#include <algorithm>
#include "KingMath.h"
#include "Surface.h"
#include "GDIPlusManager.h"
#include "SkinnedBox.h"
#include "Sheet.h"
#include "Floor.h"
#include "City.h"
#include "Food.h"
#include "Wood.h"
#include "Stone.h"
#include "Gold.h"


GDIPlusManager gdipm;

App::App()
	:
	wnd(800, 600, "Kings Window")
{
	class Factory
	{
	public:
		Factory(Graphics& gfx)
			:
			gfx(gfx)
		{}
		std::unique_ptr<Drawable> operator()()
		{
			//return std::make_unique<Sheet>(
			//	gfx, rng, adist, ddist,
			//	odist, rdist
			//	);

			//return std::make_unique<Box>(
			//	gfx, rng, adist, ddist,
			//	odist, rdist, bdist
			//	);

				//return std::make_unique<Floor>(gfx);
				//count++;

				//return std::make_unique<SkinnedBox>(
				//	gfx, rng, adist, ddist,
				//	odist, rdist
				//	);



			
			//return std::make_unique<Sheet>(
			//	gfx, rng, adist, ddist,
			//	odist, rdist
			//	);

			//switch (typedist(rng))
			//{
			////case 0:
			////	return std::make_unique<SkinnedBox>(
			////		gfx, rng, adist, ddist,
			////		odist, rdist
			////		);
			//case 1:

			//default:
			//	assert(false && "bad drawable type in factory");
			//	return {};
			//}
		}
	private:
		Graphics& gfx;
		std::mt19937 rng{ std::random_device{}() };
		std::uniform_real_distribution<float> adist{ 0.0f,PI * 2.0f };
		std::uniform_real_distribution<float> ddist{ 0.0f,PI * 0.5f };
		std::uniform_real_distribution<float> odist{ 0.0f,PI * 0.08f };
		std::uniform_real_distribution<float> rdist{ 6.0f,20.0f };
		std::uniform_real_distribution<float> bdist{ 0.4f,3.0f };
		std::uniform_int_distribution<int> latdist{ 5,20 };
		std::uniform_int_distribution<int> longdist{ 10,40 };
		std::uniform_int_distribution<int> typedist{ 0,2 };
	};

	Factory f(wnd.Gfx());
	drawables.reserve(nDrawables);
	//std::generate_n(std::back_inserter(drawables), nDrawables, f);

	drawables.push_back(std::make_unique<City>(wnd.Gfx()));
	drawables.push_back(std::make_unique<Stone>(wnd.Gfx()));
	drawables.push_back(std::make_unique<Food>(wnd.Gfx()));
	drawables.push_back(std::make_unique<Wood>(wnd.Gfx()));
	drawables.push_back(std::make_unique<Gold>(wnd.Gfx()));
	drawables.push_back(std::make_unique<Floor>(wnd.Gfx()));

	//drawables[0].

	wnd.Gfx().SetProjection(DirectX::XMMatrixPerspectiveLH(1.0f, 3.0f / 4.0f, 0.5f, 200.0f));
}

void App::DoFrame()
{
	const auto dt = timer.Mark();
	wnd.Gfx().ClearBuffer(0.07f, 0.0f, 0.12f);
	wnd.Gfx().SetCamera(cam.GetMatrix());

	for (auto& d : drawables)
	{
		d->Update(dt);
		d->Draw(wnd.Gfx());
	}
	//TODO:Update Camera.
	if (wnd.kbd.KeyIsPressed(0x57)) //w
	{
		cam.Zoom(dt, Camera::ZOOMIN);
	}
	else if (wnd.kbd.KeyIsPressed(0x53))//s
	{
		cam.Zoom(dt, Camera::ZOOMOUT);
	}

	if (wnd.kbd.KeyIsPressed(0x41))//a
	{
		cam.Rotate(dt, Camera::LEFT);
	}
	else if (wnd.kbd.KeyIsPressed(0x44))//d
	{
		cam.Rotate(dt, Camera::RIGHT);
	}

	if (wnd.kbd.KeyIsPressed(0x51))
	{
		cam.UpDown(dt, Camera::DOWN);
	}
	else if (wnd.kbd.KeyIsPressed(0x45))
	{
		cam.UpDown(dt, Camera::UP);
	}

	wnd.Gfx().EndFrame();
}

App::~App()
{}


int App::Go()
{
	while (true)
	{
		// process all messages pending, but to not block for new messages
		if (const auto ecode = Window::ProcessMessages())
		{
			// if return optional has value, means we're quitting so return exit code
			return *ecode;
		}
		DoFrame();
	}
}