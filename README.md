# So_Long: Death's Collection

Welcome to "So_Long: Death's Collection", a 2D puzzle-adventure game where you guide Death on a quest to collect souls and find a passage to the living world. Developed in C and using the MiniLibX graphics library, this game showcases a rich blend of strategy, animation, and careful design to create an immersive gaming experience.

## Table of Contents
- [Installation](#installation)
- [Gameplay](#gameplay)
- [Features](#features)
- [Technical Details](#technical-details)
- [Contributing](#contributing)
- [License](#license)

## Installation

To set up the game on your local machine, follow these steps:

```bash
1. Clone the repository
- "git clone https://github.com/Safwaan-GitHub/so_long.git"

2. Change directory
- cd so_long

3. Compile the program
- make

4. Change Map if required (NOT NECESSARY)
- ./so_long/maps/map.ber
```

## Gameplay

In "So_Long: Death's Collection", players use the W, A, S, and D keys to navigate Death through a mystical realm. The goal is to collect all the souls on the map while avoiding animated enemies. Once all souls are collected, a portal to the living world appears - enter it to win the game!

The game provides immediate visual feedback via a movement counter displayed on-screen, which increases with each move Death makes. The counter not only scores player efficiency but also heightens the game's strategic depth.

## Features

    Animated Enemies: Encounter foes with unique animations that bring the realm to life.
    Map Validation: The game rigorously validates each level loaded from .ber files, ensuring all elements are placed correctly for an error-free experience.
    Memory Leak-Free: Meticulous memory management ensures a smooth, leak-free gaming experience.
    Custom Graphics: All visuals have been carefully crafted, utilizing the capabilities of MiniLibX for an engaging visual experience.

## Technical Details

"So_Long: Death's Collection" leverages the MiniLibX library, which is well-suited for rendering 2D graphics on Unix systems. The game features an efficient rendering system, which dynamically updates the graphics based on player movements and actions.

Map files are read and processed using our customized get_next_line function, which ensures robust reading of level designs. A thorough check of the map layout is performed to validate the placement of walls, collectables, and the overall integrity of each level.

The game structure and logic are carefully crafted to handle dynamic game states, manage animated sprites, and process user inputs without delay.

## Contributing

Contributions are welcome to "So_Long: Death's Collection". Please read CONTRIBUTING.md for details on our code of conduct, and the process for submitting pull requests to us.

## License

This project is licensed under the MIT License - see the LICENSE.md file for details.

This project is the property of [Safwaan Noor]. All contributions are subject to the license and any contributor agrees to the terms therein.
