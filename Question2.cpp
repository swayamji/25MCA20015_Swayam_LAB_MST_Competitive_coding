/*1760. Minimum Limit of Balls in a Bag*/
/*Swayam 25MCA20015*/
class Solution {
public:

    bool possible(vector<int>& nums, int maxOperations, int penalty) {

        long long ops = 0;

        for(int x : nums) {
            ops += (x - 1) / penalty;
        }

        return ops <= maxOperations;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {

        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        int ans = right;

        while(left <= right) {

            int mid = (left + right) / 2;

            if(possible(nums, maxOperations, mid)) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
