.section .text
.global fun

fun:
    # rdi=n
    pushq %rbp
    movq %rsp, %rbp

    movq $0, %r8
    movq %rdi, %r9

    loop:
        cmpq $0, %r9
        jle end

        movq %r9, %rax
        movq $10, %r10
        cqto
        idivq %r10
        movq %rax, %r9
        movq $1, %r11 # fact=1
        movq %rdx, %r12
        movq $1, %r13 # i=1
        fact:
            cmpq %r12, %r13
            jg endfact

            imulq %r13, %r11
            incq %r13
            jmp fact
        endfact:
            addq %r11, %r8
    jmp loop
    end:
        cmpq %r8, %rdi
        jne endfalse
        movq $1, %rax
        popq %rbp
        ret

    endfalse:
        movq $0, %rax
        popq %rbp
        ret
