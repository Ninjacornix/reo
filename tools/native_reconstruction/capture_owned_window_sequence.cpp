#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <d3d11.h>
#include <dxgi.h>
#include <windows.graphics.capture.interop.h>
#include <windows.graphics.directx.direct3d11.interop.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Graphics.Capture.h>
#include <winrt/Windows.Graphics.DirectX.h>
#include <winrt/Windows.Graphics.DirectX.Direct3D11.h>
#include <chrono>
#include <cstdint>
#include <cstring>
#include <cstddef>
#include <cstdio>
#include <filesystem>
#include <stdexcept>
#include <string>
#include <thread>
#include <vector>
namespace cap=winrt::Windows::Graphics::Capture;
namespace direct=winrt::Windows::Graphics::DirectX;
struct Handle {HANDLE value{};~Handle(){if(value&&value!=INVALID_HANDLE_VALUE)CloseHandle(value);}};
void require(bool v,const char* message){if(!v)throw std::runtime_error(message);}
std::uint64_t stamp(FILETIME t){return (std::uint64_t(t.dwHighDateTime)<<32)|t.dwLowDateTime;}
void identify(HANDLE process,std::uint64_t creation,const std::filesystem::path& image){
 FILETIME born{},exit{},kernel{},user{};require(GetProcessTimes(process,&born,&exit,&kernel,&user)&&stamp(born)==creation,"Process creation identity mismatch");
 std::vector<wchar_t> name(32768);DWORD count=static_cast<DWORD>(name.size());require(QueryFullProcessImageNameW(process,0,name.data(),&count),"Process image query failed");
 const auto actual=std::filesystem::weakly_canonical(std::wstring(name.data(),count));require(_wcsicmp(actual.c_str(),std::filesystem::weakly_canonical(image).c_str())==0,"Canonical process image mismatch");
 require(WaitForSingleObject(process,0)==WAIT_TIMEOUT,"Owned process already exited");
}
bool same_user(HANDLE process){
 Handle theirs,ours;require(OpenProcessToken(process,TOKEN_QUERY,&theirs.value)&&OpenProcessToken(GetCurrentProcess(),TOKEN_QUERY,&ours.value),"Process user query failed");
 auto sid=[](HANDLE token){DWORD size{};GetTokenInformation(token,TokenUser,nullptr,0,&size);require(size>0&&size<65536,"Token user size");std::vector<std::byte> bytes(size);require(GetTokenInformation(token,TokenUser,bytes.data(),size,&size),"Token user read");return bytes;};
 const auto a=sid(theirs.value),b=sid(ours.value);return EqualSid(reinterpret_cast<const TOKEN_USER*>(a.data())->User.Sid,reinterpret_cast<const TOKEN_USER*>(b.data())->User.Sid)!=FALSE;
}
struct WindowSelection {DWORD pid{};HWND window{};std::uint64_t area{};};
BOOL CALLBACK visit(HWND window,LPARAM opaque){auto& result=*reinterpret_cast<WindowSelection*>(opaque);DWORD pid{};GetWindowThreadProcessId(window,&pid);RECT r{};
 if(pid==result.pid&&IsWindowVisible(window)&&GetClientRect(window,&r)&&r.right>r.left&&r.bottom>r.top){const auto area=std::uint64_t(r.right-r.left)*std::uint64_t(r.bottom-r.top);if(area>result.area){result.window=window;result.area=area;}}return TRUE;}
