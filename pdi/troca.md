---
layout: page
title: "Troca de Região"
permalink: /pdi/trocaregiao
---

# Troca de Região
Semelhante ao exercicio da Região, esse exercicio visa trabalhar com o deslocamento de pixels, mas dessa vez, utilizando uma imagem auxiliar que será transformada, 
sem que seja alterada a imagem inicial, não perdendo informações enquanto é realizado as transformações. O objetivo do exercicio é dividir a imagem em 4 quadrantes e inverter eles, para isso foi criado duas imagens,
uma que recebe a foto a ser transformada e outra que recebe uma cópia da primeira imagem.

```cpp
#include <iostream>
#include <opencv2/opencv.hpp>

int main(int, char**) {
  cv::Mat image;
  cv::Mat saida;

  image = cv::imread("bob.png", cv::IMREAD_COLOR);
  if (!image.data) std::cout << "nao abriu bob.png" << std::endl;
  saida = image.clone();
  cv::namedWindow("troca", cv::WINDOW_AUTOSIZE);
  int mX = saida.rows/2;
  int mY = saida.cols/2;
  std::cout<<mX<<mY;
  for (int i = 0; i < saida.rows; i++) {
    for (int j = 0; j < saida.cols; j++) {
	  if(i<= mX && j<= mY) {
		  saida.at<cv::Vec3b>(i, j) = image.at<cv::Vec3b>(i + mX, j + mY);
	  }
	  if(i<= mX && j>  mY) {
		  saida.at<cv::Vec3b>(i, j) = image.at<cv::Vec3b>(i + mX, j - mY);
	  }
	  if(i> mX  && j<= mY) {
		  saida.at<cv::Vec3b>(i, j) = image.at<cv::Vec3b>(i - mX, j + mY);
	  }
	  if(i> mX  && j>  mY) {
		  saida.at<cv::Vec3b>(i, j) = image.at<cv::Vec3b>(i - mX, j - mY);
	  }
    }
  }
  bool isSaved = cv::imwrite("troca.png", saida);
  
  if (isSaved) {
      std::cout << "Imagem salva com sucesso!" << std::endl;
  } else {
      std::cout << "Erro ao salvar a imagem!" << std::endl;
  }
   
  cv::imshow("troca", saida);
  cv::waitKey();

  return 0;
}
````

 O código recebe a imagem [bob.png](images/bob.png) e varre pixel a pixel da imagem e copia o pixel na posição alterada da imagem copiada, gerando assim o resultado mostrado na [Figura 1][figura1]

[figura1]: images/troca.png "Figura 1: troca.png"
![Figura 1: troca.png][figura1]  
*Figura 1: troca.png*

