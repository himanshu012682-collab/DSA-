class Solution {
public:
static bool compare(vector<int>& a, vector<int>& b) 

    { 

        // Same width -> height decreasing 

        if(a[0] == b[0]) 

            return a[1] > b[1]; 

        // Width increasing 

        return a[0] < b[0]; 

    } 
int ceilIdx(vector<int>& tail, int l, int r, int x) 

    { 

        while(r > l) 

        { 

            int m = l + (r - l) / 2; 

            if(tail[m] >= x) 

                r = m; 

            else 

                l = m + 1; 

        } 

        return r; 

    } 

 

    

 
    int maxEnvelopes(vector<vector<int>>& envelopes) {
         sort(envelopes.begin(), envelopes.end(), compare); 

 

        // Step 2: Empty case 

        if(envelopes.size() == 0) 

            return 0; 

 

        // Step 3: LIS on heights 

        vector<int> tail; 

        int len = 1; 

        tail.push_back(envelopes[0][1]); 

 

        for(int i = 1; i < envelopes.size(); i++) 

        { 

            int height = envelopes[i][1]; 

 

            // Height is greater 

            // Extend LIS 

            if(height > tail[len - 1]) 

            { 

                tail.push_back(height); 

                len++; 

            } 

            else 

            { 

                // Find first position 

                // where tail[index] >= height 

                int index = ceilIdx(tail, 0, len - 1, height); 

                tail[index] = height; 

            } 

        } 

 

        return len; 

    } 

}; 
        
    