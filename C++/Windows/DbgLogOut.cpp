#include <tchar.h>
#include <stdio.h>
#include <Windows.h>

#pragma warning(disable:4996) 

// Dbg Log Output

// simple Text method
#define LOG_T(format, ...) \
 do { _tprintf(_T("[TEST][%s][%s:%d:%s]") _T(format), _T(__TIME__), \
        _T(__FILE__), __LINE__, _T(__FUNCTION__), ##__VA_ARGS__); \
 } while(0);

// freopen("D:\\MyLog.txt", "ab", stdout);

// DbgView method
void printDbgview(const TCHAR *format, ...)
{
    TCHAR buf[1024];

    va_list args;
    va_start(args, format);
    wvsprintf(buf, format, args);
    va_end(args);

    OutputDebugString(buf);
}

#define LOG_D(format, ...) \
 printDbgview(_T("[TEST][%s][%s:%d:%s] ") _T(format), _T(__TIME__), \
    _T(__FILE__), __LINE__, _T(__FUNCTION__), ##__VA_ARGS__)


void test_DbgLogOut()
{
    freopen("D:\\MyLog.txt", "ab", stdout);
    LOG_T("test text output.\n");
    fflush(stdout);

    LOG_D("test dbgview output");
}