#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("demo.txt");
    ofstream fout("demo1.txt", ios::app);
    string line;
    while (getline(fin, line))
        fout << line << endl;
    fin.close();
    fout.close();
    return 0;
}