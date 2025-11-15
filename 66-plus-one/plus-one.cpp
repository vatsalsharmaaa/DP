class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;      // just increase and return
                return digits;
            }
            digits[i] = 0;        // set to 0 and continue carry
        }

        // If we are here, it means all digits were 9 → result is like 1000...
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
