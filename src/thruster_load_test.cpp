#include "../include/usbscale.h"


int main(void){

  USBScale myscale;

  if(myscale.open_scale_device()!=-1){
    std::cout<<"Device Opened Successfully"<<std::endl;
    auto measurement = myscale.get_measurement();
    std::cout<<"Measurement: "<<measurement<<std::endl;
    return 1;
  }
  else{
    return 0;
  }
}