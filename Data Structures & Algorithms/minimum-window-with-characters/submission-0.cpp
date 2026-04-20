class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        unordered_map<char,int>target;
        unordered_map<char,int>window;
        for( char c : t ) target[c]++;
        int required  = target.size();
        int formed = 0 , left = 0 , right = 0 ;
        int minLen = INT_MAX , startIdx = 0 ;
        while(right < s.size()){
            char c = s[right];
            window[c]++;
            if(target.count(c) && window[c] == target[c]){
                formed++;
            }
            while(left <= right && formed == required){
                char leftCharc = s[left];
                if( right -left +  1 < minLen){
                    minLen = right - left + 1;
                    startIdx = left;
                }
                window[leftCharc]--;
                if(target.count(leftCharc) && window[leftCharc] < target[leftCharc]){
                    formed--;
                }
                left++;
            }
            right++;
        }
        return minLen ==INT_MAX ? "":s.substr(startIdx,minLen);
    }
};
