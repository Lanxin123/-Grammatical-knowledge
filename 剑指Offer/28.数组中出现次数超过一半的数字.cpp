class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int number = *numbers.begin();
		int count = 1;
		for (auto iter = ++numbers.begin();iter!=numbers.end();++iter)
		{
			if (count<0)
			{
				number = *iter;
			}
			if (number==*iter)
			{
				count++;
			}
			else
			{
				count--;
			}
		}
		if (count>0)
		{
			return number;
		}
		return 0;
	}
};