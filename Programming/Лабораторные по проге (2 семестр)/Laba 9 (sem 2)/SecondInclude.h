#include <iostream>
#include <cstdlib>

using namespace std;


void Base() {
    setlocale(LC_ALL, "Ru");
    srand(time(NULL));
}

struct Students {
	string Surname;
	int Estimation[4];
	Students* next;
	Students* prev;
};

Students* SecondCreateStudent(int n) {
    int count = 0;
    Students* head = NULL;
    Students* NowStudent = NULL;

    while (count < n) {
        Students* NewStudent = new Students;
        cout << "¬ведите фамилию студента: ";
        cin >> NewStudent->Surname;

        cout << "¬ведите оценки студента: ";
        for (int i = 0; i < 4; i++) {
            cin >> NewStudent->Estimation[i];
        }

        NewStudent->prev = NULL;
        NewStudent->next = NULL;

        if (head == NULL) {
            head = NewStudent;
        }
        else {
            NowStudent->next = NewStudent;
            NewStudent->prev = NowStudent;
        }

        NowStudent = NewStudent;
        count++;
    }

    return head;
}

void DeleteStudentsWithLowEstimation(Students** head) {
    Students* NowNext = *head;

    while (NowNext != NULL) {
        bool LowEstimation = false;

        for (int i = 0; i < 4; i++) {
            if (NowNext->Estimation[i] < 3) {
                LowEstimation = true;
                break;
            }
        }

        if (LowEstimation) {
            if (NowNext->prev != NULL) {
                NowNext->prev->next = NowNext->next;
            }
            else {
                *head = NowNext->next;
            }

            if (NowNext->next != NULL) {
                NowNext->next->prev = NowNext->prev;
            }

            Students* temp = NowNext;
            NowNext = NowNext->next;
            delete temp;
        }
        else {
            NowNext = NowNext->next;
        }
    }
}

void PrintList(Students* head) {
    Students* NowStudent = head;
    while (NowStudent != NULL) {
        cout << "‘амили€ студента: " << NowStudent->Surname << endl;
        cout << "ќценки студента: ";
        for (int i = 0; i < 4; i++) {
            cout << NowStudent->Estimation[i] << '\t';
        }
        cout << endl;
        NowStudent = NowStudent->next;
    }
}
