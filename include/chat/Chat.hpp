#ifndef CHAT_H
#define CHAT_H

#include <vector>
#include <iostream>

#include "MensagemBase.hpp"

#include "MensagemTexto.hpp"
#include "MensagemImagem.hpp"
#include "MensagemAudio.hpp"

/**
 *  Classe responsável por gerenciar um conjunto de mensagens.
 */
class Chat {

  private:

    /**
     *  Coleção que representa o histórico de mensagens.
     */
    std::vector<MensagemBase*> _historico;

    /**
     *  Simula o envio de uma mensagem e a salva no histórico.
     *  @param msg Mensagem da hierarquia de MensagemBase.
     */
	  void enviarMensagem(MensagemBase* msg);
	
  public:
    std::vector<MensagemBase*> getHistorico();

    /**
     *  Exibe todo o histórico de mensagens.
     */
    void exibirMensagens();
	
    void enviarMensagemTexto(std::string texto);
    void enviarMensagemImagem(std::string imagem);
    void enviarMensagemAudio(std::string audio);
};

#endif
