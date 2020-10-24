#Radix sort:


##Machine:

	Processor: AMD Ryzen 7 2700 Eight-Core Processor 3.20 Gz

	Memory: 32 Gb

	System: Windows 10


##Test results

| Algorithm | Version | Container type | Number of elements | Digits in number | Sort time in seconds |
| --- | --- | --- | --- | --- | --- |
| Radix | Sequential | STL vector | 4000000 | 5 | 79.744 | 
| Radix | Sequential | STL vector | 4000000 | 10 | 158.026 | 
| std::sort | Sequential | STL vector | 4000000 | 5 | 14.4 | 
| std::sort | Sequential | STL vector | 4000000 | 10 | 19.429 | 
| Radix | Sequential | Dynamic Array | 4000000 | 5 | 12.75 | 
| Radix | Sequential | Dynamic Array | 4000000 | 10 | 24.316 | 
