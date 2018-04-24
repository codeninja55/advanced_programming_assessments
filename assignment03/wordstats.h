/**********************************************************************
 * wordstats.h - CSCI251 - Ass3 - Contains WordStats class declaration
 * <your name> <your login> <date last modified>
 **********************************************************************/
#ifndef WORDSTATS_H_
#define WORDSTATS_H_

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
using namespace std;

// Definition of data contained in BinaryTree


typedef map<string, vector<int> > WordMap;
typedef WordMap::iterator WordMapIter;

class WordStats
{
	public:
		WordStats();
		void ReadDictionary();
		void DisplayDictionary();
		void ReadTxtFile();
		void DisplayKnownWordStats();
		void DisplayUnknownWordStats();
		void DisplayMostFreqKnownWords();
		void DisplayMostFreqUnknownWords();
		void DisplayOriginalText();
	private:
		WordMap KnownWords;
		WordMap UnknownWords;
		set<string> Dictionary;
		char Filename[256];
		
		//add your private fns here
		
};

#endif

