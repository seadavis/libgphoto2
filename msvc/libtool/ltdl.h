#include <stdio.h>
#include <windows.h>


typedef HINSTANCE lt_dlhandle;
typedef void* lt_ptr;

int lt_dlopenext(const char* filename);

const char* ltdl_error();

void* lt_dlsym(lt_dlhandle handle, char* functionName);

int lt_dlclose(lt_dlhandle handle);

int	    lt_dlforeachfile(
	const char* search_path,
	int (*func) (const char* filename, void* data),
	void* data);