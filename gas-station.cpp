/*

Gas Station
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.


我们把gas[i] - cost[i]保存在数组edge中，然后对数组edge求最大子段和（求最大子段和和时，我们把edge数组看作首尾相连的循环数组），如果edge的所有元素之和>=0，则汽车可以循环一圈，且这个最大子段的起始位置就是汽车的出发位置；若edge之和小于0，则汽车不能循环一圈。我们之所以对edge数组求最大子段和，是因为按照最大子段和问题的特性，保证了汽车从最大子段的起始端出发到最大子段的末尾的过程中汽车油箱内的油量一直是正数，且汽车走完该子段后，车内可以剩余最多的油。

其实：edge数组所有元素之和>=0 是 汽车可以循环一圈的充分必要条件



*/


class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        const int n = gas.size();
        vector<int> edge(n);
        int sum = 0;//sum是edge数组所有元素之和
        for(int i = 0; i < n; i++) {
            edge[i] = gas[i] - cost[i];
            sum += edge[i];
        }
        if(sum < 0)
            return -1;
        int startpos = 0, endpos = 0;
        int maxSub = maxSubSegment(edge, startpos, endpos);
        return startpos;
    }

    //求循环数组的最大子段和,并返回最大子段的首尾位置
    int maxSubSegment(vector<int>&arr, int &startpos, int &endpos) {
        int n = arr.size();
        int result = INT_MIN, sum = -1;
        int starting = -1, ending = -1;//当前子段的起始端
        int i = 0, j=0; //j是i对n求模之前的值，即i = j%n
        while(starting < n) {
            if(i == starting)//防止子段首尾相接
                break;
            if(sum >= 0) {
                sum += arr[i];
                ending = i;
            }
            else {
                sum = arr[i];
                starting = j;
                //设置成j是为了控制while循环结束条件，
                //因为子段的起始位置不会过了尾部又循环到数组首部
                ending = i;
            }
            if(result < sum) {
                result = sum;
                startpos = starting;
                endpos = ending;
            }
            i = (i+1)%n;
            j ++;
        }

        return result;
    }
};