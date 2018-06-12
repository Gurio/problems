/*
 *
 https://leetcode.com/problems/substring-with-concatenation-of-all-words
 *
 */

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <numeric>
#include <iostream>
#include <functional>
#include <chrono>
#include <array>


using namespace std;
using namespace std::chrono;

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> result;
    if (words.empty()){return result;}
    unordered_map<string,int> words_m;
    int len = words[0].size();
    int num = words.size();
    for (auto w: words){
        words_m[w]++;
    }
    for (int i=0; i<(s.size()-len*num); i++){
        unordered_map<string,int> history;
        int j=0;
        for(;j<num;j++){
            string word = s.substr(i+j*len,len);
            history[word]++;
            if (!words_m.count(word) || words_m[word]<history[word]){
                break;
            }
        }
        if (j==num){result.push_back(i);}
    }
    return result;
}

int main(){
    string test_str;
    vector<string> words;
    vector<int> result;

    test_str = "barfoothefoobarman";
    words = {"foo","bar"};
    result = findSubstring(test_str, words);

    for (std::vector<int>::const_iterator i = result.begin(); i != result.end(); ++i)
        cout << *i << ", "; 
    cout << endl;

    return 0;
}