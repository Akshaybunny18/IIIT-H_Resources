#!/bin/bash
# driver.sh - A simple autograder script.
# Usage: ./driver.sh

# Initialize total scores
total_score_1=0
total_score_2=0
total_score_3=0
max_score=60
test_count_1=0
test_count_2=0
test_count_3=0

# Colors for pass/fail
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Compile the code for problem 1
# Compile the code for problem 1 
ls
cd p1/
echo "Compiling p1, main.c"
(make clean; make all)
status1=$?
if [ ${status1} -ne 0 ]; then
    echo "Failure: Unable to compile main.c (return status = ${status1})"
    total_score_1=0
else 
    # Run the code for problem 1 test cases
    run_test_1() {
        local input="$1"
        local expected_output="$2"
        local points="$3"
        
        # Increment test count
        test_count_1=$((test_count_1 + 1))
        
        # Provide the inputs to the program and capture the output
        output=$(echo "$input" | ./main)
        
        # Remove any trailing newline from the output
        output=$(echo "$output" | tr -d '\n')
        
        # Check if the output matches the expected output
        if [ "$output" = "$expected_output" ]; then
            echo -e "${GREEN}Result: PASS for Problem 1, Test Case $test_count_1${NC}"
            total_score_1=$((total_score_1 + points))
        else
            echo -e "${RED}Result: FAIL for Problem 1, Test Case $test_count_1${NC}"
            echo "Expected: $expected_output, Got: $output"
        fi
        echo "------------------------------"
    }

    # Test cases with expected outputs and points
    run_test_1 "3 2 1 2 3 4 5 6" "1 3 5 2 4 6 " 10
    run_test_1 "2 3 7 8 9 10 11 12" "7 10 8 11 9 12 " 10
    

fi

# Compile the code for problem 2
cd ../p2
echo "Compiling p2, main.c"
(make clean; make)
status2=$?
if [ ${status2} -ne 0 ]; then
    echo "Failure: Unable to compile main.c (return status = ${status2})"
    total_score_2=0
else 
    # Run the code for problem 2 test cases
    run_test_2() {
        local input1="$1"
        local expected_output="$2"
        local points="$3"
        
        # Increment test count
        test_count_2=$((test_count_2 + 1))
        
        # Provide the inputs to the program and capture the output
        output=$(echo "$input1 $input2 $input3" | ./main)
        
        # Remove any trailing newline from the output
        output=$(echo "$output" | tr -d '\n')
        
        # Check if the output matches the expected output
        if [ "$output" = "$expected_output" ]; then
            echo "Result: PASS for Problem 2, Test Case $test_count_2"
            total_score_2=$((total_score_2 + points))
        else
            echo "Result: FAIL for Problem 2, Test Case $test_count_2"
            echo "Expected: $expected_output, Got: $output"
        fi
        echo "-------------------------"
    }

    # Test cases with expected outputs and points

    run_test_2 "3
3 5 7" "7 13 15 " 10
run_test_2 "3 1 2 3" "3 0 7 " 10

fi

# Compile the code for problem 3
cd ../p3
echo "Compiling p3, main.c"
(make clean; make)
status3=$?
if [ ${status3} -ne 0 ]; then
    echo "Failure: Unable to compile main.c (return status = ${status3})"
    total_score_3=0
else 
    # Run the code for problem 1 test cases
    run_test_3() {
        local input1="$1"
        # local input2="$2"
        local expected_output="$2"
        local points="$3"
        
        # Increment test count
        test_count_3=$((test_count_3 + 1))
        
        # Provide the inputs to the program and capture the output
        output=$(echo "$input1 $input2" | ./main)
        
        # Remove any trailing newline from the output
        output=$(echo "$output" )
        # output=$(echo "$output" | tr -d '\n')
        
        # Check if the output matches the expected output
        if [ "$output" = "$expected_output" ]; then
            echo "Test Case $test_count_3 PASSED"
            total_score_3=$((total_score_3 + points))
        else
            echo "Test Case $test_count_3 FAILED"
            echo "Expected: $expected_output, Got: $output"
        fi
        echo "------------------------"
    }

    # Test cases with expected outputs and points
    run_test_3 "3 6
acf
abcdef" "YES" 10
    run_test_3 " 2 2
    ab
    cd " "NO" 10


fi


# Calculate total score and percentage
total_score=$((total_score_1 + total_score_2 + total_score_3))
percentage=$((total_score * 100 / max_score))

# Print the total score and percentage
echo "Total Score: $total_score / $max_score"
echo "Percentage: $percentage%"

echo "Success: ./p1, ./p2, ./p3 runs with an exit status of 0 for test cases."

echo "---------------------------------------------------------------------------------"

echo "{\"scores\": {\"p1\": $total_score_1, \"p2\": $total_score_2, \"p3\": $total_score_3}}"

exit