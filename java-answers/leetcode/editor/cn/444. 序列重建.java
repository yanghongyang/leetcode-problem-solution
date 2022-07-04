class Solution {
    /**
    1. sequences 各个子序列均在 1 ~ n 之间
    2. sequences 各个子序列相邻数字对应到 nums 的顺序必须严格单调递增
    3. sequences 存在任意 {nums[i], nums[i + 1]} （在 sequences 也以相邻形式存在） 
     */
    public boolean sequenceReconstruction(int[] nums, List<List<Integer>> seqs) {
        int n = nums.length;
        int[] index = new int[n + 1];
        for (int i = 0; i < n; i++) {
            index[nums[i]] = i; // index[num] 表示 nums 中的 num 的下标
        }
        boolean[] isAdj = new boolean[n + 1];   // 表示 seq 中的 (u, v), 在 nums 中是否也存在（同样的相邻数字）
        for (List<Integer> seq : seqs) {
            int len = seq.size(), v = seq.get(0), uIdx = -1, vIdx = -1; // uIdx 初始必须为 -1
            for (int i = 0; i < len; i++) {
                v = seq.get(i);
                if (v < 1 || v > n) {
                    return false;   // 检查 1
                }
                uIdx = vIdx;
                vIdx = index[v];
                if (uIdx + 1 == vIdx) {
                    isAdj[v] = true;    // 检查 3 预处理
                }
                if (uIdx > vIdx) {
                    return false;   // 检查2
                }
            }
        }
        for (int i = 1; i < isAdj.length; i++) {
            if (!isAdj[i]) {
                return false;   // 检查 3
            }
        }
        return true;
    }
}