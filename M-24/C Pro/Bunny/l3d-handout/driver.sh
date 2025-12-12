#!/usr/bin/bash
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


# Compile the code for problem 2
cd p1
echo "Compiling p1, main.c"
(make clean; make)
status1=$?
if [ ${status1} -ne 0 ]; then
    echo "Failure: Unable to compile main.c (return status = ${status1})"
    total_score_1=0
else 
    run_test_1() {
        local input_file="$1"
        local expected_output_file="$2"
        local points="$3"

        # Increment test count
        test_count_1=$((test_count_1 + 1))

        # Read input and expected output from files
        input1=$(cat "$input_file")
        expected_output=$(cat "$expected_output_file")
        echo $pwd
        # Provide the inputs to the program and capture the output
        output=$(echo "$input1" | ./main)

        # Remove any trailing newline from the output
        output=$(echo "$output")
        echo "running test cases for p1"

        # Check if the output matches the expected output
        if [ "$output" = "$expected_output" ]; then
            echo "Test Case $test_count_1 PASSED"
            total_score_1=$((total_score_1 + points))
        else
            echo "Test Case $test_count_1 FAILED"
            # echo "Expected: $expected_output"
            # echo "Got: $output"
        fi
        echo "--------------------"
    }

    echo "Problem 1 Test Cases Running"
    echo "--------------------"

    # Folder where test cases are stored
    tests_folder="testsp1"

    # Number of test cases
    num_tests=2
    i=0
    # Loop through all test cases
    while [ "$i" -lt $num_tests ];
    do
        input_file="../$tests_folder/input$i.txt"
        echo " input file $input_file"
        output_file="../$tests_folder/output$i.txt"
        # points=100/$num_tests  # Points for each test case
        points=$(( 20 / num_tests ))
        # echo " points $points"
        # echo " running test for p1 hehehehehehh" 
        # add if condition to check if the file exists
        if [ -f "$input_file" ] && [ -f "$output_file" ]; then
            echo " running test for p1" 
            run_test_1 "$input_file" "$output_file" "$points"
            
        else
            if [ ! -f "$input_file" ]; then
                echo "Input file not found: $(realpath "$input_file")"
            fi
            if [ ! -f "$output_file" ]; then
                echo "Output file not found: $(realpath "$output_file")"
            fi
        fi
        i=$(( i + 1 ))

    done
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
    run_test_2() {
        local input_file="$1"
        local expected_output_file="$2"
        local points="$3"

        # Increment test count
        test_count_2=$((test_count_2 + 1))

        # Read input and expected output from files
        input1=$(cat "$input_file")
        expected_output=$(cat "$expected_output_file")
        # echo $pwd
        # Provide the inputs to the program and capture the output
        output=$(echo "$input1" | ./main)

        # Remove any trailing newline from the output
        output=$(echo "$output")

        # Check if the output matches the expected output
        if [ "$output" = "$expected_output" ]; then
            echo "Test Case $test_count_2 PASSED"
            total_score_2=$((total_score_2 + points))
        else
            echo "Test Case $test_count_2 FAILED"
            # echo "Expected: $expected_output"
            # echo "Got: $output"
            # diff <(echo "$output") <(echo "$expected_output")

        fi
        echo "--------------------"
    }

    echo "Problem 2 Test Cases Running"
    echo "--------------------"

    # Folder where test cases are stored
    tests_folder="testsp2"

    # Number of test cases
    num_tests=2
    i=0
    # Loop through all test cases
    while [ "$i" -lt $num_tests ];
    do
        input_file="../$tests_folder/input$i.txt"
        output_file="../$tests_folder/output$i.txt"
        # points=20/$num_tests  # Points for each test case
        points=$(( 20 / num_tests ))  # Points for each test case
        echo " points $points"

        if [ -f "$input_file" ] && [ -f "$output_file" ]; then
            echo " running test for p2"
            run_test_2 "$input_file" "$output_file" "$points"
        else
            if [ ! -f "$input_file" ]; then
                echo "Input file not found: $(realpath "$input_file")"
            fi
            if [ ! -f "$output_file" ]; then
                echo "Output file not found: $(realpath "$output_file")"
            fi
        fi
        i=$(( i + 1 ))

    done
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
        local n="$1"
        local arr="$2"
        local target="$3"
        local expected_output="$4"
        local points="$5"
        
        # Increment test count
        test_count_3=$((test_count_3 + 1))
        
        # Prepare the input string with all parameters
        input_str="$n $arr $target"
        
        # Provide the inputs to the program and capture the output
        output=$(echo "$input_str" | timeout 2s ./main)
        
        # Remove any trailing newline from the output
        output=$(echo "$output" | tr -d '\n')
        
        # Check if the output matches the expected output
        if [ $? -eq 124 ]; then
            echo "Test Case $test_count_3 FAILED"
            echo "Reason: Timeout after 2 seconds"
        else
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
        fi
        echo "------------------------------"
    }

    # Test cases with expected outputs and points
    run_test_3 5 "1 2 3 -1 5" 5 "0 3" 10
    run_test_3 4 "1 2 -1 4" 7 "-1 -1" 10


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
