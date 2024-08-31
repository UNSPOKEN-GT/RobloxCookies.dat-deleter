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

int main() {
    SetConsoleTitleA("Made by GONDO");

    std::string filePath = "%localappdata%\\Roblox\\LocalStorage\\RobloxCookies.dat";
    std::string expandedPath = expand(filePath);

    std::ifstream file(expandedPath);
    if (file.good()) {
        file.close();

        std::cout << "File exists, attempting to delete...\n";

        if (std::remove(expandedPath.c_str()) == 0) {
            std::cout << "File successfully deleted.\n\nPress Escape to close the terminal..";
        } else {
            std::perror("Error deleting file");
        }
    } else {
        std::cout << "The file " << expandedPath << " does not exist.\n\nPress Escape to close the terminal..";
    }
    
    std::cin.get();

    return 0;
}