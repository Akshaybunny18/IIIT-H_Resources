.section .text
.global score

score:
    # rdi=string
    pushq %rbp
    movq %rsp, %rbp

    movq $0,%r8 # score=0
    movq $1,%r9 # i=1

    loop:
        movb (%rdi, %r9,1),%bl
        cmpb $0,%bl
        je end
        
        movq %r9,%r11
        decq %r11
        movb (%rdi, %r11,1),%cl
        subb %cl,%bl
        cmpb $0,%bl
        jge adding
        negb %bl
    adding:
        movzbq %bl,%rbx
        addq %rbx,%r8

    next:
        incq %r9
        jmp loop
    
    end:
        movq %r8, %rax
        popq %rbp
        ret
