#include "show_imu.h"

void callback(const sensor_msgs::Imu::ConstPtr& ptr)
{
    std::cout << "std_msgs/Header header" << std::endl;
    std::cout << "    uint32 seq: " << ptr->header.seq << std::endl;
    std::cout << "    time stamp: " << ptr->header.stamp << std::endl;
    std::cout << "    string frame_id: " << ptr->header.frame_id << std::endl;
    std::cout << "geometry_msgs/Quaternion orientation" << std::endl;
    std::cout << "    float64 x: " << ptr->orientation.x << std::endl;
    std::cout << "    float64 y: " << ptr->orientation.y << std::endl;
    std::cout << "    float64 z: " << ptr->orientation.z << std::endl;
    std::cout << "    float64 w: " << ptr->orientation.w << std::endl;
    std::cout << "float64[9] orientation_covariance" << std::endl;
    std::cout << "    ";
    for (int i = 0; i < 9; ++i) {
        std::cout << ptr->orientation_covariance[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "geometry_msgs/Vector3 angular_velocity" << std::endl;
    std::cout << "    float64 x: " << ptr->angular_velocity.x << std::endl;
    std::cout << "    float64 y: " << ptr->angular_velocity.y << std::endl;
    std::cout << "    float64 z: " << ptr->angular_velocity.z << std::endl;
    std::cout << "float64[9] angular_velocity_covariance" << std::endl;
    std::cout << "    ";
    for (int i = 0; i < 9; ++i) {
        std::cout << ptr->angular_velocity_covariance[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "geometry_msgs/Vector3 linear_acceleration" << std::endl;
    std::cout << "    float64 x: " << ptr->linear_acceleration.x << std::endl;
    std::cout << "    float64 y: " << ptr->linear_acceleration.y << std::endl;
    std::cout << "    float64 z: " << ptr->linear_acceleration.z << std::endl;
    std::cout << "float64[9] linear_acceleration_covariance" << std::endl;
    std::cout << "    ";
    for (int i = 0; i < 9; ++i) {
        std::cout << ptr->linear_acceleration_covariance[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;
    return ;
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "show_imu");
    ros::NodeHandle nodeHandle;
    ros::Subscriber subscriber = nodeHandle.subscribe("/imu/data_raw", 1000, callback);
    ros::spin();
    return 0;
}