#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <iostream>

int main( int argc, char ** argv ){
  std::string path = "./minha-foto.png";
  cv::Mat img = cv::imread( path ), img_resize, img_cut;

  //std::cout << "Dimensões da minha imagem: " << img.size() << '\n';
  //std::cout << "Largura da minha imagem: " << img.size().width << '\n';
  //std::cout << "Altura da minha imagem: " << img.size().height << '\n';
  //std::cout << "Área da minha imagem: " << img.size().area() << '\n';

  img_cut = img( cv::Rect( img.size().width / 2, img.size().height / 2, 200, 200 ) );

  cv::resize( img, img_resize, cv::Size(), 0.1, 0.1 );

  cv::imshow("Original", img);
  //cv::imshow("Redimensionada", img_resize);
  cv::imshow("Cortada", img_cut);

  cv::waitKey( 0 );
  return 0;
}
