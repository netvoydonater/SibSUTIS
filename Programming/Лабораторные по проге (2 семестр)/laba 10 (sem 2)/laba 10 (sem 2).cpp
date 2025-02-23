#include "INCLUDE.h"
using namespace std;

struct Word {
    string word;
};

int main() {
    string line;
    vector<Word> words;
    ifstream file("FirstFile.txt");
    while (getline(file, line)) {
        istringstream stream(line);
        string word;
        while (stream >> word) {
            words.push_back({ word });
        }
    }
    file.close();

    sort(words.begin(), words.end(), [](const Word& a, const Word& b) {
        return a.word < b.word;
    });
    ofstream outputfile("outputfile.txt");
    for (const auto& word : words) {
        outputfile << word.word << endl;
    }
    outputfile.close();

    return 0;
}
