.section .text
.global function

function:
    # rdi=n
    pushq %rbp
    movq %rsp, %rbp

    movq %rdi, %r8 # n1=n
    movq $0, %r9 # m=0

    loop:
        cmpq $0, %r8 # 0 vs n1
        je end # end if n1=0

        movq %r8, %rax
        movq $10, %r10
        cqto
        idivq %r10 # rax= n1/10, rdx=n1%10
        movq %rax, %r8 # n1=n1/10
        imulq $10, %r9 # m*=10
        addq %rdx, %r9 # m+=n1%10

        jmp loop
    
    end:
        cmpq %r9, %rdi # m vs n
        je end1
        movq $0, %rax 
        popq %rbp
        ret
    end1:
        movq $1, %rax 
        popq %rbp
        ret
