#include <stdio.h>
#include <windows.h>


typedef HINSTANCE lt_dlhandle;
typedef void* lt_ptr;

#ifdef __cplusplus
extern "C"
{
#endif
	lt_dlhandle lt_dlopenext(const char* filename);

	const char* ltdl_error();

	void* lt_dlsym(lt_dlhandle handle, char* functionName);

	int lt_dlclose(lt_dlhandle handle);

	int	    lt_dlforeachfile(
		const char* search_path,
		int (*func) (const char* filename, void* data),
		void* data);


	void lt_dlinit();

	void lt_dlexit();

	void lt_dladdsearchdir(const char*);

	void gpi_libltdl_lock();

	void gpi_libltdl_unlock();
#ifdef __cplusplus
}
#endif

