        #include<bits/stdc++.h> 
using namespace std;
typedef long long ll; 
const int mod = 1e9+7;
int main() 
{ 
ios_base::sync_with_stdio(false);cin.tie(NULL); 
int n;
cin>>n;
vector<vector<int>>dp(n,vector<int>(n,0));
vector<vector<int>>v(n,vector<int>(n));
for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
        char x;
		cin>>x;
        v[i][j] = x=='*'?0:1;
	}
} 
    dp[n-1][n-1] = v[n-1][n-1]==0?0:1;
    for(int i=n-2;i>=0;i--){
        if(v[i][n-1]==0){
            dp[i][n-1] = 0;
        }
        else{
            dp[i][n-1] = dp[i+1][n-1];
        }
    }
    for(int i=n-2;i>=0;i--){
        if(v[n-1][i]==0){
            dp[n-1][i]=0;
        }
        else{
            dp[n-1][i] = dp[n-1][i+1];
        }
    }
    for(int i=n-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            if(v[i][j]==0){
                dp[i][j]= 0;
            }
            else{
                dp[i][j] = (dp[i+1][j]+dp[i][j+1])%mod;
            }
        }
    }
cout<<dp[0][0];
return 0; 
} 

    /*  #include<bits/stdc++.h> 
using namespace std;
typedef long long ll; 
vector<vector<int>>dp;
const int mod = 1e9+7;
int solve(int i,int j,int n,vector<vector<char>>&v){
	if(i>=n || j>=n || v[i][j]=='*'){
		return 0;
	}
	if(i==n-1 && j==n-1){
		return 1;
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	} 
return dp[i][j] = (solve(i+1,j,n,v)+solve(i,j+1,n,v))%mod;
} 
int main() 
{ 
ios_base::sync_with_stdio(false);cin.tie(NULL); 
int n;
cin>>n;
dp.resize(n,vector<int>(n,-1));
vector<vector<char>>v(n,vector<char>(n));
for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		cin>>v[i][j];
	}
} 
//vector<vector<int> dp(n,vector<int>(n));
cout<<solve(0,0,n,v);
return 0; 
} */