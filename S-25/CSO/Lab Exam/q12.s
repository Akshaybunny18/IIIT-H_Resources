.section .text
.global fun

fun:
    # rdi=n, rsi=d
    pushq %rbp
    movq %rsp, %rbp

    cmpq $1, %rdi
    jle endfalse

    movq $1, %r8 # power=1
    movq $1, %r9 # i=1
    powerloop:
        cmpq %r9, %rsi # i<d
        jle endpow

        imulq $10, %r8 # power=power*10
        incq %r9 # i++
        jmp powerloop
    
    endpow:
        movq $0, %r9 # i=0

    loop:
        cmpq %rsi, %r9
        jge endtrue

        movq $2, %r10 # j=2
        prime:
            cmpq %r10, %rdi
            jle endprime

            movq %rdi, %rax
            cqto
            idivq %r10 # rax=dividend, rdx=divisor
            cmpq $0, %rdx # check if divisible
            je endfalse
            incq %r10 # j++
            jmp prime
        endprime:
            movq %rdi, %rax
            movq $10, %r11
            cqto
            idivq %r11
            movq %rax, %rdi # n=n/10
            imulq %r8, %rdx # rdx=power*remainder
            addq %rdx, %rdi # n=n+power*remainder
    next:
        incq %r9 # i++
        jmp loop
    
    endtrue:
        movq $1, %rax
        popq %rbp
        ret

    endfalse:
        movq $0, %rax
        popq %rbp
        ret
