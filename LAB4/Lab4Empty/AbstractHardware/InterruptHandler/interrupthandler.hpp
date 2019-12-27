//
// Created by Sergey on 21.11.2019.
//

#ifndef REGISTERS_INTERRUPTHANDLER_HPP
#define REGISTERS_INTERRUPTHANDLER_HPP


#include "tim2registers.hpp"  //for TIM2
#include "gpiocregisters.hpp"  //for GPIOC
#include "gpioaregisters.hpp"  //for GPIOA

#include "tim5registers.hpp"  //for TIM5


class InterruptHandler {
  public:
    static void DummyHandler() { for(;;) {} }
  
    static void Timer2Handler()
    {
      if (TIM2::SR::UIF::UpdatePending::IsSet())
      {
        TIM2::SR::UIF::NoUpdate::Set();
        GPIOC::ODR::Toggle(1 << 8) ;
      }
    }
   
    static void Timer5Handler()
    {
      if (TIM5::SR::UIF::Enable::IsSet())
      {
        TIM5::SR::UIF::Disable::Set();
        GPIOC::ODR::Toggle((1 << 8) | (1 << 5) | (1 << 9)) ;
        GPIOA::ODR::Toggle (1 << 5);
      }
    }
};

#endif //REGISTERS_INTERRUPTHANDLER_HPP
