.global swap

swap:
    movq (%rdi), %rax # t0 = *a
    movq (%rsi), %rdx # t1 = *b
    movq %rdx, (%rdi) # *a = t1
    movq %rax, (%rsi) # *b = t0
    ret
