#ifndef MENSAGEMIMAGEM_H
#define MENSAGEMIMAGEM_H

#include <string>
#include "MensagemBase.hpp"

class MensagemImagem : public MensagemBase {
	
  private:
    std::string _imagem;

  public:
    MensagemImagem(std::string imagem);
    void exibir();
	
};

#endif
