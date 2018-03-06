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

    cout.clear();
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

void print_reverse_words(char words[]) {
    int start=0, end=0;
    do{
        while(!isspace(words[end]) && words[end] != '\0') {
            end++; // find end of word
            for (int i = end - 1; i >= start; i--) {
                cout << words[i]; // print word in reverse
                cout << ' ';
                start = end = end + 1; // move to next word
            }
        }
    } while (end < strlen(words)); // len is from strlen(words)
    cout<<endl;
}

//void print_reverse_words(char msg[]) {
//    int cursor=0, word_len=0, start=0, end=0, counter=0;
//
//    for (cursor = 1; cursor < strlen(msg); cursor++) {
//        if (isspace(msg[cursor])) {
//            if (start == 0) {
//                start = 0;
//                word_len = cursor;
//            }
//            else {
//                word_len = cursor - word_len;
//                start = (counter - word_len) + 1;
//            }
//
//            cout << "Cursor: " << cursor << " Word Len: " << word_len
//                 << " Start: " << start << " |";
//
//            char word[word_len];
//            for (int j = 0; j < word_len; j++) {
//                word[j] = msg[start];
//                start++;
//            }
//
//            print_reverse_string(word);
//            cout << "\nWord size: " << strlen(word) << "\n";
//        }
//    }
//    cout << endl;
//}
