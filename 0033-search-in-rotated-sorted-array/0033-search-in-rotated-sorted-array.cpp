class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = nums.size()-1;

        while(low<=high)
        {
            int mid = (low + high)>>1;
            if(nums[mid] == target) return mid;

            // if left half is sorted
            if(nums[mid] >= nums[low])
            {
                if(nums[low]<=target && nums[mid]>=target)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                // This is if right half is sorted 
                if(target>=nums[mid] && target<=nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};