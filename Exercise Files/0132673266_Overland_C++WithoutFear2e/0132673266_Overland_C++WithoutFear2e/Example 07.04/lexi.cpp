#include <iostream>
#include <cstring>
using namespace std;
int main() {
    char the_string[81], *p;
    
    cout << "Input a string to parse: ";
    cin.getline(the_string, 81);
    p = strtok(the_string, ", ");
    while (p != NULL) {
        cout << p << endl;
    p = strtok(NULL, ", ");
    }
    system("PAUSE");
    return 0;
}
