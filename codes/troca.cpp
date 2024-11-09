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
