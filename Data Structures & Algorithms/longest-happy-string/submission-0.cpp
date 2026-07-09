class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair < int , char >> pq;
        if(a > 0) pq.push({a , 'a'});
        if(b > 0) pq.push({b , 'b'});
        if(c > 0) pq.push({c , 'c'});
        string result = "";
        while( !pq.empty()){
            int currCh= pq.top().second;
            char currCount = pq.top().first;
            pq.pop();
            if(  result.length() >= 2 &&result[result.length() - 1] == currCh && result[result.length() - 2 ] ==currCh){
                if( pq.empty()) break;
            char  nextChr = pq.top().second;
            int nextCount = pq.top().first;
            pq.pop();
            result.push_back(nextChr);
            nextCount--;
            if(nextCount > 0) pq.push( {nextCount , nextChr});

            }
            else {
                result.push_back(currCh);
                currCount--;
            }
            if(currCount > 0) pq.push({currCount , currCh});
        }
        return result;
    }
};