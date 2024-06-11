#include <iostream>
#include <thread>
#include <vector>

class MergeSort {
public:
    void Sort(std::vector<int>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            Sort(arr, left, mid);
            Sort(arr, mid + 1, right);

            Merge(arr, left, mid, right);
        }
    }

private:
    void Merge(std::vector<int>& arr, int left, int mid, int right) {
        int i, j, k;
        int n1 = mid - left + 1;
        int n2 = right - mid;

        std::vector<int> L(n1), R(n2);

        for (i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        i = 0;
        j = 0;
        k = left;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
};

int main() {
    std::vector<int> arr(10);

    std::cout << "Введите 10 чисел: ";
    for (int i = 0; i < 10; i++) {
        std::cin >> arr[i];
    }

    MergeSort mergeSort;

    std::thread mergeSortThread([&mergeSort, &arr]() {
        mergeSort.Sort(arr, 0, arr.size() - 1);
        });

    mergeSortThread.join();

    std::cout << "Сортированный массив: ";
    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}