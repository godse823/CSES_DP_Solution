      #include<bits/stdc++.h> 
using namespace std;
typedef long long int ll; 
int main() 
{ 
ios_base::sync_with_stdio(false);cin.tie(NULL); 
int n,m;
cin>>n>>m;
int x;
multiset<int,greater<int>>s1;
for(int i=0;i<n;i++){
	cin>>x;
	s1.insert(x);
}
for(int i=0;i<m;i++){
	cin>>x;
	auto it = s1.lower_bound(x);
	if(it==s1.end()){
		cout<<-1<<endl;
	}
	else{
		cout<<*it<<endl;
		s1.erase(it);
	}
}
return 0; 
}