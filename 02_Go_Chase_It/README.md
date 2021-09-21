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