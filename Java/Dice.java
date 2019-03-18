package lintcode;
import java.util.*;

public class Dice
{
    /**
     * @param n an integer
     * @return a list of Map.Entry<sum, probability>
     */
    public static List<Map.Entry<Integer, Double>> dicesSum(int n) {
        // Write your code here
        // Ps. new AbstractMap.SimpleEntry<Integer, Double>(sum, pro)
        // to create the pair
    	long[][] dict = new long[n+1][6*n+1]; // dict[i][j] 用i个骰子 扔出j时 有多少种情况
    	for (int i=1; i<=6; i++) dict[1][i] = 1;  // 初始化第一行的值
    	for (int i=2; i<=n; i++)
    	{
    		for (int j=i; j<=6*i; j++)
    		{
    			for(int t=1; t<=6; t++)
    			{
    				if (j-t < 0)
    				{
    					break;
    				}
    				dict[i][j] += dict[i-1][j-t];
    			}
    			
    		}
    	}
    	Map<Integer, Double> res = new HashMap<Integer, Double>();
    	double sum = Math.pow(6, n);
    	for (int i=n; i<=6*n; i++)
    	{
    		res.put(i,  (dict[n][i]/sum));
    		
    	}
    	return new ArrayList<Map.Entry<Integer, Double>>(res.entrySet());
    	
    	
    	
    }
    
    public static void main(String[] args)
	{
		for (Map.Entry<Integer, Double>t:dicesSum(15))
		{
			System.out.println(t.getKey() + "  =  " + t.getValue());
		}
	}
}	
