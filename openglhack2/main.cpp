#include "stdafx.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#define APP_NAME    "Tiny DLL Proxy"
#define APP_VERSION "1.0 [03.11.2019]"
#include "Main.h"

struct winspoolx
{
  HMODULE dll;
  FARPROC ADVANCEDSETUPDIALOG;
  FARPROC AbortPrinter;
  FARPROC AddFormA;
  FARPROC AddFormW;
  FARPROC AddJobA;
  FARPROC AddJobW;
  FARPROC AddMonitorA;
  FARPROC AddMonitorW;
  FARPROC AddPortA;
  FARPROC AddPortExA;
  FARPROC AddPortExW;
  FARPROC AddPortW;
  FARPROC AddPrintProcessorA;
  FARPROC AddPrintProcessorW;
  FARPROC AddPrintProvidorA;
  FARPROC AddPrintProvidorW;
  FARPROC AddPrinterA;
  FARPROC AddPrinterConnection2A;
  FARPROC AddPrinterConnection2W;
  FARPROC AddPrinterConnectionA;
  FARPROC AddPrinterConnectionW;
  FARPROC AddPrinterDriverA;
  FARPROC AddPrinterDriverExA;
  FARPROC AddPrinterDriverExW;
  FARPROC AddPrinterDriverW;
  FARPROC AddPrinterW;
  FARPROC AdvancedDocumentPropertiesA;
  FARPROC AdvancedDocumentPropertiesW;
  FARPROC AdvancedSetupDialog;
  FARPROC ClosePrinter;
  FARPROC CloseSpoolFileHandle;
  FARPROC CommitSpoolData;
  FARPROC ConfigurePortA;
  FARPROC ConfigurePortW;
  FARPROC ConnectToPrinterDlg;
  FARPROC ConvertAnsiDevModeToUnicodeDevmode;
  FARPROC ConvertUnicodeDevModeToAnsiDevmode;
  FARPROC CorePrinterDriverInstalledA;
  FARPROC CorePrinterDriverInstalledW;
  FARPROC CreatePrintAsyncNotifyChannel;
  FARPROC CreatePrinterIC;
  FARPROC DEVICECAPABILITIES;
  FARPROC DEVICEMODE;
  FARPROC DeleteFormA;
  FARPROC DeleteFormW;
  FARPROC DeleteJobNamedProperty;
  FARPROC DeleteMonitorA;
  FARPROC DeleteMonitorW;
  FARPROC DeletePortA;
  FARPROC DeletePortW;
  FARPROC DeletePrintProcessorA;
  FARPROC DeletePrintProcessorW;
  FARPROC DeletePrintProvidorA;
  FARPROC DeletePrintProvidorW;
  FARPROC DeletePrinter;
  FARPROC DeletePrinterConnectionA;
  FARPROC DeletePrinterConnectionW;
  FARPROC DeletePrinterDataA;
  FARPROC DeletePrinterDataExA;
  FARPROC DeletePrinterDataExW;
  FARPROC DeletePrinterDataW;
  FARPROC DeletePrinterDriverA;
  FARPROC DeletePrinterDriverExA;
  FARPROC DeletePrinterDriverExW;
  FARPROC DeletePrinterDriverPackageA;
  FARPROC DeletePrinterDriverPackageW;
  FARPROC DeletePrinterDriverW;
  FARPROC DeletePrinterIC;
  FARPROC DeletePrinterKeyA;
  FARPROC DeletePrinterKeyW;
  FARPROC DevQueryPrint;
  FARPROC DevQueryPrintEx;
  FARPROC DeviceCapabilities;
  FARPROC DeviceCapabilitiesA2;
  FARPROC DeviceCapabilitiesW;
  FARPROC DeviceMode;
  FARPROC DevicePropertySheets;
  FARPROC DocumentEvent;
  FARPROC DocumentPropertiesA;
  FARPROC DocumentPropertiesW;
  FARPROC DocumentPropertySheets;
  FARPROC EXTDEVICEMODE;
  FARPROC EndDocPrinter;
  FARPROC EndPagePrinter;
  FARPROC EnumFormsA;
  FARPROC EnumFormsW;
  FARPROC EnumJobNamedProperties;
  FARPROC EnumJobsA;
  FARPROC EnumJobsW;
  FARPROC EnumMonitorsA;
  FARPROC EnumMonitorsW;
  FARPROC EnumPortsA;
  FARPROC EnumPortsW;
  FARPROC EnumPrintProcessorDatatypesA;
  FARPROC EnumPrintProcessorDatatypesW;
  FARPROC EnumPrintProcessorsA;
  FARPROC EnumPrintProcessorsW;
  FARPROC EnumPrinterDataA;
  FARPROC EnumPrinterDataExA;
  FARPROC EnumPrinterDataExW;
  FARPROC EnumPrinterDataW;
  FARPROC EnumPrinterDriversA;
  FARPROC EnumPrinterDriversW;
  FARPROC EnumPrinterKeyA;
  FARPROC EnumPrinterKeyW;
  FARPROC EnumPrintersA;
  FARPROC EnumPrintersW;
  FARPROC ExtDeviceMode;
  FARPROC FindClosePrinterChangeNotification;
  FARPROC FindFirstPrinterChangeNotification;
  FARPROC FindNextPrinterChangeNotification;
  FARPROC FlushPrinter;
  FARPROC FreePrintNamedPropertyArray;
  FARPROC FreePrintPropertyValue;
  FARPROC FreePrinterNotifyInfo;
  FARPROC GetCorePrinterDriversA;
  FARPROC GetCorePrinterDriversW;
  FARPROC GetDefaultPrinterA;
  FARPROC GetDefaultPrinterW;
  FARPROC GetFormA;
  FARPROC GetFormW;
  FARPROC GetJobA;
  FARPROC GetJobNamedPropertyValue;
  FARPROC GetJobW;
  FARPROC GetPrintExecutionData;
  FARPROC GetPrintOutputInfo;
  FARPROC GetPrintProcessorDirectoryA;
  FARPROC GetPrintProcessorDirectoryW;
  FARPROC GetPrinterA;
  FARPROC GetPrinterDataA;
  FARPROC GetPrinterDataExA;
  FARPROC GetPrinterDataExW;
  FARPROC GetPrinterDataW;
  FARPROC GetPrinterDriver2A;
  FARPROC GetPrinterDriver2W;
  FARPROC GetPrinterDriverA;
  FARPROC GetPrinterDriverDirectoryA;
  FARPROC GetPrinterDriverDirectoryW;
  FARPROC GetPrinterDriverPackagePathA;
  FARPROC GetPrinterDriverPackagePathW;
  FARPROC GetPrinterDriverW;
  FARPROC GetPrinterW;
  FARPROC GetSpoolFileHandle;
  FARPROC InstallPrinterDriverFromPackageA;
  FARPROC InstallPrinterDriverFromPackageW;
  FARPROC IsValidDevmodeA;
  FARPROC IsValidDevmodeW;
  FARPROC OpenPrinter2A;
  FARPROC OpenPrinter2W;
  FARPROC OpenPrinterA;
  FARPROC OpenPrinterW;
  FARPROC PerfClose;
  FARPROC PerfCollect;
  FARPROC PerfOpen;
  FARPROC PlayGdiScriptOnPrinterIC;
  FARPROC PrinterMessageBoxA;
  FARPROC PrinterMessageBoxW;
  FARPROC PrinterProperties;
  FARPROC QueryColorProfile;
  FARPROC QueryRemoteFonts;
  FARPROC QuerySpoolMode;
  FARPROC ReadPrinter;
  FARPROC RegisterForPrintAsyncNotifications;
  FARPROC ReportJobProcessingProgress;
  FARPROC ResetPrinterA;
  FARPROC ResetPrinterW;
  FARPROC ScheduleJob;
  FARPROC SeekPrinter;
  FARPROC SetDefaultPrinterA;
  FARPROC SetDefaultPrinterW;
  FARPROC SetFormA;
  FARPROC SetFormW;
  FARPROC SetJobA;
  FARPROC SetJobNamedProperty;
  FARPROC SetJobW;
  FARPROC SetPortA;
  FARPROC SetPortW;
  FARPROC SetPrinterA;
  FARPROC SetPrinterDataA;
  FARPROC SetPrinterDataExA;
  FARPROC SetPrinterDataExW;
  FARPROC SetPrinterDataW;
  FARPROC SetPrinterW;
  FARPROC SetSplwow64AppCompat;
  FARPROC SplDriverUnloadComplete;
  FARPROC SpoolerDevQueryPrintW;
  FARPROC SpoolerPrinterEvent;
  FARPROC StartDocDlgA;
  FARPROC StartDocDlgW;
  FARPROC StartDocPrinterA;
  FARPROC StartDocPrinterW;
  FARPROC StartPagePrinter;
  FARPROC UnRegisterForPrintAsyncNotifications;
  FARPROC UploadPrinterDriverPackageA;
  FARPROC UploadPrinterDriverPackageW;
  FARPROC WaitForPrinterChange;
  FARPROC WritePrinter;
  FARPROC XcvDataW;
} winspoolx;

