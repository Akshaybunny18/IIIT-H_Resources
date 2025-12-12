#!/usr/bin/bash
# driver.sh - A simple autograder script.
# Usage: ./driver.sh

# Initialize total scores
# total_score_1=0
max_score=60

# test_count_1=0
# test_count_2=0
# test_count_3=0


# Colors for pass/fail
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m'

total_score_1=0
total_score_2=0
total_score_3=0
# Compile the code for problem 1
cd p1
echo "Compiling p1, main.c"
(make clean; make)
status1=$?
flag=0

if [ ${status1} -ne 0 ]; then
    echo "Failure: Unable to compile main.c (return status = ${status1})"
    total_score_1=0
else
    run_test_1() {
        local input_file="$1"
        local expected_output_file="$2"
        local points="$3"
        
        # Move input file to current directory as election.txt
        mv "$input_file" "election.txt"
        
        # Increment test count
        test_count_1=$((test_count_1 + 1))
        
        # Read expected output from file
        expected_output=$(cat "$expected_output_file")
        
        # Run the program with time and memory limit
        time_output=$(timeout 1s ./main 2> time_stats)
        exit_status=$?
        
        # Read time statistics
        cat "time_stats"
        
        memory_kb=0
        real_time=$(grep "Elapsed (wall clock) time" time_stats | awk '{print $8}')
        
        # Convert time to milliseconds
        real_time_seconds=$(echo $real_time | sed 's/s//')
        time_taken_ms=$(echo "$real_time_seconds * 1000" | awk '{printf "%.3f", $0}')
        
        MEMORY_LIMIT=$((4 * 1024))
        time_output=$(echo -n "$time_output" | tr -d '\n' | sed 's/[[:space:]]*$//')
        expected_output=$(echo -n "$expected_output" | tr -d '\n' | sed 's/[[:space:]]*$//')
        # Check if the program timed out
        if [ $exit_status -eq 124 ]; then
            echo -e "$TLE: Test Case $test_count_1 FAILED (Time Limit Exceeded)"
            flag=1
        else
            # Check if the output matches the expected output
            if [ "$time_output" = "$expected_output" ]; then
                echo -e "AC: Test Case $test_count_1 PASSED"
                total_score_1=$((total_score_1 + $points))
            else
                echo "$time_output"
                echo "$expected_output"
                echo -e "WA: Test Case $test_count_1 FAILED (Wrong Answer)"
                flag=1
            fi
        fi
        
        # Move election.txt back to original input file name
        mv "election.txt" "$input_file"
    }
    
    echo "Problem 1 Test Cases Running"
    echo "--------------------"
    
    # Define test files directory relative to p1
    tests_folder="../testsp1"
    
    # Number of test cases
    num_tests=2
    i=0
    
    while [ "$i" -lt $num_tests ];
    do
        if [ $flag -eq 1 ]; then
            echo "Test Case not accepted, terminating future checking!..."
            break
        fi
        
        input_file="$tests_folder/input$i.txt"
        output_file="$tests_folder/output$i.txt"
        points=$((20 / num_tests))
        
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

# Compile the code for problem 2
cd ../p2
echo "Compiling p2, main.c"
(make clean; make)
status2=$?
flag=0
if [ ${status2} -ne 0 ]; then
    echo "Failure: Unable to compile main.c (return status = ${status2})"
    total_score_2=0
