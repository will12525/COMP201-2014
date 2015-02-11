#include <iostream>
#include <ctime>

using namespace std;

enum State { FIRST, MATCH, NO_MATCH };
// Concentration game model
// The model manages the state of the game
class Model {
public:
    // Constructor (instantiates object)
    // Initialize a grid of letters randomly
	// Constructor initializes the object
    Model(int w, int h)
	{
		width = w;
		height = h;
		lastRow = -1;
		lastColumn = -1;
		state = FIRST;
		grid = new char*[h];
		visible = new char*[h];
		
		char letters[] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
		
		for (int i = 0; i < height; i++) 
		{
			grid[i] = new char[w];
			visible[i] = new char[w];
		}
		srand(time(0)); //do stuff with rand() % 26
		// TODO: make this random-ish
		for (int i = 0; i < height; i++) 
		{
			for (int j = 0; j < width; j++) 
			{
				grid[i][j] = 'a';//this needs to be random
				visible[i][j] = '*';
			}
		}
	}
    // Destructor deletes all dynamically allocated stuff
	// Destructor deletes dynamically allocated memory
    ~Model()
	{
		for (int i = 0; i < height; i++) 
		{
			delete grid[i];
			delete visible[i];
		}
		delete grid;
		delete visible;
	}
    // Methods (member functions)
    // Return the width
    int getWidth()
	{
		return width;
	}
    // Return the height
    int getHeight()
	{
		return height;
	}
    // Return visible stuff (invisible stuff is shown with character *)
    char get(int row, int column)
	{
		return visible[row][col];
	}
    // Flip this row/column
    void flip(int row, int column);
    // Is the game over?
    bool gameOver();
private:
    // Is the row/column valid?
    bool valid(int row, int column);
    // Did the cell at current row/column match the cell at the last row/column 
    bool matched(int row, int column);
    // Fields (member data)
    // Randomly generated grid. This has pairs of characters in it
    char ** grid;
    // What is visible to the user?
    char ** visible;
    // What's the width?
    int width;
    // What's the height?
    int height;
    // What'd we flip last?
    int lastRow;
    int lastColumn;
    State state;
};

// Show (output) the state of the model
class View {
public:
    // Print out the visible stuff in the grid
	// Show the model, one cell at a time
    void show(Model * model)
	{
		for (int j = 0; j < model->getWidth(); j++) 
		{
			cout << "\t" << j;
		}
		cout << endl;
		for (int i = 0; i < model->getHeight(); i++) 
		{
			cout << i;
			for (int j = 0; j < model->getWidth(); j++) 
			{
				cout << "\t" << model->get(i, j);
			}
			cout << endl;
		}
    }
};

// Handle input
class Controller {
public:
    Controller() {
        model = new Model(8,8);
        view = new View;
    }
	~Controller()
	{
		delete model;
		delete view;
	}
    // Event loop
	// Show the board
	// Read in coordinates
	// Until we're done
    void loop()
	{
		int row, col;
		while (!model->gameOver()) 
		{
			view->show(model);
			cout << "Enter row:    ";
			cin >> row;
			cout << "Enter column: ";
			cin >> col;
			model->flip(row, col);
		}
		cout<<"You win!\n";
	}
private:
    Model * model;
    View * view;
};

// TODO: Is the row/column valid?
// That is, is the row within the height, and is the column within the width?
// Return whether it is or isn't.
bool Model::valid(int row, int column) {
    return true;
}
bool Model::matched(int row, int column) {
    return true;
}
// TODO: Flip a cell
void Model::flip(int row, int column) {
    // If the row and column are not valid, break out and don't do anything
    if (!valid(row, column)) { return; }
    
    // If the last selected row and column are invalid,
        // It means we're selecting the first "cell" to flip
    // Otherwise, we are selecting the next "cell" to flip
        // If the last cell and the current cell match, great!
        // Otherwise, make the last cell invisible (set it to *)
    // Make the current cell visible
}
// If everything is visible, then it's game over
bool Model::gameOver() {
    // Hint: assume the game is over, unless it isn't
    // Hint: Loop through the grid and see if any element is not visible
    return false;
}

int main() {
    Controller c;
    c.loop();
}
