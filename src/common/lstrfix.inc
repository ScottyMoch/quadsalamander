#include <windows.h>
#include <string.h>

#include "lstrfix.h"

// potlaceni warningu C4996: This function or variable may be unsafe. Consider using strcat_s instead.
// duvod: lstrcat a dalsi Windows rutiny prost nejsou safe, takze to nema smysl resit tady
#pragma warning(push)
#pragma warning(disable:4996)

LPSTR _sal_lstrcpyA(LPSTR lpString1, LPCSTR lpString2)
{
  return strcpy(lpString1, lpString2);
}

LPWSTR _sal_lstrcpyW(LPWSTR lpString1, LPCWSTR lpString2)
{
  return wcscpy(lpString1, lpString2);
}

LPSTR _sal_lstrcpynA(LPSTR lpString1, LPCSTR lpString2, int iMaxLength)
{
  LPSTR ret;
  LPSTR end;
  if (iMaxLength <= 0) return lpString1;
  ret = lpString1;
  end = lpString1 + iMaxLength - 1;
  while (lpString1 < end && *lpString2 != 0)
    *lpString1++ = *lpString2++;
  *lpString1 = 0;
  return ret;
}

LPWSTR _sal_lstrcpynW(LPWSTR lpString1, LPCWSTR lpString2, int iMaxLength)
{
  LPWSTR ret;
  LPWSTR end;
  if (iMaxLength <= 0) return lpString1;
  ret = lpString1;
  end = lpString1 + iMaxLength - 1;
  while (lpString1 < end && *lpString2 != 0)
    *lpString1++ = *lpString2++;
  *lpString1 = 0;
  return ret;
}

int _sal_lstrlenA(LPCSTR lpString)
{
  if (lpString == NULL) return 0;
  return (int)strlen(lpString);
}

int _sal_lstrlenW(LPCWSTR lpString)
{
  if (lpString == NULL) return 0;
  return (int)wcslen(lpString);
}

LPSTR _sal_lstrcatA(LPSTR lpString1, LPCSTR lpString2)
{
  return strcat(lpString1, lpString2);
}

LPWSTR _sal_lstrcatW(LPWSTR lpString1, LPCWSTR lpString2)
{
  return wcscat(lpString1, lpString2);
}

#pragma warning(pop)



#ifdef LSTRFIX_WITHOUT_RTL

// When building small utils with default CRT libs ignored, provide
// our own implementations and disable intrinsic expansion so MSVC
// allows us to define these names.
#pragma function(strlen, wcslen, strcpy, wcscpy, strcat, wcscat)

// musel jsem si od MS pujcit implementace strlen, wcslen, strcpy, wcscpy, strcat a wcscat
// protoze se zde ignoruji default-liby, kde jsou tyto funkce umistene
size_t __cdecl strlen (
        const char * str
        )
{
        const char *eos = str;

        while( *eos++ ) ;

        return( eos - str - 1 );
}

size_t __cdecl wcslen (
        const wchar_t * wcs
        )
{
        const wchar_t *eos = wcs;

        while( *eos++ ) ;

        return( (size_t)(eos - wcs - 1) );
}

char * __cdecl strcpy(char * dst, const char * src)
{
        char * cp = dst;

        while( *cp++ = *src++ )
                ;               /* Copy src over dst */

        return( dst );
}

wchar_t * __cdecl wcscpy(wchar_t * dst, const wchar_t * src)
{
        wchar_t * cp = dst;

        while( *cp++ = *src++ )
                ;               /* Copy src over dst */

        return( dst );
}

char * __cdecl strcat (
        char * dst,
        const char * src
        )
{
        char * cp = dst;

        while( *cp )
                cp++;                   /* find end of dst */

        while( *cp++ = *src++ ) ;       /* Copy src to end of dst */

        return( dst );                  /* return dst */

}

wchar_t * __cdecl wcscat (
        wchar_t * dst,
        const wchar_t * src
        )
{
        wchar_t * cp = dst;

        while( *cp )
                cp++;                   /* find end of dst */

        while( *cp++ = *src++ ) ;       /* Copy src to end of dst */

        return( dst );                  /* return dst */

}

// #elif defined(COMPILING_SALOPEN)
#elif COMPILING_SALOPEN

//#error inside COMPILING_SALOPEN defined for lstrfix.include 'file';
#pragma message("inside COMPILING_SALOPEN defined for lstrfix.inc include 'file'")

extern "C" size_t __cdecl strlen(const char* str);
#pragma intrinsic(strlen)
#pragma function(strlen)
size_t __cdecl strlen(
    const char* str)
{
    const char* eos = str;

    while (*eos++)
        ;

    return (eos - str - 1);
}

extern "C" size_t __cdecl wcslen(const wchar_t* str);
#pragma intrinsic(wcslen)
#pragma function(wcslen)
size_t __cdecl wcslen(
    const wchar_t* wcs)
{
    const wchar_t* eos = wcs;

    while (*eos++)
        ;

    return ((size_t)(eos - wcs - 1));
}

extern "C" char* __cdecl strcpy(char* dst, const char* src);
#pragma intrinsic(strcpy)
#pragma function(strcpy)
char* __cdecl strcpy(char* dst, const char* src)
{
    char* cp = dst;

    while (*cp++ = *src++)
        ; /* Copy src over dst */

    return (dst);
}

extern "C" wchar_t* __cdecl wcscpy(wchar_t* dst, const wchar_t* src);
#pragma intrinsic(wcscpy)
#pragma function(wcscpy)
wchar_t* __cdecl wcscpy(wchar_t* dst, const wchar_t* src)
{
    wchar_t* cp = dst;

    while (*cp++ = *src++)
        ; /* Copy src over dst */

    return (dst);
}

extern "C" char* __cdecl strcat(char* dst, const char* src);
#pragma intrinsic(strcat)
#pragma function(strcat)
char* __cdecl strcat(
    char* dst,
    const char* src)
{
    char* cp = dst;

    while (*cp)
        cp++; /* find end of dst */

    while (*cp++ = *src++)
        ; /* Copy src to end of dst */

    return (dst); /* return dst */
}

extern "C" wchar_t* __cdecl wcscat(wchar_t* dst, const wchar_t* src);
#pragma intrinsic(wcscat)
#pragma function(wcscat)
wchar_t* __cdecl wcscat(
    wchar_t* dst,
    const wchar_t* src)
{
    wchar_t* cp = dst;

    while (*cp)
        cp++; /* find end of dst */

    while (*cp++ = *src++)
        ; /* Copy src to end of dst */

    return (dst); /* return dst */
}

#else

//#error compiling lstrfix.inc with lstrfix_without_rtl NOT defined or COMPILING_SALOPEN NOT defined
#pragma message("******** compiling lstrfix.inc with lstrfix_without_rtl NOT defined or COMPILING_SALOPEN NOT defined")

#endif // LSTRFIX_WITHOUT_RTL
