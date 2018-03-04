//
// Created by codeninja on 4/03/18.
//

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

void print_reverse_string(char msg[]);
void print_reverse_words(char msg[]);

int main(int argc, char *argv[]) {
    char msg[256];

    cout << "Enter words: ";
    cin.getline(msg, 256);

    print_reverse_string(msg);
    cout << endl;
    print_reverse_words(msg);
    return 0;
}

void print_reverse_string(char msg[]) {
    for (int i = strlen(msg); i < strlen(msg) + 1; i--)
        cout << msg[i];
    cout << endl;
}

void print_reverse_words(char msg[]) {
    int counter=0, start=0, iter=0;

    for (int i = 0; i < strlen(msg); i++) {
        if (isspace(msg[i])) {
            if (counter != 0)
                counter += 1;

            int start = 0;
            int word_len = i - counter;

            cout << "i: " << i << " Word Len: " << word_len << " Counter: " << counter << " |";

            char word[word_len];
            for (int j = 0; j < word_len; j++) {
                word[j] = msg[iter];
                iter++;
            }

//            cout << word << endl;
            print_reverse_string(word);
            counter = i;
        }
    }
    cout << endl;
}

//void print_reverse_words(char msg[]) {
//    vector<char> word_char;
//
//    for (int i = 0; i < strlen(msg); i++) {
//        if (isspace(msg[i])) {
//            for (int i = word_char.size(); i <= word_char.size(); i--) {
//                cout << word_char[i];
//            }
//
//        } else
//            word_char.push_back(msg[i]);
//    }
//    cout << endl;
//}
