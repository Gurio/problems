/*
 *
 Cracking Coding Interview 1.7
 *
 */

#include <unordered_map>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;


void zeroDown(vector<vector<int>> &mtx)
{
    unordered_set<int> rows, columns;
    for (int i=0; i<mtx.size(); i++){
        for (int j=0; j<mtx[i].size(); j++){
            if (mtx[i][j]==0){
                rows.insert(i);
                columns.insert(j);
            }
        }
    }
    for (auto row: rows){
        for (int i=0; i<mtx[row].size();i++){
            mtx[row][i]=0;
        }
    }
    for (auto col: columns){
        for (int i=0; i<mtx.size();i++){
            mtx[i][col]=0;
        }
    }
}



int main(){
    vector<vector<int>> input ={{1 , 2 , 0 , 4 , 5},
                                {16, 1, 2, 3, 6},
                                {15, 8, 9, 0, 7},
                                {14, 7, 0, 5, 8},
                                {13, 12, 11, 10, 9}};
    zeroDown(input);
    for (auto l :input){
        for (auto i: l)
            cout << i << "\t, "; 
        cout << endl;
    }
    cout <<endl;
    vector<vector<int>> input2 ={{1, 2 , 3 , 0},
                                {12, 1, 2, 5},
                                {11, 4, 3, 0},
                                {10, 9 , 8 , 0}};
    zeroDown(input2);
    for (auto l :input2){
        for (auto i: l)
            cout << i << "\t, "; 
        cout << endl;
    }
    cout <<endl;

    vector<vector<int>> input3 ={{1, 2 , 3},
                                {8, 0, 4},
                                {7, 6, 5}};
    zeroDown(input3);
    for (auto l :input3){
        for (auto i: l)
            cout << i << "\t, "; 
        cout << endl;
    }
    cout <<endl;


    vector<vector<int>> input4 ={{1, 2 },
                                {4, 3}};
    zeroDown(input4);
    for (auto l :input4){
        for (auto i: l)
            cout << i << "\t, "; 
        cout << endl;
    }
    cout <<endl;


    vector<vector<int>> input5 ={{1 , 2 , 3 , 4 , 5 , 6, 7},
                                {24,  1,  2,  3,  5 , 6, 8},
                                {0, 17,  1,  2,  3 , 7, 9},
                                {0, 16,  0,  9,  0 , 8, 10},
                                {21, 15,  7,  6,  5,  9, 11},
                                {20, 14, 13, 12, 0,  10,12},
                                {19, 18, 17, 16, 15,  14,13}};
    zeroDown(input5);
    for (auto l :input5){
        for (auto i: l)
            cout << i << "\t, "; 
        cout << endl;
    }
    cout <<endl;
    return 0;
}