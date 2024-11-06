#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    int age, reg_no, roll_no, semester, attendance;
    string name, parentage;
    int marks[5];
    float percentage, totalMarks;

public:
    void get_details()
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Registration Number: ";
        cin >> reg_no;
        cout << "Enter Parentage: ";
        cin >> parentage;
        cout << "Enter Semester: ";
        cin >> semester;
        cout << "Enter Roll Number: ";
        cin >> roll_no;
        cout << "Enter Attendance (Classes Attended): ";
        cin >> attendance;
        cout << "Enter Marks in 5 subjects: ";
        for (int i = 0; i < 5; i++)
        {
            cin >> marks[i];
        }
    }

    void show_details()
    {
        cout << " Name: " << name << endl;
        cout << " Age: " << age << endl;
        cout << " Reg No: " << reg_no << endl;
        cout << " Parentage: " << parentage << endl;
        cout << " Semester: " << semester << endl;
        cout << " Roll No: " << roll_no << endl;
        cout << " Attendance: " << attendance << endl;
        cout << " Percentage: " << percentage << "%" << endl;
    }

    void show_name()
    {
        cout << name;
    }

    void show_rollno()
    {
        cout << "Roll No: " << roll_no << endl;
    }

    void show_attendance()
    {
        cout << "Attendance: " << attendance << " classes" << endl;
    }

    void show_shortage()
    {
        if (attendance < 75)
        {
            cout << name << " has low attendance(shortage): " << attendance << " classes" << endl;
        }
        else
        {
            cout << "No Shortage" << endl;
        }
    }

    void cal_percentage()
    {
        totalMarks = 0;
        for (int i = 0; i < 5; i++)
        {
            totalMarks = totalMarks + marks[i];
        }
        percentage = totalMarks / 5;
    }
    void show_percentage()
    {
        if (percentage >= 90)
        {
            cout << "percentage is above 90 %" << endl;
        }
        else
        {
            cout << "percentage is below 90 %" << endl;
        }
    }

    void top_5(Student students[], int n)
    {
        int temp;
        for (int i = 0; i < n - 1; i++)
        {

            for (int j = 0; j < n - i - 1; j++)
            {
                if (students[j].totalMarks < students[j + 1].totalMarks)
                {
                    temp = students[j].totalMarks;
                    students[j].totalMarks = students[j + 1].totalMarks;
                    students[j + 1].totalMarks = temp;
                }
            }
        }
        cout << "Top 5 Students are : " << endl;
        for (int i = 0; i < 5; i++)
        {
            students[i].show_name();
            cout << " - " << students[i].totalMarks << endl;
        }
    }
};

int main()
{
    Student students[100];
    int noStudent = 0;
    cout << "Enter Number Of Students: ";
    cin >> noStudent;
    for (int i = 0; i < noStudent; i++)
    {
        cout << "Enter Details Of Student " << i + 1 << ":" << endl;
        students[i].get_details();
    }

    for (int i = 0; i < noStudent; i++)
    {
        cout << "Details Of Student :" << endl;
        students[i].cal_percentage();
        students[i].show_details();
        students[i].show_percentage();
        students[i].show_shortage();
    }

    students[0].top_5(students, noStudent);

    return 0;
}
