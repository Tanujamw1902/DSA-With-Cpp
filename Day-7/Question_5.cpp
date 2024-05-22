#include <iostream>
using namespace std;
char afterChar(char a)
{
    // Edge Case
    if (a == 'z')
    {
        return 'a';
    }
    // Common Logic
    return int(a + 1);
}
int main()
{
    cout << afterChar('t');
    return 0;
}