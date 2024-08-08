#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>

using namespace std;
using namespace cv;

//----------------------------------------------------------------------------------------------

//aula 7 - detecção de cores
int main(int argc, char** argv) {
  int matiz_min = 18, matiz_max = 34, saturacao_min = 190,
      saturacao_max = 255, brilho_min = 21, brilho_max = 255;
  std::string caminho = "./linux.png";
  cv::Mat imagem = cv::imread(caminho), img_hsv, img_mask;

  cvtColor(imagem, img_hsv, COLOR_BGR2HSV);

  namedWindow("Barra de seleção");

  createTrackbar("Matiz mínima", "Barra de seleção", &matiz_min, 255);
  createTrackbar("Matiz Máxima", "Barra de seleção", &matiz_max, 255);

  createTrackbar("Saturação mínima", "Barra de seleção", &saturacao_min, 255);
  createTrackbar("Saturação máxima", "Barra de seleção", &saturacao_max, 255);

  createTrackbar("Brilho mínima", "Barra de seleção", &brilho_min, 255);
  createTrackbar("Brilho máxima", "Barra de seleção", &brilho_max, 255);

  while (true) {
    Scalar min(matiz_min, saturacao_min, brilho_min);
    Scalar max(matiz_max, saturacao_max, brilho_max);

    inRange(img_hsv, min, max, img_mask);

    imshow("Imagem Original", imagem);
    //cv::imshow("Imagem HSV", img_hsv);
    imshow("Imagem Binaria", img_mask);
    waitKey(1);
  }
  
  return 0;
}

//----------------------------------------------------------------------------------------------
//aula 6 - perspectiva
//int main(int argc, char** argv) {
//  string caminho = "./memoria.jpg";
//  Mat imagem = cv::imread(caminho), warp, img_cut;
//
//  float w = 900;
//  float h = 200;
//
//  const Point2f origem[4] = { {11, 255}, {469, 43}, {90, 363}, {547, 131} };
//  const Point2f destino[4] = { {0, 0}, {w, 0}, {0, h}, {w, h} };
//
//  for (int i = 0; i < 4; i++) {
//    circle(imagem, Point(origem[i]), 10, Scalar(255, 0, 0), -1);
//  }
//
//  warpPerspective(imagem, warp, getPerspectiveTransform(origem, destino), Size(w, h));
//
//  Rect cut (0, 2, w, h - 2);
//  img_cut = warp(cut);
//
//  imshow("Imagem Origem", imagem);
//  imshow("Imagem Destino", warp);
//  imshow("Imagem Cortada", img_cut);
//  waitKey(0);
//  return 0;
//}

//----------------------------------------------------------------------------------------------
//aula 5 - desenhando formas e inserindo textos

//int main(int argc, char** argv) {
//  Mat img(720, 1280, CV_8UC3, Scalar(255, 0, 0));
//  //circle(img, Point(250, 250), 200, Scalar(0, 0, 255), 5);
//  circle(img, Point(250, 250), 200, Scalar(0, 0, 255), FILLED); //equivale a -1
//  //rectangle(img, Point(100, 100), Point(400, 400), Scalar(0, 255, 0), 5); //equivale a -1
//  rectangle(img, Point(100, 100), Point(400, 400), Scalar(0, 255, 0), FILLED); //equivale a -1
//  line(img, Point(0, 0), Point(400, 400), Scalar(36, 60, 14), 5);
//  line(img, Point(0, 400), Point(400, 400), Scalar(124, 90, 62), 5);
//  putText(img, "Terminal", Point(10, 50), QT_FONT_NORMAL, 2, (100, 200, 30), 5);
//
//  imshow("Fundo Azul", img);
// 
//  cv::waitKey(0);
//  return 0;
//}

//----------------------------------------------------------------------------------------------

//aula 4 - redimensionando e recortando imagem
//int main(int argc, char** argv) {
//  std::string caminho = "./minha-foto.png";
//  cv::Mat imagem = cv::imread(caminho), img_resize, img_cut;
//
//  /*std::cout << "Dimensões da imagem:" << imagem.size() << endl;
//  std::cout << "Largura da imagem:" << imagem.size().height << endl;
//  std::cout << "Altura da imagem:" << imagem.size().width << endl;
//  std::cout << "Area da imagem:" << imagem.size().area() << endl;*/
//  //scv::resize(imagem, img_resize, cv::Size(imagem.size().width / 2, imagem.size().height / 2));
//  //cv::resize(imagem, img_resize, cv::Size(), 0.5, 0.5);
//
//  //img_cut = imagem(cv::Rect(0, 0, imagem.size().width / 2, imagem.size().height / 2));
//  img_cut = imagem(cv::Rect(imagem.size().width / 2, imagem.size().height / 2, 200, 200));
//
//  cv::imshow("Origem", imagem);
//  //cv::imshow("Redimenionada", img_resize);
//  cv::imshow("Cortada", img_cut);
//  cv::waitKey(0);
//  return 0;
//}
 
//----------------------------------------------------------------------------------------------

//aula 3 - alterando cor imagem
//int main(int argc, char** argv) {
//  std::string caminho = "./minha-foto.png";
//  cv::Mat imagem = cv::imread(caminho), img_rainbow, img_bw, img_gaussian, img_canny, img_canny_dilate, img_erode;
//
//  //cv::cvtColor(imagem, img_rainbow, cv::COLORMAP_RAINBOW);
//  //cv::cvtColor(imagem, img_bw, 6);
//  //cv::GaussianBlur(imagem, img_gaussian, cv::Size(7, 7), 7);
//  cv::Canny(imagem, img_canny, 6, 93);
//  //cv::dilate(img_canny, img_canny_dilate, cv::getStructuringElement(2, cv::Size(4, 4)));
//  cv::erode(img_canny, img_erode, cv::getStructuringElement(2, cv::Size(2, 2)));
//
//  cv::imshow("Original", imagem);
//  //cv::imshow("Rainbow", img_rainbow);
//  //cv::imshow("Black and white", img_bw);
//  //cv::imshow("Gaussian Blur", img_gaussian);
//  cv::imshow("Canny", img_canny);
//  //cv::imshow("Canny Dilatada", img_canny_dilate);
//  cv::imshow("Canny Erode", img_erode);
//
//  cv::waitKey(0);
//  return 0;
//}

//----------------------------------------------------------------------------------------------

//aula 2 - carregando video e captura pela webcam
//int main(int argc, char** argv) {
//  //cv::VideoCapture cap(0);
//  cv::VideoCapture cap("./sample.mp4");
//  cv::Mat img;
//
//  while (true) {
//    cap.read(img);
//    cv::imshow("Minha webCam", img);
//    cv::waitKey(15);
//  }
//  
//  return 0;
//}

//----------------------------------------------------------------------------------------------

//aula 1 carregando imagem
//int main(int argc, char** argv) {
//  std::string caminho = "arquivos/minha-foto.png";
//  cv::Mat imagem = cv::imread(caminho);
//  cv::imshow("Imagem", imagem);
//  cv::waitKey(0);
//  return 0;
//}
