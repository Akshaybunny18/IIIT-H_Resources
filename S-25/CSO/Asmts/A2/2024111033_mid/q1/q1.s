.section .text
.global subzero

subzero:
    # rdi = arr pointer, rsi=n
    pushq %rbp #push base pointer
    movq %rsp, %rbp #new stack pointer

    movq $0,%rax #count=0
    movq $1,%r9 #i=1

    outerloop:
        cmpq %rsi,%r9 #compare i and n
        jg outerend #end if i>n

        movq $0,%rcx #sum=0
        movq $0,%r10 #j=0
        sumloop:
            cmpq %r9,%r10 #compare j with i
            jge sumend #end if j>=i

            leaq (%rdi,%r10,8),%r8
            addq (%r8),%rcx #sum+=arr[j]
            incq %r10 #j++
            jmp sumloop
        sumend:
            cmpq $0,%rcx #compare sum with 0
            jne innersetting
            incq %rax #count++
            movq %r9,%r10 #j=i

        innersetting:
            movq %r9,%r10 #j=i

        innerloop:
            cmpq %rsi,%r10 #compare j with n
            jge innerend

            movq %r10,%r11 #x=j
            subq %r9,%r11 #x=j-i
            leaq (%rdi,%r11,8),%rbx #a=arr[j-i]
            subq (%rbx),%rcx #sum-=a
            leaq (%rdi,%r10,8),%r8 #sum+=arr[j]
            addq (%r8),%rcx

            cmpq $0,%rcx #compare sum with 0
            jne innernext
            incq %rax #count++

        innernext:
            incq %r10 #j++
            jmp innerloop
        innerend:
    outernext:
        incq %r9 #i++
        jmp outerloop
    outerend:
        popq %rbp #pop base pointer
        ret
