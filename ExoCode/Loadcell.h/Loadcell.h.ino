class Loadcell {
  public:
    Loadcell(int pin, int pinClk);
    void updateForce();
    double getForce();
  private:
    double Force;   
    int pin;
    int pinClk;
  Loadcell(int pin, int pinClk)
  {
    this.pin = pin;
    this.pinClk = pinClk;
  }
  void updateForce()
  {
    
  }
  double getForce()
  {
    
  }
}

