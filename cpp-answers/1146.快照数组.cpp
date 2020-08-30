/*
 * @Description: 
 * @Author: Hongyang_Yang
 * @Date: 2020-08-30 17:47:44
 * @LastEditors: Hongyang_Yang
 * @LastEditTime: 2020-08-30 17:52:18
 */
/*
 * @lc app=leetcode.cn id=1146 lang=cpp
 *
 * [1146] 快照数组
 */

// @lc code=start
class SnapshotArray
{
public:
    vector<vector<pair<int, int>>> history; //pair<snap_id, val>
    int curSnap;
    SnapshotArray(int length)
    {
        history.resize(length, {{-1, 0}});
        curSnap = 0;
    }

    void set(int index, int val)
    {
        if (history[index].back().first < curSnap)
            history[index].push_back({curSnap, val});
        else
            history[index].back().second = val;
    }

    int snap()
    {
        return curSnap++;
    }

    int get(int index, int snap_id)
    {
        return (upper_bound(history[index].begin(), history[index].end(), make_pair(snap_id, INT_MAX)) - 1)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
// @lc code=end
