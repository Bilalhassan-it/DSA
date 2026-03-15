 //MULTI-LIST-ADD STUDENT SEAT NUMBER /COURSE NUMBER AND DISPLAY ALL
#include <iostream>
using namespace std;

//Student Node 
struct Student {
    int seatNo;
    string name;
    Student* next;

    Student(int s, string n) {
        seatNo = s;
        name = n;
        next = NULL;
    }
};

//Course Node
struct Course {
    string courseName;
    Student* studentHead;
    Course* next;

    Course(string name) {
        courseName = name;
        studentHead = NULL;
        next = NULL;
    }
};

// University
class University {
private:
    Course* courseHead;

public:
    University() {
        courseHead = NULL;
    }

    // Add new course
    void addCourse(string courseName) {
        Course* newCourse = new Course(courseName);
        newCourse->next = courseHead;
        courseHead = newCourse;
        cout << "Course added successfully!\n";
    }

    // Add student (sorted by seat no)
    void addStudent(string courseName, int seatNo, string name) {
        Course* course = courseHead;

        while (course != NULL && course->courseName != courseName) {
            course = course->next;
        }

        if (course == NULL) {
            cout << "Course not found!\n";
            return;
        }

        Student* newStudent = new Student(seatNo, name);

        if (course->studentHead == NULL ||
            seatNo < course->studentHead->seatNo) {
            newStudent->next = course->studentHead;
            course->studentHead = newStudent;
            return;
        }

        Student* temp = course->studentHead;
        while (temp->next != NULL && temp->next->seatNo < seatNo) {
            temp = temp->next;
        }

        newStudent->next = temp->next;
        temp->next = newStudent;
    }

    // Display students of a course
    void displayCourse(string courseName) {
        Course* course = courseHead;

        while (course != NULL && course->courseName != courseName) {
            course = course->next;
        }

        if (course == NULL) {
            cout << "Course not found!\n";
            return;
        }

        cout << "\nCourse: " << course->courseName << endl;
        Student* s = course->studentHead;

        if (s == NULL) {
            cout << "No students enrolled.\n";
        }

        while (s != NULL) {
            cout << "Seat No: " << s->seatNo
                 << " | Name: " << s->name << endl;
            s = s->next;
        }
    }
};

// Main (Menu Buttons) 
int main() {
    University uni;
    int choice;

    do {
        cout << "\n===== UNIVERSITY SYSTEM =====\n";
        cout << "1. Add Course\n";
        cout << "2. Add Student\n";
        cout << "3. Display Course Students\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string course;
            cout << "Enter course name: ";
            cin.ignore();
            getline(cin, course);
            uni.addCourse(course);
        }
        else if (choice == 2) {
            string course, name;
            int seat;

            cout << "Enter course name: ";
            cin.ignore();
            getline(cin, course);

            cout << "Enter seat number: ";
            cin >> seat;

            cout << "Enter student name: ";
            cin.ignore();
            getline(cin, name);

            uni.addStudent(course, seat, name);
        }
        else if (choice == 3) {
            string course;
            cout << "Enter course name: ";
            cin.ignore();
            getline(cin, course);
            uni.displayCourse(course);
        }

    } while (choice != 4);
    system("pause");

    return 0;
}
