#include "ltdl.h"
#include "pch.h"

int lt_dlopenext(const char* filename)
{
    return 0;
}

const char* lt_dlerror()
{
    return "";
}

int lt_dlforeachfile(const char* search_path, int(*func)(const char* filename, void* data), void* data)
{
    return 0;
}

void* lt_dlsym(lt_dlhandle handle, char* functionName)
{


}

int lt_dlclose(lt_dlhandle handle)
{
    return 0;
}

void lt_dlinit()
{

}

void lt_dlexit()
{

}

void lt_dladdsearchdir(const char* searchdir)
{
}

void gpi_libltdl_lock()
{
}

void gpi_libltdl_unlock()
{
}
