#!/bin/bash

echo "Select the run environment:"
echo "1. windows_msvs_2022_user"
echo "2. windows_gcc_user"
echo "3. windows_gcc_coverage_user"
echo "4. linux_gcc_user"
echo "5. linux_gcc_coverage_user"

# Prompt the user for input
read -p "Enter the number of your choice: " choice

# Set the run environment based on the user's choice
case $choice in
    1) run_environment="windows_msvs_2022_user" ;;
    2) run_environment="windows_gcc_user" ;;
    3) run_environment="windows_gcc_coverage_user" ;;
    4) run_environment="linux_gcc_user" ;;
    5) run_environment="linux_gcc_coverage_user" ;;
    *) 
       echo "Invalid choice. Exiting."
       exit 1
       ;;
esac

# Confirm the chosen environment
echo "Running with environment: $run_environment"

# Run the Python script with the selected environment
python3 scripts/gen_test_report_preset.py --run_environment="$run_environment"