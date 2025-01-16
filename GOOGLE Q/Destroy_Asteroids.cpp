class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
           int n = asteroids.size();
           sort(asteroids.begin(),asteroids.end());
            
              long long int planet=mass;
             for(int i=0;i<n;i++){
                 if(planet<asteroids[i]) return false;
                 planet+=asteroids[i];
             }
               return true;


    }
};
