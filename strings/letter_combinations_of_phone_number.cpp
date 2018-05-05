/*
 *
 https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 */

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string get_str(int number){
    switch (number) {
        case 2: {return "abc";}
        case 3: {return "def";}
        case 4: {return "ghi";}
        case 5: {return "jkf";}
        case 6: {return "mno";}
        case 7: {return "pqrs";}
        case 8: {return "tuv";}
        case 9: {return "wxyz";}
        case 0: {return " ";}
        default : {return "";}
    }
}
vector<string> letterCombinations(string digits) {
    vector<string> result;
    for (int i=0; i<digits.size(); i++){
        vector<string> sub_result;
        string str = get_str(digits[i]-'0');
        if (result.empty()){
            for (char c: str){result.push_back(string(1, c));}
        } else {
            for (char c: str){
                for (string hist: result){
                    sub_result.push_back(hist+c);
                }
            }
            result = move(sub_result);
        }
    }
    return result;
}

int main(){
    string test_str = "23";
    vector<string> result = letterCombinations(test_str);
    for (std::vector<string>::const_iterator i = result.begin(); i != result.end(); ++i)
        cout << *i << ' '; 
    cout << endl;
    return 0;
}