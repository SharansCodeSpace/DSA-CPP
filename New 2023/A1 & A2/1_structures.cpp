#include <iostream>
using namespace std;

struct student
{
    string name;
    int roll_no;
    float cgpa;
};
    
int main()
{
    int n = 3;
    student cse[n];
    cout << "Enter details of " << n << " students" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << ":" << endl;
        cout << "Enter name: ";
        cin >> cse[i].name;
        cout << "Enter roll no.: ";
        cin >> cse[i].roll_no;
        cout << "Enter cgpa: ";
        cin >> cse[i].cgpa;
    }
    float max = cse[0].cgpa;
    float min = cse[0].cgpa;
    for (int i = 0; i < n; i++)
    {
        if (cse[i].cgpa > max)
            max = cse[i].cgpa;
        if (cse[i].cgpa < min)
            min = cse[i].cgpa;
    }
    cout << "Maximum CGPA: " << max << endl;
    cout << "Minimum CGPA: " << min << endl;
    return 0;
}