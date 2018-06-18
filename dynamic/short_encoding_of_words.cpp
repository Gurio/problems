/*
 *
 https://leetcode.com/problems/short-encoding-of-words
 *
 */

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

int minimumLengthEncoding(vector<string>& words) {
	if (words.empty()){return 0;}
	set<string> rev_words;
	for (auto &w: words){
		reverse(w.begin(), w.end());
		rev_words.insert(w);
	}
	int encoded_len=0;
	for (auto &rw: rev_words){
		auto next_word = rw;
		++next_word[next_word.size()-1];
		auto beg_i = rev_words.upper_bound(rw);		
		auto end_i = rev_words.lower_bound(next_word);
        bool contained = false;
		while (beg_i != end_i){
			if (beg_i->size()>rw.size() && !beg_i->compare(0,rw.size(),rw)){
                contained = true;
            }
			++beg_i;
		}
        if (!contained){encoded_len+=rw.size()+1;}
	}
    return encoded_len;
}

int main(){
    vector<string> words = {"time", "me", "bell"};
    cout << minimumLengthEncoding(words) << endl;
    words = {"time", "me", "e", "bell"};
    cout << minimumLengthEncoding(words) << endl;
    words = {"time", "me", "e", "bell", "el"};
    cout << minimumLengthEncoding(words) << endl;
    return 0;
}