class Solution {
public:
    string addBinary(string a, string b) {
        
        int l = a.length(), m = b.length();
        string s;

        for (int i = l - 1, j = m - 1, carry = 0; i >= 0 || j >= 0 || carry != 0; i--, j--)
        {
            int bit1 = i >= 0 ? a[i] - '0' : 0;
            int bit2 = j >= 0 ? b[j] - '0' : 0;

            int sum = bit1 + bit2 + carry;
            int bit = sum % 2;
            s.push_back((char)(bit + '0'));


            carry = sum / 2;
        }
        
        reverse(s.begin(), s.end());

        return s;
    }
};