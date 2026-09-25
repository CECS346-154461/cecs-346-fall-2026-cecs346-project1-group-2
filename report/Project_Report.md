<div align="center">

<img width="220" alt="CSULB logo" src="images/csulb_logo.png" />

# Project Report

## CECS 346 Project 1

### Traffic Light Controller with Moore FSM and SysTick

California State University, Long Beach  
Department of Computer Engineering & Computer Science

**Team Number:**  
**Instructor:**  
**Submission Date:**  
**Team Members:**  

</div>

> Complete the remainder of this report on the `step2-report` branch. Replace all placeholder text and add links to evidence stored in this repository.

# 1. Project Overview

## 1.1 Objective

Describe the purpose of the traffic light controller and the problem it solves. Explain how the system coordinates South traffic, West traffic, and pedestrians at a four-corner intersection.

## 1.2 System Summary

Briefly describe the completed system, including the Moore FSM, GPIO inputs and outputs, SysTick timing, pedestrian flashing sequence, and round-robin fairness behavior.

## 1.3 Project Repository

Repository link: [Paste the repository link here](PASTE_REPOSITORY_LINK_HERE)  
Final commit or pull request: [Paste the link here](PASTE_FINAL_LINK_HERE)

# 2. System Requirements

Explain how the implementation satisfies the main project requirements.

Use one of the following status keywords: **Complete**, **Partially complete**, or **Not complete**.

### Example entries

The following entries demonstrate how to document requirement status and evidence. Use them as a model; do not copy the example entries.

| ID | Requirement | Status | Evidence or link |
|---|---|---|---|
| R1 | Implement a Moore FSM with nine states. | Complete | FSM diagram and state table in Section 4 |
| R4 | Use SysTick for all timing delays. | Complete | SysTick source files and Logic Analyzer screenshots in `evidence/simulator/` |
| R10 | Verify the system in simulation and on the LaunchPad hardware. | Partially complete | Simulation evidence is complete; hardware testing remains |

### Student requirement table

Complete the table below for your own project. Provide a specific evidence link or report section for each requirement.

| ID | Requirement | Status | Evidence or link |
|---|---|---|---|
| R1 | Implement a Moore FSM with nine states. |  |  |
| R2 | Use three inputs and eight possible input combinations. |  |  |
| R3 | Use a state structure containing output, wait time, and next-state information. |  |  |
| R4 | Use SysTick for all timing delays. |  |  |
| R5 | Use a 0.25-second base time unit. |  |  |
| R6 | Use bit-specific addressing for traffic lights, pedestrian lights, and sensors. |  |  |
| R7 | Use Port B for traffic LEDs, Port E for sensors, and Port F for pedestrian LEDs. |  |  |
| R8 | Define the required peripheral registers without including `tm4c123gh6pm.h`. |  |  |
| R9 | Avoid conditional branches inside the FSM engine. |  |  |
| R10 | Verify the system in the Keil simulator and on the LaunchPad hardware. |  |  |

# 3. Hardware Design

## 3.1 Component List

List the TM4C123 LaunchPad, six external traffic LEDs, three switches, current-limiting resistors, breadboard, jumper wires, and multimeter. The pedestrian Walk and Don't Walk LEDs are onboard the LaunchPad; no additional pedestrian LEDs are required.

## 3.2 Pin Assignments

Complete or verify the following table.

| Function | TM4C123 pin | Description |
|---|---|---|
| South sensor | PE2 | Positive logic; 3.3 V means car present |
| West sensor | PE1 | Positive logic; 3.3 V means car present |
| Pedestrian input | PE0 | Positive logic; 3.3 V means pedestrian waiting |
| South green | PB0 | Traffic LED output |
| South yellow | PB1 | Traffic LED output |
| South red | PB2 | Traffic LED output |
| West green | PB3 | Traffic LED output |
| West yellow | PB4 | Traffic LED output |
| West red | PB5 | Traffic LED output |
| Pedestrian Walk | PF3 | Green pedestrian LED |
| Pedestrian Don't Walk | PF1 | Red pedestrian LED |

## 3.3 Schematic and Hardware Photograph

