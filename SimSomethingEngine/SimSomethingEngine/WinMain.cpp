#include "KingWin.h"
#include "Window.h"

int CALLBACK WinMain(
	HINSTANCE hInstance, 
	HINSTANCE hPrevInstance, 
	LPSTR lpCmdLine, 
	int nCmdShow)
{
	try
	{
		Window wnd(800, 300, "My Window 2");

		MSG msg;
		BOOL getResult;
		while ((getResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			if (wnd.input.KeyIsPressed(VK_MENU))
			{
				MessageBox(nullptr, "What Do You Want To Do?", "Button Pressed", MB_OK);
			}
		}

		if (getResult == -1)
		{
			return -1;
		}

		return msg.wParam;
	}
	catch (const KingException & e)
	{
		MessageBox(nullptr, e.what(), e.GetType(), MB_OK | MB_ICONEXCLAMATION);
	}
	catch (const std::exception & e)
	{
		MessageBox(nullptr, e.what(), "Standard Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	catch (...)
	{
		MessageBox(nullptr, "No details available", "Unknown Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	return -1;
}