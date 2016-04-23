# c++ dynamic assertion and exception base

assertion.h
- this implements c++ dynamic_assertion. its behavior can be controled by a compile option, DEFINE_ASSERT_MODE and DEFINE_ASSERT_LEVEL. DEFINE_ASSERT_MODE specifies an assertion mode where dynamic assert a) throws an exception, b) terminates a program and do a coredump, or c) is ignored. By specifying DEFINE_ASSERT_LEVEL, a developer can selectively en/disable a dynamic assertion. In addition, the dynamic assertion is flexiable enough for a developer to adjust a assert level in a source code.

exception.h
- this implements a base class for a generic exception where debugging information can be included automatically
