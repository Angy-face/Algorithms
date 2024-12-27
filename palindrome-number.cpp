class Solution {
public:
    bool isPalindrome(int x) {
        string text = to_string(x);
        for(int i = 0 ; i < size(text); i++){
            if(text[i] != text[size(text)-i-1])
                return false;
        }
        return true;
    }
};