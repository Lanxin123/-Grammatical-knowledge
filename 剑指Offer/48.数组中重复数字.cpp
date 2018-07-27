class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], const int length, int* duplication) {
		if (numbers == NULL || length == 0)
			return 0;
		vector<int> key(length, 0);
		int count = 0;
		for (int i = 0; i < length; i++)
		{
			key[numbers[i]]++;
			if (key[numbers[i]] > 1)
			{
				duplication[count++] = numbers[i];
				return true;
			}
		}
		return false;
	}
};