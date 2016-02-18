/*

Best Time to Buy and Sell Stock My Submissions Question

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Subscribe to see which companies asked this question

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "common.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;

        int profit = 0;
        int cur_min = prices[0];

        for(int i = 1; i < prices.size(); ++i) {
        	profit = max( profit, prices[i] - cur_min );
        	cur_min = min( cur_min, prices[i] );
        }
        return profit;
    }
};

int main(int argc, char* argv[]) {
	return 0;
}