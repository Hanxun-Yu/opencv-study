#include "common.hpp"

#ifndef CV_API_READ_HPP
#define CV_API_READ_HPP

void read_img() {
//    long start = getMillisecond();

    cv::log(false);
    //读取图片，内存中默认为bgr
    cv::Mat img = getTestImg();

    //读取图片，转灰度
    //    cv::Mat img = cv::imread("../data/lane.jpg",cv::IMREAD_GRAYSCALE);

    //彩色转灰度
    cv::Mat img_gray;
    cv::cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);

//    long end = getMillisecond();
//    printf("time:%ld\n",end-start);

    cv_show(img_gray);
}

void read_video() {
    cv::VideoCapture vc = cv::VideoCapture("../data/day_lldw2.3gp");
    double fps = vc.get(cv::CAP_PROP_FPS);
    printf("read_video fps:%f",fps);

    int frame_gap = 1000 / fps; //指定播放间隔

    cv::Mat frame;
    while (vc.isOpened()) {
        bool read_flag = vc.read(frame);
        if (!read_flag) {
            break;
        } else {
            cv::imshow("img", frame);
            int exit_key = 27; //指定播放时的退出键
            if ((cv::waitKey(frame_gap) & 0xff) == exit_key) {
                break;
            }
        }
    }
    vc.release();
    cv::destroyAllWindows();
}

#endif