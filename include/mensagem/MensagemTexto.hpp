#ifndef MENSAGEMTEXTO_H
#define MENSAGEMTEXTO_H

#include <string>
#include "MensagemBase.hpp"

class ExcecaoTamanhoMensagemTexto : public std::exception {
  public:
    virtual const char* what() const throw() {
      return "Erro: Tamanho do texto acima do limite (100 caracteres).";
    }
};


class MensagemTexto : public MensagemBase {
	
  private:
    std::string _msg;

  public:
    MensagemTexto(std::string msg);
    void exibir();
	
};

#endif
