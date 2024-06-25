#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// Function prototypes
void clearScreen();
void echo(string message);
void getDate();
void getTime();
void getDir();
bool isCommand(string command);
void listCommands();
void readFile(string filename);
void writeFile(string filename, string content);

// List of available commands
vector<string> commands = {"clear", "echo", "date", "time", "dir", "help", "list", "read", "write", "exit"};

int main() {
  string input;

  while (true) {
    cout << "> ";
    getline(cin, input);

    if (isCommand(input)) {
      // Extract command and arguments
      string command = input.substr(0, input.find(" "));
      string argument = input.substr(input.find(" ") + 1);

      // Execute the command based on string comparison
      if (command == "clear") {
        clearScreen();
      } else if (command == "echo") {
        echo(argument);
      } else if (command == "date") {
        getDate();
      } else if (command == "time") {
        getTime();
      } else if (command == "dir") {
        getDir();
      } else if (command == "help" || command == "list") {
        listCommands();
      } else if (command == "read") {
        readFile(argument);
      } else if (command == "write") {
        writeFile(argument, ""); // Implement write functionality later
        cout << "Write functionality not implemented yet." << endl;
      } else if (command == "exit") {
        break;
      }
    } else {
      cout << "Invalid command. Type 'help' or 'list' for available commands." << endl;
    }
  }

  return 0;
}

// Function implementations

void clearScreen() {
  #ifdef _WIN32
    system("cls"); // For Windows
  #else
    system("clear"); // For Linux/macOS
  #endif
}

void echo(string message) {
  cout << message << endl;
}

void getDate() {
  // Use system time functions (e.g., ctime) to get and display date
  cout << "Date not implemented yet." << endl;
}

void getTime() {
  // Use system time functions (e.g., ctime) to get and display time
  cout << "Time not implemented yet." << endl;
}

void getDir() {
  // Use system calls (e.g., dir on Windows) to list directory contents
  #ifdef _WIN32
    system("dir");
  #else
    // Implement for other OS using appropriate commands
    cout << "Directory listing not implemented yet for non-Windows systems." << endl;
  #endif
}

bool isCommand(string input) {
  // Check if the input matches any of the available commands
  for (string command : commands) {
    if (command == input) {
      return true;
    }
  }
  return false;
}

void listCommands() {
  cout << "Available commands:" << endl;
  for (string command : commands) {
    cout << "- " << command << endl;
  }
}

void readFile(string filename) {
  ifstream file(filename);
  if (file.is_open()) {
    string line;
    while (getline(file, line)) {
      cout << line << endl;
    }
    file.close();
  } else {
    cout << "Error: Could not open file '" << filename << "'." << endl;
  }
}

void writeFile(string filename, string content) {
  // Implement functionality to write content to a file
  cout << "Write functionality not implemented yet." << endl;
}
