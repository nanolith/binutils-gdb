/* This test file is part of GDB, the GNU debugger.

   Copyright 1995, 1999, 2003, 2004 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
 
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

   Please email any bugs, comments, and/or additions to this file to:
   bug-gdb@prep.ai.mit.edu  */

/* This file is exactly like compiler.c.  I could just use compiler.c if
   I could be sure that every C++ compiler accepted extensions of ".c".  */

set compiler_info "unknown"

#if defined (__GNUC__)
#if defined (__GNUC_PATCHLEVEL__)
/* Only GCC versions >= 3.0 define the __GNUC_PATCHLEVEL__ macro.  */
set compiler_info [join {gcc __GNUC__ __GNUC_MINOR__ __GNUC_PATCHLEVEL__} -]
#else
set compiler_info [join {gcc __GNUC__ __GNUC_MINOR__ "unknown"} -]
#endif
#endif

#if defined (__HP_cc)
set compiler_info [join {hpcc __HP_cc} -]
#endif

#if defined (__HP_aCC)
set compiler_info [join {hpacc __HP_aCC} -]
#endif

/* gdb.base/whatis.exp still uses this */
#if defined (__STDC__) || defined (_AIX)
set signed_keyword_not_used 0
#else
set signed_keyword_not_used 1
#endif
