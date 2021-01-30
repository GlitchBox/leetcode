#define WHITE 0
#define GREY 1
#define BLACK 2

class Solution {
public:
    int visited[100010];
    
    bool ifCycle(int root, int numCourses, vector<int>graph[]){
        
        bool ret = false;
        
        visited[root] = GREY;
        for(int i=0;i<graph[root].size();i++){
            
            int neighbor = graph[root][i];
            if(visited[neighbor] == GREY)//back edge, cycle
                return true;
            else if(visited[neighbor] == WHITE)
                ret |= ifCycle(neighbor, numCourses, graph);
        }
        visited[root] = BLACK;
        
        return ret;
        
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        //First, let's create an adjacency list
        vector<int> graph[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        memset(visited, 0, sizeof(visited));
        
        while(1){
            int root = -1;
            for(int i=0;i<numCourses;i++){
                if(!visited[i]){
                    root = i;
                    break;
                }
            }
            if(root == -1)
                break;
            if(ifCycle(root, numCourses, graph))
                return false;
        }
        
        return true;
    }
};