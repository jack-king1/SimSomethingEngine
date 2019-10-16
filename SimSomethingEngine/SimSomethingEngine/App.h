#pragma once
#include <cmath>
#include <limits>
#include <iomanip>
#include "Window.h"
#include "KingTimer.h"

class App
{
public:
	App();
	// master frame / message loop
	int Go();
private:
	void DoFrame();
private:
	Window wnd;
	KingTimer timer;
};