# Wordle Project 🎮

## Introduction
This project is a simplified implementation of the popular Wordle game, written in C.  
It allows the player to choose a target word from a dictionary file and then try to guess it within 6 attempts.  
Feedback is displayed using colored boxes:
- 🟩 Green = correct letter in the correct position
- 🟨 Yellow = correct letter in the word but wrong position
- ⬜ Gray = letter not in the word

The goal is to provide a fun way to practice programming concepts such as file handling, loops, user input validation, and colored terminal output.

---

## Objectives
- Implement a Wordle‑style game in C.  
- Practice modular programming with multiple source files (`main.c`, `wordle.c`, `wordle.h`).  
- Use ANSI escape codes to display colored feedback in the terminal.  
- Validate user input against a dictionary file.  
- Provide clear win/lose messages after 6 attempts.

---

## Project Structure
- **main.c** → Handles game flow, user input, and attempts.  
- **wordle.c** → Contains functions for dictionary loading, input validation, and feedback display.  
- **wordle.h** → Header file with constants and function prototypes.  
- **words.txt** → Dictionary file containing valid 5‑letter words.  

---

## How to Compile & Run
Open a terminal in the project folder and type:

```bash
gcc main.c wordle.c -o wordle
./wordle
```
## Example Execution 📸
Here’s a screenshot of the game in action:

![Wordle Screenshot](screenshot.png)


## Features
- User chooses the target word at the start.  
- 6 attempts maximum.  
- Colored feedback boxes for each guess.  
- Invalid guesses do not consume attempts.  
- Clear win/lose messages.  


## Conclusion
This project demonstrates how a simple game can be built in C using modular design and terminal formatting.  
It combines logic, user interaction, and visual feedback to create an engaging experience.  
Overall, it highlights the importance of clean code structure, user‑friendly output, and creativity in programming assignments.



















