#include <iostream>
#include <string>
#include <limits.h>
#include <exception>

using namespace std;


int myAtoi(string str);

int main()
{
    cout << myAtoi("753") << endl;
    cout << myAtoi(" -14500") << endl;
    cout << myAtoi("-") << endl;
    cout << myAtoi("+") << endl;
    cout << myAtoi("-485+254") << endl;
    cout << myAtoi("+7777HHHHH") << endl;
    cout << myAtoi("+-2") << endl;
    cout << myAtoi("2147483648") << endl;
    cout << myAtoi("    10522545459") << endl;
    return 0;
}


int myAtoi(string str)
{
    int num = 0 ;
    int muti = 1 ;
    bool bShouldBeNum = false;

    if(str.empty())
        return 0;

    while(!str.empty())
    {
        if(str.at(0)==' ' && !bShouldBeNum)
        {
            str.erase(0,1);
        }
        else if(str.at(0)=='-' && !bShouldBeNum)
        {
            muti = -1 ;
            str.erase(0,1);
            bShouldBeNum = true;
        }
        else if(str.at(0)=='+' && !bShouldBeNum)
        {
            muti = 1 ;
            str.erase(0,1);
            bShouldBeNum = true;
        }
        else if(str.at(0)>='0' && str.at(0)<='9')
        {
            if(muti==-1 && num>INT_MAX/10)
                return INT_MIN;
            else if(muti==1 && num>INT_MAX/10)
                return INT_MAX;
            num = num*10 + (str.at(0) - '0');
            str.erase(0,1);
            bShouldBeNum = true;
        }
        else
            break;
    }

    if(muti==-1 && num*muti>0)
        return INT_MIN;
    else if(muti==1 && num*muti<0)
        return INT_MAX;

    return num*muti;

}
