#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i=0; i<9; i++){
            vector<char> rowArr;
            std::unordered_set<char> rowSet;
            vector<char> colArr;
            std::unordered_set<char> colSet;
            for (int j=0; j<9; j++){
                if (board[i][j] != '.'){
                    rowSet.insert(board[i][j]);
                    rowArr.push_back(board[i][j]);
                }
                if(board[j][i] != '.'){
                    colSet.insert(board[j][i]);
                    colArr.push_back(board[j][i]);
                }
            }
            if ((rowSet.size() != rowArr.size()) || (colSet.size() != colArr.size())){
                return false; // row or col has repetitions
            }}
        for(int blockRow = 0; blockRow < 3; blockRow++){
            for (int blockCol = 0; blockCol < 3; blockCol++){
                vector<char> blockArr;
                std::unordered_set<char> blockSet;
                for(int i = 0; i < 3; i++){ // put all the elements of the block in a set and array
                    for(int j=0; j<3; j++){
                        if (board[blockRow*3 + i][blockCol*3 + j] != '.'){
                            blockSet.insert(board[blockRow*3 + i][blockCol*3 + j]);
                            blockArr.push_back(board[blockRow*3 + i][blockCol*3 +j]);
                        }
                    }
                }
                if (blockSet.size() != blockArr.size()){
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){
    //std::vector<int> gas= {1, 2, 3, 4, 5};
    //std::vector<int> cost= {3, 4, 5, 1, 2};
    Solution s;
    return 0;
} 