
#### Steps 

(1) Build c++ project with Open3d (https://github.com/isl-org/open3d-cmake-find-package).

(2) Open project in visual studio and add provided cpp and header files.

(3) Program starts from source.cpp which has main function.


##### Controls

-- Editing control --

F            : Enter freeview mode.

X            : Enter orthogonal view along X axis, press again to flip.

Y            : Enter orthogonal view along Y axis, press again to flip.

Z            : Enter orthogonal view along Z axis, press again to flip.

K            : Lock / unlock camera.

Ctrl + D     : Downsample point cloud with a voxel grid.

Ctrl + R     : Reset geometry to its initial state.

Ctrl + P     : Change color.

Shift + +/-  : Increase/decrease picked point size.

Shift + mouse left button   : Pick a point and add in queue.

Shift + mouse right button  : Remove last picked point from queue.

-- When camera is locked --

Mouse left button + drag    : Create a selection rectangle.

Ctrl + mouse buttons + drag : Hold Ctrl key to draw a selection polygon. Release Ctrl key to close the polygon.

C                           : Annotate/Crop the geometry with selection region.

