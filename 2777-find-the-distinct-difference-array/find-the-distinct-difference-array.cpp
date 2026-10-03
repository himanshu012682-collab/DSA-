class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        vector<int>arr(nums.size());
        for(int i=0;i<nums.size();i++){
            unordered_set<int>a;
            unordered_set<int>b;
            for(int j=i+1;j<nums.size();j++){
                a.insert(nums[j]);
            }
            for(int j=0;j<=i;j++){
                b.insert(nums[j]);
            }
            arr[i]=b.size()-a.size();


        }
        return arr;
        
    }
};