# !/bin/bash
# driver.sh - The simplest autograder we could think of. It checks
#   that students can write a C program that compiles, and then
#   executes with an exit status of zero.
#   Usage: ./driver.sh
# Initialize total score
total_score_1=0
total_score_2=0
total_score_3=0
max_score=60
test_count_1=0
test_count_2=0
test_count_3=0
# Compile the code
cd p1
echo "Compiling p1, main.c"
(make clean; make)
status1=$?
if [${status1} != 0] ; then
    echo "Failure: Unable to compile main.c (return status = ${status1})"
    total_score_1=0
else 
    # Run the code for problem 1, test cases
    run_test_1() {
        local input1="$1"
        local input2="$2"
        local input3="$3"
        local input4="$4"
        local expected_output="$5"
        local points="$6"
        
        # Increment test count
        test_count_1=$((test_count_1 + 1))
        
        # Provide the inputs to the program and capture the output
        output=$(echo "$input1\n$input2\n$input3\n$input4" | ./main)
        
        # Remove any trailing newline from the output
        output=$(echo "$output" | tr -d '\n')


        

        
        # Check if the output matches the expected output
        if [ "$output" = "$expected_output" ]; then
            echo "Result: PASS for p1"
            total_score_1=$((total_score_1 + points))
        else
            echo "Result: FAIL for p1"
        fi
        echo "-------------------------"
    }

    # Test cases with expected outputs and points
    run_test_1  1 7 3 3 1 10
    run_test_1  7 7 7 7 3 10



    
    
fi
# test cases
# Function to run the program with given input and expected output for problem 1



cd ../p2
echo "Compiling p2, main.c"
(make clean; make)
status2=$?
if  [${status2} != 0] ; then
    echo "Failure: Unable to compile main.c (return status = ${status2})"
    total_score_2=0
else 
    # Function to run the program with given input and expected output for problem 2
    run_test_2() {
        local input1="$1"
        local input2="$2"
        local expected_output="$3"
        local points="$4"
        
        # Increment test count
        test_count_2=$((test_count_2 + 1))
        
        # Provide the inputs to the program and capture the output
        output=$(echo  "$input1\n$input2" | ./main)
        
        # Remove any trailing newline from the output
        output=$(echo "$output" | tr -d '\n')
        
        # Print the inputs and the output
        
        # Check if the output matches the expected output
        if [ "$output" = "$expected_output" ]; then
            echo "Result: PASS for prob_2, test case $input1 $input2"
            total_score_2=$((total_score_2 + points))
        else
            echo "Result: FAIL for prob_2, test case $input1 $input2"
        fi
        echo "-------------------------"
    }
    # Test cases with expected outputs and points
    run_test_2 6 2 "NO" 10
    run_test_2 11 5 "YES" 10



fi

cd ../p3
echo "Compiling p3, main.c"
(make clean; make)
status3=$?
if  [${status3} != 0] ; then
    echo "Failure: Unable to compile main.c (return status = ${status3})"
    total_score_3=0
else 
    # Function to run the program with given input and expected output for problem 2
    run_test_3() {
        local input1="$1"
        local expected_output="$2"
        local points="$3"
        
        # Increment test count
        test_count_3=$((test_count_3 + 1))
        
        # Provide the inputs to the program and capture the output
        output=$(echo  "$input1\n" | ./main)
        
        # Remove any trailing newline from the output
        output=$(echo "$output" | tr -d '\n')

        # Print the inputs and the output
        
        # Check if the output matches the expected output
        if [ "$output" = "$expected_output" ]; then
            echo "Result: PASS for p3, test case $input1"
            total_score_3=$((total_score_3 + points))
        else
            echo "Result: FAIL for p3, test case $input1"
        fi
        echo "-------------------------"
    }
    # Test cases with expected outputs and points
    run_test_3 "23:24:23" "11:24:23 PM" 10
    run_test_3 "11:24:23" "11:24:23 AM" 10
fi

total_score=$((total_score_1 + total_score_2+total_score_3))
# Calculate percentage score
percentage=$((total_score * 100 / max_score))

# Print the total score
echo "Total Score: $total_score / $max_score"
echo "Percentage: $percentage%"

echo "Success: ./p1, ./p2 ./p3 runs with an exit status of 0 for test case-0"
echo "{\"scores\": {\"p1\": $total_score_1, \"p2\": $total_score_2, \"p3\": $total_score_3}}" # "Prob1": 10, "Prob2": 5



exit
