#include "build_identity.h"
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <bcrypt.h>
#include <array>
#include <algorithm>
#include <optional>
#include <vector>

namespace reo::native::sound_ram {
namespace {
using Digest=std::array<std::uint8_t,32>;
constexpr Digest original_digest{
    0x06,0xbd,0x5f,0xd7,0x24,0x31,0x44,0xcd,0x30,0xcd,0xd0,0xc0,0x02,0x37,0x63,0xa3,
    0x69,0x73,0x8c,0xb9,0x1b,0x17,0x7b,0x35,0xe8,0x5f,0x6a,0x47,0x82,0xb4,0xca,0x46};
struct File {
    HANDLE value{INVALID_HANDLE_VALUE};
    explicit File(const std::filesystem::path& path)
        :value(CreateFileW(path.c_str(),GENERIC_READ,FILE_SHARE_READ,nullptr,OPEN_EXISTING,
                           FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,nullptr)) {}
    ~File() { if(value!=INVALID_HANDLE_VALUE) CloseHandle(value); }
    File(const File&)=delete;File& operator=(const File&)=delete;
};
struct Algorithm {
    BCRYPT_ALG_HANDLE value{};
    ~Algorithm() { if(value) BCryptCloseAlgorithmProvider(value,0); }
};
struct Hash {
    BCRYPT_HASH_HANDLE value{};
    ~Hash() { if(value) BCryptDestroyHash(value); }
};
bool same_observed_file(const BY_HANDLE_FILE_INFORMATION& a,const BY_HANDLE_FILE_INFORMATION& b) noexcept {
    return a.dwVolumeSerialNumber==b.dwVolumeSerialNumber && a.nFileIndexHigh==b.nFileIndexHigh &&
        a.nFileIndexLow==b.nFileIndexLow && a.nFileSizeHigh==b.nFileSizeHigh &&
        a.nFileSizeLow==b.nFileSizeLow && a.ftLastWriteTime.dwHighDateTime==b.ftLastWriteTime.dwHighDateTime &&
        a.ftLastWriteTime.dwLowDateTime==b.ftLastWriteTime.dwLowDateTime;
}
std::optional<Digest> digest_file(const std::filesystem::path& path) {
    File file(path);
    if(file.value==INVALID_HANDLE_VALUE) return {};
    BY_HANDLE_FILE_INFORMATION before{},after{};
    if(!GetFileInformationByHandle(file.value,&before) || (before.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)) return {};
    Algorithm algorithm;
    if(BCryptOpenAlgorithmProvider(&algorithm.value,BCRYPT_SHA256_ALGORITHM,nullptr,0)<0) return {};
    DWORD object_bytes{},returned{};
    if(BCryptGetProperty(algorithm.value,BCRYPT_OBJECT_LENGTH,reinterpret_cast<PUCHAR>(&object_bytes),
                         sizeof(object_bytes),&returned,0)<0 || returned!=sizeof(object_bytes) ||
       !object_bytes || object_bytes>65536) return {};
    std::vector<std::uint8_t> object(object_bytes);
    Hash hash;
    if(BCryptCreateHash(algorithm.value,&hash.value,object.data(),object_bytes,nullptr,0,0)<0) return {};
    std::array<std::uint8_t,65536> buffer{};
    std::uint64_t total{};
    for(;;) {
        DWORD count{};
        if(!ReadFile(file.value,buffer.data(),DWORD(buffer.size()),&count,nullptr)) return {};
        if(!count) break;
        total+=count;
        if(BCryptHashData(hash.value,buffer.data(),count,0)<0) return {};
    }
    if(total!=((std::uint64_t(before.nFileSizeHigh)<<32)|before.nFileSizeLow) ||
       !GetFileInformationByHandle(file.value,&after) || !same_observed_file(before,after)) return {};
    Digest result{};
    if(BCryptFinishHash(hash.value,result.data(),ULONG(result.size()),0)<0) return {};
    return result;
}
}
IdentityResult observe_build_identity(const std::filesystem::path& original_elf) noexcept {
    try {
        const auto original=digest_file(original_elf);
        if(!original) return {};
        if(*original!=original_digest) return {IdentityStatus::wrong_original_executable,{}};
        std::array<wchar_t,32768> path{};
        const auto count=GetModuleFileNameW(nullptr,path.data(),DWORD(path.size()));
        if(!count || count>=path.size()) return {};
        const auto native=digest_file(std::filesystem::path(path.data()));
        if(!native) return {};
        bank_packets::v3::MemoryIdentity identity;
        identity.executable_sha256=*original;
        identity.native_build_sha256=*native;
        if(BCryptGenRandom(nullptr,identity.session.data(),ULONG(identity.session.size()),BCRYPT_USE_SYSTEM_PREFERRED_RNG)<0 ||
           std::all_of(identity.session.begin(),identity.session.end(),[](auto value){return value==0;})) return {};
        // Incarnation and RAM-size metadata are intentionally absent here. Only
        // actual RuntimeMemory preparation can bind these observations to RAM.
        return {IdentityStatus::observed_metadata,identity};
    } catch(...) { return {}; }
}
} // namespace reo::native::sound_ram
