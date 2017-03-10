#include "stdafx.h"
#include <iostream>
#include "SFML\Graphics.hpp"

#include "Framework.hpp"
#include "Point.hpp"



int main()
{
    int testing = 0;
    if (testing == 0)
    {
        Framework mFramework;
        mFramework.run();

        std::getchar();
        return 0;
    }
    else
    {
        //Only for testing stuff
        Point mPoint(fd::Vector4f(0));
        fd::Matrix42f erg = mPoint.correctEdge(fd::Vector4f({3.f,2.f,-2.f,2.f}), fd::Vector4f({5.f,11.f,3.f,-2.f}));
        std::cout << (float) erg.at(0,0) << " " << erg.at(1,0) << " " << erg.at(2,0) << " " << erg.at(3,0) << std::endl;
        std::cout << (float) erg.at(0,1) << " " << erg.at(1,1) << " " << erg.at(2,1) << " " << erg.at(3,1) << std::endl;

    }

}

