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