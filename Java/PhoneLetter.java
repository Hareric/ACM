package lintcode;

import java.util.*;

public class PhoneLetter
{
	public static final Map<Character, Character[]> digitLetterMap = new HashMap<Character, Character[]>();
	static
	{
		digitLetterMap.put('2', new Character[] { 'a', 'b', 'c' });
		digitLetterMap.put('3', new Character[] { 'd', 'e', 'f' });
		digitLetterMap.put('4', new Character[] { 'g', 'h', 'i' });
		digitLetterMap.put('5', new Character[] { 'j', 'k', 'l' });
		digitLetterMap.put('6', new Character[] { 'm', 'n', 'o' });
		digitLetterMap.put('7', new Character[] { 'p', 'q', 'r','s' });
		digitLetterMap.put('8', new Character[] { 't', 'u', 'v' });
		digitLetterMap.put('9', new Character[] { 'w', 'x', 'y','z' });
	};
	
	public static List<String> res;
	public static List<String> letterCombinations(String digits)
	{

		res = new ArrayList<String>();
		if (digits.length() == 0)
		{
			return null;
		}
		String s = "";
		backTrack(digits, 0, s);
		return res;
	}
	
	public static void backTrack(String digits, int index, String word)
	{
		if (index == digits.length())
		{
			res.add(word);
			return;
		}
		for (char c : digitLetterMap.get(digits.charAt(index)))
		{
			
			String word2 = word + String.valueOf(c);
			backTrack(digits, index+1, word2);
			
		}
		
	}
	
	public static void main(String[] args)
	{
		letterCombinations("39484");
		for (String s: res)
		{
			System.out.print(s + " ");
		}
		System.out.println(res.size());
		
	}
}
