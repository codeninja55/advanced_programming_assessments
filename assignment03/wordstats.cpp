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
void WordStats::ReadDictionary()
{
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
    cout<<Dictionary.size()<<" words read from dictionary."<<endl<<endl;
}

// Displays the first 20 words in the dictionary set
void WordStats::DisplayDictionary()
{
    set<string>::iterator iter = Dictionary.begin();
    int count = 0;
    cout<<"Displaying the first 20 words in the dictionary..."<<endl;
    for (iter; iter!=Dictionary.end(); ++iter) {
        cout<<*iter<<endl;
        if (count++ == 19) break;
    }
    cout<<endl;
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
        if (word.size() == 1 && char(word[0]) == '-') continue;
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
    cout<<UnknownWords.size()<<" unknown words read."<<endl<<endl;
}

// Displays stats of words in KnownWords
void WordStats::DisplayKnownWordStats()
{
    cout<<setw(15)<<right<<"Word"<<'\t';
    cout<<setw(6)<<right<<"Count"<<'\t';
    cout<<setw(25)<<left<<"Positions"<<endl;

    for (WordMapIter iter = KnownWords.begin(); iter != KnownWords.end(); ++iter) {
        vector<int> vect = (*iter).second;
        cout<<setw(15)<<right<<(*iter).first<<'\t';
        cout<<setw(4)<<right<<vect.size()<<'\t';
        cout<<setw(3)<<left;
        copy(vect.begin(), vect.end(), ostream_iterator<int>(cout, " "));
        cout<<endl;
    }
    cout<<endl;
}

// Displays stats of words in UnknownWords
void WordStats::DisplayUnknownWordStats()
{
    cout<<setw(15)<<right<<"Word"<<'\t';
    cout<<setw(6)<<right<<"Count"<<'\t';
    cout<<setw(25)<<left<<"Positions";
    cout<<endl;

    for (WordMapIter iter = UnknownWords.begin(); iter != UnknownWords.end(); ++iter) {
        vector<int> vect = (*iter).second;

        cout<<setw(15)<<right<<(*iter).first<<'\t';
        cout<<setw(4)<<right<<vect.size()<<'\t';
        cout<<setw(3)<<left;
        copy(vect.begin(), vect.end(), ostream_iterator<int>(cout, " "));
        cout<<endl;
    }
    cout<<endl;
}

// Displays 20 most frequent words in KnownWords
void WordStats::DisplayMostFreqKnownWords()
{
    multimap<int, string> MostFreqWords;
    multimap<int, string>::reverse_iterator RMMapIter;
    int count = 0;

    for (WordMapIter iter = KnownWords.begin(); iter != KnownWords.end(); ++iter){
        vector<int> vect = (*iter).second;
        MostFreqWords.insert(pair<int, string>(vect.size(), (*iter).first));
    }

    cout<<right<<setw(15)<<"Word";
    cout<<setw(8)<<"Count"<<endl;
    for (RMMapIter = MostFreqWords.rbegin(); RMMapIter != MostFreqWords.rend(); ++RMMapIter) {
        cout<<setw(15)<<(*RMMapIter).second;
        cout<<right;
        cout<<setw(6)<<(*RMMapIter).first<<endl;
        if (count++ == 19) break;
    }
    cout<<endl;
}

// Displays 20 most frequent words in UnknownWords
void WordStats::DisplayMostFreqUnknownWords()
{
    multimap<int, string> MostFreqWords;
    multimap<int, string>::reverse_iterator RMMapIter;
    int count = 0;

    for (WordMapIter iter = UnknownWords.begin(); iter != UnknownWords.end(); ++iter){
        vector<int> vect = (*iter).second;
        MostFreqWords.insert(pair<int, string>(vect.size(), (*iter).first));
    }

    cout<<right<<setw(15)<<"Word";
    cout<<setw(8)<<"Count"<<endl;
    for (RMMapIter = MostFreqWords.rbegin(); RMMapIter != MostFreqWords.rend(); ++RMMapIter) {
        cout<<setw(15)<<(*RMMapIter).second;
        cout<<right;
        cout<<setw(6)<<(*RMMapIter).first<<endl;
        if (count++ == 19) break;
    }
    cout<<endl;
}

// Displays original text from KnownWords & UnknownWords
void WordStats::DisplayOriginalText()
{
    map<int, string> OriginalTextMap;
    map<int, string>::iterator TextMapIter;
    WordMapIter KnownWordsIter;
    WordMapIter UnknownWordsIter;

    for (KnownWordsIter = KnownWords.begin(); KnownWordsIter != KnownWords.end(); ++KnownWordsIter) {
        vector<int>::iterator VectIter;
        vector<int> vect = (*KnownWordsIter).second;

        for (VectIter = vect.begin(); VectIter != vect.end(); ++VectIter) {
            OriginalTextMap.insert(pair<int, string>((*VectIter), (*KnownWordsIter).first));
        }
    }

    for (UnknownWordsIter = UnknownWords.begin(); UnknownWordsIter != UnknownWords.end(); ++UnknownWordsIter) {
        vector<int>::iterator VectIter;
        vector<int> vect = (*UnknownWordsIter).second;

        for (VectIter = vect.begin(); VectIter != vect.end(); ++VectIter) {
            OriginalTextMap.insert(pair<int, string>((*VectIter), (*UnknownWordsIter).first));
        }
    }

    // Print the original text in order
    for (TextMapIter = OriginalTextMap.begin(); TextMapIter != OriginalTextMap.end(); ++TextMapIter) {
        cout<<(*TextMapIter).second<<" ";
    }

    cout<<endl;
}

// ============ Private Fns ========================

string WordStats::ToLower(string word)
{
    for (int i=0; i<word.length(); i++) word[i] = tolower(word[i]);
    return word;
}

string WordStats::PreprocessWord(string word)
{
    string cleaned_word;
    for (int i=0; i<word.length(); ++i) {
        if (isalpha(word[i])) cleaned_word += word[i];
        else if (char(word[i]) == '\'') cleaned_word += word[i];  // Char code 45: '-'
        else if (char(word[i]) == '-') cleaned_word += word[i]; // Char code 39: "'"
    }
    return cleaned_word;
}
