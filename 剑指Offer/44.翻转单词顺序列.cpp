class Solution {
public:
    void Reverse(int begin,int end,string& str)
    {
        if(begin<0||end<0)return;
        while(begin<end)
        {
            swap(str[begin],str[end]);
            
            begin++;
            end--;
        }
    }
	string ReverseSentence(string str) {
		if(str.length()<=0)
            return str;
        int begin = 0;
        int end = str.length()-1;
        Reverse(begin,end,str);
        
        begin = end=0;
        while(str[begin] != '\0')
        {
            if(str[begin] == ' ')
            {
                begin++;
                end++;
            }
            else if(str[end] == ' ' || str[end] == '\0')
            {
                Reverse(begin, --end, str);
                begin = ++ end;
            }
            else
                end++;
        }
        return str;

	}
};