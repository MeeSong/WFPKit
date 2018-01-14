#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#pragma warning(push)
#pragma warning(disable: 4201)
#pragma warning(disable: 4324)
#ifndef NDIS_SUPPORT_NDIS6
#define NDIS_SUPPORT_NDIS6 1
#endif // !NDIS_SUPPORT_NDIS6
#include <ntifs.h>
#include <ntddk.h>
#include <ndis.h>
#include <fwpsk.h>
#include <fwpmk.h>
#pragma warning(pop)

#define INITGUID
#include <guiddef.h>
#include <ntimage.h>

NTSTATUS __stdcall ZwQuerySystemInformation(
  ULONG SystemInformationClass,
  PVOID SystemInformation,
  ULONG SystemInformationLength,
  PULONG ReturnLength
);
#define SystemProcessInformation 5
typedef struct _SYSTEM_THREAD_INFORMATION {
  LARGE_INTEGER KernelTime;
  LARGE_INTEGER UserTime;
  LARGE_INTEGER CreateTime;
  LARGE_INTEGER reserved;
  LARGE_INTEGER WaitTime;
  PVOID StartAddress;
  CLIENT_ID ClientId;
  KPRIORITY Priority;
  LONG BasePriority;
  ULONG ContextSwitches;
  ULONG ThreadState;
  ULONG WaitReason;
} SYSTEM_THREAD_INFORMATION, *PSYSTEM_THREAD_INFORMATION;


typedef struct _SYSTEM_PROCESS_INFORMATION {
  ULONG NextEntryOffset;
  ULONG NumberOfThreads;
  LARGE_INTEGER SpareLi1;
  LARGE_INTEGER SpareLi2;
  LARGE_INTEGER SpareLi3;
  LARGE_INTEGER CreateTime;
  LARGE_INTEGER UserTime;
  LARGE_INTEGER KernelTime;
  UNICODE_STRING ImageName;
  KPRIORITY BasePriority;
  HANDLE UniqueProcessId;
  HANDLE InheritedFromUniqueProcessId;
  ULONG HandleCount;
  ULONG SessionId;
  ULONG_PTR PageDirectoryBase;
  VM_COUNTERS VmCounters;
  IO_COUNTERS IoCounters;
  SYSTEM_THREAD_INFORMATION Threads[1];
} SYSTEM_PROCESS_INFORMATION, *PSYSTEM_PROCESS_INFORMATION;

typedef struct _RTL_PROCESS_MODULE_INFORMATION {
  HANDLE Section;
  PVOID MappedBase;
  PVOID ImageBase;
  ULONG ImageSize;
  ULONG Flags;
  USHORT LoadOrderIndex;
  USHORT InitOrderIndex;
  USHORT LoadCount;
  USHORT OffsetToFileName;
  UCHAR FullPathName[256];
}RTL_PROCESS_MODULE_INFORMATION, *PRTL_PROCESS_MODULE_INFORMATION;

typedef struct _RTL_PROCESS_MODULES {
  ULONG NumberOfModules;
  RTL_PROCESS_MODULE_INFORMATION Modules[1];
}RTL_PROCESS_MODULES, *PRTL_PROCESS_MODULES;

#ifdef __cplusplus
}
#endif // __cplusplus

/*
KernelGetModuleHandle
    �ں��е�GetModuleHandle
������
    module_name ģ������
    image_size  ���ڷ���ģ���С��
����ֵ��
    ģ�����ʼ��ַ��ʧ�ܷ���NULL��
*/
PVOID KernelGetModuleHandle(char* module_name, ULONG* image_size);

/*
KernelGetProcAddress
    �ں˵�GetProcAddress��
������
    module     ģ���ַ��
    size       ģ���С��
    proc_name  ������������
����ֵ��
    ����ָ�롣��������ڣ��򷵻�NULL��
*/
PVOID KernelGetProcAddress(PVOID module, ULONG size, char* proc_name);

#endif // !_GLOBAL_H_

