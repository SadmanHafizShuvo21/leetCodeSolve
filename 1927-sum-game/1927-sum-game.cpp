class Solution {
public:
    using ll = long long;

    bool sumGame(string num) {
        ll n = num.size(), hf = n / 2;

        ll lq = 0, lds = 0;
        for (int i = 0; i < hf; i++) {
            lq += (num[i] == '?');

            lds += (num[i] != '?' ? num[i] - '0' : 0);
        }

        ll rq = 0, rds = 0;
        for (int i = hf; i < n; i++) {
            rq += (num[i] == '?');

            rds += (num[i] != '?' ? num[i] - '0' : 0);
        }

        if (lq == rq) {
            return lds != rds;
        }

        ll dif  = lq - rq;
        ll difSum = lds - rds;

        if (abs(dif) % 2 == 1) {
            return true;
        }

        if (dif < 0) {
            dif = - dif;
            difSum = -difSum;
        }

        return difSum + 9L * (dif / 2) != 0;
    }
};