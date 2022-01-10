// IoBuf.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "IoBuf.h"

void IoBuf::writeOutInfoRecordInFirstPage(PVOID infoRecord, UINT infoRecordLen)
{
	CopyMemory(buffer, infoRecord, infoRecordLen); // 写入记录。
	fwrite(buffer, IOBUF_SIZE, 1, ioFile); // 写出到文件。
	ZeroMemory(buffer, IOBUF_SIZE); // 清空缓冲区。
}

void IoBuf::writeOutOneDataPage()
{
	CopyMemory(buffer, &recordCnt, sizeof(UINT)); // 写入本页记录数。
	fwrite(buffer, IOBUF_SIZE, 1, ioFile); // 写出到文件。
	recordCnt = 0; // 本页记录数重置。
	writePtr = buffer + sizeof(UINT); // 写指针重置。
	ZeroMemory(buffer, IOBUF_SIZE); // 清空缓冲区。
}

void IoBuf::addOneRecord(PVOID record, UINT recordLen)
{
	if (recordLen + sizeof(UINT) > UINT(IOBUF_SIZE + buffer - writePtr)) // 满了。
		writeOutOneDataPage(); // 写出并换页。
	CopyMemory(writePtr, &recordLen, sizeof(UINT)); // 写入记录长度。
	CopyMemory(writePtr + sizeof(UINT), record, recordLen); // 写入记录。
	writePtr += recordLen + sizeof(UINT); // 写指针后移。
	recordCnt++; // 本页记录加一。
}

PBYTE IoBuf::readInFistPageToGetInfoRecord()
{
	fread(buffer, IOBUF_SIZE, 1, ioFile); // 读取第一页。
	return buffer; // 返回缓冲区指针。
}

bool IoBuf::readInOneDataPage()
{
	ZeroMemory(buffer, IOBUF_SIZE); // 清空缓冲区。
	if (!fread(buffer, IOBUF_SIZE, 1, ioFile)) return false; // 文件读完。
	restCnt = *(UINT*)buffer; // 获得此页记录数。
	readPtr = buffer + sizeof(UINT); // 重置读指针。
	return true;
}

PBYTE IoBuf::getOneRecord(UINT& recordLen)
{
	if (restCnt == 0) // 此页读完需要换页。
		if (!readInOneDataPage()) return NULL; // 文件读完。
	recordLen = *(UINT*)readPtr; // 获得记录长度。
	PBYTE recordPtr = readPtr + sizeof(UINT); // 获得记录位置。
	readPtr += sizeof(UINT) + recordLen; // 读指针后移。
	restCnt--; // 剩余记录数加一。
	return recordPtr; // 返回记录位置。
}

IoBuf::IoBuf(const char* ioFilePath, const char* ioMode)
{
	ZeroMemory(buffer, IOBUF_SIZE); // 清空缓冲区。
	writePtr = buffer + sizeof(UINT); // 重置写指针。
	readPtr = buffer + sizeof(UINT); // 重置读指针。
	recordCnt = 0; // 缓冲区中写入的记录数置零。
	restCnt = 0; // 缓冲区中未读取的记录数置零。
	ioFile = NULL;
	if (ioFilePath && ioMode) fopen_s(&ioFile, ioFilePath, ioMode); // 打开文件（假设不会出错）。
}

IoBuf::~IoBuf()
{
	if (recordCnt != 0) writeOutOneDataPage(); // 最后一页未满的话要写出。
	fclose(ioFile); // 关闭文件。
}