else
    run_test_2() {
        local input_file="$1"
        local expected_output_file="$2"
        local points="$3"
        
        # Move input file to current directory as election.txt
        mv "$input_file" "vowel.txt"
        
        # Increment test count
        test_count_2=$((test_count_2 + 1))
        
        # Read expected output from file
        expected_output=$(cat "$expected_output_file")
        
        # Run the program with time and memory limit
        time_output=$(timeout 1s ./main 2> time_stats)
        exit_status=$?
        
        # Read time statistics
        cat "time_stats"
        
        memory_kb=0
        real_time=$(grep "Elapsed (wall clock) time" time_stats | awk '{print $8}')
        
        # Convert time to milliseconds
        real_time_seconds=$(echo $real_time | sed 's/s//')
        time_taken_ms=$(echo "$real_time_seconds * 1000" | awk '{printf "%.3f", $0}')
        
        MEMORY_LIMIT=$((4 * 1024))
        time_output=$(echo -n "$time_output" | tr -d '\n' | sed 's/[[:space:]]*$//')
        expected_output=$(echo -n "$expected_output" | tr -d '\n' | sed 's/[[:space:]]*$//')
        # Check if the program timed out
        if [ $exit_status -eq 124 ]; then
            echo -e "$TLE: Test Case $test_count_2 FAILED (Time Limit Exceeded)"
            flag=1
        else
            # Check if the output matches the expected output
            if [ "$time_output" = "$expected_output" ]; then
                echo -e "AC: Test Case $test_count_2 PASSED"
                total_score_2=$((total_score_2 + $points))
            else
                echo $time_output
                echo -e "WA: Test Case $test_count_2 FAILED (Wrong Answer)"
                flag=1
            fi
        fi
        
        # Move election.txt back to original input file name
        mv "vowel.txt" "$input_file"
    }
    
    echo "Problem 2 Test Cases Running"
    echo "--------------------"
    
    # Folder where test cases are stored
    tests_folder="testsp2"
    
    # Number of test cases
    #num_tests=2
    num_tests=2
    
    i=0
    # Loop through all test cases
    while [ "$i" -lt $num_tests ];
    do
        if [ $flag -eq 1 ]; then
            echo "Test Case not accepted, terminating future checking!..."
            break
        fi
        
        input_file="../$tests_folder/input$i.txt"
        output_file="../$tests_folder/output$i.txt"
        points=$((20 / num_tests)) # Points for each test case
        
        if [[ -f "$input_file" && -f "$output_file" ]]; then
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
flag=0

if [ ${status3} -ne 0 ]; then
    echo "Failure: Unable to compile main.c (return status = ${status3})"
    total_score_3=0
else
    run_test_3() {
        local input_file="$1"
        local expected_output_file="$2"
        local points="$3"
        
        # Move input file to current directory as number.txt
        mv "$input_file" "number.txt"
        
        # Increment test count
        test_count_3=$((test_count_3 + 1))
        
        # Read expected output from file
        expected_output=$(cat "$expected_output_file")
        
        # Run the program with time and memory limit
        time_output=$(timeout 1s ./main 2> time_stats)
        exit_status=$?
        
        # Read time statistics
        cat "time_stats"
        
        memory_kb=0
        real_time=$(grep "Elapsed (wall clock) time" time_stats | awk '{print $8}')
        
        # Convert time to milliseconds
        real_time_seconds=$(echo $real_time | sed 's/s//')
        time_taken_ms=$(echo "$real_time_seconds * 1000" | awk '{printf "%.3f", $0}')
        
        MEMORY_LIMIT=$((4 * 1024))
        time_output=$(echo -n "$time_output" | tr -d '\n' | sed 's/[[:space:]]*$//')
        expected_output=$(echo -n "$expected_output" | tr -d '\n' | sed 's/[[:space:]]*$//')
        
        # Check if the program timed out
        if [ $exit_status -eq 124 ]; then
            echo -e "$TLE: Test Case $test_count_3 FAILED (Time Limit Exceeded)"
            flag=1
        else
            # Check if the output matches the expected output
            if [ "$time_output" = "$expected_output" ]; then
                echo -e "AC: Test Case $test_count_3 PASSED"
                total_score_3=$((total_score_3 + $points))
            else
                echo "$time_output"
                echo "$expected_output"
                echo -e "WA: Test Case $test_count_3 FAILED (Wrong Answer)"
                flag=1
            fi
        fi
        
        # Move number.txt back to original input file name
        mv "number.txt" "$input_file"
    }
    
    echo "Problem 3 Test Cases Running"
    echo "--------------------"
    
    # Define test files directory relative to p3
    tests_folder="../testsp3"
    
    # Number of test cases
    num_tests=2
    i=0
    
    while [ "$i" -lt $num_tests ];
    do
        if [ $flag -eq 1 ]; then
            echo "Test Case not accepted, terminating future checking!..."
            break
        fi
        
        input_file="$tests_folder/input$i.txt"
        output_file="$tests_folder/output$i.txt"
        points=$((20 / num_tests))
        
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
total_score=$((total_score_1+total_score_2+total_score_3))
percentage=$((total_score * 100 / max_score))

# Print the total score and percentage
echo "Total Score: $total_score / $max_score"
echo "Percentage: $percentage%"


echo "---------------------------------------------------------------------------------"

echo "{\"scores\": {\"p1\": $total_score_1, \"p2\": $total_score_2, \"p3\": $total_score_3}}"
exit
