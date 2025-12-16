class Solution {
public:
    int FU(int n, vector<int> P, vector<int> F, vector<vector<int>> Vo, int B) {

        vector<vector<int>> V(n + 1);
        vector<int> PAR(n + 1, -1);
        vector<int> VST(n + 1, 0);
        for (int q = 1; q <= n - 1; q++) {
            V[Vo[q - 1][0]].push_back(Vo[q - 1][1]);
            PAR[Vo[q - 1][1]] = Vo[q - 1][0];
            VST[Vo[q - 1][0]] = VST[Vo[q - 1][0]] + 1;
        }

        queue<int> Po;
        int dp[n + 1][B + 1][3];
        for (int q = 1; q <= n; q++) {
            if (V[q].empty()) {
                Po.push(q);
                VST[q] = 0;
                for (int qo = 0; qo <= B; qo++) {
                    dp[q][qo][0] = 0;
                    dp[q][qo][1] = 0;
                    dp[q][qo][2] = 0;
                    if (qo >= P[q] && F[q] >= P[q]) {
                        dp[q][qo][1] = F[q] - P[q];
                    }
                    if (qo >= (P[q] / 2) && F[q] >= (P[q] / 2) && q != 1) {
                        dp[q][qo][2] = F[q] - (P[q] / 2);
                    }
                }
            }
        }

        while (!Po.empty()) {

            queue<int> PL;
            while (!Po.empty()) {

                int h = Po.front();
                Po.pop();
                if (V[h].empty()) {
                    if (h != 1) {
                        VST[PAR[h]] = VST[PAR[h]] - 1;
                    }
                    if (PAR[h] != -1 && VST[PAR[h]] == 0) {
                        PL.push(PAR[h]);
                    }
                    continue;
                }

                vector<int> DL(B + 1, 0);
                for (int q = 0; q < V[h].size(); q++) {
                    vector<int> Do = DL;
                    for (int d = 0; d <= B; d++) {
                        for (int b = 0; b <= d; b++) {
                            Do[d] =
                                max(Do[d], DL[d - b] + max(dp[V[h][q]][b][0],
                                                           dp[V[h][q]][b][2]));
                        }
                    }
                    DL = Do;
                }

                vector<int> DR(B + 1, 0);
                for (int q = 0; q < V[h].size(); q++) {
                    vector<int> Do = DR;
                    for (int d = 0; d <= B; d++) {
                        for (int b = 0; b <= d; b++) {
                            Do[d] =
                                max(Do[d], DR[d - b] + max(dp[V[h][q]][b][0],
                                                           dp[V[h][q]][b][1]));
                        }
                    }
                    DR = Do;
                }

                for (int q = 0; q <= B; q++) {
                    dp[h][q][0] = DR[q];
                    dp[h][q][1] = DR[q];
                    dp[h][q][2] = DR[q];
                    if (q >= P[h]) {
                        dp[h][q][1] = (F[h] - P[h]) + DL[q - P[h]];
                    }
                    if (q >= P[h] / 2 && h != 1) {
                        dp[h][q][2] = (F[h] - (P[h] / 2)) + DL[q - (P[h] / 2)];
                    }
                }

                for (int q = 1; q <= B; q++) {
                    for (int qo = 0; qo <= 2; qo++) {
                        dp[h][q][qo] = max(dp[h][q][qo], dp[h][q - 1][qo]);
                    }
                }
                if (h != 1) {
                    VST[PAR[h]] = VST[PAR[h]] - 1;
                }
                if (h != 1 && (VST[PAR[h]] == 0)) {
                    PL.push(PAR[h]);
                }
            }

            while (!PL.empty()) {
                Po.push(PL.front());
                PL.pop();
            }
        }

        int S = max(dp[1][B][0], dp[1][B][1]);
        return S;
    }
    int maxProfit(int n, vector<int>& Po, vector<int>& Fo,
                  vector<vector<int>>& Vo, int B) {

        vector<int> P(n + 1);
        vector<int> F(n + 1);
        for (int q = 1; q <= n; q++) {
            P[q] = Po[q - 1];
            F[q] = Fo[q - 1];
        }
        return FU(n, P, F, Vo, B);
    }
};