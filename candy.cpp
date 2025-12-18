#include <vector>
#include <numeric>
using namespace std;


class Solution {
public:
    int candy(vector<int>& ratings) {
        bool changedFlag = true;
        int s = ratings.size();
        int sum=0;
        vector<int> candy(s, 1);
        if (s==1){ 
            return 1;
        }
        while (changedFlag){
            changedFlag=false;
            if ((ratings[0] > ratings[1]) && (candy[0] <= candy[1])) {
                candy[0]=candy[1]+1;
                changedFlag=true;
            }
            for(unsigned i=1; i<s-1; i++){
                if ((ratings[i] > ratings[i-1]) && (candy[i] <= candy[i-1])){
                        candy[i]=candy[i-1]+1;
                        changedFlag=true;
                    }
            }
            if (((ratings[s-1]) > ratings[s-2]) && (candy[s-1] <= candy[s-2])) {
                candy[s-1]=candy[s-2]+1;
                changedFlag=true;
            }
            
            // useful to go backwards in case decreasing
            for(unsigned i=s-2; i>=1; i--){
                if ((ratings[i] > ratings[i+1]) && (candy[i] <= candy[i+1])){
                        candy[i]=candy[i+1]+1;
                        changedFlag=true;
                    }
            }


        }
        
        sum += std::accumulate(candy.begin(), candy.end(), 0);
        return sum;
    }
};

int main(){
    Solution s;
    vector<int> myVec = {1, 2, 2};
    s.candy(myVec);
    return 0;
} 