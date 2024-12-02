// Voxels_gl.cpp : Defines the entry point for the application.
//

//#include "framework.h"
//#include "Voxels_gl.h"
//
//#define MAX_LOADSTRING 100
//
//// Global Variables:
//HINSTANCE hInst;                                // current instance
//WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
//WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
//
//// Forward declarations of functions included in this code module:
//ATOM                MyRegisterClass(HINSTANCE hInstance);
//BOOL                InitInstance(HINSTANCE, int);
//LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
//INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
//
//int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
//                     _In_opt_ HINSTANCE hPrevInstance,
//                     _In_ LPWSTR    lpCmdLine,
//                     _In_ int       nCmdShow)
//{
//    UNREFERENCED_PARAMETER(hPrevInstance);
//    UNREFERENCED_PARAMETER(lpCmdLine);
//
//    // TODO: Place code here.
//
//    // Initialize global strings
//    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
//    LoadStringW(hInstance, IDC_VOXELSGL, szWindowClass, MAX_LOADSTRING);
//    MyRegisterClass(hInstance);
//
//    // Perform application initialization:
//    if (!InitInstance (hInstance, nCmdShow))
//    {
//        return FALSE;
//    }
//
//    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_VOXELSGL));
//
//    MSG msg;
//
//    // Main message loop:
//    while (GetMessage(&msg, nullptr, 0, 0))
//    {
//        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
//        {
//            TranslateMessage(&msg);
//            DispatchMessage(&msg);
//        }
//    }
//
//    return (int) msg.wParam;
//}
//
//
//
////
////  FUNCTION: MyRegisterClass()
////
////  PURPOSE: Registers the window class.
////
//ATOM MyRegisterClass(HINSTANCE hInstance)
//{
//    WNDCLASSEXW wcex;
//
//    wcex.cbSize = sizeof(WNDCLASSEX);
//
//    wcex.style          = CS_HREDRAW | CS_VREDRAW;
//    wcex.lpfnWndProc    = WndProc;
//    wcex.cbClsExtra     = 0;
//    wcex.cbWndExtra     = 0;
//    wcex.hInstance      = hInstance;
//    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_VOXELSGL));
//    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
//    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
//    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_VOXELSGL);
//    wcex.lpszClassName  = szWindowClass;
//    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
//
//    return RegisterClassExW(&wcex);
//}
//
////
////   FUNCTION: InitInstance(HINSTANCE, int)
////
////   PURPOSE: Saves instance handle and creates main window
////
////   COMMENTS:
////
////        In this function, we save the instance handle in a global variable and
////        create and display the main program window.
////
//BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
//{
//   hInst = hInstance; // Store instance handle in our global variable
//
//   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
//      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
//
//   if (!hWnd)
//   {
//      return FALSE;
//   }
//
//   ShowWindow(hWnd, nCmdShow);
//   UpdateWindow(hWnd);
//
//   return TRUE;
//}
//
////
////  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
////
////  PURPOSE: Processes messages for the main window.
////
////  WM_COMMAND  - process the application menu
////  WM_PAINT    - Paint the main window
////  WM_DESTROY  - post a quit message and return
////
////
//LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//    switch (message)
//    {
//    case WM_COMMAND:
//        {
//            int wmId = LOWORD(wParam);
//            // Parse the menu selections:
//            switch (wmId)
//            {
//            case IDM_ABOUT:
//                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
//                break;
//            case IDM_EXIT:
//                DestroyWindow(hWnd);
//                break;
//            default:
//                return DefWindowProc(hWnd, message, wParam, lParam);
//            }
//        }
//        break;
//    case WM_PAINT:
//        {
//            PAINTSTRUCT ps;
//            HDC hdc = BeginPaint(hWnd, &ps);
//            // TODO: Add any drawing code that uses hdc here...
//            EndPaint(hWnd, &ps);
//        }
//        break;
//    case WM_DESTROY:
//        PostQuitMessage(0);
//        break;
//    default:
//        return DefWindowProc(hWnd, message, wParam, lParam);
//    }
//    return 0;
//}
//
//// Message handler for about box.
//INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
//{
//    UNREFERENCED_PARAMETER(lParam);
//    switch (message)
//    {
//    case WM_INITDIALOG:
//        return (INT_PTR)TRUE;
//
//    case WM_COMMAND:
//        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
//        {
//            EndDialog(hDlg, LOWORD(wParam));
//            return (INT_PTR)TRUE;
//        }
//        break;
//    }
//    return (INT_PTR)FALSE;
//}




#include <windows.h>
#include <windowsx.h>

