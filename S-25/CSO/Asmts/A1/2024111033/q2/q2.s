.section .text
.global rotateby2

rotateby2:
    # rdi = arr pointer, rsi = n (length)
    pushq %rbp #push base pointer
    movq %rsp, %rbp #new stack pointer
    
    movq %rsi,%r8 #i = n
    movq %rsi,%r9 #y=n
    
    subq $1,%r9 #y=y-1
    movq (%rdi,%r9,8),%r10 #temp1=arr[y]

    subq $1,%r9 #y=y-1
    movq (%rdi,%r9,8),%r11 #temp2=arr[y]

    subq $3,%r8 #i=i-3

    loop:
        cmpq $0,%r8 #compare i with 0
        jl end #end if i<0
        
        leaq 2(%r8),%r12 #z=i+2
        movq (%rdi,%r8,8),%r13 #a=arr[i]
        movq %r13,(%rdi,%r12,8) #arr[z]=a

    next:
        decq %r8 #i--
        jmp loop

    end:
        movq %r11,(%rdi) #arr[0]=temp1
        movq %r10,8(%rdi) #arr[1]=temp2
        movq %rdi,%rax #move arr pointer to rax for returning
        pop %rbp #pop base pointer
        ret
