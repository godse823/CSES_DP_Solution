      #include<bits/stdc++.h> 
using namespace std;
typedef long long ll; 

int main() 
{ 
ios_base::sync_with_stdio(false);cin.tie(NULL); 

 int n,x;
 cin>>n>>x;
 int arr[n];
 for(int i=0;i<n;i++){
 	cin>>arr[i];
 }
 sort(arr,arr+n);
 int low =0,high = n-1,cnt=0;
 while(low<high){
 	if(arr[low]+arr[high]<=x){
 		cnt++;
 		low++;
 		high--;
 	}
 	else{
 		cnt++;
 		high--;
 	}
 }
 if(low==high){
 	cnt++;
 }
 cout<<cnt;
return 0; 
}