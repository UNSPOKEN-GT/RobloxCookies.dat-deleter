#include <iostream>
#include <filesystem>
#include <fstream>
#include <Windows.h>

namespace t_fs = std::filesystem;

std::string expand(const std::string& path) {
    char expandedPath[MAX_PATH];
    ExpandEnvironmentStringsA(path.c_str(), expandedPath, MAX_PATH);
    return std::string(expandedPath);
}

void consoleColor(WORD color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void printColor(const std::string& prefix, const std::string& message, WORD color) {
    consoleColor(color);
    std::cout << prefix;
    consoleColor(7);
    std::cout << message << '\n';
}

int main() {
    SetConsoleTitleA("- Made by GONDO -");

    std::string filePath = "%localappdata%\\Roblox\\LocalStorage\\RobloxCookies.dat";
    std::string expandedPath = expand(filePath);

    std::ifstream file(expandedPath);
    if (file.good()) {
        file.close();

        printColor("[+]", " : File exists, attempting to delete...\n", 1);

        if (std::remove(expandedPath.c_str()) == 0) {
            printColor("[-]", " : File successfully deleted.", 2);
        }
        else {
            printColor("[<!>]", " : Error deleting file", 4);
        }
    }
    else {
        printColor("[!]", " : The file '" + expandedPath + "' does not exist.", 6);
    }

    std::cout << "\nPress Escape to close the terminal..";
    std::cin.get();

    return 0;
}
