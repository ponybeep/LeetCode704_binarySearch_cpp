#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
//��Ŀ������
//����һ��n��Ԫ���������������nums��һ��Ŀ��ֵtarget��дһ����������nums�е�target,���Ŀ��ֵ���ڷ����±꣬���򷵻�-1.
//����Լ���nums������Ԫ���ǲ��ظ��ġ�
//n����[1,10000]֮��
//nums��ÿ��Ԫ�ض���[-9999,9999]֮��

//����˼·һ��
//������c++�е�STL�ͺ��˰���bool ret= binary_search(nums.begin(),nums.end(),target)�ж��Ƿ����Ŀ��ֵ
//���±�ans, vector<int>::iteratot it=find(nums.begin(),nums.end(),target),��ans=it-nums.begin();

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
		nums.push_back(i*2+1);	//��Ȼ�ҽ�nums����Ϊһ��int���������������1��3��5������39��Щ����
	}
	Solution1 solution;
	cout << "��������û��9�أ�(û�о����-1��������±꣩��" << solution.BinarySearch(nums,9) << endl;
	cout << "��������û��10�أ���û�о����-1���о�����±꣩��" << solution.BinarySearch(nums, 10) << endl;
	cout << "��������û��41�أ���û�о����-1���о�����±꣩��" << solution.BinarySearch(nums, 41) << endl;

}

//����˼·����
//ʹ��while�ж���Nmin<=Nmax(�������±� <=�����±�)������С�����޷�Χ����Nmin=Ntemp+1;Nmax=Ntemp-1;

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
		nums.push_back(i * 2 + 1);	//��Ȼ�ҽ�nums����Ϊһ��int���������������1��3��5������39��Щ����
	}
	Solution2 solution;
	cout << "��������û��9�أ�(û�о����-1��������±꣩��" << solution.binarySearch(nums, 9) << endl;
	cout << "��������û��10�أ���û�о����-1���о�����±꣩��" << solution.binarySearch(nums, 10) << endl;
	cout << "��������û��41�أ���û�о����-1���о�����±꣩��" << solution.binarySearch(nums, 41) << endl;

}


int main()
{
	test01();
	cout << "---------�������ַ���֮�仪���ķָ���-------------------" << endl;
	test02();




	system("pause");
	return 0;
}





