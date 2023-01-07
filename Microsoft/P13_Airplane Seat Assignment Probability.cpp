class Solution {
public:
    //1227. Airplane Seat Assignment Probability
    double nthPersonGetsNthSeat(int n) {
       if(n==1) return (double)n;
       return (double)1/2; 
    }
};