void write(HANDLE file,const void* data,DWORD bytes){DWORD done{};require(WriteFile(file,data,bytes,&done,nullptr)&&done==bytes,"Capture write failed");}
int wmain(int argc,wchar_t** argv)try{
 require(argc==6,"pid creation-filetime canonical-executable fresh-folder seconds required");const auto numeric=std::stoull(argv[1]);require(numeric>0&&numeric<=MAXDWORD,"PID bound");const auto pid=static_cast<DWORD>(numeric);const auto creation=std::stoull(argv[2]);const std::filesystem::path image(argv[3]),output(argv[4]);
 const auto seconds=std::stoi(argv[5]);require(seconds>=1&&seconds<=540,"Duration bound");require(!std::filesystem::exists(output),"Fresh capture output required");std::filesystem::create_directory(output);Handle process{OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION|SYNCHRONIZE,FALSE,pid)};require(process.value,"Owned process query failed");identify(process.value,creation,image);require(same_user(process.value),"Foreign user capture refused");
 WindowSelection selected{pid};EnumWindows(visit,reinterpret_cast<LPARAM>(&selected));require(selected.window&&!IsIconic(selected.window),"Visible non-minimized owned window required");const auto foreground_before=GetForegroundWindow();
 winrt::init_apartment(winrt::apartment_type::multi_threaded);require(cap::GraphicsCaptureSession::IsSupported(),"Windows window capture unavailable");
 winrt::com_ptr<ID3D11Device> device;winrt::com_ptr<ID3D11DeviceContext> context;D3D_FEATURE_LEVEL level{};winrt::check_hresult(D3D11CreateDevice(nullptr,D3D_DRIVER_TYPE_HARDWARE,nullptr,D3D11_CREATE_DEVICE_BGRA_SUPPORT,nullptr,0,D3D11_SDK_VERSION,device.put(),&level,context.put()));
 auto dxgi=device.as<IDXGIDevice>();winrt::com_ptr<IInspectable> inspectable;winrt::check_hresult(CreateDirect3D11DeviceFromDXGIDevice(dxgi.get(),inspectable.put()));auto native=inspectable.as<winrt::Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice>();
 const auto factory=winrt::get_activation_factory<cap::GraphicsCaptureItem,IGraphicsCaptureItemInterop>();cap::GraphicsCaptureItem item{nullptr};winrt::check_hresult(factory->CreateForWindow(selected.window,winrt::guid_of<cap::GraphicsCaptureItem>(),winrt::put_abi(item)));
 const auto size=item.Size();require(size.Width>0&&size.Height>0&&std::uint64_t(size.Width)*size.Height*4<=64*1024*1024,"Capture dimensions outside bound");
 auto pool=cap::Direct3D11CaptureFramePool::CreateFreeThreaded(native,direct::DirectXPixelFormat::B8G8R8A8UIntNormalized,2,size);auto session=pool.CreateCaptureSession(item);session.StartCapture();

 Handle raw{CreateFileW((output/L"gray.bin").c_str(),GENERIC_WRITE,0,nullptr,CREATE_NEW,FILE_ATTRIBUTE_NORMAL,nullptr)};
 Handle csv{CreateFileW((output/L"frames.csv").c_str(),GENERIC_WRITE,0,nullptr,CREATE_NEW,FILE_ATTRIBUTE_NORMAL,nullptr)};
 require(raw.value!=INVALID_HANDLE_VALUE&&csv.value!=INVALID_HANDLE_VALUE,"Fresh output files unavailable");
 const char* heading="index,system_100ns,observed_qpc_100ns,width,height,foreground,iconic\n";write(csv.value,heading,static_cast<DWORD>(std::strlen(heading)));
 LARGE_INTEGER frequency{};require(QueryPerformanceFrequency(&frequency)&&frequency.QuadPart>0,"QPC unavailable");
 const auto start=std::chrono::steady_clock::now(),deadline=start+std::chrono::seconds(seconds);
 std::int64_t previous=-1;unsigned count=0,foreground=0;winrt::com_ptr<ID3D11Texture2D> staging;UINT oldWidth=0,oldHeight=0;
 while(std::chrono::steady_clock::now()<deadline&&WaitForSingleObject(process.value,0)==WAIT_TIMEOUT){
  auto frame=pool.TryGetNextFrame();if(!frame){std::this_thread::sleep_for(std::chrono::milliseconds(3));continue;}
  const auto stamp100=frame.SystemRelativeTime().count();
  if(previous>=0&&stamp100-previous<480000){frame.Close();continue;}
  const auto actual=frame.ContentSize();require(actual.Width==size.Width&&actual.Height==size.Height,"Capture resize requires a new bounded run");
  auto access=frame.Surface().as<::Windows::Graphics::DirectX::Direct3D11::IDirect3DDxgiInterfaceAccess>();winrt::com_ptr<ID3D11Texture2D> texture;winrt::check_hresult(access->GetInterface(__uuidof(ID3D11Texture2D),texture.put_void()));
  D3D11_TEXTURE2D_DESC desc{};texture->GetDesc(&desc);require(desc.Format==DXGI_FORMAT_B8G8R8A8_UNORM&&desc.Width>=static_cast<UINT>(actual.Width)&&desc.Height>=static_cast<UINT>(actual.Height)&&std::uint64_t(desc.Width)*desc.Height*4<=64*1024*1024,"Capture surface profile");
  if(desc.Width!=oldWidth||desc.Height!=oldHeight){desc.Usage=D3D11_USAGE_STAGING;desc.BindFlags=0;desc.CPUAccessFlags=D3D11_CPU_ACCESS_READ;desc.MiscFlags=0;staging=nullptr;winrt::check_hresult(device->CreateTexture2D(&desc,nullptr,staging.put()));oldWidth=desc.Width;oldHeight=desc.Height;}
  context->CopyResource(staging.get(),texture.get());D3D11_MAPPED_SUBRESOURCE mapped{};winrt::check_hresult(context->Map(staging.get(),0,D3D11_MAP_READ,0,&mapped));
  std::uint8_t gray[128*96]{};
  for(unsigned y=0;y<96;++y)for(unsigned x=0;x<128;++x){const auto sy=(std::uint64_t(y)*static_cast<unsigned>(actual.Height)+static_cast<unsigned>(actual.Height)/2)/96;const auto sx=(std::uint64_t(x)*static_cast<unsigned>(actual.Width)+static_cast<unsigned>(actual.Width)/2)/128;const auto* pixel=static_cast<const std::uint8_t*>(mapped.pData)+sy*mapped.RowPitch+sx*4;gray[y*128+x]=static_cast<std::uint8_t>((unsigned(pixel[0])*29+unsigned(pixel[1])*150+unsigned(pixel[2])*77+128)>>8);}
  if(count==0){
   std::vector<std::byte> pixels(std::size_t(actual.Width)*actual.Height*4);for(int y=0;y<actual.Height;++y)std::memcpy(pixels.data()+std::size_t(y)*actual.Width*4,static_cast<const std::byte*>(mapped.pData)+std::size_t(y)*mapped.RowPitch,std::size_t(actual.Width)*4);
   BITMAPFILEHEADER header{};header.bfType=0x4d42;header.bfOffBits=sizeof(header)+sizeof(BITMAPINFOHEADER);header.bfSize=header.bfOffBits+static_cast<DWORD>(pixels.size());BITMAPINFOHEADER info{};info.biSize=sizeof(info);info.biWidth=actual.Width;info.biHeight=-actual.Height;info.biPlanes=1;info.biBitCount=32;info.biCompression=BI_RGB;info.biSizeImage=static_cast<DWORD>(pixels.size());
   Handle bmp{CreateFileW((output/L"first.bmp").c_str(),GENERIC_WRITE,0,nullptr,CREATE_NEW,FILE_ATTRIBUTE_NORMAL,nullptr)};require(bmp.value!=INVALID_HANDLE_VALUE,"First image create failed");write(bmp.value,&header,sizeof(header));write(bmp.value,&info,sizeof(info));write(bmp.value,pixels.data(),static_cast<DWORD>(pixels.size()));
  }
  context->Unmap(staging.get(),0);frame.Close();LARGE_INTEGER qpc{};QueryPerformanceCounter(&qpc);const auto observed=static_cast<std::int64_t>(static_cast<long double>(qpc.QuadPart)*10000000/frequency.QuadPart);
  DWORD owner{};GetWindowThreadProcessId(selected.window,&owner);require(owner==pid,"Window owner changed");const bool fg=GetForegroundWindow()==selected.window;foreground+=fg?1u:0u;
  char line[256]{};const int bytes=std::snprintf(line,sizeof(line),"%u,%lld,%lld,%d,%d,%u,%u\n",count,stamp100,observed,actual.Width,actual.Height,fg?1u:0u,IsIconic(selected.window)?1u:0u);require(bytes>0&&bytes<static_cast<int>(sizeof(line)),"CSV row bound");write(raw.value,gray,sizeof(gray));write(csv.value,line,static_cast<DWORD>(bytes));++count;previous=stamp100;
 }
 session.Close();pool.Close();require(FlushFileBuffers(raw.value)&&FlushFileBuffers(csv.value),"Capture flush failed");require(count>0,"No frames captured");
 std::printf("{\"pid\":%lu,\"creation_filetime\":%llu,\"frames\":%u,\"gray_width\":128,\"gray_height\":96,\"foreground_samples\":%u,\"desktop_read\":false,\"focus_requested\":false,\"foreground_unchanged\":%s}\n",static_cast<unsigned long>(pid),creation,count,foreground,GetForegroundWindow()==foreground_before?"true":"false");return 0;
}catch(const winrt::hresult_error& error){std::fprintf(stderr,"Window capture HRESULT=%08lx\n",static_cast<unsigned long>(error.code().value));return 1;}catch(const std::exception& error){std::fprintf(stderr,"Window capture: %s\n",error.what());return 1;}
