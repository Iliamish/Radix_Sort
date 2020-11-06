# Radix sort


## Machine:

	Processor: AMD Ryzen 7 2700 Eight-Core Processor 3.20 Gz

	Memory: 32 Gb

	System: Windows 10


## Test results

| Algorithm | Version | Container type | Number of elements | Digits in number | Sort time in seconds |
| --- | --- | --- | --- | --- | --- |
| Radix | Sequential | STL vector | 4000000 | 5 | 4.433 | 
| Radix | Sequential | STL vector | 4000000 | 9 | 7.825 | 
| std::sort | Sequential | STL vector | 4000000 | 5 | 0.285 | 
| std::sort | Sequential | STL vector | 4000000 | 9 | 0.363 | 
| Radix | Sequential | Dynamic Array | 4000000 | 5 | 4.37 | 
| Radix | Sequential | Dynamic Array | 4000000 | 9 | 7.83 | 
| Radix | Parallel TBB | STL vector | 4000000 | 5 | 1.619 | 
| Radix | Parallel TBB | STL vector | 4000000 | 9 | 2.113 | 
| parallel_sort | Parallel TBB | STL vector | 4000000 | 5 | 0.096 | 
| parallel_sort | Parallel TBB | STL vector | 4000000 | 9 | 0.095 | 
