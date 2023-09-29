#include "ltdl.h"
#include "pch.h"

int lt_dlopenext(const char* filename)
{
    return 0;
}

const char* ltdl_error()
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