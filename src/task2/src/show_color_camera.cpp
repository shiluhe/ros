#include "show_color_camera.h"

void callback(const sensor_msgs::ImageConstPtr& ptr)
{
    cv_bridge::CvImagePtr cv_ptr;
    try {
        cv_ptr = cv_bridge::toCvCopy(ptr, sensor_msgs::image_encodings::BGR8);
    } catch (cv_bridge::Exception& e) {
        ROS_ERROR("cv_bridge exception: %s", e.what());
        return ;
    }
    cv::imshow("color_camera", cv_ptr->image);
    cv::waitKey(1);
    return ;
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "show_color_camera");
    ros::NodeHandle nodeHandle;
    image_transport::ImageTransport imageTransport(nodeHandle);
    image_transport::Subscriber subscriber = imageTransport.subscribe("/camera/color/image_raw", 1000, callback);
    ros::spin();

    return 0;
}