#include <string>
#include <format>
#include <iostream>
#include <cstring>
#include <map>

using namespace std;

string reverseString(string toRev);
string incrementLetter(string toManip);
string capitalizeEachWord(string toCap);
bool hasUniqueLetter(string toCheck);

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
    cout << format("Does string contain unique letter (1 is true, 0 is false): {}", to_string(hasUnique));

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
