bool compare(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int w, Item arr[], int n)
{
    double W = w;
    sort(arr, arr + n, compare);
    double sum = 0;
    for (int i = 0; i < n; i++)
    {

        double weight1 = arr[i].weight;
        if (W <= 0)
        {
            break;
        }
        else if (weight1 <= W)
        {
            sum += arr[i].value;
            W -= weight1;
        }
        else
        {
            sum += arr[i].value * (W / weight1);
            break;
        }
    }
    return sum;
}