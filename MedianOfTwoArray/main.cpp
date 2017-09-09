#include <iostream>
#include <vector>

using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

int main()
{
    int num1[] = {1,2,3,4};
    int num2[] = {};
    vector<int> a(num1,num1+sizeof(num1)/sizeof(int));
    vector<int> b(num2,num2+sizeof(num2)/sizeof(int));
    cout << findMedianSortedArrays(a,b) << endl;
    return 0;
}


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    vector<int> mergeNums;
    vector<int> longVec = nums1.size()>nums2.size()? nums1 : nums2 ;
    vector<int> shortVec = nums1.size()>nums2.size()? nums2 : nums1 ;

    int middle = (nums1.size() + nums2.size())/2 ;
    bool isOdd = (nums1.size() + nums2.size())%2 != 0 ;

    int itrShort = 0 ;
    for(int i=0;i<longVec.size();i++)
    {
        while(itrShort<shortVec.size())
        {
            if(longVec[i]>shortVec[itrShort])
            {
                mergeNums.push_back(shortVec[itrShort]);
                itrShort++;
            }
            else
                break;

            if(mergeNums.size()>middle)
                return isOdd? mergeNums[middle] : 0.5*(mergeNums[middle]+mergeNums[middle-1]) ;
        }
        mergeNums.push_back(longVec[i]);
        if(mergeNums.size()>middle)
            return isOdd? mergeNums[middle] : 0.5*(mergeNums[middle]+mergeNums[middle-1]) ;
    }

    mergeNums.push_back(shortVec[0]);
    return isOdd? mergeNums[middle] : 0.5*(mergeNums[middle]+mergeNums[middle-1]) ;
}
