/*
 *
 Cracking Coding Interview 3.4
 *
 */

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

template <typename T>
void moveDisks(stack<T>& src, stack<T>& dst, stack<T>& spare, int base_size) {
    if (src.size()<=base_size+1){
        dst.push(src.top());
        src.pop();
        return;
    }
    int spare_base_size = spare.size();
    moveDisks(src,spare,dst,base_size+1);
    dst.push(src.top());
    src.pop();
    moveDisks(spare,dst,src,spare_base_size);
}

int main(){
    stack<int> src;
    stack<int> dst;
    stack<int> spare;
    for (auto& item : {1,2,3,4,6,8,9,11,13,14,15}) {
        src.push(item);
    }
    moveDisks(src, dst, spare, 0);
    
    while (src.size() >= 1 || dst.size() >= 1 || spare.size() >= 1){
        if (src.size() == 0) {src.push(0);} 
        if (dst.size() == 0) {dst.push(0);} 
        if (spare.size() == 0) {spare.push(0);}

        cout << src.top() << '\t' << dst.top() << '\t' << spare.top() << '\t' << endl;

        src.pop(); 
        dst.pop();
        spare.pop();
    }
    
    return 0;
}