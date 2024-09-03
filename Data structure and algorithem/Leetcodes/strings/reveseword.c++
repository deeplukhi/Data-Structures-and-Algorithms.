#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

string reverseLettersInWords(const string& str){
    string word;
    string result;

    for(char ch : str){
        if(ch == ' '){
            reverse(word.begin(),word.end());
            result += word + " ";
            word.clear();
        }
        else{
            word += ch;
        }
    }

    reverse(word.begin(), word.end());
    result += word;
    return result;

}
    


int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    string result = reverseLettersInWords(s);
    cout << "Reversed letters in words string: " << result << endl;

    return 0;
}
