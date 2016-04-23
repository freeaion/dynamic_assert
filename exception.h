/* -------------------------------------------------------------------------
 * exception.h: implement base class for exception
 *
 * Copyright 2016 by Yonghyun Hwang <freeaion@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.  Some rights reserved.
 * -------------------------------------------------------------------------*/
#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <stdexcept>
#include <iostream>
#include <string>

#define STRINGFY(TOKEN) STRINGFY_TOKEN(TOKEN)
#define STRINGFY_TOKEN(TOKEN) #TOKEN

#define SOURCE_CODE_INFO_STRING                             \
   std::string(__func__) +                                  \
   std::string("@" __FILE__ ":" STRINGFY(__LINE__))

#ifdef NDEBUG // debug build or not
#  define ERROR_MESSAGE(MESG) std::string(MESG)
#else
#  define ERROR_MESSAGE(MESG) SOURCE_CODE_INFO_STRING \
   + std::string("::") + std::string(MESG)
#endif

class ExceptionBase : public std::runtime_error
{
public:
   ExceptionBase(const std::string & rMsg,
                 const int code) :
      runtime_error(rMsg),
      mErrCode(code) { }

   const int code(void) const { return mErrCode; }
   const void print(void) const {
      std::cerr << "error_code[" << mErrCode << "]|"
                << this->what() << std::endl;
   }

protected:
   int mErrCode;
};

#endif // EXCEPTION_H
