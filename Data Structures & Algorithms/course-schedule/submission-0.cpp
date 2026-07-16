class Solution {
private:
    bool Cycle( int src , vector<vector<int>> & graph , vector<bool>& visited , vector<int>&path){
        visited[src] = true;
        path[src] = 1;
        for( int neig : graph[src] ){
            if(!visited[neig]){
                if(Cycle( neig , graph , visited , path))
                return true;
            }
            else if (path[neig]) return true;
        }
        path[src] =0;
        return false;
    }

public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        for ( auto & it : prerequisites){
            int course = it[0];
            int pre = it[1];
            graph[pre].push_back(course);
        }
        vector<bool>visited( numCourses , false);
        vector<int>path(numCourses , false);
        for (int i = 0  ; i < numCourses  ; i++){
            if(!visited[i]){
              if(Cycle(i , graph ,visited , path )) return false;
            }
            
        }   
        return true;
    }
};
