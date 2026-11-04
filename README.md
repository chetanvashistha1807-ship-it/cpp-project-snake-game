# Console Snake Game (C++)

A classic Snake game built as a **beginner C++ project**. The game runs in the Windows console and was developed to practise core C++ programming, arrays, functions, input handling, and basic game logic.

## Features

- A 40 × 20 console game board with boundary walls.
- Keyboard-controlled movement using **W**, **A**, **S**, and **D**.
- Food (`*`) placed at random positions inside the board.
- Food spawning checks the snake's occupied coordinates before accepting a position.
- The snake grows by one segment whenever it eats food.
- A score counter increases by one for each food item eaten.
- Wall collision and self-collision detection.
- Continuous movement with a short delay between frames.
- Press **X** to exit the game.

## Controls

| Key | Action |
|---|---|
| W | Move up |
| A | Move left |
| S | Move down |
| D | Move right |
| X | Exit the game |

## Requirements

- Windows.
- A C++ compiler such as MinGW GCC.
- A terminal such as Windows Terminal, PowerShell, or the VS Code integrated terminal.

> **Platform note:** This version uses Windows-specific headers and functions (`<conio.h>`, `<windows.h>`, `_kbhit()`, `_getch()`, and `Sleep()`), so it is intended to compile and run on Windows with a compatible compiler such as MinGW. It is not currently a cross-platform version.

## Build and run

Open a terminal in the folder containing the source file.

1. Compile the program (assuming the source file is named `snake.cpp`):

   ```powershell
   g++ -std=c++11 snake.cpp -o snake.exe
   ```

2. Run it in PowerShell:

   ```powershell
   .\snake.exe
   ```

If your source file has a different name, replace `snake.cpp` in the compile command with that filename. Make sure `g++` is available in your system `PATH`.

## C++ concepts and programming techniques used

This project practises **18 grouped C++ concepts and programming techniques**:

1. **Structures (`struct`)** — grouping the `x` and `y` coordinates of a snake segment.
2. **Fixed-size arrays** — storing the snake's segments in an array.
3. **Array indexing and traversal** — accessing and checking individual segments.
4. **Array references** — passing the fixed-size snake array to a function by reference.
5. **Functions and modularity** — separating movement and food generation into functions.
6. **Variable scope and state** — using local and global variables to maintain game state.
7. **Loops** — using `for` and `while` loops to repeat operations.
8. **Nested loops** — visiting each row and column while drawing the board.
9. **Conditional statements** — using `if` and `else` to control game behaviour.
10. **Logical operators** — combining collision and input conditions with `&&` and `||`.
11. **Two-dimensional coordinates** — representing positions with horizontal (`x`) and vertical (`y`) values.
12. **Array shifting** — moving body segments from tail to head so each segment follows the one ahead.
13. **Pseudo-random number generation** — using `rand()`, `srand()`, and `time()` to place food.
14. **Recursion** — retrying food generation when a random position overlaps the snake.
15. **Keyboard polling and input** — using `_kbhit()` and `_getch()` to read keys without requiring Enter.
16. **Game-loop and state management** — repeatedly processing input, movement, collisions, and rendering while the game is running.
17. **Collision detection** — checking the head against the board walls and the rest of the snake.
18. **Console rendering, timing, and score tracking** — drawing the board, pacing updates with `Sleep()`, and updating the score when food is eaten.

## Implementation notes

- The snake's head is stored at `snake[0]`; the remaining occupied array elements represent its body.
- The movement function shifts segments from the tail towards the head before updating the head's coordinates.
- When food is eaten, the previous tail coordinates are saved and assigned to the new segment so the snake grows without losing its tail.
- Food generation checks the snake's occupied coordinates and retries if the generated position is already occupied.
- The snake is stored in a fixed-size array with a capacity of 100 segments.

## Possible future improvements

- Add a game-over screen and a restart option.
- Prevent immediate 180-degree direction reversals.
- Add a persistent high-score system using file handling.
- Replace the Windows-specific console functions to support other operating systems.
- Improve console drawing to reduce flicker.

---

Built as a hands-on C++ learning project.
