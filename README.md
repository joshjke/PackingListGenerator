# Packing List Generator

It uses the paramters of temperature, weather condition, nights spent, and days until items need replenished to generate a packing list. It shows a list of essentials along with their quantities.

## Getting Started

Open the project on a C++ editor and give it a shot.

## How it works

Currently, it builds a 2 array of objects that contain a name and an expiration date. The parameters for the array are the weather condition and the item number. The array is looped through for each item inside a category. The quantity of an item is determined through this formula: 
1 + int(days/daysUntilRefresh). It determines the amount of items needed based on when the need to be refreshed (ex: washed, replenished). They all begin with 1 and are added onto depending on how many nights are spent and the refreshment number.

### Prerequisites
```
MingW compiler || http://www.mingw.org/
```
## Current Stage
A short prototype for a clothing list and 4 different weather conditions

## Background
A hobby project since I don't like writing packing lists from scratch everytime I camp, move, hike, etc. 

## Authors

* **Josh Kennedy** 
