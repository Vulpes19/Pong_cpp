#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char	*cal(char *num, int ndigits, int len, int n)
{
	int	ifneg;

	ifneg = 0;
	while (ndigits >= 0)
	{
		if (n < 0)
		{
			n *= -1;
			ifneg = 1;
		}
		num[ndigits] = n % 10 + '0';
		n /= 10;
		ndigits--;
	}
	if (ifneg)
		num[0] = '-';
	num[len] = '\0';
	return (num);
}

static int	ndigits(int n)
{
	int	count;

	count = 0;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		nd;
	int		len;

	if (n == -2147483648)
		return (strdup("-2147483648"));
	nd = ndigits(n);
	len = nd;
	if (n == 0)
		return (strdup("0"));
	if (n < 0)
	{
		nd++;
		len++;
	}
	num = (char *)malloc(sizeof(char) * nd + 1);
	if (!num)
		return (NULL);
	nd -= 1;
	return (cal(num, nd, len, n));
}