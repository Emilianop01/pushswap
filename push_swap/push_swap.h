
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_list
{
	int			content;
	struct s_list	*next;
}					t_list;

typedef struct s_stack
{
	t_list	*head;
}	t_stack;

typedef struct s_duo
{
	t_stack a;
	t_stack b;
}	t_duo;

typedef struct s_rot
{
	int rab;
	int rra;
	int rrb;
	int rrab;
}	t_rot;

int	 lenarr(char **arr);
int	 checks(int argc, char **argv);
int	 checklist(t_duo *duo);
long	ftatoi(const char *num);
int	 isnumb(char *n);
int	 checkdup(t_duo *stack);
int	 checkorder(t_duo *duo);
int	 countw(char const *str);
int	 copiaw(const char *s, char **frase, int i, int l, int j);
char	**split(char const *str);
t_list	*findb(t_duo *duo, int node);
t_list	*finds(t_duo *duo);
t_list	*findtarg(t_duo *duo, int curr);
t_list	*findeco(t_duo *duo);
void	freequit(t_duo *stacks, int i);
void	freematrix(char **matrix);
void	sa(t_duo *stacks);
void	sb(t_duo *stacks);
void	ss(t_duo *stacks);
t_list	*ftlstlast(t_list *list);
void	rotate(t_list **list);
void	ra(t_duo *duo);
void	rb(t_duo *duo);
void	rr(t_duo *duo);
void	pb(t_duo *duo);
void	pa(t_duo *duo);
void	rrotate(t_list **list);
void	rra(t_duo *duo);
void	rrb(t_duo *duo);
void	rrr(t_duo *duo);
void	pushrab(t_duo *duo, int indexa, int indexb);
void	pushrrab(t_duo *duo, int diffa, int diffb);
void	pushrra(t_duo *duo, int diffa, int indexb);
void	pushrrb(t_duo *duo, int indexa, int diffb);
int	 listlen(t_list *head);
int	 magg(int a, int b);
int	 listindex(t_list *head, t_list *targ);
t_rot	calcrot(t_duo *duo, t_list *node, t_list *targ);
int	 bestrot(t_rot rot);
void	emptya(t_duo *duo);
void	pushnode(t_duo *duo, t_list *node, t_list *targ);
void	solve(t_duo *duo);
int	 countnode(t_duo *duo);
void	create_stack(t_duo *stack, char **argv, int argc);
void	appendnode(char **argv, t_duo *duo, int i, int argc);
t_list	*lstnew(int content);
void	addnodeb(t_list **list, t_list *new);
t_list	*lastn(t_list *list);
void	ordb(t_duo *duo, int len, int min, int index);
void	solvesmall(t_duo *duo, int i);
void	solve3(t_duo *duo);
void	solve35(t_duo *duo, int i);
void	solve45(int indexl, int indes, int i, t_duo *duo);
void	solve5(int indexl, int indexs, t_duo *duo);
int	 checklowest(t_duo *duo);
int	 checklowest2(t_duo *duo, int indexl);

#endif