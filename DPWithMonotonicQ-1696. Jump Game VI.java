class Game implements Comparable<Game>{ 

    int score;
    int idx;

    public Game(int score,int idx){
        this.score = score;
        this.idx = idx;
    }

    @Override
    public int compareTo(Game other){
        return Integer.compare(other.score,this.score);
    }
}
class Solution {
     
    public int maxResult(int[] nums, int k) {
        
        int n = nums.length;
        int [] dp = new int[n+1];
        PriorityQueue<Game> maxHeap = new PriorityQueue<>();
        Deque<Integer> dq = new ArrayDeque<>();
        dq.addLast(0);
        dp[0] = nums[0];
        // max heap sol
        // maxHeap.add(new Game(dp[0],0));
        // for(int i=1;i<n;i++){
            
        //     while(!maxHeap.isEmpty() && maxHeap.peek().idx < i-k){
        //         maxHeap.poll();
        //     }

        //     dp[i] = nums[i] + maxHeap.peek().score;
        //     maxHeap.add(new Game(dp[i],i));
        // }

        for(int i=1;i<n;i++){

            while(!dq.isEmpty() && dq.peekFirst()<i-k){
                dq.pollFirst();
            }

            dp[i] = nums[i] + dp[dq.peekFirst()];
            while(!dq.isEmpty() && dp[dq.peekLast()]<dp[i]){
                dq.pollLast();
            }
            dq.addLast(i);
        }

        return dp[n-1];
    }
}
