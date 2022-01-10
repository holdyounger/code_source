#pragma once

#ifndef IOBUF_H_
#define IOBUF_H_

#include <windows.h>
#include <iostream>
#include "stdafx.h"

const int IOBUF_SIZE = 4096;

class IoBuf {
private:
	BYTE buffer[IOBUF_SIZE]; // 缓冲区。
	PBYTE writePtr; // 写指针。
	PBYTE readPtr; // 读指针。
	UINT recordCnt; // 当前缓冲区中记录数。
	UINT restCnt; // 当前缓冲区未读的记录数。
	FILE* ioFile; // 文件。

	void writeOutOneDataPage();
	bool readInOneDataPage();

public:
	IoBuf(const char* ioFilePath, const char* ioMode);
	~IoBuf();

	void writeOutInfoRecordInFirstPage(PVOID infoRecord, UINT infoRecordLen);
	void addOneRecord(PVOID record, UINT recordLen);
	PBYTE readInFistPageToGetInfoRecord();
	PBYTE getOneRecord(UINT& recordLen);
};

#endif // !IOBUF_H_

