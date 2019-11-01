#pragma once
#include "Window.h"
#include "KingTimer.h"
#include "Camera.h"

class App
{
public:
	App();
	// master frame / message loop
	int Go();
	~App();
private:
	void DoFrame();
private:

	Window wnd;
	KingTimer timer;
	std::vector<std::unique_ptr<class Drawable>> drawables;
	Camera cam;
	static constexpr size_t nDrawables = 2;
};