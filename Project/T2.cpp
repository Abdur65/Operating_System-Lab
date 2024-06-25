// C213031

// Libraries required
#include <bits/stdc++.h>
#include <windows.h>
#include <chrono>
#include <ctime>
#include <shellapi.h>

using namespace std;

// Function prototypes
void clearScreen();
void echo(string message);
void getDate();
void getTime();
void getDir();
bool isCommand(string command);
void listCommands();
void ShowCurrentDirectory();
void readFile(string filename);
string read_file(const string &filename);
void writeFile(string filename);
void createFile(string filename);
bool createNewDirectory(const string& directoryPath);
wstring stringToWstring(const string& str);
bool mkdir(const string& dirname);
void del(const string& filename);
void renameFile(string filename);

// Vector that consists of all the acceptable commands
vector<string> commands = {"clear", "echo", "date", "time", "dir", "manual", "read", "write", "create", "currpath", "exit", "makedir", "delete", "rename"};

int main()
{
    string input;
    // List of available commands

    while (true)
    {
        cout << ">> ";
        getline(cin, input);
        // Extract command and arguments
        string command = input.substr(0, input.find(" "));
        string argument = input.substr(input.find(" ") + 1);

        // cout << command << " " << argument << endl;

        // Checks whether the input command is a valid one
        if (isCommand(command))
        {
            // Execute the command based on string comparison
            if (command == "clear")
            {
                clearScreen();
            }
            else if (command == "echo")
            {
                echo(argument);
            }
            else if (command == "date")
            {
                getDate();
            }
            else if (command == "time")
            {
                getTime();
            }
            else if (command == "dir")
            {
                getDir();
            }
            else if (command == "manual")
            {
                listCommands();
            }
            else if (command == "read")
            {
                readFile(argument);
            }
            else if (command == "write")
            {
                writeFile(argument);
            }
            else if (command == "currpath")
            {
                ShowCurrentDirectory();
            }
            else if (command == "create")
            {
                createFile(argument);
            }
            else if(command == "makedir")
            {
                mkdir(argument);
            }
            else if(command == "delete")
            {
                del(argument);
            }
            else if(command == "rename")
            {
                renameFile(argument);
            }
            else if (command == "exit")
            {
                break;
            }
        }
        else
        {
            cout << "Invalid command. Type 'help' or 'list' for available commands." << endl;
        }
    }
    return 0;
}

// Function implementations

// Checking for valid command
bool isCommand(string input)
{
    // Check if the input matches any of the available commands
    for (string command : commands)
    {
        if (command == input)
        {
            return true;
        }
    }
    return false;
}

// Listing all the available commands
void listCommands()
{
    cout << "\t------------------------ Available commands ----------------------" << endl;
    cout << "\t_________________________________________________________________" << endl;
    cout << endl;
    cout << "\t|\tmanual - lists all the available commands.          \t|" << endl;
    cout << "\t|\tclear - clears the terminal screen.               \t|" << endl;
    cout << "\t|\techo - prints out a message.                      \t|" << endl;
    cout << "\t|\tdate - shows the current date.                    \t|" << endl;
    cout << "\t|\ttime - shows the current time.                    \t|" << endl;
    cout << "\t|\tdir - show the contents of the directory.         \t|" << endl;
    cout << "\t|\tcurrpath - show the current directory path.       \t|" << endl;
    cout << "\t|\tcreate (filename) - creates a file.               \t|" << endl;
    cout << "\t|\twrite (filename) - write contents on a file.      \t|" << endl;
    cout << "\t|\tread (filename) - read contents of a file.        \t|" << endl;
    cout << "\t|\trename (filename) - rename a file.                \t|" << endl;
    cout << "\t|\tdelete (filename) - delete a file.                   \t|" << endl;
    cout << "\t|\tmakedir (directory name) - create a new directory.\t|" << endl;
    cout << "\t|\texit - exit from the terminal.                    \t|" << endl;
    cout << "\t_________________________________________________________________" << endl;
}

// Clearing the screen
void clearScreen()
{
    system("cls"); // For Windows
}

