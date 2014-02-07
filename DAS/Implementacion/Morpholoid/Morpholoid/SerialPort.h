#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <stdio.h>
#include <conio.h>
#include <Windows.h>

class SerialPortF{
public:
	SerialPortF();
	virtual ~SerialPortF();
	
	HRESULT Open(const wchar_t * szPortName, DWORD baudRate);
	void Close();
	void Clear();

	HRESULT SendData(BYTE* pBuffer, unsigned long* pSize);
	HRESULT ReceiveData(BYTE* pBuffer, unsigned long* pSize);

private:
	HANDLE serialPortHandle;
};

#endif