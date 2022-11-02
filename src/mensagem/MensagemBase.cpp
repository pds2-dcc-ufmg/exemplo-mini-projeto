#include "MensagemBase.hpp"

MensagemBase::MensagemBase() {
  this->_data = std::time(nullptr);
  this->_status = MsgStatus::NONE;
}

std::time_t MensagemBase::getData() {
  return this->_data;
}

MsgStatus MensagemBase::getStatus() {
  return this->_status;
}

void MensagemBase::setStatus(MsgStatus status) {
  this->_status = status;
}