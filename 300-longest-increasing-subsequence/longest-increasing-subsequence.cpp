class Solution {
public:
int ceil(int tail[],int l,int r,int target){
    while(l<r){
        int mid=l/2+r/2;
        if(tail[mid]>=target){
            r=mid;
        }
        else{
            l=mid+1;
        }
        

    }
    return r;

}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int tail[n];
        tail[0]=nums[0];
        int len=1;
        for(int i=1;i<n;i++){
            if(tail[len-1]<nums[i]){
                tail[len]=nums[i];
                len++;

            }
            else{
                int c=ceil(tail,0,len,nums[i]);
                tail[c]=nums[i];

            }
        }
        return len;
        
    }
};