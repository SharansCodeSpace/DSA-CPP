#include <iostream>
using namespace std;

bool isprime(int x)
{
    for (int i = 2; i <= x - 1; i++)
        if (x % i == 0)
            return false;
    return true;
}

int main()
{
    cout << "Enter a number: ";
    int x;
    cin >> x;
    if (isprime(x))
        cout << "Prime Number!" << endl;
    else
        cout << "Not Prime Number!" << endl;
    return 0;
}

// Algorithm to check whether a number is prime or not.
// Step 1: Start
// Step 2: Input a number, x
// Step 3: Check whether x is divisible by any number from 2 to x - 1
// Step 4: If yes, then go to Step 6 otherwise go to Step 5
// Step 5: Display number is a prime number
// Step 6: Display number is not a prime number
// Step 7: Stop

// Pseudocode
// 1. FUNCTION CheckPrime(x):
// 2.   FOR I FROM 2 -> X - 1:
// 3.       IF X % I = 0:
// 4.           RETURN false
// 5.       ENDIF
// 6.   ENDLOOP
// 7.   RETURN true
// 8. ENDFUNCTION


// Java
// C
// C++
// SQL -> Oracle MySQL
// HTML CSS Bootstrap Tailwind CSS
// Java -> J2SE J2EE J2ME
// VB.Net
// Assembly Language
// Shell scripting
// JavaScript -> Node, Express, React, Next
// MongoDB
// Python
// PHP
// Android