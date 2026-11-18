#include "build_identity.h"
#include <cstdio>
#include <string>
#include <string_view>
int main(int argc,char** argv) {
    if(argc!=2) return 2;
    const std::string_view argument(argv[1]);
    const auto value=reo::native::sound_ram::observe_build_identity(
        std::filesystem::path(std::u8string(argument.begin(),argument.end())));
    std::printf("{\"status\":%u,\"session\":\"",unsigned(value.status));
    for(const auto byte:value.identity.session) std::printf("%02x",unsigned(byte));
    std::printf("\",\"original\":\"");
    for(const auto byte:value.identity.executable_sha256) std::printf("%02x",unsigned(byte));
    std::printf("\",\"native\":\"");
    for(const auto byte:value.identity.native_build_sha256) std::printf("%02x",unsigned(byte));
    std::printf("\",\"runtime_incarnation\":%llu,\"ram_incarnation\":%llu,\"ram_bytes\":%llu}\n",
        static_cast<unsigned long long>(value.identity.runtime_incarnation),
        static_cast<unsigned long long>(value.identity.ram_incarnation),
        static_cast<unsigned long long>(value.identity.ram_bytes));
}
