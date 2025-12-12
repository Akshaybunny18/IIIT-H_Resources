.section .text
.global fun

fun:
    # rdi=arr pointer, rsi=n, rdx=freq arr pointer
    pushq %rbp
    movq %rsp, %rbp

    movq (%rdi), %r8 # min=arr[0]
    movq $0, %r9 # i=0

    loop1:
        cmpq %rsi, %r9
        jge end1

        movq $0, (%rdx, %r9, 8) # freq[i]=0
        movq (%rdi, %r9, 8), %r10 # x=arr[i]

        cmpq %r8, %r10
        jg next1
        movq %r10, %r8 # min=x

    next1:
        incq %r9
        jmp loop1
    
    end1:
        movq $0, %r9

    loop2:
        cmpq %rsi, %r9
        jge end2

        movq (%rdi, %r9, 8), %r10 # x=arr[i]
        subq %r8, %r10 # x=x-min

        incq (%rdx, %r10, 8) # freq[x]++

    next2:
        incq %r9
        jmp loop2

    end2:
        movq $0, %r9 # i=0

    loop3:
        cmpq %rsi, %r9
        jge endtrue

        movq (%rdx, %r9, 8), %r10 # freq[i]
        cmpq $1, %r10
        jne endfalse

    next3:
        incq %r9
        jmp loop3

    endtrue:
        movq $1, %rax # return 1
        popq %rbp
        ret

    endfalse:
        movq $0, %rax # return 0
        popq %rbp
        ret
