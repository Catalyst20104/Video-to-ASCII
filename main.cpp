#include <iostream>
#include <chrono>
#include <thread>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

string pixelTOASCII(int pixel_intensity){
	const string ASCII_CHAIRS = "@#$%+=-. ";
	string s=string(1,ASCII_CHAIRS[pixel_intensity*ASCII_CHAIRS.length() / 256 ]);
	return s;
}

int main(){
	cout<<"HELLO"<<endl; 
	string video_path="/home/gaurav/Documents/utkarsh/video-to-ascii/sample3.mp4";
	VideoCapture cap(video_path);
	double fps=cap.get(CAP_PROP_FPS);
	//cout<<fps<<endl;
	int frame_duration_ms = 1000/fps;
	int width =200;
	int height =50;
	
	Mat frame,gray_frame,resized_frame;

	while(true){

		cap >> frame;
		if(frame.empty()) break;
		
		cv::cvtColor(frame ,gray_frame ,cv::COLOR_BGR2GRAY);
		
		resize(gray_frame,resized_frame,Size(width,height),0,0,INTER_CUBIC);

		string ascii_frame;
		for(int i=0;i<height;i++){
			for(int j=0;j<width;j++){
				ascii_frame+=pixelTOASCII(resized_frame.at<uchar>(i,j));
			}
			ascii_frame+="\n";
		}
		system("clear"); //to clear the console
		cout<<ascii_frame;
		std::this_thread::sleep_for(std::chrono::milliseconds(30));

	}


	return 0;
}
