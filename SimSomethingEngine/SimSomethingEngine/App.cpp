#include "App.h"


App::App()
{

}

App::App(const App& other)
{

}

App::~App()
{

}

bool App::Init()
{
	int screenWidth, screenHeight;
	bool result;

	// Initialize the width and height of the screen to zero before sending the variables into the function.
	screenWidth = 0;
	screenHeight = 0;

	//Init windows api.
	InitWindow(screenWidth, screenHeight);

	//Init Input


	//Init Graphics.

	return true;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:
		PostQuitMessage(99);
		break;
		// All other messages pass to the message handler in the system class.
		//WORK OUT WHY THIS DONT CLOSE THE APP.
		//ON TUT 5.
	default:
	{
		return ApplicationHandle->MessageHandler(hWnd, msg, wParam, lParam);
	}
	}

		if (wParam == 'F')
		{
			SetWindowText(hWnd, "Respects");
		}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

void App::InitWindow(int& screenWidth, int& screenHeight)
{
	ApplicationHandle = this;

	// Get the instance of this application.
	hInstance = GetModuleHandle(NULL);

	const auto pClassName = "SimSomething";
	//Register Windows Class
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = pClassName;
	wc.hIconSm = nullptr;
	RegisterClassEx(&wc);

	//Create window instance
	HWND hWnd = CreateWindowEx(
		0, pClassName,
		"My Window", WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200, 200, 640, 480,
		nullptr, nullptr, hInstance, nullptr);
	ShowWindow(hWnd, SW_SHOW);
}

void App::Run()
{
	MSG msg;
	bool done;
	bool result;

	// Initialize the message structure.
	ZeroMemory(&msg, sizeof(MSG));

	// Loop until there is a quit message from the window or the user.
	done = false;
	while (!done)
	{
		// Handle the windows messages.
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		// If windows signals to end the application then exit out.
		if (msg.message == WM_QUIT)
		{
			done = true;
		}
		else
		{
			// Otherwise do the frame processing.
			result = Frame();
			if (!result)
			{
				done = true;
			}
		}
	}

	return;
}

bool App::Frame()
{
	return true;
}

void App::ShutDownWindows()
{

}

LRESULT CALLBACK App::MessageHandler(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)
{
	switch (umsg)
	{
		// Check if a key has been pressed on the keyboard.
	case WM_KEYDOWN:
	{
		// If a key is pressed send it to the input object so it can record that state.
		//m_Input->KeyDown((unsigned int)wparam);
		return 0;
	}

	// Check if a key has been released on the keyboard.
	case WM_KEYUP:
	{
		// If a key is released then send it to the input object so it can unset the state for that key.
		//m_Input->KeyUp((unsigned int)wparam);
		return 0;
	}

	// Any other messages send to the default message handler as our application won't make use of them.
	default:
	{
		return DefWindowProc(hwnd, umsg, wparam, lparam);
	}
	}
}
