#include "show_point_cloud.h"
pcl::visualization::CloudViewer viewer ("Simple Cloud Viewer");
void pointcloudCallback(const sensor_msgs::PointCloud2::ConstPtr& msg)
{
    pcl::PointCloud<pcl::PointXYZ>cloud;
    pcl::PCLPointCloud2 pcl_pc;
    pcl_conversions::toPCL(*msg,pcl_pc);
    pcl::fromPCLPointCloud2(pcl_pc,cloud);
    viewer.showCloud(cloud.makeShared());
}
int main(int argc,char** argv)
{
    ros::init(argc,argv,"show_point_cloud");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("/rslidar_points",1000,pointcloudCallback);
    ros::spin();
    return 0;
}