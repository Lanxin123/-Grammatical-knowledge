class Solution
{
public:
	bool Find( int target, vector<vector<int>> array)
	{
		if (array.empty())
		{
			return false;
		}
		int row = array.size();//行
		int col = array[0].size();//列
		int i = 0;
		int j = col - 1;
		while (i < row - 1 && j>0)
		{
			if (array[i][j] > target)
			{
				j--;
			}
			if (array[i][j] < target)
			{
				i++;
			}
			if (array[i][j] == target)
			{
				return true;
			}
		}
		return false;
	}
};