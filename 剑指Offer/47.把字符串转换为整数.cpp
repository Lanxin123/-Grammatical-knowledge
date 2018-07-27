class Solution {
public:
    int StrToInt(string str) {
        if(str.size()==0)
            return 0;
        int result;
        bool sign = true;
        int i;
        while(str[i]==' '&&str[i]!='\0')
            i++;
        if(str[i]=='+')
        {
            i++;
            sign = true;
        }
            
        if(str[i]=='-')
        {
            i++;
            sign = false;
        }

        while(str[i]!='\0')
        {
            if(str[i]==' ')
            {
                i++;
                continue;
            }
            if(str[i]>'9'||str[i]<'0')
                return 0;
            result = result*10+(str[i]-'0');
            i++;
        }
        if(sign == false)
            result = -result;
        return result;
    }
};