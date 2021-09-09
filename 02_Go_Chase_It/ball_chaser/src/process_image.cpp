#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

using namespace std;

// Define a global client that can request services
ros::ServiceClient client;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float lin_x, float ang_z)
{
    ROS_INFO_STREAM("Driving the robot");

    // TODO: Request a service and pass the velocities to it to drive the robot
    ball_chaser::DriveToTarget srv;

    srv.request.linear_x = lin_x;
    srv.request.angular_z = ang_z;

    //Call the command_robot service and pass the requested motor velocities
    if(!client.call(srv)){
        ROS_ERROR("Failed to call service command_robot");
    }
}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{
    int white_pixel = 255;
    
    int step = -1;
    bool ball_detected = false;

    // TODO: Loop through each pixel in the image and check if there's a bright white one
    for(int i = 0; i < (img.height * img.step); i++){
        if(img.data[i] == white_pixel &&
           img.data[i+1] == white_pixel &&
           img.data[i+2] == white_pixel)
        {
                step = i % img.step;
                ball_detected = true; 
                break;
        }
        else{
            ball_detected = false;
        }
    }

    // Then, identify if this pixel falls in the left, mid, or right side of the image
    if(ball_detected == true){
        // Depending on the white ball position, call the drive_bot function and pass velocities to it
        if(step <= img.step * 0.3 && step >= 0){
            // if the pixel is in the left area, turn left
            drive_robot(0.0,0.5);
            ROS_INFO("Turning Left");
        }
        else if(step > img.step * 0.7 && step <= img.step){
            // if the pixel is in the right area, turn right
            drive_robot(0.0,-0.5);
            ROS_INFO("Turning Right");
        }
        else if((step > img.step * 0.3 && step >=0 ) && (step <= img.step * 0.7 && step <= img.step)){
            // if the pixel is in the middle area, move forward in a straight line
            drive_robot(0.5,0.0);
            ROS_INFO("Moving forward");
        }
    }
    // Request a stop when there's no white ball seen by the camera
    else{
        drive_robot(0.0,0.0);
    }
}

int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    // Handle ROS communication events
    ros::spin();

    return 0;
}
