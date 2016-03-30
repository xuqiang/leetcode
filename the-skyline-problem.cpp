/*

The Skyline Problem


A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A), write a program to output the skyline formed by these buildings collectively (Figure B).

 Buildings  Skyline Contour
The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .

The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.

For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].

Notes:

The number of buildings in any input list is guaranteed to be in the range [0, 10000].
The input list is already sorted in ascending order by the left x position Li.
The output list must be sorted by the x position.
There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]


将每个线段的左边节点与右边节点存到新的vector height中，根据x坐标值排序，然后遍历求拐点。求拐点的时候用一个最大化heap来保存当前的楼顶高度，遇到左边节点，就在heap中插入高度信息，遇到右边节点就从heap中删除高度。分别用pre与cur来表示之前的高度与当前的高度，当cur != pre的时候说明出现了拐点。在从heap中删除元素时要注意，我使用priority_queue来实现，priority_queue并不提供删除的操作，所以又用了别外一个unordered_map来标记要删除的元素。在从heap中pop的时候先看有没有被标记过，如果标记过，就一直pop直到空或都找到没被标记过的值。别外在排序的时候要注意，如果两个节点的x坐标相同，我们就要考虑节点的其它属性来排序以避免出现冗余的答案。且体的规则就是如果都是左节点，就按y坐标从大到小排，如果都是右节点，按y坐标从小到大排，一个左节点一个右节点，就让左节点在前



*/


class Solution {
private:
    enum NODE_TYPE {LEFT, RIGHT};
    struct node {
        int x, y;
        NODE_TYPE type;
        node(int _x, int _y, NODE_TYPE _type) : x(_x), y(_y), type(_type) {}
    };
    
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<node> height;
        for (auto &b : buildings) {
            height.push_back(node(b[0], b[2], LEFT));
            height.push_back(node(b[1], b[2], RIGHT));
        }
        sort(height.begin(), height.end(), [](const node &a, const node &b) {
            if (a.x != b.x) return a.x < b.x;
            else if (a.type == LEFT && b.type == LEFT) return a.y > b.y;
            else if (a.type == RIGHT && b.type == RIGHT) return a.y < b.y;
            else return a.type == LEFT;
        });
        
        priority_queue<int> heap;
        unordered_map<int, int> mp;
        heap.push(0);
        vector<pair<int, int>> res;
        int pre = 0, cur = 0;
        for (auto &h : height) {
            if (h.type == LEFT) {
                heap.push(h.y);
            } else {
                ++mp[h.y];
                while (!heap.empty() && mp[heap.top()] > 0) {
                    --mp[heap.top()];
                    heap.pop();
                }
            }   
            cur = heap.top();
            if (cur != pre) {
                res.push_back({h.x, cur});
                pre = cur;
            }
        }
        return res;
    }
};