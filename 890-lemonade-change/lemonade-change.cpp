class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fivedol = 0;
        int tendol = 0;
        int n = bills.size();

        for(int i = 0;i<n;i++){
            if(bills[i] == 5){
                fivedol++;
            }
            else if (bills[i] == 10){
                if(fivedol != 0)fivedol--;
                else return false;
                tendol++;
            }
            else{
                if(tendol != 0 && fivedol != 0){
                    tendol--;
                    fivedol--;
                }
                else if (fivedol>= 3)fivedol = fivedol-3;
                else return false;
            }
        }
        return true;
    }
};