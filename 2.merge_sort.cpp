#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int *leftsub, int mid, int *rightsub, int right)
{
    int i = 0, j = 0, k = 0;
    while (i < mid && j < right)
    {
        if (leftsub[i] < rightsub[j])
        {
            arr[k++] = leftsub[i++];
        }
        else
        {
            arr[k++] = rightsub[j++];
        }
    }

    while (i < mid)
    {
        arr[k++] = leftsub[i++];
    }
    while (j < right)
    {
        arr[k++] = rightsub[j++];
    }
}

void mergeSort(int *arr, int n)
{
    if (n <= 1)
        return;

    int mid = n / 2;
    int leftsub[mid];
    int rightsub[n - mid];

    for (int i = 0; i < mid; i++)
    {
        leftsub[i] = arr[i];
    }
    for (int i = mid; i < n; i++)
    {
        rightsub[i - mid] = arr[i];
    }

    mergeSort(leftsub, mid);
    mergeSort(rightsub, n - mid);
    merge(arr, leftsub, mid, rightsub, n - mid);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}