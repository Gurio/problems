/*
 *
 CCI 1.4 Palindrome permutation
 *
 */
 
#include <string>
#include <vector>
#include <iostream>
#include <tuple>
#include <limits>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>

using namespace std;

bool PalindromePermutation (const string& inp){
    unordered_map<char,int> chars;
    for (auto c: inp){
        ++chars[c];
    }
    int odd_chars = 0;
    for (auto kv: chars){
        if((kv.second % 2) != 0){
            ++odd_chars;
        }
    }
    return odd_chars <= 1;
}

int main(){
    
    cout << PalindromePermutation("ap") << endl;
    cout << PalindromePermutation("a") << endl;
    cout << PalindromePermutation("ab  -v-  vab") << endl;
    cout << PalindromePermutation("aaa bbn") << endl;
    cout << PalindromePermutation("aaa  bbna") << endl;

    return 0;
}