#include "show_odometry.h"

void callback(const nav_msgs::Odometry::ConstPtr& ptr)
{
    std::cout << "std_msgs/Header header" << std::endl;
    std::cout << "    uint32 seq: " << ptr->header.seq << std::endl;
    std::cout << "    time stamp: " << ptr->header.stamp << std::endl;
    std::cout << "    string frame_id: " << ptr->header.frame_id << std::endl;
    std::cout << "string child_frame_id: " << ptr->child_frame_id << std::endl;
    std::cout << "geometry_msgs/PoseWithCovariance pose" << std::endl;
    std::cout << "    geometry_msgs/Pose pose" << std::endl;
    std::cout << "        geometry_msgs/Point position" << std::endl;
    std::cout << "        float64 x: " << ptr->pose.pose.position.x << std::endl;
    std::cout << "        float64 y: " << ptr->pose.pose.position.y << std::endl;
    std::cout << "        float64 z: " << ptr->pose.pose.position.z << std::endl;
    std::cout << "    geometry_msgs/Quaternion orientation" << std::endl;
    std::cout << "        float64 x: " << ptr->pose.pose.orientation.x << std::endl;
    std::cout << "        float64 y: " << ptr->pose.pose.orientation.y << std::endl;
    std::cout << "        float64 z: " << ptr->pose.pose.orientation.z << std::endl;
    std::cout << "        float64 w: " << ptr->pose.pose.orientation.w << std::endl;
    std::cout << "    float64[36] covariance" << std::endl;
    std::cout << "        " << std::endl;
    for (int i = 0; i < 36; ++i) {
        std::cout << ptr->pose.covariance[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "geometry_msgs/TwistWithCovariance twist" << std::endl;
    std::cout << "    geometry_msgs/Twist twist" << std::endl;
    std::cout << "        geometry_msgs/Vector3 linear" << std::endl;
    std::cout << "            float64 x: " << ptr->twist.twist.linear.x << std::endl;
    std::cout << "            float64 y: " << ptr->twist.twist.linear.y << std::endl;
    std::cout << "            float64 z: " << ptr->twist.twist.linear.z << std::endl;
    std::cout << "        geometry_msgs/Vector3 angular" << std::endl;
    std::cout << "            float64 x: " << ptr->twist.twist.angular.x << std::endl;
    std::cout << "            float64 y: " << ptr->twist.twist.angular.y << std::endl;
    std::cout << "            float64 z: " << ptr->twist.twist.angular.z << std::endl;
    std::cout << "    float64[36] covariance" << std::endl;
    std::cout << "        " << std::endl;
    for (int i = 0; i < 36; ++i) {
        std::cout << ptr->twist.covariance[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;
    return ;
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "show_odometry");
    ros::NodeHandle nodeHandle;
    ros::Subscriber subscriber = nodeHandle.subscribe("/odom", 1000, callback);
    ros::spin();
    return 0;
}