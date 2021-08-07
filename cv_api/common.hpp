#ifndef CV_API_COMMON_HPP
#define CV_API_COMMON_HPP


#include <opencv2/core/utils/logger.hpp>


cv::Mat getTestImg() {
    return cv::imread("../data/lane.jpg");
}

void cv_show(const cv::String &name, cv::InputArray mat, bool needWaitKey) {
    cv::imshow(name, mat);
    if (needWaitKey)
        cv::waitKey(0);
}

void cv_destroyAllWindows() {
    cv::destroyAllWindows();
}

void cv_show(cv::InputArray mat, bool needWaitKey) {
    cv_show("default_name", mat, needWaitKey);
}

void cv_show(cv::InputArray mat) {
    cv_show("default_name", mat, true);
}

void cv_setLog() {
    //关闭log
    cv::utils::logging::setLogLevel(cv::utils::logging::LOG_LEVEL_SILENT);

    //如果想要输入特定级别的日志，可以这样设置
    cv::utils::logging::setLogLevel(cv::utils::logging::LOG_LEVEL_ERROR);
}

#endif