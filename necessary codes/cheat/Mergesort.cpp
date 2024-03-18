#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int ara1[n1];
    int ara2[n2];

    for (int i = 0; i < n1; i++)
        ara1[i] = arr[l + i];

    for (int i = 0; i < n2; i++)
        ara2[i] = arr[m + 1 + i];

    int cnt1 = 0, cnt2 = 0;
    int k = l;

    while (cnt1 < n1 && cnt2 < n2) {
        if (ara1[cnt1] <= ara2[cnt2])
            arr[k++] = ara1[cnt1++];
        else
            arr[k++] = ara2[cnt2++];
    }

    while (cnt1 < n1)
        arr[k++] = ara1[cnt1++];

    while (cnt2 < n2)
        arr[k++] = ara2[cnt2++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    cin >> n;

    int ara[n];

    for (int i = 0; i < n; i++)
        cin >> ara[i];

    mergeSort(ara, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << ara[i] << " ";
    cout << endl;

    return 0;
}
