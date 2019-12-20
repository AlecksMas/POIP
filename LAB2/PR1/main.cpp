#include <cstdint>
#include <cstddef>
#include <iostream>
#include "rccregisters.hpp"
#include "gpiocregisters.hpp"
using namespace std;
constexpr size_t GpiocAddr = 0x40020800; //
constexpr size_t ModerOffset = 0x00; //
constexpr size_t OdrOffset = 0x14; //
constexpr size_t ModerAddr = GpiocAddr + ModerOffset; //
constexpr size_t OdrAddr = GpiocAddr + OdrOffset; //

using namespace std;
void delay(uint32_t delay)
 {
   for (int i=0; i<delay; i++)
   {
   }
 }

int main() 
{
 RCC::AHB1ENR::GPIOCEN::Enable::Set() ;

  volatile uint32_t *ModerPointer = reinterpret_cast<volatile uint32_t*>(ModerAddr); 
  volatile uint32_t *OdrPointer = reinterpret_cast<volatile uint32_t*>(OdrAddr ) ; 
  
  for(;;) 
   {
      *ModerPointer |= ((1 << 10 )|(1<<16)|(1<<18));      // biti 10, 16, 18  v 1 moder 
      *ModerPointer &= ~ ((1 << 11 )|(1<<17)|(1<<19));      // biti 10, 16, 18  v 1 moder 
      *OdrPointer |= ((1 << 5 )|(1<<8)|(1<<9));            // biti 5, 8, 9  v 1 odr
      delay (1'000'000);
      *OdrPointer &= ~ ((1 << 5 )|(1<<8)|(1<<9));  
   }
  return 0 ;
}
