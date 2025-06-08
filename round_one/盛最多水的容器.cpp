#include<iostream>
#include<string>
#include <vector>

using namespace std;
//暴力法
int maxArea(vector<int>& height) {
	int max = 0;
	for(int i = 0;i < height.size();i++)
	{
		for(int j = i + 1;j < height.size();j++)
		{
			int heighttemp = height[i] <= height[j] ? height[i] : height[j];
			int areatemp = heighttemp * (j - i);
			max = max >= areatemp ? max : areatemp;
		}
	}
	return max;        
}

//双指针法
 int maxArea(vector<int>& height) {
     int max = 0;
     int left = 0,right = height.size() - 1;
     while(left < right)
     {
     	int h = height[left] <= height[right] ? height[left] : height[right];
     	int area = h * (right - left);
     	max = max >= area ? max : area;
     	if(height[left] < height[right])
     	{
     		left++;
     	} 
     	else
     		right--;
     } 
     return max;  
}

int main(){
    vector<int> nums = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(nums) << endl;
    return 0;
}

