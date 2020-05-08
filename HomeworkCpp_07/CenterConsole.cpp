#include "CenterConsole.h"

void CenterConsole::Center(std::string line)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    
    if (hStdOut == INVALID_HANDLE_VALUE)
    {
        return;
    }

    COORD cursorPos;
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    int ConsoleWindowWidth;
    int ConsoleWindowHeight;
    int ConsoleCursorTop;

    if (GetConsoleScreenBufferInfo(hStdOut, &consoleInfo))
    {
        ConsoleWindowWidth = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
        
        ConsoleCursorTop = consoleInfo.dwCursorPosition.Y;
    }

    for (int i = 0, release = 0; i < line.length(); i += release)
    {
        if (line.length() - release < ConsoleWindowWidth)
        {
            cursorPos.X = ConsoleWindowWidth / 2 - (line.length() - release) / 2;
            cursorPos.Y = ConsoleCursorTop;

            SetConsoleCursorPosition(hStdOut, cursorPos);
            std::cout << line.substr(release) << std::endl;
            release = line.length();
        }
        else
        {
            std::cout << line.substr(release, ConsoleWindowWidth) << std::endl;
            release += ConsoleWindowWidth;
        }
    }
}
