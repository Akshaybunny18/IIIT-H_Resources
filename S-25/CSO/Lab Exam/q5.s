.section .text
.global unq

unq:
    # rdi=arr pointer, rsi=n, rdx=result array pointer
    pushq %rbp
    movq %rsp, %rbp

    movq $0, %r8 # size=0
    movq $0, %r9 # i=0
    movq (%rdi), %r10 # prev=arr[0]

    movq %r10, (%rdx) # result[0] = arr[0]
    incq %r8

    loop:
        cmpq %r9, %rsi
        jle end

        movq (%rdi, %r9, 8), %r11
        cmpq %r10, %r11
        je next
        movq %r11, (%rdx, %r8, 8)
        incq %r8
        movq %r11, %r10

    next:   
        incq %r9
        jmp loop

    end:
        movq %r8, %rax
        popq %rbp
        ret
