class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>res;
        for( int ast : asteroids){
            while( !res.empty() && res.back() > 0 && ast < 0 && res.back() < abs(ast)){
                res.pop_back();
            }
            if(!res.empty() && res.back() > 0 && ast < 0 && res.back() == abs(ast)){
                res.pop_back();
            }
            else if( res.empty() || res.back() <0 || ast > 0 ){
                res.push_back(ast);
            }
        }
        return res;
    }
};