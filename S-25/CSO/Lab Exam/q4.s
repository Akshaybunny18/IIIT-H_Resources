.section .text
.global function

function:
    # rdi=2D arr, rsi=m, rdx=n
    pushq %rbp
    movq %rsp, %rbp

    imulq %rsi, %rdx
    movq %rdx, %r8
    movq $0, %r9
    movq $0, %r10 # sum
    xorq %rdx, %rdx

    loop:
        cmpq %r9, %r8
        jle end

        movq (%rdi, %r9, 8), %r11 # arr[i][j]

        rem5:
            movq $5, %r12
            movq %r11, %rax
            cqto
            idivq %r12
            cmpq $0, %rdx
            je next

        rem3:
            movq $3, %r12
            movq %r11, %rax
            cqto
            idivq %r12
            cmpq $0, %rdx
            jne next
            addq %r11, %r10 # sum+=arr[i][j]

    next:
        incq %r9
        jmp loop

    end:
        movq %r10, %rax # return sum
        popq %rbp
        ret
