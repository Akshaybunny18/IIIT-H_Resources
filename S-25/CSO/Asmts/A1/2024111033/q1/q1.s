.section .text
.global findunique

findunique:
    # rdi = arr pointer, rsi = 3*n+1 (length), rdx = freq arr pointer
    pushq %rbp #push base pointer
    movq %rsp, %rbp #new stack pointer
    
    movq $0,%r8 #i=0

    loop1:
        cmpq %rsi,%r8 #compare 3*n+1 with i
        jge end1 #end if i>=3*n+1

        movq (%rdi,%r8,8),%r9 #x=arr[i]
        incq (%rdx,%r9,8) #freq[arr[i]]++

    next1:
        incq %r8 #i++
        jmp loop1

    end1:
        movq $0,%r8 #i=0

    loop2:
        cmpq $100001,%r8 #compare i with 100001
        jge end2 #if i>=100001 end loop

        cmpq $1,(%rdx,%r8,8) #compare freq[i] with 1
        je found #if freq[i]=1 then jump to found

    next:
        incq %r8 #i++
        jmp loop2

    end2:
        movq $-1,%rax #return -1
        jmp return
    found:
        movq %r8,%rax #return i

    return:
        popq %rbp #pop base pointer
        ret
