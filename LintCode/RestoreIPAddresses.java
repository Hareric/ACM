public class Solution {
    /**
     * @param s the IP string
     * @return All possible valid IP addresses
     */
     
    ArrayList<String> ipList;
    
    public void backTrack(String originIp, int sLen, int num, String ip){
        if(num==4 && sLen == originIp.length()){
            this.ipList.add(ip.substring(0, ip.length()-1));
        }
        else if (num==4){
            return;
        }
        for (int i=1; i<=3; i++){
            if (sLen+i > originIp.length()){
                break;
            }
            if(i!=1){
                int ipInt = Integer.parseInt(originIp.substring(sLen, sLen+i));
                if(ipInt >255 || ipInt < 10){
                    break;
                }
            }
            String newIp = ip + originIp.substring(sLen, sLen+i) + '.';
            backTrack(originIp, sLen+i, num+1, newIp);
        }
        
    }
    public ArrayList<String> restoreIpAddresses(String s) {
        // Write your code here
        this.ipList = new ArrayList<String>();
        backTrack(s, 0, 0, "");
        return this.ipList;
    }
}
