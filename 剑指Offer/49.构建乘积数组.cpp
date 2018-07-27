class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
     
         
            int n = A.size();
    vector<int> B0(n, 1);
    vector<int> B1(n, 1);
 
    for (int i = 1; i < n;++i)
    {
        B0[i] = B0[i - 1] * A[i - 1];
    }
    for (int i = n - 2; i >= 0;--i)
    {
        B1[i] = B1[i + 1] * A[i + 1];
    }
 
    vector<int> B(n, 1);
    for (int i = 0; i < n;++i)
    {
        B[i] = B0[i] * B1[i];
    }
 
    return B;
         
         
    }
};
