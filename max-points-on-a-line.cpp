/*

Max Points on a Line


Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.


一个很直观的解法是计算每两个点形成的直线，然后把相同的直线合并，最后包含点最多的直线上点的个数就是本题的解。我们知道表示一条直线可以用斜率和y截距两个浮点数（垂直于x轴的直线斜率为无穷大，截距用x截距），同时还需要保存每条直线上的点（避免重复



*/


/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = points.size(), res = 1;
        if(len == 0)return 0;
        unordered_map<double, int> umap;
        for(int i = 0; i < len; i++) {
            umap.clear();
            int samePointNum = 0,tmpres = 1;
            for(int j = i+1; j < len; j++) {
                double slope = std::numeric_limits<double>::infinity();//斜率初始化为无穷大，我们视横坐标相同的两点间的斜率为无穷大
                if(points[i].x != points[j].x)
                    slope = 1.0*(points[i].y - points[j].y) / (points[i].x - points[j].x);
                else if(points[i].y == points[j].y)
                    {samePointNum++; continue;}
                int tmp;
                if(umap.find(slope) != umap.end())
                    tmp = ++umap[slope];
                else  {
                    umap.insert(unordered_map<double, int>::value_type(slope, 2));
                    tmp = 2;
                }
                if(tmpres < tmp)tmpres = tmp;
            }
            if(res < tmpres + samePointNum)res = tmpres + samePointNum;
        }
        return res;
    }
};