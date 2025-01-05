class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0, cow = 0;
        string ans = "";
        int arrS[10] = {0}, arrG[10] = {0};

        for(int i = 0; i < secret.length(); i++){
            if(secret[i] == guess[i]){
                bull++;
                continue;
            }
            arrS[secret[i] - '0']++;
            arrG[guess[i] - '0']++;
        }
        for(int i = 0; i < 10; i++){
            if((arrG[i] >= arrS[i] || arrS[i] > arrG[i]) && arrS[i] != 0 && arrG[i] != 0){
                cow++;
                arrS[i]--;
                arrG[i]--;
                if(arrS[i] != 0)
                    i--;
            }
        }
        ans = to_string(bull) + 'A' + to_string(cow) + 'B';
        return ans;
    }
};
