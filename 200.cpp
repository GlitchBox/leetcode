class Solution {
public:
    int visited[90010];
    
    void bfs(int root, vector<vector<char>>& grid){
        
        int m = grid.size(), n = grid[0].size();
        
        visited[root] = 1;
        queue<int>q;
        q.push(root);
        
        while(!q.empty()){
            
            int front = q.front();
            q.pop();
            
            //if the current node is not at the rightmost edge and the node on the right is not water
            if( (front%n)<n-1 && !visited[front+1]){
                visited[front+1] = 1;
                q.push(front+1);
            }
            
            //if the current node is not at the bottomost row and the node on the bottom is not water
            if( (front/n)<m-1 && !visited[front+n]){
                visited[front+n] = 1;
                q.push(front+n);
            }
            
            //if the current node is not at the leftmost edge and the node on the left is not water
            if( (front%n)>0 && !visited[front-1]){
                visited[front-1] = 1;
                q.push(front-1);
            }
            
            //if the current node is not at the topmost row and the node on the top is not water
            if( (front/n)>0 && !visited[front-n]){
                visited[front-n] = 1;
                q.push(front-n);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        int nodes = m*n;
        memset(visited, 0, nodes);
        
        for(int rowNo = 0; rowNo<m; rowNo++){
            for(int colNo = 0; colNo<n; colNo++){
                
                if(grid[rowNo][colNo] == '0')
                    visited[rowNo*n+colNo] = 1; //making the water visited
            }
        }
        
        int islands = 0;
        int prevRoot = -1;
        
        while(1){
            
            int root = -1;
            for(int i=prevRoot+1;i<nodes;i++){
                if(!visited[i]){
                    root = i;
                    break;
                }
            }
            
            if(root==-1)
                break;
            
            prevRoot = root;
            bfs(root, grid);
            islands++;
            
        }
        
        return islands;
    }
};