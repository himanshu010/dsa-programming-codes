#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

// int MOD = 98765431;
#define MOD 1000000000


vector<vector<int>> multiply(vector<vector<int>> A,vector<vector<int>> B, int n){
    vector<vector<int>> c(n,vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                c[i][j]=(c[i][j]+(A[i][k]*B[k][j])%MOD)%MOD;
            }
        }
    }
    return c;

}

vector<vector<int >> pow(vector<vector<int>> v,int power, int n){
    if(power==1){
        return v;
    }
    if(power&1){
        return multiply(v,pow(v,power-1,n),n);
    }
    else{
        return multiply(pow(v,power/2,n),pow(v,power/2,n),n);
    }

}

vector<vector<int>> tmatrix(int n, int m, vector<int> cvector){
    vector<vector<int>> v(n,vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if(j==i+1){
                v[i][j]=1;
            }
            else{
                v[i][j]=0;
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        // cout<<cvector[(n-1)-i]<<endl;
        v[n-1][i]=cvector[(n-1)-i];
    }
    return v;
}

int32_t main()
{
    #ifndef ONLINE_JUDGE

    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w" , stdout);
    #endif

    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin>>n;
        
        vector<int> v,v2;
        for (int i = 0; i < n; ++i)
        {
            int temp;
            cin>>temp;
            temp=temp%MOD ;
            v.pb(temp);
        }
        for (int i = 0; i < n; ++i)
        {
            int temp;
            cin>>temp;
            temp=temp%MOD;
            v2.pb(temp);
        }

        reverse(v.begin(),v.end());
        cin>>m;

        if (m==0){
            cout<<0;
        }
        if(m<=n){
            cout<<v[m-1];
        }
        else{
            vector<vector<int>> umatrix = tmatrix(n,m,v2); 

            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    cout<<umatrix[i][j]<<" ";
                }
                cout<<"  "<<v[i] <<endl;
            }

            umatrix=pow(umatrix,m,n);

            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    cout<<umatrix[i][j]<<" ";
                }
                cout<<"  "<<v[i] <<endl;
            }



            int f[n]={0};

            for (int i = 0; i < n; ++i)
            {
               sum=sum+ (umatrix[0][i]*v[i]);
               cout<<sum<<endl;
            }
            // for (int i = 0; i < n; ++i)
            // {
            //     cout<<v[i]<<endl;
            // }
            
        }

    }
}