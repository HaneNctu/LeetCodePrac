#include <iostream>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s);

int main()
{
    cout << lengthOfLongestSubstring("abcabcbb") << endl;
    cout << lengthOfLongestSubstring("bbbb") << endl;
    cout << lengthOfLongestSubstring("pwwkewa") << endl;
    return 0;
}

int lengthOfLongestSubstring(string s)
{
    int longestLeng = 0 ;
    int leng = 0 ;
    string charSet = "" ;
    for(int i=0;i<s.length();i++)
    {
        int tPos=i;
        while(charSet.find(s[tPos])==string::npos && tPos<s.length())
        {
            charSet.push_back(s[tPos]);
            tPos++;
            leng++;
        }
        charSet.clear();
        longestLeng = leng>longestLeng ? leng : longestLeng ;
        leng = 0 ;
    }
    return longestLeng ;
}
