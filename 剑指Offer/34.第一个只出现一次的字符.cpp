class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        map<char,int> temp;
        for(int i = 0;i<str.size();i++)
            temp[str[i]]++;
        for(int i = 0;i<str.size();i++)
        {
            if(temp[str[i]]==1)
                return i;
        }
        return -1;
    }
};