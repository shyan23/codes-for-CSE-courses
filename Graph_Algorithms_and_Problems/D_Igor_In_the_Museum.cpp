    #include<bits/stdc++.h>
     
    using namespace std;
     
    char c[1001][1001]={};
    int vis[1001][1001]={};
    int p[100001]={};
    int n,m,k,x,y,ans,i;
    void visit(int x,int y)
    {
     
    	if(x==0||y==0||x==n+1||y==m+1) return;
		//cout << i << endl;
    	if(c[x][y]=='*') 
		{
			ans++; 
			return;
		}
    	if(vis[x][y] !=0) return;
    	vis[x][y]=i;
    	visit(x+1,y);
    	visit(x,y+1);
    	visit(x-1,y);
    	visit(x,y-1);
    	return;
    }
    int main()
    {
    	cin>>n>>m>>k;
    	for(i=1;i<=n;i++)
    	{
    		for(int j=1;j<=m;j++)
    		{
    			cin>>c[i][j];
    		}
    	}
    	for(i=1;i<=k;i++)
    	{
    		cin>>x>>y;
    		ans=0;
    		if(!vis[x][y]) visit(x,y);
    		else ans=p[vis[x][y]];
    		p[i]=ans;
    		cout<<ans<<endl;
    	}
    	return 0;
    }