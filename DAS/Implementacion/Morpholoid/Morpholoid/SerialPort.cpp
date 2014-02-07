#include "SerialPort.h"

SerialPortF::SerialPortF() : 
	serialPortHandle(INVALID_HANDLE_VALUE)
{
}

SerialPortF::~SerialPortF()
{    
	Close();
} 

HRESULT SerialPortF::Open(const wchar_t * szPortName, DWORD baudRate)
{
	HRESULT hrResult = S_OK;
	DCB dcb;

	memset( &dcb, 0, sizeof(dcb) );
	
	dcb.DCBlength = sizeof(dcb);
	dcb.BaudRate = baudRate;
	dcb.Parity = NOPARITY;
	dcb.fParity = 0;
	dcb.StopBits = ONESTOPBIT;
	dcb.ByteSize = 8;

	serialPortHandle = CreateFile(szPortName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, NULL, NULL);
	if ( serialPortHandle!=INVALID_HANDLE_VALUE )
	{
		if( !SetCommState(serialPortHandle, &dcb) )
		{
			hrResult = E_INVALIDARG;
			Close();
		}
	}
	else
	{        
		hrResult = ERROR_OPEN_FAILED;
	}
	
	return hrResult;
}

void SerialPortF::Close()
{ 
	if (serialPortHandle!=INVALID_HANDLE_VALUE || serialPortHandle!=NULL)
	{
		PurgeComm(serialPortHandle, PURGE_RXCLEAR | PURGE_TXCLEAR);
		CloseHandle(serialPortHandle);
	}
	serialPortHandle = INVALID_HANDLE_VALUE;
}

void SerialPortF::Clear()
{ 
	if (serialPortHandle!=INVALID_HANDLE_VALUE || serialPortHandle!=NULL)
	{
		PurgeComm(serialPortHandle, PURGE_RXCLEAR | PURGE_TXCLEAR);
	}
}

HRESULT SerialPortF::SendData(BYTE* pBuffer, unsigned long* pSize)
{   
	HRESULT hrResult = ERROR_WRITE_FAULT;

	if (serialPortHandle!=INVALID_HANDLE_VALUE && serialPortHandle!=NULL)
	{
		if( WriteFile(serialPortHandle, pBuffer, *pSize, pSize, NULL) && 
			FlushFileBuffers(serialPortHandle)
		)
		{
			hrResult = S_OK;
		}
	}
	
	return hrResult;
} 

HRESULT SerialPortF::ReceiveData(BYTE* pBuffer, unsigned long* pSize)
{    
	HRESULT hrResult = ERROR_READ_FAULT;

	if (serialPortHandle!=INVALID_HANDLE_VALUE && serialPortHandle!=NULL)
	{
		if( ReadFile(serialPortHandle, pBuffer, *pSize, pSize, NULL) )
		{
			hrResult = S_OK;
		}
	}
	
	return hrResult;
} 

