#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n; cin >> n;
	ll p[n] = {0};
	cin >> p[0];
	for(int i=1;i<n;i++){
		int y; cin >> y;
		p[i] = p[i-1]+y;
	}
	//for(int i=0;i<n;i++) cout << p[i] << " ";
	//cout << endl;
	map<ll,int> mp;
	mp[0] = -1;
	//bool first_zero = true;
	int L = -1; ll ans = 0;
	for(int i=0;i<n;i++){
		ll s = p[i];
		if(mp.find(s) != mp.end()){
			if (s==0 && mp[0]==-1){
				L = max(L,0);
			}
			else{
				L = max(L,mp[s]+1);
			}
		}
		mp[s] = i;
		ans+=(i-L);
		//cout << L << " " << ans << endl; 
	}
	cout << ans << endl;

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
}
