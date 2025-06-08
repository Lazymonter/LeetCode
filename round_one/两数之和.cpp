//给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
//你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。
//暴力循环法，时间复杂度O(n^2),空间复杂度O(1)

#include<iostream>
#include<string>
#include<vector>
#include <map>

using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
  vector<int> vec;
	for(int i = 0;i < nums.size();i++)
	{
		for(int j = i + 1;j < nums.size();j++)
		{
			if(nums[j] == target - nums[i])
			{
                vec.push_back(i);
				vec.push_back(j);
			}
		}
	}
	return vec; 
}
//使用hashmap
vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> result;
        for(int i = 0;i < nums.size();i++)
        {
            int sub = target - nums[i];
            if(m.count(nums[i]) != 0)
            {
                result.push_back(m[nums[i]]);
                result.push_back(i);
                break;
            }
            m[sub] = i;
            
        }
        return result;
        
}
