#include <iostream>
#include <string>

using namespace std;

struct Student {
    string Surname;
    int grades[4];
    Student* left;
    Student* right;
};

void CreateStudents(Student*& Node, Student newStudent) {
    if (Node == nullptr) {
        Node = new Student;
        Node->Surname = newStudent.Surname;
        for (int i = 0; i < 4; i++) {
            Node->grades[i] = newStudent.grades[i];
        }
        Node->left = nullptr;
        Node->right = nullptr;
    }
    else {
        if (newStudent.Surname < Node->Surname) {
            CreateStudents(Node->left, newStudent);
        }
        else {
            CreateStudents(Node->right, newStudent);
        }
    }
}

void PrintListInc(Student* Node) {
    if (Node != nullptr) {
        PrintListInc(Node->left);
        cout << Node->Surname << endl;
        PrintListInc(Node->right);
    }
}

void PrintListIDec(Student* Node) {
    if (Node != nullptr) {
        PrintListIDec(Node->right);
        cout << Node->Surname << endl;
        PrintListIDec(Node->left);
    }
}

Student* SearchStudent(Student* Node, string Surname) {
    if (Node == nullptr || Node->Surname == Surname) {
        return Node;
    }

    if (Surname < Node->Surname) {
        return SearchStudent(Node->left, Surname);
    }
    else {
        return SearchStudent(Node->right, Surname);
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    Student* Node = nullptr;
    int n;
    cout << "Введите кол-во студентов: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Student newStudent;
        cout << "Введите фамилию студента: ";
        cin >> newStudent.Surname;
        cout << "Введите оценки студента: ";
        for (int j = 0; j < 4; j++) {
            cin >> newStudent.grades[j];
        }
        CreateStudents(Node, newStudent);
    }

    cout << "" << endl;
    PrintListInc(Node);
    cout << "\n" << endl;
    PrintListIDec(Node);

    string SearchSurname;
    cin >> SearchSurname;
    Student* foundStudent = SearchStudent(Node, SearchSurname);

    if (foundStudent != nullptr) {
        cout << "\nСтудент с фамлией " << SearchSurname << " найден." << endl;
    }
    else {
        cout << "\nСтудент с фамилией " << SearchSurname << " не найден." << endl;
    }

    return 0;
}
