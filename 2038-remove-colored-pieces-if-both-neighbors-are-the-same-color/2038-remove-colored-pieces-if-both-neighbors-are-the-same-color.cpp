class Solution {
public:
    bool winnerOfGame(string C) {
        int n = C.size();
        bool ans = false;
        int As=0, Bs=0;
        int l=0, r=0;
        
        while (r < n) {
            if (C[r] != C[l]){
                if (r-l>2) {
                    if (C[l] == 'A')
                        As += r-l-2;
                    else 
                        Bs += r-l-2;
                }
                l = r;
            } else if (r==n-1) {
                if (r-l>1) {
                    if (C[l] == 'A')
                        As += r-l-1;
                    else 
                        Bs += r-l-1;
                }
            }
            r++;
        }
        
        cout <<As<<Bs<<endl;
        
        return As > Bs;
    }
};