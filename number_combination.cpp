#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

class Solution {
public:
    Solution()
    {
        this->LetterNumberMapping.insert(std::pair < int, string > {1, ""});
        this->LetterNumberMapping.insert(std::pair < int, string > {2, "abc"});
        this->LetterNumberMapping.insert(std::pair < int, string > {3, "def"});
        this->LetterNumberMapping.insert(std::pair < int, string > {4, "ghi"});
        this->LetterNumberMapping.insert(std::pair < int, string > {5, "jkl"});
        this->LetterNumberMapping.insert(std::pair < int, string > {6, "mno"});
        this->LetterNumberMapping.insert(std::pair < int, string > {7, "pqrs"});
        this->LetterNumberMapping.insert(std::pair < int, string > {8, "tuv"});
        this->LetterNumberMapping.insert(std::pair < int, string > {9, "wxyz"});
    }
    map<int, string> LetterNumberMapping;
    

    vector<string> letterCombinations(string digits) {
        list<string> result{""};
        if (digits.size() >= 0)
        {
            vector<int> numbers;
            for (int i = 0; i < digits.size(); i++)
            {
                numbers.push_back((int)(digits[i] - '0'));
            }

            PrintNumber(result, numbers);
        }

        return vector<string>(result.begin(), result.end());
    }

    void PrintNumber(list<string> &result, const vector<int> &numbers)
    {
        for (auto n : numbers)
        {
            size_t count = result.size();
            for (size_t i = 0; i < count; i++)
            {
                string f = result.front();
                result.pop_front();

                for (auto j : this->LetterNumberMapping[n])
                {
                    result.push_back(f + j);
                }
            }
        }
    }
};
