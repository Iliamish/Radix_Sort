RESULTS:

*Machine:*

Processor: AMD Ryzen 7 2700 Eight-Core Processor 3.20 Gz

Memory: 32 Gb

System: Windows 10

| Algorithm | Version | Container type | Number of elements | Digits in number | Sort time in seconds |
| --- | --- | --- | --- | --- | --- |
| Radix | Sequential | STL vector | 4000000 | 5 | 80.521 | 
| Radix | Sequential | STL vector | 4000000 | 10 | 159.202 | 
| std::sort | Sequential | STL vector | 4000000 | 5 | 14.738 | 
| std::sort | Sequential | STL vector | 4000000 | 10 | 19.393 | 
| Radix | Sequential | Dynamic Array | 4000000 | 5 | 13.049 | 
| Radix | Sequential | Dynamic Array | 4000000 | 10 | 25.36 | 
