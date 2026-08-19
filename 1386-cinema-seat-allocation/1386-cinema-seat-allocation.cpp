class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> reservedMap;
        for(const auto& seat: reservedSeats){
            int row=seat[0];
            int col=seat[1];
            if(col>=2 && col<=9){
                reservedMap[row] |=(1<<col);
            }
        }
        int maxFamilies=(n- static_cast<int>(reservedMap.size()))*2;
        int leftMask= 0b0000111100;
        int rightMask= 0b1111000000;
        int middleMask= 0b0011110000;
        for(const auto& [row,mask]:reservedMap){
            bool leftPossible= (mask & leftMask) ==0;
            bool rightPossible= (mask & rightMask) ==0;
            bool middlePossible= (mask & middleMask) ==0;
            if(leftPossible && rightPossible){
                maxFamilies+=2;
            }
            else if(leftPossible || rightPossible || middlePossible){
                maxFamilies +=1;
            }
        }
        return maxFamilies;
    }
};