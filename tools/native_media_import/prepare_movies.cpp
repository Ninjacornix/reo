// Import-time conversion only. The native player consumes the resulting MP4s;
// no source archive/sector/CRI protocol belongs to the playback implementation.
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <bcrypt.h>
#include <algorithm>
#include <array>
#include <atomic>
#include <chrono>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace fs=std::filesystem;
namespace {
constexpr const char* elf_hash="06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46";
constexpr const char* tool_hash="3256173f3f8bffd7df12227c68adf68025edb1832273a9530688a7bb1ed8edec";
constexpr const char* profile="file1-h264-cfr-crf18-v1";
struct Entry {const char* container;const char* name;std::uint64_t offset,bytes;const char* sha;unsigned frames,archive_index,member_index;};
constexpr Entry entries[]{
#include "file1_movies.inc"
};
std::atomic<bool> cancelled{};
BOOL WINAPI cancel(DWORD event){if(event==CTRL_C_EVENT||event==CTRL_BREAK_EVENT){cancelled.store(true);return TRUE;}return FALSE;}
void require(bool ok,const char* what){if(!ok)throw std::runtime_error(what);}
void system_check(bool ok,const char* what){if(!ok)throw std::runtime_error(std::string(what)+"; Win32="+std::to_string(GetLastError()));}
struct Handle {
    HANDLE value{INVALID_HANDLE_VALUE};
    Handle()=default;explicit Handle(HANDLE h):value(h){}~Handle(){if(value!=INVALID_HANDLE_VALUE&&value)CloseHandle(value);}
    Handle(const Handle&)=delete;Handle& operator=(const Handle&)=delete;
    Handle(Handle&& other)noexcept:value(std::exchange(other.value,INVALID_HANDLE_VALUE)){}
};
Handle read_file(const fs::path& path){Handle file(CreateFileW(path.c_str(),GENERIC_READ,FILE_SHARE_READ,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,nullptr));system_check(file.value!=INVALID_HANDLE_VALUE,"Open input file");return file;}
std::uint64_t length(const Handle& file){LARGE_INTEGER n{};system_check(GetFileSizeEx(file.value,&n)!=FALSE,"Read file size");require(n.QuadPart>=0,"Negative file size");return static_cast<std::uint64_t>(n.QuadPart);}
struct Hash {
    BCRYPT_ALG_HANDLE algorithm{};BCRYPT_HASH_HANDLE state{};std::vector<unsigned char> object;
    Hash(){try{require(BCryptOpenAlgorithmProvider(&algorithm,BCRYPT_SHA256_ALGORITHM,nullptr,0)>=0,"SHA256 provider");DWORD bytes{},copied{};
        require(BCryptGetProperty(algorithm,BCRYPT_OBJECT_LENGTH,reinterpret_cast<PUCHAR>(&bytes),sizeof(bytes),&copied,0)>=0,"SHA256 workspace");object.resize(bytes);
        require(BCryptCreateHash(algorithm,&state,object.data(),bytes,nullptr,0,0)>=0,"SHA256 creation");}catch(...){if(algorithm)BCryptCloseAlgorithmProvider(algorithm,0);throw;}}
    ~Hash(){if(state)BCryptDestroyHash(state);if(algorithm)BCryptCloseAlgorithmProvider(algorithm,0);}
    void add(unsigned char* bytes,DWORD n){require(BCryptHashData(state,bytes,n,0)>=0,"SHA256 input");}
    std::string finish(){std::array<unsigned char,32> digest{};require(BCryptFinishHash(state,digest.data(),static_cast<ULONG>(digest.size()),0)>=0,"SHA256 completion");std::ostringstream text;text<<std::hex<<std::setfill('0');for(auto byte:digest)text<<std::setw(2)<<unsigned(byte);return text.str();}
};
std::string read_range(const Handle& file,std::uint64_t at,std::uint64_t bytes,std::ostream* copy=nullptr) {
    const auto total=length(file);require(at<=total&&bytes<=total-at,"Movie extent outside imported archive");
    LARGE_INTEGER position{};position.QuadPart=static_cast<LONGLONG>(at);system_check(SetFilePointerEx(file.value,position,nullptr,FILE_BEGIN)!=FALSE,"Position input");
    Hash hash;std::array<unsigned char,65536> block;
    while(bytes){require(!cancelled.load(),"Movie preparation cancelled");DWORD got{},requested=static_cast<DWORD>(std::min<std::uint64_t>(bytes,block.size()));
        system_check(ReadFile(file.value,block.data(),requested,&got,nullptr)!=FALSE,"Read movie source");require(got==requested,"Truncated movie source");
        hash.add(block.data(),got);if(copy){copy->write(reinterpret_cast<const char*>(block.data()),got);require(bool(*copy),"Write staging movie");}bytes-=got;}
    return hash.finish();
}
std::string hash_file(const fs::path& path){auto file=read_file(path);return read_range(file,0,length(file));}
std::wstring quote(std::wstring_view value) {
    std::wstring out=L"\"";unsigned slashes{};
    for(wchar_t ch:value){if(ch==L'\\'){++slashes;continue;}if(ch==L'\"'){out.append(slashes*2+1,L'\\');out+=ch;}else{out.append(slashes,L'\\');out+=ch;}slashes=0;}
    out.append(slashes*2,L'\\');out+=L'\"';return out;
}
void convert(const fs::path& tool,const fs::path& source,const fs::path& output,const fs::path& progress,const fs::path& log) {
    std::vector<std::wstring> args{tool.native(),L"-hide_banner",L"-loglevel",L"error",L"-nostdin",L"-n",L"-threads",L"2",L"-i",source.native(),L"-map",L"0:v:0",L"-an",L"-sn",L"-dn",L"-map_metadata",L"-1",L"-vf",L"settb=expr=1/90000,setpts=N*3003",L"-c:v",L"libx264",L"-preset",L"veryfast",L"-crf",L"18",L"-pix_fmt",L"yuv420p",L"-threads",L"2",L"-enc_time_base",L"1:90000",L"-fps_mode",L"passthrough",L"-video_track_timescale",L"90000",L"-movflags",L"+faststart",L"-progress",progress.native(),L"-nostats",output.native()};
    std::wstring command;for(const auto& arg:args){if(!command.empty())command+=L' ';command+=quote(arg);}require(command.size()<32767,"Converter command too long");
    SECURITY_ATTRIBUTES inheritance{sizeof(inheritance),nullptr,TRUE};
    Handle logs(CreateFileW(log.c_str(),GENERIC_WRITE,FILE_SHARE_READ,&inheritance,CREATE_NEW,FILE_ATTRIBUTE_NORMAL,nullptr));system_check(logs.value!=INVALID_HANDLE_VALUE,"Create converter log");
    Handle input(CreateFileW(L"NUL",GENERIC_READ,FILE_SHARE_READ|FILE_SHARE_WRITE,&inheritance,OPEN_EXISTING,0,nullptr));system_check(input.value!=INVALID_HANDLE_VALUE,"Open converter input");
    STARTUPINFOW start{};start.cb=sizeof(start);start.dwFlags=STARTF_USESTDHANDLES;start.hStdInput=input.value;start.hStdOutput=start.hStdError=logs.value;
    PROCESS_INFORMATION process{};system_check(CreateProcessW(tool.c_str(),command.data(),nullptr,nullptr,TRUE,CREATE_NO_WINDOW|BELOW_NORMAL_PRIORITY_CLASS,nullptr,nullptr,&start,&process)!=FALSE,"Start owned converter");
    Handle child(process.hProcess),thread(process.hThread);const auto deadline=std::chrono::steady_clock::now()+std::chrono::minutes(10);
    for(;;){const auto wait=WaitForSingleObject(child.value,100);if(wait==WAIT_OBJECT_0)break;
        if(wait!=WAIT_TIMEOUT||cancelled.load()||std::chrono::steady_clock::now()>deadline){TerminateProcess(child.value,1);WaitForSingleObject(child.value,10000);throw std::runtime_error("Owned movie conversion cancelled, failed or timed out");}}
    DWORD code{};system_check(GetExitCodeProcess(child.value,&code)!=FALSE,"Read converter result");require(code==0,"Movie conversion failed; see private converter log");
}
std::string json(std::string_view input){std::string out="\"";for(unsigned char ch:input){require(ch>=32&&ch<127,"Catalogue key is not ASCII");if(ch=='\\'||ch=='\"')out+='\\';out+=static_cast<char>(ch);}return out+'\"';}
void publish(const fs::path& temporary,const fs::path& destination){system_check(MoveFileExW(temporary.c_str(),destination.c_str(),MOVEFILE_REPLACE_EXISTING|MOVEFILE_WRITE_THROUGH)!=FALSE,"Publish prepared movie asset");}
bool reusable(const fs::path& output,const fs::path& stamp) {
    if(!fs::is_regular_file(output)||!fs::is_regular_file(stamp)||fs::file_size(stamp)>256)return false;
    std::ifstream stream(stamp);std::string format,digest;std::getline(stream,format);std::getline(stream,digest);
    return stream&&format==profile&&digest.size()==64&&hash_file(output)==digest;
}
unsigned encoded_frames(const fs::path& path){std::ifstream stream(path);std::string line;unsigned frames{};bool complete=false;
    while(std::getline(stream,line)){if(!line.empty()&&line.back()=='\r')line.pop_back();if(line.rfind("frame=",0)==0)frames=static_cast<unsigned>(std::stoul(line.substr(6)));if(line=="progress=end")complete=true;}
    require(complete,"Converter did not report a completed stream");return frames;}
}
int wmain(int argc,wchar_t** argv)try {
    require(argc==4||argc==6,"Usage: reo-prepare-movies <import-data> <cached-ffmpeg> <movie-cache> [--only <source-sha256>]");
    const auto data=fs::canonical(argv[1]),tool=fs::canonical(argv[2]);const auto cache=fs::weakly_canonical(fs::absolute(argv[3]));
    std::string only;if(argc==6){require(std::wstring_view(argv[4])==L"--only","Unknown movie preparation option");for(wchar_t ch:std::wstring_view(argv[5])){require((ch>=L'0'&&ch<=L'9')||(ch>=L'a'&&ch<=L'f'),"Expected lowercase source hash");only+=static_cast<char>(ch);}require(only.size()==64,"Expected full source hash");}
    auto executable=read_file(tool);require(read_range(executable,0,length(executable))==tool_hash,"Cached converter does not match the launcher's pinned tool");
    auto elf=read_file(data/L"SLUS_207.65");require(read_range(elf,0,length(elf))==elf_hash,"Supported owned File1 import required");
    std::vector<const Entry*> selected;for(const auto& entry:entries)if(only.empty()||only==entry.sha)selected.push_back(&entry);require(!selected.empty(),"Movie key is absent from this import profile");
    const auto common=std::mismatch(data.begin(),data.end(),cache.begin(),cache.end(),[](const auto& a,const auto& b){return _wcsicmp(a.c_str(),b.c_str())==0;});
    require(common.first!=data.end(),"Keep native movie cache outside imported data");
    fs::create_directories(cache);Handle lease(CreateFileW((cache/L"prepare.lock").c_str(),GENERIC_READ|GENERIC_WRITE,0,nullptr,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,nullptr));system_check(lease.value!=INVALID_HANDLE_VALUE,"Acquire movie preparation lease");
    SetConsoleCtrlHandler(cancel,TRUE);std::map<std::string,Handle> archives;std::vector<std::string> prepared;unsigned converted{},reused{};
    const auto prefix=std::string(".prepare-")+std::to_string(GetCurrentProcessId())+"-"+std::to_string(GetTickCount64());
    for(const auto* item:selected){const auto& e=*item;require(!cancelled.load(),"Movie preparation cancelled");
        auto found=archives.find(e.container);if(found==archives.end())found=archives.emplace(e.container,read_file(data/e.container)).first;
        const auto output=cache/(std::string(e.sha)+".mp4"),stamp=cache/(std::string(e.sha)+".stamp");
        const bool was_cached=reusable(output,stamp);
        if(was_cached) {
            require(read_range(found->second,e.offset,e.bytes)==e.sha,"Imported movie differs from recorded revision");++reused;
        }else {
            ULARGE_INTEGER free{};system_check(GetDiskFreeSpaceExW(cache.c_str(),&free,nullptr,nullptr)!=FALSE,"Check movie cache space");require(free.QuadPart>e.bytes*2+512ull*1024*1024,"Insufficient space for bounded movie preparation");
            const auto stem=prefix+"-"+std::to_string(converted);const auto source=cache/(stem+".sfd"),video=cache/(stem+".mp4"),progress=cache/(stem+".progress"),log=cache/(stem+".log"),receipt=cache/(stem+".stamp");
            require(!fs::exists(source)&&!fs::exists(video)&&!fs::exists(progress)&&!fs::exists(log)&&!fs::exists(receipt),"Fresh movie staging paths required");
            {std::ofstream copy(source,std::ios::binary);require(bool(copy),"Create source staging file");require(read_range(found->second,e.offset,e.bytes,&copy)==e.sha,"Imported movie hash mismatch");}
            convert(tool,source,video,progress,log);require(encoded_frames(progress)==e.frames,"Converted picture count differs from the owned source");
            const auto digest=hash_file(video);{std::ofstream file(receipt);file<<profile<<'\n'<<digest<<'\n';require(bool(file),"Write native movie cache receipt");}
            publish(video,output);publish(receipt,stamp);
            // Only the exact per-invocation temporary source is deleted. Never
            // enumerate/delete an imported directory or original archive.
            require(fs::remove(source),"Remove temporary extracted movie");++converted;
        }
        const auto native_hash=hash_file(output);std::ostringstream row;
        row<<"{\"source_key\":"<<json(e.sha)<<",\"source_name\":"<<json(e.name)<<",\"file\":"<<json(std::string(e.sha)+".mp4")<<",\"sha256\":"<<json(native_hash)<<",\"bytes\":"<<fs::file_size(output)<<",\"frames\":"<<e.frames<<",\"archive_index\":"<<e.archive_index<<",\"member_index\":"<<e.member_index<<'}';prepared.push_back(row.str());
        std::printf("Prepared %zu/%zu: %s (%s)\n",prepared.size(),selected.size(),e.name,was_cached?"cached":"converted");std::fflush(stdout);
    }
    const auto staging=cache/(prefix+"-index.json");require(!fs::exists(staging),"Fresh native catalogue receipt required");
    {std::ofstream index(staging);index<<"{\"format\":1,\"game\":\"file1\",\"profile\":"<<json(profile)<<",\"source_elf_sha256\":"<<json(elf_hash)<<",\"complete_catalogue\":"<<(only.empty()?"true":"false")<<",\"prepared\":"<<prepared.size()<<",\"movies\":[";
        for(std::size_t i=0;i<prepared.size();++i){if(i)index<<',';index<<prepared[i];}index<<"]}\n";require(bool(index),"Write native movie catalogue");}
    publish(staging,cache/L"movies.json");
    std::printf("{\"status\":\"native movie cache prepared\",\"prepared\":%zu,\"converted\":%u,\"reused\":%u,\"complete_catalogue\":%s}\n",prepared.size(),converted,reused,only.empty()?"true":"false");return 0;
}catch(const std::exception& error){std::fprintf(stderr,"Movie preparation failed: %s\n",error.what());return 1;}
