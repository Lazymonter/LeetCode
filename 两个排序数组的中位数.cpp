//给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。
//请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 。
#include<iostream>
#include<string>
#include<vector>

using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {


	int length1 = nums1.size();
	int length2 = nums2.size();
	int totallength = length1 + length2;
	int flag = 0;//标记位奇数为1偶数为0
	int mid = 0;
	vector<int> vec;
	double midnum = 0;
	if(totallength % 2 == 1)
	{
		flag = 1;
		mid = (totallength + 1) / 2; 
	}
	else
	{
		mid = totallength / 2;
	}
	int j = 0,k = 0;
	for(int i = 0;i <= totallength;i++)//防止中位数即为尾数时出错其实此处循环终止条件可为空(后面有break)
	{
		if(j < length1 && k < length2)
		{
			if(nums1[j] < nums2[k])
			{
				vec.push_back(nums1[j]);
				j++;
			}
			else
			{
				vec.push_back(nums2[k]);
				k++;
			}
		}
		else
		{//此处可用else if
			if(j == length1 && k < length2)
			{
				vec.push_back(nums2[k]);
				k++;
			}
			if(k == length2 && j < length1)
			{
				vec.push_back(nums1[j]);
				j++;
			}
		}
		if(i == mid)
		{
			if(flag == 1)
			{
				midnum = vec[i - 1];
			}
			else{
				midnum = (vec[i] + vec[i - 1]) / 2.0;
			}
			break;
		}
	}
	return midnum;


}
