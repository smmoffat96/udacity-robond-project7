#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

int main(int argc, char** argv) {
    ros::init(argc, argv, "add_markers");
    ros::NodeHandle n;
    ros::Rate r(1);
    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

    while (ros::ok()) {
        // Define ros params
        std::string robot_pose;
        
        visualization_msgs::Marker marker;
        // Set the frame ID and timestamp
        marker.header.frame_id = "map";
        marker.header.stamp = ros::Time::now();
        marker.ns = "add_markers";
        marker.id = 0;
        // Shape
        marker.type = visualization_msgs::Marker::CUBE;
        // Scale
        marker.scale.x = 0.5;
        marker.scale.y = 0.5;
        marker.scale.z = 0.5;
        // Color
        marker.color.r = 0.0f;
        marker.color.g = 1.0f;
        marker.color.b = 0.0f;
        marker.color.a = 1.0;
            
        // Marker pose
        marker.pose.position.x = 1.0;
        marker.pose.position.y = 1.0;
        marker.pose.orientation.w = 1.0;
        
        marker.pose.position.z = 0;
        marker.pose.orientation.x = 0;
        marker.pose.orientation.y = 0;
        marker.pose.orientation.z = 0;

        marker.lifetime = ros::Duration();

        // Publish the marker
        while (marker_pub.getNumSubscribers() < 1) {
            if (!ros::ok()) {
                return 0;
            }
            ROS_WARN_ONCE("Please create a subscriber to the marker");
            sleep(1);
        }

        if (ros::param::get("/robot_pose", robot_pose)) {
            if (robot_pose == "init_pose") {
                ROS_INFO("Moving to pickup...");
                marker.action = visualization_msgs::Marker::ADD;
                marker_pub.publish(marker);
            }
            if (robot_pose == "pickup_pose") {
                // Leave in pickup pose for 5 seconds before hiding
                ROS_INFO("Picking up and transporting to dropoff...");
                ros::Duration(5.0).sleep();
                marker.action = visualization_msgs::Marker::DELETE;
                marker_pub.publish(marker);
            }
            if (robot_pose == "dropoff_pose") {
                marker.action = visualization_msgs::Marker::ADD;
                // Marker pose
                marker.pose.position.x = -2.0;
                marker.pose.position.y = -1.0;
                marker.pose.orientation.w = -1.0;
                marker_pub.publish(marker);
                ROS_INFO("Dropped off");
            }
        }
        r.sleep();
    }
}