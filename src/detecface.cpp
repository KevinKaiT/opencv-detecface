#include <opencv2/opencv.hpp>
#include <iostream>
#include "./detecface.h"

using namespace cv;
using namespace std;


bool detecface::addDetectFile(const string filename){
	file_list.push_back( filename );
}

//bool delDetectFile(const &string filename);

bool detecface::detectFaceImage(const cv::Mat &image)
{
	Mat gray;
	Mat original = image.clone();

	cvtColor(original, gray, CV_RGB2GRAY);
	CascadeClassifier cascade;

	for(int j = 0; j < detecface::file_list.size(); j++)
	{
		try{
			cout << "file_name: " << file_list[j] << endl;
			cascade.load(file_list[j]);

			vector<cv::Rect> faces;
			cascade.detectMultiScale(gray, faces, 1.1, 3, 0, Size(20, 20));
			if(faces.size() != 0){
				for(int i = 0; i < faces.size(); i++)
				{
					rectangle(original, 
							Point(faces[i].x,faces[i].y),
							Point(faces[i].x + faces[i].width,faces[i].y + faces[i].height),
							Scalar(0,200,0), 3, CV_AA);
					
				}
				imwrite("./detectface.png", original);
				return true;
			}
		} catch ( cv::Exception &e ) {
			cout << "顔検出異常"
			<< e.msg.c_str() << endl;
		}

	}
	return false;// No detect
}

detecface::detecface(void)
{
	//識別器読み込む
	addDetectFile(ANIME_FACE);
	addDetectFile(REAL_FRONT_FACE);
}

int main()
{
	cout << "start" << endl;
	detecface deface;

	Mat face_image;
	face_image = imread("../pic/anime.jpg");
//	face_image = imread("../pic/people.jpg");

//	imshow("show", face_image);
//	waitKey(0);

	bool result = deface.detectFaceImage( face_image );
	if( result ){
		cout << "Get Face" << endl;
	}else{
		cout << "No Face" << endl;
	}

	return 0;
}
