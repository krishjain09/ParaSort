# Parallel Merge Sort Implementation

## Overview

This project implements the **Merge Sort algorithm** in both sequential and parallel versions using **C++ multithreading**.  
By leveraging multiple CPU threads, the sorting process is significantly accelerated, especially for large datasets.  
The project also benchmarks **standard Merge Sort vs Parallel Merge Sort** to highlight performance improvements.

## Features

- **Parallel Processing**: Splits sorting tasks across multiple CPU threads for faster execution.
- **Threshold Optimization**: Uses sequential sorting for small subarrays to reduce overhead.
- **Performance Benchmarking**: Compares sequential and parallel execution times on large datasets.

## Implementation Details

The implementation enhances traditional Merge Sort by introducing **parallelism**:

- **Recursive Division**: The array is recursively divided until a threshold size is reached.
- **Parallel Sorting**: Subarrays are sorted concurrently using `std::thread`.
- **Merging**: Sorted subarrays are merged to form the final sorted output.

⚠️ Note: Extremely large inputs (e.g., `10^8` elements) may exceed system memory and cause the process to be killed.

## Performance Comparison

Benchmark results on a **4-core, 8-thread CPU with 8GB RAM**:

| Array Size | Sequential Merge Sort | Parallel Merge Sort | Speedup |
|------------|------------------------|---------------------|---------|
| 10^6       | ~1.2 sec              | ~0.4 sec           | ~3x     |
| 10^7       | ~12 sec               | ~2.3 sec           | ~5x     |

## Getting Started

### Prerequisites

- **C++11 or later**
- g++ (or any modern C++ compiler with thread support)

### Installation & Compilation

```bash
# Clone the repository
git clone https://github.com/krishjain09/ParaSort.git
cd ParaSort/src/app

# Compile
g++ -std=c++11 -O2 -pthread main.cpp sorting/mergeSort.cpp sorting/parallelMergeSort.cpp -o parallelSort

# Run
./parallelSort
