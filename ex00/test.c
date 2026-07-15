#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void		ft_putchar(char c);
void		ft_putstr(char *str);
int			ft_strcmp(char *s1, char *s2);
int			ft_strlen(char *str);
void		ft_swap(int *a, int *b);

enum
{
	READ_END,
	WRITE_END
};

typedef struct s_capture
{
	int		pipe_fds[2];
	int		stdout_backup;
	char	buf[1024];
	ssize_t	len;
}			t_capture;

void	setup(t_capture *c)
{
	c->stdout_backup = dup(STDOUT_FILENO);
	pipe(c->pipe_fds);
	dup2(c->pipe_fds[WRITE_END], STDOUT_FILENO);
}

void	teardown(t_capture *c)
{
	close(c->pipe_fds[WRITE_END]);
	dup2(c->stdout_backup, STDOUT_FILENO);
	c->len = read(c->pipe_fds[READ_END], c->buf, sizeof(c->buf) - 1);
	c->buf[c->len] = '\0';
	close(c->pipe_fds[READ_END]);
}

void	test_putchar(void)
{
	t_capture	c;

	setup(&c);
	ft_putchar('x');
	teardown(&c);
	assert(0 == strcmp("x", c.buf));
}

void	test_putstr(void)
{
	t_capture	c;

	setup(&c);
	ft_putstr("simon");
	teardown(&c);
	assert(0 == strcmp("simon", c.buf));
}

void	test_strcmp(void)
{
	assert((strcmp("simon", "str") ^ ft_strcmp("simon", "str")) > 0);
	assert((strcmp("", "str") ^ ft_strcmp("", "str")) > 0);
	assert((strcmp("simon", "") ^ ft_strcmp("simon", "")) > 0);
	assert(strcmp("", "") == ft_strcmp("", ""));
	assert(strcmp("simon", "simon") == ft_strcmp("simon", "simon"));
}

void	test_strlen(void)
{
	assert(strlen("simon") == ft_strlen("simon"));
	assert(strlen("") == ft_strlen(""));
}

void	test_swap(void)
{
	int	a;
	int	b;

	a = 10;
	b = 42;
	ft_swap(&a, &b);
	assert(42 == a);
	assert(10 == b);
}

int	main(void)
{
	test_putchar();
	test_putstr();
	test_strcmp();
	test_strlen();
	test_swap();
}
