/**********************************************************************
 * wordstats.cpp - CSCI251 - Ass3 - Contains WordsStats class definition
 * Dinh Che | dbac496 | 2018-04-25
 **********************************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <algorithm>
#include <iterator>
#include "wordstats.h"
using namespace std;

WordStats::WordStats(){
    strcpy(Filename,"testdata.txt");
}

// Reads dictionary.txt into Dictionary
void WordStats::ReadDictionary(){
    ifstream fin;
    string word;

    strcpy(DictFile, "dictionary.txt");
    fin.open(DictFile);

    if(!fin.good()) {
        cout<<"[DEBUG]: Error during opening testdata.txt"<<endl;
        exit(1);
    }

    //fin >> word;
    while(!fin.eof()) {
        fin>>word;
        Dictionary.insert(ToLower(word));
    }
    cout<<Dictionary.size()<<" words read from dictionary."<<endl;
}

// Displays the first 20 words in the dictionary set
void WordStats::DisplayDictionary(){
    set<string>::iterator iter = Dictionary.begin();
    int count = 1;
    cout<<"Displaying the first 20 words in the dictionary..."<<endl;
    for (iter; iter!=Dictionary.end(); ++iter) {
        cout<<*iter<<endl;
        if (count++ == 20) return;
    }
}

// Reads textfile into KnownWords and UnknownWords
void WordStats::ReadTxtFile()
{
    ifstream fin;
    string word, cleaned_word;
    int pos = 0;

    fin.open(Filename);

    if (!fin.good()) {
        cout<<"[DEBUG]: Error during opening of testdata.txt"<<endl;
        exit(1);
    }

    while(!fin.eof()) {
        fin>>word;
        cleaned_word = PreprocessWord(ToLower(word));
        // If the cleaned_word in Dictionary set
        set<string>::iterator dictSetIter = Dictionary.find(cleaned_word);
        if (dictSetIter != Dictionary.end()) {
            WordMapIter knownMapIter = KnownWords.find(cleaned_word);
            // If cleaned_word already in KnownWords
            if(knownMapIter != KnownWords.end()) // Already in map
                (*knownMapIter).second.push_back(pos);
            else {
                vector<int> vect(1, pos);
                KnownWords.insert(knownMapIter, pair<string, vector<int> >(cleaned_word, vect));
            }
        } else {
            WordMapIter unknownMapIter = UnknownWords.find(cleaned_word);
            if(unknownMapIter != KnownWords.end())
                UnknownWords[cleaned_word].push_back(pos);
            else {
                vector<int> vect(1, pos);
                KnownWords.insert(unknownMapIter, pair<string, vector<int> >(cleaned_word, vect));
            }
        }

        pos++;
    }

    cout<<KnownWords.size()<<" known words read."<<endl;
    cout<<UnknownWords.size()<<" unknown words read."<<endl;
}

// Displays stats of words in KnownWords
void WordStats::DisplayKnownWordStats()
{
    for (WordMapIter iter = KnownWords.begin(); iter != KnownWords.end(); ++iter) {
        cout<<(*iter).first<<" | ";
        vector<int> vect = (*iter).second;
        cout<<vect.size()<<" | ";
        copy(vect.begin(), vect.end(), ostream_iterator<int>(cout, " "));
        cout<<endl;
    }
}

// Displays stats of words in UnknownWords
void WordStats::DisplayUnknownWordStats()
{
    for (WordMapIter iter = UnknownWords.begin(); iter != UnknownWords.end(); ++iter) {
        cout<<(*iter).first<<" | ";
        vector<int> vect = (*iter).second;
        cout<<vect.size()<<" | ";
        copy(vect.begin(), vect.end(), ostream_iterator<int>(cout, " "));
        cout<<endl;
    }
}

// Displays 20 most frequent words in KnownWords
void WordStats::DisplayMostFreqKnownWords(){
}

// Displays 20 most frequent words in UnknownWords
void WordStats::DisplayMostFreqUnknownWords(){
}

// Displays original text from KnownWords & UnknownWords
void WordStats::DisplayOriginalText()
{
}

// ============ Private Fns ========================

string WordStats::ToLower(string word)
{
    for (int i=0; i<word.length(); i++)
        word[i] = tolower(word[i]);
    return word;
}

string WordStats::PreprocessWord(string word)
{
    string cleaned_word;
    for (int i=0; i<word.length(); ++i) {
        if (char(word[i]) == char(45)) cleaned_word += word[i];  // Char code 45: '-'
        else if (char(word[i]) == char(39)) cleaned_word += word[i]; // Char code 39: "'"
        else if (isalpha(word[i])) cleaned_word += word[i];
    }

    /*for(int i=0; i<word.size(); ++i) {
        while(!isalpha(word[i]) && i<word.size())
            word.erase(i, 1);
    }*/
    // Only available with std=c++11
    /*word.erase(remove_if(word.begin(), word.end(), [](char c) {
        return !isalnum(c);
    }), word.end());*/

    return cleaned_word;
}