#include <iostream>

#include <dwmapi.h>
#include "headerOne.h"
//#include "DrawClass.h"
#include <string_view>

import lLog;
import lMath;

//#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "dwmapi.lib")


HGLRC ourOpenGLRenderingContext;
HDC ourWindowHandleToDeviceContext;
HDC m_deviceContext;
HGLRC m_renderingContext;
HWND hWnd;
int destWidth;
int destHeight;
float n = 1.0f;

bool finished = false;
constexpr float FRAMES_PER_SECOND = 60.0f;

void RenderLos();

//DrawClass* myMainDraw;

void FullScreenOn() {


    auto style = GetWindowLong(hWnd, GWL_STYLE);
    auto ex_style = GetWindowLong(hWnd, GWL_EXSTYLE);

    //SetWindowLong(hWnd, GWL_STYLE, style & ~(WS_CAPTION | WS_THICKFRAME));
    //SetWindowLong(hWnd, GWL_EXSTYLE, ex_style & ~(WS_EX_DLGMODALFRAME | WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE | WS_EX_STATICEDGE));


    // On expand, if we're given a window_rect, grow to it, otherwise do
    // not resize.  

        //MONITORINFO monitor_info;
        //monitor_info.cbSize = sizeof(monitor_info);
        //GetMonitorInfo(MonitorFromWindow(hWnd, MONITOR_DEFAULTTONEAREST), &monitor_info);
        ////gfx::Rect window_rect(monitor_info.rcMonitor);
        //std::cout << " monitor_info.rcMonitor x == " << monitor_info.rcMonitor.left << " \n";
        //std::cout << " monitor_info.rcMonitor y == " << monitor_info.rcMonitor.top << " \n";
        //std::cout << " monitor_info.rcMonitor width == " <<  monitor_info.rcMonitor.right - monitor_info.rcMonitor.left << " \n";
        //SetWindowPos(hWnd, NULL, monitor_info.rcMonitor.left, monitor_info.rcMonitor.top,
        //    monitor_info.rcMonitor.right - monitor_info.rcMonitor.left, monitor_info.rcMonitor.bottom - monitor_info.rcMonitor.top,
        //    SWP_NOZORDER  | SWP_FRAMECHANGED);

        // SWP_NOACTIVATE

}

void loadConsole() {

    AllocConsole();
    AttachConsole(GetCurrentProcessId());
    FILE* stream;
    freopen_s(&stream, "CONOUT$", "w+", stdout);
    freopen_s(&stream, "CONOUT$", "w+", stderr);
    SetConsoleTitle(TEXT(" Our Console Window "));

}



auto composition_enabled() -> bool {
    BOOL composition_enabled = FALSE;
    bool success = ::DwmIsCompositionEnabled(&composition_enabled) == S_OK;
    return composition_enabled && success;
}


auto set_shadow(HWND handle, bool enabled) -> void {

    if (composition_enabled()) {
        static const MARGINS shadow_state[2]{ { 0,0,0,0 },{ 1,1,1,1 } };
        ::DwmExtendFrameIntoClientArea(handle, &shadow_state[enabled]);
    }
}



LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    if (message == WM_NCCREATE) {
        // auto userdata = reinterpret_cast<CREATESTRUCTW*>(lParam)->lpCreateParams;
        // ::SetWindowLongPtrW(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(userdata));

        return DefWindowProc(hWnd, message, wParam, lParam);
    }

    switch (message)
    {

    case WM_NCCALCSIZE: {
        {
            auto& params = *reinterpret_cast<NCCALCSIZE_PARAMS*>(lParam);
            //adjust_maximized_client_rect(hWnd, params.rgrc[0]);
            return 0;
        }
        break;
    }
    case WM_NCHITTEST: {
        //std::cout << " in this " << GET_X_LPARAM(lParam) << " \n";

      /*  if (myMainDraw != nullptr) {
            myMainDraw->emptyMousePlace(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
        }*/
        // When we have no border or title bar, we need to perform our
        // own hit testing to allow resizing and moving.
        {
            /*   return hit_test(POINT{
                   GET_X_LPARAM(lParam),
                   GET_Y_LPARAM(lParam)
                   });*/
        }
        break;
    }
    case WM_NCACTIVATE: {
        //if (!composition_enabled()) {
        //    // Prevents window frame reappearing on window activation
        //    // in "basic" theme, where no aero shadow is present.
        //    return 1;
        //}
        break;
    }


    case WM_CREATE:
    {
        // LosOutputStringConvert(" start in create ! ");
        PIXELFORMATDESCRIPTOR pfd =
        {
            sizeof(PIXELFORMATDESCRIPTOR),
            1,
            PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
            PFD_TYPE_RGBA,
            32,
            0, 0, 0, 0, 0, 0,
            0,
            0,
            0,
            0, 0, 0, 0,
            24,
            8,
            0,
            PFD_MAIN_PLANE,
            0,
            0, 0, 0
        };

        ourWindowHandleToDeviceContext = GetDC(hWnd);

        destWidth = LOWORD(lParam);
        destHeight = HIWORD(lParam);

        int  letWindowsChooseThisPixelFormat;
        letWindowsChooseThisPixelFormat = ChoosePixelFormat(ourWindowHandleToDeviceContext, &pfd);
        SetPixelFormat(ourWindowHandleToDeviceContext, letWindowsChooseThisPixelFormat, &pfd);

        ourOpenGLRenderingContext = wglCreateContext(ourWindowHandleToDeviceContext);
        wglMakeCurrent(ourWindowHandleToDeviceContext, ourOpenGLRenderingContext);

        //baseCall();


        typedef BOOL(WINAPI* PFNWGLCHOOSEPIXELFORMATARBPROC) (HDC hdc, const int* piAttribIList, const FLOAT* pfAttribFList, UINT nMaxFormats,
            int* piFormats, UINT* nNumFormats);

        typedef HGLRC(WINAPI* PFNWGLCREATECONTEXTATTRIBSARBPROC) (HDC hDC, HGLRC hShareContext, const int* attribList);
        typedef BOOL(WINAPI* PFNWGLSWAPINTERVALEXTPROC) (int interval);

        PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB;
        PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB;
        PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT;

        wglChoosePixelFormatARB = (PFNWGLCHOOSEPIXELFORMATARBPROC)wglGetProcAddress("wglChoosePixelFormatARB");
        wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");
        wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC)wglGetProcAddress("wglSwapIntervalEXT");

        wglMakeCurrent(NULL, NULL);
        wglDeleteContext(ourOpenGLRenderingContext);
        ourOpenGLRenderingContext = NULL;
        ReleaseDC(hWnd, ourWindowHandleToDeviceContext);
        ourWindowHandleToDeviceContext = 0;
        int attributeListInt[19];
        int pixelFormat2[1];
        unsigned int formatCount;
        int result;
        PIXELFORMATDESCRIPTOR pixelFormatDescriptor;
        int attributeList[5];
        float fieldOfView, screenAspect;
        char* vendorString, * rendererString;

        m_deviceContext = GetDC(hWnd);
        if (!m_deviceContext)
        {
            lLogs::logPrintWindowsClear(" no 777 device contex ");
            //LosOutputStringConvert("no 777 device context");
            return false;
        }

        attributeListInt[0] = WGL_SUPPORT_OPENGL_ARB;
        attributeListInt[1] = TRUE;
        attributeListInt[2] = WGL_DRAW_TO_WINDOW_ARB;
        attributeListInt[3] = TRUE;
        attributeListInt[4] = WGL_ACCELERATION_ARB;
        attributeListInt[5] = WGL_FULL_ACCELERATION_ARB;
        attributeListInt[6] = WGL_COLOR_BITS_ARB;
        attributeListInt[7] = 24;
        attributeListInt[8] = WGL_DEPTH_BITS_ARB;
        attributeListInt[9] = 24;
        attributeListInt[10] = WGL_DOUBLE_BUFFER_ARB;
        attributeListInt[11] = TRUE;
        attributeListInt[12] = WGL_SWAP_METHOD_ARB;
        attributeListInt[13] = WGL_SWAP_EXCHANGE_ARB;
        attributeListInt[14] = WGL_PIXEL_TYPE_ARB;
        attributeListInt[15] = WGL_TYPE_RGBA_ARB;
        attributeListInt[16] = WGL_STENCIL_BITS_ARB;
        attributeListInt[17] = 8;
        attributeListInt[18] = 0;

        int result1 = wglChoosePixelFormatARB(m_deviceContext, attributeListInt, NULL, 1, pixelFormat2, &formatCount);
        if (result1 != 1)
        {
            lLogs::logPrintWindowsClear(" Error to wglChoosePixelFormat ");
            //LosOutputStringConvert("Error to wglChoosePixelFormat", 21);
            return false;
        }


        result1 = SetPixelFormat(m_deviceContext, pixelFormat2[0], &pixelFormatDescriptor);
        if (result1 != 1)
        {
            lLogs::logPrintWindowsClear(" Error to setPixelPerfect ");
            //LosOutputStringConvert("Error to serPixelPerfect", 21);
            return false;
        }

        attributeList[0] = WGL_CONTEXT_MAJOR_VERSION_ARB;
        attributeList[1] = 4;
        attributeList[2] = WGL_CONTEXT_MINOR_VERSION_ARB;
        attributeList[3] = 3;
        attributeList[4] = 0;


        m_renderingContext = wglCreateContextAttribsARB(m_deviceContext, 0, attributeList);
        if (m_renderingContext == NULL)
        {
            //LosOutputStringConvert("no render context");
            return false;
        }


        result1 = wglMakeCurrent(m_deviceContext, m_renderingContext);
        if (result1 != 1)
        {
            //LosOutputStringConvert("sdf");
            return false;
        }

        wglSwapIntervalEXT(1);
        //losGraphics::CallingLoadingExtension();
        //myMainDraw = new DrawClass();

    }
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        switch (wmId)
        {

        case IDM_EXIT:
            wglDeleteContext(ourOpenGLRenderingContext);
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;


    case WM_KEYDOWN:

        //LosOutputStringConvert(" key down press ");

        if (lParam & (1 << 30)) {
            return 0;
        }

        switch (wParam) {
        case 'O':
            //LosOutputStringConvert(" press K ");

            // openFiles 
            std::cout << " press O our values " << " \n";

            char openedFileName[MAX_PATH];
            // if (openFileDialog(openedFileName)) {
            //     std::cout << " my file names = " << openedFileName << " \n";
            // }
             //callbackDo(a, openedFileName);
            return 0;


        case 'Q':
            //LosOutputStringConvert(" press Q ");
            //myMainDraw->changeDrawRenderAReady(); // = false;
            //myMainDraw->DestroyAll();
            finished = true;
            //DestroyAll();
            PostQuitMessage(0);
            return 0;


        case 'F': {

            std::cout << " FullScreen Mode on " << " \n";
            FullScreenOn();

            return 0;
        }


                break;
        }



        //switch (wParam) {
        //case 'Q':
        //    //LosOutputStringConvert(" press Q ");
        //    
        //    finished = true;
        //    //DestroyAll();
        //    PostQuitMessage(0);
        //    return 0;
        //}




    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        EndPaint(hWnd, &ps);
    }
    break;



    case WM_MOUSEWHEEL:
    {
        std::cout << " wheel mouse " << " \n";
    }


    case WM_LBUTTONUP:
    {
        std::cout << " left mouse UP  " << " \n";
        POINT pLos;
        ::GetCursorPos(&pLos);
        const long xSend = pLos.x - 200;
        const long ySend = pLos.y - 200;
        //myMainDraw->pressMouse(xSend, ySend, losMath::PressVaraint::MouseUp);
        break;
    }

    case WM_RBUTTONDOWN: {

        std::cout << " Right mouse Down  " << " \n";
        break;
    }

    case WM_RBUTTONUP: {


        std::cout << " Right button pressUP " << " \n";
        break;
    }

    case WM_MOUSEMOVE:
    {

        POINT pLos;
        ::GetCursorPos(&pLos);
        const long xSend = pLos.x - 200;
        const long ySend = pLos.y - 200;

        //myMainDraw->pressMouse(xSend, ySend, losMath::PressVaraint::MouseMove);

        break;
    }

    case WM_LBUTTONDOWN:
    {
        //LosOutputStringConvert("d);
        POINT pLos;
        ::GetCursorPos(&pLos);
        std::cout << " left qmouse Down  " << " \n";
        std::cout << " press buttonX " << pLos.x - 200 << " \n";
        std::cout << " press buttonY  " << pLos.y - 200 << " \n";
        const long xSend = pLos.x - 200;
        const long ySend = pLos.y - 200;
        //myMainDraw->pressMouse(xSend, ySend, losMath::PressVaraint::MouseDown);  // PressVaraint
        //LosOutputStringConvert(" press buttons ", pLos.x);
        //LosOutputStringConvert("press buttons ", pLos.y);


        RECT rectLos;
        ::GetClientRect(hWnd, &rectLos);
        //LosOutputStringConvert("get this touch ");

    }
    break;


    case WM_DESTROY:

        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}


