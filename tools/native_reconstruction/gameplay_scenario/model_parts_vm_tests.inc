#include "game/native/gameplay_world/model_parts.hpp"

namespace {
std::size_t model_part_queries{},model_part_refusals{};

void model_parts_tests() {
    std::vector<std::uint8_t> ram(0x900000);
    for (unsigned trial = 0; trial < 4096; ++trial) {
        assertion_context = "Model part query trial="+std::to_string(trial);
        const auto count = trial%9;
        std::vector<std::byte> bytes(12);
        const auto write = [&](unsigned at,std::uint32_t value) {
            std::memcpy(bytes.data()+at,&value,sizeof(value));
        };
        write(0,trial*1664525u);write(4,count);write(8,trial*1013904223u);
        for (unsigned index = 0; index < count; ++index) {
            const auto at = unsigned(bytes.size()),size = 12u+4u*((trial+index)%5);
            bytes.resize(at+size);
            write(at,std::array<std::uint32_t,6>{0,1,2,0x10002,0xffffffffu,2}[(trial+index)%6]);
            write(at+4,trial*65521u+index*17u);
            write(at+8,size);
        }
        const auto before = bytes;
        std::memcpy(ram.data()+0x90000,bytes.data(),bytes.size());
        const auto expected = invoke_npc_original(ram,sub_001A31B0_0x1a31b0,{0x90000,0,0,0});
        check(reo::native::gameplay_world::model_part_count(bytes) == expected);
        check(bytes == before && std::memcmp(ram.data()+0x90000,bytes.data(),bytes.size()) == 0);
        ++model_part_queries;
    }
    // The original query stops at the first matching header. Its unconsumed
    // size, root length and following records impose no extra precondition.
    for (const auto declared : {UINT32_MAX,0x80000000u,0x7fffffffu,1u}) {
        assertion_context = "Model part prefix count="+std::to_string(declared);
        const bool negative = (declared&0x80000000u) != 0;
        std::vector<std::byte> prefix(negative ? 16 : 20);
        const auto write_prefix = [&](unsigned at,std::uint32_t value) { std::memcpy(prefix.data()+at,&value,sizeof(value)); };
        write_prefix(4,declared);write_prefix(12,2);
        if (!negative) write_prefix(16,0x80010001u);
        std::memcpy(ram.data()+0x90000,prefix.data(),prefix.size());
        const auto expected = negative ? 0u : 0x80010001u;
        check(invoke_npc_original(ram,sub_001A31B0_0x1a31b0,{0x90000,0,0,0}) == expected);
        check(reo::native::gameplay_world::model_part_count(prefix) == expected);
        ++model_part_queries;
    }
    for (unsigned refusal = 0; refusal < 7; ++refusal) {
        std::vector<std::byte> bytes(refusal == 0 ? 7 : refusal == 1 ? 12 : refusal == 2 ? 16 : 24);
        const auto write = [&](unsigned at,std::uint32_t value) { std::memcpy(bytes.data()+at,&value,sizeof(value)); };
        if (refusal > 0) write(4,refusal == 6 ? 2 : 1);
        if (refusal == 2) write(12,2);
        if (refusal >= 3) { write(12,1);write(20,std::array<std::uint32_t,4>{0,8,UINT32_MAX,12}[refusal-3]); }
        bool caught = false;
        try { (void)reo::native::gameplay_world::model_part_count(bytes); }
        catch (const std::invalid_argument&) { caught = true; }
        check(caught);
        ++model_part_refusals;
    }
}
}
