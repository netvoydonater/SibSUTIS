#include "include.h"

struct Note {
    string SNM;
    int NumberOfSeats;
    float Weight;
};
void Menu() {
    cout << "Меню:" << endl;
    cout << "1)Cоздать  файл из N записей." << endl;
    cout << "2)Просмотреть файл." << endl;
    cout << "3)Добавить в конец файла новую запись." << endl;
    cout << "4)Найти и удалить из файла записи о пассажирах, общий вес вещей которых меньше, чем 10 кг." << endl;
    cout << "5)Изменить вес вещей пассажира по заданной фамилии." << endl;
}
void CreateNotes() {
    int number;
    cout << "Введите кол-во записей: ";
    cin >> number;
    vector<Note> Notes(number);

    ofstream file("File.txt");
    if (file.is_open()) {
        for (int i = 0; i < number; i++) {
            cout << "Введите ФИО пассажира: ";
            cin.ignore();
            getline(cin, Notes[i].SNM);
            file << Notes[i].SNM << endl;

            cout << "Введите кол-во занимаемых багажом мест: ";
            cin >> Notes[i].NumberOfSeats;
            file << Notes[i].NumberOfSeats << endl;

            cout << "Общий вес багажа: ";
            cin >> Notes[i].Weight;
            file << Notes[i].Weight << endl;
        }
        file.close();
    }
}

void ShowNotes() {
	ifstream file("File.txt");
    if (file.is_open()) {
        string Info;
        while (getline(file, Info)) {
			cout << Info << endl;
        }
		file.close();
    }
}

void AddEndNote() {
    vector<Note> Notes(1);
    ofstream file("File.txt", ios::app);
    if (file.is_open()) {
        for (int i = 0; i < 1; i++) {
            cout << "Введите ФИО пассажира: ";
            cin.ignore();
            getline(cin, Notes[i].SNM);
            file << Notes[i].SNM << endl;

            cout << "Введите кол-во занимаемых багажом мест: ";
            cin >> Notes[i].NumberOfSeats;
            file << Notes[i].NumberOfSeats << endl;

            cout << "Общий вес багажа: ";
            cin >> Notes[i].Weight;
            file << Notes[i].Weight << endl;
        }
        file.close();
    }
}


void FindAndDelete() {
    vector<Note> Notes;
    ifstream File("File.txt");
    Note EditNotes;
    while (File >> EditNotes.SNM >> EditNotes.NumberOfSeats >> EditNotes.Weight) {
        Notes.push_back(EditNotes);
    }
    File.close();
    ofstream TempFile("tempFile.txt");
    if (TempFile.is_open()) {
        for (int i = 0; i < Notes.size(); i++) {
            if (Notes[i].Weight >= 10) {
                TempFile << Notes[i].SNM << endl;
                TempFile << Notes[i].NumberOfSeats << endl;
                TempFile << Notes[i].Weight << endl;
            }
        }
        TempFile.close();

        remove("File.txt");
        rename("tempFile.txt" , "File.txt");
    }
}


void FindAndChange() {
    ifstream File("File.txt");
    ofstream TempFile("tempFile.txt");
    vector<Note> Notes;
    Note EditNotes;
    while (File >> EditNotes.SNM >> EditNotes.NumberOfSeats >> EditNotes.Weight) {
        Notes.push_back(EditNotes);
    }

    if (File.is_open() && TempFile.is_open()) {
        string FindSNM;
        cout << "Введите искомую фамилию: ";
        cin.ignore();
        getline(cin, FindSNM);

        for (int i = 0; i < Notes.size(); i++) {
            if (Notes[i].SNM != FindSNM) {
                TempFile << Notes[i].SNM << endl;
                TempFile << Notes[i].NumberOfSeats << endl;
                TempFile << Notes[i].Weight << endl;
            }
            else {
                cout << "Введите новый вес: ";
                float NewWeight;
                cin >> NewWeight;
                TempFile << Notes[i].SNM << endl;
                TempFile << Notes[i].NumberOfSeats << endl;
                TempFile << NewWeight << endl; // Записываем новый вес
            }
        }

        File.close();
        TempFile.close();

        remove("File.txt");
        rename("tempFile.txt", "File.txt");
    }
}


int main() {
	Base();
    while (true)
    {
        Menu();
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            CreateNotes();
            break;
        case 2:
            ShowNotes();
            break;
        case 3:
            AddEndNote();
            break;
        case 4:
			FindAndDelete();
            break;
        case 5:
			FindAndChange();
            break;
        default:
            break;
        }
    }
}



