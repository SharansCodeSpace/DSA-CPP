#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream file("demo.txt");
    string line;
    int line_count = 0;
    while (getline(file, line))
    {
        line_count++;
    }
    cout << "Number of lines: " << line_count << endl;
    file.close();
    return 0;
}