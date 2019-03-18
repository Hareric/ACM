package lintcode;

import java.util.*;

public class Sudoku
{
	/**
	 * @param board:
	 *            the sudoku puzzle
	 * @return: nothing
	 */
	static HashSet<Integer> hashset = new HashSet<Integer>();
	static boolean canReture = false;
	
	public static boolean isValid(int[][] board, int startX, int endX, int startY, int endY)
	{
		hashset.clear();
		for (int i = startX; i < endX; i++)
		{
			for (int j = startY; j < endY; j++)
			{
				if (board[i][j] == 0)
				{
					continue;
				}
				if (hashset.contains(board[i][j]))
				{
					return false;
				} else
				{
					hashset.add(board[i][j]);
				}
			}
		}
		return true;
	}
	
	public static boolean canPutIn(int[][] board, int x, int y, int value)
	{
		board[x][y] = value;
		if(!isValid(board, 0, 9, y, y+1) || !isValid(board, x, x+1, 0, 9) || !isValid(board, x/3*3,x/3*3+3,y/3*3,y/3*3+3))
		{
			board[x][y] = 0;
			return false;
		}
		board[x][y] = 0;
		return true;
	}
	
	public static void backtrack(int count, int[][] board)
	{
		if (canReture)
		{
			return;
		}
		if (count==81)
		{
			canReture = true;
			return;
			
		}
		int x = count / 9;
		int y = count % 9;
		if (board[x][y]==0)
		{
			for (int i=1; i<=9; i++)
			{
				if (canPutIn(board,x,y,i))
				{
					board[x][y] = i;
					backtrack(count+1, board);
					if (canReture)
					{
						return;
					}
				}
			}
			board[x][y] = 0;  // 回溯
		}
		else
		{
			backtrack(count+1, board);
		}
	}

	public void solveSudoku(int[][] board)
	{
		backtrack(0, board);
	}
	
	public static void main(String[] args)
	{
		int board[][] = {{0,0,9,7,4,8,0,0,0},
		                 {7,0,0,0,0,0,0,0,0},
		                 {0,2,0,1,0,9,0,0,0},
		                 {0,0,7,0,0,0,2,4,0},
		                 {0,6,4,0,1,0,5,9,0},
		                 {0,9,8,0,0,0,3,0,0},
		                 {0,0,0,8,0,3,0,2,0},
		                 {0,0,0,0,0,0,0,0,6},
		                 {0,0,0,2,7,5,9,0,0}};
		backtrack(0, board);
		
		for (int i=0; i<9; i++)
		{
			for (int j=0; j<9; j++)
			{
				System.out.print(board[i][j] + " ");
			}
			System.out.println();
		}
		
	}
}
