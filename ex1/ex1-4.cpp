//
// Created by codeninja on 4/03/18.
//

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "student.h"
using namespace std;

void get_student_details(StudentType &student_record);
void print_student_details(StudentType student_record);
void save_student_record(StudentType &student_record);
void load_student_record(StudentType &student_record);

int main(int argc, char* argv[]) {
    int inpt, exit = 1;
    StudentType student_record;

    while (inpt != 0) {
        cout << "\nDo you want to create or load a student record?\n"
             << "[1] Load\n"
             << "[2] Create\n"
             << "[0] Exit\n"
             << ">> ";
        cin >> inpt;

        if (inpt == 1) {
            load_student_record(student_record);
        } else if (inpt == 2) {
            get_student_details(student_record);
            save_student_record(student_record);
        }
    }

    return 0;
}
void save_student_record(StudentType &student_record) {
    ofstream fout;

    fout.open("student_data.txt");

    if (!fout.good()) {
        cout << "[DEBUG] Error, file not found" << endl;
        exit(1);
    }

    fout << student_record.name.first_name << endl;
    fout << student_record.name.last_name << endl;
    fout << student_record.name.initial << endl;
    fout << student_record.gender << endl;
    fout << student_record.address.number << endl;
    fout << student_record.address.street << endl;
    fout << student_record.address.suburb << endl;
    fout << student_record.address.post_code << endl;

    fout.close();
}

void load_student_record(StudentType &student_record) {
    int gender;
    ifstream fin;

    fin.open("student_data.txt");

    if (!fin.good()) {
        cout << "[DEBUG] Error, file not found for reading" << endl;
        exit(1);
    }

    fin >> student_record.name.first_name;
    fin >> student_record.name.last_name;
    fin >> student_record.name.initial;
    fin >> gender;
    student_record.gender = GenderType(gender);
    fin >> student_record.address.number;
    fin >> student_record.address.street;
    fin >> student_record.address.suburb;
    fin >> student_record.address.post_code;

    print_student_details(student_record);

    fin.close();
}
