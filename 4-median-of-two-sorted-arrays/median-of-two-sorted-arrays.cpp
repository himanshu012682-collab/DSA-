class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nums3;
        double ans;
        for(int i=0;i<nums1.size();i++){
            nums3.push_back(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            nums3.push_back(nums2[i]);
        }
        sort(nums3.begin(),nums3.end());
        int n=nums3.size();
        double mid=n/2.00000;
        if(n%2==0){
             ans= (nums3[mid]+nums3[mid-1])/2.00000;

        }
        else{
            ans= nums3[mid];
        }
        return ans;
    }
};