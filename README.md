
# Grain Simulation - DLD CA3 (Fall 2024)

This project is a grain simulation developed as part of the Digital Logic Design course (CA3) for Fall 2024. The goal of the project is to model grain growth behavior and simulate its dynamics using a computational approach.

## Features

- Simulates grain growth behavior over time.
- Implements key algorithms for modeling grain dynamics.
- Provides modular and extendable code for experimenting with grain simulation parameters.

## Repository Structure

### Source Code (`src/`)
- **`main.cpp`**: The main entry point of the program.
- **`grain/`**: Implementation and definition of the `Grain` class, modeling the properties and behavior of Grain module.
- **`LFSR/`**: Implementation and definition of the `LFSR` class, modeling the properties and behavior of LFSR module.
- **`NFSR/`**: Implementation and definition of the `LFSR` class, modeling the properties and behavior of NFS module.
- **`uint24/`**: Class for handling unsigned int with width of 24 bits. 
- **`uint80/`**: Class for handling unsigned int with width of 80 bits.


## Requirements

To build and run the project, you need the following:
- A C++ compiler supporting C++11 or later (e.g., GCC, Clang).
- Make utility to use the provided `makefile`.


## Installation and Usage

1. Clone the repository:
   ```bash
   git clone https://github.com/mohasnik/DLD-CA3---Fall-2024---Grain-Simulation.git
   cd DLD-CA3---Fall-2024---Grain-Simulation
   ```

2. Build the project:
   ```bash
   make
   ```

3. Run the executable:
   To run the executable and generate the desired log files, additional arguments must be passed to it. The order and type of arguments is as follows :
   
   ```bash
   ./grain <MODULE_TYPE> <SEED_HEX> <NUM_ITERATIONS>
   ```
  - <MODULE_TYPE> : "-l" for LFSR module, "-n" for NFSR, and "-g" for Grain.
  - <SEED_HEX> : the input seed for each module in hexadecimal.
  - <NUM_ITERATIONS> : the number of iterations (or equivalently number of clock cycles) to execute the simulator.


