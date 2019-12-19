#include "rccregisters.hpp" //for RCC
#include "gpioaregisters.hpp" //for GPIOC
#include "gpiocregisters.hpp" //for gpioc
int main()
{
RCC::AHB1ENR::GPIOAEN::Enable::Set() ;  //Razresh taktir na A
GPIOA::MODER::MODER5::Output::Set() ;        //zadaem kaka vhod

RCC::AHB1ENR::GPIOCEN::Enable::Set() ;  //Razresh taktir na A
GPIOC::MODER::MODER9::Output::Set() ; 
GPIOC::MODER::MODER8::Output::Set() ; 
GPIOC::MODER::MODER5::Output::Set() ; 


GPIOA::ODR::ODR5::High::Set() ;     //Vkl odr
GPIOC::ODR::ODR9::High::Set() ; 
GPIOC::ODR::ODR8::High::Set() ; 
GPIOC::ODR::ODR5::High::Set() ; 

GPIOA::ODR::ODR5::Low::Set() ;      //Vikl odr
GPIOC::ODR::ODR9::Low::Set() ; 
GPIOC::ODR::ODR8::Low::Set() ; 
GPIOC::ODR::ODR5::Low::Set() ; 
  
       
 
 
 return 0 ;
}