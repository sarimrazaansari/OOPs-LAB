#include <iostream>
#include <fstream>
#include <string> // Added for better line handling
using namespace std;

int main() {
    char name[100];
    cout << "Enter name: ";
    cin.getline(name, 100);

    // 1. Append the name to the file
    fstream myfile("xyz.txt", ios::app | ios::out); 
    if (myfile.is_open()) {
        myfile << name << "\n";
        myfile.close();
        cout << "File updated successfully." << endl;
    }

    cout << "You just entered: " << name << endl;

    // 2. Open the file to READ everything
    // We use ios::in to tell C++ we are reading now
    myfile.open("xyz.txt", ios::in); 

    if (myfile.is_open()) {
        cout << "-------------- File Content -----------" << endl;
        
        string line;
        string word;
        // This loop reads the file until there are no lines left
        while (getline(myfile, line)) {
            cout << line << endl;
        }
    

        // --- THE FIX STARTS HERE ---
        myfile.clear();  // Clear EOF flags
        myfile.seekg(0); // Move cursor back to start
        // ---------------------------

        while (myfile >> word) {
            cout << "Found name: " << word << endl;
        }
        myfile.close();
        cout << "---------------------------------------" << endl;

        
    } else {
        cout << "Error: Could not open file for reading." << endl;
    }

    return 0;
}