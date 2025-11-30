#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Student class
class Student {
public:
    int id;
    string name;
    int age;
    double year;
    
    Student(int i, string n, int a, double y) {
        id = i;
        name = n;
        age = a;
        year = y;
    }
    
    void display() {
        cout << "ID: " << id << " | Name: " << name 
             << " | Age: " << age << " | Grade: " << year << endl;
    }
};

// Main system
class StudentManager {
private:
    vector<Student> students;  // Using vector to store students
    int nextId = 1;

public:
    // Add student
    void addStudent() {
        string name;
        int age;
        double year;
        
        cout << "Enter student name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter year level: ";
        cin >> year;
        
        students.push_back(Student(nextId, name, age, year));
        cout << "Student added successfully! ID: " << nextId << endl;
        nextId++;
    }
    
    // Display all students
    void displayAll() {
        if (students.empty()) {
            cout << "No students found!" << endl;
            return;
        }
        
        cout << "\n=== ALL STUDENTS ===" << endl;
        for (auto &student : students) {
            student.display();
        }
    }
    
    // Search student by ID
    void searchStudent() {
        int searchId;
        cout << "Enter student ID to search: ";
        cin >> searchId;
        
        for (auto &student : students) {
            if (student.id == searchId) {
                cout << "Student found: ";
                student.display();
                return;
            }
        }
        cout << "Student not found!" << endl;
    }
    
    // Delete student
    void deleteStudent() {
        int deleteId;
        cout << "Enter student ID to delete: ";
        cin >> deleteId;
        
        for (int i = 0; i < students.size(); i++) {
            if (students[i].id == deleteId) {
                students.erase(students.begin() + i);
                cout << "Student deleted successfully!" << endl;
                return;
            }
        }
        cout << "Student not found!" << endl;
    }
};

// Menu function
void showMenu() {
    cout << "\n=== STUDENT MANAGEMENT SYSTEM ===" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. Display All Students" << endl;
    cout << "3. Search Student" << endl;
    cout << "4. Delete Student" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose an option: ";
}

// Main function
int main() {
    StudentManager manager;
    int choice;
    
    do {
        showMenu();
        cin >> choice;
        
        switch(choice) {
            case 1:
                manager.addStudent();
                break;
            case 2:
                manager.displayAll();
                break;
            case 3:
                manager.searchStudent();
                break;
            case 4:
                manager.deleteStudent();
                break;
            case 5:
                cout << "Thank you for using the system!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);
    
    return 0;
}