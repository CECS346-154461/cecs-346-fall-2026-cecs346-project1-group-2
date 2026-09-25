# evidence/ - Project Evidence Folder

This folder contains the testing and demonstration evidence for CECS 346 Project 1: Traffic Light Controller with Moore FSM and SysTick.

Collect evidence during the `step1-coding` branch and organize the final evidence for the report during the `step2-report` branch.

## Folder Structure

```text
evidence/
├── README.md
├── simulator/
├── hardware/
└── demonstration/
```

## simulator/

Store evidence from Keil simulation and the Logic Analyzer, including:

- Input and output waveforms
- Test cases for one, two, and three active participants
- Timing verification
- Screenshots showing the FSM output sequence
- Evidence that all required input combinations were tested

Suggested file names:

```text
logic_analyzer_all_participants.png
logic_analyzer_south_request.png
logic_analyzer_west_request.png
logic_analyzer_pedestrian_request.png
timing_verification.png
```

## hardware/

Store evidence from the physical LaunchPad and breadboard system, including:

- Hardware schematic
- Breadboard or system photograph
- Switch wiring
- LED wiring
- Hardware test results

Suggested file names:

```text
hardware_schematic.png
hardware_system_photo.jpg
switch_wiring.jpg
led_wiring.jpg
hardware_test_results.png
```

## demonstration/

Store the on-board demonstration evidence, including:

- Demonstration video link
- Demonstration notes
- Additional photographs or screenshots

Create a Markdown file such as:

```text
demonstration_video.md
```

Example content:

```markdown
# On-Board Demonstration Video

Video link: Paste the shareable video link here.

The demonstration includes:

- Initial South green state
- Single-participant tests
- Two-participant fairness tests
- Three-participant round-robin test
- Pedestrian walk and flashing-hurry sequence
```

## Evidence Guidelines

- Use clear and descriptive file names.
- Use lowercase letters, numbers, underscores, and file extensions.
- Make sure screenshots are readable.
- Include the relevant test case in the file name or description.
- Do not upload unrelated files or multiple copies of the same evidence.
- Do not include passwords, private access tokens, or personal information.
- Make sure evidence is consistent with the source code and project report.
- Reference the evidence files from the final report in the `report/` folder.

## Step Workflow

### Step 1 - Coding and Verification

During `step1-coding`, collect and commit:

- Simulator screenshots
- Logic Analyzer results
- Hardware test photographs
- Timing observations
- Other evidence that confirms the system works

### Step 2 - Report and Evidence

During `step2-report`:

- Review the evidence collected during Step 1.
- Select the clearest and most complete evidence.
- Add missing evidence if necessary.
- Reference the evidence from the final report.
- Do not repeat the implementation; document and explain the completed work.
