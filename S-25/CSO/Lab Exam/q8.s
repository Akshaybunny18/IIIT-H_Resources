.section .text
.global fun

fun:
    # rdi=arr pointer, rsi=n
    pushq %rbp
    movq %rsp, %rbp

    movq $0, %r8 # i=0
    bsout:
        cmpq %r8, %rsi
        jle bsend

        movq $0, %r9 # j=0
        movq %rsi, %r10 # k=n
        decq %r10 # k=n-1
        subq %r8, %r10 # k=n-1-i

        bsin:
            cmpq %r9, %r10
            jle bsnext

            movq (%rdi, %r9, 8), %r11 # x=arr[j]
            incq %r9
            movq (%rdi, %r9, 8), %r12 # y=arr[j+1]
            decq %r9

            cmpq %r11, %r12
            jge bsinnext
            movq %r12, (%rdi, %r9, 8) # arr[j]=y
            incq %r9
            movq %r11, (%rdi, %r9, 8)
            decq %r9

        bsinnext:
            incq %r9
            jmp bsin
    
    bsnext:
        incq %r8
        jmp bsout
    
    bsend:
        movq $0, %r8
        movq %rsi, %r9
        decq %r9

    swaploop:  
        cmpq %r8, %r9
        jle end

        movq (%rdi, %r8, 8), %r11
        incq %r8
        movq (%rdi, %r8, 8), %r12
        decq %r8
        movq %r12, (%rdi, %r8, 8)
        incq %r8
        movq %r11, (%rdi, %r8, 8)
        decq %r8

        incq %r8
        incq %r8
        jmp swaploop
    
    end:
        movq %rdi, %rax
        popq %rbp
        ret
