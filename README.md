# Radix sort


## Machine:

	Processor: AMD Ryzen 7 2700 Eight-Core Processor 3.20 Gz

	Memory: 32 Gb

	System: Windows 10


## Test results

| Algorithm | Version | Container type | Number of elements | Digits in number | Sort time in seconds |
| --- | --- | --- | --- | --- | --- |
| std::sort | Sequential | STL vector | 4000000 | 5 | 0.29 | 
| std::sort | Sequential | STL vector | 4000000 | 9 | 0.365 | 
| parallel_sort | Parallel TBB | STL vector | 4000000 | 5 | 0.116 | 
| parallel_sort | Parallel TBB | STL vector | 4000000 | 9 | 0.098 | 
| Radix | Sequential | STL vector | 4000000 | 5 | 4.759 | 
| Radix | Sequential | STL vector | 4000000 | 9 | 8.039 | 
| Radix | Sequential | Dynamic Array | 4000000 | 5 | 5.004 | 
| Radix | Sequential | Dynamic Array | 4000000 | 9 | 8.406 | 
| Radix | Parallel TBB | STL vector | 4000000 | 5 | 0.804 | 
| Radix | Parallel TBB | STL vector | 4000000 | 9 | 1.032 | 
| Radix | Parallel TBB | Dynamic Array | 4000000 | 5 | 0.448 | 
| Radix | Parallel TBB | Dynamic Array | 4000000 | 9 | 0.611 | 
| Radix | std::thread | STL vector | 4000000 | 5 | 1.105 | 
| Radix | std::thread | STL vector | 4000000 | 9 | 1.839 | 
| Radix | std::thread | Dynamic Array | 4000000 | 5 | 0.459 | 
| Radix | std::thread | Dynamic Array | 4000000 | 9 | 0.603 | 
