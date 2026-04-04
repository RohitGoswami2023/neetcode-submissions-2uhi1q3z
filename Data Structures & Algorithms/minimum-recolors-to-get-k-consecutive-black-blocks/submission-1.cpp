class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n =  blocks.size();
        int whitecount = 0 ;
        for( int i = 0 ; i < k ;i++){
            if(blocks[i] == 'W') whitecount ++;
        }
        int ans = whitecount;
        for(int i = k ; i < n ; i++){
            if( blocks[i -k] == 'W') whitecount--;
            if( blocks[i] == 'W') whitecount++;
            ans = min(ans,whitecount);
        }
    return ans;
    }

};