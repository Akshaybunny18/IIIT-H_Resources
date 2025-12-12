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
cd p1
echo "Compiling p1, main.c"
(make clean; make)
status1=$?
if [ ${status1} != 0 ]; then
    echo "Failure: Unable to compile p1/main.c (return status = ${status1})"
    total_score_1=0
else 
    # Run the code for problem 1, test cases
    run_test_1() {
        local input1="$1"
        local expected_output="$2"
        local points="$3"
        
        # Increment test count
        test_count_1=$((test_count_1 + 1))
        
        # Provide the input to the program and capture the output
        output=$(echo "$input1" | ./main)
        
        # Remove any trailing newline and extra spaces
        output=$(echo "$output" | tr -d '\n' | xargs)
        
        # Check if the output matches the expected output
        if [ "$output" = "$expected_output" ] ; then
            echo " ${GREEN} Result: PASS for p1 ${NC} "
            total_score_1=$((total_score_1 + points))
        else
            echo " ${RED} Result: FAIL for p1 ${NC} "
            echo "Output: $output"
        fi
        echo "-------------------------"
    }


    # Test cases with expected outputs and points
    run_test_1 "1 1 2 3" "6" 10
    run_test_1 "3 3 123 456" "56088" 10
fi

# Compile the code for problem 2
cd ../p2
echo "Compiling p2, main.c"
(make clean; make)
status2=$?
if [ ${status2} -ne 0 ]; then
    echo "Failure: Unable to compile p2/main.c (return status = ${status2})"
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
        output=$(echo "$input1" | ./main)
        
        # Remove any trailing newline from the output
        output=$(echo "$output" | tr -d '\n' | xargs)
        # output=$(echo "$output")
        
        # Check if the output matches the expected output
        # Check if the output matches the expected output
        if [ "$output" = "$expected_output" ] ; then
            echo  " ${GREEN} Result: PASS for p2 ${NC} "
            total_score_2=$((total_score_2 + points))
        else
            echo  " ${RED} Result: FAIL for p 2${NC} "
            echo "Output: $output"
        fi
        echo "-------------------------"
    }

    # Test cases with expected outputs and points
    run_test_2 "5 0 1 3 5 6" "3 0" 10
    run_test_2 "3 1 2 100" "2 1" 10
fi

# Compile the code for problem 3
cd ../p3
echo "Compiling p3, main.c"
(make clean; make)
status3=$?
if [ ${status3} -ne 0 ]; then
    echo "Failure: Unable to compile p3/main.c (return status = ${status3})"
    total_score_3=0
else 
    # Run the code for problem 1, test cases
    run_test_3() {
        local input1="$1"
        local expected_output="$2"
        local points="$3"
        
        # Increment test count
        test_count_3=$((test_count_3 + 1))
        # Provide the inputs to the program and capture the output

        output=$(echo "$input1" | ./main)

        # Remove any trailing newline from the output
        output=$(echo "$output" | tr -d '\n' | xargs)
        
       if [ "$output" = "$expected_output" ] ; then
            echo  " ${GREEN} Result: PASS for p3 ${NC} "
            total_score_3=$((total_score_3 + points))
        else
            echo  " ${RED} Result: FAIL for p3 ${NC} "
            echo "Output: $output"
        fi
        echo "------------------------------"
    }

    run_test_3 "61 56 1 41 5 1 45 10 2 33 2 30 1 16 20 1 36 33 1 46 67 2 55 2 5 2 31 1 40 86 2 21 1 55 71 1 51 69 1 50 75 2 7 1 40 64 2 24 1 60 93 2 48 1 35 27 2 16 1 61 97 2 19 2 55 2 1 2 3 1 21 54 2 4 1 23 76 1 55 92 2 27 2 2 1 29 38 2 25 2 23 1 31 68 2 38 1 18 11 1 1 97 1 7 58 2 41 1 7 13 1 39 71 1 60 6 1 35 52 1 53 5 1 22 96 2 46 2 41 1 60 3 1 48 74 1 18 23 2 26 2 11 2 49" "1 1 1 1 1 1 1 1 1 1 20 1 1 71 1 1 1 1 1 1 1 76 1 1 5 1 67 1 5 1 1 1" 20
    
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