#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <iostream>

// v1 = 11 , 255
// v2 = 469 , 43
// v3 = 90 , 363
// v4 = 547 , 131

int main( int argc, char ** argv ){

  float w = 900, h = 200;

  std::string path = "./memoria.jpg";

  cv::Mat img = cv::imread( path ), warp, img_cut;

  cv::Point2f src[4] = {  { 11 , 255 } , { 469 , 43 }, { 90 , 363 }, { 547 , 131 }  };
  cv::Point2f des[4] = {  { 0, 0 } , { w , 0 }, { 0, h }, { w, h }  };


  for (int i = 0; i < 4; ++i) {
    cv::circle( img, cv::Point( src[i] ), 10, cv::Scalar( 255, 0, 0 ), -1 );
  }

  cv::warpPerspective( img, warp, cv::getPerspectiveTransform( src, des ), cv::Size( w, h ) );

  cv::Rect cut( 0, 2, w, h - 2 );

  img_cut = warp( cut );

  cv::imshow("Imagem Original", img);
  cv::imshow("Imagem Transformada", warp);
  cv::imshow("Imagem Cortada", img_cut);
  cv::waitKey( 0 );
  return 0;
}
