#include <iostream>
#include <vector>
#include <algorithm>

void countingSort(std::vector<int>& arr) {
    // Find the maximum and minimum values in the array
    int maxVal = *std::max_element(arr.begin(), arr.end());
    int minVal = *std::min_element(arr.begin(), arr.end());

    // Find the range of values
    int range = maxVal - minVal + 1;

    // Create a count array to store the frequency of each element
    std::vector<int> count(range, 0);

    // Update the count array with the frequency of each element
    for (int i = 0; i < arr.size(); ++i) {
        count[arr[i] - minVal]++;
    }

    // Update the array based on the count array
    int index = 0;
    for (int i = 0; i < range; ++i) {
        while (count[i] > 0) {
            arr[index++] = i + minVal;
            count[i]--;
        }
    }
}

int main() {
    std::vector<int> arr = {4, -2, 1, 0, -3, 3, -1, 2, 4, 2, 0};

    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }

    countingSort(arr);

    std::cout << "\nSorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }

    return 0;
}
