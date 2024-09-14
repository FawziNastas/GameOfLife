# Conway's Game of Life (C++ Implementation)

## Overview
This project implements Conway's Game of Life, a cellular automaton devised by mathematician John Conway. The game operates on a 2D grid where each cell can either be alive or dead, and evolves based on the state of neighboring cells. The simulation follows a set of rules to produce complex, often beautiful, emergent behavior.

## Rules of the Game:
1. **Any live cell** with two or three live neighbors survives.
2. **Any dead cell** with exactly three live neighbors becomes a live cell.
3. **All other live cells** die, and all other dead cells remain dead.

These simple rules create diverse patterns such as oscillators, still lifes, and spaceships.

## Features
- Dynamic grid resizing.
- Adjustable game speed and initial configuration.
- Supports loading custom initial states from files.
- Visual representation of the grid in the terminal or graphical interface.

## Installation
To compile the program, make sure you have a C++ compiler installed, then download the .cpp source code file and the .h header file and place them in the same folder to run the program.
