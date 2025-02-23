//#include "FirstInclude.h"
#include "SecondInclude.h"

int main(void) {
	Base();
	/*int n; cin >> n;
	Students* head = new Students;*/
	/*CreateStudent(n);
	SortStudents(head , n);
	printList(head);*/
    int n; cin >> n;
    Students* head = SecondCreateStudent(n);
    cout << "\nИсходный список студентов:" << endl;
    PrintList(head);
    DeleteStudentsWithLowEstimation(&head);
    cout << "\nСписок студентов без плохих оценок:" << endl;
    PrintList(head);
}