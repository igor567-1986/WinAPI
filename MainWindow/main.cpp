#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<stdio.h>

CONST CHAR gsz_MY_WINDOW_CLASS[] = "MyWindowClass";
CONST CHAR gsz_WINDOW_NAME[] = "My Firs Window";

INT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	//1) Регистрация класса окна:
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(wc));

	wc.cbSize = sizeof(wc);
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.style = 0;
	wc.hIcon =(HICON) LoadImage(hInstance,"palm.ico",IMAGE_ICON,LR_DEFAULTSIZE,LR_DEFAULTSIZE,LR_LOADFROMFILE);
	wc.hIconSm =(HICON) LoadImage(hInstance, "Star.ico", IMAGE_ICON, LR_DEFAULTSIZE, LR_DEFAULTSIZE, LR_LOADFROMFILE);
	wc.hCursor = (HICON)LoadCursorFromFile("Working In Background.ani");
	//wc.hCursor = LoadCursor(hInstance, IDC_ARROW);
	wc.hInstance = hInstance;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = gsz_MY_WINDOW_CLASS;

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Class registration failed", "Error", MB_OK | MB_ICONERROR);
		return 0;
	}

	//2) Создание окна:
	int screen_width = GetSystemMetrics(SM_CXSCREEN);
	int screen_height = GetSystemMetrics(SM_CYSCREEN);
	int window_width = screen_width * 3/ 4;
	int window_height = screen_height * 3 / 4;
	//int window_width = g_START_X * 3.5 + (g_BUTTON_SIZE + g_INTERVAL) * 5;
	//int window_height = g_START_Y + (g_BUTTON_SIZE + g_INTERVAL) * 4 + g_INTERVAL * 2 + 55;
	int start_x = screen_width / 8;
	int start_y = screen_height / 8;

	HWND hwnd = CreateWindowEx
	(
		NULL,	//ExStyle
		gsz_MY_WINDOW_CLASS,	//Class name
		gsz_WINDOW_NAME,		//Window name
		//WS_OVERLAPPEDWINDOW,	//dwStyle
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,	//dwStyle
		start_x, start_y,	//Начальная позиция окна
		window_width, window_height,	//Размер окна
		NULL,		//HWND родительского окна. У главного окна НЕТ родительского окна
		NULL,		//Menu отсутствует
		hInstance,
		NULL
	);
	if (hwnd == NULL)
	{
		MessageBox(NULL, "Window creation failed", "Error", MB_OK | MB_ICONERROR);
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);	//Задает режим отображения окна (свернуто в окно, развернуто на весь экран, свернуто на панель задач.....)
	UpdateWindow(hwnd);	//Прорисовывает содержимое окна

	//3) Запуск цикла сообщений:
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}
INT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:break;
	case WM_COMMAND:break;
	case WM_SIZE:
	case WM_MOVE:
	{

		RECT rect;
		GetWindowRect(hwnd, &rect);
		CONST INT SIZE = 256;
		CHAR sz_buffer[SIZE] = {};
		sprintf(sz_buffer, "%s,Position:%dx%d, Size:%dx%d", gsz_WINDOW_NAME,
			rect.left, rect.top,
			rect.right - rect.left, rect.bottom - rect.top);
		SendMessage(hwnd, WM_SETTEXT, 0, (LPARAM)sz_buffer);
	}
		break;
	case WM_DESTROY:PostQuitMessage(0); break;
	case WM_CLOSE:
		switch (MessageBox(hwnd, 
			"Вы действительно закрыть окно",
			"Вопрос на миллион доллоров",
			MB_YESNO | MB_ICONQUESTION))
		{
		case IDYES:
			MessageBox(hwnd, "Лучше б двери закрыли)", "Полезная инфа", MB_OK | MB_ICONINFORMATION);
			DestroyWindow(hwnd);
			break;
		}
		break;
		DestroyWindow(hwnd); break;
	default:return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return 0;
}