class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size(); 
        int sum = 0;
        for (int num : nums) sum += num; 
        bool possible = false;
        for (int k = 1; k <= n / 2; k++) {
            if ((sum * k) % n == 0) {
                possible = true;
                break;
            }
        }
        if (!possible) return false;

        
        int mid = n / 2;    
        int left_size = mid;   
        int right_size = n - mid; 
        
        
        vector<unordered_set<int>> left_sums(left_size + 1);
        int total_left = 1 << left_size; 
        for (int mask = 1; mask < total_left; mask++) {
            int current_sum = 0;
            int count = 0;
            for (int j = 0; j < left_size; j++) {
                if (mask & (1 << j)) { 
                    current_sum += nums[j];
                    count++;
                }
            }
            left_sums[count].insert(current_sum);
        }

        int total_right = 1 << right_size; 
        for (int mask = 0; mask < total_right; mask++) {
            int current_sum = 0;
            int count = 0;
            for (int j = 0; j < right_size; j++) {
                if (mask & (1 << j)) {
                    current_sum += nums[mid + j]; 
                    count++;
                }
            }
            
            for (int k = 1; k <= n / 2; k++) {
                if ((sum * k) % n == 0) {
                    int target_sum = (sum * k) / n;
                    int left_count = k - count; 
                    
                    if (left_count >= 0 && left_count <= left_size) {
                        int required_left_sum = target_sum - current_sum;
                        
                        if (left_count == 0 && current_sum == 0) continue;
                        if (left_count == left_size && count == right_size) continue;
                        
                    
                        if (left_sums[left_count].count(required_left_sum)) {
                            return true; 
                        }
                    }
                }
            }
        }
        return false;
    }
};