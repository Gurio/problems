/*
 *
 Cracking Coding Interview 1.6
 *
 */

#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;


void rotateHelper(vector<vector<int>> &mtx,int start,int end)
{
    //if (mtx.size()-end > 2){return;}
    if (start>=end){return;}
    int up = start;
    int down = end;
    int left = start;
    int right = end;
    for (int o=0; o<(end-start); o++){
        int i = start + o;
        int j = end - o;
        int tmp = mtx[up][i];
        mtx[up][i] = mtx[j][left];
        mtx[j][left] = mtx[down][j];
        mtx[down][j] = mtx[i][right];
        mtx[i][right] = tmp;
    }
    rotateHelper(mtx,start+1,end-1);
}

void rotate(vector<vector<int>>& mtx) {
    rotateHelper(mtx,0,mtx.size()-1);
}


int main(){
    vector<vector<int>> input ={{1 , 2 , 3 , 4 , 5},
                                {16, 1, 2, 3, 6},
                                {15, 8, 9, 4, 7},
                                {14, 7, 6, 5, 8},
                                {13, 12, 11, 10, 9}};
    rotate(input);
    for (auto l :input){
        for (auto i: l)
            cout << i << ", "; 
        cout << endl;
    }
    cout <<endl;
    vector<vector<int>> input2 ={{1, 2 , 3 , 4},
                                {12, 1, 2, 5},
                                {11, 4, 3, 6},
                                {10, 9 , 8 , 7}};
    rotate(input2);
    for (auto l :input2){
        for (auto i: l)
            cout << i << ", "; 
        cout << endl;
    }
    cout <<endl;

    vector<vector<int>> input3 ={{1, 2 , 3},
                                {8, 9, 4},
                                {7, 6, 5}};
    rotate(input3);
    for (auto l :input3){
        for (auto i: l)
            cout << i << ", "; 
        cout << endl;
    }
    cout <<endl;


    vector<vector<int>> input4 ={{1, 2 },
                                {4, 3}};
    rotate(input4);
    for (auto l :input4){
        for (auto i: l)
            cout << i << ", "; 
        cout << endl;
    }
    cout <<endl;


    vector<vector<int>> input5 ={{1 , 2 , 3 , 4 , 5 , 6, 7},
                                {24,  1,  2,  3,  5 , 6, 8},
                                {23, 17,  1,  2,  3 , 7, 9},
                                {22, 16,  8,  9,  4 , 8, 10},
                                {21, 15,  7,  6,  5,  9, 11},
                                {20, 14, 13, 12, 11,  10,12},
                                {19, 18, 17, 16, 15,  14,13}};
    rotate(input5);
    for (auto l :input5){
        for (auto i: l)
            cout << i << ", "; 
        cout << endl;
    }
    cout <<endl;
    return 0;
}