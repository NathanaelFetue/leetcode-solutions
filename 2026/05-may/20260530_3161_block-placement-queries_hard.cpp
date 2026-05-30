/*
 * Problem #3161 - Block Placement Queries (Hard)
 * URL: https://leetcode.com/problems/block-placement-queries/
 *
 * Approach: Segment Tree + Ordered Set (std::set)
 * Obstacles are tracked in a sorted set to efficiently find gaps between consecutive obstacles.
 * A max segment tree stores, at each obstacle position x, the gap size (x - prev_obstacle),
 * enabling range-max queries to determine if any gap in [0, x] is large enough to fit a block of given size.
 * For type-1 queries, insert the obstacle and update gap values for affected positions.
 * For type-2 queries, check if the direct gap before x suffices, or if any gap in [0, x] is >= sz.
 *
 * Time Complexity: O(Q * log(maxX))
 *   - Each query involves at most O(log maxX) set operations and O(log maxX) segment tree operations.
 *
 * Space Complexity: O(maxX + Q)
 *   - Segment tree uses O(maxX) space; set and results use O(Q) space.
 *
 * Runtime: 325 ms | Memory: 340.8 MB
 */

class Solution {
    struct SegTree {
        int n;
        vector<int> tree;
        SegTree(int n) : n(n), tree(4*n+4, 0) {}
        void update(int pos, int val, int node, int lo, int hi) {
            if (lo == hi) { tree[node] = val; return; } // SET pas MAX
            int mid = (lo+hi)/2;
            if (pos <= mid) update(pos, val, 2*node, lo, mid);
            else            update(pos, val, 2*node+1, mid+1, hi);
            tree[node] = max(tree[2*node], tree[2*node+1]);
        }
        int query(int l, int r, int node, int lo, int hi) {
            if (r < lo || hi < l) return 0;
            if (l <= lo && hi <= r) return tree[node];
            int mid = (lo+hi)/2;
            return max(query(l,r,2*node,lo,mid), query(l,r,2*node+1,mid+1,hi));
        }
        void update(int p, int v) { update(p, v, 1, 0, n-1); }
        int query(int l, int r) { return l>r ? 0 : query(l,r,1,0,n-1); }
    };

public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int maxX = 0;
        for (auto& q : queries) maxX = max(maxX, q[1]);

        SegTree seg(maxX + 1);
        set<int> obs;
        obs.insert(0);
        obs.insert(maxX + 1);

        vector<bool> results;
        for (auto& q : queries) {
            if (q[0] == 1) {
                int x = q[1];
                auto it = obs.insert(x).first;
                auto nextIt = std::next(it);
                int prev = *std::prev(it);
                int next = *nextIt;

                seg.update(x, x - prev);          // gap prev→x
                if (next <= maxX)
                    seg.update(next, next - x);    // mise à jour gap x→next
            } else {
                int x = q[1], sz = q[2];
                auto it = obs.upper_bound(x);
                --it;
                int lastObs = *it;
                bool ok = (x - lastObs >= sz) || (seg.query(0, x) >= sz);
                results.push_back(ok);
            }
        }
        return results;
    }
};
