#ifndef LS_H
#define LS_H

#include <sys/types.h>
#include <sys/stats.h>
#include <sys/sysmacros.h>
#include <dirent.h>
#include <pwd.h> // getpwuid
#include <grp.h> // getgrgid
#include <time.h>
#include <errno.h>
#include <string.h>

typedef struct s_opts
{
	int	l;
	int	R;
	int a;
	int r;
	int t;
}	t_opts;

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

// files
void	files_init(t_files *v);
int		files_push(t_files *v, t_file f);
void	files_free(t_files *v);
void	files_sort(t_files *v, t_opts *opts);

//opts
t_opts	new_opts(void);

#endif