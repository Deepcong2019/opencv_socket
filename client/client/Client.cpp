/*M///
//
//  基于OpenCV和Winsock的图像传输（发送）
//

//
//M*/


#include "WinsockMatTransmissionClient.h"

int main()
{
	WinsockMatTransmissionClient socketMat;
	if (socketMat.socketConnect("127.0.0.1", 6566) < 0)
	{
		return 0;
	}

	cv::VideoCapture capture(0);
	cv::Mat image;

	while (1)
	{
		if (!capture.isOpened())
			return 0;

		capture >> image;
		cv::imshow("client", image);
		cv::waitKey(30);
		if (image.empty())
			return 0;

		socketMat.transmit(image);
	}

	socketMat.socketDisconnect();
	return 0;
}