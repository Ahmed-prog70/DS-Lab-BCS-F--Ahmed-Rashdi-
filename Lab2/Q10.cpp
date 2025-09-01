#include <iostream>
#include <string>
using namespace std;

int main() {
    int numCategories;
    cout << "Enter number of book categories: ";
    cin >> numCategories;
    
    if (numCategories <= 0) {
        cout << "Invalid input" << endl;
        return 1;
    }
    
    string* categories = new string[numCategories];
    int** bookIDs = new int*[numCategories];
    int* bookCounts = new int[numCategories];
    
    for (int i = 0; i < numCategories; i++) {
        cout << "\nEnter category " << (i + 1) << " name: ";
        cin >> categories[i];
        
        cout << "Enter number of books in " << categories[i] << ": ";
        cin >> bookCounts[i];
        
        while (bookCounts[i] <= 0) {
            cout << "Please enter a positive number: ";
            cin >> bookCounts[i];
        }
        bookIDs[i] = new int[bookCounts[i]];
        
        cout << "Enter " << bookCounts[i] << " book IDs for " << categories[i] << ":\n";
        for (int j = 0; j < bookCounts[i]; j++) {
            cout << "Book " << (j + 1) << " ID: ";
            cin >> bookIDs[i][j];
        }
    }
    cout << "LIBRARY BOOK INVENTORY\n";
    
    for (int i = 0; i < numCategories; i++) {
        cout << "\nCategory: " << categories[i] << " (" << bookCounts[i] << " books)\n";
        cout << "Book IDs: ";
        for (int j = 0; j < bookCounts[i]; j++) {
            cout << bookIDs[i][j];
            if (j < bookCounts[i] - 1) cout << ", ";
        }
        cout << endl;
    }
    
    char searchAgain;
    do {
        int searchID;
        bool found = false;

        cout << "BOOK SEARCH\n";
        cout << "Enter book ID to search: ";
        cin >> searchID;

        for (int i = 0; i < numCategories; i++) {
            for (int j = 0; j < bookCounts[i]; j++) {
                if (bookIDs[i][j] == searchID) {
                    cout << "Book FOUND!\n";
                    cout << "Category: " << categories[i] << endl;
                    cout << "Book ID: " << searchID << endl;
                    cout << "Status: AVAILABLE\n";
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        
        if (!found) {
            cout << "Book NOT FOUND!\n";
            cout << "Book ID " << searchID << " is not available.\n";
        }
        
        cout << "\nSearch for another book? (Y/N): ";
        cin >> searchAgain;
        
    } while (searchAgain == 'Y' || searchAgain == 'y');
    
    for (int i = 0; i < numCategories; i++) {
        delete[] bookIDs[i];
    }
    delete[] bookIDs;
    delete[] categories;
    delete[] bookCounts;
    
    cout << "\nMemory cleaned up successfully!\n";
    
    return 0;
}
