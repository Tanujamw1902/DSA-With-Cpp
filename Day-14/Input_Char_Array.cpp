#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char word[30];
    cin >> word;

    cout << "Your Word Was : " << word << endl;
    cout << "Length : " << strlen(word) << endl;

    char sentence[30];
    cin.getline(sentence, 30, '*');

    cout << "Your Sentence Was : " << sentence << endl;
    cout << "Your Sentence Was : " << sentence[0] << endl;
    cout << "Length : " << strlen(sentence) << endl;

    return 0;
}
