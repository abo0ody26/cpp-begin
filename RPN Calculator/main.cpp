// Try to fix

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

#define MAX_CHARS MAX_PATH

int main(int argc, char *argv[])
{
    
    char input_str[MAX_CHARS+1], *p;
    stack<double> num_stack;
    int c;
    double a, b, n, x;
    cout << "Welcome to the RPN Calculator!" << endl;
    cout << "==============================" << endl;
    cout << "Enter RPN string: ";
    cin.getline(input_str, MAX_CHARS);
    p = strtok(input_str, " ");
    while (p) {
          c = p[0];
          if(c == '+' || c == '*' || c == '/' || c == '-'){
               if (num_stack.size() < 2) {
                   cout << "Error: too many ops." << endl;
                   system("PAUSE");
                   return - 1;
               }
          
         
               
          
               b = num_stack.top(); num_stack.pop();
               a = num_stack.top(); num_stack.pop();
               switch (c) {
                      case '+': n = a + b; break;
                      case '*': n = a * b; break;
                      case '/': n = a / b; break;
                      case '-': n = a - b; break;
                      }
                      num_stack.push(n);
               } else {
                      num_stack.push(atof(p));
               }
               
          if ( c == '#') {
              if (num_stack.size() < 1) {
                   cout << "Error: too many ops." << endl;
                   system("PAUSE");
                   return - 1;
                   }
                   x = num_stack.top(); num_stack.pop();
                   n = 1 / x; break;
                   num_stack.push(n);
               } else {
                      num_stack.push(atof(p));
               }
               
               p = strtok(NULL, " ");
          }
          
          
          
          
          
          
          
          
          
          cout << "The answer is: " << num_stack.top() << endl; 
               
    system("PAUSE");
    return EXIT_SUCCESS;
}
