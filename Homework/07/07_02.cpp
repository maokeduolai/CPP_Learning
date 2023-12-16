#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // 加载图像
    cv::Mat originalImage = cv::imread("Resource/Avatar.jpeg");

    if (originalImage.empty()) {
        std::cerr << "无法读取损坏图片！" << std::endl;
        return -1;
    }

    // 将图像转换为灰度图
    cv::Mat grayImage;
    cv::cvtColor(originalImage, grayImage, cv::COLOR_BGR2GRAY);

    // 将灰度图像二值化
    cv::Mat binaryImage;
    cv::threshold(grayImage, binaryImage, 128, 255,
                  cv::THRESH_BINARY);  // 阈值为 128，像素值大于 128 的像素将被设置为白色，小于 128 的像素将被设置为黑色

    // 将灰度图像进行高斯模糊处理
    cv::Mat blurredImage;
    cv::GaussianBlur(grayImage, blurredImage, cv::Size(5, 5), 3);

    // 显示原始图像和处理后的图像
    cv::imshow("Original Image", originalImage);
    cv::imshow("Gray Image", grayImage);
    cv::imshow("Binary Image", binaryImage);
    cv::imshow("Blurred Image", blurredImage);

    // 等待键盘输入，输入任意键后关闭窗口
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
