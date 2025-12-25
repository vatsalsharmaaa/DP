class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        sort(happiness.rbegin(), happiness.rend());
      
        // Initialize the total happiness sum
        long long totalHappiness = 0;
      
        // Select k children with the highest happiness values
        for (int i = 0; i < k; ++i) {
            
            int adjustedHappiness = happiness[i] - i;
          
            // Add the adjusted happiness to total (minimum 0 if happiness becomes negative)
            totalHappiness += max(adjustedHappiness, 0);
        }
      
        return totalHappiness;
    }
};