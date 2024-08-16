#ifndef FORMAS_H_
#define FORMAS_H_

#include<opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core.hpp>
#include <iostream>

class Formas
{
public:
	Formas();
	~Formas();

	void DesenharNasFormas();

	cv::String path, nomeForma;
	cv::Mat img, imgDilatada, imgCanny, nucleo;

	std::vector<std::vector<cv::Point>> contornos, lados;
	std::vector<cv::Vec4i> hierarquia;
	std::vector<cv::Rect> retangulo;

	double perimetro;
};

#endif
