# CS 525 SimpleScalar Project

A testbed for cache optimization using SimpleScalar.

## Features

- Supported algorithms:
  - QuickSort
  - RadixSort (coming soon)
- SimpleScalar cache configurations (coming soon)

## Compiling

1. You must have SimpleScalar built on your target system.
2. Compile the programs with SimpleScalar. See source comments for compiling the associated program.
```
cd cs525advcomparch/programs
~/simplescalar/bin/sslittle-na-sstrix-gcc program.c -o bin/testout
```

## Simulation

Run the programs using SimpleScalar. See source comments for usage.

For, running quicksort test with default settings:
```
cd cs525advcomparch/programs
~/simplescalar/simplesim-3.0/sim-cache redir:sim quicksort_test_default.txt ./bin/quicksort test
```
The results, ```quicksort_test_default.txt``` file, should be found under ```cs525advcomparch/programs```

### Cache Config

Configure the cache by adding argument ```-cache:<type> <config>```

The format for the type config follows:
```
<name>:<nsets>:<bsize>:<assoc>:<repl>
```

Each of these fields has the following meaning:
```
<name>  # cache name, must be unique.
<nsets> # number of sets in the cache.
<bsize> # block size (for TLBs, use the page size).
<assoc> # associativity of the cache (power of two).
<repl>  # replacement policy (l | f | r), where l = LRU, f = FIFO, r = random replacement
```

### sim-cache defaults

|Type                | Config                             |
|--------------------|------------------------------------|
|L1 instruction cache|```il1:256:32:1:l (8 KB)```         |
|L1 data cache       |```dl1:256:32:1:l (8 KB)```         |
|L2 unified cache    |```ul2:1024:64:4:l (256 KB)```      |
|instruction TLB     |```itlb:16:4096:4:l (64 entries)``` |
|data TLB            |```dtlb:32:4096:4:l (128 entries)```|
