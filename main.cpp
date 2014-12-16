#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> split(const string& s, char delim) {
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
    
    size_t find(const string &a, size_t start, const string &b)
    {
        if (a.empty() || b.empty() || a.size() < b.size())
        {
            return string::npos;
        }
        
        size_t i = start, j = 0;
        while (i < a.size() && j < b.size())
        {
            if (a[i+j] == b[j] || b[j] == '?')
            {
                j++;
            }
            else
            {
                i++;
                j = 0;
            }
        }
        
        if (j == b.size())
        {
            return i;
        }
        else
        {
            return string::npos;
        }
    }
    
    size_t rfind(const string &a, const string &b)
    {
        if (a.empty() || b.empty() || a.size() < b.size())
        {
            return string::npos;
        }
        
        size_t i = a.size() - b.size(), j = 0;
        while (i >= 0 && j < b.size())
        {
            if (a[i+j] == b[j] || b[j] == '?')
            {
                j++;
            }
            else
            {
                if (i > 0)
                {
                    i--;
                }
                else
                {
                    break;
                }
                
                j = 0;
            }
        }
        
        if (j == b.size())
        {
            return i;
        }
        else
        {
            return string::npos;
        }
    }
    
    bool isMatch(const char *s, const char *p) {
        string stringS(s);
        string stringP(p);

        vector<string> tokens = split(stringP, '*');

        // p and s are all empty (not null) situation
        if (stringP.empty() && stringS.empty())
        {
            return true;
        }

        // p is * or multiple * situation
        if (tokens.size() == 0 && stringP.find('*') != string::npos)
        {
            return true;
        }
        
        if (tokens.size() <= 1 && stringP.find('*') == string::npos)
        {
            return find(stringS, 0, stringP) == 0 && stringS.size() == stringP.size();
        }
        
        bool checkStart = false;
        bool checkEnd = false;
        if (stringP.front() != '*')
        {
            checkStart = true;
        }
        
        if (stringP.back() != '*')
        {
            checkEnd = true;
        }

        size_t i=0;
        size_t j=0;
        while(i < stringS.size() && j < tokens.size())
        {
            size_t pos = string::npos;
            if (checkEnd && j == tokens.size() - 1)
            {
                pos = rfind(stringS, tokens[j]);
            }
            else
            {
                pos = find(stringS, i, tokens[j]);
            }
            
            if (j == 0 && checkStart && pos != 0)
            {
                break;
            }
            else if(j == tokens.size() - 1 && checkEnd && (pos != stringS.size() - tokens.back().size() || pos < i))
            {
                break;
            }
            else if (j == tokens.size() - 1 && !checkEnd && pos < i)
            {
                break;
            }
            else if(pos == string::npos)
            {
                break;
            }
            
            i = pos + tokens[j].size();
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
    Solution solution;
    //cout<<"Match?"<<solution.isMatch("a", "a")<<endl;
    //cout<<"Match?"<<solution.isMatch("a", "?")<<endl;
    //cout<<"Match?"<<solution.isMatch("a", "b")<<endl;
    //cout<<"Match?"<<solution.isMatch("aa", "a")<<endl;
    //cout<<"Match?"<<solution.isMatch("a", "aa")<<endl;
    //cout<<"Match?"<<solution.isMatch("aa", "a*")<<endl;
    //cout<<"Match?"<<solution.isMatch("aa", "*")<<endl;
    //cout<<"Match?"<<solution.isMatch("aaa", "a*a")<<endl;
    //cout<<"Match?"<<solution.isMatch("aa", "a*a")<<endl;
    //cout<<"Match?"<<solution.isMatch("aa", "a**a")<<endl;
    //cout<<"Match?"<<solution.isMatch("aaa", "a*a*a")<<endl;
    //cout<<"Match?"<<solution.isMatch("aaa", "a*a*?")<<endl;
    //cout<<"Match?"<<solution.isMatch("abcede", "abc*d")<<endl;
    //cout<<"Match?"<<solution.isMatch("abce", "abc*??")<<endl;
    //cout<<"Match?"<<solution.isMatch("mississippi", "m*i*si*si*si*pi")<<endl;
    //cout<<"Match?"<<solution.isMatch("hi", "*?")<<endl;
    cout<<"Match?"<<solution.isMatch("aaab", "b**")<<endl;
    return 0;
}

