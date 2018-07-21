#ifndef RUBY_MJIT_CONFIG_H
#define RUBY_MJIT_CONFIG_H 1

#define MJIT_MIN_HEADER_NAME "/include/ruby-2.6.0/x86_64-darwin17/rb_mjit_min_header-2.6.0.h"
#define MJIT_CC_COMMON   "clang",
#define MJIT_CFLAGS      "-w",
#define MJIT_OPTFLAGS    "-O3",
#define MJIT_DEBUGFLAGS  "-ggdb3",
#define MJIT_LDSHARED    "clang", "-dynamic", "-bundle",
#define MJIT_DLDFLAGS    "-Wl,-undefined,dynamic_lookup", "-Wl,-multiply_defined,suppress",
#define MJIT_LIBS        "-lruby.2.6",

#endif /* RUBY_MJIT_CONFIG_H */
