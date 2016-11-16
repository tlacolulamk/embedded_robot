class queue10
{
 private:

 public:
 typedef struct{
    int buffer[10];
    int front;
    int back;
    const int capacity;
 }tenvarQueue;
    bool put_q(tenvarQueue *r1, int datum); 
};

