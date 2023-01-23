class Solution {
public:
    //904. Fruit Into Baskets
    int totalFruit(vector<int>& fruits) {
    int right=0, left=0, fruit=0;
    unordered_map<int, int> mp;
    while(right<fruits.size()){
        if(mp.find(fruits[right])==mp.end()){
            if(mp.size()==2){
                int i= right-1, temp = fruits[i];
                while(i>=0){
                    if(fruits[i]!=temp){
                        mp.erase(fruits[i]);
                        break;
                    }
                    i--;
                }
                left = i+1;
            }
            mp.insert({fruits[right], 1});
        }
        right++;
        fruit = max(fruit, right-left);
    }
    return fruit;
    }
};
