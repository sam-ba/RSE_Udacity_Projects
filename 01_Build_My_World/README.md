### Directory Structure
```
.01_Build_My_World
├── model
│   ├── boxer
│   │   ├── model.config
│   │   └── model.sdf
│   └── mybuilding
│       ├── model.config
│       └── model.sdf
├── script
│   ├── hello.cpp
│   └── welcome.cpp
└── world
    ├── myworld
    └── sam_world
├── CMakeLists.txt
├── README.md
```

### Run 
- Clone this repository
- Create the build directory in the top level by running:
```
mkdir build && cd build
```
- Compile the code in the build directory:
```
cmake .. && make
```
- Export the plugin folder in the terminal: 
```
export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:/home/workspace/01_Build_My_World/build
``` 
- Launch the world file in Gazebo:
```
cd /home/workspace/01_Build_My_World/

gazebo sam_world
```