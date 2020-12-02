# Radix sort


## Machine:

	Processor: AMD Ryzen 7 2700 Eight-Core Processor 3.20 Gz

	Memory: 32 Gb

	System: Windows 10


## Test results

| Algorithm | Version | Container type | Number of elements | Digits in number | Sort time in seconds |
| --- | --- | --- | --- | --- | --- |
| std::sort | Sequential | STL vector | 4000000 | 5 | 0.299 | 
| std::sort | Sequential | STL vector | 4000000 | 9 | 0.376 | 
| parallel_sort | Parallel TBB | STL vector | 4000000 | 5 | 0.122 | 
| parallel_sort | Parallel TBB | STL vector | 4000000 | 9 | 0.103 | 
| Radix | Sequential | STL vector | 4000000 | 5 | 4.874 | 
| Radix | Sequential | STL vector | 4000000 | 9 | 8.65 | 
| Radix | Sequential | Dynamic Array | 4000000 | 5 | 0.449 | 
| Radix | Sequential | Dynamic Array | 4000000 | 9 | 0.877 | 
| Radix | Parallel TBB | STL vector | 4000000 | 5 | 0.857 | 
| Radix | Parallel TBB | STL vector | 4000000 | 9 | 1.035 | 
| Radix | Parallel TBB | Dynamic Array | 4000000 | 5 | 0.642 | 
| Radix | Parallel TBB | Dynamic Array | 4000000 | 9 | 1.073 | 
| Radix | std::thread | STL vector | 4000000 | 5 | 1.332 | 
| Radix | std::thread | STL vector | 4000000 | 9 | 2.29 | 
| Radix | std::thread | Dynamic Array | 4000000 | 5 | 0.863 | 
| Radix | std::thread | Dynamic Array | 4000000 | 9 | 1.705 | 
| Radix Byte | Sequential | STL vector | 4000000 | 5 | 3.242 | 
| Radix Byte | Sequential | STL vector | 4000000 | 9 | 4.773 | 
| Radix Byte | Sequential | Dynamic Array | 4000000 | 5 | 0.111 | 
| Radix Byte | Sequential | Dynamic Array | 4000000 | 9 | 0.142 | 
| Radix Byte | Parallel TBB | Dynamic Array | 4000000 | 5 | 0.582 | 
| RadixByte | Parallel TBB | Dynamic Array | 4000000 | 9 | 0.55 | 
| Radix Byte | std::thread | Dynamic Array | 4000000 | 5 | 0.553 | 
| Radix Byte | std::thread | Dynamic Array | 4000000 | 9 | 0.647 | 
