/*
 *
 https://leetcode.com/problems/generate-parentheses
 *
 */
 
#include <string>
#include <vector>
#include <iostream>
#include <tuple>
#include <limits>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_set<string> generateHelper(int n) {
    if (n==0) {return {};}
    if (n==1) {return {"()"};}
    unordered_set<string> subresult = generateHelper(n-1);
    unordered_set<string> result;
    for (auto str: subresult){
        for (size_t i = 1; i<=str.size()-1; i++){
            if (str[i]!=str[i-1]){
                string new_str_1 = (str);
                new_str_1.insert(i,"()");
                result.insert(std::move(new_str_1));
                
                if (str[i-1]=='(' && str[i] == ')'){
                    string new_str_2 = (str);
                    new_str_2.insert(i,")(");
                    result.insert(std::move(new_str_2));
                }
            }
        }
        string new_str = (str);
        new_str.insert(str.size(),"()");
        result.insert(std::move(new_str));
    }
    cout << endl;
    return result;
}

vector<string> generateParenthesis(int n) {
    unordered_set<string> result = generateHelper(n);
    vector<string> res( result.begin(), result.end());
    return res;
}

int main(){
    vector<string> result = generateParenthesis(10);
    for (std::vector<string>::const_iterator i = result.begin(); i != result.end(); ++i)
        cout << *i << ';'; 
    cout << endl;
    return 0;
}