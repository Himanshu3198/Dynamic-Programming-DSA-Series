class Job{

    int start;
    int end;
    int profit;

    public Job(int start,int end,int profit){
        this.start = start;
        this.end = end;
        this.profit = profit;
    }
}
class Solution {

    private int solve(Map<Integer,Integer> dp,Job[] job,int idx){
         
         if(idx == job.length) return 0;
         if(dp.containsKey(idx)) return dp.get(idx);

         int pick = 0;
         int nextPick = findNext(job,idx);
         pick = pick + job[idx].profit + solve(dp,job,nextPick);

         int notPick = solve(dp,job,idx+1);

         int maxProfit = Math.max(pick,notPick);

         dp.put(idx,maxProfit);
         return maxProfit;
    }

    private int findNext(Job[] job,int idx){

        int low = idx+1,high = job.length-1,ans = job.length;
        while(low <= high){

            int mid = low+(high-low)/2;
            if(job[mid].start >= job[idx].end){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return ans;
    }
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        
         int n = profit.length;
         Map<Integer,Integer> dp = new HashMap<>();
         Job[] job = new Job[n];
         for(int i=0;i<n;i++){
            job[i] = new Job(startTime[i],endTime[i],profit[i]);
         }
         Arrays.sort(job,(a,b)->a.start-b.start);
         return solve(dp,job,0);
    }
}
