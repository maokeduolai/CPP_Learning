#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // 键盘输入记录
    int key;

    // 加载并显示一张图像，等待键盘输入（Esc退出）
    cv::Mat image = cv::imread(
            "Resource/Avatar.jpeg");

    if (image.empty()) {
        std::cerr << "图片损坏无法读取！" << std::endl;
        return -1;
    }

    cv::imshow("Image", image);
    key = cv::waitKey(0);  // 等待直到用户按下按键

    if (key == 27) { // 27是Esc的ASCII码
        cv::destroyAllWindows();
    }

    // 加载一个视频，使用while循环读取视频帧，输入“Esc”退出
    cv::VideoCapture video(
            "Resource/Test.mp4");

    if (!video.isOpened()) {
        std::cerr << "视频损坏无法读取！" << std::endl;
        return -1;
    }

    while (true) {
        cv::Mat frame;
        video >> frame;

        if (frame.empty()) {
            std::cerr << "视频播放结束！" << std::endl;
            cv::destroyAllWindows();
            break;
        }

        cv::imshow("Video", frame);
        key = cv::waitKey(25); // 根据延迟时间控制播放帧率，1000ms / 24fps = 25ms

        if (key == 27) {
            cv::destroyAllWindows();
            break;
        }
    }

    // 开启计算机摄像头，使用while循环读取视频帧，输入“Esc”退出
    cv::VideoCapture camera(0);

    if (!camera.isOpened()) {
        std::cerr << "无法打开摄像头！" << std::endl;
        return -1;
    }

    while (true) {
        cv::Mat frame;
        camera >> frame;

        if (frame.empty()) {
            std::cerr << "无法读取摄像头数据！" << std::endl;
            cv::destroyAllWindows();
            break;
        }

        cv::imshow("Camera", frame);
        key = cv::waitKey(33);

        if (key == 27) {
            cv::destroyAllWindows();
            break;
        }
    }

    return 0;
}
