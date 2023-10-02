/** \file gphoto2-port-log.h
 *
 * Copyright 2001 Lutz Mueller <lutz@users.sf.net>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA  02110-1301  USA
 */



/************************************************************************
 * Begin Windows definitions (but not during WINE compilation)
 ************************************************************************/

# include <windows.h>
/* done by mingw/wine headers ... defined to struct ... tsaes*/
#undef interface
# include <sys/types.h>
# include <sys/stat.h>
# include <string.h>
# include <stdio.h>
# include <direct.h>

#pragma once

# define strcasecmp		_stricmp
# ifndef snprintf
#  define snprintf		_snprintf
# endif

#define __func__ __FUNCTION__

#ifndef _SSIZE_T_DEFINED
typedef SSIZE_T ssize_t;
#endif

/* Work-around for readdir() */
typedef struct {
	HANDLE handle;
	int got_first;
	WIN32_FIND_DATA search;
	char dir[1024];
	char drive[32][2];
	int  drive_count;
	int  drive_index;
} GPPORTWINDIR;


/* Directory-oriented functions */
# define gp_system_dir		  GPPORTWINDIR *
# define gp_system_dirent	  WIN32_FIND_DATA *
# define gp_system_dir_delim	  '\\'

# define sleep(x) usleep((x) * 1000 * 1000)






/************************************************************************
 * Begin platform independent portability functions
 ************************************************************************/

int		 gp_system_mkdir	(const char *dirname);
int              gp_system_rmdir        (const char *dirname);
gp_system_dir	 gp_system_opendir	(const char *dirname);
gp_system_dirent gp_system_readdir	(gp_system_dir d);
const char*	 gp_system_filename	(gp_system_dirent de);
int		 gp_system_closedir	(gp_system_dir dir);
int		 gp_system_is_file	(const char *filename);
int		 gp_system_is_dir	(const char *dirname);

/************************************************************************
 * End platform independent portability functions
*/

/* end of file */
