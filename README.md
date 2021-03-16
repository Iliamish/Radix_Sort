# Radix sort


## Machine:

	Processor: AMD Ryzen 7 2700 Eight-Core Processor 3.20 Gz

	Memory: 32 Gb

	System: Windows 10


## Test results

| Algorithm | Version | Container type | Number of elements | Digits in number | Sort time in seconds |
| --- | --- | --- | --- | --- | --- |
| std::sort | Sequential | STL vector | 10000000 | 5 | 0.698 | 
| std::sort | Sequential | STL vector | 10000000 | 9 | 0.986 | 
| parallel_sort | Parallel TBB | STL vector | 10000000 | 5 | 0.135 | 
| parallel_sort | Parallel TBB | STL vector | 10000000 | 9 | 0.133 | 
| Radix | Sequential | STL vector | 10000000 | 5 | 12.214 | 
| Radix | Sequential | STL vector | 10000000 | 9 | 22.094 | 
| Radix | Sequential | Dynamic Array | 10000000 | 5 | 1.125 | 
| Radix | Sequential | Dynamic Array | 10000000 | 9 | 2.176 | 
| Radix | Parallel TBB | STL vector | 10000000 | 5 | 2.27 | 
| Radix | Parallel TBB | STL vector | 10000000 | 9 | 2.607 | 
| Radix | Parallel TBB | Dynamic Array | 10000000 | 5 | 1.272 | 
| Radix | Parallel TBB | Dynamic Array | 10000000 | 9 | 2.444 | 
| Radix | std::thread | STL vector | 10000000 | 5 | 2.823 | 
| Radix | std::thread | STL vector | 10000000 | 9 | 4.9 | 
| Radix | std::thread | Dynamic Array | 10000000 | 5 | 0.245 | 
| Radix | std::thread | Dynamic Array | 10000000 | 9 | 0.466 | 
| Radix Byte | Sequential | STL vector | 10000000 | 5 | 7.896 | 
| Radix Byte | Sequential | STL vector | 10000000 | 9 | 11.702 | 
| Radix Byte | Sequential | Dynamic Array | 10000000 | 5 | 0.348 | 
| Radix Byte | Sequential | Dynamic Array | 10000000 | 9 | 0.35 | 
| Radix Byte | Parallel TBB | Dynamic Array | 10000000 | 5 | 1.149 | 
| Radix Byte | Parallel TBB | Dynamic Array | 10000000 | 9 | 1.121 | 
| Radix Byte | std::thread | Dynamic Array | 10000000 | 5 | 0.141 | 
| Radix Byte | std::thread | Dynamic Array | 10000000 | 9 | 0.195 | 