bool openFileDialog(LPWSTR szFileName) {

    OPENFILENAME ofn;
    auto FilterSpec = L"Object Files(.obj)\0*.obj\0All Files(.)\0*.*\0*.glfw\0";
    auto Title = L"Open 3d file..";

    //LPWSTR szFileTitle[MAX_PATH] = " ";

    //WCHAR laskdjfalskdf = WCHAR("asldkfjaksdfkjashdjkfaskjdfjkasdhfsd");
    //LPWSTR szFileName2 = &laskdjfalskdf;

    //LPWSTR szFileName3 = "sdf";
    //WCHAR df(szFileName2);
    //*szFileName = 0;
    //wchar_t A{ "sdfsdf" };

  /* fill in non-variant fields of OPENFILENAME struct. */
    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.hwndOwner = hWnd; //GetFocus(); // 
    ofn.lpstrFilter = FilterSpec;
    ofn.lpstrCustomFilter = NULL;
    ofn.nMaxCustFilter = 0;
    ofn.nFilterIndex = 0;
    ofn.lpstrFile = szFileName;  // LPWSTR
    ofn.nMaxFile = MAX_PATH;
    ofn.lpstrInitialDir = L"."; // Initial directory.
    ofn.lpstrFileTitle = nullptr; // *szFileTitle;
    ofn.nMaxFileTitle = MAX_PATH;
    ofn.lpstrTitle = Title;
    ofn.lpstrDefExt = 0; // I've set to null for demonstration
    ofn.Flags = OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;


    return GetOpenFileName(&ofn);
}


