#include "ls.h"

void	files_init(t_files *v)
{
	if (!v)
		return ;
	v->data = NULL;
	v->len = 0;
	v->cap = 0;
}
int     files_push(t_files *v, t_file f)
{
	size_t	new_cap;
	t_file *tmp;

	if (!v)
		return (-1);
	if (v->len == v->cap)
	{
		if (v->cap == 0)
			new_cap = 16;
		else
			new_cap = v->cap * 2;
		tmp = realloc(v->data, new_cap * sizeof(t_file));
		if (!tmp)
			return (-1);
		v->data = tmp;
		v->cap = new_cap;
	}
	v->data[v->len] = f;
	v->len++;
	return (0);
}

void    files_free(t_files *v);                   // libère name/path de chaque case, puis data
void    files_sort(t_files *v, t_opts *opts);     // qsort avec le bon comparateur
