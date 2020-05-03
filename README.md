# JetPipes

Yet another "pipes screensaver" powered by Qt3D.

## Rules

The default configuration defines 32 tubes randomly growing in a sphere of R=100 units.
Tubes cannot intersect each other, as well as they cannot grow beyond the scene's sphere.
Each tube is given several attempts to find the next point satisfying all requirements.
If a tube is stuck, it stops growing and when vast majority of tubes cannot advance, 
the scene got reset and start all over again.

## Controls

Press ESC key to close the app. Space key to toggle fullscreen/windowed mode.

## Technical Background

The application uses Qt3D module: https://doc.qt.io/qt-5/qt3d-index.html for visualization.
Each tube is defined by set of 3D points which then interpolated using Centripetal Catmull–Rom splines: 
https://en.wikipedia.org/wiki/Centripetal_Catmull%E2%80%93Rom_spline
After the final tube's path is estimated, the guided extrusion math is applied to generate the tube's mesh.
The current implementation is not very optimal in terms of performace, as it keeps regenerating all splines,
even for the immutable parts.


