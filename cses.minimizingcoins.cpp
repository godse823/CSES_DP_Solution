      #include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int mod = 1e9+7; 

int main() 
{ 
ios_base::sync_with_stdio(false);cin.tie(NULL); 

int n,x;
cin>>n>>x;
vector<int>v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	vector<int>dp(x+1,INT_MAX);
    dp[0] =0;//minimum way
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(v[j]>i)continue;
            dp[i] = min(dp[i],1+dp[i-v[j]])%mod;        
        }
    }
    if(dp[x]==INT_MAX || dp[x]<0){
    	cout<<-1<<endl;
    }
    else{
    	cout<<dp[x]<<endl;
    }
return 0; 
}