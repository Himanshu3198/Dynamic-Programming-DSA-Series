class Solution {

    private boolean canForm(String word,Set<String>dict,Map<Integer,Boolean> dp,int start,int len){

        if(word.length() == start && len>1)  return true;
        if(dp.containsKey(start)) return dp.get(start);

        for(int end = start+1;end<=word.length();end++){
            if(dict.contains(word.substring(start,end))){
                if(canForm(word,dict,dp,end,len+1)){
                    dp.put(start,true);
                    return true;
                }
            }
        }
        dp.put(start,false);
        return false;
    }
    public List<String> findAllConcatenatedWordsInADict(String[] words) {
        
        Set<String> dict = new HashSet<>(Arrays.asList(words));
        int  n = words.length;
        List<String> res = new ArrayList<>();

        for(String word:words){
             Map<Integer,Boolean> dp = new HashMap<>();
            if(canForm(word,dict,dp,0,0)){
                res.add(word);
            }
        }
        return res;
    }
}
