#include <iostream>
#include <vector>

// ����������
void quickSort(std::vector<int>& arr, int low, int high) {
    // ����λ����С�ڸ�λ����ʱ��������
    if (low < high) {
        // ѡ���м�Ԫ����Ϊ��ŦԪ��
        int pivot = arr[(low + high) / 2];
        int left = low;
        int right = high;

        // �����黮��Ϊ�����֣�ʹ��߲��ֵ�Ԫ��С����ŦԪ�أ��ұ߲��ֵ�Ԫ�ش�����ŦԪ��
        while (left<= right) {
            // ������ҵ���һ�����ڵ�����ŦԪ�ص�Ԫ��
            while (arr[left] < pivot) {
                ++left;
            }
            // ���ұ��ҵ���һ��С�ڵ�����ŦԪ�ص�Ԫ��
            while (arr[right] > pivot) {
                --right;
            }
            // ����ҵ��˺��ʵ�Ԫ�أ��򽻻�����
            if (left <= right) {
                std::swap(arr[left], arr[right]);
                left++;
                right--;
            }
        }

        // �ݹ���������������
        quickSort(arr, low, right);
        quickSort(arr, left, high);
    }
}

int main() {
    // �����������
    std::vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    int n = arr.size();
    // ���ÿ���������
    quickSort(arr, 0, n - 1);
    // ��������Ľ��
    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
