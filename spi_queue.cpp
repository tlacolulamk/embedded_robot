#include "spi_queue.h"

bool queue10::put_q(tenvarQueue *r1, int datum){
    int next = r1->back +1;
    if(next >= r1->capacity) next = 0;
    if(next == r1->front) return false;
    else{    
        r1->buffer[r1->back] = datum;
        r1->back = next;
        return true;
        }
}