__declspec() void _ADVANCEDSETUPDIALOG() { winspoolx.ADVANCEDSETUPDIALOG; }
__declspec() void _AbortPrinter() { winspoolx.AbortPrinter; }
__declspec() void _AddFormA() { winspoolx.AddFormA; }
__declspec() void _AddFormW() { winspoolx.AddFormW; }
__declspec() void _AddJobA() { winspoolx.AddJobA; }
__declspec() void _AddJobW() { winspoolx.AddJobW; }
__declspec() void _AddMonitorA() { winspoolx.AddMonitorA; }
__declspec() void _AddMonitorW() { winspoolx.AddMonitorW; }
__declspec() void _AddPortA() { winspoolx.AddPortA; }
__declspec() void _AddPortExA() { winspoolx.AddPortExA; }
__declspec() void _AddPortExW() { winspoolx.AddPortExW; }
__declspec() void _AddPortW() { winspoolx.AddPortW; }
__declspec() void _AddPrintProcessorA() { winspoolx.AddPrintProcessorA; }
__declspec() void _AddPrintProcessorW() { winspoolx.AddPrintProcessorW; }
__declspec() void _AddPrintProvidorA() { winspoolx.AddPrintProvidorA; }
__declspec() void _AddPrintProvidorW() { winspoolx.AddPrintProvidorW; }
__declspec() void _AddPrinterA() { winspoolx.AddPrinterA; }
__declspec() void _AddPrinterConnection2A() { winspoolx.AddPrinterConnection2A; }
__declspec() void _AddPrinterConnection2W() { winspoolx.AddPrinterConnection2W; }
__declspec() void _AddPrinterConnectionA() { winspoolx.AddPrinterConnectionA; }
__declspec() void _AddPrinterConnectionW() { winspoolx.AddPrinterConnectionW; }
__declspec() void _AddPrinterDriverA() { winspoolx.AddPrinterDriverA; }
__declspec() void _AddPrinterDriverExA() { winspoolx.AddPrinterDriverExA; }
__declspec() void _AddPrinterDriverExW() { winspoolx.AddPrinterDriverExW; }
__declspec() void _AddPrinterDriverW() { winspoolx.AddPrinterDriverW; }
__declspec() void _AddPrinterW() { winspoolx.AddPrinterW; }
__declspec() void _AdvancedDocumentPropertiesA() { winspoolx.AdvancedDocumentPropertiesA; }
__declspec() void _AdvancedDocumentPropertiesW() { winspoolx.AdvancedDocumentPropertiesW; }
__declspec() void _AdvancedSetupDialog() { winspoolx.AdvancedSetupDialog; }
__declspec() void _ClosePrinter() { winspoolx.ClosePrinter; }
__declspec() void _CloseSpoolFileHandle() { winspoolx.CloseSpoolFileHandle; }
__declspec() void _CommitSpoolData() { winspoolx.CommitSpoolData; }
__declspec() void _ConfigurePortA() { winspoolx.ConfigurePortA; }
__declspec() void _ConfigurePortW() { winspoolx.ConfigurePortW; }
__declspec() void _ConnectToPrinterDlg() { winspoolx.ConnectToPrinterDlg; }
__declspec() void _ConvertAnsiDevModeToUnicodeDevmode() { winspoolx.ConvertAnsiDevModeToUnicodeDevmode; }
__declspec() void _ConvertUnicodeDevModeToAnsiDevmode() { winspoolx.ConvertUnicodeDevModeToAnsiDevmode; }
__declspec() void _CorePrinterDriverInstalledA() { winspoolx.CorePrinterDriverInstalledA; }
__declspec() void _CorePrinterDriverInstalledW() { winspoolx.CorePrinterDriverInstalledW; }
__declspec() void _CreatePrintAsyncNotifyChannel() { winspoolx.CreatePrintAsyncNotifyChannel; }
__declspec() void _CreatePrinterIC() { winspoolx.CreatePrinterIC; }
__declspec() void _DEVICECAPABILITIES() { winspoolx.DEVICECAPABILITIES; }
__declspec() void _DEVICEMODE() { winspoolx.DEVICEMODE; }
__declspec() void _DeleteFormA() { winspoolx.DeleteFormA; }
__declspec() void _DeleteFormW() { winspoolx.DeleteFormW; }
__declspec() void _DeleteJobNamedProperty() { winspoolx.DeleteJobNamedProperty; }
__declspec() void _DeleteMonitorA() { winspoolx.DeleteMonitorA; }
__declspec() void _DeleteMonitorW() { winspoolx.DeleteMonitorW; }
__declspec() void _DeletePortA() { winspoolx.DeletePortA; }
__declspec() void _DeletePortW() { winspoolx.DeletePortW; }
__declspec() void _DeletePrintProcessorA() { winspoolx.DeletePrintProcessorA; }
__declspec() void _DeletePrintProcessorW() { winspoolx.DeletePrintProcessorW; }
__declspec() void _DeletePrintProvidorA() { winspoolx.DeletePrintProvidorA; }
__declspec() void _DeletePrintProvidorW() { winspoolx.DeletePrintProvidorW; }
__declspec() void _DeletePrinter() { winspoolx.DeletePrinter; }
__declspec() void _DeletePrinterConnectionA() { winspoolx.DeletePrinterConnectionA; }
__declspec() void _DeletePrinterConnectionW() { winspoolx.DeletePrinterConnectionW; }
__declspec() void _DeletePrinterDataA() { winspoolx.DeletePrinterDataA; }
__declspec() void _DeletePrinterDataExA() { winspoolx.DeletePrinterDataExA; }
__declspec() void _DeletePrinterDataExW() { winspoolx.DeletePrinterDataExW; }
__declspec() void _DeletePrinterDataW() { winspoolx.DeletePrinterDataW; }
__declspec() void _DeletePrinterDriverA() { winspoolx.DeletePrinterDriverA; }
__declspec() void _DeletePrinterDriverExA() { winspoolx.DeletePrinterDriverExA; }
__declspec() void _DeletePrinterDriverExW() { winspoolx.DeletePrinterDriverExW; }
__declspec() void _DeletePrinterDriverPackageA() { winspoolx.DeletePrinterDriverPackageA; }
__declspec() void _DeletePrinterDriverPackageW() { winspoolx.DeletePrinterDriverPackageW; }
__declspec() void _DeletePrinterDriverW() { winspoolx.DeletePrinterDriverW; }
__declspec() void _DeletePrinterIC() { winspoolx.DeletePrinterIC; }
__declspec() void _DeletePrinterKeyA() { winspoolx.DeletePrinterKeyA; }
__declspec() void _DeletePrinterKeyW() { winspoolx.DeletePrinterKeyW; }
__declspec() void _DevQueryPrint() { winspoolx.DevQueryPrint; }
__declspec() void _DevQueryPrintEx() { winspoolx.DevQueryPrintEx; }
__declspec() void _DeviceCapabilities() { winspoolx.DeviceCapabilities; }
__declspec() void _DeviceCapabilitiesA() { winspoolx.DeviceCapabilitiesA2; }
__declspec() void _DeviceCapabilitiesW() { winspoolx.DeviceCapabilitiesW; }
__declspec() void _DeviceMode() { winspoolx.DeviceMode; }
__declspec() void _DevicePropertySheets() { winspoolx.DevicePropertySheets; }
__declspec() void _DocumentEvent() { winspoolx.DocumentEvent; }
__declspec() void _DocumentPropertiesA() { winspoolx.DocumentPropertiesA; }
__declspec() void _DocumentPropertiesW() { winspoolx.DocumentPropertiesW; }
__declspec() void _DocumentPropertySheets() { winspoolx.DocumentPropertySheets; }
__declspec() void _EXTDEVICEMODE() { winspoolx.EXTDEVICEMODE; }
__declspec() void _EndDocPrinter() { winspoolx.EndDocPrinter; }
__declspec() void _EndPagePrinter() { winspoolx.EndPagePrinter; }
__declspec() void _EnumFormsA() { winspoolx.EnumFormsA; }
__declspec() void _EnumFormsW() { winspoolx.EnumFormsW; }
__declspec() void _EnumJobNamedProperties() { winspoolx.EnumJobNamedProperties; }
__declspec() void _EnumJobsA() { winspoolx.EnumJobsA; }
__declspec() void _EnumJobsW() { winspoolx.EnumJobsW; }
__declspec() void _EnumMonitorsA() { winspoolx.EnumMonitorsA; }
__declspec() void _EnumMonitorsW() { winspoolx.EnumMonitorsW; }
__declspec() void _EnumPortsA() { winspoolx.EnumPortsA; }
__declspec() void _EnumPortsW() { winspoolx.EnumPortsW; }
__declspec() void _EnumPrintProcessorDatatypesA() { winspoolx.EnumPrintProcessorDatatypesA; }
__declspec() void _EnumPrintProcessorDatatypesW() { winspoolx.EnumPrintProcessorDatatypesW; }
__declspec() void _EnumPrintProcessorsA() { winspoolx.EnumPrintProcessorsA; }
__declspec() void _EnumPrintProcessorsW() { winspoolx.EnumPrintProcessorsW; }
__declspec() void _EnumPrinterDataA() { winspoolx.EnumPrinterDataA; }
__declspec() void _EnumPrinterDataExA() { winspoolx.EnumPrinterDataExA; }
__declspec() void _EnumPrinterDataExW() { winspoolx.EnumPrinterDataExW; }
__declspec() void _EnumPrinterDataW() { winspoolx.EnumPrinterDataW; }
__declspec() void _EnumPrinterDriversA() { winspoolx.EnumPrinterDriversA; }
__declspec() void _EnumPrinterDriversW() { winspoolx.EnumPrinterDriversW; }
__declspec() void _EnumPrinterKeyA() { winspoolx.EnumPrinterKeyA; }
__declspec() void _EnumPrinterKeyW() { winspoolx.EnumPrinterKeyW; }
__declspec() void _EnumPrintersA() { winspoolx.EnumPrintersA; }
__declspec() void _EnumPrintersW() { winspoolx.EnumPrintersW; }
__declspec() void _ExtDeviceMode() { winspoolx.ExtDeviceMode; }
__declspec() void _FindClosePrinterChangeNotification() { winspoolx.FindClosePrinterChangeNotification; }
__declspec() void _FindFirstPrinterChangeNotification() { winspoolx.FindFirstPrinterChangeNotification; }
__declspec() void _FindNextPrinterChangeNotification() { winspoolx.FindNextPrinterChangeNotification; }
__declspec() void _FlushPrinter() { winspoolx.FlushPrinter; }
__declspec() void _FreePrintNamedPropertyArray() { winspoolx.FreePrintNamedPropertyArray; }
__declspec() void _FreePrintPropertyValue() { winspoolx.FreePrintPropertyValue; }
__declspec() void _FreePrinterNotifyInfo() { winspoolx.FreePrinterNotifyInfo; }
__declspec() void _GetCorePrinterDriversA() { winspoolx.GetCorePrinterDriversA; }
__declspec() void _GetCorePrinterDriversW() { winspoolx.GetCorePrinterDriversW; }
__declspec() void _GetDefaultPrinterA() { winspoolx.GetDefaultPrinterA; }
__declspec() void _GetDefaultPrinterW() { winspoolx.GetDefaultPrinterW; }
__declspec() void _GetFormA() { winspoolx.GetFormA; }
__declspec() void _GetFormW() { winspoolx.GetFormW; }
__declspec() void _GetJobA() { winspoolx.GetJobA; }
__declspec() void _GetJobNamedPropertyValue() { winspoolx.GetJobNamedPropertyValue; }
__declspec() void _GetJobW() { winspoolx.GetJobW; }
__declspec() void _GetPrintExecutionData() { winspoolx.GetPrintExecutionData; }
__declspec() void _GetPrintOutputInfo() { winspoolx.GetPrintOutputInfo; }
__declspec() void _GetPrintProcessorDirectoryA() { winspoolx.GetPrintProcessorDirectoryA; }
__declspec() void _GetPrintProcessorDirectoryW() { winspoolx.GetPrintProcessorDirectoryW; }
__declspec() void _GetPrinterA() { winspoolx.GetPrinterA; }
__declspec() void _GetPrinterDataA() { winspoolx.GetPrinterDataA; }
__declspec() void _GetPrinterDataExA() { winspoolx.GetPrinterDataExA; }
__declspec() void _GetPrinterDataExW() { winspoolx.GetPrinterDataExW; }
__declspec() void _GetPrinterDataW() { winspoolx.GetPrinterDataW; }
__declspec() void _GetPrinterDriver2A() { winspoolx.GetPrinterDriver2A; }
__declspec() void _GetPrinterDriver2W() { winspoolx.GetPrinterDriver2W; }
__declspec() void _GetPrinterDriverA() { winspoolx.GetPrinterDriverA; }
__declspec() void _GetPrinterDriverDirectoryA() { winspoolx.GetPrinterDriverDirectoryA; }
__declspec() void _GetPrinterDriverDirectoryW() { winspoolx.GetPrinterDriverDirectoryW; }
__declspec() void _GetPrinterDriverPackagePathA() { winspoolx.GetPrinterDriverPackagePathA; }
__declspec() void _GetPrinterDriverPackagePathW() { winspoolx.GetPrinterDriverPackagePathW; }
__declspec() void _GetPrinterDriverW() { winspoolx.GetPrinterDriverW; }
__declspec() void _GetPrinterW() { winspoolx.GetPrinterW; }
__declspec() void _GetSpoolFileHandle() { winspoolx.GetSpoolFileHandle; }
__declspec() void _InstallPrinterDriverFromPackageA() { winspoolx.InstallPrinterDriverFromPackageA; }
__declspec() void _InstallPrinterDriverFromPackageW() { winspoolx.InstallPrinterDriverFromPackageW; }
__declspec() void _IsValidDevmodeA() { winspoolx.IsValidDevmodeA; }
__declspec() void _IsValidDevmodeW() { winspoolx.IsValidDevmodeW; }
__declspec() void _OpenPrinter2A() { winspoolx.OpenPrinter2A; }
__declspec() void _OpenPrinter2W() { winspoolx.OpenPrinter2W; }
__declspec() void _OpenPrinterA() { winspoolx.OpenPrinterA; }
__declspec() void _OpenPrinterW() { winspoolx.OpenPrinterW; }
__declspec() void _PerfClose() { winspoolx.PerfClose; }
__declspec() void _PerfCollect() { winspoolx.PerfCollect; }
__declspec() void _PerfOpen() { winspoolx.PerfOpen; }
__declspec() void _PlayGdiScriptOnPrinterIC() { winspoolx.PlayGdiScriptOnPrinterIC; }
__declspec() void _PrinterMessageBoxA() { winspoolx.PrinterMessageBoxA; }
__declspec() void _PrinterMessageBoxW() { winspoolx.PrinterMessageBoxW; }
__declspec() void _PrinterProperties() { winspoolx.PrinterProperties; }
__declspec() void _QueryColorProfile() { winspoolx.QueryColorProfile; }
__declspec() void _QueryRemoteFonts() { winspoolx.QueryRemoteFonts; }
__declspec() void _QuerySpoolMode() { winspoolx.QuerySpoolMode; }
__declspec() void _ReadPrinter() { winspoolx.ReadPrinter; }
__declspec() void _RegisterForPrintAsyncNotifications() { winspoolx.RegisterForPrintAsyncNotifications; }
__declspec() void _ReportJobProcessingProgress() { winspoolx.ReportJobProcessingProgress; }
__declspec() void _ResetPrinterA() { winspoolx.ResetPrinterA; }
__declspec() void _ResetPrinterW() { winspoolx.ResetPrinterW; }
__declspec() void _ScheduleJob() { winspoolx.ScheduleJob; }
__declspec() void _SeekPrinter() { winspoolx.SeekPrinter; }
__declspec() void _SetDefaultPrinterA() { winspoolx.SetDefaultPrinterA; }
__declspec() void _SetDefaultPrinterW() { winspoolx.SetDefaultPrinterW; }
__declspec() void _SetFormA() { winspoolx.SetFormA; }
__declspec() void _SetFormW() { winspoolx.SetFormW; }
__declspec() void _SetJobA() { winspoolx.SetJobA; }
__declspec() void _SetJobNamedProperty() { winspoolx.SetJobNamedProperty; }
__declspec() void _SetJobW() { winspoolx.SetJobW; }
__declspec() void _SetPortA() { winspoolx.SetPortA; }
__declspec() void _SetPortW() { winspoolx.SetPortW; }
__declspec() void _SetPrinterA() { winspoolx.SetPrinterA; }
__declspec() void _SetPrinterDataA() { winspoolx.SetPrinterDataA; }
__declspec() void _SetPrinterDataExA() { winspoolx.SetPrinterDataExA; }
__declspec() void _SetPrinterDataExW() { winspoolx.SetPrinterDataExW; }
__declspec() void _SetPrinterDataW() { winspoolx.SetPrinterDataW; }
__declspec() void _SetPrinterW() { winspoolx.SetPrinterW; }
__declspec() void _SetSplwow64AppCompat() { winspoolx.SetSplwow64AppCompat; }
__declspec() void _SplDriverUnloadComplete() { winspoolx.SplDriverUnloadComplete; }
__declspec() void _SpoolerDevQueryPrintW() { winspoolx.SpoolerDevQueryPrintW; }
__declspec() void _SpoolerPrinterEvent() { winspoolx.SpoolerPrinterEvent; }
__declspec() void _StartDocDlgA() { winspoolx.StartDocDlgA; }
__declspec() void _StartDocDlgW() { winspoolx.StartDocDlgW; }
__declspec() void _StartDocPrinterA() { winspoolx.StartDocPrinterA; }
__declspec() void _StartDocPrinterW() { winspoolx.StartDocPrinterW; }
__declspec() void _StartPagePrinter() { winspoolx.StartPagePrinter; }
__declspec() void _UnRegisterForPrintAsyncNotifications() { winspoolx.UnRegisterForPrintAsyncNotifications; }
__declspec() void _UploadPrinterDriverPackageA() { winspoolx.UploadPrinterDriverPackageA; }
__declspec() void _UploadPrinterDriverPackageW() { winspoolx.UploadPrinterDriverPackageW; }
__declspec() void _WaitForPrinterChange() { winspoolx.WaitForPrinterChange; }
__declspec() void _WritePrinter() { winspoolx.WritePrinter; }
__declspec() void _XcvDataW() { winspoolx.XcvDataW; }

