#include <iostream>
#include <opencv2/opencv.hpp>

int main(int, char**) {
  cv::Mat image;
  cv::Vec3b val;

  image = cv::imread("bob.png", cv::IMREAD_GRAYSCALE);
  if (!image.data) {
    std::cout << "nao abriu bob.png" << std::endl;
    return 0;
  }

  cv::namedWindow("regiao", cv::WINDOW_AUTOSIZE);

  int x1, y1, x2, y2;

  // Entrada para coordenada x1
  std::cout << "Digite a coordenada X do Ponto 1:" << std::endl;
  std::cin >> x1;
  while (x1 < 0 || x1 > image.rows) {
    std::cout << "Coordenada inválida. Digite um valor para X do Ponto 1 entre 0 e " << image.rows << ":" << std::endl;
    std::cin >> x1;
  }

  // Entrada para coordenada y1
  std::cout << "Digite a coordenada Y do Ponto 1:" << std::endl;
  std::cin >> y1;
  while (y1 < 0 || y1 > image.cols) {
    std::cout << "Coordenada inválida. Digite um valor para Y do Ponto 1 entre 0 e " << image.cols << ":" << std::endl;
    std::cin >> y1;
  }

  // Entrada para coordenada x2
  std::cout << "Digite a coordenada X do Ponto 2:" << std::endl;
  std::cin >> x2;
  while (x2 < 0 || x2 > image.rows) {
    std::cout << "Coordenada inválida. Digite um valor para X do Ponto 2 entre 0 e " << image.rows << ":" << std::endl;
    std::cin >> x2;
  }

  // Entrada para coordenada y2
  std::cout << "Digite a coordenada Y do Ponto 2:" << std::endl;
  std::cin >> y2;
  while (y2 < 0 || y2 > image.cols) {
    std::cout << "Coordenada inválida. Digite um valor para Y do Ponto 2 entre 0 e " << image.cols << ":" << std::endl;
    std::cin >> y2;
  }

  for (int i = x1; i < x2; i++) {
    for (int j = y1; j < y2; j++) {
      image.at<uchar>(i, j) = 255-image.at<uchar>(i, j);
    }
  }
  
  bool isSaved = cv::imwrite("regiao.png", image); 

    if (isSaved) {
        std::cout << "Imagem salva com sucesso!" << std::endl;
    } else {
        std::cout << "Erro ao salvar a imagem!" << std::endl;
    }
    
  cv::imshow("regiao", image);
  cv::waitKey();

  image = cv::imread("bob.png", cv::IMREAD_COLOR);



  for (int i = x1; i < x2; i++) {
    for (int j = y1; j < y2; j++) {
      val = image.at<cv::Vec3b>(i, j);
      
      val[0] = 255 - val[0];
      val[1] = 255 - val[1];
      val[2] = 255 - val[2];
      
      image.at<cv::Vec3b>(i, j) = val;
    }
  }
  
  isSaved = cv::imwrite("regiao-color.png", image); 

    if (isSaved) {
        std::cout << "Imagem salva com sucesso!" << std::endl;
    } else {
        std::cout << "Erro ao salvar a imagem!" << std::endl;
    }
    
  cv::imshow("regiao", image);
  cv::waitKey();
  return 0;
}
