		
//      time complexity O(n*n*log(n)
//      time complexity O(n*m)
    
    int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
    
    bool isValid(int i,int j,int n,int m){
        	    if(i>=0 and j>=0 and  i<n and j<m) return true;
         	    return false;
    }
    
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here    
          int n=grid.size();
          int m=grid[0].size();
           
       vector<vector<int>>vis(n,vector<int>(m,0));
       priority_queue< pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> ,
       greater<pair<int,pair<int,int>>>>pq;
            pq.push({grid[0][0],{0,0}});
            vis[0][0]=1;
            while(!pq.empty()){
                int curr=pq.top().first;
                int i=pq.top().second.first;
                int j=pq.top().second.second;
                pq.pop();
                for(int k=0;k<4;k++){
                        
                      int x=i+dx[k];
                      int y=j+dy[k];
                      if(isValid(x,y,n,m)==1){
                         if(vis[x][y]==0){
                             vis[x][y]=1;
                           if(x==n-1 and y==m-1) return curr+grid[x][y];
                           pq.push({curr+grid[x][y],{x,y}});
                           
                            }
                                 
                      }
                }
        }
    return 0;
    }
