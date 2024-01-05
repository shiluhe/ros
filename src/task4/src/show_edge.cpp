#include "show_edge.h"
static const std::string OPENCV_WINDOW = "Raw Image window";
static const std::string OPENCV_WINDOW_1 = "Edge Detection";
class Edge_Detector
{
  ros::NodeHandle nh_;
  image_transport::ImageTransport it_;
  image_transport::Subscriber image_sub_;
  image_transport::Publisher image_pub_;
public:
  Edge_Detector()
    : it_(nh_)
  {
    // Subscribe to input video feed and publish output video feed
    image_sub_ = it_.subscribe("/camera/color/image_raw", 1, 
      &Edge_Detector::imageCb, this);
    image_pub_ = it_.advertise("/edge_detector/raw_image", 1);
    cv::namedWindow(OPENCV_WINDOW);
  }
  ~Edge_Detector()
  {
    cv::destroyWindow(OPENCV_WINDOW);
  }
//回调函数
  void imageCb(const sensor_msgs::ImageConstPtr& msg)
  {
    cv_bridge::CvImagePtr cv_ptr;
    namespace enc = sensor_msgs::image_encodings;
    try
    {
      cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    }
    catch (cv_bridge::Exception& e)
    {
      ROS_ERROR("cv_bridge exception: %s", e.what());
      return;
    }
    // Draw an example circle on the video stream
    if (cv_ptr->image.rows > 400 && cv_ptr->image.cols > 600){
	detect_edges(cv_ptr->image);
    	image_pub_.publish(cv_ptr->toImageMsg());
	}
  }
  //OpenCV的边缘检测程序
  void detect_edges(cv::Mat img)
  {
 
   	cv::Mat src, src_gray;
	cv::Mat dst, detected_edges;
	int edgeThresh = 1;
	int lowThreshold = 200;
	int highThreshold =300;
	int kernel_size = 5;
	img.copyTo(src);
	cv::cvtColor( img, src_gray, CV_BGR2GRAY );
        cv::blur( src_gray, detected_edges, cv::Size(5,5) );
	cv::Canny( detected_edges, detected_edges, lowThreshold, highThreshold, kernel_size );
 
  	dst = cv::Scalar::all(0);
  	img.copyTo( dst, detected_edges);
	dst.copyTo(img);
 
    	cv::imshow(OPENCV_WINDOW, src);
    	cv::imshow(OPENCV_WINDOW_1, dst);
    	cv::waitKey(3);
  }	
};
int main(int argc, char** argv)
{
  ros::init(argc, argv, "Edge");
  Edge_Detector ic;
  ros::spin();
  return 0;
}