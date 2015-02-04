class Sender {
  public: 
    Sender();
    ~Sender();
  private:
   
  enum FsmEvent{
    ePktToSend,
    eTimeout,
    eCorruptedAck,
    eCorrectedAck
  };
  enum FsmState{
    eReady,
    eBlocking,
  };

  handleEvent(FsmEvent event){
    switch (m_fsmState){
      case eReady: {
        switch (event){
          case ePktToSend: doSendWithRawSocket(); break;
          default:;
        } break;
      } break;
      case eBlocking:{
        switch (event){
          case eTimeout: doTimeout_Blocking(); break;
          case eCorruptedAck: doDiscardAck_Blocking(); break;
          case eCorrectedAck: doAck_Ready(); break;
          default:;
        } break;
      } break;
      default:;
    }
  }

  inline FsmState getFsmState(){
    return m_FsmState;
  }

  void doTimeout_Blocking(){ 
  }

  void doDiscardAck_Blocking(){
  }

  void doAck_Ready(){
  }

  void doSendWithRawSocket(){
  }

  FsmState m_fsmState;
  pthread* m_sendThread;
  pthread* m_recvThread;
  pthread* m_timer;
}
