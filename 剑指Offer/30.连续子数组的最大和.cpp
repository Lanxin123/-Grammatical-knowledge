class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
         
        int cursum=array[0];
        int maxsum=array[0];
        for(int i=1;i<array.size();i++){
            cursum+=array[i];
            if(cursum<array[i])//加上他还比他小必为负
                cursum=array[i];
            if(cursum>maxsum)
                maxsum=cursum;           
        }
    return maxsum;
    }
};