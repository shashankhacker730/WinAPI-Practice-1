#include <ntddk.h>

//Driver unloading routine
void DUnload(_In_ PDRIVER_OBJECT DO) {
	UNREFERENCED_PARAMETER(DO);

	KdPrint(("Sample Driver Unloaded Successfully"));
}

extern "C"
//DriverEntry is like Main for Driver code
NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT DO, _In_ PUNICODE_STRING RP) {
	/*

	UNREFERENCED_PARAMETER references the argument given just by writing its value as is 
	and shuts up compiler for showing Unused variable error.
	*/
	
	UNREFERENCED_PARAMETER(RP);
	

	DO->DriverUnload = DUnload;

	KdPrint(("Sample Driver Installed Successfully"));

	return STATUS_SUCCESS;
}