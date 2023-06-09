#include <iostream>
#include <vector>
#include <string>

using namespace std;

void showList(const vector<string>& dane) {
    cout << "Lista danych:" << endl;
    for (const auto& element : dane) {
        cout << "- " << element << endl;
    }
}

int main() {
    vector<string> dane;

    int LD;
    cout << "Podaj liczb� danych: ";
    cin >> LD;

    for (int i = 0; i < LD; i++) {
        string DaneInput;
        cout << "Podaj dane " << i + 1 << ": ";
        cin >> DaneInput;
        dane.push_back(DaneInput);
    }

    showList(dane);

    return 0;
}
