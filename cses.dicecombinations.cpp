      #include<bits/stdc++.h> 
using namespace std;
typedef long long ll; 
const unsigned int mod = 1000000007;
unordered_map<int,int>mp;
int solve(int n,int currsum){
	if(currsum>n){
		return 0;
	}
	if(currsum==n){
		return 1;
	}
	if(mp.find(currsum)!=mp.end()){
		return mp[currsum];
	}
	
	int f = solve(n,currsum+1);
	int s = solve(n,currsum+2);
	int t = solve(n,currsum+3);
	int fo = solve(n,currsum+4);
	int fi = solve(n,currsum+5);
	int si = solve(n,currsum+6);
	mp[currsum] = (((((((((f+s)%mod)+t)%mod)+fo)%mod)+fi)%mod)+si)%mod;
return (((((((((f+s)%mod)+t)%mod)+fo)%mod)+fi)%mod)+si)%mod;
}
int main() 
{ 
ios_base::sync_with_stdio(false);cin.tie(NULL); 
	int n;
	cin>>n;
	int ans = solve(n,0);
	cout<<ans<<endl;
return 0; 
}
/*

vector<int> dp(n+1,0);
dp[0]= dp[1] = 1;
for(int i=2;i<=n;i++){
	for(int j=1;j<=6;j++){
		if(i>j){
		dp[i] = (dp[i]%mod + dp[i-j]%mod)%mod;
	}
	}
}
return dp[n];

*/