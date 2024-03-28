#include<iostream>
#include<vector>
using namespace std;

void bubble_sort1(vector<int>& nums)
{
	int size = nums.size();
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (nums[j] > nums[j + 1])
			{
				swap(nums[j], nums[j + 1]);
			}
		}
	}
}

//效率更高的代码
void bubble_sort(vector<int>& nums)
{
	int size = nums.size();
	bool flag = true;
	for (int i = 0; i < size - 1 && flag; i++)
	{
		flag = false;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (nums[j] > nums[j + 1])
			{
				swap(nums[j], nums[j + 1]);
				flag = true;
			}
		}
	}
}



int main01()
{
	vector<int>nums = { 10,1,2,3,5,1,0,5,4,0,50,3,0,40,6,0 };
	cout << "排序前:";
	for (int num : nums)
	{
		cout << num << ' ';
	}
	cout << endl;
	bubble_sort(nums);
	cout << "排序后:";
	for (int num : nums)
	{
		cout << num << ' ';
	}
	cout << endl;
	return 0;
}