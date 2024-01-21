class Solution {
public:
    int rob(vector<int>& nums) {
        int prevMax = 0;  // Maximum amount of money robbed from the previous house
        int currMax = 0;  // Maximum amount of money robbed from the current house

        for (int num : nums) {
            int temp = currMax;
            currMax = max(prevMax + num, currMax);
            prevMax = temp;
        }

        return currMax;
    }
};
