#include <iostream>
#include <vector>

// ����������
int Parition(std::vector<int>& arr, int low, int high) {
        // ѡ���һ��Ԫ����Ϊ��ŦԪ��
        int pivot = arr[low];
        while (low < high)
        {
            //�ҵ���һ��С��pivot��Ԫ��
            while (low < high && arr[high] >= pivot)
            {
                high--;
            }
            arr[low] = arr[high];
            //�ҵ���һ������pivot��Ԫ���±�
            while (low < high && arr[low] <= pivot)
            {
                low++;
            }
            arr[high] = arr[low];
        }
        //���low == high֮��,�����λ��pivot�
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
    // �����������
    std::vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    int n = arr.size();
    // ���ÿ���������
    Quick_sort(arr, 0, n - 1);
    // ��������Ľ��
    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
