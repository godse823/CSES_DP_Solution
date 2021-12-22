      #include<bits/stdc++.h> 
using namespace std;
typedef long long ll; 
void solve(); 
int main() 
{ 
ios_base::sync_with_stdio(false);cin.tie(NULL); 

int n,m,k;
cin>>n>>m>>k;
int arr[n],brr[m];
for(int i=0;i<n;i++){
	cin>>arr[i];
}
for(int i=0;i<m;i++){
	cin>>brr[i];
}
sort(arr,arr+n);
sort(brr,brr+m);
int i=0,j=0,cnt=0;
while(i<n && j<m){
	if(abs(arr[i]-brr[j])<=k){
		cnt++;
		i++;
		j++;
	}
	else if(arr[i]<brr[j]){
		i++;
	}
	else{
		j++;
	}
}
cout<<cnt;
return 0; 
} 