      #include<bits/stdc++.h> 
using namespace std;
typedef long long ll; 
const int mod = 1e9+7;
std::vector<vector<int> > dp;
int solve(int n,int x,int arr[]){
	if(x==0)return dp[n][x]  =1;
	if(x<0)return dp[n][x] = 0;
	if(x>=1 && n<=0)return dp[n][x] = 0;
	if(dp[n][x]!=-1){
		return dp[n][x];
	}
	if(arr[n-1]<=x){
		return  dp[n][x]= (solve(n-1,x,arr)+solve(n,x-arr[n-1],arr))%mod;
	}
	else{
		return  dp[n][x]= solve(n-1,x,arr);
	
	}
} 
int main() 
{ 
ios_base::sync_with_stdio(false);cin.tie(NULL); 
int n,x;
	cin>>n>>x;
	dp.clear();
	//dp.resize(n+1,vector<int>(x+1,-1));
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
// cout<<solve(n,x,arr)<<endl;
	dp.resize(n+1,vector<int>(x+1,-1));
	for(int i=0;i<n+1;i++){
		for(int j = 0;j<x+1;j++){
			if(i==0)dp[i][j] =0;
			if(j==0)dp[i][j] = 1;
	
		}
	}
	for(int i=1;i<n+1;i++){
		for(int j = 1;j<x+1;j++){
			if(arr[i-1]<=j){
				dp[i][j] = (dp[i-1][j] + dp[i][j-arr[i-1]])%mod;
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	cout<<dp[n][x];
return 0; 
} 
void solve() 
{ 
} 
