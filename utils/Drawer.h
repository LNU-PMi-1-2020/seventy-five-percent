#ifndef SEVENTY_FIVE_PERCENT_DRAWER_H
#define SEVENTY_FIVE_PERCENT_DRAWER_H


#include <vector>
#include "Drawable.h"

class Drawer {
private:
    Drawer() = default;

public:
    static void draw(Drawable drawable);

    static void draw(std::vector<Drawable> drawable);
};


#endif //SEVENTY_FIVE_PERCENT_DRAWER_H
