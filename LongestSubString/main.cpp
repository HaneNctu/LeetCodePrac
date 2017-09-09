#include <iostream>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s);

int main()
{
    cout << lengthOfLongestSubstring("abcabcbb") << endl;
    cout << lengthOfLongestSubstring("bbbb") << endl;
    cout << lengthOfLongestSubstring("pwwkew") << endl;
    return 0;
}

int lengthOfLongestSubstring(string s)
{
    int longestLeng = 0 ;
    int leng = 0 ;
    string charSet = "" ;
    for(int i=0;i<s.length();i++)
    {
        for(int j=0;j<charSet.length();j++)
        {
            if(s[i]==charSet[j])
            {
                if(longestLeng<leng)
                    longestLeng = leng;
                charSet.clear();
                leng = 0;
                break;
            }
        }
    }
    return 0 ;
}
