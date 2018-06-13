
#ifndef _DETECTFACE_
#define _DETECTFACE_
#include <iostream>

#define ANIME_FACE "../cascade/lbpcascade_animeface.xml"
#define REAL_FRONT_FACE "../cascade/haarcascade_frontalface_alt.xml"


class detecface{
private:
	std::vector<std::string> file_list;

public:
	detecface(void);

	bool addDetectFile(const std::string filename);
	bool delDetectFile(const std::string filename);
	bool detectFaceImage(const cv::Mat &image);

};

#endif