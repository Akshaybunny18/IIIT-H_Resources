.section .text
.global function

function:
    # rdi=n, rsi=arr pointer
    pushq %rbp
    movq %rsp, %rbp

    movq $0, %r8 # i=0
    loop:
        cmpq %rdi, %r8 # i vs n
        jge end # end if i>=n

        movq %r8, %r9 
        incq %r9
        
        movq %r9,(%rsi,%r8,8) # arr[i]=i+1

        rem2:
            movq $2, %r10
            movq %r9, %rax
            cqto
            idivq %r10
            cmpq $0, %rdx
            jne rem7
            movq $-1, (%rsi,%r8,8) # arr[i]=-1

        rem7:
            movq $7, %r10
            movq %r9, %rax
            cqto
            idivq %r10
            cmpq $0, %rdx
            jne next
            movq $-2, (%rsi,%r8,8) # arr[i]=-2

        rem14:
            movq $14, %r10
            movq %r9, %rax
            cqto
            idivq %r10
            cmpq $0, %rdx
            jne next
            movq $-3, (%rsi,%r8,8) # arr[i]=-3
    
    next:
        incq %r8 # i++
        jmp loop # repeat

    end:
        movq %rsi, %rax
        popq %rbp
        ret
