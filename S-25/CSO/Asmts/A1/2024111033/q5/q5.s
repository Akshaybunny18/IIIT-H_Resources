.section .text
.global prodarr

prodarr:
    #rdi=arr, rsi=n, rdx=prod
    pushq %rbp
    movq %rsp, %rbp
    
    movq %rdx, %r13  # Save result array pointer in r13
    
    movq $0, %r8     # i=0
    movq $0, %r9     # zerocount=0
    movq $1, %r10    # prod=1

    loop1:
        cmpq %rsi, %r8 #compare n with i
        jge end1 #if i>=n end loop

        movq (%rdi, %r8, 8), %r11 #x=arr[i]
        cmpq $0, %r11 #compare x with 0
        je nextzero #if x=0 then jump to nextzero
        
        imulq %r11, %r10 #prod*=x
        jmp nextprod # Skip zero counter increment
    
    nextzero:
        incq %r9 #zerocount++

    nextprod:
        incq %r8 #i++
        jmp loop1
    
    end1:
        movq $0, %r8 #i=0
        cmpq $0, %r9 #compare zerocount with 0
        je loop2 #if zerocount=0 then jump to loop2
        cmpq $1, %r9 #compare zerocount with 1
        je loop3 #if zerocount=1 then jump to loop3
        jmp loop4 #if zerocount>1 then jump to loop4

    loop2:
        cmpq %rsi, %r8 #compare n with i
        jge end2 #if i>=n end loop

        movq (%rdi, %r8, 8), %r11 #x=arr[i]
        
    division:
        movq %r10, %rax # Move product to RAX (dividend)
        cqto # Sign-extend RAX into RDX:RAX
        idivq %r11 # RAX = quotient, RDX = remainder
        movq %rax, (%r13, %r8, 8) # Use r13 instead of rdx!
        
    next2:
        incq %r8 #i++
        jmp loop2
    end2:
        jmp return

    loop3:
        cmpq %rsi, %r8 #compare n with i
        jge end3 #if i>=n end loop

        # Fix result array access - using r13 instead of rdx
        movq (%rdi, %r8, 8), %r11 #r11 = arr[i]
        cmpq $0, %r11 #compare arr[i] with 0
        je zero_element # if arr[i]==0, it gets prod
        
        movq $0, (%r13, %r8, 8) # Use r13 instead of rdx!
        jmp next3
        
    zero_element:
        movq %r10, (%r13, %r8, 8) # Use r13 instead of rdx!
    next3:
        incq %r8 #i++
        jmp loop3
    end3:
        jmp return

    loop4:
        cmpq %rsi, %r8 #compare n with i
        jge end4 #if i>=n end loop

        movq $0, (%r13, %r8, 8) # Use r13 instead of rdx!
        jmp next4
    next4:
        incq %r8 #i++
        jmp loop4
    end4:
        jmp return
    
    return:
        popq %rbp
        ret
