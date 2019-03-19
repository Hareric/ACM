package lintcode;

import java.util.*;

public class WordSearchII
{

	/**
	 * @param board:
	 *            A list of lists of character
	 * @param words:
	 *            A list of string
	 * @return: A list of string
	 */
	public static List<String> wordSearch(char[][] board, List<String> words)
	{
		// write your code here
		String word = "";
		int rowNum = board.length;
		int colNum = board[0].length;
		Set<String> resSet = new HashSet<String>();
		TreeSet<String> trie = new TreeSet<String>(); // 字典树
		for (int i = 0; i < words.size(); i++)  // 构建字典树
		{
			word = words.get(i);
			for (int j = 0; j <= word.length(); j++)
			{
				trie.add(word.substring(0, j));
			}
		}
		
		for (int i = 0; i < rowNum; i++)
		{
			for (int j = 0; j < colNum; j++)
			{
				String candidateWord = String.valueOf(board[i][j]);
				if (trie.contains(candidateWord));  // 遍历board 每个board[i][j]扔进search函数里寻找可能的word
				{
					resSet.add(candidateWord);
					boolean hasVisited[][] = new boolean[rowNum][colNum];
					hasVisited[i][j] = true;
					resSet.addAll(search(hasVisited, board, trie, i, j, candidateWord));
				}
				
			}
		}
		resSet.retainAll(words);  // 与字典去交集
		return new ArrayList<String>(resSet);
	}

	public static List<String> search(boolean hasVisited[][], char[][] board, TreeSet<String> trie, int x, int y,
			String candidateWord)
	{

		List<String> candidateResList = new ArrayList<String>();
		candidateResList.add(candidateWord);
		if (x > 0 && !hasVisited[x - 1][y] && trie.contains(candidateWord + board[x - 1][y])) // 向上寻找
		{
			hasVisited[x - 1][y] = true;
			candidateResList.addAll(search(hasVisited, board, trie, x - 1, y, candidateWord + board[x - 1][y]));
			hasVisited[x - 1][y] = false;
		}
		if (x < board.length-1 && !hasVisited[x + 1][y] && trie.contains(candidateWord + board[x + 1][y])) // 向下寻找
		{
			hasVisited[x + 1][y] = true;
			candidateResList.addAll(search(hasVisited, board, trie, x + 1, y, candidateWord + board[x + 1][y]));
			hasVisited[x + 1][y] = false;
		}
		if (y > 0 && !hasVisited[x][y - 1] && trie.contains(candidateWord + board[x][y - 1])) // 向左寻找
		{
			hasVisited[x][y - 1] = true;
			candidateResList.addAll(search(hasVisited, board, trie, x, y - 1, candidateWord + board[x][y - 1]));
			hasVisited[x][y - 1] = false;
		}
		if (y < board[0].length-1&& !hasVisited[x][y + 1] && trie.contains(candidateWord + board[x][y + 1])) // 向右寻找
		{
			hasVisited[x][y + 1] = true;
			candidateResList.addAll(search(hasVisited, board, trie, x, y + 1, candidateWord + board[x][y + 1]));
			hasVisited[x][y + 1] = false;
		}
		return candidateResList;
	}

	public static void main(String[] args)
	{
		// String[] test = {"dog", "dad", "dgdg", "can", "again"};
		char board[][] = { "doaf".toCharArray(), "agai".toCharArray(), "dcan".toCharArray() };
		List<String> words = Arrays.asList("dog", "dad", "dgdg", "can", "again");
		List<String> res = wordSearch(board, words);
		System.out.println(res.size());
		System.out.println(res.toString());
	}
}
