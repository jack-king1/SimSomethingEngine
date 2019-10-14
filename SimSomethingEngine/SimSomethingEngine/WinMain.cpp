#include "KingWin.h"
#include "Window.h"

int CALLBACK WinMain(
	HINSTANCE hInstance, 
	HINSTANCE hPrevInstance, 
	LPSTR lpCmdLine, 
	int nCmdShow)
{
	Window wnd(800, 300, "My Window 2");

	MSG msg;
	BOOL getResult;
	while((getResult = GetMessage(&msg,nullptr,0,0)) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		if (wnd.input.KeyIsPressed(VK_SPACE))
		{
			MessageBox(nullptr, "Space Pressed","What Do You Want To Do?", MB_OK);
		}
	}

	if (getResult == -1)
	{
		return -1;
	}

	return msg.wParam;
}