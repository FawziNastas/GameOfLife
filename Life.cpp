#include "Life.h"


void Life::initialize()
{
    int row,col = 0;                // Variables for rows and columns....

    generation=0;                   // Starting generation is zero
    living=0;                       // Nothing is alive, yet

    for (row=0;row<maxrow;row++)    // Default is nothing is alive
        for (col=0;col<maxcol;col++)
            grid[row][col]=dead;

    cout << "Enter row and column of living cells " <<
             "and finish with -1 -1" << endl;

    while ((row!=-1) || (col!=-1)) {
        cin >> row >> col;
        if (row==-1 && col==-1)
            cout << "Done" << endl;
        else if ((row<0) || (row>=maxrow))
            cout << "Row out of range" << endl;
        else if ((col<0) || (col>=maxcol))
            cout << "Column out of range" << endl;
        else {
            grid[row][col] = alive;
            living++;
        }
    }
} //Life::initialize

void Life::print() const                // Means function cannot modify any object member
{
    cout << endl << "Generation: " << generation
        << "; " << living << " living cells" << endl << endl;
    
    for (int row=0;row<maxrow;row++) {
        for (int col=0;col<maxcol;col++)
            if (alive==grid[row][col]) cout << "*";
            else cout << " ";
        cout << endl;
    }
    cout << endl;
} //Life:print


int Life::neighborCount(int row,int col) const  // Means function cannot modify any object member
{
    int br,er;              // beginning and ending row
    int bc,ec;              // beginning and ending column
    int i,j;                // Typical loop variables
    int t;                  // Tally of cells

    //Edge Cases

    if (0 == row) br=0;     // Can't go above the first row
    else br=row-1;          // Otherwise, start on row above
    if (0 == col) bc=0;     // Can't go before the first column
    else bc=col-1;          // Otherwise, start on column before
    if (row > maxrow-2)     // Can't go after last row
        er=maxrow-1;        // Arrays are zero based!!!
    else er=row+1;          // Row below this one
    if (col > maxcol-2)     // Can't go after last column
        ec=maxcol-1;        // Arrays are zero based!!!
    else ec=col+1;          // Column after this one
    
    // Loop and tally the living cells
    t=0;                                // Initialize the tally
    for (i=br;i<=er;i++)                // Go through all the rows in the octant
        for (j=bc;j<=ec;j++)            // Go through all the columns in the octant
            if ((i==row) && (j==col))   // Us??
                continue;               // Don't count our own cell!!!
            else if (alive==grid[i][j]) // Is it alive?
                t++;                    // Only count live neighbors
    return t;                           // Return final tally
} // Life::neighCount




status Life::decide (const int N) {
    switch (N) {
        case 0:                     // No neighbors alive?
        case 1:                     // One neighbor alive?
            return dead;            // Die of isolation
        case 2:                     // Two neighbors?
        case 3:                     // Three neighbors?
            return alive;           // Survive
        case 4:                     // Anything above 3 will
        case 5:                     // die of overcrowding
        case 6:
        case 7:
        case 8:
            return dead;
        default:                    // None of the above?  Just stay dead...
            return dead;
    }
} // Life::decide



void Life::update ()
{
    status snap[maxrow][maxcol];        // Snapshot or copy of grid
    int i,j;                            // Typical loop variables
    int n;                              // Neighbor count
    
    // No need to initialize snap since we are completely overwriting it
    for (i=0;i<maxrow;i++)              // Loop through all the rows
    for (j=0;j<maxcol;j++) {            // And all the columns!!
        n =neighborCount(i,j);          // First get neighbor count
        if (dead == grid[i][j]) {       // Is this dead?
            if (n == 3)                 // Exactly three neighbors alive?
                snap[i][j]=alive;       // Grow something here
            else snap[i][j]=dead;       // Otherwise it stays dead
        } else snap[i][j]=decide(n);    // Cell is alive, more complex rules
    }
  
    // Now that we are all done, copy the snapshot over the existing grid
    living=0;                           // Reset the living total
    for (i=0;i<maxrow;i++)
    for (j=0;j<maxcol;j++) {
            grid[i][j]=snap[i][j];      // Copy item over
            if (alive == grid[i][j])    // Is this cell alive?
                living++;               // Count living cell
    }
    
    generation++;                       // Finally bump the generation count
} // Life::update

// Some trivial accessor functions for testing

int Life::getGeneration() const { return generation; };
int Life::getLiving() const { return living; };

void welcome()
{
    cout << "Welcome to the game of life" << endl << endl;
}
