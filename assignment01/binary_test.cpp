//
// Created by codeninja on 11/03/18.
//

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <cstring>
using namespace std;

int main(int argc, char* argv[]) {
    // These are for writing
    string str("Hello World!");
    string  newline("\n");
    int i = 100;

    // These are for reading
    streampos buffer_size;  // Determine the size of the file to be read
    char * buffer;

    /* WRITING */
    ofstream fout("test.bin", ios::binary);

    if (!fout.good()) {
        cout << "[DEBUG] File cannot be open!";
        exit(1);
    }

    int str_len = str.length();

    // How to write -- cast a pointer to a type char * and give sizeof the type
//    fout.write((char*) &str_len, sizeof(int));
    fout.write(str.c_str(), str.length());
    fout.write(newline.c_str(), newline.length());
    fout.write(str.c_str(), str.length());
    fout.close();

    /* READING */
    ifstream fin("test.bin", ios::in | ios::binary |
            ios::ate); // Open the file with the pointer at end to get the size of the file

    buffer_size = fin.tellg();  // obtain the pointer position at end of file
    buffer = new char[buffer_size];  // create a new buffer memory alloc big enough for file size

    fin.seekg(0, ios::beg);  // Move pointer to begin of the file
    fin.read(buffer, buffer_size);
    fin.close();

    for (int i = 0; i < buffer_size; i++)
        cout << ((buffer[i] == ' ') ? '\n' : buffer[i]);

    cout << endl;

    return 0;
}