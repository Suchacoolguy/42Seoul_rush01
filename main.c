#ifndef UNISTD_H
#define UNISTD_H
#include <unistd.h>
#endif

int		g_board[4][4];
int		g_row_height[4][4];
int		g_col_height[4][4];
int		g_condition[16];
int		g_shift[4];
int		*g_ptr[16];

int		make_case1(int row, int col);

void	print_board(void)
{
	int i;
	int j;
	char height;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 3)
		{
			height = g_board[i][j] + '0';
			write(1, &height, 1);
			write(1, " ", 1);
			j++;
		}
		height = g_board[i][j] + '0';
		write(1, &height, 1);
		write(1, "\n", 1);
		i++;
	}
}


void	inish(void)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		g_ptr[i] = &g_board[0][i];
		g_ptr[i + 4] = &g_board[3][i];
		g_ptr[i + 8] = &g_board[i][0];
		g_ptr[i + 12] = &g_board[i][3];
		j = 0;
		while (j < 4)
		{
			g_row_height[i][j] = 1;
			g_col_height[i][j] = 1;
			j++;
		}
		i++;
	}
	g_shift[0] = 4;
	g_shift[1] = -4;
	g_shift[2] = 1;
	g_shift[3] = -1;
}

int		is_space(char c)
{
	return (c == '\f' || c == '\n' || c == '\r' || c == '\v' || c == '\t' || c == ' ');
}

int		make_condition(char *str)
{
	int count;

	count = 0;
	while (*str)
	{
		while (is_space(*str))
			str++;
		if (*str >= '1' && *str <= '4')
		{
			if ((!is_space(*(str + 1)) && *(str + 1)) || count == 16)
				return (0);
			g_condition[count] = *str - '0';
			count++;
		}
		else
			return (0);
		str++;
	}
	if (count == 16)
		return (1);
	else
		return (0);
}

int		main(int argc, char **argv)
{
	inish();
	if (!(argc == 2 && make_condition(argv[1]) && make_case1(0,0)))
		write(1, "Error\n", 6);
	return (0);
}


