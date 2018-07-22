class Solution {
public:
    	int Fibonacci(int n) {
         if(n<0)
             return 0;
        int f = 0, g = 1;
        while(n--) {
            g += f;//f是n的结果 而g是n+1的结果先求n+1再求n
            f = g - f;
        }
        return f;
    }
};