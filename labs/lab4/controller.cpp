#include "controller.h"
#include <iostream>

using namespace std;

Controller::Controller() {
    model = new Model(8,8);
    view = new View("Concentration!", 1024, 768);
}

Controller::~Controller() {
    delete model;
    delete view;
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
    cout << "Hooray, you win!" << endl;
}
