# Radix sort


## Machine:

	Processor: AMD Ryzen 7 2700 Eight-Core Processor 3.20 Gz

	Memory: 32 Gb

	System: Windows 10


## Test results

| Algorithm | Version | Container type | Number of elements | Digits in number | Sort time in seconds |
| --- | --- | --- | --- | --- | --- |
| std::sort | Sequential | STL vector | 4000000 | 5 | 0.301 | 
| std::sort | Sequential | STL vector | 4000000 | 9 | 0.383 | 
| parallel_sort | Parallel TBB | STL vector | 4000000 | 5 | 0.117 | 
| parallel_sort | Parallel TBB | STL vector | 4000000 | 9 | 0.108 | 
| Radix | Sequential | STL vector | 4000000 | 5 | 5.451 | 
| Radix | Sequential | STL vector | 4000000 | 9 | 9.746 | 
| Radix | Sequential | Dynamic Array | 4000000 | 5 | 0.44 | 
| Radix | Sequential | Dynamic Array | 4000000 | 9 | 0.84 | 
| Radix | Parallel TBB | STL vector | 4000000 | 5 | 0.829 | 
| Radix | Parallel TBB | STL vector | 4000000 | 9 | 1.067 | 
| Radix | Parallel TBB | Dynamic Array | 4000000 | 5 | 0.593 | 
| Radix | Parallel TBB | Dynamic Array | 4000000 | 9 | 0.956 | 
| Radix | std::thread | STL vector | 4000000 | 5 | 1.261 | 
| Radix | std::thread | STL vector | 4000000 | 9 | 2.377 | 
| Radix | std::thread | Dynamic Array | 4000000 | 5 | 0.166 | 
| Radix | std::thread | Dynamic Array | 4000000 | 9 | 0.25 | 
| Radix Byte | Sequential | STL vector | 4000000 | 5 | 2.872 | 
| Radix Byte | Sequential | STL vector | 4000000 | 9 | 4.291 | 
| Radix Byte | Sequential | Dynamic Array | 4000000 | 5 | 0.136 | 
| Radix Byte | Sequential | Dynamic Array | 4000000 | 9 | 0.137 | 
| Radix Byte | Parallel TBB | Dynamic Array | 4000000 | 5 | 0.464 | 
| Radix Byte | Parallel TBB | Dynamic Array | 4000000 | 9 | 0.135 | 
| Radix Byte | std::thread | Dynamic Array | 4000000 | 5 | 0.117 | 
| Radix Byte | std::thread | Dynamic Array | 4000000 | 9 | 0.128 | 
