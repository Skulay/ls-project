#ifndef LS_H
#define LS_H

#include 

typedef struct s_file
{
	char		*name;
	char		*path;
	struct stat	st;
}	t_file;

typedef struct s_files
{
	t_file	*data;
	size_t	len;
	size_t	cap;
}	t_files;

void	files_init(t_files *v);
int		files_push(t_files *v, t_file f);
void	files_free(t_files *v);
void	files_sort(t_files *v, t_opts *opts);

#endif