# Radix sort


## Machine:

	Processor: AMD Ryzen 7 2700 Eight-Core Processor 3.20 Gz

	Memory: 32 Gb

	System: Windows 10


## Test results

| Algorithm | Version | Container type | Number of elements | Digits in number | Sort time in seconds |
| --- | --- | --- | --- | --- | --- |
| std::sort | Sequential | STL vector | 4000000 | 5 | 0.296 | 
| std::sort | Sequential | STL vector | 4000000 | 9 | 0.381 | 
| parallel_sort | Parallel TBB | STL vector | 4000000 | 5 | 0.132 | 
| parallel_sort | Parallel TBB | STL vector | 4000000 | 9 | 0.109 | 
| Radix | Sequential | STL vector | 4000000 | 5 | 5.328 | 
| Radix | Sequential | STL vector | 4000000 | 9 | 9.337 | 
| Radix | Sequential | Dynamic Array | 4000000 | 5 | 0.432 | 
| Radix | Sequential | Dynamic Array | 4000000 | 9 | 0.857 | 
| Radix | Parallel TBB | STL vector | 4000000 | 5 | 0.839 | 
| Radix | Parallel TBB | STL vector | 4000000 | 9 | 1.024 | 
| Radix | Parallel TBB | Dynamic Array | 4000000 | 5 | 0.597 | 
| Radix | Parallel TBB | Dynamic Array | 4000000 | 9 | 0.992 | 
| Radix | std::thread | STL vector | 4000000 | 5 | 1.238 | 
| Radix | std::thread | STL vector | 4000000 | 9 | 2.262 | 
| Radix | std::thread | Dynamic Array | 4000000 | 5 | 0.173 | 
| Radix | std::thread | Dynamic Array | 4000000 | 9 | 0.27 | 
| Radix Byte | Sequential | STL vector | 4000000 | 5 | 2.964 | 
| Radix Byte | Sequential | STL vector | 4000000 | 9 | 4.27 | 
| Radix Byte | Sequential | Dynamic Array | 4000000 | 5 | 0.136 | 
| Radix Byte | Sequential | Dynamic Array | 4000000 | 9 | 0.137 | 
| Radix Byte | Parallel TBB | Dynamic Array | 4000000 | 5 | 0.468 | 
| Radix Byte | Parallel TBB | Dynamic Array | 4000000 | 9 | 0.482 | 
| Radix Byte | std::thread | Dynamic Array | 4000000 | 5 | 0.119 | 
| Radix Byte | std::thread | Dynamic Array | 4000000 | 9 | 0.135 | 
