# Radix sort


## Machine:

	Processor: AMD Ryzen 7 2700 Eight-Core Processor 3.20 Gz

	Memory: 32 Gb

	System: Windows 10


## Test results

| Algorithm | Version | Container type | Number of elements | Digits in number | Sort time in seconds |
| --- | --- | --- | --- | --- | --- |
| std::sort | Sequential | STL vector | 4000000 | 5 | 0.286 | 
| std::sort | Sequential | STL vector | 4000000 | 9 | 0.369 | 
| parallel_sort | Parallel TBB | STL vector | 4000000 | 5 | 0.113 | 
| parallel_sort | Parallel TBB | STL vector | 4000000 | 9 | 0.099 | 
| Radix | Sequential | STL vector | 4000000 | 5 | 4.412 | 
| Radix | Sequential | STL vector | 4000000 | 9 | 7.846 | 
| Radix | Sequential | Dynamic Array | 4000000 | 5 | 4.39 | 
| Radix | Sequential | Dynamic Array | 4000000 | 9 | 7.856 | 
| Radix | Parallel TBB | STL vector | 4000000 | 5 | 0.768 | 
| Radix | Parallel TBB | STL vector | 4000000 | 9 | 0.95 | 
| Radix | Parallel TBB | Dynamic Array | 4000000 | 5 | 0.429 | 
| Radix | Parallel TBB | Dynamic Array | 4000000 | 9 | 0.599 | 
| Radix | std::thread | STL vector | 4000000 | 5 | 0.907 | 
| Radix | std::thread | STL vector | 4000000 | 9 | 1.558 | 
| Radix | Parallel TBB | Dynamic Array | 4000000 | 5 | 0.473 | 
| Radix | Parallel TBB | Dynamic Array | 4000000 | 9 | 0.644 | 
