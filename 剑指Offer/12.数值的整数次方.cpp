class Solution {
public:
	double Power(double base, int exponent) {
		double result = 1;
		if (exponent > 0)
		{
			while (exponent != 0)
			{
				result *= base;
				exponent--;
			}
		}
		if (exponent < 0)
		{
			while (exponent != 0)
			{
				result *= base;
				exponent++;
			}
			result = 1 / result;
		}
		return result;
	}
};