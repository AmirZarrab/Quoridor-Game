#include <iostream> // Include the input-output library for console operations

using namespace std; // Use the standard namespace to avoid prefixing with 'std::'

// Global 2D array representing the game board
char A[19][19]; // Initialize a 19x19 character array to represent the game board

// Function to initialize the game screen with player positions and walls
int screen(int ip, int jp, int ir, int jr)
{
    // Variables for iterating through the board and initializing positions
    int m = 2, n = 2, q = 2, w = 1;
    
    // Set initial markers on the board (Columns for walls and moves)
    A[0][0] = '*'; // Top left corner marker
    A[0][2] = 'a'; // Column labels for wall placements
    A[0][4] = 'b';
    A[0][6] = 'c';
    A[0][8] = 'd';
    A[0][10] = 'e';
    A[0][12] = 'f';
    A[0][14] = 'g';
    A[0][16] = 'h';
    A[0][18] = 'i';

    // Set row markers for wall placements
    A[2][0] = 'A'; // Row labels for wall placements
    A[4][0] = 'B';
    A[6][0] = 'C';
    A[8][0] = 'D';
    A[10][0] = 'E';
    A[12][0] = 'F';
    A[14][0] = 'G';
    A[16][0] = 'H';
    A[18][0] = 'I';

    // Initialize the board with 'O' for empty spaces
    while (m < 19)
    {
        n = 2; // Start from the second column
        while (n < 19)
        {
            A[m][n] = 'O'; // Set each cell to 'O'
            n = n + 2; // Move to the next column
        }
        m = m + 2; // Move to the next row
    }

    // Set initial player positions
    A[ip][jp] = 'P'; // Player P position
    A[ir][jr] = 'R'; // Player R position
}

