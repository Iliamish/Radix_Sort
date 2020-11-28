# Radix sort


## Machine:

	Processor: AMD Ryzen 7 2700 Eight-Core Processor 3.20 Gz

	Memory: 32 Gb

	System: Windows 10


## Test results

| Algorithm | Version | Container type | Number of elements | Digits in number | Sort time in seconds |
| --- | --- | --- | --- | --- | --- |
| std::sort | Sequential | STL vector | 4000000 | 5 | 0.29 | 
| std::sort | Sequential | STL vector | 4000000 | 9 | 0.362 | 
| parallel_sort | Parallel TBB | STL vector | 4000000 | 5 | 0.119 | 
| parallel_sort | Parallel TBB | STL vector | 4000000 | 9 | 0.101 | 
| Radix | Sequential | STL vector | 4000000 | 5 | 4.539 | 
| Radix | Sequential | STL vector | 4000000 | 9 | 8.203 | 
| Radix | Sequential | Dynamic Array | 4000000 | 5 | 4.576 | 
| Radix | Sequential | Dynamic Array | 4000000 | 9 | 8.207 | 
| Radix | Parallel TBB | STL vector | 4000000 | 5 | 0.824 | 
| Radix | Parallel TBB | STL vector | 4000000 | 9 | 1.014 | 
| Radix | Parallel TBB | Dynamic Array | 4000000 | 5 | 0.461 | 
| Radix | Parallel TBB | Dynamic Array | 4000000 | 9 | 0.632 | 
| Radix | std::thread | STL vector | 4000000 | 5 | 0.935 | 
| Radix | std::thread | STL vector | 4000000 | 9 | 1.773 | 
| Radix | std::thread | Dynamic Array | 4000000 | 5 | 0.51 | 
| Radix | std::thread | Dynamic Array | 4000000 | 9 | 0.699 | 
| Radix Byte | Sequential | STL vector | 4000000 | 5 | 2.647 | 
| Radix Byte | Sequential | STL vector | 4000000 | 9 | 3.814 | 
| Radix Byte | Sequential | Dynamic Array | 4000000 | 5 | 0.132 | 
| Radix Byte | Sequential | Dynamic Array | 4000000 | 9 | 0.136 | 
| Radix Byte | Parallel TBB | Dynamic Array | 4000000 | 5 | 0.469 | 
| RadixByte | Parallel TBB | Dynamic Array | 4000000 | 9 | 0.476 | 
| Radix Byte | std::thread | Dynamic Array | 4000000 | 5 | 0.467 | 
| Radix Byte | std::thread | Dynamic Array | 4000000 | 9 | 0.48 | 
