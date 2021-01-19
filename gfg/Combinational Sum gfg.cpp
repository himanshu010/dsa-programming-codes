vector<vector<int>> final_ans;

void findSum(vector<int> &a, int sum, int b, int n, int index, vector<int> ans) {
    if (sum == b) {
        final_ans.push_back(ans);
        return;
    }

    for (int i = index; i < n ; i++) {
        if (sum + a[i] <= b) {
            ans.push_back(a[i]);
            findSum(a, sum + a[i], b, n, i, ans);
            ans.pop_back();
        }
    }
}


vector<vector<int> > combinationSum(vector<int> &A, int B) {
    final_ans.clear();
    vector<int> ans;
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    findSum(A, 0, B, A.size(), 0, ans);
    return final_ans;
}