
class Encoder {
  public:
    Encoder(double pin);
    void updatePos();
    double getPos();   // position
    double getDis();   // displacement

  private:
    double pos;
    double dis;
    int pin;

  Ecoder(int pin) 
  {
    this.pin = pin
  }
  void updatePos();
  {
    pos = analogRead(pin)*5/1023
  }
  double getPos();   // position
  {
    return pos;
  }
  double getDis();   // displacement
  {
    double pos = 0;
    double previous = 0;
    dis = previous-current;  
    return dis;  
  }
}

