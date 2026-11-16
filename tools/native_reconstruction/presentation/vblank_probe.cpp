#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <dxgi.h>
#include <dwmapi.h>
#include <cstdio>

int main(){
    HWND window=CreateWindowExA(0,"STATIC","native vblank probe",0,0,0,16,16,nullptr,nullptr,GetModuleHandleA(nullptr),nullptr);
    if(!window){std::puts("window unavailable");return 1;}
    DWM_TIMING_INFO before{};before.cbSize=sizeof(before);const HRESULT timing=DwmGetCompositionTimingInfo(nullptr,&before);
    if(FAILED(timing)){std::printf("DWM timing unavailable: %08lx\n",static_cast<unsigned long>(timing));DestroyWindow(window);return 2;}
    IDXGIFactory* factory=nullptr;HRESULT hr=CreateDXGIFactory(__uuidof(IDXGIFactory),reinterpret_cast<void**>(&factory));
    if(FAILED(hr)){std::printf("DXGI factory unavailable: %08lx\n",static_cast<unsigned long>(hr));DestroyWindow(window);return 3;}
    const auto monitor=MonitorFromWindow(window,MONITOR_DEFAULTTONEAREST);IDXGIOutput* selected=nullptr;
    for(UINT a=0;!selected;++a){IDXGIAdapter* adapter=nullptr;if(factory->EnumAdapters(a,&adapter)==DXGI_ERROR_NOT_FOUND)break;if(!adapter)break;
        for(UINT o=0;;++o){IDXGIOutput* output=nullptr;if(adapter->EnumOutputs(o,&output)==DXGI_ERROR_NOT_FOUND)break;if(!output)break;
            DXGI_OUTPUT_DESC desc{};if(SUCCEEDED(output->GetDesc(&desc))&&desc.Monitor==monitor&&desc.AttachedToDesktop){selected=output;break;}output->Release();}
        adapter->Release();}
    if(!selected){std::puts("window output unavailable");factory->Release();DestroyWindow(window);return 4;}
    LARGE_INTEGER frequency{},start{},finish{};QueryPerformanceFrequency(&frequency);QueryPerformanceCounter(&start);
    for(unsigned i=0;i<10;++i){hr=selected->WaitForVBlank();if(FAILED(hr))break;DWM_TIMING_INFO current{};current.cbSize=sizeof(current);DwmGetCompositionTimingInfo(nullptr,&current);std::printf("sample%u=%llu ",i,static_cast<unsigned long long>(current.cRefresh));}
    QueryPerformanceCounter(&finish);std::printf("elapsed_ms=%.3f ",double(finish.QuadPart-start.QuadPart)*1000/double(frequency.QuadPart));
    DWM_TIMING_INFO after{};after.cbSize=sizeof(after);const HRESULT sample=DwmGetCompositionTimingInfo(nullptr,&after);
    for(unsigned i=0;i<5;++i){DWM_TIMING_INFO current{};current.cbSize=sizeof(current);DwmGetCompositionTimingInfo(nullptr,&current);std::printf("immediate%u=%llu ",i,static_cast<unsigned long long>(current.cRefresh));}
    std::printf("wait=%08lx timing=%08lx refresh=%u/%u before=%llu after=%llu\n",static_cast<unsigned long>(hr),static_cast<unsigned long>(sample),after.rateRefresh.uiNumerator,after.rateRefresh.uiDenominator,static_cast<unsigned long long>(before.cRefresh),static_cast<unsigned long long>(after.cRefresh));
    selected->Release();factory->Release();DestroyWindow(window);return FAILED(hr)||FAILED(sample)||after.cRefresh<=before.cRefresh?5:0;
}
