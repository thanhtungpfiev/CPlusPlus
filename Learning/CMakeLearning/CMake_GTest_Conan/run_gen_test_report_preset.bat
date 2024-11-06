@echo off
setlocal enabledelayedexpansion

echo Select the run environment:
echo 1. windows_msvs_2022_user
echo 2. windows_gcc_user
echo 3. windows_gcc_coverage_user
echo 4. linux_gcc_user
echo 5. linux_gcc_coverage_user

set /p choice="Enter the number of your choice: "

if "%choice%"=="1" set run_environment=windows_msvs_2022_user
if "%choice%"=="2" set run_environment=windows_gcc_user
if "%choice%"=="3" set run_environment=windows_gcc_coverage_user
if "%choice%"=="4" set run_environment=linux_gcc_user
if "%choice%"=="5" set run_environment=linux_gcc_coverage_user

if not defined run_environment (
    echo Invalid choice. Exiting.
    exit /b 1
)

echo Running with environment: %run_environment%
python scripts/gen_test_report_preset.py --run_environment=%run_environment%

pause
