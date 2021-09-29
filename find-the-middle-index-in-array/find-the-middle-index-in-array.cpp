class Solution {
public:
	int findMiddleIndex(vector<int> &nums) {
		int left_sum(0), right_sum(0);
				
		for (size_t middleIndex = 0; middleIndex < nums.size(); middleIndex++) {
			// Left
			for (size_t leftSide = 0; leftSide <= middleIndex; leftSide++) {
				if (leftSide == middleIndex) {
					continue;
				}

				left_sum += nums[leftSide];
			}

			// Right
			for (size_t rightSide = middleIndex; rightSide < nums.size(); rightSide++) {
				if (rightSide == middleIndex) {
					continue;
				}

				right_sum += nums[rightSide];
			}

			// Compare
			if (left_sum == right_sum) {
				return middleIndex;
			} else {
				// Reset
				left_sum = 0; right_sum = 0;
			}

		}

		return -1;
	}
};