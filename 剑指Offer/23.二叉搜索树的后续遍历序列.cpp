class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int size = sequence.size();
        if(0==size)return false;
 
        int i = 0;
        while(--size)
        {
            while(sequence[i++]<sequence[size]);
            while(sequence[i++]>sequence[size]);
            //比sequence小的在左边，大的在右边，如果最后的i<size，前必有一项不满足。 
            if(i<size)return false;
            i=0;
        }
        return true;
    }
};
