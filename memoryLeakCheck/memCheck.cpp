#include "memCheck.h"

MemRecord memRecord;

#ifdef (MEM_DEBUG)

char DELETE_FILE[ FILENAME_LENGTH ] = {0};
int  DELETE_LINE = 0;
CCommonMutex globalLock;
stack<DELINFOSTACK> globalStack;

void BuildStack(){
    DELINFOSTACK delInfo = {"",0};
    strcpy(delInfo.Filename,DELETE_FILE);
    delInfo.LineNum = DELETE_LINE;

    globalStack.push(delInfo);
}

void* operator new( size_t nSize, char *pszFileName, int nLineNum){
    MemOperation record;
    void *pBuf;
    pBuf = ::operator new( nSize );

    //分配成功，则记录该操作的相关信息
    if(pBuf){
        strncpy(record.Filename, pszFileName,FILENAME_LENGTH -1);
        record.Filename[ FILENAME_LENGTH - 1] = '\0';
        record.LineNum = nLineNum;
        record.AllocSize = nSize;
        record.OperationType = SINGLE_NEW;
        record.errCode = 0;
        record.pBuffer = pBuf;
        MemRecord.Insert(pBuf,&record);
    }
    return pBuf;
}
#endif
