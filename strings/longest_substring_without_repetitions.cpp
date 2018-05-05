/*
 *
 https://leetcode.com/problems/longest-substring-without-repeating-characters/
 *
 */

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int lengthOfLongestSubstring(const string& s) {
    if (s.size() < 2) {return s.size();}
    int maxLen = 0;
    int curLen = 0;
    unordered_map<char,size_t> last_idx;
    for (size_t i=0; i<s.size(); ++i){
        char ch = s[i];
        if (last_idx.find(ch) == last_idx.end()){
            curLen++;
        } else {
            size_t last = last_idx[ch];
            size_t newLen = i - last;
            if (newLen > curLen) {
                curLen++;
            } else {
                curLen = newLen;
            }
        }
        last_idx[ch] = i;
        maxLen = max(maxLen, curLen);
    }
    return maxLen;
}

int main(){
    string test_str = "pwwkew";
    int result = lengthOfLongestSubstring(test_str);
    cout << result << endl;
    return 0;
}