BOOL APIENTRY DllMain2222(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    char path[MAX_PATH];
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CopyMemory(path + GetSystemDirectory(path, MAX_PATH - 17), "\\winspool.drv", 18);
        winspoolx.dll = LoadLibrary(path);
        if (!winspoolx.dll)
        {
            MessageBox(0, "Не удалось загрузить winspoolx.dll!", APP_NAME, MB_ICONERROR);
            ExitProcess(0);
        }
        winspoolx.ADVANCEDSETUPDIALOG = GetProcAddress(winspoolx.dll, "ADVANCEDSETUPDIALOG");
        winspoolx.AbortPrinter = GetProcAddress(winspoolx.dll, "AbortPrinter");
        winspoolx.AddFormA = GetProcAddress(winspoolx.dll, "AddFormA");
        winspoolx.AddFormW = GetProcAddress(winspoolx.dll, "AddFormW");
        winspoolx.AddJobA = GetProcAddress(winspoolx.dll, "AddJobA");
        winspoolx.AddJobW = GetProcAddress(winspoolx.dll, "AddJobW");
        winspoolx.AddMonitorA = GetProcAddress(winspoolx.dll, "AddMonitorA");
        winspoolx.AddMonitorW = GetProcAddress(winspoolx.dll, "AddMonitorW");
        winspoolx.AddPortA = GetProcAddress(winspoolx.dll, "AddPortA");
        winspoolx.AddPortExA = GetProcAddress(winspoolx.dll, "AddPortExA");
        winspoolx.AddPortExW = GetProcAddress(winspoolx.dll, "AddPortExW");
        winspoolx.AddPortW = GetProcAddress(winspoolx.dll, "AddPortW");
        winspoolx.AddPrintProcessorA = GetProcAddress(winspoolx.dll, "AddPrintProcessorA");
        winspoolx.AddPrintProcessorW = GetProcAddress(winspoolx.dll, "AddPrintProcessorW");
        winspoolx.AddPrintProvidorA = GetProcAddress(winspoolx.dll, "AddPrintProvidorA");
        winspoolx.AddPrintProvidorW = GetProcAddress(winspoolx.dll, "AddPrintProvidorW");
        winspoolx.AddPrinterA = GetProcAddress(winspoolx.dll, "AddPrinterA");
        winspoolx.AddPrinterConnection2A = GetProcAddress(winspoolx.dll, "AddPrinterConnection2A");
        winspoolx.AddPrinterConnection2W = GetProcAddress(winspoolx.dll, "AddPrinterConnection2W");
        winspoolx.AddPrinterConnectionA = GetProcAddress(winspoolx.dll, "AddPrinterConnectionA");
        winspoolx.AddPrinterConnectionW = GetProcAddress(winspoolx.dll, "AddPrinterConnectionW");
        winspoolx.AddPrinterDriverA = GetProcAddress(winspoolx.dll, "AddPrinterDriverA");
        winspoolx.AddPrinterDriverExA = GetProcAddress(winspoolx.dll, "AddPrinterDriverExA");
        winspoolx.AddPrinterDriverExW = GetProcAddress(winspoolx.dll, "AddPrinterDriverExW");
        winspoolx.AddPrinterDriverW = GetProcAddress(winspoolx.dll, "AddPrinterDriverW");
        winspoolx.AddPrinterW = GetProcAddress(winspoolx.dll, "AddPrinterW");
        winspoolx.AdvancedDocumentPropertiesA = GetProcAddress(winspoolx.dll, "AdvancedDocumentPropertiesA");
        winspoolx.AdvancedDocumentPropertiesW = GetProcAddress(winspoolx.dll, "AdvancedDocumentPropertiesW");
        winspoolx.AdvancedSetupDialog = GetProcAddress(winspoolx.dll, "AdvancedSetupDialog");
        winspoolx.ClosePrinter = GetProcAddress(winspoolx.dll, "ClosePrinter");
        winspoolx.CloseSpoolFileHandle = GetProcAddress(winspoolx.dll, "CloseSpoolFileHandle");
        winspoolx.CommitSpoolData = GetProcAddress(winspoolx.dll, "CommitSpoolData");
        winspoolx.ConfigurePortA = GetProcAddress(winspoolx.dll, "ConfigurePortA");
        winspoolx.ConfigurePortW = GetProcAddress(winspoolx.dll, "ConfigurePortW");
        winspoolx.ConnectToPrinterDlg = GetProcAddress(winspoolx.dll, "ConnectToPrinterDlg");
        winspoolx.ConvertAnsiDevModeToUnicodeDevmode = GetProcAddress(winspoolx.dll, "ConvertAnsiDevModeToUnicodeDevmode");
        winspoolx.ConvertUnicodeDevModeToAnsiDevmode = GetProcAddress(winspoolx.dll, "ConvertUnicodeDevModeToAnsiDevmode");
        winspoolx.CorePrinterDriverInstalledA = GetProcAddress(winspoolx.dll, "CorePrinterDriverInstalledA");
        winspoolx.CorePrinterDriverInstalledW = GetProcAddress(winspoolx.dll, "CorePrinterDriverInstalledW");
        winspoolx.CreatePrintAsyncNotifyChannel = GetProcAddress(winspoolx.dll, "CreatePrintAsyncNotifyChannel");
        winspoolx.CreatePrinterIC = GetProcAddress(winspoolx.dll, "CreatePrinterIC");
        winspoolx.DEVICECAPABILITIES = GetProcAddress(winspoolx.dll, "DEVICECAPABILITIES");
        winspoolx.DEVICEMODE = GetProcAddress(winspoolx.dll, "DEVICEMODE");
        winspoolx.DeleteFormA = GetProcAddress(winspoolx.dll, "DeleteFormA");
        winspoolx.DeleteFormW = GetProcAddress(winspoolx.dll, "DeleteFormW");
        winspoolx.DeleteJobNamedProperty = GetProcAddress(winspoolx.dll, "DeleteJobNamedProperty");
        winspoolx.DeleteMonitorA = GetProcAddress(winspoolx.dll, "DeleteMonitorA");
        winspoolx.DeleteMonitorW = GetProcAddress(winspoolx.dll, "DeleteMonitorW");
        winspoolx.DeletePortA = GetProcAddress(winspoolx.dll, "DeletePortA");
        winspoolx.DeletePortW = GetProcAddress(winspoolx.dll, "DeletePortW");
        winspoolx.DeletePrintProcessorA = GetProcAddress(winspoolx.dll, "DeletePrintProcessorA");
        winspoolx.DeletePrintProcessorW = GetProcAddress(winspoolx.dll, "DeletePrintProcessorW");
        winspoolx.DeletePrintProvidorA = GetProcAddress(winspoolx.dll, "DeletePrintProvidorA");
        winspoolx.DeletePrintProvidorW = GetProcAddress(winspoolx.dll, "DeletePrintProvidorW");
        winspoolx.DeletePrinter = GetProcAddress(winspoolx.dll, "DeletePrinter");
        winspoolx.DeletePrinterConnectionA = GetProcAddress(winspoolx.dll, "DeletePrinterConnectionA");
        winspoolx.DeletePrinterConnectionW = GetProcAddress(winspoolx.dll, "DeletePrinterConnectionW");
        winspoolx.DeletePrinterDataA = GetProcAddress(winspoolx.dll, "DeletePrinterDataA");
        winspoolx.DeletePrinterDataExA = GetProcAddress(winspoolx.dll, "DeletePrinterDataExA");
        winspoolx.DeletePrinterDataExW = GetProcAddress(winspoolx.dll, "DeletePrinterDataExW");
        winspoolx.DeletePrinterDataW = GetProcAddress(winspoolx.dll, "DeletePrinterDataW");
        winspoolx.DeletePrinterDriverA = GetProcAddress(winspoolx.dll, "DeletePrinterDriverA");
        winspoolx.DeletePrinterDriverExA = GetProcAddress(winspoolx.dll, "DeletePrinterDriverExA");
        winspoolx.DeletePrinterDriverExW = GetProcAddress(winspoolx.dll, "DeletePrinterDriverExW");
        winspoolx.DeletePrinterDriverPackageA = GetProcAddress(winspoolx.dll, "DeletePrinterDriverPackageA");
        winspoolx.DeletePrinterDriverPackageW = GetProcAddress(winspoolx.dll, "DeletePrinterDriverPackageW");
        winspoolx.DeletePrinterDriverW = GetProcAddress(winspoolx.dll, "DeletePrinterDriverW");
        winspoolx.DeletePrinterIC = GetProcAddress(winspoolx.dll, "DeletePrinterIC");
        winspoolx.DeletePrinterKeyA = GetProcAddress(winspoolx.dll, "DeletePrinterKeyA");
        winspoolx.DeletePrinterKeyW = GetProcAddress(winspoolx.dll, "DeletePrinterKeyW");
        winspoolx.DevQueryPrint = GetProcAddress(winspoolx.dll, "DevQueryPrint");
        winspoolx.DevQueryPrintEx = GetProcAddress(winspoolx.dll, "DevQueryPrintEx");
        winspoolx.DeviceCapabilities = GetProcAddress(winspoolx.dll, "DeviceCapabilities");
        winspoolx.DeviceCapabilitiesA2 = GetProcAddress(winspoolx.dll, "DeviceCapabilitiesA");
        winspoolx.DeviceCapabilitiesW = GetProcAddress(winspoolx.dll, "DeviceCapabilitiesW");
        winspoolx.DeviceMode = GetProcAddress(winspoolx.dll, "DeviceMode");
        winspoolx.DevicePropertySheets = GetProcAddress(winspoolx.dll, "DevicePropertySheets");
        winspoolx.DocumentEvent = GetProcAddress(winspoolx.dll, "DocumentEvent");
        winspoolx.DocumentPropertiesA = GetProcAddress(winspoolx.dll, "DocumentPropertiesA");
        winspoolx.DocumentPropertiesW = GetProcAddress(winspoolx.dll, "DocumentPropertiesW");
        winspoolx.DocumentPropertySheets = GetProcAddress(winspoolx.dll, "DocumentPropertySheets");
        winspoolx.EXTDEVICEMODE = GetProcAddress(winspoolx.dll, "EXTDEVICEMODE");
        winspoolx.EndDocPrinter = GetProcAddress(winspoolx.dll, "EndDocPrinter");
        winspoolx.EndPagePrinter = GetProcAddress(winspoolx.dll, "EndPagePrinter");
        winspoolx.EnumFormsA = GetProcAddress(winspoolx.dll, "EnumFormsA");
        winspoolx.EnumFormsW = GetProcAddress(winspoolx.dll, "EnumFormsW");
        winspoolx.EnumJobNamedProperties = GetProcAddress(winspoolx.dll, "EnumJobNamedProperties");
        winspoolx.EnumJobsA = GetProcAddress(winspoolx.dll, "EnumJobsA");
        winspoolx.EnumJobsW = GetProcAddress(winspoolx.dll, "EnumJobsW");
        winspoolx.EnumMonitorsA = GetProcAddress(winspoolx.dll, "EnumMonitorsA");
        winspoolx.EnumMonitorsW = GetProcAddress(winspoolx.dll, "EnumMonitorsW");
        winspoolx.EnumPortsA = GetProcAddress(winspoolx.dll, "EnumPortsA");
        winspoolx.EnumPortsW = GetProcAddress(winspoolx.dll, "EnumPortsW");
        winspoolx.EnumPrintProcessorDatatypesA = GetProcAddress(winspoolx.dll, "EnumPrintProcessorDatatypesA");
        winspoolx.EnumPrintProcessorDatatypesW = GetProcAddress(winspoolx.dll, "EnumPrintProcessorDatatypesW");
        winspoolx.EnumPrintProcessorsA = GetProcAddress(winspoolx.dll, "EnumPrintProcessorsA");
        winspoolx.EnumPrintProcessorsW = GetProcAddress(winspoolx.dll, "EnumPrintProcessorsW");
        winspoolx.EnumPrinterDataA = GetProcAddress(winspoolx.dll, "EnumPrinterDataA");
        winspoolx.EnumPrinterDataExA = GetProcAddress(winspoolx.dll, "EnumPrinterDataExA");
        winspoolx.EnumPrinterDataExW = GetProcAddress(winspoolx.dll, "EnumPrinterDataExW");
        winspoolx.EnumPrinterDataW = GetProcAddress(winspoolx.dll, "EnumPrinterDataW");
        winspoolx.EnumPrinterDriversA = GetProcAddress(winspoolx.dll, "EnumPrinterDriversA");
        winspoolx.EnumPrinterDriversW = GetProcAddress(winspoolx.dll, "EnumPrinterDriversW");
        winspoolx.EnumPrinterKeyA = GetProcAddress(winspoolx.dll, "EnumPrinterKeyA");
        winspoolx.EnumPrinterKeyW = GetProcAddress(winspoolx.dll, "EnumPrinterKeyW");
        winspoolx.EnumPrintersA = GetProcAddress(winspoolx.dll, "EnumPrintersA");
        winspoolx.EnumPrintersW = GetProcAddress(winspoolx.dll, "EnumPrintersW");
        winspoolx.ExtDeviceMode = GetProcAddress(winspoolx.dll, "ExtDeviceMode");
        winspoolx.FindClosePrinterChangeNotification = GetProcAddress(winspoolx.dll, "FindClosePrinterChangeNotification");
        winspoolx.FindFirstPrinterChangeNotification = GetProcAddress(winspoolx.dll, "FindFirstPrinterChangeNotification");
        winspoolx.FindNextPrinterChangeNotification = GetProcAddress(winspoolx.dll, "FindNextPrinterChangeNotification");
        winspoolx.FlushPrinter = GetProcAddress(winspoolx.dll, "FlushPrinter");
        winspoolx.FreePrintNamedPropertyArray = GetProcAddress(winspoolx.dll, "FreePrintNamedPropertyArray");
        winspoolx.FreePrintPropertyValue = GetProcAddress(winspoolx.dll, "FreePrintPropertyValue");
        winspoolx.FreePrinterNotifyInfo = GetProcAddress(winspoolx.dll, "FreePrinterNotifyInfo");
        winspoolx.GetCorePrinterDriversA = GetProcAddress(winspoolx.dll, "GetCorePrinterDriversA");
        winspoolx.GetCorePrinterDriversW = GetProcAddress(winspoolx.dll, "GetCorePrinterDriversW");
        winspoolx.GetDefaultPrinterA = GetProcAddress(winspoolx.dll, "GetDefaultPrinterA");
        winspoolx.GetDefaultPrinterW = GetProcAddress(winspoolx.dll, "GetDefaultPrinterW");
        winspoolx.GetFormA = GetProcAddress(winspoolx.dll, "GetFormA");
        winspoolx.GetFormW = GetProcAddress(winspoolx.dll, "GetFormW");
        winspoolx.GetJobA = GetProcAddress(winspoolx.dll, "GetJobA");
        winspoolx.GetJobNamedPropertyValue = GetProcAddress(winspoolx.dll, "GetJobNamedPropertyValue");
        winspoolx.GetJobW = GetProcAddress(winspoolx.dll, "GetJobW");
        winspoolx.GetPrintExecutionData = GetProcAddress(winspoolx.dll, "GetPrintExecutionData");
        winspoolx.GetPrintOutputInfo = GetProcAddress(winspoolx.dll, "GetPrintOutputInfo");
        winspoolx.GetPrintProcessorDirectoryA = GetProcAddress(winspoolx.dll, "GetPrintProcessorDirectoryA");
        winspoolx.GetPrintProcessorDirectoryW = GetProcAddress(winspoolx.dll, "GetPrintProcessorDirectoryW");
        winspoolx.GetPrinterA = GetProcAddress(winspoolx.dll, "GetPrinterA");
        winspoolx.GetPrinterDataA = GetProcAddress(winspoolx.dll, "GetPrinterDataA");
        winspoolx.GetPrinterDataExA = GetProcAddress(winspoolx.dll, "GetPrinterDataExA");
        winspoolx.GetPrinterDataExW = GetProcAddress(winspoolx.dll, "GetPrinterDataExW");
        winspoolx.GetPrinterDataW = GetProcAddress(winspoolx.dll, "GetPrinterDataW");
        winspoolx.GetPrinterDriver2A = GetProcAddress(winspoolx.dll, "GetPrinterDriver2A");
        winspoolx.GetPrinterDriver2W = GetProcAddress(winspoolx.dll, "GetPrinterDriver2W");
        winspoolx.GetPrinterDriverA = GetProcAddress(winspoolx.dll, "GetPrinterDriverA");
        winspoolx.GetPrinterDriverDirectoryA = GetProcAddress(winspoolx.dll, "GetPrinterDriverDirectoryA");
        winspoolx.GetPrinterDriverDirectoryW = GetProcAddress(winspoolx.dll, "GetPrinterDriverDirectoryW");
        winspoolx.GetPrinterDriverPackagePathA = GetProcAddress(winspoolx.dll, "GetPrinterDriverPackagePathA");
        winspoolx.GetPrinterDriverPackagePathW = GetProcAddress(winspoolx.dll, "GetPrinterDriverPackagePathW");
        winspoolx.GetPrinterDriverW = GetProcAddress(winspoolx.dll, "GetPrinterDriverW");
        winspoolx.GetPrinterW = GetProcAddress(winspoolx.dll, "GetPrinterW");
        winspoolx.GetSpoolFileHandle = GetProcAddress(winspoolx.dll, "GetSpoolFileHandle");
        winspoolx.InstallPrinterDriverFromPackageA = GetProcAddress(winspoolx.dll, "InstallPrinterDriverFromPackageA");
        winspoolx.InstallPrinterDriverFromPackageW = GetProcAddress(winspoolx.dll, "InstallPrinterDriverFromPackageW");
        winspoolx.IsValidDevmodeA = GetProcAddress(winspoolx.dll, "IsValidDevmodeA");
        winspoolx.IsValidDevmodeW = GetProcAddress(winspoolx.dll, "IsValidDevmodeW");
        winspoolx.OpenPrinter2A = GetProcAddress(winspoolx.dll, "OpenPrinter2A");
        winspoolx.OpenPrinter2W = GetProcAddress(winspoolx.dll, "OpenPrinter2W");
        winspoolx.OpenPrinterA = GetProcAddress(winspoolx.dll, "OpenPrinterA");
        winspoolx.OpenPrinterW = GetProcAddress(winspoolx.dll, "OpenPrinterW");
        winspoolx.PerfClose = GetProcAddress(winspoolx.dll, "PerfClose");
        winspoolx.PerfCollect = GetProcAddress(winspoolx.dll, "PerfCollect");
        winspoolx.PerfOpen = GetProcAddress(winspoolx.dll, "PerfOpen");
        winspoolx.PlayGdiScriptOnPrinterIC = GetProcAddress(winspoolx.dll, "PlayGdiScriptOnPrinterIC");
        winspoolx.PrinterMessageBoxA = GetProcAddress(winspoolx.dll, "PrinterMessageBoxA");
        winspoolx.PrinterMessageBoxW = GetProcAddress(winspoolx.dll, "PrinterMessageBoxW");
        winspoolx.PrinterProperties = GetProcAddress(winspoolx.dll, "PrinterProperties");
        winspoolx.QueryColorProfile = GetProcAddress(winspoolx.dll, "QueryColorProfile");
        winspoolx.QueryRemoteFonts = GetProcAddress(winspoolx.dll, "QueryRemoteFonts");
        winspoolx.QuerySpoolMode = GetProcAddress(winspoolx.dll, "QuerySpoolMode");
        winspoolx.ReadPrinter = GetProcAddress(winspoolx.dll, "ReadPrinter");
        winspoolx.RegisterForPrintAsyncNotifications = GetProcAddress(winspoolx.dll, "RegisterForPrintAsyncNotifications");
        winspoolx.ReportJobProcessingProgress = GetProcAddress(winspoolx.dll, "ReportJobProcessingProgress");
        winspoolx.ResetPrinterA = GetProcAddress(winspoolx.dll, "ResetPrinterA");
        winspoolx.ResetPrinterW = GetProcAddress(winspoolx.dll, "ResetPrinterW");
        winspoolx.ScheduleJob = GetProcAddress(winspoolx.dll, "ScheduleJob");
        winspoolx.SeekPrinter = GetProcAddress(winspoolx.dll, "SeekPrinter");
        winspoolx.SetDefaultPrinterA = GetProcAddress(winspoolx.dll, "SetDefaultPrinterA");
        winspoolx.SetDefaultPrinterW = GetProcAddress(winspoolx.dll, "SetDefaultPrinterW");
        winspoolx.SetFormA = GetProcAddress(winspoolx.dll, "SetFormA");
        winspoolx.SetFormW = GetProcAddress(winspoolx.dll, "SetFormW");
        winspoolx.SetJobA = GetProcAddress(winspoolx.dll, "SetJobA");
        winspoolx.SetJobNamedProperty = GetProcAddress(winspoolx.dll, "SetJobNamedProperty");
        winspoolx.SetJobW = GetProcAddress(winspoolx.dll, "SetJobW");
        winspoolx.SetPortA = GetProcAddress(winspoolx.dll, "SetPortA");
        winspoolx.SetPortW = GetProcAddress(winspoolx.dll, "SetPortW");
        winspoolx.SetPrinterA = GetProcAddress(winspoolx.dll, "SetPrinterA");
        winspoolx.SetPrinterDataA = GetProcAddress(winspoolx.dll, "SetPrinterDataA");
        winspoolx.SetPrinterDataExA = GetProcAddress(winspoolx.dll, "SetPrinterDataExA");
        winspoolx.SetPrinterDataExW = GetProcAddress(winspoolx.dll, "SetPrinterDataExW");
        winspoolx.SetPrinterDataW = GetProcAddress(winspoolx.dll, "SetPrinterDataW");
        winspoolx.SetPrinterW = GetProcAddress(winspoolx.dll, "SetPrinterW");
        winspoolx.SetSplwow64AppCompat = GetProcAddress(winspoolx.dll, "SetSplwow64AppCompat");
        winspoolx.SplDriverUnloadComplete = GetProcAddress(winspoolx.dll, "SplDriverUnloadComplete");
        winspoolx.SpoolerDevQueryPrintW = GetProcAddress(winspoolx.dll, "SpoolerDevQueryPrintW");
        winspoolx.SpoolerPrinterEvent = GetProcAddress(winspoolx.dll, "SpoolerPrinterEvent");
        winspoolx.StartDocDlgA = GetProcAddress(winspoolx.dll, "StartDocDlgA");
        winspoolx.StartDocDlgW = GetProcAddress(winspoolx.dll, "StartDocDlgW");
        winspoolx.StartDocPrinterA = GetProcAddress(winspoolx.dll, "StartDocPrinterA");
        winspoolx.StartDocPrinterW = GetProcAddress(winspoolx.dll, "StartDocPrinterW");
        winspoolx.StartPagePrinter = GetProcAddress(winspoolx.dll, "StartPagePrinter");
        winspoolx.UnRegisterForPrintAsyncNotifications = GetProcAddress(winspoolx.dll, "UnRegisterForPrintAsyncNotifications");
        winspoolx.UploadPrinterDriverPackageA = GetProcAddress(winspoolx.dll, "UploadPrinterDriverPackageA");
        winspoolx.UploadPrinterDriverPackageW = GetProcAddress(winspoolx.dll, "UploadPrinterDriverPackageW");
        winspoolx.WaitForPrinterChange = GetProcAddress(winspoolx.dll, "WaitForPrinterChange");
        winspoolx.WritePrinter = GetProcAddress(winspoolx.dll, "WritePrinter");
        winspoolx.XcvDataW = GetProcAddress(winspoolx.dll, "XcvDataW");

        break;

    case DLL_PROCESS_DETACH:
        FreeLibrary(winspoolx.dll);
        break;
    }
    return TRUE;
}