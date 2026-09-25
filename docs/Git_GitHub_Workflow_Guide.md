# Git and GitHub Workflow Guide

This guide explains the Git, GitHub, and Classroom 50 workflow used for five-step embedded-systems projects. Use it together with the project-specific requirements in `docs/project_description.md` and the current step instructions in `docs/`.

## Required Tools

You need Git, a web browser, and the embedded-systems tools specified by your course. GitHub CLI is optional.

### Install Git

- Windows: install [Git for Windows](https://git-scm.com/download/win), which includes Git Bash.
- macOS: install Git through Xcode Command Line Tools or [git-scm.com](https://git-scm.com/download/mac).
- Linux: install Git with your distribution's package manager or [git-scm.com](https://git-scm.com/download/linux).

Verify the installation by opening Git Bash or a terminal and running `git --version`.

## GitHub Account and Canvas Team

Use the approved GitHub account for your course. Your GitHub team must match your Canvas team. If the automatically generated repository or group name does not match your Canvas team, do not create a new repository; contact the instructor and request a correction.

## Classroom 50 Setup

1. Open the Classroom 50 invitation link posted in Canvas.
2. Sign in with the approved course GitHub account.
3. The designated team lead accepts the assignment and creates the team repository.
4. The team lead invites the other Canvas team members through the web interface.
5. Each teammate accepts the repository invitation.
6. Confirm that everyone can access the same repository before beginning work.

Do not create duplicate repositories. The repository name may include a Classroom 50 group number; this is normal.

## Repository Privacy and Copyright

The instructor controls repository visibility. Do not create public copies, forks, or mirrors, or publish course code, documentation, evidence, or reports publicly. This protects course intellectual property and copyright. Unauthorized public distribution may result in a grade penalty, including no credit for affected work, and may be addressed under applicable university policies.

## Configure Git Identity

Set your name and course GitHub email before making commits. Use the email associated with the approved GitHub account.

Run `git config --global user.name "Your Name"` and `git config --global user.email "your-email@example.com"`.

Verify the settings with `git config --global --list`.

## Clone the Repository

1. Open the team repository in a web browser.
2. Select the green **Code** button.
3. Copy the HTTPS URL.
4. In Git Bash or a terminal, run `git clone <TEAM-REPOSITORY-URL>`.
5. Enter the repository with `cd <TEAM-REPOSITORY-NAME>`.
6. Verify the remote with `git remote -v` and the working tree with `git status`.

## Five-Step Branch Workflow

Each step has a start date and due date posted in Canvas. Begin work only during the scheduled period. Do not make project changes directly on `main`.

At the start of a step, update `main` and create the corresponding step branch. For example, use `git switch main`, `git pull origin main`, `git switch -c step1`, and `git push -u origin step1` for Step 1. Use `step2`, `step3`, `step4`, or `step5` for later steps.

Only the team lead should create the shared step branch unless the instructor gives different instructions. Other members obtain it with `git fetch origin`, `git switch step1`, and `git pull`.

## Make, Test, Commit, and Push Changes

Before editing, run `git switch <STEP-BRANCH>` and `git pull`.

After completing and testing an assigned task:

1. Run `git status` and `git diff` to review the changes.
2. Stage the intended files with `git add <changed-files>`.
3. Commit with a meaningful message, such as `git commit -m "Implement UART initialization"`.
4. Push with `git push`.

Each team member must make identifiable, meaningful commits. Examples include implementing one function, adding a test, fixing a verified bug, updating documentation, or adding evidence.

## Pull Request Workflow

Each step uses one team pull request from the step branch into `main`.

1. Open the repository in a web browser.
2. Select **Pull requests**, then **New pull request**.
3. Set the base branch to `main` and the compare branch to the current step branch.
4. Review the changed files and commits.
5. Summarize the completed work and testing in the PR description.
6. Create the pull request.
7. Ask at least one teammate to review the PR.
8. Resolve requested changes by committing and pushing to the same step branch.
9. After peer review and successful automated checks, the team lead may merge the PR.

Creating a pull request does not immediately change `main`. The changes enter `main` only after the PR is merged. The PR records the team's review discussion, commits, and contributions. Instructor/TA approval is not required before every merge; the instructor or TA may review PRs, commits, and evidence later for grading.

Repeat the process for `step1`, `step2`, `step3`, `step4`, and `step5`. Do not begin the next step until the previous step has been reviewed and merged and the next Canvas start date has arrived.

## Update and Resolve Conflicts

Before beginning new work, update your local `main` with `git switch main` and `git pull origin main`.

If `main` changed while you were working on a step branch, run `git switch <STEP-BRANCH>` followed by `git merge origin/main`.

If Git reports a conflict, open the marked files, keep the correct content, remove the conflict markers, and test the result. Then run `git add <resolved-files>`, `git commit -m "Resolve merge conflicts"`, and `git push`.

The pull request updates automatically. Ask the instructor for help before resolving a conflict if you are unsure which version to keep.

## Optional GitHub CLI

GitHub CLI is optional. It provides command-line shortcuts for GitHub tasks, but it is not required. The required workflow uses Git and a web browser.

## Common Problems

### `git` is not recognized

Restart Git Bash or the terminal after installing Git. If the problem remains, reinstall Git and verify with `git --version`.

### Wrong GitHub account

Stop before accepting the assignment or pushing work. Sign in with the approved course account and contact the instructor if commits were already made with the wrong account.

### Assignment already accepted

Do not accept it again or create another repository. Use the repository already created for your team.

### Teammate cannot access the repository

Confirm that the team lead invited the teammate's exact GitHub username and that the teammate accepted the invitation. Contact the instructor if the problem remains.

### Pull request cannot be created

Confirm that the step branch was pushed successfully and that the PR compares the step branch with `main`.

## Help

When requesting help, provide the exact command and complete error message. Remove passwords, tokens, access keys, and other private information.
