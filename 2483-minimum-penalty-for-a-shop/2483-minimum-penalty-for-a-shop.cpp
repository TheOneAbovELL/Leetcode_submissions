class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int totalY = 0;
        for (char c : customers) {
            if (c == 'Y') totalY++;
        }
        
        int minPenalty = totalY;
        int bestHour = 0;
        int currentY = 0;
        
        for (int i = 0; i < n; i++) {
            if (customers[i] == 'Y') {
                currentY++;
            }
            int penalty = (i + 1 - currentY) + (totalY - currentY);
            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = i + 1;
            }
        }
        
        return bestHour;
    }
};