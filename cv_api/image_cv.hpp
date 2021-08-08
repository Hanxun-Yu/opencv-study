//
// Created by xunxun on 2021/8/8.
//

#ifndef OPENCV_STUDY_IMAGE_CV_HPP
#define OPENCV_STUDY_IMAGE_CV_HPP

#include "common.hpp"

using namespace cv;

void image_canny() {
    auto img = getTestImgGraySmall();

    Mat cannyRes;
    Canny(img, cannyRes, 100, 200, 3, false);

    cv_show(cannyRes);
}

void image_hough_line() {
    auto img = getTestImgGraySmall();

    Mat cannyRes;
    Canny(img, cannyRes, 100, 200, 3, false);

    Mat houghRes;
    cvtColor(img, houghRes, cv::COLOR_GRAY2BGR);
    std::vector<Vec4f> lines;
    HoughLinesP(cannyRes, lines, 1, CV_PI / 180, 10, 8, 1);
    Scalar color = Scalar(0, 0, 255);
    for (size_t i = 0; i < lines.size(); i++) {
        Vec4f plines = lines[i];  //一个plines里边是四个点一条直线
        line(houghRes, Point(plines[0], plines[1]), Point(plines[2], plines[3]), color, 1, LINE_AA);
    }

    cv_show(houghRes);
}

#endif //OPENCV_STUDY_IMAGE_CV_HPP
