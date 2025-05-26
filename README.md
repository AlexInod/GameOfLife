# GameOfLife

A complete C implementation of Conway's Game of Life with multiple execution modes.

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Compilation](#compilation)
- [Usage](#usage)
- [Input Format](#input-format)
- [Task Modes](#task-modes)
- [File Structure](#file-structure)
- [Examples](#examples)

## Overview

This project implements Conway's Game of Life, a cellular automaton devised by mathematician John Horton Conway. The program supports multiple task modes for different types of simulation.

## Features

- **Standard Game of Life Evolution** (Task 1)
- **Generation Change Tracking** (Task 2) 
- **Binary Tree Evolution Simulation** (Task 3)
- **Reverse to Initial State** (Task 5) - Reconstruct initial state from final state and changes

## Compilation

```bash
gcc -o game_of_life Task1.c Task1func.c -std=c99 -Wall
```

## Usage

```bash
./game_of_life <input_file> <output_file>
```

### Arguments
- `input_file`: Path to the input file containing the initial configuration
- `output_file`: Path where the results will be written

## Input Format

The input file should follow this format:

```
T N M K
<grid_row_1>
<grid_row_2>
...
<grid_row_N>
[additional_data_for_specific_tasks]
```

Where:
- `T`: Task number (1, 2, 3, or 5)
- `N`: Number of rows in the grid
- `M`: Number of columns in the grid  
- `K`: Number of generations/iterations
- Grid uses `X` for live cells and `+` for dead cells

## Task Modes

This is the site where everything is explained about each task
https://site-pa.netlify.app/proiecte/game_of_life/

**Input Format for Task 5:**
```
5 N M K
<generation_1> (row1,col1) (row2,col2) ...
<generation_2> (row1,col1) (row2,col2) ...  
...
<generation_K> (row1,col1) (row2,col2) ...
<final_grid_row_1>
<final_grid_row_2>
...
<final_grid_row_N>
```

**Output:** The reconstructed initial state

## File Structure

```
├── Task1.c          # Main program entry point
├── Task1.h          # Header file with function declarations and structures  
├── Task1func.c      # Implementation of all functions
└── README.md        # This file
```

## Examples

### Example Input (Task 1):
```
1 3 3 2
+++
+X+
+++
```

This simulates a single live cell for 2 generations.

### Example Input (Task 2):
```
2 4 4 3
++++
+XX+
+XX+
++++
```

This tracks changes in a 2x2 block pattern for 3 generations.

### Example Input (Task 5):
```
5 3 3 2  
1 (1,1)
2 (0,1) (1,0)
+++
+X+
+++
```

This reconstructs the initial state that led to the given final state.
