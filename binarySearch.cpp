#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
//题目描述：
//给定一个n各元素有序的整型数组nums和一个目标值target，写一个函数搜索nums中的target,如果目标值存在返回下标，否则返回-1.
//你可以假设nums中所有元素是不重复的。
//n将在[1,10000]之间
//nums的每个元素都在[-9999,9999]之间

//解题思路一：
//就利用c++中的STL就好了啊，bool ret= binary_search(nums.begin(),nums.end(),target)判断是否存在目标值
//设下标ans, vector<int>::iteratot it=find(nums.begin(),nums.end(),target),则ans=it-nums.begin();

class Solution1
{
public:
	int BinarySearch(vector<int>& nums, int target)
	{
		bool ret = binary_search(nums.begin(), nums.end(), target);
		if (ret)
		{
			vector<int>::iterator it = find(nums.begin(), nums.end(), target);
			int ans = it - nums.begin();
			return ans;
		}
		else
		{
			return -1;
		}
	}
};

void test01()
{
	vector<int> nums;
	for (int i = 0; i < 20; i++)
	{
		nums.push_back(i*2+1);	//显然我将nums定义为一个int型数组容器，存放1、3、5、、、39这些奇数
	}
	Solution1 solution;
	cout << "数组中有没有9呢？(没有就输出-1，有输出下标）：" << solution.BinarySearch(nums,9) << endl;
	cout << "数组中有没有10呢？（没有就输出-1，有就输出下标）：" << solution.BinarySearch(nums, 10) << endl;
	cout << "数组中有没有41呢？（没有就输出-1，有就输出下标）：" << solution.BinarySearch(nums, 41) << endl;

}

//解题思路二：
//使用while判断若Nmin<=Nmax(即下限下标 <=上限下标)，则缩小上下限范围，即Nmin=Ntemp+1;Nmax=Ntemp-1;

class Solution2
{
public:
	int binarySearch(vector<int>& nums, int target)
	{
		int Nmin = 0;
		int Nmax = nums.size() - 1;
		int Ntemp;
		while (Nmin <= Nmax)
		{
			Ntemp = (Nmax - Nmin) / 2 + Nmin;
			if (nums[Ntemp] == target)
			{
				return Ntemp;
			}
			else if (nums[Ntemp] < target)
			{
				Nmin = Ntemp + 1;
			}
			else
			{
				Nmax = Ntemp - 1;
			}
		}
		return -1;
	}
};

void test02()
{
	vector<int> nums;
	for (int i = 0; i < 20; i++)
	{
		nums.push_back(i * 2 + 1);	//显然我将nums定义为一个int型数组容器，存放1、3、5、、、39这些奇数
	}
	Solution2 solution;
	cout << "数组中有没有9呢？(没有就输出-1，有输出下标）：" << solution.binarySearch(nums, 9) << endl;
	cout << "数组中有没有10呢？（没有就输出-1，有就输出下标）：" << solution.binarySearch(nums, 10) << endl;
	cout << "数组中有没有41呢？（没有就输出-1，有就输出下标）：" << solution.binarySearch(nums, 41) << endl;

}


int main()
{
	test01();
	cout << "---------这是两种方法之间华丽的分割线-------------------" << endl;
	test02();




	system("pause");
	return 0;
}





