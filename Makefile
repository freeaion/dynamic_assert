# -------------------------------------------------------------------------
# Makefile: Top Builder
#
# Copyright 2016 by Yonghyun Hwang <freeaion@gmail.com>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.  Some rights reserved.
# -------------------------------------------------------------------------
# 06/03/2015 Yonghyun Hwang Initial version
#

# 0: list of source codes
#    - if specified, only those are compiled
#    - if not specified, all *.c, *.cpp, and *.cc will be compiled
SRCS           =

# 1: list of sub directories
#    - if specified,	do make recursively
SUB_DIRS	      =

# 2: list of compile options (-Ddefine, -Iinc, ...)
LOCAL_CXXFLAGS = -DDEFINE_ASSERT_MODE=AssertMode::THROW_ -DDEFINE_ASSERT_LEVEL=1
#LOCAL_CXXFLAGS = -DDEFINE_ASSERT_MODE=AssertMode::IGNORE_ -DDEFINE_ASSERT_LEVEL=0
#LOCAL_CXXFLAGS = -DDEFINE_ASSERT_MODE=AssertMode::TERMINATE_ -DDEFINE_ASSERT_LEVEL=0
LOCAL_CFLAGS   =

# 3: list of linker options (-lm, -Labc, ...)
LOCAL_LIB      =

# 4: library name
#    - specify this if you want to create	.so out of your SRCS
LIB_NAME       =

# 5: specify compiler
#    - if not specified, CC = gcc, CXX= g++
CC             =
CXX            =

# 6: specify dir w/ Makefile.rules in it
PRJ_ROOT_DIR  ?= .

# --------------------------------------------
# Magic part: please don't touch if you don't know what you are doing
# --------------------------------------------
include $(PRJ_ROOT_DIR)/Makefile.rules
$(eval $(call play_magic,$(EXE)))
