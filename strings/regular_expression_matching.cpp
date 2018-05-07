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

struct Token {
    char symbol;
    bool is_any;
    bool is_multiple;
    Token (char c, bool ia, bool im): symbol(c), is_any(ia), is_multiple(im) {}
    friend ostream& operator<<(ostream& os, const Token& token);  
};
ostream& operator<<(ostream& os, const Token& token)  
{  
    os << "(";
    if (token.is_any){
        os << ".";
    } else {
        os << token.symbol;
    }
    if (token.is_multiple){
        os << "*";
    }
    os << ")";
    return os;  
} 

bool matchHelper(const string& s, vector<Token>& tokens, size_t s_idx, size_t token_idx){
    while (s_idx<s.size() && token_idx<tokens.size()){
        char c = s[s_idx];
        Token& token = tokens[token_idx];
        if (token.is_any && token.is_multiple){

            cout<<"matching token:" << token << ":" <<token_idx<< ", against sym: " << c << ":" << s_idx << endl;
            while (token.is_any && token.is_multiple){
                if (token_idx >= tokens.size()-1){
                    return true;
                }
                token = tokens[++token_idx];
            }
            while (true){
                if (++s_idx >= s.size()){cout<<"wildcard has unmatched trailing symbols"<<endl;return false;}
                c=s[s_idx];
                if (c==token.symbol || token.is_any){
                    bool subres = matchHelper(s,tokens,s_idx,token_idx);
                    if (subres) {return true;}
                }
            }
        }
        if (!token.is_multiple){
            cout<<"matching token:" << token << ":" <<token_idx<< ", against sym: " << c << ":" << s_idx << endl;
            if (!token.is_any && token.symbol != c){
                if (token.is_any){
                    cout<<"token " << token.is_any <<" at pos "<< token_idx << " not matched"<<endl;
                } else {
                    cout<<"token " << token.symbol <<" at pos "<< token_idx << " not matched"<<endl;
                }
                cout<<"against symbol " << c <<" at pos "<< s_idx << " not matched"<<endl;
                return false;
            }
            s_idx++;
            token_idx++;
            continue;
        }
        cout<<"matching token:" << token << ":" <<token_idx<< ", against sym: " << c << ":" << s_idx << endl;
        while (token.is_multiple && c==token.symbol){
            if (++s_idx>=s.size()){return true;}
            c=s[s_idx];
        }
        token_idx++;
    }
    while (token_idx<tokens.size()){
        Token& token = tokens[token_idx];
        if (!token.is_multiple){break;}
        token_idx++;
    }
    cout<<"matching finished token_idx:" << token_idx <<"; s_idx: "<< s_idx << "; sizes:"<<tokens.size()<< "," << s.size()<<endl;
    return (s_idx>=s.size() && token_idx>=tokens.size());
}

bool isMatch(string s, string p) {
    if (p.empty()) {return s.empty();}
    vector<Token> tokens;
    for (int i=0; i<p.size(); i++){
        char c = p[i];
        if (c=='*') {continue;}
        bool is_any = (c=='.');
        bool is_multiple = (i+1 < p.size() && p[i+1]=='*');
        //
        //
        //IF SAME SIMBOL FOLLOWS, COMBINE THEM INTO ONE MULTIPLE TOKEN? OR BETTER REARRANGE
        tokens.emplace_back(c,is_any,is_multiple);
    }
    for (int i = 0; i<tokens.size(); i++){
        cout << tokens[i] << ':'<< i << ';';
    }
    cout << endl;
    return matchHelper(s,tokens,0,0);
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