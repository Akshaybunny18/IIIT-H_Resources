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
        local input1="$1"
        local expected_output="$2"
        local points="$3"
        
        # Increment test count
        test_count_1=$((test_count_1 + 1))
        
        # Provide the inputs to the program and capture the output
        output=$(echo "$input1 $input2" | ./main)
        
        # Remove any trailing newline from the output
        output=$(echo "$output" | tr -d '\n')
        
        # Check if the output matches the expected output
        if [ "$output" = "$expected_output" ]; then
            echo "Result: PASS for Problem 1, Test Case $test_count_1"
            total_score_1=$((total_score_1 + points))
        else
            echo "Result: FAIL for Problem 1, Test Case $test_count_1"
            echo "Expected: $expected_output, Got: $output"
        fi
        echo "------------------------------"
    }

    # Test cases with expected outputs and points
    run_test_1 "145
791 19 406 505 896 79 670 398 198 880 581 639 364 131 519 503 245 924 640 438
255 966 333 783 335 954 189 541 719 863 219 778 360 168 479 562 345 338 884 209" 10000101101 5
    run_test_1 "391
22 211 188 73 65 99 28 376 27 265 853 448 590 406 552 541 840 336 608 758
355 506 302 20 221 807 511 852 977 163 996 368 694 761 917 50 16 840 883 252" 10011011100 5
    run_test_1 "662
987 150 886 520 862 993 766 416 596 541 729 583 122 707 235 526 389 771 714 981
115 822 191 494 146 415 31 494 531 201 203 104 759 18 32 362 251 832 172 797" 11001110111 5
    run_test_1 "319
237 733 244 110 448 678 964 717 98 769 144 645 817 179 163 932 320 983 858 93
458 768 599 830 879 461 555 827 427 476 935 2 720 10 849 418 641 435 918 536" 10100010110 5

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
    run_test_2 "2
1 2
3 4" 1 10
    run_test_2 "3
1 3 1
4 -1 2
3 4 5" 3 10

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
        output=$(echo "$output" | tr -d '\n')
        
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
    run_test_3 "4 4
67 97 82 61
30 35 36 48
28 51 21 62
16 74 100 7" 322 10
    run_test_3 "3 3
69 6 62
48 39 50
84 26 94" 234 10


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