# c++ dynamic assertion and exception base

assertion.h
- this implements c++ dynamic_assertion. its behavior can be controled by compile option, DEFINE_ASSERT_MODE and DEFINE_ASSERT_LEVEL. DEFINE_ASSERT_MODE specifies assertion mode where dynamic assert a) throws an exception, b) terminates program and do coredump, or c) is ignored. By specifying DEFINE_ASSERT_LEVEL, a developer can selectively en/disable dynamic assertion. In addition, in source code, the dynamic assertion is flexiable enough for a developer can adjust assert level in a source code.

exception.h
- this implements base class for generic exception where debugging information can be included automatically
