# CECS 346 Project 1

## Traffic Light Controller with Moore FSM and SysTick

This repository contains the starter files and workflow for CECS 346 Project 1. You will design, implement, test, and document a traffic light controller for South traffic, West traffic, and pedestrians.

The project integrates GPIO programming, bit-specific addressing, Moore FSM design, SysTick timing, hardware interfacing, debugging, and technical documentation.

## Start Here

1. Read the complete [Project 1 Description](docs/CECS346_Project1_Description.md).
2. Review the starter code in [`src/main.c`](src/main.c).
3. Review the Keil project files in [`keil/`](keil/).
4. Follow the required two-step branch workflow.

## Two-Step Workflow

Complete the project in two steps:

1. `step1-coding` - design, implement, test, and debug the controller.
2. `step2-report` - document the design, testing evidence, demonstration video, and reflection.

Do not make project changes directly on `main`. Create the required step branch, commit meaningful changes, push the branch, and use a pull request to merge completed work into `main`.

## Repository Structure

```text
.
|-- src/       Starter and project source code
|-- keil/      Keil project files
|-- docs/      Complete project requirements and design references
|-- evidence/  Screenshots, test results, and demonstration evidence
|-- report/    Project report template and report materials
|-- .gitignore
`-- README.md
```

## Commit Guidelines

Commit regularly. Each commit should represent a meaningful, testable change. Examples include:

```text
Add GPIO bit-specific addresses
Implement SysTick initialization
Complete traffic FSM state table
Test pedestrian light sequence
Verify all sensor combinations
Add Project 1 evidence
```

Before committing, make sure the project builds or clearly document what remains incomplete.

## Important Links

- [Complete Project 1 Description](docs/CECS346_Project1_Description.md)
- [Starter Source Code](src/main.c)
- [Report Template](report/report.md)

If a linked file is not present in the repository, follow the corresponding instructions in the project assignment or contact the instructor.
