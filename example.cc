#include "exception.h"
#include "assertion.h"

int main(void)
{
   try {
      dynamic_assert(true, ASSERT_MESSAGE("assertion true"));
   }
   catch(const ExceptionBase & e) {
      e.print();
   }

   try {
      dynamic_assert(false, ASSERT_MESSAGE("assertion false"));
   }
   catch(const ExceptionBase & e) {
      e.print();
   }

   try {
      dynamic_assert<assert_level(1)>(true, ASSERT_MESSAGE("assertion true w/ level 1"));
   }
   catch(const ExceptionBase & e) {
      e.print();
   }

   try {
      throw ExceptionBase(ERROR_MESSAGE("this is an exception test"), 10);
   }
   catch(const ExceptionBase & e) {
      e.print();
   }

   return 0;
}
