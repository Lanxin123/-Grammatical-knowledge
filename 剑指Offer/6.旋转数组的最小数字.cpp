class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.empty())
			return 0;
		int left = 0;
		int right = rotateArray.size() - 1;
		int middle = 0;
		while (rotateArray[left]>=rotateArray[right])
		{
			if (right-left==1)
			{
				middle = right;
				break;
			}
			middle = left + (right - left) / 2;
			if (rotateArray[middle] >= rotateArray[left])
				left = middle;
			if (rotateArray[middle] <= rotateArray[right])
				right = middle;
		}
		return rotateArray[middle];
	}
};