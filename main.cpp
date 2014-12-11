#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<string> split(const string& s, char delim) {
        vector<string> flds;
        string work = s.data();
        string buf = "";
        size_t i = 0;
        while (i < work.length()) {
            if (work[i] != delim){
                buf += work[i];
            } 
            else if (buf.length() > 0) {
                flds.push_back(buf);
                buf = "";
            }
            i++;
        }
        if (!buf.empty())
            flds.push_back(buf);
        return flds;
    }
    
    static bool isMatch(const char *s, const char *p) {
        if (!s || !p)
        {
            return false;
        }

        string stringS(s), stringP(p);
        vector<string> tokens = split(stringP, '*');
        // cout << "Get " << tokens.size() << " tokens" << endl;
        
        if (tokens.size() == 0)
        {
            return true;
        }

        size_t i=0;
        size_t j=0;
        while(i < stringS.size() && j < tokens.size())
        {
            size_t pos = string::npos;
            if (j < tokens.size() - 1)
            {
                pos = stringS.find(tokens[j], i);
            }
            else
            {
                pos = stringS.rfind(tokens[j]);
            }
            
            if (j == 0 && pos != 0)
            {
                break;
            }
            else if(j == tokens.size() - 1 && pos != stringS.size() - tokens.back().size())
            {
                break;
            }
            else if(pos == string::npos)
            {
                break;
            }
            
            i += tokens[j].size();
            j++;
        }

        if (j == tokens.size() )
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main(int argc, char **argv)
{
    cout<<"Match?"<<Solution::isMatch("a", "a")<<endl;
    cout<<"Match?"<<Solution::isMatch("a", "b")<<endl;
    cout<<"Match?"<<Solution::isMatch("aa", "a")<<endl;
    cout<<"Match?"<<Solution::isMatch("aa", "*")<<endl;
    cout<<"Match?"<<Solution::isMatch("aaa", "a*a")<<endl;
    cout<<"Match?"<<Solution::isMatch("aa", "a*a")<<endl;
    return 0;
}
