#include<bits/stdc++.h>

using namespace std;

int n,k,ans=0,vis[2001]={},match[2001]={};//n:存點數量 k:存邊數量 ans:存匹配數 vis[]:存是否被遍歷過 match[]:存匹配的點
vector<int> gra[2001];//儲存圖
int dfs(int pos){
	if(vis[pos])return 0;//已遍歷不做事
	vis[pos]=1;
	for(auto i:gra[pos]){
		if(vis[i])continue;//已遍歷不做事
		vis[i]=1;
		if(match[i]==0||dfs(match[i])){//遞迴式找增廣路徑
			match[pos]=i;
			match[i]=pos;
			return 1;//找到回傳
		}
	}
	return 0;
}
main(){
	for(int i=1;i<=n*2;i++){
		for(int j=1;j<=n*2;j++)vis[j]=0;
		if(match[i]==0)ans+=dfs(i);
	}
   
}