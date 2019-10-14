#include <Windows.h>
#include "App.h"

int CALLBACK WinMain(
	HINSTANCE hInstance, 
	HINSTANCE hPrevInstance, 
	LPSTR lpCmdLine, 
	int nCmdShow)
{
	App* app;
	bool result;

	//Create new app
	app = new App;
	if (!app)
	{
		return 0;
	}

	//init and run app object.
	result = app->Init();
	if (result)
	{
		app->Run();
	}

	
	//Message Pumpo
	MSG msg;
	BOOL getResult;
	while((getResult = GetMessage(&msg,nullptr,0,0)) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	if (getResult == -1)
	{
		return -1;
	}
	else
	{
		return msg.wParam;
	}
}