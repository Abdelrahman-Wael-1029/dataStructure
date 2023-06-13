#include<iostream>
#include<cstring>

namespace sortlib {
    /*
        * Bubble Sort
        * best case: O(n)
        * worst case: O(n^2)
        * average case: O(n^2)
        * Space Complexity: O(1)
        * Stable: Yes
     */
    template<typename T>
    void bubbleSort(T arr[], int n) {
        for (int i = 0; i < n; ++i) {
            bool swapped = false;
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped)
                break;
        }
    }
    /*
     * Selection Sort
     * best case: O(n^2)
     * worst case: O(n^2)
     * average case: O(n^2)
     * Space Complexity: O(1)
     * Stable: No
     */

    template<typename T>
    void selectionSort(T arr[], int n) {
        for (int i = 0; i < n; ++i) {
            int ind = i;
            for (int j = i; j < n; ++j) {
                if (arr[j] < arr[ind])
                    ind = j;
            }
            std::swap(arr[ind], arr[i]);
        }
    }

    /*
     * Insertion Sort
     * best case: O(n)
     * worst case: O(n^2)
     * average case: O(n^2)
     *  Space Complexity: O(1)
     *  Stable: Yes
     */

    template<typename T>
    void insertionSort(T arr[], int n) {
        for (int i = 1; i < n; ++i) {
            T temp = arr[i];
            int ind = i - 1;
            while (ind >= 0 && temp < arr[ind]) {
                arr[ind + 1] = arr[ind];
                --ind;
            }
            arr[ind + 1] = temp;
        }
    }



    template<typename T>
    void merge(T arr[], int l, int r, int m) {
        int sizL = m - l + 1, sizR = r - m;
        T arrL[sizL], arrR[sizR];
        for (int i = l, j = 0; j < sizL; ++i, ++j) {
            arrL[j] = arr[i];
        }
        for (int i = m + 1, j = 0; j < sizR; ++i, ++j) {
            arrR[j] = arr[i];
        }

        int L = 0, R = 0;
        while (L < sizL && R < sizR) {
            if (arrL[L] <= arrR[R]) {
                arr[l] = arrL[L];
                ++l;
                ++L;
            } else {
                arr[l] = arrR[R];
                ++R;
                ++l;
            }
        }
        while (L < sizL) {
            arr[l] = arrL[L];
            ++l;
            ++L;
        }
        while (R < sizR) {
            arr[l] = arrR[R];
            ++R;
            ++l;
        }
    }
    /*
     * Merge Sort
     * best case: O(nlogn)
     * worst case: O(nlogn)
     * average case: O(nlogn)
     * Space Complexity: O(n)
     * Stable: Yes
     */

    template<typename T>
    void mergeSort(T arr[], int l, int r) {
        if (l < r) {
            int m = (r - l) / 2 + l;
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);
            merge(arr, l, r, m);
        }
    }

    template<typename T>
    int partition(T arr[], int l, int r) {
        int i = l, j = l + 1;
        for (; j <= r; ++j) {
            if (arr[j] < arr[l]) {
                ++i;
                std::swap(arr[j], arr[i]);
            }
        }
        std::swap(arr[i], arr[l]);

        return i;
    }
    /*
     * Quick Sort
     * best case: O(nlogn)
     * worst case: O(n^2)
     * average case: O(nlogn)
     * Space Complexity: O(1)
     * Stable: No
     */
    template<typename T>
    void quickSort(T arr[], int l, int r) {
        if (l < r) {
            int pivotIndex = partition(arr, l, r);
            quickSort(arr, l, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, r);
        }
    }

    template<typename T>
    void shellSort(T arr[], int n) {
        for (int gap = n; gap; gap /= 2) {
            for (int i = gap; i < n; ++i) {
                T temp = arr[i];
                int ind = i - gap;
                while (ind >= 0 && temp < arr[ind]) {
                    arr[ind + gap] = arr[ind];
                    ind -= gap;
                }
                arr[ind + gap] = temp;
            }
        }
    }

    /*
     * Count Sort
     * best case: O(n + k)
     * worst case: O(n + k)
     * average case: O(n + k)
     * Space Complexity: O(k)
     * Stable: Yes
     */

    void countSort(int arr[], int n) {
        int mx = *std::max_element(arr, arr + n);
        int cot[mx + 1];
        memset(cot, 0, sizeof cot);
        for (int i = 0; i < n; ++i) {
            cot[arr[i]]++;
        }
        for (int i = 1; i <= mx; ++i) {
            cot[i] += cot[i - 1];
        }

        int output[n];
        for (int i = 0; i < n; ++i) {
            output[cot[arr[i]] - 1] = arr[i];
            --cot[arr[i]];
        }

        for (int i = 0; i < n; ++i) {
            arr[i] = output[i];
        }
    }
}


