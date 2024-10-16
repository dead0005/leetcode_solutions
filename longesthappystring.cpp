class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res;
        int ac = 0, bc = 0, cc = 0;
        
        while (a > 0 || b > 0 || c > 0) {
            if (a >= b && a >= c) {
                if (a >= 2 && ac != 1) {
                    if (ac == 2 && bc == 0 && cc == 0) break;
                    res += "aa"; a -= 2; ac = 2; bc = 0; cc = 0;
                    if (b > 0) { res += "b"; bc = 1; ac = 0; b--; }
                    else if (c > 0) { res += "c"; cc = 1; ac = 0; c--; }
                } else {
                    if (ac == 2) break;
                    res += "a"; a--; ac = 1;
                }
            } else if (b >= a && b >= c) {
                if (b >= 2 && bc != 1) {
                    if (ac == 0 && bc == 2 && cc == 0) break;
                    res += "bb"; b -= 2; ac = 0; bc = 2; cc = 0;
                    if (a > 0) { res += "a"; ac = 1; bc = 0; a--; }
                    else if (c > 0) { res += "c"; cc = 1; bc = 0; c--; }
                } else {
                    if (bc == 2) break;
                    res += "b"; b--; bc = 1;
                }
            } else {
                if (c >= 2 && cc != 1) {
                    if (ac == 0 && bc == 0 && cc == 2) break;
                    res += "cc"; c -= 2; ac = 0; bc = 0; cc = 2;
                    if (a > 0) { res += "a"; ac = 1; cc = 0; a--; }
                    else if (b > 0) { res += "b"; bc = 1; cc = 0; b--; }
                } else {
                    if (cc == 2) break;
                    res += "c"; c--; cc = 1;
                }
            }
        }
        return res;
    }
};