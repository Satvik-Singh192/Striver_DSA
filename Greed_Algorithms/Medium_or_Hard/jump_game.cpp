#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        bool canJump(vector<int>& nums) {
            if(nums.size()==1)return true;
            bool zero_present=false;
            vector<int> zero_ind;
            for(int i=0;i<nums.size();i++){
                if(nums[i]==0){
                    zero_present=true;
                    if(i!=nums.size()-1)zero_ind.push_back(i);
                }
            }
            if(zero_present==false)return true;
            for(int i=0;i<zero_ind.size();i++){
                int j=0;bool flyover=false;
                while(j<zero_ind[i]){
                    if(nums[j]>zero_ind[i]-j){
                        flyover=true;break;
                    }
                    j++;
                }
                if(flyover==false)return false;
            }
            return true;
    
        }
};
int main(){
    Solution s;
    vector<int>testcase={1,2,3,0,1,1,1,0};
    cout<<s.canJump(testcase);
}
