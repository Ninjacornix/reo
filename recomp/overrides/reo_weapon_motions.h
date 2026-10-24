#pragma once

namespace reo::mods {
// Fill only the weapon-motion holes before the native loader converts and
// registers these clips, preserving animation events and resource lifetimes.
inline bool readGlobalWeaponMotions(uint8_t* ram, R5900Context* ctx,
                                    const std::string& path, uint32_t destination,
                                    const char* catalogue) {
    const auto name=path.substr(path.find_last_of("/\\")+1);
    if(std::getenv("REO_TEST_WEAPON_MOTIONS") && path.find("PC_")!=std::string::npos)
        std::fprintf(stderr,"[TEST-WEAPON-MOTIONS] read=%s destination=%08x\n",path.c_str(),destination);
    if(name.size()==10 && name.starts_with("PC_") && name.ends_with(".BIN") && name.substr(3,3)!="000") {
        const auto folder=std::filesystem::path(std::u8string(reinterpret_cast<const char8_t*>(catalogue))).parent_path()/"global-motions";
        std::ifstream input(folder/name,std::ios::binary|std::ios::ate);
        if(input) {
            const auto length=std::streamoff(input.tellg());
            if(length<328 || length>3*1024*1024 || destination<0x100000 ||
               uint64_t(destination)+uint64_t(length)>PS2_RAM_SIZE)
                throw std::runtime_error("Global weapon motions exceed the native read buffer");
            input.seekg(0);
            if(!input.read(reinterpret_cast<char*>(ram+destination),length))
                throw std::runtime_error("Cannot read global weapon motions");
            std::fprintf(stderr,"[MOD-WEAPON-MOTIONS-1] file=%s destination=%08x bytes=%lld\n",name.c_str(),destination,static_cast<long long>(length));
            SET_GPR_U32(ctx,2,uint32_t(length));ctx->pc=GPR_U32(ctx,31);return true;
        }
    }
    return false;
}
}
