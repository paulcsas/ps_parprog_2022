#!/bin/bash

# Execute job in the partition "lva.q" unless you have special requirements.
#SBATCH --partition=lva
# Name your job to be able to identify it later
#SBATCH --job-name test
# Redirect output stream to this file
#SBATCH --output=output.log
# Maximum number of tasks (=processes) to start in total
#SBATCH --ntasks=1
# Maximum number of tasks (=processes) to start per node
#SBATCH --ntasks-per-node=1
# Enforce exclusive node allocation, do not share with other jobs
#SBATCH --exclusive

./serial 500000000
./parallel_1_thread
./parallel_2_thread
./parallel_3_thread
./parallel_4_thread
./parallel_5_thread
./parallel_6_thread
./parallel_7_thread
./parallel_8_thread

/bin/hostname
