.section .text
.global binarysearch

binarysearch:
    # rdi=arr pointer, rsi=start, rdx=end, rcx=target
    pushq %rbp
    movq %rsp, %rbp

    movq %rsi, %r8 # start
    movq %rdx, %r9 # end

    cmpq %r8, %r9
    jl notfound

    addq %r8, %r9
    shrq $1, %r9 # mid = (start + end) / 2
    movq (%rdi, %r9, 8), %r10
    cmpq %r10, %rcx
    je found
    jg left
    jmp right

    left:
        decq %r9
        movq %r9, %rdx # end = mid - 1
        incq %r9
        call binarysearch
        jmp end

    right:
        incq %r9
        movq %r9, %rsi # start = mid + 1
        decq %r9
        call binarysearch
        jmp end

    found:
        movq %r9, %rax
        jmp end
    
    notfound:
        movq $-1, %rax

    end:
        popq %rbp
        ret
