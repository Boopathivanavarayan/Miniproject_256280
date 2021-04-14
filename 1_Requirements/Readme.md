# Requirements
<img src="https://github.com/Boopathivanavarayan/Miniproject_256280/blob/main/5_ImagesAndVideos/name1.PNG" width="800" height="100">

## Introduction
 Remember Mr.Bean? Frictional charater from the popular British Comedy Programme, famous not only among children but also among the elders. A man who tought us how to enjoy our own company. Being a smart, attractive, weird and innovative one day he visits a country fete. Among many other fun games there, he also plays this intresting **WIRE LOOP GAME**. This mini-project aims to implement the same in sofware environment using C programming. 

## Research

### Wire Loop Game
In real time game play, the player will be given a metal loop or probe. The player will then be guiding this probe along a serpentine length of wire without touching the loop to the wire. The system is set in such a way when loop and the wire touch it completes an electric circuit containg a light emmiting diode(LED) or buzzer connected to the power supply, as result of circuit completion the LED emmits light or the buzzer makes a buzz sound. This game demand good hand-eye coordination.
### Sate of Art
- This traditional game has got an android, online and virual reality versions.
- Serveral variants of this game are also available where this gaming concept has been refined and remodeled.
- What is new in our variant is that we will be using keyboard as an input interface in such a way that it engages left and right brain activity along with hand-eye coordination.  
## Cost and Features

- Game support different levels.
- Game contains a simple interface.
- Offline game.
## Defining Our System
<img src="https://github.com/Boopathivanavarayan/Miniproject_256280/blob/main/5_ImagesAndVideos/defsys.PNG" width="450" height="450">

## SWOT ANALYSIS

<img src="https://github.com/Boopathivanavarayan/Miniproject_256280/blob/main/5_ImagesAndVideos/swot.PNG" width="450" height="450">

# 4W&#39;s and 1&#39;H

## Who:

- People of all age groups.
- People who prefer to choose lightweight games for temporary relaxation and refreshment.

## What:

- Virtual version of Wire Loop Game.
- Differ from its other variants by providing complete keyboard interface.

## When:

- Can be played anytime.

## Where:

- Can be played anywhere with PC.

## How:

- Require 8 control keys to play the game. 
- First set of 4 keys controls upper probe pointer to prevent it from touching the wire.
- Next set of 4 keys controls lower probe pointer to prevent it from touching the wire.

# Detail requirements
## High Level Requirements:
 | ID | Description | Status (Implemented/Future) |
 | ------ | --------- | ------ |
 | HLR01 | Show game interface when select start | Implemented |
 | HLR02 | Enable to change control keys when select change setting | Implemented |
 | HLR03 | Exit game when select exit | Implemented |
 | HLR04 | Store score log | Implemented |
 | HLR05 | Display score | Implemented |


##  Low level Requirements:
| ID | Description | HLR ID | Status (Implemented/Future) |
| ------ | --------- | ------ | ----- |
| LLR01 | Getting and storing user's game ID | HLR01 | Implemented |
| LLR02 | Creating and stroing diffrent patterns of game play | HLR01 | Implemented |
| LLR03 | Providing options to select users own set of keys  | HLR02 | Implemented |
| LLR04 | Creating option to take user back to menu mode | HLR02,HLR03 | Implemented |
| LLR05 | Acquiring the time taken to complete game for score calculation | HLR05 | Implemented |