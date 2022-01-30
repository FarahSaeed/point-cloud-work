// ----------------------------------------------------------------------------
// -                        open3d: www.open3d.org                            -
// ----------------------------------------------------------------------------
// the mit license (mit)
//
// copyright (c) 2018 www.open3d.org
//
// permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "software"), to deal
// in the software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the software, and to permit persons to whom the software is
// furnished to do so, subject to the following conditions:
//
// the above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the software.
//
// the software is provided "as is", without warranty of any kind, express or
// implied, including but not limited to the warranties of merchantability,
// fitness for a particular purpose and noninfringement. in no event shall the
// authors or copyright holders be liable for any claim, damages or other
// liability, whether in an action of contract, tort or otherwise, arising
// from, out of or in connection with the software or the use or other dealings
// in the software.
// ----------------------------------------------------------------------------
#pragma once
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <memory>
#include <thread>
#include "open3d/open3d.h"
#include "visualizerwithediting1.h"
#include "linmath.h"
#include <string>

int main(int argc, char* argv[]) {
    
    auto cloud_ptr = std::make_shared<open3d::geometry::PointCloud>();
        if (open3d::io::ReadPointCloud(
                   "pcds/DP1646 - Cloud.pcd"   // file_path     
            , *cloud_ptr)) {

        open3d::utility::LogInfo("successfully read ");       
        open3d::utility::LogInfo("successfully read {}\n", "0_pred (1).ply");
        open3d::visualization::VisualizerWithEditing1 vis;
        vis.CreateVisualizerWindow();
        vis.AddGeometry(cloud_ptr);
        // vis.rendersomething();
        vis.Run();
        vis.DestroyVisualizerWindow();
    }
    return 0;
}
