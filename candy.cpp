/*
 
 candy

 There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

题目：
n个小孩 每个小孩有个平分rating value，分配糖果要求：
1. 每个小孩至少有一个
2. 如果一个小孩的rating比邻居高，那么需要分的糖果也多

在满足条件的情况下 需要拿出糖果的总数

*/




 #include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "common.h"

using namespace std;


class Solution {
public:
    int candy(vector<int>& ratings) {
        // 左右扫描 

       	const int N = ratings.size();
       	vector<int> incrment(N);

       	// 第一次遍历 从左 到 右
       	for (int i = 1, inc = 1; i < N; ++i) {
       		if(ratings[i] > ratings[i - 1]) {
       			incrment[i] = max(inc++, incrment[i]);
       		} else {
       			inc = 1;
       		}
       	}
       	// 第二次 从右 到 左
       	for( int i = N - 2, inc = 1; i >= 0; i -- ) {
       		if(ratings[i] > ratings[ i + 1 ]) {
       			incrment[ i ] = max( inc++, incrment[i] );
       		} else {
       			inc = 1;
       		}
       	}
       	return std::accumulate( &incrment[0], &incrment[0] + N , N );
     }
};


int main(int argc, char* argv[]) {
	return 0;
}