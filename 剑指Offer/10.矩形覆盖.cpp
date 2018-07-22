class Solution {
public:
    int rectCover(int number) {
        if(number<=2)
            return number;
       // return rectCover(number-1)+rectCover(number-2); 递归
        int f = 1,g = 1;
        while(number--)
        {
            g+=f;//动态规划法
            f=g-f;
        }
        return f;
    }
};