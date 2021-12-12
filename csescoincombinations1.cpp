      #include<bits/stdc++.h> 
using namespace std;
typedef long long ll; 
const unsigned int mod = 1000000007;
unordered_map<int,int>mp;
int solve(int n,int  x,int arr[],int currsum){
	if(currsum>x){
		return 0;
	}
	if(currsum==x){
		return 1;
	}
	if(mp.find(currsum)!=mp.end()){
		return mp[currsum];
	}
	int ways =0;
	for(int i=0;i<n;i++){
		ways = ((ways%mod)+(solve(n,x,arr,currsum+arr[i])%mod))%mod;
	}
	return mp[currsum] = ways;
}
int main() 
{ 
ios_base::sync_with_stdio(false);cin.tie(NULL); 
	int n,x;
	cin>>n>>x;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	//int ans = solve(n,x,arr,0);
	//cout<<ans<<endl;

	std::vector<int> dp(x+1,0);
	dp[0] = 1;/// 0 sum sathi kahich input ny ghetla
	for(int i=1;i<=x;i++){
		for(int j = 0;j<n;j++){
			if(arr[j]<=i){
				dp[i] = (dp[i] + dp[i-arr[j]])%mod;
			}
			else{
				dp[i] = dp[i-1];
			}
		}
	}
	cout<<dp[x]<<endl;
return 0; 
}