
#ifndef CFCSOCKET_H
#define CFCSOCKET_H

#include "ClientSocket.h"

const int CPSCKT_MAX_SOCKET_BUFRECIVED = 241 ;//socket max recive buf len
/*==================================================================
note: CPSCKT_MAX_SOCKET_BUFRECIVED > sizeof(CFC_MESSAGE_PACK) + 1
===================================================================*/

//recive STATE const define
const int CPSCKT_RECIVE_STATE1 = 0;//bengin recive
const int CPSCKT_RECIVE_STATE2 = 1;
const int CPSCKT_RECIVE_STATE3 = 2;

class CCFSocket:public CClientSocket  
{
public:
	CCFSocket();
	virtual ~CCFSocket();
	void Initialize();
public:
	
	int m_nDMType;
	int m_nDMID;
	int m_nSMType;
	int m_nSMID;
	int m_nSecDMType ;
	int m_nSecDMID ; 


	
private:

};

#endif 
