# Slay the Dragon
Project for my OOP course. Small card battler game inspired by [Slay the Spire](https://store.steampowered.com/app/646570/Slay_the_Spire/).

## Objective

You start each round with 3 energy and 5 cards from your deck which will either deal damage, block the dragon's attacks, or both. Playing cards costs energy, so you have to play your cards wisely and try to slay the dragon as fast as possible. At the end of the round, all 5 cards go into your discard pile. Once your deck is empty, your entire discard pile is shuffled into your deck.

## String parsing system for deck-building

The **deck.txt** file can be modified in order to implement your own cards. Each line represents a card, with its name, description, energy cost, attack value and shield value separated by commas.

    