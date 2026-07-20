#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	**ft_split(char *str, char *charset);

void	test_invalid(void)
{
	char	**result;

	result = ft_split(" simon", " ");
	assert(NULL == result);
}

void	test_two_sep(void)
{
	char	**result;

	result = ft_split(" simon ", " ");
	assert(NULL != result);
	assert(0 == strcmp("simon", result[0]));
	assert(NULL == result[1]);
	free(result[0]);
	free(result);
}

void	test_three_sep(void)
{
	char	**result;

	result = ft_split(" simon lau ", " ");
	assert(NULL != result);
	assert(0 == strcmp("simon", result[0]));
	assert(0 == strcmp("lau", result[1]));
	assert(NULL == result[2]);
	free(result[0]);
	free(result[1]);
	free(result);
}

int	main(void)
{
	test_invalid();
	test_two_sep();
	test_three_sep();
}
