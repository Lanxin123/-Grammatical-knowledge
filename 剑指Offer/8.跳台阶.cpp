class Solution {
public:
    int jumpFloor(int number) {
        if(number<=1)
           return number;
        int n = 1,n_next = 1;
        while(number--)
        {
            n_next+=n;
            n=n_next-n;
        }
        return n;
    }
};