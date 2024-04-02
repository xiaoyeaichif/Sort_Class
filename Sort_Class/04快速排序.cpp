#include <iostream>
#include <vector>

// 快速排序函数
int Parition(std::vector<int>& arr, int low, int high) {
        // 选择第一个元素作为枢纽元素
        int pivot = arr[low];
        while (low < high)
        {
            //找到第一个小于pivot的元素
            while (low < high && arr[high] >= pivot)
            {
                high--;
            }
            arr[low] = arr[high];
            //找到第一个大于pivot的元素下标
            while (low < high && arr[low] <= pivot)
            {
                low++;
            }
            arr[high] = arr[low];
        }
        //最后low == high之后,这个空位由pivot填补
        arr[low] = pivot;
        return low;
}
void Quick_sort(std::vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        int Pivot = Parition(arr, low, high);
        Quick_sort(arr, low, Pivot - 1);
        Quick_sort(arr, Pivot + 1, high);
    }
}

int main04() {
    // 待排序的数组
    std::vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    int n = arr.size();
    // 调用快速排序函数
    Quick_sort(arr, 0, n - 1);
    // 输出排序后的结果
    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
