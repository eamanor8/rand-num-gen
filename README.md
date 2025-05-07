# Random Number Generation for Security

This project explores the differences between general-purpose and cryptographically secure random number generation. It implements and analyzes random number generators used in security applications like encryption key creation, using `/dev/random`, `/dev/urandom`, and seeded PRNGs.

📄 The detailed report of this lab with screenshots and explanations is provided in: `random_numbers_report.pdf`

## Overview

This lab, conducted as part of ECE/CS 5560, highlights key concepts in secure randomness, including:

- Why typical PRNGs are not secure
- How bad randomness can lead to attacks (e.g., AES key guessing)
- Monitoring entropy in Linux
- Difference between `/dev/random` and `/dev/urandom`
- Evaluating the quality of random data using `ent`

## Project Structure

```
.
├── .vscode/                          # Editor config files
├── Files/                            # Shared files or test data
├── task1/                            # Task 1: Insecure key generation with srand(time(NULL))
├── task2/                            # Task 2: AES key guessing attack based on known plaintext
├── task5/                            # Task 5: Use /dev/urandom to securely generate 256-bit keys
├── random_numbers_instructions.pdf   # Lab instruction document
└── random_numbers_report.pdf         # Full lab report with observations and code output
```

## Lab Tasks Summary

### Task 1: Insecure Key Generation

- Demonstrates use of `srand(time(NULL))` in C and Python
- Shows how using predictable seeds can produce repeatable "random" keys
- Explains impact of seeding and why this is unsuitable for cryptographic use

### Task 2: Key Guessing Attack

- Scenario: An attacker (Bob) attempts to brute-force Alice's AES key
- Known: timestamp, IV, and first block of plaintext
- Approach: Simulate key guesses based on time window and verify against known ciphertext
- Written in **C** to match Alice's original key generation

### Task 3 & 4: Measuring Entropy and Using `/dev/random`

- Monitor entropy pool in Linux using:
  ```bash
  watch -n .1 cat /proc/sys/kernel/random/entropy_avail
  ```
- Observe entropy increase with user activity (mouse, keyboard, I/O)
- Read from `/dev/random` and note blocking behavior when entropy is low
- Discuss potential for **Denial of Service (DoS)** via entropy exhaustion

### Task 5: Using `/dev/urandom`

- Read 256-bit keys from `/dev/urandom` in C
- Use `ent` tool to evaluate randomness quality:
  ```bash
  head -c 1M /dev/urandom > output.bin
  ent output.bin
  ```
- Discuss quality, performance, and use in production systems

## Report

Refer to [`random_numbers_report.pdf`](./random_numbers_report.pdf) for:

- Output logs, screenshots, and entropy graphs
- Source code snippets with inline explanations
- Security implications and attack scenarios

## Credit

- Lab adapted from **SEED Labs** by Dr. Wenliang Du: https://seedsecuritylabs.org
- Course: ECE/CS 5560 – Fundamentals of Information Security
