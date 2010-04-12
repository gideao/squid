#ifndef SQUID_CONFIG_H
#include "config.h"
#endif

#ifndef SQUID_OS_LINUX_H
#define SQUID_OS_LINUX_H

#ifdef _SQUID_LINUX_

/****************************************************************************
 *--------------------------------------------------------------------------*
 * DO *NOT* MAKE ANY CHANGES below here unless you know what you're doing...*
 *--------------------------------------------------------------------------*
 ****************************************************************************/


#if USE_ASYNC_IO
#define _SQUID_LINUX_THREADS_
#endif

/*
 * res_init() is just a macro re-definition of __res_init on Linux (Debian/Ubuntu)
 */
#if !defined(HAVE_RES_INIT) && defined(HAVE___RES_INIT) && !defined(res_init)
#define res_init  __res_init
#define HAVE_RES_INIT  HAVE___RES_INIT
#endif


/*
 * sys/capability.h is only needed in Linux apparently.
 *
 * HACK: LIBCAP_BROKEN Ugly glue to get around linux header madness colliding with glibc
 */
#if HAVE_SYS_CAPABILITY_H

#if LIBCAP_BROKEN
#undef _POSIX_SOURCE
#define _LINUX_TYPES_H
#define _LINUX_FS_H
typedef uint32_t __u32;
#endif

#include <sys/capability.h>
#endif /* HAVE_SYS_CAPABILITY_H */


#endif /* _SQUID_LINUX_ */
#endif /* SQUID_OS_LINUX_H */