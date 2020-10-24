# Radix sort:


## Machine:

	Processor: AMD Ryzen 7 2700 Eight-Core Processor 3.20 Gz

	Memory: 32 Gb

	System: Windows 10


## Test results

| Algorithm | Version | Container type | Number of elements | Digits in number | Sort time in seconds |
| --- | --- | --- | --- | --- | --- |
| Radix | Sequential | STL vector | 4000000 | 5 | 78.779 | 
| Radix | Sequential | STL vector | 4000000 | 10 | 157.732 | 
| std::sort | Sequential | STL vector | 4000000 | 5 | 14.321 | 
| std::sort | Sequential | STL vector | 4000000 | 10 | 18.824 | 
| Radix | Sequential | Dynamic Array | 4000000 | 5 | 12.578 | 
| Radix | Sequential | Dynamic Array | 4000000 | 10 | 23.972 | 
