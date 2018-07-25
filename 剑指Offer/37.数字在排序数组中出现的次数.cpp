class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        map<int,int> temp;
        for(auto iter = data.begin();iter!=data.end();++iter)
        {
            temp[*iter]++;
        }
        return temp[k];
    }
};