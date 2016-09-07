#include "CommonMutex.h"

CCommonMutex::CCommonMutex(){
    sem_init(&m_Semaphore , 0 , 1);
    count = 0;
    m_nPid = 0;
}

CCommonMutex::~CCommonMutex(){
    sem_destroy( m_Semaphore );
}

void CCommonMutex::Lock(){

    //如果是同一个线程（锁的持有者）就增加访问计数，否则挂起

    if(m_nPid != getpid()){
        sem_wait( &m_Semaphore );
        m_nPid = getpid();
    }
    count++;
}

bool CCommonMutex::tryLock(){
    if(m_nPid != getpid()){
        if(sem_trywait( &m_Semaphore ) == 0){
            m_nPid = getpid();
            count++;
            return TRUE;
        }
        else{
            return FALSE;
        }
    }
    else{
        count++;
        return TRUE;
    }
}

void CCommonMutex::Unlock(){
    if(m_npid == getpid()){
        if(count == 1){
            //锁持有者最后一次解锁
            m_nPid = 0;
        }
        if(count > 0)
            count--;
        if(count == 0)
            sem_post(&m_Semaphore);
    }
}
