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
	Students* left , *right;
};

void ThirdCreateStudent(int n) {
	int count = 0;
	Students* NewStudent = NULL;
	NewStudent->left = NewStudent->right = NULL;
	while (count < n) {
		Students*& NewStudent = new Students;
		cout << "¬ведите фамилию студента: "; cin >> NewStudent->Surname;
		cout << "¬ведите оценки студента: ";  for (int i = 0; i < 4; i++) {
			cin >> NewStudent->Estimation[i];
		}
		NewStudent->left = NewStudent->right = NULL;
		count++;
	}
}

