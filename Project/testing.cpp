#include <iostream>
#include <windows.h>
#include <string>

// Helper function to convert std::string to std::wstring
std::wstring stringToWString(const std::string& str) {
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int)str.size(), NULL, 0);
    std::wstring wstrTo(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int)str.size(), &wstrTo[0], size_needed);
    return wstrTo;
}

int main() {
    std::string newPath;
    std::cout << "Enter the path to change to: ";
    std::getline(std::cin, newPath);

    std::wstring newPathW = stringToWString(newPath);

    if (SetCurrentDirectoryW(newPathW.c_str())) {
        std::wcout << L"Current working directory changed to: " << newPathW << std::endl;
    } else {
        std::cerr << "Error: Could not change the directory. Error code: " << GetLastError() << '\n';
    }

    return 0;
}
