#include "ls.h"

void    files_init(t_files *v)
{
	if (!v)
		return (NULL);
	v->data = NULL;
	v->len = 0;
	v->cap = 0;
}
int     files_push(t_files *v, t_file f);         // 0 = ok, -1 = erreur malloc
void    files_free(t_files *v);                   // libère name/path de chaque case, puis data
void    files_sort(t_files *v, t_opts *opts);     // qsort avec le bon comparateur