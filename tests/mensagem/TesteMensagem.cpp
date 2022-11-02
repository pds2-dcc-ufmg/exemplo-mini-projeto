#include "doctest.h"
#include "MensagemTexto.hpp"

TEST_CASE("Mensagem Status None") {
  MensagemTexto* msg = new MensagemTexto("MsgTexto");
  CHECK_EQ(msg->getStatus(), MsgStatus::NONE);
}