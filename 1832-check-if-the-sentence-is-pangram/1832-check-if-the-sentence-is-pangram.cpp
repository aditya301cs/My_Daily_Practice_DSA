class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>alpha(26,0);
        int count = 0;
        for(auto & ch : sentence){
            int index = ch - 'a';
            if(alpha[index] == 0){
                alpha[index]++;
                count++;
            }
        }
        if(count == 26){
            return true;
        }else{
            return false;
        }
    }
};