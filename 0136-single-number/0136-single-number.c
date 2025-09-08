int singleNumber(int* nums, int numsSize) {
    int result  = 0, i =0;

    __asm__ volatile (
        "mov %0 , %%eax;"
        "mov %[i] , %%edx;" // use named variable
        "1:\n\t"
        "cmp %%esi ,%%eax;"
        "jge 2f;"
        "mov (%%rdi, %%rax ,4) ,%%rcx;"
        "xor %%ecx , %%edx;"
        "inc %%eax;"
        "jmp 1b;"

        "2:\n\t"
        "mov %%edx , %0;" // start output to 0 1 2 3
        :"+r"(result) // =r (write) + read and write
        :[i]"r"(i), "D"(nums), "S"(numsSize) //named variable only read 
        : "rcx", "rdx", "memory");



    return result;  // here compiler will just use eax already
}
