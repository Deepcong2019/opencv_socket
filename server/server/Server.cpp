/*M///
//
//  基于OpenCV和Winsock的图像传输（接收）

//M*/




#include "WinsockMatTransmissionServer.h"

int main()
{
	WinsockMatTransmissionServer socketMat;

	if (socketMat.socketConnect("127.0.0.1", 6566) < 0)
	{
		return 0;
	}
	
	cv::Mat image;
	while (1)
	{
		if (socketMat.receive(image) > 0)
		{
			cv::imshow("server", image);
			cv::waitKey(30);
		}
	}

	socketMat.socketDisconnect();
	return 0;
}