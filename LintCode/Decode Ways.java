public class Solution {
    /**
     * @param s a string,  encoded message
     * @return an integer, the number of ways decoding
     */
    public int numDecodings(String s) {
        // Write your code here
        if(s.equals("")||s.charAt(0)=='0'){
            return 0;
        }
        if(s.length()==1){
            return 1;
        }
        int[] ways = new int[s.length()];
        ways[0] = 1;
        int st = Integer.parseInt(s.substring(0,2));
        if(st>0&&st<=26){
            if(s.charAt(1)=='0'){
                ways[1] = 1;
            }
            else{
                ways[1] = 2;
            }
        }
        
        for(int i=2; i<s.length(); i++){
            if(s.charAt(i)=='0'){
                if(s.charAt(i-1)=='1'||s.charAt(i-1)=='2'){
                        ways[i] = ways[i-2];
                        continue;
                }
                else{
                    return 0;
                }
            }
            st = Integer.parseInt(s.substring(i-1,i+1));
            if(st>10&&st<=26){
                ways[i] = ways[i-1] + ways[i-2];
            }
            else{
                ways[i] = ways[i-1];
            }
        }
        return ways[s.length()-1];
        
    }
}
