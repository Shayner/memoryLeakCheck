#ifndef CCommonMutex_h
#define CCommonMutex_h

#include <semaphore.h>
#include "header.h"

/**
*CCommonMutex类实现了与pthread_mutex_t的使用特性一致，但是多个线程之间互斥，
*而单个线程上下文之间可重入，但在一个线程中有多少次lock，就需要调用多少次
*unlock才能释放对mutex的拥有
*/

class CCommonMutex{
protected:
    //利用信号量实现互斥锁
    sem_t m_Semaphore;
private:
    UINT count;

    int m_nPid;  //获得本线程pid
public:
    CCommonMutex_h();
    virtual ~CCommonMutex();

    void Lock();   //阻塞性的上锁操作

    bool tryLock();   //非阻塞性的上锁操作

    void Unlock();    //解锁

};


#endif
