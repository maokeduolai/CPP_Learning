#include <opencv2/opencv.hpp>
#include <iostream>

// 回调函数，根据滑动条数值的变化更改图片
void onTrackbarChange(int value, void *userdata) {
    auto *originalImage = static_cast<cv::Mat *>(userdata);

    // 从滑动条获取亮度和对比度的值
    double brightness = static_cast<double>(cv::getTrackbarPos("Brightness", "Adjust Image")) / 50.0;
    double contrast = static_cast<double>(cv::getTrackbarPos("Contrast", "Adjust Image")) / 50.0;

    // 调整图像亮度和对比度
    cv::Mat adjustedImage = originalImage->clone();
    adjustedImage.convertTo(adjustedImage, -1, contrast, brightness);

    // 显示调整后的图像
    cv::imshow("Adjust Image", adjustedImage);
}

int main() {
    // 加载图像
    cv::Mat originalImage = cv::imread("Resource/Avatar.jpeg");

    if (originalImage.empty()) {
        std::cerr << "无法读取损坏图片！" << std::endl;
        return -1;
    }

    // 创建窗口
    cv::namedWindow("Adjust Image");

    // 创建滑动条
    cv::createTrackbar("Brightness", "Adjust Image", nullptr, 500, onTrackbarChange, &originalImage);
    cv::createTrackbar("Contrast", "Adjust Image", nullptr, 100, onTrackbarChange, &originalImage);

    // 初始时调用一次回调函数，显示原始图像
    onTrackbarChange(0, &originalImage);

    // 等待键盘输入，输入任意键后关闭窗口
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
