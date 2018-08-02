#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    string intToRoman(int num)
    {
        vector<string> ans;
        int level = 0;
        while (num > 0)
        {
            char I, V, X;
            switch (level)
            {
            case 0:
                I = 'I';
                V = 'V';
                X = 'X';
                break;
            case 1:
                I = 'X';
                V = 'L';
                X = 'C';
                break;
            case 2:
                I = 'C';
                V = 'D';
                X = 'M';
                break;
            case 3:
                I = 'M';
                break;
            }
            int n = num % 10;
            num /= 10;
            string s;
            if (n == 9)
            {
                s = s + I + X;
                n = 0;
            }
            else if (n == 4)
            {
                s = s + I + V;
                n = 0;
            }
            else if (n >= 5)
            {
                s = s + V;
                n -= 5;
            }
            while (n--)
            {
                s = s + I;
            }
            level++;
            ans.push_back(s);
        }
        string finalAns;
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            finalAns += ans[i];
        }
        return finalAns;
    }
    int romanToInt(string s)
    {
        int ans = 0;
        map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        for(int i = 0; i < s.length(); i++)
        {
            if (i < s.length() -1 && m[s[i]] < m [s[i+1]])
                ans -= m[s[i]];
            else
                ans += m[s[i]];
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.intToRoman(3) << endl;
    cout << solution.intToRoman(4) << endl;
    cout << solution.intToRoman(9) << endl;
    cout << solution.intToRoman(58) << endl;
    cout << solution.intToRoman(1994) << endl;

    cout << solution.romanToInt("III") << endl;
    cout << solution.romanToInt("IV") << endl;
    cout << solution.romanToInt("IX") << endl;
    cout << solution.romanToInt("LVIII") << endl;
    cout << solution.romanToInt("MCMXCIV") << endl;

    return 0;
}