Schematic: [Open the schematic](../evidence/hardware/hardware_schematic.png)  
Hardware photograph: [Open the hardware photograph](../evidence/hardware/hardware_system_photo.jpg)

Explain the switch connections, LED connections, logic levels, and current-limiting resistors.

# 4. Software Design

## 4.1 FSM Design

Insert or link the final nine-state Moore FSM diagram.

FSM diagram: [Open the FSM diagram](../evidence/simulator/fsm_state_diagram.png)

Explain the role of each state and why separate states are required for the pedestrian hurry-up flashing sequence.

## 4.2 State Table

Insert or link the completed state table, including each state's output, wait time, and eight next-state values.

State table: [Open the state table](../evidence/simulator/fsm_state_table.png)

Explain how the three input bits are converted into an index from 0 through 7.

## 4.3 Fairness and Safety Rules

Explain how the FSM satisfies the following rules:

- Traffic lights follow green, yellow, and red in order.
- Pedestrian lights follow Walk, Hurry, and Don't Walk in order.
- A participant completes its sequence before another participant receives green.
- Competing participants are served fairly using round-robin scheduling.
- Conflicting traffic directions are never green at the same time.

## 4.4 Software Implementation

Briefly describe the main source files and the responsibilities of the GPIO initialization, SysTick driver, state table, and FSM engine. Explain how the implementation uses the required ports, bit-specific addressing, 0.25-second timing unit, and table-driven state transitions.

Source-code folder: [`src/`](../src/)  
Keil-project folder: [`keil/`](../keil/)

# 5. Verification and Testing

## 5.1 Step 1 Coding and Verification

Step 1 design record: [`docs/step1_coding_verification.md`](../docs/step1_coding_verification.md)

Summarize the tests completed during Step 1. Store detailed evidence in the `evidence/` folder.

## 5.2 Simulator Tests

Logic Analyzer screenshots must include all six external traffic-light outputs and both onboard pedestrian-light outputs: PF3 Walk and PF1 Don't Walk.

| Test case | Input condition | Expected behavior | Observed result | Evidence |
|---|---|---|---|---|
| 1 | Reset condition | South green, West red, Don't Walk |  |  |
| 2 | West only | South completes transition, then West green |  |  |
| 3 | Pedestrian only | Traffic completes transition, then Walk sequence |  |  |
| 4 | South, West, and pedestrian active | Round-robin service |  |  |

Logic Analyzer evidence: [`evidence/simulator/`](../evidence/simulator/)

## 5.3 Hardware Tests

Describe the hardware tests and explain whether the physical system matched the simulator.

Hardware evidence: [`evidence/hardware/`](../evidence/hardware/)

## 5.4 Demonstration

Document the required six single-participant tests, three two-participant fairness tests, and one three-participant test. Include the input condition, expected sequence, observed result, and evidence link.

Demonstration evidence: [`evidence/demonstration/`](../evidence/demonstration/)

Video link: [Paste the shareable demonstration video link here](PASTE_VIDEO_LINK_HERE)

The demonstration should include the reset condition, single-participant tests, two-participant fairness tests, the three-participant test, and the pedestrian flashing sequence.

GitHub workflow evidence: Include the repository link and final commit or pull request link. Briefly describe how the team used meaningful commits, branches, and pull requests to coordinate the work.

# 6. Team Contributions

Describe each member's contributions to implementation, testing, documentation, evidence collection, and repository coordination.

| Team member | Contributions |
|---|---|
|  |  |
|  |  |
|  |  |
|  |  |

# 7. Challenges and Reflection

## 7.1 Technical Challenge

Describe the most important technical challenge, its cause, the debugging process, and the solution.

## 7.2 What We Learned

Explain what the team learned about GPIO, Moore FSM design, SysTick timing, hardware interfacing, testing, and GitHub collaboration.

## 7.3 Future Improvements

Describe one or more improvements that could make the design more reliable, maintainable, efficient, or easier to test.

# 8. References and AI Usage

List the datasheets, lecture slides, live textbook sections, lab documents, and other technical sources used.

If AI assistance was used, document it in [`docs/AI_Log.md`](../docs/AI_Log.md). The log should explain how each response was evaluated and how the final work was independently verified.

Make sure the report, source code, documentation, evidence, and demonstration agree with one another.
