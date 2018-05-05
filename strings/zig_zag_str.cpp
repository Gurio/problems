/*
 *
 https://leetcode.com/problems/zigzag-conversion/description/
 *
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string convert(const string& s, int numRows) {
    if (s.empty() || numRows <= 0) {return "";}
    if (numRows == 1) {return s;}
    vector<string> zigZagStr (numRows);
    string result;
    size_t idx = 0;
    size_t row = 0;
    while (idx < s.size()){
        row = 0;
        while (row < numRows && idx < s.size()){
            zigZagStr[row++] += s[idx++];
        }
        row -= 2;
        while (row > 0 && idx < s.size()){
            zigZagStr[row--] += s[idx++];
        }
    }
    for (int i=0; i<numRows; i++){
        result.append(zigZagStr[i]);
    }
    return result;
}

int main(){
    string test_str = "AB";
    string res_1 = convert(test_str, 1);
    cout << res_1 << endl;
    return 0;
}