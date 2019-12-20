#include "rccregisters.hpp"
#include "gpioaregisters.hpp"
#include "gpiocregisters.hpp"
#include "tim2registers.hpp"

extern "C"
{
  int __low_level_init (void)
  {
    RCC::CR::HSEON::Enable::Set();
    while (!RCC::CR::HSERDY::Enable::IsSet());
    {
    };
    
    RCC::CFGR::SW::Hse::Set();
    while (!RCC::CFGR::SWS::Hse::IsSet());
    {
    };
    RCC::AHB1ENR::GPIOCEN::Enable::Set(); 
    RCC::AHB1ENR::GPIOAEN::Enable::Set(); 
    GPIOA::MODER::MODER5::Output::Set(); 
    GPIOC::MODER::MODER5::Output::Set(); 
    GPIOC::MODER::MODER8::Output::Set(); 
    GPIOC::MODER::MODER9::Output::Set(); 
    GPIOC::MODER::MODER13::Input::Set(); 

    return 0;
  }
}

int main()
{
bool flag = false;
for (; ;)
{

if(GPIOC::IDR::IDR13::Low::IsSet()) //kn vkl
{
while(GPIOC::IDR::IDR13::Low::IsSet())
{
} ;

if(flag)
{
GPIOA::ODR::ODR5::High::Set ();
GPIOC::ODR::ODR5::High::Set ();
GPIOC::ODR::ODR8::High::Set ();
GPIOC::ODR::ODR9::High::Set ();
flag = false ;
}
else
{
GPIOA::ODR::ODR5::Low::Set ();
GPIOC::ODR::ODR5::Low::Set ();
GPIOC::ODR::ODR8::Low::Set ();
GPIOC::ODR::ODR9::Low::Set ();
flag = true ;
}
}
}
return 0;
}