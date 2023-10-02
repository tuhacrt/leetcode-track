class Solution {
public:
    bool winnerOfGame(string C) {
        int a=0, b=0;
        
        for (int i=1;i<C.size()-1;i++) {
            if(C[i-1] == C[i] && C[i] == C[i+1]) {
                if (C[i] == 'A')
                    a++;
                else
                    b++;
            }
        }
        
        return a > b;
    }
};