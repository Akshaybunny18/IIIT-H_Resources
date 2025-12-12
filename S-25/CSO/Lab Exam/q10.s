.section .text
.global fun

fun:
    # rdi=n, rsi=string pointer, rdx=stack pointer
    pushq %rbp
    movq %rsp, %rbp

    movq $-1, %r8 # top
    movq $0, %r9 # i

    loop:
        cmpq %r9, %rdi
        jle endtrue

        movb (%rsi, %r9, 1), %cl
        cmpb $40, %cl
        je addtostack
        cmpb $91, %cl
        je addtostack
        cmpb $123, %cl
        je addtostack

        cmpb $41, %cl
        je round
        cmpb $93, %cl
        je square
        cmpb $125, %cl
        je curly

        addtostack:
            incq %r8
            movb %cl, (%rdx, %r8, 1)
            jmp next

        round:
            cmpq $-1, %r8
            je endfalse
            movb (%rdx, %r8, 1), %bl
            cmpb $40, %bl
            jne endfalse
            decq %r8
            jmp next

        square:
            cmpq $-1, %r8
            je endfalse
            movb (%rdx, %r8, 1), %bl
            cmpb $91, %bl
            jne endfalse
            decq %r8
            jmp next

        curly: 
            cmpq $-1, %r8
            je endfalse
            movb (%rdx, %r8, 1), %bl
            cmpb $123, %bl
            jne endfalse
            decq %r8
            jmp next

    next:   
        incq %r9
        jmp loop

    endtrue:
        movq $1, %rax
        popq %rbp
        ret
    
    endfalse:
        movq $0, %rax
        popq %rbp
        ret
