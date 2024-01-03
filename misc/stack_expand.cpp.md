---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"misc/stack_expand.cpp\"\n//#define BEGIN_STACK_EXTEND(size)\
    \ void * stack_extend_memory_ = malloc(size);void * stack_extend_origin_memory_;char\
    \ * stack_extend_dummy_memory_ = (char*)alloca((1+(int)(((long long)stack_extend_memory_)&127))*16);*stack_extend_dummy_memory_\
    \ = 0;asm volatile(\"mov %%rsp, %%rbx\\nmov %%rax, %%rsp\":\"=b\"(stack_extend_origin_memory_):\"\
    a\"((char*)stack_extend_memory_+(size)-1024));\n//#define END_STACK_EXTEND asm\
    \ volatile(\"mov %%rax, %%rsp\"::\"a\"(stack_extend_origin_memory_));free(stack_extend_memory_);\n\
    #include <bits/stdc++.h>\n#define BEGIN_STACK_EXTEND(size) void *sem = malloc(size);void*\
    \ seom;char* sedm = (char*)alloca((1+(int)(((long long)sem)&127))*16);*sedm =\
    \ 0;asm volatile(\"mov %%esp, %%ebx\\nmov %%eax, %%esp\":\"=b\"(seom):\"a\"((char*)sem+(size)-1024));\n\
    #define END_STACK_EXTEND asm volatile(\"mov %%eax, %%esp\"::\"a\"(seom));free(sem);\n\
    using namespace std;\nint f(int x){\n\tif(x==0) return 0;\n\treturn x^f(x-1);\n\
    }\nint main(){\n    BEGIN_STACK_EXTEND(128*1024*1024);\n\n    //  \u30E1\u30A4\
    \u30F3\u306E\u51E6\u7406\n    int x;\n    cin>>x;\n    cout<<f(x)<<endl;\n \n\
    \    END_STACK_EXTEND;\n    return 0;\n};\n"
  code: "//#define BEGIN_STACK_EXTEND(size) void * stack_extend_memory_ = malloc(size);void\
    \ * stack_extend_origin_memory_;char * stack_extend_dummy_memory_ = (char*)alloca((1+(int)(((long\
    \ long)stack_extend_memory_)&127))*16);*stack_extend_dummy_memory_ = 0;asm volatile(\"\
    mov %%rsp, %%rbx\\nmov %%rax, %%rsp\":\"=b\"(stack_extend_origin_memory_):\"a\"\
    ((char*)stack_extend_memory_+(size)-1024));\n//#define END_STACK_EXTEND asm volatile(\"\
    mov %%rax, %%rsp\"::\"a\"(stack_extend_origin_memory_));free(stack_extend_memory_);\n\
    #include <bits/stdc++.h>\n#define BEGIN_STACK_EXTEND(size) void *sem = malloc(size);void*\
    \ seom;char* sedm = (char*)alloca((1+(int)(((long long)sem)&127))*16);*sedm =\
    \ 0;asm volatile(\"mov %%esp, %%ebx\\nmov %%eax, %%esp\":\"=b\"(seom):\"a\"((char*)sem+(size)-1024));\n\
    #define END_STACK_EXTEND asm volatile(\"mov %%eax, %%esp\"::\"a\"(seom));free(sem);\n\
    using namespace std;\nint f(int x){\n\tif(x==0) return 0;\n\treturn x^f(x-1);\n\
    }\nint main(){\n    BEGIN_STACK_EXTEND(128*1024*1024);\n\n    //  \u30E1\u30A4\
    \u30F3\u306E\u51E6\u7406\n    int x;\n    cin>>x;\n    cout<<f(x)<<endl;\n \n\
    \    END_STACK_EXTEND;\n    return 0;\n};"
  dependsOn: []
  isVerificationFile: false
  path: misc/stack_expand.cpp
  requiredBy: []
  timestamp: '2024-01-04 00:07:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/stack_expand.cpp
layout: document
redirect_from:
- /library/misc/stack_expand.cpp
- /library/misc/stack_expand.cpp.html
title: misc/stack_expand.cpp
---
