import subprocess
import matplotlib.pyplot as plt
import re

def run_make_command(n):
    # run input command
    subprocess.run(f"make input NUM={n}", shell=True, check=True)
    
    # run time command
    result = subprocess.run("make time", shell=True, capture_output=True, text=True)
    
    # find time in output
    match = re.search(r'(\d+\.\d+) real', result.stderr)
    time_taken = float(match.group(1)) 
    return time_taken

n_values = []
times = []

# loop over the values of n for number of characters in the input file
n = 1
while n <= 100000000:
    print(f"Running for n={n}")
    time_taken = run_make_command(n)
    n_values.append(n)
    times.append(time_taken)
    n *= 10

# plot the results
plt.plot(n_values, times, marker='o')
plt.xscale('log')
plt.yscale('log')
plt.xlabel('Number of Characters')
plt.ylabel('Time (Seconds)')
plt.title('Execution Time vs Number of Characters')
plt.grid(True)
plt.show()
