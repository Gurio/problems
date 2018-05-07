/*
 *
 https://leetcode.com/problems/regular-expression-matching
 *
 */
 
#include <string>
#include <vector>
#include <iostream>
#include <tuple>
#include <limits>

using namespace std;

bool isMatch(string& text, string& pattern) {
    vector<vector<bool>> dp(text.size() + 1, vector<bool>(pattern.size() + 1));
    dp[text.size()][pattern.size()] = true;
    
    for (int i = text.size(); i >= 0; i--){
        for (int j = pattern.size() - 1; j >= 0; j--){
            bool first_match = (i < text.size() && 
                                    (pattern[j] == text[i] ||
                                    pattern[j] == '.'));
            if (j + 1 < pattern.size() && pattern[j+1] == '*'){
                dp[i][j] = dp[i][j+2] || first_match && dp[i+1][j];
            } else {
                dp[i][j] = first_match && dp[i+1][j+1];
            }
        }
    }
    return dp[0][0];        
}

void test (string str, string pattern, bool expected){
    cout << str << " vs ";
    cout << pattern << endl;
    bool result = isMatch(str, pattern);
    cout << "result: " << result << "; expected: " << expected << endl;
}

int main(){
    test ("aa", "a", false);
    test ("aa", "a*", true);
    test ("ab", ".*", true);
    test ("ab", ".*c", false);
    test ("aab", "c*a*b", true);
    test ("mississippi", "mis*is*p*.", false);
    test ("mississippi", "mis*is*ip*.", true);
    test ("mississippi", "mis*.*pi", true);
    test ("mississippi", "mis*.*pppi", false);
    test ("a", "ab*", true);
    test ("aaa", "aaaa", false);
    test ("aaa", "aaac", false);
    return 0;
}