#include <list.h>

void	lst_destroy(void *sentinel)
{
	t_list	*it;
	t_list	*tmp;

	it = ((t_list *)sentinel)->next;
	while (it != sentinel)
	{
		tmp = it;
		it = it->next;
		if (tmp->destructor)
			(*tmp->destructor)(tmp->data);
		free(tmp);
	}
	free(((t_list *)sentinel)->size);
	free(sentinel);
}
