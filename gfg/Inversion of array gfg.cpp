long long mergeHelper(long long *&a, long long s, long long e) {
    long long sum = 0;
    vector<long long> temp(e + 1 - s);
    long long mid = (s + e) / 2;
    long long i = s, j = mid + 1, k = 0;

    while (i <= mid and j <= e) {
        if (a[i] > a[j]) {
            sum += (mid + 1 - i);
            temp[k] = a[j];
            k++;
            j++;
        }
        else {
            temp[k] = a[i];
            i++;
            k++;
        }
    }
    while (i <= mid) {
        temp[k] = a[i];
        i++;
        k++;
    }
    while (j <= e) {
        temp[k] = a[j];
        j++;
        k++;
    }

    for (long long i = s; i <= e; ++i)
    {
        a[i] = temp[i - s];
    }
    return sum;
}
long long mergeSortTree(long long *&a, long long s, long long e) {
    if (s == e) {
        return 0;
    }


    long long mid = (s + e) / 2;
    long long left = mergeSortTree(a, s, mid);
    long long right = mergeSortTree(a, mid + 1, e);

    long long resolve = mergeHelper(a, s, e);
    return left + right + resolve;
}
long long inversionCount(long long arr[], long long N)
{
    return mergeSortTree(arr, 0, N - 1);
}