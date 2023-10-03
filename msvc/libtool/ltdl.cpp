#include "ltdl.h"
#include "pch.h"
#include <stdio.h>
#include <windows.h>
#include <comdef.h>
#include <filesystem>

#include <algorithm>
#include <fstream>
#include <iostream>


extern "C" lt_dlhandle lt_dlopenext(const char* filename)
{
    size_t wn = mbsrtowcs(NULL, &filename, 0, NULL);

    wchar_t* buf = new wchar_t[wn + 1]();  // value-initialize to 0 (see below)
    wn = mbsrtowcs(buf, &filename, wn + 1, NULL);

    auto handle = LoadLibrary(buf);
    delete[] buf;
    return handle;
}

extern "C" const char* lt_dlerror()
{
    return "";
}

extern "C" int lt_dlforeachfile(const char* search_path, int(*func)(const char* filename, void* data), void* data)
{
    
    for (const auto& dirEntry : std::filesystem::recursive_directory_iterator(search_path))
    {
        auto pathStr = dirEntry.path().native().c_str();
        
        if (dirEntry.path().extension() == ".dll")
        {
            _bstr_t b(pathStr);
            const char* c = b;
            func(c, data);
        }
    }
       
    return 0;
}

extern "C" void* lt_dlsym(lt_dlhandle handle, char* functionName)
{
    return GetProcAddress(handle, functionName);
}

extern "C" int lt_dlclose(lt_dlhandle handle)
{
    FreeLibrary(handle);
    return 0;
}
extern "C" void lt_dlinit()
{

}

extern "C" void lt_dlexit()
{

}

extern "C" void lt_dladdsearchdir(const char* searchdir)
{
}

extern "C" void gpi_libltdl_lock()
{
}

extern "C" void gpi_libltdl_unlock()
{
}
