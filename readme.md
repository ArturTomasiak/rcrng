## rcrng

A simple function that achieves random number generation using race conditions.

```c
rcrng(uint16_t from, uint16_t to)
```

> [!NOTE]
> magic_number and thread_count are arbitrary; their value should depend on needs and hardware

### Flaws

**Scalability**

This implementation requires drastically more cpu cycles than f.e. RDRAND, with which one can generate a random number from 3 to 9 in about 350–520 cycles.

**Safety Concerns**

It's randomness can be influenced by: 

- OS scheduler
- CPU architecture 
- system load 
- compiler optimizations

Furthermore, system load and timing can be manipulated.

### Sample Results

The following tables summarize the results of rcrng over multiple sample batches where

Processor 12th Gen Intel(R) Core(TM) i3-1215U, 1200 Mhz, 6 Core(s), 8 Logical Processor(s)

```c
static uint32_t magic_number = 100000;
static const uint8_t thread_count = 6;
```

#### Sample Size: 10 000 | Range: 3-9

|Batch| 3   | 4   | 5   | 6   | 7   | 8   | 9   |
|-----|-----|-----|-----|-----|-----|-----|-----|
|Batch 1| 1356 | 1385 | 1475 | 1456 | 1520 | 1382 | 1426 |
|Batch 2| 1412 | 1382 | 1453 | 1450 | 1426 | 1418 | 1459 |
|Batch 3| 1421 | 1439 | 1509 | 1427 | 1388 | 1393 | 1423 |

#### Sample Size: 10 000 | Range: 0-1

|Batch| 0   | 1   |
|-----|-----|-----|
|Batch 1| 4926 | 5074 |
|Batch 2| 4967 | 5033 |
|Batch 3| 5042 | 4958 |