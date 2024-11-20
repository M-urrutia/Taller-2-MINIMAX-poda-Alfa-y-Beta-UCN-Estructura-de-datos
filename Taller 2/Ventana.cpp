#include <windows.h>

#define ID_BOTON_1 1

// Procedimiento de la ventana para manejar los eventos (incluyendo el botón)
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_COMMAND:
            if (LOWORD(wParam) == ID_BOTON_1) // Si se hace clic en el botón
            {
                // Crear una nueva ventana secundaria
                HWND hwndSecundaria = CreateWindowEx(
                    0,                              // Estilo extendido (0 en este caso)
                    "SecundariaClase",               // Clase de la ventana secundaria
                    "Ventana Secundaria",            // Título de la ventana secundaria
                    WS_OVERLAPPEDWINDOW,             // Estilo de la ventana
                    CW_USEDEFAULT, CW_USEDEFAULT,   // Posición
                    400, 300,                       // Tamaño de la ventana secundaria
                    nullptr,                         // Ventana principal como parent
                    nullptr,                         // Sin menú
                    GetModuleHandle(nullptr),       // HINSTANCE
                    nullptr                          // Parámetros adicionales
                );

                if (hwndSecundaria) 
                {
                    ShowWindow(hwndSecundaria, SW_SHOW);  // Mostrar la ventana secundaria
                    UpdateWindow(hwndSecundaria);         // Actualizar la ventana secundaria
                }
            }
            break;

        case WM_DESTROY:
            PostQuitMessage(0);  // Terminar el programa cuando la ventana se cierra
            break;

        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int main()
{
    const char* className = "MiVentanaClase";

    // Definir la clase de la ventana principal
    WNDCLASS wndClass = {};
    wndClass.lpfnWndProc = WindowProcedure;   // Procedimiento para los eventos de la ventana
    wndClass.hInstance = GetModuleHandle(nullptr); // Handle del programa
    wndClass.lpszClassName = className;  // Nombre de la clase

    // Registrar la clase de la ventana
    if (!RegisterClass(&wndClass))
    {
        MessageBox(nullptr, "No se pudo registrar la clase de la ventana.", "Error", MB_OK | MB_ICONERROR);
        return -1;
    }

    // Crear la ventana principal
    HWND hwnd = CreateWindowEx(
        0,                              // Estilo extendido (0 en este caso)
        className,                      // Clase de la ventana
        "Ventana Principal con Botón",   // Título de la ventana
        WS_OVERLAPPEDWINDOW,            // Estilo de la ventana
        CW_USEDEFAULT, CW_USEDEFAULT,   // Posición
        800, 600,                       // Tamaño
        nullptr,                        // Ventana principal (sin ventana padre)
        nullptr,                        // Menú (no utilizamos un menú)
        GetModuleHandle(nullptr),       // HINSTANCE
        nullptr                         // Parámetros adicionales
    );

    if (!hwnd)
    {
        MessageBox(nullptr, "No se pudo crear la ventana.", "Error", MB_OK | MB_ICONERROR);
        return -1;
    }

    // Crear el botón
    HWND hButton = CreateWindow(
        "BUTTON",                        // Clase del botón
        "Abrir ventana secundaria",      // Texto del botón
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, // Estilos del botón
        10, 10,                          // Posición del botón (X, Y)
        200, 40,                         // Tamaño del botón (ancho, alto)
        hwnd,                            // Ventana principal como padre
        (HMENU)ID_BOTON_1,               // ID del botón (para identificarlo en WM_COMMAND)
        GetModuleHandle(nullptr),        // HINSTANCE
        nullptr                          // Parámetros adicionales
    );

    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);

    // Bucle de mensajes
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
