#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

vector<string> words = {"programowanie", "komputer", "programista", "algorytm", "struktura", "zmienna"};

string getSecretWord() {
    srand(static_cast<unsigned int>(time(0)));
    int randomIndex = rand() % words.size();
    return words[randomIndex];
}

string maskWord(const string& word) {// ustalenie slowa do odgadniecia
    string masked = word;
    for (char& c : masked) {
        c = '_';
    }
    return masked;
}

void displayWord(const string& word) {// wyswietlenie liter
    for (char c : word) {
        cout << c << " ";
    }
    cout << endl;
}

bool isGuessCorrect(const string& word, char guess) {//
    for (char c : word) {
        if (c == guess) {
            return true;
        }
    }
    return false;
}

void updateWord(const string& secretWord, string& maskedWord, char guess) { // Zgadywanie liter
        for (int i = 0; i < secretWord.length(); ++i) {
        if (secretWord[i] == guess) {
            maskedWord[i] = guess;
        }
    }
}

bool isWordGuessed(const string& word) { //sprawdzenie poprawnosci liter
    for (char c : word) {
        if (c == '_') {
            return false;
        }
    }
    return true;
}

void playHangman() {
    string secretWord = getSecretWord();
    string maskedWord = maskWord(secretWord);
    int attempts = 6;

    cout << "Witaj w grze Wisielec!" << endl;
    cout << "Odgadnij ukryte s³owo. Masz " << attempts << " prób." << endl;

    while (attempts > 0) {
        cout << "Aktualne s³owo: ";
        displayWord(maskedWord);

        char guess;
        cout << "Podaj literê: ";
        cin >> guess;

        if (isGuessCorrect(secretWord, guess)) {
            cout << "Brawo! Zgad³eœ literê." << endl;
            updateWord(secretWord, maskedWord, guess);

            if (isWordGuessed(maskedWord)) {
                cout << "Gratulacje! Wygra³eœ!" << endl;
                return;
            }
        } else {
            cout << "Nieprawid³owa litera. Straci³eœ jedn¹ próbê." << endl;
            --attempts;
        }

        cout << "Pozosta³e próby: " << attempts << endl;
    }

    cout << "Przegra³eœ! Ukryte s³owo to: " << secretWord << endl;
}

int main() {
    playHangman();
    return 0;
}
