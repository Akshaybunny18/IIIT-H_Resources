.section .text
.global fun

fun:
    # rdi=arr pointer, rsi=n, rdx=stack pointer, rcx=result array pointer
    pushq %rbp
    movq %rsp, %rbp

    movq $-1, %r8 # top
    movq $0, %r9 # i

    loop:
        cmpq %rsi, %r9
        jge end

        while:
            cmpq $-1, %r8
            je wend
            movq (%rdi, %r9, 8), %r10 # arr[i]
            movq (%rdx, %r8, 8), %r11 # stack[top]
            cmpq %r10, %r11
            jg wend
            decq %r8 # top--
            jmp while
        
        wend:
            cmpq $-1, %r8
            jne elsecon
            movq $-1, (%rcx, %r9, 8) # result[i] = -1
            jmp next
        
        elsecon:
            movq (%rdx, %r8, 8), %r10 # stack[top]
            movq %r10, (%rcx, %r9, 8) # result[i] = stack[top]
            jmp next

    next:
        incq %r8
        movq (%rdi, %r9, 8), %r10 # arr[i]
        movq %r10, (%rdx, %r8, 8) # stack[top] = arr[i]
        incq %r9
        jmp loop

    end:
        movq %rcx, %rax
        popq %rbp
        ret
