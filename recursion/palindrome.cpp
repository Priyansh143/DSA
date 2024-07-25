#include <iostream>
#include <array>
using namespace std;

bool palind(string &str, int i, int j)
{
    // base
    if (i >= j)
    {
        return true;
    }

    if (str[i] == str[j])
    {
        return palind(str, i + 1, j - 1);
    }
    else
    {
        return false;
    }
}

int main()
{
    string str = "naman";
    if (palind(str, 0, str.length() - 1))
    {
        cout << "palindrome.";
    }
    else
    {
        cout << "Not palindrome";
    }
    return 0;
}