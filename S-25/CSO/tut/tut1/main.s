.globl swap
swap:
    movq (%rdi), %rax # t0 = *xp 
    movq (%rsi), %rdx # t1 = *yp
    movq %rdx, (%rdi) # *xp = t1
    movq %rax, (%rsi) # *yp = t0
    ret
