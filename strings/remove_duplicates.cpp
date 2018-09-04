/*
 *
 Cracking Coding Interview 1.3
 *
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string removeDuplicates(string& s) {
    int size = s.size();
    for (int i=0; i<size; i++){
        int offset = 0;
        for (int j=i+1; j<size; j++){
            if (s[i]==s[j]){
                offset++;
            } else {
                s[j-offset]=s[j];
            }
        }
        size -= offset;
    }
    s.resize(size);
    return s;
}

int main(){
    string test_str = "AB";
    string res = removeDuplicates(test_str);
    cout << res << endl;

    test_str = "aaaaa";
    res = removeDuplicates(test_str);
    cout << res << endl;

    test_str = "";
    res = removeDuplicates(test_str);
    cout << res << endl;

    test_str = "aabcd";
    res = removeDuplicates(test_str);
    cout << res << endl;

    test_str = "aabcabcabddd";
    res = removeDuplicates(test_str);
    cout << res << endl;

    test_str = "abababa";
    res = removeDuplicates(test_str);
    cout << res << endl;

    test_str = "aaabbb";
    res = removeDuplicates(test_str);
    cout << res << endl;

    test_str = "abcd";
    res = removeDuplicates(test_str);
    cout << res << endl;
    return 0;
    
}