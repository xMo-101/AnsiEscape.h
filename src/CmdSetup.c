#ifdef _WIN32
#include <windows.h>
#include <stdio.h>

int main() {
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE); 
    DWORD mode = 0;

    // Get current mode
    GetConsoleMode(hStdin, &mode);

    // Disable line input and echo
    mode &= ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT);
    SetConsoleMode(hStdin, mode);

    // USE CONSOLE NORMALLY:
    // FOR EXAMPLE:
    char c;
    printf("Type a character: ");
    ReadConsole(hStdin, &c, 1, NULL, NULL);
    printf("\nYou typed: %c\n", c);

    // Restore original settings if needed
    SetConsoleMode(hStdin, originalMode);

    return 0;
}

#endif // _WIN32