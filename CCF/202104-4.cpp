#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1000 + 1;
const int ai = 100000 + 1;

int n, a[N];//储存输入数据（电线杆坐标） 
long long f[N];//默认为0 
bool sign[ai];//标记每个坐标是否种树 
vector<int> v[ai];//向量数组


int main() {
	
	for (int i = 1; i < ai; i++)//在求因数 
		for (int j = 2 * i; j < ai; j += i)
			v[j].push_back(i);
//v[0] v[1] v[2] 1 v[3] 1 v[4] 1 2  v[5] 1 v[6] 1 2 3 v[7] 1 v[8] 1 2 			
	cin>>n; 
	for (int i = 1; i <= n; i++)
		cin>>a[i];
	f[1] = 1;
	for (int i = 2; i <= n; i++) {
		memset(sign, false, sizeof sign);//是否种树 
		for (int j = i - 1; j >= 1; j--) {
			int d = a[i] - a[j], cnt = 0;//d是电线杆间距  
			for (int k:v[d])//间距为d的因子赋值给k 
				if (!sign[k])//可以以此为间距种树 
					cnt++, sign[k] = true;//可能性加1 标记 
			sign[d] = true;//标记 电线杆中必须有树 
			f[i] = (f[i] + f[j] * cnt) % MOD;
		}
	}
	cout<<f[n]<<endl;
	return 0;
}

