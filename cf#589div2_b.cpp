#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
	int h,w;
	cin >> h >> w;
	int rows[h],cols[w];
	for (int i=0;i<h;i++){
		cin >> rows[i];
	}
	for (int i=0;i<w;i++){
		cin >> cols[i];
	}
	int grid[h][w];
	memset(grid,0,sizeof(int)*h*w);
	ll count = 0;
	for (int i=0;i<h;i++){
		for (int j=0;j<w;j++){
			if (j>(rows[i]) && i>(cols[j])){
				count++;
			}
			else if ((j<rows[i] && i==cols[j]) || (i<cols[j] && j==rows[i])){
				cout << "0" << endl;
				return 0;
			}
		}
	}
    ll ans = 1;
	while(count--){
		ans = (ans*2)%mod;
	}
	cout << ans << endl;
}
