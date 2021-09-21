### Directory Structure

```
.02_Go_Chase_It
├── ball_chaser
│   ├── launch
│   │   └── ball_chaser.launch
│   ├── src
│   │   ├── drive_bot.cpp
│   │   └── process_image.cpp
│   └── srv
│       └── DriveToTarget.srv
│   ├── CMakeLists.txt
│   ├── package.xml
├── my_robot
│   ├── launch
│   │   ├── robot_description.launch
│   │   └── world.launch
│   ├── meshes
│   │   └── hokuyo.dae
│   ├── urdf
│   │   ├── my_robot.gazebo
│   │   └── my_robot.xacro
│   └── worlds
│       ├── empty.world
│       └── sam_world
│   ├── CMakeLists.txt
│   ├── package.xml
└── README.md
```

### Run the code
- Clone this repo
- Make the repo in your workspace
```
cd /home/workspace/catkin_ws/

catkin_make
```
- Load the world and its plugins using the my_robot launch file
```
source devel/setup.bash

roslaunch my_robot world.launch 
```
- Launch the ball_chaser node
```
cd /home/workspace/catkin_ws/

source devel/setup.bash

roslaunch ball_chaser ball_chaser.launch
```
- Use rqt to visualize what the robot sees
```
cd /home/workspace/catkin_ws/

source devel/setup.bash

rosrun rqt_image_view rqt_image_view
```