#pragma once
#include <iostream>
using namespace std;
#include "utilities.h"

const int maxrow=20;                    // Maximum number of rows in grid
const int maxcol=60;                    // Maximum number of columns in grid
void welcome();                         // Prints welcome banner

enum status {dead,alive};               // A cell has a binary state

class Life {
public:
    void initialize();                  // Populates the life grid
    void print() const;                 // Displays life grid; doesn't modify it!!!
    void update();                      // Ages the cells one generation
    int getGeneration() const;          // Accessor to get current generation
    int getLiving() const;              // Accessor to get current living cell count
private:
    int neighborCount(int,int) const;   // Counts living neighbors of a cell
    int generation;                     // Generation counter
    int living;                         // Living cells in this generation
    status decide(const int n);         // Decides whether a living cell dies
    status grid[maxrow][maxcol];        // Actual array the cells live in
};
