#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // 加载图像
    cv::Mat originalImage = cv::imread("Resource/Avatar.jpeg");

    if (originalImage.empty()) {
        std::cerr << "无法读取损坏图片！" << std::endl;
        return -1;
    }

    // 检测图像边缘
    cv::Mat edges;
    cv::Canny(originalImage, edges, 50, 150);

    // 进行膨胀操作
    cv::Mat dilatedImage;
    cv::dilate(edges, dilatedImage, cv::Mat(), cv::Point(-1, -1), 2);

    // 进行侵蚀操作
    cv::Mat erodedImage;
    cv::erode(dilatedImage, erodedImage, cv::Mat(), cv::Point(-1, -1), 2);

    // 改变图像大小，缩放为50%
    cv::Mat resizedImage;
    cv::resize(originalImage, resizedImage, cv::Size(), 0.5, 0.5);

    // 显示原始图像和处理后的图像
    cv::imshow("Original Image", originalImage);
    cv::imshow("Edges", edges);
    cv::imshow("Dilated Image", dilatedImage);
    cv::imshow("Eroded Image", erodedImage);
    cv::imshow("Resized Image", resizedImage);

    // 等待键盘输入，输入任意键后关闭窗口
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
