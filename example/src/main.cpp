// ========================================================================================
//  ApproxMVBB 
//  Copyright (C) 2014 by Gabriel Nützi <nuetzig (at) imes (d0t) mavt (d0t) ethz (døt) ch>
//  
//  Licensed under GNU General Public License 3.0 or later. 
//  Some rights reserved. See COPYING, README.rst.
//
//  @license GPL-3.0 <http://www.gnu.org/licenses/gpl-3.0.html>
// ========================================================================================

#include <iostream>


#include "ApproxMVBB/ComputeApproxMVBB.hpp"

int  main( int  argc, char  ** argv ){

    unsigned int nPoints = 10000;

    std::cout << "Sample "<<nPoints<<" points in unite cube (coordinates are in world frame I) " << std::endl;
    ApproxMVBB::Matrix3Dyn points(3,10000);
    points.setRandom();

    ApproxMVBB::OOBB oobb = ApproxMVBB::approximateMVBB(points,0.001,500,5,0,5);

    std::cout << "Computed OOBB: " << std::endl
              << "---> lower point in OOBB frame: " << oobb.m_minPoint.transpose() << std::endl
              << "---> upper point in OOBB frame: " << oobb.m_maxPoint.transpose() << std::endl
              << "---> coordinate transformation A_IK matrix from OOBB frame K to world frame I" << std::endl
              << oobb.m_q_KI.matrix() << std::endl
              << "---> this is also the rotation matrix R_KI  which turns the world frame I into the OOBB frame K" << std::endl;


    return 0;
}
