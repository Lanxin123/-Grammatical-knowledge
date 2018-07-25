class Solution {
public:
      int Min(int number1, int number2, int number3)
{
	int min = number1 < number2 ? number1 : number2;
	min = min < number3 ? min : number3;
	return min;
}

int GetUglyNumber_Solution(int index)
{
	if (index<=0)
	{
		return 0;
	}

	int *pUglyNumbers = new int[index];
	pUglyNumbers[0] = 1;
	int nextUglyIndex = 1;

	int *pMultioly2 = pUglyNumbers;
	int *pMultioly3 = pUglyNumbers;
	int *pMultioly5 = pUglyNumbers;

	while (nextUglyIndex<index)
	{
		int min = Min(*pMultioly2 * 2,*pMultioly3*3,*pMultioly5*5);
		pUglyNumbers[nextUglyIndex] = min;
		while (*pMultioly2*2<=pUglyNumbers[nextUglyIndex])
		{
			++pMultioly2;
		}
		while (*pMultioly3*3<=pUglyNumbers[nextUglyIndex])
		{
			++pMultioly3;
		}
		while (*pMultioly5*5<=pUglyNumbers[nextUglyIndex])
		{
			++pMultioly5;
		}

		++nextUglyIndex;
	}
	int ugly = pUglyNumbers[nextUglyIndex - 1];
	delete[] pUglyNumbers;
	return ugly;
}
};