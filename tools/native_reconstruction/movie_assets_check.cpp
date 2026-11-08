#include "game/native/movie_assets/catalogue.hpp"
#include "game/native/host_movie/player.hpp"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <d3d11.h>
#include <chrono>
#include <cstdio>
#include <fstream>
#include <set>
#include <stdexcept>
#include <thread>

namespace fs=std::filesystem;
namespace assets=reo::native::movie_assets;
namespace movie=reo::native::host_movie;
namespace {
void check(bool value,const char* what){if(!value)throw std::runtime_error(what);}
template<class F>void refused(F&& fn){bool failed=false;try{fn();}catch(const std::runtime_error&){failed=true;}check(failed,"Invalid native cache was accepted");}
template<class T>struct Com {T* p{};~Com(){if(p)p->Release();}T** out(){return &p;}T* operator->()const{return p;}};
bool writable(const fs::path& path){const auto h=CreateFileW(path.c_str(),GENERIC_WRITE,FILE_SHARE_READ,nullptr,OPEN_EXISTING,0,nullptr);if(h==INVALID_HANDLE_VALUE){check(GetLastError()==ERROR_SHARING_VIOLATION,"Unexpected file write refusal");return false;}CloseHandle(h);return true;}
}
int wmain(int argc,wchar_t** argv)try {
    check(argc==4,"Complete cache, partial cache and fresh private work directory required");
    const fs::path complete=argv[1],partial=argv[2],work=argv[3];check(!fs::exists(work),"Fresh cache test directory required");fs::create_directory(work);
    auto all=assets::Catalogue::open(complete);check(all->entries().size()==201,"Complete movie catalogue size");
    std::set<std::string> keys;std::uint64_t frames{};for(const auto& row:all->entries()){keys.insert(row.asset->key());frames+=row.asset->frames();check(all->find_label(row.label)==row.asset,"Catalogue label mismatch");}
    check(keys.size()==200&&frames==216998,"Native asset deduplication or picture totals");
    constexpr auto key="f003fe27fc6c402e9e2142a3786828a492bcb26c4b933b8f1a2a944a6d1e94bb";
    auto expected=all->find(key);check(expected&&expected->frames()==195,"Expected converted native movie");check(!all->find("missing")&&!all->find_label("../outside"),"Foreign cache lookup");
    refused([&]{(void)assets::Catalogue::open(partial);});
    const auto owned=assets::Catalogue::open(partial,false);check(owned->entries().size()==1,"Explicit partial cache profile");
    const auto root=work/L"copied cache #1";fs::create_directory(root);fs::copy_file(partial/L"movies.json",root/L"movies.json");
    const auto original=owned->find(key);check(bool(original),"Partial asset key");const auto copy=root/original->path().filename();fs::copy_file(original->path(),copy);
    auto copied=assets::Catalogue::open(root,false);auto lease=copied->find(key);check(lease&&!writable(copy),"Real read-only movie lease");
    copied.reset();check(!writable(copy),"Asset lost file lease when its catalogue closed");
    Com<ID3D11Device> device;Com<ID3D11DeviceContext> context;
    check(SUCCEEDED(D3D11CreateDevice(nullptr,D3D_DRIVER_TYPE_HARDWARE,nullptr,D3D11_CREATE_DEVICE_BGRA_SUPPORT|D3D11_CREATE_DEVICE_VIDEO_SUPPORT,nullptr,0,D3D11_SDK_VERSION,device.out(),nullptr,context.out())),"Native movie GPU");
    movie::Player player(device.p);const auto generation=player.open(lease->path(),{false,true,0});player.play(generation);
    const auto deadline=std::chrono::steady_clock::now()+std::chrono::seconds(8);
    for(;;){const auto status=player.snapshot();check(status.state!=movie::State::error,"Pinned asset native player error");if(status.state==movie::State::playing)break;check(std::chrono::steady_clock::now()<deadline,"Pinned asset readiness deadline");std::this_thread::sleep_for(std::chrono::milliseconds(1));}
    D3D11_TEXTURE2D_DESC texture{};texture.Width=512;texture.Height=384;texture.ArraySize=texture.MipLevels=texture.SampleDesc.Count=1;texture.Format=DXGI_FORMAT_B8G8R8A8_UNORM;texture.BindFlags=D3D11_BIND_RENDER_TARGET;Com<ID3D11Texture2D> target;
    check(SUCCEEDED(device->CreateTexture2D(&texture,nullptr,target.out())),"Pinned asset render texture");
    while(!player.transfer(generation,target.p).updated){check(std::chrono::steady_clock::now()<deadline,"Pinned asset frame deadline");std::this_thread::sleep_for(std::chrono::milliseconds(1));}
    player.close();context->Flush();lease.reset();check(writable(copy),"Native asset retained its own lease after release");
    {std::fstream file(copy,std::ios::in|std::ios::out|std::ios::binary);file.put('x');}
    refused([&]{(void)assets::Catalogue::open(root,false);});
    std::puts("{\"status\":\"native movie asset preflight and player handoff passed\",\"catalogue_entries\":201,\"physical_assets\":200,\"source_pictures\":216998,\"actual_read_only_lease\":true,\"retained_after_catalogue_close\":true,\"actual_native_texture_transfer\":true,\"corrupt_cache_refused\":true,\"partial_cache_requires_explicit_profile\":true,\"game_run\":false}");return 0;
}catch(const std::exception& error){std::fprintf(stderr,"%s\n",error.what());return 1;}
