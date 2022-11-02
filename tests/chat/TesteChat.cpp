#include "doctest.h"
#include "Chat.hpp"

TEST_CASE("Historico inicial vazio") {
  Chat chat;
  CHECK_EQ(chat.getHistorico().size(), 0);
}

TEST_CASE("Historico com mensagens") {
  Chat chat;

  chat.enviarMensagemTexto("Msg1");
  chat.enviarMensagemTexto("Msg2");
  chat.enviarMensagemTexto("Msg3");

  CHECK_EQ(chat.getHistorico().size(), 3);
}

TEST_CASE("Mensagem Status Sent") {
  Chat chat;
  chat.enviarMensagemTexto("Msg1");
  CHECK_EQ(chat.getHistorico()[0]->getStatus(), MsgStatus::SENT);
}

TEST_CASE("Exceção Mensagem Texto") {
    Chat chat;
    std::string line = "01234567890123456789012345678901234567890123456789" 
    "012345678901234567890123456789012345678901234567890";
    CHECK_THROWS_AS(chat.enviarMensagemTexto(line), ExcecaoTamanhoMensagemTexto);
} 