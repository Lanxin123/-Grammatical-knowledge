class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> temp;
        if(k>input.size())
            return temp;
        sort(input.begin(),input.end());
        for(int i=0;i<k;i++)
            temp.push_back(input[i]);
        return temp;
    }
};