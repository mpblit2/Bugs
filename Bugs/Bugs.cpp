// Bugs.cpp: Okre�la punkt wej�cia dla aplikacji.
//

#include "stdafx.h"
#include "Bugs.h"
#include <boost\any.hpp>

#include <SFML/Graphics.hpp>



// Let's define some constants for the window.

constexpr unsigned int wndWidth{ 800 }, wndHeight{ 600 };

int main()

{

	// Now we'll create the window.



	// The class is named `sf::RenderWindow`, and the constructor

	// requires an `sf::Vector2u` (size of the window), and an

	// `std::string` (title of the window).

	sf::RenderWindow window{ { wndWidth, wndHeight }, "Arkanoid - 1" };



	// Instead of explicitly specifying the `sf::Vector2u` type,

	// we used the {...} uniform initialization syntax.



	// We'll also set a limit to the framerate, ensuring that the

	// game logic will run at a constant speed.

	window.setFramerateLimit(60);



	// The next step is "keeping the window alive".

	// This is where the "game loop" comes into play.

	// {Info: game loop}



	while (true)

	{

		// Every iteration of this loop is a "frame" of our game.

		// We'll begin our frame by clearing the window from previously

		// drawn graphics.

		window.clear(sf::Color::Black);



		// Then we'll check the input state. In this case, if the

		// player presses the "Escape" key, we'll jump outside of the

		// loop, destroying the window and terminating the program.

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) break;



		// Show the window's contents.

		window.display();

	}



	return 0;

}

/*
#define MAX_LOADSTRING 100

// Zmienne globalne:
HINSTANCE hInst;                                // bie��ce wyst�pienie
WCHAR szTitle[MAX_LOADSTRING];                  // Tekst paska tytu�u
WCHAR szWindowClass[MAX_LOADSTRING];            // nazwa klasy okna g��wnego

// Przeka� dalej deklaracje funkcji do��czonych w tym module kodu:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{

	UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: W tym miejscu umie�� kod.
	boost::any dupa;
	dupa = 1;

    // Zainicjuj ci�gi globalne
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_BUGS, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Wykonaj inicjacje aplikacji:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_BUGS));

    MSG msg;

    // G��wna p�tla wiadomo�ci:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNKCJA: MyRegisterClass()
//
//  CEL: Rejestruje klas� okna.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_BUGS));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_BUGS);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNKCJA: InitInstance(HINSTANCE, int)
//
//   CEL: Zapisuje doj�cie wyst�pienia i tworzy okno g��wne
//
//   KOMENTARZE:
//
//        W tej funkcji doj�cie wyst�pienia jest zapisywane w zmiennej globalnej i
//        jest tworzone i wy�wietlane okno g��wne programu.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Przechowuj doj�cie wyst�pienia w zmiennej globalnej

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNKCJA: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  CEL: Przetwarza wiadomo�ci dla okna g��wnego.
//
//  WM_COMMAND � przetwarzaj menu aplikacji
//  WM_PAINT � pomaluj okno g��wne
//  WM_DESTROY � opublikuj komunikat o rezygnacji i wr��
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Analizuj zaznaczenia menu:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: tutaj dodaj kod rysowania u�ywaj�cy elementu hdc...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

//Procedura obs�ugi wiadomo�ci dla okna informacji o programie.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

*/

