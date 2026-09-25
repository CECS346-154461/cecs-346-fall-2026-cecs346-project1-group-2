# docs/ - Project Documentation Folder

This folder contains the documentation for **CECS 346 Project 1: Traffic Light Controller with Moore FSM and SysTick**.

## Files in This Folder

### Project Description

The complete Project 1 description is provided in the Word and/or Markdown file in this folder. Read it before starting the project. It includes:

- Project objectives
- Required hardware and materials
- System requirements
- GPIO pin assignments
- SysTick timing requirements
- Moore FSM requirements
- State and transition tables
- Testing procedures
- Deliverables and grading information

### `AI_Log.md`

Use this file to document any AI assistance used during the project. Record:

- Date
- Tool used
- Prompt or question
- How the response was evaluated
- What was accepted, modified, or rejected
- How the assistance contributed to the final work

AI assistance does not replace your responsibility to understand, test, debug, and explain your project.

## Two-Step Project Workflow

The project has two GitHub workflow steps. The steps have different purposes and should not duplicate the same work.

### Step 1 - Coding and Verification

Work on the `step1-coding` branch.

Save the Step 1 design and verification record using the following filename:

```text
docs/step1_coding_verification.md
```

Complete and verify the working system:

- Design the nine-state Moore FSM.
- Prepare the working state diagram and state table.
- Calculate the GPIO bit-specific addresses.
- Implement `main.c` and supporting source files.
- Test the program in the Keil simulator.
- Use the Logic Analyzer to verify input and output behavior.
- Build and test the hardware system.
- Record important testing observations.
- Commit meaningful coding and testing changes.
- Open a pull request and merge the completed coding work into `main`.

The state diagram, state table, calculations, and testing notes in Step 1 are working design artifacts. They do not need to be formatted as a final report yet.

### Step 2 - Report and Evidence

Create the `step2-report` branch from the updated `main` branch.

Use the report template provided in the `report/` folder. The final report filename and format will be specified when the template is finalized.

Complete the report and organize the final evidence:

- Finalize the FSM state diagram and state table.
- Add Logic Analyzer screenshots and test results.
- Add the hardware schematic and system photograph.
- Add the on-board demonstration video link.
- List the submitted source files.
- Describe challenges, solutions, and lessons learned.
- Complete the report template in the `report/` folder.
- Open a pull request and merge the completed report work into `main`.

Students may reuse working design files from Step 1 in the final report. The purpose of Step 2 is to organize, explain, and provide evidence for the completed work, not to repeat the implementation.

## Suggested Folder Organization

```text
main branch
├── src/
├── keil/
├── docs/
├── evidence/
└── report/

step1-coding branch
├── src/
├── keil/
└── docs/
    └── step1_coding_verification.md

step2-report branch
├── src/
├── keil/
├── docs/
├── evidence/
└── report/
    └── Report_Template
```

## Documentation Guidelines

- Use the required filename `step1_coding_verification.md` for the Step 1 record.
- Use the report template provided in the `report/` folder for Step 2.
- Use clear file names for additional evidence.
- Do not delete the complete project description.
- Keep working design files separate from final evidence when practical.
- Do not submit placeholder text as completed work.
- Make sure screenshots are readable and labeled.
- Explain unexpected results and how they were resolved.
- Keep the documentation consistent with the source code and test evidence.
- Commit documentation changes regularly.
- Do not make changes directly on `main`; use the required step branches and pull requests.
