#include <iostream>
using namespace std;

class Student
{
private:
    static int count;
    int id;
    string name;
    int marks[5];

public:
    Student(string n, int m1, int m2, int m3, int m4, int m5)
    {
        id = ++count;
        name = n;

        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
        marks[3] = m4;
        marks[4] = m5;
    }

    float average()
    {
        int sum = 0;
        for (int i = 0; i < 5; i++)
        {
            sum = sum + marks[i];
        }
        return sum / 5.0;
    }

    void display()
    {
        cout << "ID: " << id << " Name: " << name << " Avg: " << average() << endl;
    }
};

int Student::count = 0;

int main()
{

    Student s[3] = {
        Student("Ali", 80, 75, 90, 85, 70),
        Student("Ahmed", 88, 92, 91, 85, 90),
        Student("Sarim", 70, 72, 68, 75, 74)
    };

    cout << "All Students:\n";
    for (int i = 0; i < 3; i++)
    {
        s[i].display();
    }

    int top = 0;
    for (int i = 1; i < 3; i++)
    {
        if (s[i].average() > s[top].average())
        {
            top = i;
        }
    }

    cout << "\nStudent with Highest Average:\n";
    s[top].display();

    return 0;
}