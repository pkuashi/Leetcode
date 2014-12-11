#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    static bool isMatch(const char *s, const char *p) {
        if (!s || !p)
        {
            return false;
        }

        const char *sIt = s;
        const char *pIt = p;
        while(*sIt != '\n' && *pIt != '\n')
        {
            if (*sIt == *pIt)
            {
                sIt++;
                pIt++;
            }
            else
            {
                break;
            }
            
            break;
        }

        if (*sIt == '\n' && *pIt == '\n' )
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
    cout<<"Match?"<<Solution::isMatch("hello", "world")<<endl;
    return 0;
}
