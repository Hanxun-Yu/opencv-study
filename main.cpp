#include "opencv2/opencv.hpp"
#include "read.hpp"
#include "common.hpp"
#include "TimeHelper.hpp"
#include "image_process.hpp"
#include "image_cv.hpp"

int main() {
    std::cout << "opencv:" << cv::getVersionString() << std::endl;

//    test_time();
    cv_setLog();
//    read_img();
//    read_video();

//    image_roi();
//    image_channel();

//    image_border();
//    image_value_cal();
//    image_threshold();
//    image_smooth();
//    image_erode();
//    image_dilate();
//    image_morph_open_close();
//    image_gradient();

//    image_canny();
    image_hough_line();
    cv_destroyAllWindows();
    return 0;
}
