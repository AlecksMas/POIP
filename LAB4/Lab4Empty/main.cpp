//#include <cstdint>            //for int types such as uint32_t
#include "gpioaregisters.hpp" //for Gpioa
#include "rccregisters.hpp"   //for RCC
#include "tim2registers.hpp"   //for SPI2
#include "nvicregisters.hpp"  //for NVIC
#include "tim5registers.hpp" 
#include "gpiocregisters.hpp"

using namespace std ;



extern "C"
{
int __low_level_init(void)
{
    RCC::CR::HSION::Enable::Set();
    while ( !RCC::CR::HSIRDY::Enable::IsSet( ) )
     {      
     };
    
    RCC::CFGR::SW::Hsi::Set();
    while ( !RCC::CFGR::SWS::Hsi::IsSet( ))
    { 
    };
    
    // punkt 4
    RCC::APB1ENR::TIM5EN::Enable::Set();
    TIM5::CR1::URS::Value1::Set();
    
    // punkt 5
    RCC::AHB1ENR::GPIOAEN::Enable::Set();
    RCC::AHB1ENR::GPIOCEN::Enable::Set();
    
    // punkt 6
    GPIOA::MODER::MODER5::Output::Set();
    GPIOC::MODER::MODER5::Output::Set();
    GPIOC::MODER::MODER8::Output::Set();
    GPIOC::MODER::MODER9::Output::Set();
    
    // punkt 8
    TIM5::PSC::Write(15999) ;
    TIM5::ARR::Write(500) ;
    TIM5::SR::UIF::Enable::Set();
    TIM5::CNT::Write(0);
    TIM5::CR1::CEN::Enable::Set() ;  
  
    //punkt 9
    NVIC::ISER1::Write(1 << 18);
    TIM5::DIER::UIE::Enable::Set();

    TIM5::SR::UIF::Disable::IsSet ();
    GPIOC::ODR::Toggle((1 << 8) | (1 << 5) | (1 << 9)) ;
    GPIOA::ODR::Toggle (1 << 5); 

  return 1;
}
}

 int main()
{

  for(;;)
  {
  }
  
  return 0 ;
}

