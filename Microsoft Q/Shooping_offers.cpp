class Solution {
public:
    map<vector<int>,int> dp;
    int calculateMin(vector<int>& needs,vector<vector<int>>& special,vector<int>& price){
        // IF SUBPROBLEM ALREADY SOLVED RETURN THE STORED ANSWER
        if(dp.find(needs)!=dp.end()){
            return dp[needs];
        }
		
		//IF NOT SOLVED , THEN WE WILL SOLVE IT
        int result = INT_MAX;
		
		//TRYING ALL THE POSSIBLE COMBINATIONS WITH THE SPECIAL OFFERS
        for(vector<int> offer: special){
            bool flag = true;
            for(int i=0;i<needs.size();i++){
                needs[i] -= offer[i];
                if(needs[i]<0)
                    flag = false;
            }
            if(flag){
                result = min(result,offer[needs.size()] + calculateMin(needs,special,price));
            }
            for(int i=0;i<needs.size();i++){
                needs[i] += offer[i];
            }
        }
		//IF WE CAN'T GET A SUITABLE OFFER FOR THE ABOVE NEEDS THE WE WILL BUY THEM AT ORIGINAL PRICES
		int tempResult = 0;
		for(int i=0;i<needs.size();i++){
			tempResult += needs[i]*price[i];
		}
		
        result = min(result,tempResult);
        return dp[needs] = result;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return calculateMin(needs,special,price);
    }
};
