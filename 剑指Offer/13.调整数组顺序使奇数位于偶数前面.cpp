class Solution {
public:
    void reOrderArray(vector<int> &array) {
	
		vector<int> temp;
		auto iter = array.begin();
		for (iter = array.begin(); iter != array.end(); iter++)
		{
			if (*iter & 1)
			{
				temp.push_back(*iter);
			}
		}
		for (iter = array.begin(); iter != array.end(); iter++)
		{
			if (~*iter & 1)//(!(*iter & 1)) 优先级问题~和~先和*iter结合
			{
				temp.push_back(*iter);
			}
		}
		array = temp;
	}
};