#ifndef UNISTD_H
#define UNISTD_H
#include <unistd.h>
#endif

extern int		g_board[4][4];
extern int		g_row_height[4][4];
extern int		g_col_height[4][4];
extern int 		g_condition[16];
extern int		g_shift[4];
extern int		*g_str[16];

void	print_board(void);
int		make_case1(int row, int col);

int		is_valid2(int *ptr, int shift, int condition)
{
	int result;
	int i;
	int tmp;

	result = 0;
	i = 0;
	tmp = 0;
	while (i < 4)
	{
		if (*ptr > tmp)
		{
			tmp = *ptr;
			result++;
		}
		ptr = ptr + shift;
		i++;
	}
	if (result == condition)
		return (1);
	else
		return (0);
}

int		is_valid1(void)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if(!is_valid2(g_ptr[i], g_shift[i / 4], g_condition[i]))
			return (0);
		i++;
	}
	return (1);
}

int		make_case2(int row, int col)
{
	int height;

	height = 0;
		while (height < 4)
		{
			if (!(g_row_height[row][height] && g_col_height[col][height]))
			{
				height++;
				continue ;
			}
			g_row_height[row][height] = 0;
			g_col_height[col][height] = 0;
			g_board[row][height] = height + 1;
			if (make_case1(row, col + 1))
				return (1);
			g_row_height[row][height] = 1;
			g_col_height[col][height] = 1;
			height++;
		}
		return (0);
}

