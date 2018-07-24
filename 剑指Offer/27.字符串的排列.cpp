class Solution {
public:
    vector<string> result;
    
    void Permutation(string str,int begin){
        if(begin == str.length()){
            result.push_back(str);
            return ;
        }
            for(int i = begin; str[i]!='\0';i++){
                 
                if(i!=begin&&str[begin]==str[i])
                    continue;
                swap(str[begin],str[i]);
                Permutation(str,begin+1);
                swap(str[begin],str[i]);
            }
             
    }
    
    vector<string> Permutation(string str) {
        if(str.length()==0){
            return result;
        }
        Permutation(str,0);
        sort(result.begin(),result.end());
        return result;
    }
    
};
