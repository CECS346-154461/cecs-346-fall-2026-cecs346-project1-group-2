# src/ - Source Code Folder

This folder contains all source code for CECS 346 Project 1: Traffic Light Controller with Moore FSM and SysTick.

## Starter File

The starter file is:

```text
main.c
```

Begin your implementation in `main.c`. Complete the project header information, including the course, term, project number, project description, team number, and team members.

The starter program includes the basic program structure:

```c
void System_Init(void);

int main(void) {
  System_Init();

  while(1) {
  }
}

void System_Init(void) {
}
```

Add the required system initialization, GPIO configuration, SysTick configuration, FSM state table, and FSM engine as you develop the project.

## Source Files

Keep all project source code in this folder.

```text
src/
├── main.c
├── SysTick.c       Optional module file
├── SysTick.h       Optional header file
├── GPIO.c          Optional module file
├── GPIO.h          Optional header file
└── README.md
```

You may add additional `.c` and `.h` files when they improve the organization of your program. Each additional source file must be added to the Keil project so that it is compiled and linked.

## Project Requirements

- Define the required peripheral registers yourself.
- Do not include `tm4c123gh6pm.h`.
- Use bit-specific addressing for the traffic lights, pedestrian lights, and sensors.
- Use SysTick for all timing delays.
- Implement the nine-state Moore FSM using a structured state table.
- Keep the FSM engine free of conditional branches that implement the traffic-control behavior.
- Use clear names, comments, and meaningful function organization.

## Suggested Module Organization

You may organize the code using functions or separate modules such as:

- System and clock initialization
- GPIO initialization
- SysTick initialization and delay functions
- Bit-specific address definitions
- FSM state definitions and state table
- FSM execution engine
- Output and input definitions

Choose an organization that makes the code easy to test, debug, and explain in the project report.

## Header Files and Register Definitions

Place project-specific declarations and register definitions in appropriate header files when using multiple modules. Make sure the declarations match the implementation and that every file is included in the Keil project.

Do not copy a completed solution into this folder. Your team must implement, test, and explain the code submitted for the project.

## Branch and Commit Workflow

Complete the implementation on the `step1-coding` branch. Do not make project changes directly on `main`.

Commit meaningful, testable changes, such as:

```text
Add GPIO register definitions
Implement Port B initialization
Implement Port E sensor inputs
Implement SysTick delay functions
Add Moore FSM state table
Implement FSM engine
Test all sensor combinations
Fix pedestrian flashing sequence
```

Before committing, build the project and document any known incomplete work.

## Source-Code Checklist

Before completing Step 1, verify that:

- `main.c` builds successfully in Keil.
- All required source files are inside `src/`.
- All source files are included in the Keil project.
- Register definitions are present and correct.
- GPIO pin assignments match the project description.
- SysTick timing calculations use the correct bus frequency.
- The FSM state table contains all nine states and eight input combinations.
- The FSM engine follows the required output, wait, input, and transition sequence.
- No completed source files or unrelated CECS 347 files remain in the folder.
