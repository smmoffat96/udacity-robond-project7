# udacity-robond-p7
Udacity Robotics Nanodegree Program - Project 7: Home Service Robot

This is my submission for Project 7: Home Service Robot for the Udacity Robotics Software Engineer Nanodegree Program.


This project completes the following tasks:

- Display a marker at the pickup zone

- Hide the marker once the robot reaches the pickup zone

- Wait 5 seconds to simulate a pickup

- Show the marker at the drop off zone once the robot reaches it


The following packages were used to achieve localization, mapping, and navigation: 

- gmapping (used amcl_demo.launch for SLAM)

- turtlebot_teleop (used keyboard_teleop.launch for manual control during development)

- turtlebot_rviz_launchers (used view_navigation.launch for loading an rviz configuration for navigation)

- turtlebot_gazebo (used turtlebot_world.launch for gazebo environment)

- pick_objects (used to send goal poses to robot)

- add_markers (used for marker visualization)
