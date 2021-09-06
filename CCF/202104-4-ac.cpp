#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1000+1;
const int ai = 100000+ 1;

int n,a[N];

long long f[N];

bool sign[ai];

vector<int> v[ai];

int main(){

    for (int i = 1; i < ai; i++)
    {
        for(int j=i*2;j<ai;j+=i){
            v[j].push_back(i);
        }
    }

    cin>>n;

    for (int i = 1; i <=n; i++)
    {
        cin>>a[i];
    }

    f[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        memset(sign,false,sizeof sign);

        for (int j = i-1; j >= 1; j--)
        {
            int d = a[i] - a[j];
            int cnt = 0;
            for(int k:v[d]){
                if (!sign[k])
                {
                    cnt++;
                    sign[k]=true;
                }
            }
            sign[d] = true;
            f[i] = (f[i]+f[j]*cnt)%MOD;
        }
        
    }
    cout<<f[n]<<endl;
    return 0;

}