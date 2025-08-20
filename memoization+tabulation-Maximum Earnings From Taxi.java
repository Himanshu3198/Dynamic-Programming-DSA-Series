class Solution {
    public long maxTaxiEarnings(int n, int[][] rides) {

        Arrays.sort(rides, (a, b) -> a[0] - b[0]);
        Long memo[] = new Long[100005];
        return solve(rides, 0, memo);
    }

    private long solve(int[][] rides, int idx, Long[] memo) {
        if (idx >= rides.length)
            return 0;
        if (memo[idx] != null)
            return memo[idx];

        int nextIdx = binarySearch(rides, rides[idx][1]);
        long pick = rides[idx][1] - rides[idx][0] + rides[idx][2] + solve(rides, nextIdx, memo);
        long notPick = solve(rides, idx + 1, memo);
        return memo[idx] = Math.max(pick, notPick);
    }

    private int binarySearch(int[][] rides, int target) {

        int start = 0, end = rides.length - 1;
        while (start <= end) {
            int mid = (end + start) / 2;
            if (rides[mid][0] >= target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return start;
    }
}
