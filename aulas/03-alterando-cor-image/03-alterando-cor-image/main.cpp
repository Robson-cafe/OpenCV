#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <iostream>

int main( int argc, char ** argv ){
  std::string path = "./minha-foto.png";
  cv::Mat img = cv::imread( path ), img_rainbow, img_bw, img_gaussian, img_canny, img_canny_dilate, img_erode;

  //cv::cvtColor( img, img_rainbow, cv::COLORMAP_RAINBOW );
  //cv::cvtColor( img, img_bw, 6 );
  //cv::GaussianBlur( img, img_gaussian, cv::Size(7, 7), 2 );
  cv::Canny( img, img_canny, 6, 93 );

  //cv::dilate( img_canny, img_canny_dilate, cv::getStructuringElement( 2, cv::Size(4, 4) ) );
  //cv::erode( img_canny, img_erode, cv::getStructuringElement( 1, cv::Size( 2,2  ) ) );
  
  cv::imshow("Original", img);
  //cv::imshow("Rainbow", img_rainbow);
  //cv::imshow("Black & White", img_bw);
  //cv::imshow("Gaussian Blur", img_gaussian);
  //cv::imshow("Canny", img_canny);
  //cv::imshow("Canny Dilatada", img_canny_dilate);
  //cv::imshow("Canny Erode", img_erode);

  cv::waitKey( 0 );
  return 0;
}
