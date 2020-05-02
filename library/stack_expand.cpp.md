---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../assets/css/copy-button.css" />


# :warning: stack_expand.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/stack_expand.cpp">View this file on GitHub</a>
    - Last commit date: 2016-12-08 00:51:38+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//#define BEGIN_STACK_EXTEND(size) void * stack_extend_memory_ = malloc(size);void * stack_extend_origin_memory_;char * stack_extend_dummy_memory_ = (char*)alloca((1+(int)(((long long)stack_extend_memory_)&127))*16);*stack_extend_dummy_memory_ = 0;asm volatile("mov %%rsp, %%rbx\nmov %%rax, %%rsp":"=b"(stack_extend_origin_memory_):"a"((char*)stack_extend_memory_+(size)-1024));
//#define END_STACK_EXTEND asm volatile("mov %%rax, %%rsp"::"a"(stack_extend_origin_memory_));free(stack_extend_memory_);
#include <bits/stdc++.h>
#define BEGIN_STACK_EXTEND(size) void *sem = malloc(size);void* seom;char* sedm = (char*)alloca((1+(int)(((long long)sem)&127))*16);*sedm = 0;asm volatile("mov %%esp, %%ebx\nmov %%eax, %%esp":"=b"(seom):"a"((char*)sem+(size)-1024));
#define END_STACK_EXTEND asm volatile("mov %%eax, %%esp"::"a"(seom));free(sem);
using namespace std;
int f(int x){
	if(x==0) return 0;
	return x^f(x-1);
}
int main(){
    BEGIN_STACK_EXTEND(128*1024*1024);

    //  メインの処理
    int x;
    cin>>x;
    cout<<f(x)<<endl;
 
    END_STACK_EXTEND;
    return 0;
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "stack_expand.cpp"
//#define BEGIN_STACK_EXTEND(size) void * stack_extend_memory_ = malloc(size);void * stack_extend_origin_memory_;char * stack_extend_dummy_memory_ = (char*)alloca((1+(int)(((long long)stack_extend_memory_)&127))*16);*stack_extend_dummy_memory_ = 0;asm volatile("mov %%rsp, %%rbx\nmov %%rax, %%rsp":"=b"(stack_extend_origin_memory_):"a"((char*)stack_extend_memory_+(size)-1024));
//#define END_STACK_EXTEND asm volatile("mov %%rax, %%rsp"::"a"(stack_extend_origin_memory_));free(stack_extend_memory_);
#include <bits/stdc++.h>
#define BEGIN_STACK_EXTEND(size) void *sem = malloc(size);void* seom;char* sedm = (char*)alloca((1+(int)(((long long)sem)&127))*16);*sedm = 0;asm volatile("mov %%esp, %%ebx\nmov %%eax, %%esp":"=b"(seom):"a"((char*)sem+(size)-1024));
#define END_STACK_EXTEND asm volatile("mov %%eax, %%esp"::"a"(seom));free(sem);
using namespace std;
int f(int x){
	if(x==0) return 0;
	return x^f(x-1);
}
int main(){
    BEGIN_STACK_EXTEND(128*1024*1024);

    //  メインの処理
    int x;
    cin>>x;
    cout<<f(x)<<endl;
 
    END_STACK_EXTEND;
    return 0;
};

```
{% endraw %}

<a href="../index.html">Back to top page</a>

