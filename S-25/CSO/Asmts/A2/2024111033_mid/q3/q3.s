.section .text
.global nextgrelt

nextgrelt:
    # rdi=arr pointer, rsi=n, rdx=result array pointer, rcx=stack array pointer
    pushq %rbp # push base pointer
    movq %rsp, %rbp # new stack pointer

    movq $-1,%r8 # top = -1
    movq $0,%r9 # i=0
    movq %rdx,%r10 # result array pointer to r10
    movq %rdi,%r11 # arr pointer to r11

    setloop:
        cmpq %rsi,%r9 # compare i with n
        jge endset # if i >= n, exit loop

        movq $-1,(%r10,%r9,8) # set result[i] to -1

        incq %r9 # i++
        jmp setloop # jump to set loop

    endset:
        movq %rsi,%r9 # i = n
        decq %r9 # i = n - 1
        jmp loop # jump to main loop

    loop:
        cmpq $0,%r9 # check if i < 0
        jl endloop # if i < 0, exit loop

        whileloop:
            cmpq $-1,%r8 # check if top == -1
            je endwhile # if top == -1, exit while loop
            
            movq (%rcx,%r8,8),%r12 # get stack[top]
            movq (%r11,%r9,8),%r13 # get arr[i]
            cmpq %r13,%r12 # compare stack[top] with arr[i]
            jg endwhile # if stack[top] > arr[i], exit while loop
            
            decq %r8 # (top)--
            jmp whileloop # continue checking
            
        endwhile:
            cmpq $-1,%r8 # check if top == -1
            je push # if top == -1, skip to push (result[i] already set to -1)
            
            movq (%rcx,%r8,8),%r12 # get stack[top]
            movq %r12,(%r10,%r9,8) # result[i] = stack[top]
            
        push:
            incq %r8 # ++(top)
            movq (%r11,%r9,8),%r13 # get arr[i]
            movq %r13,(%rcx,%r8,8) # stack[top] = arr[i]

        decq %r9 # i--
        jmp loop # jump to main loop
        
    endloop:
        movq %rdx,%rax # return result array pointer
        popq %rbp # restore base pointer
        ret
