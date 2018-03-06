/********************************************************************
 * CSCI251 - Ass1
 * <Name - Login>
 * main.cpp - Contains interface for student records database
 ********************************************************************/

#include <iostream>
#include <cctype>
#include "ass1.h"
using namespace std;

void PrintMenu();

int main(){

	char Command;
	ReadFile();		
	PrintMenu();
	do{
		cout << "Command: ";
		cin >> Command;
		Command=tolower(Command);
		switch (Command)
		{
			case 'u':
				UpdateRecord();
				break;
			case 'd':
				DisplayRecord();
				break;
			case 'm':
				PrintMenu();
				break;
			case 'q':
				break;
			default:
				cerr << "Illegal Command\n";
				PrintMenu();
		}
	} while (Command != 'q');

	SaveFile();

	return 0;
}

void PrintMenu(){
	cout << "Commands Available:\n";
	cout << "  d - Display Record\n";
	cout << "  u - Update Record\n";
	cout << "  m - Print Menu\n";
	cout << "  q - Quit the program\n\n";
}
