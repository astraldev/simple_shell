/*
* Created by ifiokekott on 8/6/22.
*/
#include "_pow_recursion.h"

int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	return (x * _pow_recursion(x, y - 1));
}
