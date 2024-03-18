#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to get the maximum element in the array
int getMax(vector<int> &arr, int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// Counting sort for negative numbers
void countSortNeg(vector<int> &arr, int n, int exp)
{
    vector<int> output(n);
    vector<int> count(19, 0); // count array for digits -9 to 9

    for (int i = 0; i < n; i++)
    {
        int place_value = (arr[i] / exp) % 10 + 9; // shifting index by 9 to make it non-negative

        count[place_value]++;
    } 

    for (int i = 1; i < 19; i++)    // the usual step of prefix sum
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        int place_value = (arr[i] / exp) % 10 + 9;
        output[count[place_value] - 1] = arr[i];
        count[(arr[i] / exp) % 10 + 9]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Radix sort for both positive and negative numbers
void radixSort(vector<int> &arr, int n)
{
    int m = getMax(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSortNeg(arr, n, exp);
}

void printArray(const vector<int> &arr)
{
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    radixSort(arr, n);
    printArray(arr);

    return 0;
}
