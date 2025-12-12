.section .text
.global majority

majority:
    # rdi=arr pointer, rsi=n
    pushq %rbp # push base pointer
    movq %rsp, %rbp # new stack pointer

    movq $0, %r8 # count=0
    movq $-1, %r9 # majelt=-1
    movq $0, %r10 # i=0

    loop:
        cmpq %rsi, %r10 # compare i and n
        jge end # if i >= n, exit loop

        movq (%rdi, %r10, 8), %r11 # r11=arr[i]
        cmpq $0, %r8 # check if count == 0
        je set # if count==0
        cmpq %r9, %r11 # compare majelt and arr[i]
        je countinc # if arr[i]==majelt

        decq %r8 # else decrement count
        jmp next

    set:
        movq %r11, %r9 # majelt=arr[i]
        incq %r8 # count++
        jmp next

    countinc:
        incq %r8 # count++
        jmp next

    next:
        incq %r10 # i++
        jmp loop

    end:
        movq %r9, %rax # return majelt
        popq %rbp # pop base pointer
        ret
