#include <iostream>
#include <vector>
#include <sstream>  // Include the stringstream library
#include <algorithm>  // Include the algorithm library for reverse

using namespace std;

string reverseWords(const string &S) {
    vector<string> words;
    string word;
    stringstream ss(S);  // Initialize stringstream with the input string S
    
    // Split the string by dots and store each word in the vector
    while (getline(ss, word, ' ')) {
        words.push_back(word);
    }
    
    // Reverse the list of words
    reverse(words.begin(), words.end());
    
    // Join the reversed list of words with dots
    string result;
    for (size_t i = 0; i < words.size(); ++i) {
        result += words[i];
        if (i < words.size() - 1) {
            result += " ";
        }
    }
    
    return result;
}

int main() {
    string S = "i like";
    cout << reverseWords(S) << endl;  // Output: "much.very.program.this.like.i"
    return 0;
}
