//
// Created by codeninja on 4/03/18.
//

#include <iostream>
using namespace std;

struct NameType {
    char first_name[20];
    char last_name[20];
    char initial;
};

enum GenderType { eMale=1, eFemale=2 };

struct AddressType {
    unsigned int number;
    char street[20];
    char suburb[20];
    unsigned int post_code;
};

struct StudentType {
    NameType name;
    GenderType gender;
    AddressType address;
};

void get_student_details(StudentType &student);
void print_student_details(StudentType student);

int main(int argc, char* argv[]) {
    StudentType student;

    cout << "Enter your details " << endl;
    get_student_details(student);
    print_student_details(student);
    return 0;
}

void get_student_details(StudentType &student) {
    unsigned int gender_inpt;

    cout << "First Name: ";
    cin >> student.name.first_name;
    cout << "Last Name: ";
    cin >> student.name.last_name;
    cout << "Initial: ";
    cin >> student.name.initial;
    cout << "Gender Type: " << "[1] Male; [2] Female \n" << "Input: ";
    cin >> gender_inpt;
    student.gender = GenderType(gender_inpt);
    cout << "Address Number: ";
    cin >> student.address.number;
    cout << "Street Name: ";
    cin >> student.address.street;
    cout << "Suburb: ";
    cin >> student.address.suburb;
    cout << "Postcode: ";
    cin >> student.address.post_code;

}

void print_student_details(StudentType student) {
    cout << "\n\n" << student.name.first_name << " "
         << student.name.last_name
         << " (" << student.name.initial << ")" << endl;

    switch (student.gender) {
        case eMale: cout << "Gender: Male"; break;
        case eFemale: cout << "Gender: Female"; break;
    }

    cout << "\nAddress: " << student.address.number << " "
         << student.address.street << " "
         << student.address.suburb << " "
         << student.address.post_code;
}
