#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

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
        vector<string> result;
        if (digits.size() == 0)
        {
            return result;
        }
        vector<int> numbers;
        for (int i = 0; i < digits.size(); i++)
        {
            numbers.push_back((int)(numbers[i] - '0'));
        }

        vector<string> stage{""};
        PrintNumber(result, stage, numbers);
    }

    void PrintNumber(vector<string> &result, const vector<string> &stage, const vector<int> numbers)
    {
        if (numbers.size() == 1)
        {
            for (auto i : stage)
            {
                for (auto j : Solution::LetterNumberMapping.at(numbers[0]))
                {
                    result.push_back(i + j);
                }
            }

            return;
        }


    }
};

void main()
{
    Solution solution;

    solution.letterCombinations("23");
}
