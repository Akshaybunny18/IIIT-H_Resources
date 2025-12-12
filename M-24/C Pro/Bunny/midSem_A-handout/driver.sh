#!/usr/bin/bash
# driver.sh - A simple autograder script.
# Usage: ./driver.sh

# Initialize total scores
total_score_1=0
total_score_2=0
total_score_3=0
max_score=70
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

    # Read expected output from file
    expected_output=$(cat "$expected_output_file")

    # Run the program with a time limit of 1 second and capture time stats using the built-in 'time' command
    # 'time' doesn't directly support custom output formatting, so we'll capture its default output instead
    { time_output=$(timeout 1s ./main < "$input_file" 2> time_stats) ; } 2>&1
    exit_status=$?

    # Capture time stats from the time command's stderr
    real_time=$(grep real time_stats | awk '{print $2}')
    memory_kb=0  # Not captured since built-in time doesn't support memory usage

    # Read the program's output
    output=$time_output
    # rm temp_output time_stats

    MEMORY_LIMIT=24 # 24 MB

    # Extract real time in seconds
    real_time_seconds=$(echo $real_time | sed 's/s//')  # Remove the 's' suffix from time if any

    # Convert time to milliseconds (integer arithmetic)
    time_taken_ms=$(echo "$real_time_seconds * 1000" | awk '{printf "%.3f", $0}')

    # Check if the program timed out
    if [ $exit_status -eq 124 ]; then
        echo "Test Case $test_count_1 FAILED (Time Limit Exceeded)"
    else
        # Check if the output matches the expected output
        if [ "$output" = "$expected_output" ]; then
            echo "Test Case $test_count_1 PASSED"
            total_score_1=$((total_score_1 + points))
        else
            echo "Test Case $test_count_1 FAILED (Wrong Answer)"
            echo "Expected: $expected_output, Got: $output"
        fi
    fi
    echo "--------------------"
}

    echo "Problem 1 Test Cases Running"
    echo "--------------------"

    # Folder where test cases are stored
    tests_folder="testsp1"

    # Number of test cases
    num_tests=3
    i=0
    # Loop through all test cases
    while [ "$i" -lt $num_tests ];
    do
        input_file="../$tests_folder/input$i.txt"
        output_file="../$tests_folder/output$i.txt"
        points=20/$num_tests  # Points for each test case

        if [[ -f "$input_file" && -f "$output_file" ]]; then
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

# compile the code for problem 2
cd ../p2
echo "Compiling p2, main.c"
(make clean; make all)
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
        output=$(echo "$input1" | ./main)
        
        # Remove any trailing newline from the output
        output=$(echo "$output" | tr -d '\n')
        output=$(echo "$output" | sed 's/ $//')
        
        # Check if the output matches the expected output
        if [ "$output" = "$expected_output" ]; then
            echo "Result: PASS for Problem 2, Test Case $test_count_2"
            total_score_2=$((total_score_2 + points))
        else
            echo "Result: FAIL for Problem 2, Test Case $test_count_2"
            echo "Expected: $expected_output, Got: $output"
        fi
        echo "------------------------------"
    }

    echo "Problem 2 Test Cases Running"
    echo "--------------------"
    run_test_2 "1" "-1" 10
    run_test_2 "3" "3 2 1" 10
fi



# Compile the code for problem 2
cd ../p3
echo "Compiling p3, main.c"
(make clean; make)
status3=$?
if [ ${status3} -ne 0 ]; then
    echo "Failure: Unable to compile main.c (return status = ${status3})"
    total_score_3=0
else 
    run_test_3() {
    local input_file="$1"
    local expected_output_file="$2"
    local points="$3"

    # Increment test count
    test_count_3=$((test_count_3 + 1))

    # Read expected output from file
    expected_output=$(cat "$expected_output_file")

    # Run the program with a time limit of 1 second and capture time stats using the built-in 'time' command
    # 'time' doesn't directly support custom output formatting, so we'll capture its default output instead
    { time_output=$(timeout 1s ./main < "$input_file" 2> time_stats) ; } 2>&1
    exit_status=$?

    # Capture time stats from the time command's stderr
    real_time=$(grep real time_stats | awk '{print $2}')
    memory_kb=0  # Not captured since built-in time doesn't support memory usage

    # Read the program's output
    output=$time_output
    # rm temp_output time_stats

    MEMORY_LIMIT=24 # 24 MB

    # Extract real time in seconds
    real_time_seconds=$(echo $real_time | sed 's/s//')  # Remove the 's' suffix from time if any

    # Convert time to milliseconds (integer arithmetic)
    time_taken_ms=$(echo "$real_time_seconds * 1000" | awk '{printf "%.3f", $0}')

    # Check if the program timed out
    if [ $exit_status -eq 124 ]; then
        echo "Test Case $test_count_3 FAILED (Time Limit Exceeded)"
    else
        # Check if the output matches the expected output
        if [ "$output" = "$expected_output" ]; then
            echo "Test Case $test_count_3 PASSED"
            total_score_3=$((total_score_3 + points))
        else
            echo "Test Case $test_count_3 FAILED (Wrong Answer)"
            echo "Expected: $expected_output, Got: $output"
        fi
    fi
    echo "--------------------"
}

    echo "Problem 3 Test Cases Running"
    echo "--------------------"

    # Folder where test cases are stored
    tests_folder="testsp3"

    # Number of test cases
    num_tests=2
    i=0
    # Loop through all test cases
    while [ "$i" -lt $num_tests ];
    do
        input_file="../$tests_folder/input$i.txt"
        output_file="../$tests_folder/output$i.txt"
        points=20/$num_tests  # Points for each test case

        if [[ -f "$input_file" && -f "$output_file" ]]; then
            run_test_3 "$input_file" "$output_file" "$points"
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