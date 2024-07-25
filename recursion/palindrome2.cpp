#include <iostream>
using namespace std;

bool isPalindrome(const string &str, int i, int j)
{
    // Base case: when indices meet or cross, it's a palindrome
    if (i >= j)
    {
        return true;
    }

    // Check if the characters at current indices are the same
    if (str[i] != str[j])
    {
        return false;
    }

    // Recursive call to check the next set of characters
    return isPalindrome(str, i + 1, j - 1);
}

int main()
{
    string str = "naman";

    if (isPalindrome(str, 0, str.length() - 1))
    {
        cout << "Palindrome." << endl;
    }
    else
    {
        cout << "Not a palindrome." << endl;
    }

    return 0;
}
