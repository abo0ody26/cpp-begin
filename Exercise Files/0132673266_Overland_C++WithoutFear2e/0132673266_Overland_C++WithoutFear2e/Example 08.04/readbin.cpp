#include <iostream>
#include <fstream>
using namespace std;

int get_int(int default_value);
char name[20];

int main() {
    char filename[81];
    int n;
    int age;
    int recsize =  sizeof(name) + sizeof(int);
    

    cout << "Enter file name: ";
    cin.getline(filename, 80);

    // Open file for binary read access.

    fstream  fbin(filename, ios::binary | ios::in);
    if (!fbin) {
        cout << "Could not open file " << filename << endl;
        system("PAUSE");
        return -1;
    }

	while(1) {

        // Get record number and go to record.

        cout << "Enter file record number (-1 to quit): ";
        n = get_int(-1);
		if (n == -1)
		    break;
        
		fbin.seekp(n * recsize);

        // Read data from the file.

        fbin.read(name, 20);
        fbin.read(reinterpret_cast<char*>(&age), sizeof(int));

        // Display the data and close.
    
        cout << "The name is: " << name << endl;
        cout << "The age is: " << age << endl;
    }
    fbin.close();
    system("PAUSE");
    return 0;
}

// Get integer function
// Get an integer from keyboard; return default
//  value if user enters 0-length string.
//
int get_int(int default_value) {
    char s[81];

    cin.getline(s, 80);
    if (strlen(s) == 0)
         return default_value;
    return atoi(s);
}
