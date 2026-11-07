
class Solution {
public:
    std::vector<int> assignTasks(std::vector<int>& servers, std::vector<int>& tasks) {
        using ll = long long;

        ll n = servers.size();
        ll m = tasks.size();

        using freeServer = std::pair<int, int>;
        using busyServer = std::tuple<ll, int, int>;

        std::priority_queue<
            freeServer,
            std::vector<freeServer>,
            std::greater<freeServer>
        > free;

        std::priority_queue<
            busyServer,
            std::vector<busyServer>,
            std::greater<busyServer>
        > busy;

        for (int i = 0; i < n; i++) {
            free.push({servers[i], i});
        }

        std::vector<int> ans(m);

        for (int j = 0; j < m; j++) {

            while (!busy.empty() && std::get<0>(busy.top()) <= j) {
                auto [time, weight, idx] = busy.top();
                busy.pop();

                free.push({weight, idx});
            }

            if (free.empty()) {
                auto [time, weight, idx] = busy.top();
                busy.pop();

                ans[j] = idx;

                busy.push({time + tasks[j], weight, idx});
            }
            else {
                auto [weight, idx] = free.top();
                free.pop();

                ans[j] = idx;

                busy.push({j + tasks[j], weight, idx});
            }
        }

        return ans;
    }
};
