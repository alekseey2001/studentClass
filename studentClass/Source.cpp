#include <iostream>
#include <vector>
#include <memory>

struct Student {
    int id;
    std::string name;
    int age;
};

class StudentDatabase {
private:
    std::vector<std::shared_ptr<Student>> students;

public:
    void addStudent(int id, const std::string& name, int age) {
        std::shared_ptr<Student> newStudent = std::make_shared<Student>();
        newStudent->id = id;
        newStudent->name = name;
        newStudent->age = age;
        students.push_back(newStudent);
    }

    void removeStudent(int id) {
        auto it = std::find_if(students.begin(), students.end(), [id](const std::shared_ptr<Student>& student) {
            return student->id == id;
            });

        if (it != students.end()) {
            students.erase(it);
        }
        else {
            std::cout << "Student with id " << id << " not found." << std::endl;
        }
    }

    void getStudentInfo(int id) {
        auto it = std::find_if(students.begin(), students.end(), [id](const std::shared_ptr<Student>& student) {
            return student->id == id;
            });

        if (it != students.end()) {
            std::cout << "Student ID: " << (*it)->id << ", Name: " << (*it)->name << ", Age: " << (*it)->age << std::endl;
        }
        else {
            std::cout << "Student with id " << id << " not found." << std::endl;
        }
    }
};

int main() {
    StudentDatabase db;

    db.addStudent(1, "Alice", 20);
    db.addStudent(2, "Bob", 21);

    db.getStudentInfo(1);
    db.getStudentInfo(3);

    db.removeStudent(1);
    db.getStudentInfo(1);

    return 0;
}
