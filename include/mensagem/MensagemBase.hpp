#ifndef MENSAGEMBASE_H
#define MENSAGEMBASE_H

#include <ctime>

enum MsgStatus {
  NONE,
  SENT,
  DELIVERED,
  READ
};

class MensagemBase {

  private:
    std::time_t _data;
	  MsgStatus _status;
	
  public:
    MensagemBase();
    
    std::time_t getData();
    
    MsgStatus getStatus();
    void setStatus(MsgStatus status);

    virtual void exibir() = 0;
};

#endif
