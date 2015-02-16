#include "model.h"

#ifndef _VIEW_H
#define _VIEW_H

// Show (output) the state of the model
class View {
public:
    // Print out the visible stuff in the grid
    void show(Model * model);
};
#endif