#include <cstdint>
#include <cstddef>
#include <iostream>

using namespace std;
constexpr size_t GpiocAddr = 0x40020800;
constexpr size_t ModerOffset = 0x00;
constexpr size_t ModerAddr = GpiocAddr + ModerOffset;
constexpr size_t LuboeAddr =  0x20200010;
int main() 
{
    volatile uint32_t *ModerPointer = reinterpret_cast<volatile uint32_t*>(ModerAddr) ;
    volatile uint32_t *LuboePointer = reinterpret_cast<volatile uint32_t*>(LuboeAddr) ;

     uint32_t Moder = *ModerPointer;
     uint32_t Luboe = *LuboePointer;

  return 0 ;
}