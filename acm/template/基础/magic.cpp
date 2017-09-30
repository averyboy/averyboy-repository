#pragma comment(linker, "/STACK:102400000,102400000")   //C++手动扩栈

int size = 256 << 20; // 256MB  			//G++手动扩栈
    char *p = (char*)malloc(size) + size;  
    __asm__("movl %0, %%esp\n" :: "r"(p));

std::ios::sync_with_stdio(false)			//cin关闭同步
