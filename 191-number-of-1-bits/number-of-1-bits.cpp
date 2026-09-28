class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        while(n!=0){
            int k=n&1;
            if(k!=0){
                count++;
            }
            n=n>>1;
        }
        return count;
    }
};