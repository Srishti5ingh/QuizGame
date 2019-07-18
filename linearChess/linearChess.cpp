#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=5e5+10;
int t,n;
char s[maxn];

inline bool run(bool moved){
	int l=-1,r=-1;
	for(int i=n;i;--i)
		if(s[i]=='W'){
			l=i;
			break;
		}
	if(l==-1)
		return false;
	for(int i=1;i<=n;++i)
		if(s[i]=='B'){
			r=i;
			break;
		}
	if(r==-1)
		return true;
	ll val=moved;
	if(moved)
		goto xxx;
	while(true){
		if(r-l<=2)
			break;
		++l;
xxx:
		if(r-l<=2)
			break;
		--r;
	}
	for(int i=l,p=l;i;--i)
		if(s[i]=='W'){
			val+=p-i;
			--p;
		}
	for(int i=r,p=r;i<=n;++i)
		if(s[i]=='B'){
			val-=i-p;
			++p;
		}
	return val>0;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%s",s+1);
		n=strlen(s+1);
		int l,r;
		bool ans;
		for(int i=n;i;--i)
			if(s[i]=='W'){
				l=i;
				break;
			}
		for(int i=1;i<=n;++i)
			if(s[i]=='B'){
				r=i;
				break;
			}
		if(r-l==1)
			if(r==n||s[r+1]=='.'){
				s[r]='W';
				s[l]='.';
				ans=run(true);
			}
			else if(l>1&&s[l-1]=='W')
				ans=run(false);
			else if(l>2&&s[l-2]=='W'){
				ans=false;
				s[l-2]='.';
				s[l-1]='W';
				ans|=run(true);
				s[l-2]='W';
				s[l-1]='.';
				s[l]='.';
				s[l+2]='.';
				ans|=run(false);
			}
			else{
				ans=false;
				s[l]='.';
				ans|=run(false);
				s[l+2]='.';
				ans|=run(false);
			}
		else
			ans=run(false);
		puts(ans?"W":"B");
	}
	return 0;
}