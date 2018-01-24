#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data);
int ft_list_push_back(t_list **begin_list, void *data);
int ft_list_size(t_list *begin_list);
int ft_putnbr(int nb);
t_list *ft_list_last(t_list *begin_list);
t_list	*ft_list_push_params(int ac, char **av);
void	ft_list_clear(t_list **begin_list);

int		check_list(t_list *list)
{
	int i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

void	print(t_list *list)
{
	if (list == NULL)
		printf("ksks");
	while (list)
	{
		printf("%s\n", list->data);
		list = list->next;
	}
}

int main()
{
	t_list *list;

	list = NULL;
	ft_list_push_back(&list, "tata");
	ft_list_push_front(&list, "toto");
	ft_list_push_back(&list, "blop");
	//ft_putnbr(ft_list_size(list));
	print(list);
	//ft_list_last(list);
	//printf("%s\n", ft_list_last(list)->data);
	//print(ft_list_push_params(ac, av));
	//ft_list_clear(&list);
	//print(list);
	return (0);
	
}

