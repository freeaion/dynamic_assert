/* -------------------------------------------------------------------------
* assertion.h: implement dynamic assertion
*
* Copyright 2016 by Yonghyun Hwang <freeaion@gmail.com>
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.  Some rights reserved.
* -------------------------------------------------------------------------*/
#ifndef ASSERTION_H
#define ASSERTION_H

#include <cstddef>
#include <string>
#include <iostream>

#include "exception.h"

#define ASSERT_MESSAGE(MESG) ERROR_MESSAGE(MESG)

enum class AssertMode : uint8_t {
   THROW_     = 0,
   TERMINATE_ = 1,
   IGNORE_    = 2
};

// DEFINE_ASSERT_MODE comes from -Doption
constexpr AssertMode CURRENT_MODE = DEFINE_ASSERT_MODE;
constexpr uint8_t DEFAULT_LEVEL = 1;

constexpr bool assert_level(uint8_t n)
{
   // DEFINE_ASSERT_LEVEL should come from -Doption
   return (n <= DEFINE_ASSERT_LEVEL);
}

template<bool cond = assert_level(DEFAULT_LEVEL),
         typename Exception = ExceptionBase>
void dynamic_assert(bool assertion,
                    const std::string & mesg = "dynamic assertion failed",
                    int errorCode = 0)
{
   if (assertion) return ;

   switch(CURRENT_MODE) {
   case AssertMode::THROW_:
      throw Exception(mesg, errorCode);

   case AssertMode::TERMINATE_:
      std::cerr << mesg << std::endl;
      std::terminate();

   case AssertMode::IGNORE_:
      return ;
   }
}

template<>
void dynamic_assert<false, ExceptionBase>(bool, const std::string &, int) { }

void dynamic_assert(bool b, const std::string & mesg)
{
   dynamic_assert<true>(b, mesg);
}

void dynamic_assert(bool b)
{
   dynamic_assert<true>(b);
}

#endif // ASSERTION_H
