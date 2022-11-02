#include <iostream>
#include <fstream>

#include "MensagemImagem.hpp"

MensagemImagem::MensagemImagem(std::string imagem) {
  this->_imagem = imagem;
}

void MensagemImagem::exibir() {
  std::ifstream arquivo("./imgfiles/" + this->_imagem, std::fstream::in);
  if (!arquivo.is_open()) {
    exit(1);
  }
    
  std::string line;
  while (std::getline(arquivo, line))
    std::cout << line << std::endl;

  arquivo.close();
}