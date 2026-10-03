class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int low =0;
        int high=n-1;
        int area= 0;
        while(low<=high){
            int m=min(height[low],height[high]);
            area=max(area,m*(high-low));
            if(height[high]>height[low]){
                low++;
            }
            else if(height[high]<height[low]){
                high--;
            }
            else{
                low++;
                high--;
            }
        }
      return area;
        
    }
};