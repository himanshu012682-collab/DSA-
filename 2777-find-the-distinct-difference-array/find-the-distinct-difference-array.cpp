class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        unordered_set<int> left;
        unordered_map<int, int> freq;

        // Count frequency of every element
        for (int x : nums) {
            freq[x]++;
        }

        for (int i = 0; i < n; i++) {

            // Current element is now part of left
            left.insert(nums[i]);

            // Remove current element from right
            freq[nums[i]]--;

            // If no occurrence remains on right
            if (freq[nums[i]] == 0) {
                freq.erase(nums[i]);
            }

            ans[i] = left.size() - freq.size();
        }

        return ans;
    }
};