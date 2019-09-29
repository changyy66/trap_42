// trap_42.cpp : 定义控制台应用程序的入口点。
//
/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
|
|
|                      __
|          __         |  |__    __
|   __    |  |__    __|  |  |__|  |__
|__|__|___|__|__|__|__|__|__|__|__|__|___
Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/
#include "stdafx.h"
#include <vector>
#include <iostream>
//#include <stack>
using namespace std;

int trap(vector<int>& height) {
	if (height.size() < 2)return 0;
	vector<int> dp;
	dp.push_back(-1);
	int area = 0;
	int i = 0;
	while (i<height.size())
	{
		if (dp.size()==1 || height[dp.back()] >height[i])
		{
			dp.push_back(i++);
			continue;
		}
		int top = height[dp.back()];
		dp.pop_back();
		if (dp.back()==-1)
		{
			dp.push_back(i++);
			continue;
		}
		if (height[dp.back()] > height[i])
		{
			area += (height[i] - top)*(i - dp.back() - 1);
			dp.push_back(i++);
		}
		else
		{
			area += (height[dp.back()] - top)*(i - dp.back() - 1);
		}
	}
	return area;
}

int main()
{
	vector<int> height = { 0,1,0,3,1,0,1,3,2,1,2,1 };
	cout << trap(height);
    return 0;
}

