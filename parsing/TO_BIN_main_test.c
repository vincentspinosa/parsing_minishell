//#include "../minishell.h" // decomment after code sync
#include "parsing.h"

int	main(int ac, char **av, char **envp)
{
	t_token	***array;
	t_state	*state;

	if (ac != 2)
		return (0);
	array = malloc(sizeof(t_token **));
	state = malloc(sizeof(t_state));
	state->exit_code = 999;
	state->env = &(*(envp));
	array = parseline(state, av[1]);
	if (array)
		print_main_array(array);
	else
		printf("Array is NULL");
	//destroy_gc(&(state->gc));
	return (0);
}

// pour compiler : cc -W... *.c libft/*.c

// ex fonctionnels :
// ./a.out "echo aaa << HELLO | cat e"
// ./a.out "echo aaa << HELLO | cat e | grep a >> outfile"
// ./a.out "sleep 10 | sleep 10"
// ./a.out "sleep 10 | sleep 10 | sleep 10 | echo a a a a a"
// ./a.out '"e""rr""eee" | "e""ee""eee"'
// ./a.out "'e''rr''eee' | 'e''ee''eee'"
// ./a.out "sleep 10 | sleep 10 | sleep 10 | sleep 10 | sleep 10"
// ./a.out "sleep 10 | sleep 10 | sleep 10 | sleep 10 | sleep 10               "
// ./a.out "echo a | sleep 1 | echo >> LIMITER < aaa << bbb << a"
// ./a.out "echo $LANG"
// ./a.out "echo a|sleep 1|echo>>LIMITER<aaa<<bbb<<a"

//ex non fonctionnels :
// plupart des ex avec variables, mais il faut tester sur linux