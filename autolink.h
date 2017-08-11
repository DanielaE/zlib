#if defined(_MSC_VER) && !defined(ZLIB_BUILD_DLL)

#pragma once

#ifndef ZLIB_TOOLSET
#if (_MSC_VER >= 1910)
#define ZLIB_TOOLSET "vc141"
#elif (_MSC_VER >= 1900)
#define ZLIB_TOOLSET "vc140"
#elif (_MSC_VER >= 1800)
#define ZLIB_TOOLSET "vc120"
#elif (_MSC_VER >= 1700)
#define ZLIB_TOOLSET "vc110"
#elif (_MSC_VER >= 1600)
#define ZLIB_TOOLSET "vc100"
#elif (_MSC_VER >= 1500)
#define ZLIB_TOOLSET "vc90"
#endif
#endif

#ifndef ZLIB_PREFIX
#ifdef ZLIB_DLL
#define ZLIB_PREFIX "zlib"
#else
#define ZLIB_PREFIX "libzlib"
#endif
#endif

#ifndef ZLIB_API_POSTFIX
#ifdef ZLIB_WINAPI
#define ZLIB_API_POSTFIX "wapi"
#else
#define ZLIB_API_POSTFIX
#endif
#endif

#ifndef ZLIB_THREAD_OPT
#if defined(_MT) || defined(__MT__)
#  define ZLIB_THREAD_OPT "-mt"
#else
#  define ZLIB_THREAD_OPT
#endif
#endif

#ifndef ZLIB_RT_OPT
#ifndef NDEBUG
#define ZLIB_RT_OPT "-gd"
#else
#define ZLIB_RT_OPT
#endif
#endif

#if defined(ZLIB_PREFIX) \
      && defined(ZLIB_TOOLSET) \
      && defined(ZLIB_THREAD_OPT) \
      && defined(ZLIB_RT_OPT) \
      && defined(ZLIB_VERSION)

#  pragma comment(lib, ZLIB_PREFIX ZLIB_API_POSTFIX "-" ZLIB_TOOLSET ZLIB_THREAD_OPT ZLIB_RT_OPT "-" ZLIB_VERSION ".lib")
#endif

#endif
