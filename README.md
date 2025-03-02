# Slay the Dragon
A turn-based card battler inspired by [Slay the Spire](https://store.steampowered.com/app/646570/Slay_the_Spire/) made in C++ in order to learn the principles of Object Oriented Programming and design patterns.

The goal of the game is to defeat one of the three enemies as quickly as possible using a combination of cards and potions. Each round begins with 3 energy and 5 cards drawn from your deck. Cards can deal damage, block incoming attacks, or provide a combination of both. Energy is limited, so careful strategy is required to maximize efficiency and defeat the enemy quickly. At the end of each round, the cards used are added to the discard pile, and when the deck is depleted, the discard pile is shuffled back into the deck.

## Classes
- **Game Manager** - Responsible for handling all game inputs and managing the console-based user interface. Implements the Singleton pattern to ensure a single instance controls the game's state and flow.
- **Card** - Represents a playing card in the game, storing attributes such as cost, damage dealt, and block received.
- **Potions** - Stores information about each starting potion and tracks whether they have been consumed.
- **Player** - Represents the player in the game, managing their stats, deck, hand, and allowing them to use potions.
- **Enemy** - An abstract class that defines and manages the base stats for all enemies.
- **Skeleton** - Inherits from Enemy and adds a unique interaction, allowing the Skeleton to heal itself while dealing damage.
- **Dark Elf** - Inherits from Enemy and adds a unique interaction, allowing the Dark Elf to increase its attack for future turns.
- **Dragon** - Inherits from Enemy and adds a unique interaction, allowing the Dragon to destroy cards in the player's deck.
- **Enemy Factory** - Implements the Factory design pattern to create different types of enemies in the game. It is responsible for generating enemy objects based on the current game difficulty.

## Features
- Displays an interactive user interface in the console.
- The [deck.txt](deck.txt) file can be modified in order to implement your own cards. Each line represents a card, with its name, description, energy cost, attack value and shield value separated by commas.
- Implemented error handling throughout the game, ensuring that invalid inputs and unexpected card formats are managed without crashing the application.

    
