#include "Chat.hpp"

std::vector<MensagemBase*> Chat::getHistorico() {
  return this->_historico;
}

void Chat::enviarMensagem(MensagemBase *msg) {
  msg->setStatus(MsgStatus::SENT);
  this->_historico.push_back(msg);
}

void Chat::exibirMensagens() {
  for (auto m : this->_historico) {
    time_t d = m->getData();	
    char data[20];
      strftime(data, 20, "%Y-%m-%d %H:%M:%S", localtime(&d));
    
    m->setStatus(MsgStatus::READ);
    std::cout << "(" << data << ", " << m->getStatus() << ")" << std::endl;
    m->exibir();
    std::cout << std::endl;
  }  
}

void Chat::enviarMensagemTexto(std::string texto) {
  if (texto.size() > 100)
    throw ExcecaoTamanhoMensagemTexto();

  MensagemTexto *msg = new MensagemTexto(texto);
  this->enviarMensagem(msg);
}

void Chat::enviarMensagemImagem(std::string imagem) {
  MensagemImagem *msg = new MensagemImagem(imagem);
  this->enviarMensagem(msg);
}

void Chat::enviarMensagemAudio(std::string audio) {
  MensagemAudio *msg = new MensagemAudio(audio);
  this->enviarMensagem(msg);
}