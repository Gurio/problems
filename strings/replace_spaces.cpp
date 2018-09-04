/*
 *
 Cracking Coding Interview 1.5
 *
 */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string replaceSpaces(string& s) {
    int space_cnt = count(s.begin(),s.end(),' ');
    int offset = space_cnt*2;
    s.resize(s.size()+offset,' ');
    for (int i=s.size()-1; i>=0; i--){
        int j=i-offset;
        if (s[j]==' '){
            s[i--]='0';
            s[i--]='2';
            s[i]='%';
            offset-=2;
        } else {
            s[i]=s[j];
        }
    }
    return s;
}

int main(){
    string test_str = "AB";
    string res = replaceSpaces(test_str);
    cout << res << endl;

    test_str = "aa aaa";
    res = replaceSpaces(test_str);
    cout << res << endl;

    test_str = "";
    res = replaceSpaces(test_str);
    cout << res << endl;

    test_str = "aabcd ";
    res = replaceSpaces(test_str);
    cout << res << endl;

    test_str = " aab    cabcabddd";
    res = replaceSpaces(test_str);
    cout << res << endl;

    test_str = "abababa        ";
    res = replaceSpaces(test_str);
    cout << res << endl;

    test_str = "      aaabbb";
    res = replaceSpaces(test_str);
    cout << res << endl;

    test_str = "  a b   c  d    ";
    res = replaceSpaces(test_str);
    cout << res << endl;
    return 0;    
}