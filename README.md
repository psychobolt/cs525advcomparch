# CS 525 SimpleScalar Project

A testbed for cache optimization using SimpleScalar.

## Features

- Supported algorithms:
  - QuickSort
  - RadixSort (coming soon)
- SimpleScalar cache configurations (coming soon)

## Running

1. You must have SimpleScalar built on your target system.
2. Compile the programs with SimpleScalar. See source comments for compiling the associated program.
```
cd cs525advcomparch
~/simplescalar/bin/sslittle-na-sstrix-gcc program.c -o bin/testout
```
3. Run the programs using SimpleScalar. See source comments for usage. e.g. Running quicksort test ```~/simplescalar/simplesim-3.0/sim-cache ./bin/quicksort test```
