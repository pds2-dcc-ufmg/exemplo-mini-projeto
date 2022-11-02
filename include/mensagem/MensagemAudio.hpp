#ifndef MENSAGEMAUDIO_H
#define MENSAGEMAUDIO_H

#include <string>
#include "MensagemBase.hpp"

class MensagemAudio : public MensagemBase {
	
  private:
    std::string _audio;

  public:
    MensagemAudio(std::string audio);
    void exibir();
	
};

#endif
