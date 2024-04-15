#include <string>
#include <format>
#include <iostream>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

string reverseString(string toRev);
string incrementLetter(string toManip);
string capitalizeEachWord(string toCap);
bool hasUniqueLetter(string toCheck);
vector<string> split(string s, char seperator);
vector<string> split(string s, string seperator);

int main()
{
    string theWord = "This is a sentence.";
    cout << format("The original word: {}", theWord) << endl;

    // Take a string and reverse it
    string revWord = reverseString(theWord);
    cout << format("Reversed string: {}", revWord) << endl;

    // Take each letter and increment it to the next one
    string incrementWord = incrementLetter(theWord);
    cout << format("Incremented string: {}", incrementWord) << endl;

    // Capitalize the first letter of each word
    string capitalizeWord = capitalizeEachWord(theWord);
    cout << format("Capitalized word: {}", capitalizeWord) << endl;

    // See if string contains any unique letters
    bool hasUnique = hasUniqueLetter(theWord);
    cout << format("Does string contain unique letter (1 is true, 0 is false): {}", to_string(hasUnique)) << endl; 

    // Custom split function. At the moment it will only take a single char as a seperator
    vector<string> wordList = split(theWord, ' ');
    cout << "Word List: " << endl;
    for (auto word : wordList)
    {
        cout << word << endl;
    }

    // Custom split function. THis one takes a string of anywhere from 1 char and on.
    vector<string> custWordList = split(theWord, "is");
    cout << "Custom word list: " << endl;
    for (auto word : custWordList)
    {
        cout << word << endl;
    }

    return 0;
}

string reverseString(string toRev)
{
    int frontIndex = 0;
    int backIndex = toRev.size() - 1;

    while (frontIndex < backIndex && frontIndex != backIndex)
    {
        char temp = toRev[frontIndex];
        
        toRev[frontIndex] = toRev[backIndex];
        toRev[backIndex] = temp;

        frontIndex++;
        backIndex--;
    }

    return toRev;
}

string incrementLetter(string toManip)
{
    for(int i = 0; i < toManip.size() - 1; i++)
    {
        int code = int(toManip[i]);
        code++;
        toManip[i] = char(code);
    }
    
    return toManip;
}

string capitalizeEachWord(string toCap)
{
    bool needsCap = false;

    for (auto i = 0; i < toCap.size() - 1; i++)
    {
        char letter = toCap[i];
        if (needsCap)
        {
            toCap[i] = toupper(letter);
            needsCap = false;
        }
        else if (letter  ==  ' ')
        {
            needsCap = true;
        }
    }

    return toCap;
}

bool hasUniqueLetter(string toCheck)
{
    map<char, int> letterIndex {};
    bool hasUniqueLetter = false;
    for (auto letter : toCheck)
    {
        map<char, int>::iterator iter = letterIndex.find(letter);

        if(iter == letterIndex.end())
        {
            letterIndex[letter] = 1;
        }
        else
        {
            iter->second++;
        }
    }

    map<char, int>::iterator iter = letterIndex.begin();
    for(iter; iter != letterIndex.end(); iter++)
    {
        if (iter->second == 1)
        {
            return true;
        }
    }

    return hasUniqueLetter;
}

vector<string> split(string s, char seperator)
{
    vector<string> splitList {};

    string word {};
    for (auto letter : s)
    {
        if (letter != seperator)
        {
            word += letter;
        }
        else
        {
            splitList.push_back(word);
            word = "";
        }
    }

    splitList.push_back(word);

    return splitList;
}

vector<string> split(string s, string seperator)
{
    vector<string> splitList {};

    string word {};
    string sep {};
    int index {};
    for (auto i = 0; i < s.length(); i++)
    {
        if (s[i] == seperator[0])
        {   
            sep += s[i];
            for (auto letter : seperator)
            {
                if (sep == seperator)
                {
                    i = index;
                    splitList.push_back(word);
                    sep = "";
                }
                else if (letter == s[index])
                {
                    sep += letter;
                    index++;
                }
                else if (letter != s[index])
                {
                    sep += letter;
                    index++;
                    word += sep;
                    sep = "";
                    i = index;
                }
                index++;
            }
        }
        else
        {
            word += s[i];
        }
    }

    splitList.push_back(word);

    return splitList;
}
