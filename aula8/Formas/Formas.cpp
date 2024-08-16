#include	"Formas.h"

using namespace cv;

//-----------------------------------------------------------

Formas::Formas()
{
	path = "./outras.jpg";

	img = imread(path);

	Canny(img, imgCanny, 0, 200);

	nucleo = getStructuringElement(0, Size(3, 3));

	dilate(imgCanny, imgDilatada, nucleo);
}

//-----------------------------------------------------------

Formas::~Formas(){
  cv::waitKey( 0 );
}


//-----------------------------------------------------------

void Formas::DesenharNasFormas()
{
	findContours(imgDilatada, contornos, hierarquia, 0, 2);
	//drawContours(img, contornos, -1, Scalar(147, 20, 255), 2);

	lados = contornos;
	retangulo.resize(contornos.size());

	for (int i = 0; i < contornos.size(); i++) {
		double area = contourArea(contornos[i]);
		perimetro = arcLength(contornos[i], true);
		approxPolyDP(contornos[i], lados[i], 0.03 * perimetro, true);
		//drawContours(img, lados, i, Scalar(147,20,255), 2);
		retangulo[i] = boundingRect(lados[i]);
		//rectangle(img, retangulo[i].tl(), retangulo[i].br(), Scalar(0, 140, 255), 4);

		if (lados[i].size() == 3) {
				nomeForma = "Triangulo";
		}
		else if (lados[i].size() == 4) {
			if (retangulo[i].width == retangulo[i].height) {
				nomeForma = "Quadrado";
			}
			else {
				nomeForma = "Retangulo";
			}
		}
		else if (lados[i].size() > 4) {
			nomeForma = "Circulo";	
		}
		

		putText(img, nomeForma, cv::Point(retangulo[i].x, retangulo[i].y), QT_FONT_NORMAL, 0.8, Scalar(0, 0, 0), 2);
		//std::cout << "Area: " << area << " | Qtd lados: " << lados[i].size() << '\n';
	}
	imshow("Imagem original", img);
	//imshow("Imagem Canny", imgCanny);
	//imshow("Imagem Dialtada", imgDilatada);
}

//-----------------------------------------------------------
