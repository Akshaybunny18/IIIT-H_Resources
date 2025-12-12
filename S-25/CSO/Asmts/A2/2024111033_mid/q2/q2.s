.section .text
.global ncr

ncr:
    #rdi=n, rsi=r
    pushq %rbp #push base pointer
    movq %rsp, %rbp #new stack pointer

    cmpq $0,%rsi #compare r with 0
    je edge #jump to edgecase if r=0
    jne continue #else continue

    edge:
        movq $1,%rax #move 1 to rax
        popq %rbp #pop base pointer
        ret

    continue:
        decq %rdi #n--
        decq %rsi #r--

        call ncr #ncr(n-1,r-1)

        incq %rdi #n++
        incq %rsi #r++

    ncr_end:
        movq %rax,%rcx #store result in rcx
        movq %rdi,%rax #move n to rax
        imulq %rcx,%rax #n*result
        cqto #convert rax to rdx:rax
        idivq %rsi #n*result/r
        popq %rbp #pop base pointer
        ret
