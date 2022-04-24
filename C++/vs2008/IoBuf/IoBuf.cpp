// IoBuf.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "IoBuf.h"

void IoBuf::writeOutInfoRecordInFirstPage(PVOID infoRecord, UINT infoRecordLen)
{
	CopyMemory(buffer, infoRecord, infoRecordLen); // д���¼��
	fwrite(buffer, IOBUF_SIZE, 1, ioFile); // д�����ļ���
	ZeroMemory(buffer, IOBUF_SIZE); // ��ջ�������
}

void IoBuf::writeOutOneDataPage()
{
	CopyMemory(buffer, &recordCnt, sizeof(UINT)); // д�뱾ҳ��¼����
	fwrite(buffer, IOBUF_SIZE, 1, ioFile); // д�����ļ���
	recordCnt = 0; // ��ҳ��¼�����á�
	writePtr = buffer + sizeof(UINT); // дָ�����á�
	ZeroMemory(buffer, IOBUF_SIZE); // ��ջ�������
}

void IoBuf::addOneRecord(PVOID record, UINT recordLen)
{
	if (recordLen + sizeof(UINT) > UINT(IOBUF_SIZE + buffer - writePtr)) // ���ˡ�
		writeOutOneDataPage(); // д������ҳ��
	CopyMemory(writePtr, &recordLen, sizeof(UINT)); // д���¼���ȡ�
	CopyMemory(writePtr + sizeof(UINT), record, recordLen); // д���¼��
	writePtr += recordLen + sizeof(UINT); // дָ����ơ�
	recordCnt++; // ��ҳ��¼��һ��
}

PBYTE IoBuf::readInFistPageToGetInfoRecord()
{
	fread(buffer, IOBUF_SIZE, 1, ioFile); // ��ȡ��һҳ��
	return buffer; // ���ػ�����ָ�롣
}

bool IoBuf::readInOneDataPage()
{
	ZeroMemory(buffer, IOBUF_SIZE); // ��ջ�������
	if (!fread(buffer, IOBUF_SIZE, 1, ioFile)) return false; // �ļ����ꡣ
	restCnt = *(UINT*)buffer; // ��ô�ҳ��¼����
	readPtr = buffer + sizeof(UINT); // ���ö�ָ�롣
	return true;
}

PBYTE IoBuf::getOneRecord(UINT& recordLen)
{
	if (restCnt == 0) // ��ҳ������Ҫ��ҳ��
		if (!readInOneDataPage()) return NULL; // �ļ����ꡣ
	recordLen = *(UINT*)readPtr; // ��ü�¼���ȡ�
	PBYTE recordPtr = readPtr + sizeof(UINT); // ��ü�¼λ�á�
	readPtr += sizeof(UINT) + recordLen; // ��ָ����ơ�
	restCnt--; // ʣ���¼����һ��
	return recordPtr; // ���ؼ�¼λ�á�
}

IoBuf::IoBuf(const char* ioFilePath, const char* ioMode)
{
	ZeroMemory(buffer, IOBUF_SIZE); // ��ջ�������
	writePtr = buffer + sizeof(UINT); // ����дָ�롣
	readPtr = buffer + sizeof(UINT); // ���ö�ָ�롣
	recordCnt = 0; // ��������д��ļ�¼�����㡣
	restCnt = 0; // ��������δ��ȡ�ļ�¼�����㡣
	ioFile = NULL;
	if (ioFilePath && ioMode) fopen_s(&ioFile, ioFilePath, ioMode); // ���ļ������費�������
}

IoBuf::~IoBuf()
{
	if (recordCnt != 0) writeOutOneDataPage(); // ���һҳδ���Ļ�Ҫд����
	fclose(ioFile); // �ر��ļ���
}
