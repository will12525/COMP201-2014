#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

enum State { FIRST, SECOND, MATCH, NO_MATCH };
// Concentration game model
// The model manages the state of the game
class Model {
public:
    // Constructor (instantiates object)
    // Initialize a grid of letters randomly
    Model(int w, int h);
    // Destructor deletes all dynamically allocated stuff
    ~Model();
    // Methods (member functions)
    // Return the width
    int getWidth();
    // Return the height
    int getHeight();
    // Return visible stuff (invisible stuff is shown with character *)
    char get(int row, int column);
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
	int lastRow2;
    int lastColumn2;
    State state;
};

// Show (output) the state of the model
class View {
public:
    // Print out the visible stuff in the grid
    void show(Model * model);
};

// Handle input
class Controller {
public:
    Controller() {
        model = new Model(8,8);
        view = new View;
    }
    // Event loop
    void loop();
private:
    Model * model;
    View * view;
};

// Constructor initializes the object
Model::Model(int w, int h) {
    width = w;
    height = h;
    lastRow = -1;
    lastColumn = -1;
    state = FIRST;
    grid = new char*[h];
    visible = new char*[h];
	char letters[] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','!','@','#','$','%','^','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','!','@','#','$','%','^'};
	srand(time(0));
	for(int x=0;x<4000;x++)
	{
		int num1 = rand()%64;
		int num2 = rand()%64;
		char letter1 = letters[num1];
		char letter2 = letters[num2];
		letters[num1]=letter2;
		letters[num2]=letter1;
	}
	
    for (int i = 0; i < height; i++) {
        grid[i] = new char[w];
        visible[i] = new char[w];
    }
	int index=0;
    // TODO: make this random-ish
    for (int i = 0; i < height; i++) 
	{
        for (int j = 0; j < width; j++) 
		{
		
			grid[i][j] = letters[index];//this needs to be random
			visible[i][j] = '*';
			index++;
        }
    }
	state=FIRST;
	ofstream stream;
	stream.open("cheatcode.txt");
	
	for(int y=0;y<height;y++)
	{
		for(int x=0;x<width;x++)
		{
			stream<<grid[y][x]<<" ";
		}
		stream<<endl;
	}
	stream.close();
}
// Destructor deletes dynamically allocated memory
Model::~Model() {
    for (int i = 0; i < height; i++) {
        delete grid[i];
        delete visible[i];
    }
    delete grid;
    delete visible;
}
// TODO: Is the row/column valid?
// That is, is the row within the height, and is the column within the width?
// Return whether it is or isn't.
bool Model::valid(int row, int column) {
	if(row>7||row<0||column>7||column<0)
	{
		cout<<"Choice is out of range\n";
		return false;
	}
	if(visible[row][column]!='*')
	{
		cout<<"Choice is already used\n";
		return false;
	}
    return true;
}
bool Model::matched(int row, int column) {
    return true;
}
// TODO: Flip a cell
void Model::flip(int row, int column) {
    // If the row and column are not valid, break out and don't do anything
    if (!valid(row, column)) { return; }
    
	if(state==NO_MATCH)
	{
		visible[lastRow][lastColumn]='*';
		visible[lastRow2][lastColumn2]='*';
		state=FIRST;
	}
	
	if(state==FIRST)
	{
		visible[row][column]=grid[row][column];
		lastRow=row;
		lastColumn=column;
		state=SECOND;
	}
	else if(state==SECOND)
	{
		visible[row][column]=grid[row][column];
		state=FIRST;
	}
	
	if(visible[row][column]!=visible[lastRow][lastColumn])
	{	
		lastRow2=row;
		lastColumn2=column;
		state=NO_MATCH;
	}
	
	
		
    // If the last selected row and column are invalid,
        // It means we're selecting the first "cell" to flip
    // Otherwise, we are selecting the next "cell" to flip
        // If the last cell and the current cell match, great!
        // Otherwise, make the last cell invisible (set it to *)
    // Make the current cell visible
	
	
}
// If everything is visible, then it's game over
bool Model::gameOver() {

	for(int y=0;y<height;y++)
	{
		for(int x=0;x<width;x++)
		{
			if(visible[y][x]=='*')
			{
				return false;
			}
		}
	}
    // Hint: assume the game is over, unless it isn't
    // Hint: Loop through the grid and see if any element is not visible
    return true;
}
int Model::getWidth() {
    return width;
}
int Model::getHeight() {
    return height;
}
char Model::get(int row, int col) {
    return visible[row][col];
}
// Show the model, one cell at a time
void View::show(Model * model) {
    for (int j = 0; j < model->getWidth(); j++) {
        cout << "\t" << j;
    }
    cout << endl;
    for (int i = 0; i < model->getHeight(); i++) {
        cout << i;
        for (int j = 0; j < model->getWidth(); j++) {
            cout << "\t" << model->get(i, j);
        }
        cout << endl;
    }
}

// Show the board
// Read in coordinates
// Until we're done
void Controller::loop() {
    int row, col;
    while (!model->gameOver()) {
        view->show(model);
        cout << "Enter row:    ";
        cin >> row;
        cout << "Enter column: ";
        cin >> col;
        model->flip(row, col);
    }
	cout<<"You win!\n";
	
}

int main() {
    Controller c;
    c.loop();
}