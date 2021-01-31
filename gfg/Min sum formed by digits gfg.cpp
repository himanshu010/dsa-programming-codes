long long int minSum(int arr[], int n)
{
    sort(arr, arr + n);
    long long int a = 0, b = 0;

    for (int i = 0; i < n; i++) {
        if (i & 1) {
            b *= 10;
            b += arr[i];
        }
        else {
            a *= 10;
            a += arr[i];
        }
    }

    return a + b;
}