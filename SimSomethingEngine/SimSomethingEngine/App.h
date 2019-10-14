#pragma 
#include "KingWin.h"
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::ostringstream

//This file will be responsible for the main game loop and updating our game.
//e.g. message handling, Shutdown, Initialzeation. Render, Update etc.

class App
{
public:
	App();
	App(const App&);
	~App();

	bool Init();

	void Run();
	void ShutDown();
	LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);

private:
	bool Frame();
	void InitWindow(int& screenWidth, int& screenHeight);
	void ShutDownWindows();

	LPCWSTR applicationName;
	HINSTANCE hInstance;
	HWND hWnd;
};

/////////////////////////
// FUNCTION PROTOTYPES //
/////////////////////////
static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


/////////////
// GLOBALS //
/////////////
static App* ApplicationHandle = 0;

