#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
private:
    // Custom pair comparator: Sorts by frequency descending, then by value descending
    struct Compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
            if (a.first != b.first) {
                return a.first > b.first; // Higher frequency gets priority
            }
            return a.second > b.second;   // Higher value breaks the tie
        }
    };

    set<pair<int, int>, Compare> top; // VIP Club (holds at most x elements)
    set<pair<int, int>, Compare> bot; // Waiting Room (holds everything else)
    long long current_sum = 0;        // Tracks the exact x-sum of the top set
    int max_x;

    // Helper to add an item to the waiting room
    void add(pair<int, int> p) {
        bot.insert(p);
    }

    // Helper to remove an item cleanly from whichever room it resides in
    void remove(pair<int, int> p) {
        if (top.count(p)) {
            current_sum -= (long long)p.first * p.second;
            top.erase(p);
        } else {
            bot.erase(p);
        }
    }

    // Automatically rebalances the sets in O(log K) time
    void balance() {
        // 1. If the VIP club has vacant seats, fill them from the Waiting Room
        while (!bot.empty() && top.size() < max_x) {
            auto best_bot = *bot.begin();
            bot.erase(bot.begin());
            top.insert(best_bot);
            current_sum += (long long)best_bot.first * best_bot.second;
        }

        // 2. If the VIP club is overfilled, move the weakest guests down to bot
        while (top.size() > max_x) {
            auto weakest_top = *top.rbegin(); // Weakest is at the end
            top.erase(prev(top.end()));
            bot.insert(weakest_top);
            current_sum -= (long long)weakest_top.first * weakest_top.second;
        }

        // 3. Swap Check: If a guest in bot is stronger than the weakest in top, swap them
        while (!bot.empty() && !top.empty()) {
            auto weakest_top = *top.rbegin();
            auto best_bot = *bot.begin();

            Compare comp;
            if (comp(best_bot, weakest_top)) { 
                // Evict weakest top
                top.erase(prev(top.end()));
                current_sum -= (long long)weakest_top.first * weakest_top.second;
                bot.insert(weakest_top);

                // Admit best bot
                bot.erase(bot.begin());
                top.insert(best_bot);
                current_sum += (long long)best_bot.first * best_bot.second;
            } else {
                break; // Balanced perfectly
            }
        }
    }

public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        max_x = x;
        vector<long long> ans(n - k + 1, 0);
        unordered_map<int, int> freq; 

        // Initialize the first sliding window
        for (int i = 0; i < k; i++) {
            int val = nums[i];
            if (freq[val] > 0) {
                remove({freq[val], val});
            }
            freq[val]++;
            add({freq[val], val});
        }
        balance();
        ans[0] = current_sum;

        // Slide the window across the remaining segments
        for (int i = 1; i <= n - k; i++) {
            // Remove left outgoing element
            int out_val = nums[i - 1];
            remove({freq[out_val], out_val});
            freq[out_val]--;
            if (freq[out_val] > 0) {
                add({freq[out_val], out_val});
            }

            // Insert right incoming element
            int in_val = nums[i + k - 1];
            if (freq[in_val] > 0) {
                remove({freq[in_val], in_val});
            }
            freq[in_val]++;
            add({freq[in_val], in_val});

            // Rebalance and collect the sum in O(1) time
            balance();
            ans[i] = current_sum;
        }

        return ans;
    }
};
