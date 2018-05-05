/*
 *
https://leetcode.com/problems/add-two-numbers/
DIGITS ARE REVERSED!
======================
there is no need to append zeroes, or compare length
So please don't
 *
 */


#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int lenDiff (ListNode* l1, ListNode* l2){
    int diff = 0;
    while (l1 && l2){
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1){
        ++diff;
        l1 = l1->next;
    }
    while (l2){
        --diff;
        l2 = l2->next;
    }
    return diff;
}

ListNode* prependZeroes(ListNode* l, int zeroes){
    ListNode *result = l;
    while (l->next){
        l = l->next;
    }
    for (int i=0; i<zeroes; i++){
        ListNode *zero = new ListNode(0);
        l->next = zero;
        l = zero;
    }
    return result;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int len_diff = lenDiff(l1,l2);
    if (len_diff < 0){
        l1 = prependZeroes(l1,-len_diff);
    } else {
        l2 = prependZeroes(l2,len_diff);
    }
    int rem = 0;
    ListNode* result = new ListNode(0);
    ListNode* sum = result;
    while (l1){
        sum->val = l1->val + l2->val + rem;
        rem = sum->val/10;
        sum->val %= 10;
        l1 = l1->next;
        l2 = l2->next;
        if (l1 || rem){
            sum->next = new ListNode(rem);
            sum = sum->next;
        }
    }
    return result;
}

int main (){
    ListNode *l1 = new ListNode (9);
    ListNode *l2 = new ListNode (1);
    l1->next = new ListNode (8);
    //l1->next->next = new ListNode (3); 
    //l2->next = new ListNode (6);
    //l2->next->next = new ListNode (4);

    ListNode* result = addTwoNumbers(l1,l2);
    while (result){
        cout << result->val << ' ';
        result = result->next;
    } 
    cout << endl;

    return 0;
}