// Printing out a text
void echo(string message)
{
    cout << message << endl;
}

// Showing the current date on the device
void getDate()
{
    time_t now = time(0);            // Get current time in seconds
    tm *localTime = localtime(&now); // Convert to local time structure

    // Format date string using strftime
    char formattedDate[80];
    strftime(formattedDate, 80, "%d-%m-%Y", localTime); // YYYY-MM-DD format
    cout << "Date: " << formattedDate << endl;
}

// Showing the current time on the device
void getTime()
{
    time_t now = time(0);            // Get current time in seconds
    tm *localTime = localtime(&now); // Convert to local time structure

    // Format time string using strftime
    char formattedTime[80];
    strftime(formattedTime, 80, "%H:%M:%S", localTime); // HH:MM:SS format
    cout << "Time: " << formattedTime << endl;
}

// For getting the contents of directory
void getDir()
{
    // Use system calls (e.g., dir on Windows) to list directory contents
    system("dir");
}

// Show file path of current directory
void ShowCurrentDirectory()
{
    char buffer[MAX_PATH];
    GetCurrentDirectoryA(MAX_PATH, buffer);
    cout << string(buffer) << endl;
}

// For reading from file
void readFile(string filename)
{
    string file_content = read_file(filename);

    if (!file_content.empty())
    {
        cout << "File content:\n"
             << file_content << endl;
    }
}
string read_file(const string &filename)
{
    string content;
    ifstream file(filename);

    // Check if file is open
    if (file.is_open())
    {
        // Read the entire file content into a string
        string line;
        while (getline(file, line))
        {
            content += line + "\n";
        }
        file.close();
    }
    else
    {
        cerr << "Error: Could not open file: " << filename << endl;
    }

    return content;
}

// Writing on a file
void writeFile(string filename)
{
    string content;
    cout << "Enter content to write to file '" << filename << "': ";
    getline(cin, content);
    content += "\n";

    ofstream outfile(filename, ios::out | ios::app);

    if (outfile.is_open())
    {
        outfile << content << endl;
        cout << "Successfully appended to file: " << filename << endl;
    }
    else
    {
        cerr << "Error opening file: " << filename << endl;
    }

    outfile.close();
}

// For creating a new file
void createFile(string filename)
{
    ofstream outfile(filename);
    if (outfile.is_open())
    {
        std::cout << "File " << filename << " created successfully." << std::endl;
        // You can now write to the file using outfile
    }
    else
    {
        std::cerr << "Error creating file: " << filename << std::endl;
    }

    // Close the file (automatically done when the object goes out of scope,
    // but good practice to close explicitly)
    outfile.close();
}

// Helper function to convert string to wstring
wstring stringToWstring(const string& str) {
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int)str.size(), NULL, 0);
    wstring wstrTo(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int)str.size(), &wstrTo[0], size_needed);
    return wstrTo;
}

// Deleting file
void del(const string& filename)
{
    if (remove(filename.c_str()) == 0) {
        std::cout << "File deleted successfully.\n";
    } else {
        std::perror("Error deleting file");
    }
}

// Renaming files
void renameFile(string filename)
{
    string oldPath, newPath;
    oldPath = filename;
    cout << "Enter the new name of the file: ";
    getline(cin, newPath);

    wstring oldPathW = stringToWstring(oldPath);
    wstring newPathW = stringToWstring(newPath);

    if (MoveFileW(oldPathW.c_str(), newPathW.c_str())) {
        cout << "Renamed successfully.\n";
    } else {
        cerr << "Error: Could not rename the file/folder. Error code: " << GetLastError() << '\n';
    }
}

// Create a new directory
bool mkdir(const string& dirname)
{
    wstring wDirectoryPath = stringToWstring(dirname);
    if (CreateDirectoryW(wDirectoryPath.c_str(), NULL) || GetLastError() == ERROR_ALREADY_EXISTS) {
        cout << "New directory created" << endl;
        return true; // Directory created successfully or already exists
    } else {
        // Error occurred, print the error message
        cerr << "Error: Unable to create directory. Error code: " << GetLastError() << endl;
        return false;
    }
}