int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int  nCmdShow)
{

    std::cout << " start in this " << " \n";



    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    loadConsole();
    lLogs::logPrintWindows();
    //std::function<void(LPWSTR szFileName)> callLoad;
    //callLoad = openFileDialog;

    WNDCLASSEXW wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW | CS_DROPSHADOW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;


    wcex.hIcon = (HICON)LoadImage(NULL, L"logo_los.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE | LR_SHARED);   // LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON2)); // was IDB_PNG1 IDI_RAYTRACINGOPENGL
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = 0;

    wcex.lpszClassName = L"loadOne";
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    RegisterClassExW(&wcex);

    lLogs::fileWriteWinAPi(std::string_view(" create Register Class "));

    destWidth = 1100;
    destHeight = 820;


    std::cout << " pre Width0 = " << destWidth << " \n";
    std::cout << " pre Height0  = " << destHeight << " \n";
    const wchar_t CLASS_NAME[20] = L"loadOne";

    hWnd = CreateWindowExA(0L, "loadOne", "Loskutnikov Games", WS_OVERLAPPEDWINDOW,
        200, 200, destWidth, destHeight, NULL, NULL, hInstance, NULL);


    lLogs::fileWriteWinAPi(std::string_view("createWindowExA"));

    if (!hWnd)
    {
        return FALSE;
    }

    auto destWidth1 = 1100;
    auto destHeight1 = 820;
    std::cout << " pre Width = " << destWidth1 << " \n";
    std::cout << " pre Height  = " << destHeight1 << " \n";
    //myMainDraw->setSize(destWidth1, destHeight1);
    //myMainDraw->buildP();
    //myMainDraw->setLoadCallback(callLoad);



    // ::SetWindowPos(hWnd, nullptr, 0, 0, 0, 0, SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE);
    // ::SetWindowPos(hWnd, nullptr, 300, 0, 0, 0, SWP_FRAMECHANGED  | SWP_NOSIZE);

     ///LosOutputStringConvert("in my InitInstance", 1);

    ::SetWindowLongPtrW(hWnd, GWL_STYLE, static_cast<LONG>(WS_POPUP | WS_THICKFRAME | WS_SYSMENU | WS_MAXIMIZEBOX | WS_MINIMIZEBOX));
    set_shadow(hWnd, true);

    //::SetWindowPos(hWnd, nullptr, 0, 0, 0, 0, SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE);
    //::ShowWindow(hWnd, SW_SHOW);


    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    lLogs::fileWriteWinAPi(std::string_view(" set Windows update "));


    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(109));
    MSG msg;

   // myMainDraw->renderReady();

    while (!finished) {
        DWORD currentTick = GetTickCount();
        DWORD endTick = currentTick + 1000 / FRAMES_PER_SECOND;

        while (currentTick < endTick) {
            if (PeekMessage(&msg, hWnd, 0, 0, PM_REMOVE)) {
                if (WM_QUIT == msg.message) {
                    // finished = true;
                    break;
                }
                else {
                    TranslateMessage(&msg);
                    DispatchMessage(&msg);
                }
                currentTick = GetTickCount();
            }
            else {
                break;
            }
        }

        RenderLos();
    }



    return EXIT_SUCCESS;
}





void RenderLos() {


    //myMainDraw->cleanColor();

    //myMainDraw->drawRectangle();

    SwapBuffers(m_deviceContext);
}