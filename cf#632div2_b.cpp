#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++) cin >> b[i];
	vector<int> req(2);
	req[0] = n+1 ; req[1] = n+1;
	for (int i=0;i<n;i++){
		if(a[i]==1){
			req[1] = i;
			break;
		}
	}
	for (int i=0;i<n;i++){
		if (a[i]==-1){
			req[0] = i;
			break;
		}
	}
	if (n==1 && a[0]!=b[0]){
		cout << "NO" << endl; return;
	}
	for(int i=0;i<n;i++){
		int diff = b[i] - a[i];
		if (diff>0 && req[1]>=i){
			cout << "NO" << endl; return;
		}
		if (diff<0 && req[0]>=i){
			cout << "NO" << endl; return;
		}
	}
	cout << "YES" << endl;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		solve();
	}
}
