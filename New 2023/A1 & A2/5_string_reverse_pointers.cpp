#include <iostream>
#include <cstring>
using namespace std;

void reverse(char *str)
{
    char *ptr = str + strlen(str) - 1;   
    while (ptr >= str) {
        cout << *ptr;
        ptr--;
    }
    cout << endl;
}

int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    cout << "Reversed string: ";
    reverse(&str[0]);
    return 0;
}