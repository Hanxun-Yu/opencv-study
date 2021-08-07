#ifndef CV_API_IMAGEPROCESS_HPP
#define CV_API_IMAGEPROCESS_HPP

#include "common.hpp"

void image_roi() {
    cv::Mat img = getTestImg();
    img = img(cv::Rect(20, 20, 200, 300));

    cv_show(img);
}

/**
 * 通道
 */
void image_channel() {
    cv::Mat img = getTestImg();
    int channel_count = img.channels();

    //split
    printf("channel_count:%d", channel_count);
    cv::Mat *channelMatArr = new cv::Mat[channel_count]; //提取出 b,g,r 3个通道到 3个Mat
    cv::split(img, channelMatArr);
    //直接显示这3个通道，是看不出 bgr结果的，因为是以灰度形式显示的
    //    cv_show(channelMatArr[0]);
    //    cv_show(channelMatArr[1]);
    //    cv_show(channelMatArr[2]);

    //merge 把多通道合并
    cv::Mat mergeMat;
    cv::merge(channelMatArr, channel_count, mergeMat);
//    cv_show(mergeMat);
    delete[] channelMatArr;

    //分别显示rgb----------------------------------------

    //显示r通道
    channelMatArr = new cv::Mat[channel_count];
    cv::split(img, channelMatArr);
    channelMatArr[0] = 0; //b
    channelMatArr[1] = 0; //g
    cv::Mat r_mat;
    cv::merge(channelMatArr, channel_count, r_mat);
//    cv_show(r_mat);
    delete[] channelMatArr;

    //显示g通道
    channelMatArr = new cv::Mat[channel_count];
    cv::split(img, channelMatArr);
    channelMatArr[0] = 0; //b
    channelMatArr[2] = 0; //r
    cv::Mat g_mat;
    cv::merge(channelMatArr, channel_count, g_mat);
//    cv_show(g_mat);
    delete[] channelMatArr;


    //显示g通道
    channelMatArr = new cv::Mat[channel_count];
    cv::split(img, channelMatArr);
    channelMatArr[1] = 0; //g
    channelMatArr[2] = 0; //r
    cv::Mat b_mat;
    cv::merge(channelMatArr, channel_count, b_mat);
    cv_show(b_mat);
    delete[] channelMatArr;


}

/**
 * 外扩边 并填充
 */
void image_border() {
    auto img = getTestImg();

    auto left_border = 20;
    auto top_border = 20;
    auto right_border = 20;
    auto bottom_border = 20;

    cv::Mat original;
    cv::resize(img, original, cv::Size(200, 200));

    cv::Mat replicate;
    cv::Mat reflect;
    cv::Mat reflect101;
    cv::Mat wrap;
    cv::Mat constant;

    cv::copyMakeBorder(original, replicate, top_border, bottom_border, left_border, right_border, cv::BORDER_REPLICATE);
    cv::copyMakeBorder(original, reflect, top_border, bottom_border, left_border, right_border, cv::BORDER_REFLECT);
    cv::copyMakeBorder(original, reflect101, top_border, bottom_border, left_border, right_border,
                       cv::BORDER_REFLECT101);
    cv::copyMakeBorder(original, wrap, top_border, bottom_border, left_border, right_border, cv::BORDER_WRAP);

    //填充常量 最后1个参数是色值
    cv::copyMakeBorder(original, constant, top_border, bottom_border, left_border, right_border, cv::BORDER_CONSTANT,
                       cv::Scalar(100));

    cv_show("original", original, false);
    cv_show("replicate", replicate, false);
    cv_show("reflect", reflect, false);
    cv_show("reflect101", reflect101, false);
    cv_show("wrap", wrap, false);
    cv_show("constant", constant, true);
}

/**
 * 数值计算
 */
void image_value_cal() {
    auto img = getTestImg();

    cv::print(img(cv::Rect(20, 20, 5, 5)));

    //元素加50 （只对图像第一个通道有效）
    img = img + 50;
    printf("\n");
    cv::print(img(cv::Rect(20, 20, 5, 5)));

}

/**
 * 阈值处理
 */
void image_threshold() {
    auto img = getTestImg();
    cv::cvtColor(img, img, cv::COLOR_BGR2GRAY);
    cv::resize(img, img, cv::Size(200, 200));

    cv::Mat binary;
    cv::Mat binary_inv;
    cv::Mat trunc;
    cv::Mat tozero;
    cv::Mat tozero_inv;

    //二值化 大于127 取255 否则取0
    cv::threshold(img, binary, 127, 255, cv::THRESH_BINARY);
    //二值化反转 小于127 取255 否则取0
    cv::threshold(img, binary_inv, 127, 255, cv::THRESH_BINARY_INV);
    //截断值 大于127 取127  否则不变
    cv::threshold(img, trunc, 127, 255, cv::THRESH_TRUNC);
    //tozero 大于127 不变  否则取0
    cv::threshold(img, tozero, 127, 255, cv::THRESH_TOZERO);
    //tozero反转 小于127 不变  否则取0
    cv::threshold(img, tozero_inv, 127, 255, cv::THRESH_TOZERO_INV);

    cv_show("original", img, false);
    cv_show("binary", binary, false);
    cv_show("binary_inv", binary_inv, false);
    cv_show("trunc", trunc, false);
    cv_show("tozero", tozero, false);
    cv_show("tozero_inv", tozero_inv, true);

}

/**
 * 平滑处理
 */
void image_smooth() {
    auto img = getTestImg();
    cv::resize(img, img, cv::Size(300, 300));

    cv::Mat img_blur;


    //均值滤波 卷积后求平均数 cv::Size(3,3) 表示3x3卷积核
    cv::blur(img, img_blur, cv::Size(3, 3));
    cv_show("blur",img_blur, false);

    //高斯滤波
    cv::GaussianBlur(img, img_blur, cv::Size(3, 3),1);
    cv_show("GaussianBlur",img_blur, false);

    //中值滤波
    cv::medianBlur(img, img_blur, 3);
    cv_show("medianBlur",img_blur, false);


    cv_show("original",img,true);
}

/**
 * 腐蚀操作
 */
void image_erode() {
    auto img = getTestImg();
    cv::cvtColor(img, img, cv::COLOR_BGR2GRAY);
    cv::resize(img, img, cv::Size(300, 300));
    //二值化方便腐蚀操作
    cv::Mat binary;
    cv::threshold(img, binary, 127, 255, cv::THRESH_BINARY);

    cv::Mat erode;
    cv::erode(binary,erode,cv::Mat());

    cv_show("erode",erode, false);
    cv_show("binary",binary,true);
}

#endif