#include "Chat.hpp"

int main() {

  Chat chat;	
  
  chat.enviarMensagemTexto("Oi, tem aula de PDS2 hoje?");
  chat.enviarMensagemAudio("audio.wav");
  chat.enviarMensagemImagem("imagem03.ascii");
  chat.enviarMensagemTexto("Mas que puxa :(");

  chat.exibirMensagens();
  
  return 0;
}
