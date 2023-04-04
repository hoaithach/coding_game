#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

// this sub-function to get the start position on ACSII character
int getStartPostion(char ch, int width)
{
    int charNumb = toupper(static_cast<int>(ch));
    int ANumb = toupper(static_cast<int>('A'));
    int ZNumb = toupper(static_cast<int>('Z'));
    int returnVal;

    if (((charNumb - ANumb) * (charNumb - ZNumb)) <= 0)
    {
        // check charNumb in range 'A' to 'Z'
        returnVal = ((charNumb - ANumb) * width);
    }
    else
    {
        // other characters
        returnVal = (26 * width); // 26 is last position
    }

    return returnVal;
}

int main()
{
    // get width of character
    int l;
    cin >> l;
    cin.ignore();

    // get height of character
    int h;
    cin >> h;
    cin.ignore();

    // get the string, that we need print out
    string t;
    getline(cin, t);

    // input ACSII type and process output
    for (int i = 0; i < h; i++) {
        string row;
        getline(cin, row);

        string output;

        for (int idx = 0; idx < t.length(); idx++) {
            // sweep all character on input string
            output = output + row.substr(getStartPostion(t[idx], l), l);
        }

        cout << output << endl;
    }
}