// Main function to run the game
int main()
{
    // Variables to control game flow and player actions
    int n = 0;        // Turn counter
    int a = 0, b = 0; // Menu selection variables
    int c = 0, d = 0; // Move and wall options
    int ip = 2, jp = 10; // Initial position for Player P
    int ir = 18, jr = 10; // Initial position for Player R
    int Woodr = 10, Woodp = 10; // Available walls for each player
    int column = 0, row = 0; // Wall placement positions
    int istar1 = 0, jstar1 = 0, istar2 = 0, jstar2 = 0; // Coordinates for wall placements

    // Display game start menu
    cout << "1.Start Game" << endl << "2.Exit" << endl;
    cout << "Please Choose Number: ";
    cin >> a;
    cout << endl;

    // Validate menu selection
    while (a < 1 || a > 2)
    {
        cout << "Please Choose Correct Number: ";
        cin >> a;
    }

    // Initialize game board with players' positions
    screen(ip, jp, ir, jr);

    // Display initial game board state
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            cout << A[i][j] << "  "; // Print each cell value
        }
        cout << endl; // New line for the next row
    }

    // If the player chooses to exit
    if (a == 2)
    {
        cout << "End!"; // Display end message
        return 0; // Exit the program
    }
    else // If the player chooses to start the game
    {
        // Game loop
        while (1) // Infinite loop until break conditions are met
        {
            if (n % 2 == 0) // Player R's turn (even turn count)
            {
                // Display Player R's turn options
                cout << endl << "Player R" << endl;
                cout << endl << "1.Add Wall" << endl << "2.Move" << endl;
                cout << "Please Choose Number: ";
                cin >> b;

                // Validate Player R's choice
                while (b < 1 || b > 2)
                {
                    cout << "Please Choose Correct Number: ";
                    cin >> b;
                }

                if (b == 1) // If Player R chooses to add a wall
                {
                    if (Woodr > 0) // Check if Player R has walls left
                    {
                        // Display wall placement options
                        cout << endl << "R Wood number is " << Woodr;
                        cout << endl << endl << "1.Horizontal" << endl << "2.Vertical" << endl;
                        cout << "Please Choose Number: ";
                        cin >> d;
                        // Validate wall placement direction
                    
                        while (d < 1 || d > 2)
                        {
                            cout << "Please Choose Correct Number: "; // Prompt user for correct input
                            cin >> d;
                        }

                        if (d == 1) // If Player R chooses to place a horizontal wall
                        {
                            // Prompt user to choose the column for wall placement
                            cout << endl << "1.a" << "    " << "2.b" << "    " << "3.c" << "    " << "4.d" << "    " << "5.e" << "    " << "6.f" << "    " << "7.g" << "    " << "8.h" << endl;
                            cout << "Please Choose Number: ";
                            cin >> column;
                            cout << endl;

                            // Validate column choice
                            while (column < 1 || column > 8)
                            {
                                cout << "Please Choose Correct Number: "; // Ask again for valid input
                                cin >> column;
                            }

                            // Prompt user to choose the row for wall placement
                            cout << endl << "1.AB" << "    " << "2.BC" << "    " << "3.CD" << "    " << "4.DE" << "    " << "5.EF" << "    " << "6.FG" << "    " << "7.GH" << "    " << "8.HI" << endl;
                            cout << "Please Choose Number: ";
                            cin >> row;
                            cout << endl;

                            // Validate row choice
                            while (row < 1 || row > 8)
                            {
                                cout << "Please Choose Correct Number: "; // Ask again for valid input
                                cin >> row;
                            }

                            // Calculate the positions for the wall
                            istar1 = 2 * row + 1; // Starting row position for horizontal wall
                            jstar1 = 2 * column; // Starting column position
                            istar2 = 2 * row + 1; // Ending row position for horizontal wall
                            jstar2 = 2 * column + 2; // Ending column position

                            screen(ip, jp, ir, jr); // Refresh the screen with updated positions

                            // Check for collisions or invalid wall placements
                            if (A[istar1 - 1][jstar1 + 1] == '*' || A[istar1 - 1][jstar1 + 1] == ' ')
                            {
                                cout << endl << "!ERROR!" << endl; // Display error for collision
                                continue; // Restart loop for new input
                            }

                            // Additional checks for wall placement
                            if (A[istar1][jstar1] == '*' || A[istar2][jstar2] == '*')
                            {
                                cout << endl << "!ERROR!" << endl; // Display error if wall position is occupied
                                continue; // Restart loop for new input
                            }
                            else // Valid placement
                            {
                                A[istar1][jstar1] = '*'; // Place the first part of the wall
                                A[istar2][jstar2] = '*'; // Place the second part of the wall

                                // Print the updated board state
                                for (int i = 0; i < 19; i++)
                                {
                                    for (int j = 0; j < 19; j++)
                                    {
                                        cout << A[i][j] << "  "; // Print each cell
                                    }
                                    cout << endl; // New line for the next row
                                }
                            }
                        }
                        else if (d == 2) // If Player R chooses to place a vertical wall
                        {
                            // Prompt user to choose the row for wall placement
                            cout << endl << "1.A" << "    " << "2.B" << "    " << "3.C" << "    " << "4.D" << "    " << "5.E" << "    " << "6.F" << "    " << "7.G" << "    " << "8.H" << endl;
                            cout << "Please Choose Number: ";
                            cin >> row;
                            cout << endl;

                            // Validate row choice
                            while (row < 1 || row > 8)
                            {
                                cout << "Please Choose Correct Number: "; // Ask again for valid input
                                cin >> row;
                            }

                            // Prompt user to choose the column for wall placement
                            cout << endl << "1.ab" << "    " << "2.bc" << "    " << "3.cd" << "    " << "4.de" << "    " << "5.ef" << "    " << "6.fg" << "    " << "7.gh" << "    " << "8.hi" << endl;
                            cout << "Please Choose Number: ";
                            cin >> column;
                            cout << endl;

                            // Validate column choice
                            while (column < 1 || column > 8)
                            {
                                cout << "Please Choose Correct Number: "; // Ask again for valid input
                                cin >> column;
                            }

                            // Calculate the positions for the wall
                            istar1 = 2 * row; // Starting row position for vertical wall
                            jstar1 = 2 * column + 1; // Starting column position
                            istar2 = 2 * row + 2; // Ending row position for vertical wall
                            jstar2 = 2 * column + 1; // Ending column position

                            screen(ip, jp, ir, jr); // Refresh the screen with updated positions

                            // Check for collisions or invalid wall placements
                            if (A[istar1 + 1][jstar1 - 1] == '*' || A[istar1 + 1][jstar1 - 1] == ' ')
                            {
                                cout << endl << "!ERROR!" << endl; // Display error for collision
                                continue; // Restart loop for new input
                            }
                            // Check if the wall position is already occupied
                            if (A[istar1][jstar1] == '*' || A[istar2][jstar2] == '*')
                            {
                                cout << endl << "!ERROR!" << endl; // Display error if wall position is occupied
                                continue; // Restart loop for new input
                            }
                            else // Valid wall placement
                            {
                                A[istar1][jstar1] = '*'; // Place the first part of the wall
                                A[istar2][jstar2] = '*'; // Place the second part of the wall

                                // Print the updated board state
                                for (int i = 0; i < 19; i++)
                                {
                                    for (int j = 0; j < 19; j++)
                                    {
                                        cout << A[i][j] << "  "; // Print each cell
                                    }
                                    cout << endl; // New line for the next row
                                }
                            }
                        }
                    }
                    else // Invalid input for wall placement
                    {
                        cout << "!ERROR!"; // Display error message
                        continue; // Restart loop for new input
                    }
                    
                    Woodr--; // Decrement Player R's available walls
                }
                else if (b == 2) // If Player R chooses to move
                {
                    // Display move options
                    cout << endl << "1.Up" << endl << "2.Down" << endl << "3.Left" << endl << "4.Right" << endl;
                    cout << "Please Choose Number: ";
                    cin >> c;
                    cout << endl;

                    // Validate move choice
                    while (c < 1 || c > 4)
                    {
                        cout << "Please Choose Correct Number: "; // Ask for a valid move
                        cin >> c;
                    }

                    if (c == 1) // Move Up
                    {
                        if (A[ir - 1][jr] != '*') // Check if the path is clear
                        {
                            if (ir - 2 == 2) // Check if Player R has reached the winning row
                            {
                                cout << "YOU WIN" << endl; // Player R wins
                                break; // End the game
                            }
                            if (A[ir - 2][jr] != 'P') // Check if the space ahead is not occupied by Player P
                            {
                                ir = ir - 2; // Move Player R up
                                screen(ip, jp, ir, jr); // Refresh the screen with updated positions

                                // Print the updated board state
                                for (int i = 0; i < 19; i++)
                                {
                                    for (int j = 0; j < 19; j++)
                                    {
                                        cout << A[i][j] << "  "; // Print each cell
                                    }
                                    cout << endl; // New line for the next row
                                }
                            }
                            else // If the space ahead is occupied by Player P
                            {
                                if (A[ir - 3][jr] == '*') // Check if moving further up is blocked by a wall
                                {    
                                    cout << endl << "!ERROR!" << endl; // Display error message
                                    continue; // Restart loop for new input
                                }
                                else // Move Player R further up if not blocked
                                {
                                    ir = ir - 4; // Move Player R up by two additional spaces
                                    screen(ip, jp, ir, jr); // Refresh the screen with updated positions

                                    // Print the updated board state
                                    for (int i = 0; i < 19; i++)
                                    {
                                        for (int j = 0; j < 19; j++)
                                        {
                                            cout << A[i][j] << "  "; // Print each cell
                                        }
                                        cout << endl; // New line for the next row
                                    }
                                }
                            }
                        }
                        else // If the path is blocked
                        {
                            cout << "!ERROR!"; // Display error message
                            continue; // Restart loop for new input
                        }
                    }

                    else if (c == 2) // Move Down
                    {
                        if (A[ir + 1][jr] != '*') // Check if the path downward is clear
                        {
                            if (ir + 2 > 18) // Check if Player R is at the bottom boundary
                            {
                                cout << "!ERROR!" << endl; // Display error message if out of bounds
                                continue; // Restart loop for new input
                            }
                            if (A[ir + 2][jr] != 'P') // Check if the space ahead is not occupied by Player P
                            {
                                ir = ir + 2; // Move Player R down
                                screen(ip, jp, ir, jr); // Refresh the screen with updated positions

                                // Print the updated board state
                                for (int i = 0; i < 19; i++)
                                {
                                    for (int j = 0; j < 19; j++)
                                    {
                                        cout << A[i][j] << "  "; // Print each cell
                                    }
                                    cout << endl; // New line for the next row
                                }
                            }
                            else // If the space ahead is occupied by Player P
                            {
                                if (A[ir + 3][jr] == '*') // Check if moving further down is blocked by a wall
                                {    
                                    cout << endl << "!ERROR!" << endl; // Display error message
                                    continue; // Restart loop for new input
                                }
                                else // Move Player R further down if not blocked
                                {
                                    ir = ir + 4; // Move Player R down by two additional spaces
                                    screen(ip, jp, ir, jr); // Refresh the screen with updated positions

                                    // Print the updated board state
                                    for (int i = 0; i < 19; i++)
                                    {
                                        for (int j = 0; j < 19; j++)
                                        {
                                            cout << A[i][j] << "  "; // Print each cell
                                        }
                                        cout << endl; // New line for the next row
                                    }
                                }    
                            }
                        }
                        else // If the path downward is blocked
                        {
                            cout << "!ERROR!"; // Display error message
                            continue; // Restart loop for new input
                        }
                    }

                    else if (c == 3) // Move Left
                    {
                        if (A[ir][jr - 1] != '*') // Check if the path to the left is clear
                        {
                            if (jr - 2 < 2) // Check if Player R is at the left boundary
                            {
                                cout << "!ERROR!" << endl; // Display error message if out of bounds
                                continue; // Restart loop for new input
                            }            
                            if (A[ir][jr - 2] != 'P') // Check if the space to the left is not occupied by Player P
                            {
                                jr = jr - 2; // Move Player R left
                                screen(ip, jp, ir, jr); // Refresh the screen with updated positions

                                // Print the updated board state
                                for (int i = 0; i < 19; i++)
                                {
                                    for (int j = 0; j < 19; j++)
                                    {
                                        cout << A[i][j] << "  "; // Print each cell
                                    }
                                    cout << endl; // New line for the next row
                                }
                            }
                            else // If the space to the left is occupied by Player P
                            {
                                if (A[ir][jr - 3] == '*') // Check if moving further left is blocked by a wall
                                {    
                                    cout << endl << "!ERROR!" << endl; // Display error message
                                    continue; // Restart loop for new input
                                }
                                else // Move Player R further left if not blocked
                                {
                                    jr = jr - 4; // Move Player R left by two additional spaces
                                    screen(ip, jp, ir, jr); // Refresh the screen with updated positions

                                    // Print the updated board state
                                    for (int i = 0; i < 19; i++)
                                    {
                                        for (int j = 0; j < 19; j++)
                                        {
                                            cout << A[i][j] << "  "; // Print each cell
                                        }
                                        cout << endl; // New line for the next row
                                    }
                                }    
                            }
                        }
                        else // If the path to the left is blocked
                        {
                            cout << "!ERROR!"; // Display error message
                            continue; // Restart loop for new input                            
                        }
                    }

                    else if (c == 4) // Move Right
                    {
                        if (A[ir][jr + 1] != '*') // Check if the path to the right is clear
                        {
                            if (jr + 2 > 18) // Check if Player R is at the right boundary
                            {
                                cout << "!ERROR!" << endl; // Display error message if out of bounds
                                continue; // Restart loop for new input
                            }
                            if (A[ir][jr + 2] != 'P') // Check if the space to the right is not occupied by Player P
                            {    
                                jr = jr + 2; // Move Player R right
                                screen(ip, jp, ir, jr); // Refresh the screen with updated positions

                                // Print the updated board state
                                for (int i = 0; i < 19; i++)
                                {
                                    for (int j = 0; j < 19; j++)
                                    {
                                        cout << A[i][j] << "  "; // Print each cell
                                    }
                                    cout << endl; // New line for the next row
                                }
                            }
                            else // If the space to the right is occupied by Player P
                            {
                                if (A[ir][jr + 3] == '*') // Check if moving further right is blocked by a wall
                                {    
                                    cout << endl << "!ERROR!" << endl; // Display error message
                                    continue; // Restart loop for new input
                                }
                                else // Move Player R further right if not blocked
                                {
                                    jr = jr + 4; // Move Player R right by two additional spaces
                                    screen(ip, jp, ir, jr); // Refresh the screen with updated positions

                                    // Print the updated board state
                                    for (int i = 0; i < 19; i++)
                                    {
                                        for (int j = 0; j < 19; j++)
                                        {
                                            cout << A[i][j] << "  "; // Print each cell
                                        }
                                        cout << endl; // New line for the next row
                                    }
                                }
                            }
                        }
                        else // If the path to the right is blocked
                        {
                            cout << "!ERROR!"; // Display error message
                            continue; // Restart loop for new input                            
                        }
                    }            
                }
            }
            
            else if (n % 2 == 1) // Player P's turn (odd turn count)
            {
                cout << endl << "Player P" << endl;
                cout << endl << "1.Add Wall" << endl << "2.Move" << endl;
                cout << "Please Choose Number: ";
                cin >> b;

                // Validate Player P's choice
                while (b < 1 || b > 2)
                {
                    cout << "Please Choose Correct Number: "; // Ask for a valid input
                    cin >> b;
                }
                
                if (b == 1) // If Player P chooses to add a wall
                {
                    if (Woodp > 0) // Check if Player P has walls left
                    {
                        // Display wall placement options for Player P
                        cout << endl << "P Wood number is " << Woodp;
                        cout << endl << "1.Horizontal" << endl << "2.Vertical" << endl;
                        cout << "Please Choose Number: ";
                        cin >> d;

                        // Validate wall placement direction
                        while (d < 1 || d > 2)
                        {
                            cout << "Please Choose Correct Number: "; // Ask again for valid input
                            cin >> d;
                        }

                        if (d == 1) // If Player P chooses to place a horizontal wall
                        {
                            // Prompt user to choose the column for wall placement
                            cout << endl << "1.a" << "    " << "2.b" << "    " << "3.c" << "    " << "4.d" << "    " << "5.e" << "    " << "6.f" << "    " << "7.g" << "    " << "8.h" << endl;
                            cout << "Please Choose Number: ";
                            cin >> column;
                            cout << endl;

                            // Validate column choice
                            while (column < 1 || column > 8)
                            {
                                cout << "Please Choose Correct Number: "; // Ask again for valid input
                                cin >> column;
                            }

                            // Prompt user to choose the row for wall placement
                            cout << endl << "1.AB" << "    " << "2.BC" << "    " << "3.CD" << "    " << "4.DE" << "    " << "5.EF" << "    " << "6.FG" << "    " << "7.GH" << "    " << "8.HI" << endl;
                            cout << "Please Choose Number: ";
                            cin >> row;
                            cout << endl;

                            // Validate row choice
                            while (row < 1 || row > 8)
                            {
                                cout << "Please Choose Correct Number: "; // Ask again for valid input
                                cin >> row;    
                            }

                            // Calculate the positions for the wall
                            istar1 = 2 * row + 1; // Starting row position for horizontal wall
                            jstar1 = 2 * column; // Starting column position
                            istar2 = 2 * row + 1; // Ending row position for horizontal wall
                            jstar2 = 2 * column + 2; // Ending column position
                            screen(ip, jp, ir, jr); // Refresh the screen with updated positions
                            
                            // Check for collisions or invalid wall placements for a horizontal wall
                            if (A[istar1 - 1][jstar1 + 1] == '*' || A[istar1 - 1][jstar1 + 1] == ' ')
                            {
                                cout << endl << "!ERROR!" << endl; // Display error if a wall or empty space is found
                                continue; // Restart loop for new input
                            }
                            
                            // Check if the selected wall positions are already occupied
                            if (A[istar1][jstar1] == '*' || A[istar2][jstar2] == '*')
                            {
                                cout << endl << "!ERROR!" << endl; // Display error if wall positions are already occupied
                                continue; // Restart loop for new input
                            }
                            else // Valid wall placement
                            {
                                A[istar1][jstar1] = '*'; // Place the first part of the wall
                                A[istar2][jstar2] = '*'; // Place the second part of the wall

                                // Print the updated board state
                                for (int i = 0; i < 19; i++)
                                {
                                    for (int j = 0; j < 19; j++)
                                    {
                                        cout << A[i][j] << "  "; // Print each cell
                                    }
                                    cout << endl; // New line for the next row
                                }    
                            }
                    }
                        
                    else if (d == 2) // If Player P chooses to place a vertical wall
                    {
                        // Prompt user to choose the row for wall placement
                        cout << endl << "1.A" << "    " << "2.B" << "    " << "3.C" << "    " << "4.D" << "    " << "5.E" << "    " << "6.F" << "    " << "7.G" << "    " << "8.H" << endl;
                        cout << "Please Choose Number: ";
                        cin >> row;
                        cout << endl;

                        // Validate row choice
                        while (row < 1 || row > 8)
                        {
                            cout << "Please Choose Correct Number: "; // Ask again for valid input
                            cin >> row;
                        }

                        // Prompt user to choose the column for wall placement
                        cout << endl << "1.ab" << "    " << "2.bc" << "    " << "3.cd" << "    " << "4.de" << "    " << "5.ef" << "    " << "6.fg" << "    " << "7.gh" << "    " << "8.hi" << endl;
                        cout << "Please Choose Number: ";
                        cin >> column;
                        cout << endl;

                        // Validate column choice
                        while (column < 1 || column > 8)
                        {
                            cout << "Please Choose Correct Number: "; // Ask again for valid input
                            cin >> column;
                        }

                        // Calculate the positions for the wall
                        istar1 = 2 * row; // Starting row position for vertical wall
                        jstar1 = 2 * column + 1; // Starting column position
                        istar2 = 2 * row + 2; // Ending row position for vertical wall
                        jstar2 = 2 * column + 1; // Ending column position

                        screen(ip, jp, ir, jr); // Refresh the screen with updated positions

                        // Check for collisions or invalid wall placements for a vertical wall
                        if (A[istar1 + 1][jstar1 - 1] == '*' || A[istar1 + 1][jstar1 - 1] == ' ')
                        {
                            cout << endl << "!ERROR!" << endl; // Display error if a wall or empty space is found
                            continue; // Restart loop for new input
                        }

                        // Check if the selected wall positions are already occupied
                        if (A[istar1][jstar1] == '*' || A[istar2][jstar2] == '*')
                        {
                            cout << endl << "!ERROR!" << endl; // Display error if wall positions are already occupied
                            continue; // Restart loop for new input
                        }
                        else // Valid wall placement
                        {
                            A[istar1][jstar1] = '*'; // Place the first part of the wall
                            A[istar2][jstar2] = '*'; // Place the second part of the wall

                            // Print the updated board state
                            for (int i = 0; i < 19; i++)
                            {
                                for (int j = 0; j < 19; j++)
                                {
                                    cout << A[i][j] << "  "; // Print each cell
                                }
                                cout << endl; // New line for the next row
                            }    
                        }
                    }
                }
                else // Invalid input for wall placement
                {
                    cout << "!ERROR!"; // Display error message
                    n++; // Increment turn counter
                    continue; // Restart loop for new input
                }
                Woodp--; // Decrement Player P's available walls
            }

            else if (b == 2) // If Player P chooses to move
            {
                // Display move options for Player P
                cout << endl << "1.Up" << endl << "2.Down" << endl << "3.Left" << endl << "4.Right" << endl;
                cout << "Please Choose Number: ";
                cin >> c;
                cout << endl;

                // Validate move choice
                while (c < 1 || c > 4)
                {
                    cout << "Please Choose Correct Number: "; // Ask for a valid move
                    cin >> c;
                }
            
                if (c == 1) // Move Up
                {
                    if (A[ip - 1][jp] != '*') // Check if the path upward is clear
                    {
                        if (ip - 2 < 2) // Check if Player P is at the top boundary
                        {
                            cout << "!ERROR!" << endl; // Display error message if out of bounds
                            continue; // Restart loop for new input
                        }
                        if (A[ip - 2][jp] != 'R') // Check if the space upward is not occupied by Player R
                        {
                            ip = ip - 2; // Move Player P up
                            screen(ip, jp, ir, jr); // Refresh the screen with updated positions

                            // Print the updated board state
                            for (int i = 0; i < 19; i++)
                            {
                                for (int j = 0; j < 19; j++)
                                {
                                    cout << A[i][j] << "  "; // Print each cell
                                }
                                cout << endl; // New line for the next row
                            }
                        }
                        else // If the space upward is occupied by Player R
                        {
                            if (A[ip - 3][jp] == '*') // Check if moving further up is blocked by a wall
                            {    
                                cout << endl << "!ERROR!" << endl; // Display error message
                                n++; // Increment turn counter
                                continue; // Restart loop for new input
                            }
                            else // Move Player P further up if not blocked
                            {
                                ip = ip - 4; // Move Player P up by two additional spaces
                                screen(ip, jp, ir, jr); // Refresh the screen with updated positions

                                // Print the updated board state
                                for (int i = 0; i < 19; i++)
                                {
                                    for (int j = 0; j < 19; j++)
                                    {
                                        cout << A[i][j] << "  "; // Print each cell
                                    }
                                    cout << endl; // New line for the next row
                                }
                            }
                        }
                    }
                    else // If the path upward is blocked
                    {
                        cout << "!ERROR!" << endl; // Display error message
                        continue; // Restart loop for new input                            
                    }
                }

                else if (c == 2) // Move Down
                {
                    if (A[ip + 1][jp] != '*') // Check if the path downward is clear
                    {
                        if (ip + 2 == 18) // Check if Player P has reached the bottom boundary (winning condition)
                        {
                            cout << "YOU WIN" << endl; // Player P wins
                            ip = ip + 2; // Move Player P down to the winning position
                            screen(ip, jp, ir, jr); // Refresh the screen with updated positions

                            // Print the updated board state
                            for (int i = 0; i < 19; i++)
                            {
                                for (int j = 0; j < 19; j++)
                                {
                                    cout << A[i][j] << "  "; // Print each cell
                                }
                                cout << endl; // New line for the next row
                            }
                            break; // End the game
                        }
                        if (A[ip + 2][jp] != 'R') // Check if the space downward is not occupied by Player R
                        {
                            ip = ip + 2; // Move Player P down
                            screen(ip, jp, ir, jr); // Refresh the screen with updated positions

                            // Print the updated board state
                            for (int i = 0; i < 19; i++)
                            {
                                for (int j = 0; j < 19; j++)
                                {
                                    cout << A[i][j] << "  "; // Print each cell
                                }
                                cout << endl; // New line for the next row
                            }
                        }
                        else // If the space downward is occupied by Player R
                        {
                            if (A[ip + 3][jp] == '*') // Check if moving further down is blocked by a wall
                            {    
                                cout << endl << "!ERROR!" << endl; // Display error message
                                continue; // Restart loop for new input
                            }
                            else // Move Player P further down if not blocked
                            {
                                ip = ip + 4; // Move Player P down by two additional spaces
                                screen(ip, jp, ir, jr); // Refresh the screen with updated positions

                                // Print the updated board state
                                for (int i = 0; i < 19; i++)
                                {
                                    for (int j = 0; j < 19; j++)
                                    {
                                        cout << A[i][j] << "  "; // Print each cell
                                    }
                                    cout << endl; // New line for the next row
                                }
                            }
                        }
                    }
                    else // If the path downward is blocked
                    {
                        cout << "!ERROR!" << endl; // Display error message
                        continue; // Restart loop for new input
                    }
                }
                else if (c == 3) // Move Left
                {
                    if (A[ip][jp - 1] != '*') // Check if the path to the left is clear
                    {
                        if (jp - 2 < 2) // Check if Player P is at the left boundary
                        {
                            cout << "!ERROR!" << endl; // Display error message if out of bounds
                            continue; // Restart loop for new input
                        }        
                        if (A[ip][jp - 2] != 'R') // Check if the space to the left is not occupied by Player R
                        {
                            jp = jp - 2; // Move Player P left
                            screen(ip, jp, ir, jr); // Refresh the screen with updated positions

                            // Print the updated board state
                            for (int i = 0; i < 19; i++)
                            {
                                for (int j = 0; j < 19; j++)
                                {
                                    cout << A[i][j] << "  "; // Print each cell
                                }
                                cout << endl; // New line for the next row
                            }
                        }
                        else // If the space to the left is occupied by Player R
                        {
                            if (A[ip][jp - 3] == '*') // Check if moving further left is blocked by a wall
                            {    
                                cout << endl << "!ERROR!" << endl; // Display error message
                                continue; // Restart loop for new input
                            }
                            else // Move Player P further left if not blocked
                            {
                                jp = jp - 4; // Move Player P left by two additional spaces
                                screen(ip, jp, ir, jr); // Refresh the screen with updated positions

                                // Print the updated board state
                                for (int i = 0; i < 19; i++)
                                {
                                    for (int j = 0; j < 19; j++)
                                    {
                                        cout << A[i][j] << "  "; // Print each cell
                                    }
                                    cout << endl; // New line for the next row
                                }
                            }                            
                        }
                    }
                    else // If the path to the left is blocked
                    {
                        cout << "!ERROR!" << endl; // Display error message
                        continue; // Restart loop for new input                            
                    }
                }

                else if (c == 4) // Move Right
                {
                    if (A[ip][jp + 1] != '*') // Check if the path to the right is clear
                    {
                        if (jp + 2 > 18) // Check if Player P is at the right boundary
                        {
                            cout << "!ERROR!" << endl; // Display error message if out of bounds
                            continue; // Restart loop for new input
                        }            
                        if (A[ip][jp + 2] != 'R') // Check if the space to the right is not occupied by Player R
                        {
                            jp = jp + 2; // Move Player P right
                            screen(ip, jp, ir, jr); // Refresh the screen with updated positions

                            // Print the updated board state
                            for (int i = 0; i < 19; i++)
                            {
                                for (int j = 0; j < 19; j++)
                                {
                                    cout << A[i][j] << "  "; // Print each cell
                                }
                                cout << endl; // New line for the next row
                            }
                        }
                        else // If the space to the right is occupied by Player R
                        {
                            if (A[ip][jp + 3] == '*') // Check if moving further right is blocked by a wall
                            {    
                                cout << endl << "!ERROR!" << endl; // Display error message
                                continue; // Restart loop for new input
                            }
                            else // Move Player P further right if not blocked
                            {
                                jp = jp + 4; // Move Player P right by two additional spaces
                                screen(ip, jp, ir, jr); // Refresh the screen with updated positions

                                // Print the updated board state
                                for (int i = 0; i < 19; i++)
                                {
                                    for (int j = 0; j < 19; j++)
                                    {
                                        cout << A[i][j] << "  "; // Print each cell
                                    }
                                    cout << endl; // New line for the next row
                                }
                            }                                
                        }
                    }
                    else // If the path to the right is blocked
                    {
                        cout << "!ERROR!" << endl; // Display error message
                        continue; // Restart loop for new input                                    
                    }
                }            
            }
        }
    n++; // Increment turn counter after each complete turn
    }

    }
}
