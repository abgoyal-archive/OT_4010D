#if !defined(_LINUX_XLOG_H)
#define _LINUX_XLOG_H

#include <linux/linkage.h>

enum android_log_priority {
	ANDROID_LOG_UNKNOWN = 0,
	ANDROID_LOG_DEFAULT,    /* only for SetMinPriority() */
	ANDROID_LOG_VERBOSE,
	ANDROID_LOG_DEBUG,
	ANDROID_LOG_INFO,
	ANDROID_LOG_WARN,
	ANDROID_LOG_ERROR,
	ANDROID_LOG_FATAL,
	ANDROID_LOG_SILENT,     /* only for SetMinPriority(); must be last */
};

#define LOGGER_ALE_ARGS_MAX 16

struct ale_convert {
    const char *tag_str;
    const char *fmt_ptr;
    unsigned int hash;
    char params[LOGGER_ALE_ARGS_MAX];
};

struct xlog_record {
	const char *tag_str;
	const char *fmt_str;
	int prio;
};

#if defined(HAVE_ALE_FEATURE)

int __xlog_ale_printk(int prio, const struct ale_convert *convert, ...);

#define xlog_printk(prio, tag, fmt, ...)				\
  ({									\
	  static const struct ale_convert ____xlogk_ale_rec____ =	\
		  { tag, fmt, prio, "" };				\
	  __xlog_ale_printk(prio, &____xlogk_ale_rec____,		\
			    ##__VA_ARGS__);				\
  })

#else

asmlinkage int __xlog_printk(const struct xlog_record *rec, ...);

#define xlog_printk(prio, tag, fmt, ...)				\
	({								\
		static const struct xlog_record _xlog_rec =		\
			{tag, fmt, prio};				\
		__xlog_printk(&_xlog_rec, ##__VA_ARGS__);		\
	})

#endif

#endif
