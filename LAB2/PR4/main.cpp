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

struct Button
{
  static bool IsPressed()
  {
    bool result = false;
    if (GPIOC::IDR::IDR13::Low::IsSet() )
    {
      while (GPIOC::IDR::IDR13::Low::IsSet() )
      {
        result = true;
      };
    }
    return result;
  }
};
template <typename Port, std::uint32_t pinNum> struct Led {

  static void Toggle()
  {
    Port::ODR::Toggle(1<<pinNum);
  }
};
using Led1 = Led<GPIOC,5>;

using Led2 = Led<GPIOC,8>;

using Led3 = Led<GPIOC,9>;

using Led4 = Led<GPIOA,5>;

int main()

{

  for (; ;)
  {
    if (Button::IsPressed())
    {
      Led1::Toggle ();
      Led2::Toggle ();
      Led3::Toggle ();
      Led4::Toggle ();
    }
  }
  return 0;
}

