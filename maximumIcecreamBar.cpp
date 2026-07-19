#include <vector>
#include <algorithm>

class Solution {
public:
    int maxIceCream(std::vector<int>& costs, int coins) {
        // Find the maximum price in costs to bound our frequency array
        int max_cost = 0;
        for (int cost : costs) {
            if (cost > max_cost) {
                max_cost = cost;
            }
        }

        // Create a frequency array populated with 0s
        std::vector<int> freq(max_cost + 1, 0);
        for (int cost : costs) {
            freq[cost]++;
        }

        int bars_bought = 0;

        // Iterate through all possible prices greedily
        for (int price = 1; price <= max_cost; ++price) {
            // Skip prices that don't exist in our costs array
            if (freq[price] == 0) {
                continue;
            }

            // If we can't afford even one bar at this price, we must stop
            if (coins < price) {
                break;
            }

            // Calculate how many bars at this price we can afford vs how many are available
            long long total_available = freq[price];
            long long affordable = coins / price;
            long long count_to_buy = std::min(total_available, affordable);

            // Update total bars bought and remaining coins
            bars_bought += count_to_buy;
            coins -= count_to_buy * price;

            // Early exit if we can no longer afford any more bars at this current price tier
            if (coins < price) {
                break;
            }
        }

        return bars_bought;
    }
};