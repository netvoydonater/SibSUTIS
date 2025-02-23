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
};

Students* CreateStudent(int n) {
	int count = 0;
	Students* head = NULL;
	Students* NowStudent = NULL; 
	while (count < n) {
		Students* NewStudent = new Students;
		cout << "¬ведите фамилию студента: "; cin >> NewStudent->Surname;
		cout << "¬ведите оценки студента: ";  for (int i = 0; i < 4; i++) {
			cin >> NewStudent->Estimation[i];
		}
		NewStudent->next = NULL;
		if (head == NULL) {
			head = NewStudent;
		}
		else {
			NowStudent->next = NewStudent; 
		}
		NowStudent = NewStudent; 
		count++;
	}
	return head;
}

void SortStudents(Students* head, int n) {
	Students* NowStudent = head;
	Students* NowNext = nullptr;
	for (int i = 0; i < n - 1; i++) {
		NowNext = NowStudent->next;

		while (NowNext != nullptr) {
			if (NowStudent->Surname > NowNext->Surname) swap(NowStudent->Surname, NowNext->Surname);
			NowNext = NowNext->next;
		}
		NowStudent = NowStudent->next;
	}
}


void printList(Students* head) {
	Students* NowStudent = head;
	while (NowStudent != NULL) {
		cout << "‘амили€: " << NowStudent->Surname << endl;
		cout << "ќценки: ";
		for (int i = 0; i < 4; i++) {
			cout << NowStudent->Estimation[i] << '\t';
		}
		cout << endl;
		NowStudent = NowStudent->next;
	}
}


