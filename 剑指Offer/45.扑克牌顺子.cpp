class Solution {
public:
/*顺子满足的条件：max-min<5;
                除0外其他的数字都不能重复
                传入的数组放5个元素*/
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.empty()) return 0;
        int count[14]={0};//记录每个元素出现的次数;以numbers中的元素作为下标(最大K,对应13)
        int len=numbers.size();
        int max=-1;
        int min=14;
          
        for(int i=0;i<len;++i)
            {
            count[numbers[i]]++;
            if(numbers[i]==0) continue;
              
            if(count[numbers[i]]>1) return 0;
              
            if(numbers[i]>max) max=numbers[i];
              
            if(numbers[i]<min) min=numbers[i];
              
        }//end for
          
        if(max-min<5) return 1;
          
        return 0;
          
    }//end IsContinuous()
};
