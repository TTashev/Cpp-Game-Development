#include <iostream>
#include "../App/App.h"

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int MAGNIFICATION = 1;

int main(int argc, char** args)
{
    if( App::Singleton().Init(SCREEN_WIDTH, SCREEN_HEIGHT, MAGNIFICATION) )
    {
        App::Singleton().Run();
    }

    return 0;
}

