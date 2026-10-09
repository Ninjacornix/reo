#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001840E0
// Address: 0x1840e0 - 0x184360
void sub_001840E0_0x1840e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001840E0_0x1840e0");
#endif

    switch (ctx->pc) {
        case 0x184138u: goto label_184138;
        case 0x184144u: goto label_184144;
        case 0x184154u: goto label_184154;
        case 0x184174u: goto label_184174;
        case 0x18417cu: goto label_18417c;
        case 0x184188u: goto label_184188;
        case 0x1841a0u: goto label_1841a0;
        case 0x1841c8u: goto label_1841c8;
        case 0x18422cu: goto label_18422c;
        case 0x1842acu: goto label_1842ac;
        case 0x1842e4u: goto label_1842e4;
        case 0x184310u: goto label_184310;
        default: break;
    }

    ctx->pc = 0x1840e0u;

    // 0x1840e0: 0x27bdfba0  addiu       $sp, $sp, -0x460
    ctx->pc = 0x1840e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966176));
    // 0x1840e4: 0xffb20420  sd          $s2, 0x420($sp)
    ctx->pc = 0x1840e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1056), GPR_U64(ctx, 18));
    // 0x1840e8: 0x120902d  daddu       $s2, $t1, $zero
    ctx->pc = 0x1840e8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1840ec: 0xffb30428  sd          $s3, 0x428($sp)
    ctx->pc = 0x1840ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1064), GPR_U64(ctx, 19));
    // 0x1840f0: 0x100982d  daddu       $s3, $t0, $zero
    ctx->pc = 0x1840f0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1840f4: 0xffb40430  sd          $s4, 0x430($sp)
    ctx->pc = 0x1840f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1072), GPR_U64(ctx, 20));
    // 0x1840f8: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x1840f8u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1840fc: 0xffb50438  sd          $s5, 0x438($sp)
    ctx->pc = 0x1840fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1080), GPR_U64(ctx, 21));
    // 0x184100: 0x80a82d  daddu       $s5, $a0, $zero
    ctx->pc = 0x184100u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184104: 0xffb60440  sd          $s6, 0x440($sp)
    ctx->pc = 0x184104u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1088), GPR_U64(ctx, 22));
    // 0x184108: 0xe0b02d  daddu       $s6, $a3, $zero
    ctx->pc = 0x184108u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18410c: 0xffb70448  sd          $s7, 0x448($sp)
    ctx->pc = 0x18410cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1096), GPR_U64(ctx, 23));
    // 0x184110: 0x24170001  addiu       $s7, $zero, 0x1
    ctx->pc = 0x184110u;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x184114: 0xffbe0450  sd          $fp, 0x450($sp)
    ctx->pc = 0x184114u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1104), GPR_U64(ctx, 30));
    // 0x184118: 0xa0f02d  daddu       $fp, $a1, $zero
    ctx->pc = 0x184118u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18411c: 0xffb00410  sd          $s0, 0x410($sp)
    ctx->pc = 0x18411cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1040), GPR_U64(ctx, 16));
    // 0x184120: 0xffb10418  sd          $s1, 0x418($sp)
    ctx->pc = 0x184120u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1048), GPR_U64(ctx, 17));
    // 0x184124: 0xffbf0458  sd          $ra, 0x458($sp)
    ctx->pc = 0x184124u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1112), GPR_U64(ctx, 31));
    // 0x184128: 0xafa60404  sw          $a2, 0x404($sp)
    ctx->pc = 0x184128u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 1028), GPR_U32(ctx, 6));
    // 0x18412c: 0x10000068  b           . + 4 + (0x68 << 2)
    ctx->pc = 0x18412Cu;
    {
        const bool branch_taken_0x18412c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x184130u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18412Cu;
            // 0x184130: 0xafa00400  sw          $zero, 0x400($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 1024), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18412c) {
            ctx->pc = 0x1842D0u;
            goto label_1842d0;
        }
    }
    ctx->pc = 0x184134u;
    // 0x184134: 0x0  nop
    ctx->pc = 0x184134u;
    // NOP
label_184138:
    // 0x184138: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x184138u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18413c: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x18413Cu;
    SET_GPR_U32(ctx, 31, 0x184144u);
    ctx->pc = 0x184140u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18413Cu;
            // 0x184140: 0x244517b0  addiu       $a1, $v0, 0x17B0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 6064));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184144u; }
        if (ctx->pc != 0x184144u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184144u; }
        if (ctx->pc != 0x184144u) { return; }
    }
    ctx->pc = 0x184144u;
label_184144:
    // 0x184144: 0x14400075  bnez        $v0, . + 4 + (0x75 << 2)
    ctx->pc = 0x184144u;
    {
        const bool branch_taken_0x184144 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x184148u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184144u;
            // 0x184148: 0x27b00240  addiu       $s0, $sp, 0x240 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 576));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184144) {
            ctx->pc = 0x18431Cu;
            goto label_18431c;
        }
    }
    ctx->pc = 0x18414Cu;
    // 0x18414c: 0xc042c56  jal         func_10B158
    ctx->pc = 0x18414Cu;
    SET_GPR_U32(ctx, 31, 0x184154u);
    ctx->pc = 0x184150u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18414Cu;
            // 0x184150: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184154u; }
        if (ctx->pc != 0x184154u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184154u; }
        if (ctx->pc != 0x184154u) { return; }
    }
    ctx->pc = 0x184154u;
label_184154:
    // 0x184154: 0x2c430020  sltiu       $v1, $v0, 0x20
    ctx->pc = 0x184154u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)32) ? 1 : 0);
    // 0x184158: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x184158u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x18415c: 0x10600074  beqz        $v1, . + 4 + (0x74 << 2)
    ctx->pc = 0x18415Cu;
    {
        const bool branch_taken_0x18415c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x184160u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18415Cu;
            // 0x184160: 0x34429002  ori         $v0, $v0, 0x9002 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)36866);
        ctx->in_delay_slot = false;
        if (branch_taken_0x18415c) {
            ctx->pc = 0x184330u;
            goto label_184330;
        }
    }
    ctx->pc = 0x184164u;
    // 0x184164: 0x3c060024  lui         $a2, 0x24
    ctx->pc = 0x184164u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
    // 0x184168: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x184168u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18416c: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x18416Cu;
    SET_GPR_U32(ctx, 31, 0x184174u);
    ctx->pc = 0x184170u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18416Cu;
            // 0x184170: 0x24c517b8  addiu       $a1, $a2, 0x17B8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 6), 6072));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184174u; }
        if (ctx->pc != 0x184174u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184174u; }
        if (ctx->pc != 0x184174u) { return; }
    }
    ctx->pc = 0x184174u;
label_184174:
    // 0x184174: 0x14400069  bnez        $v0, . + 4 + (0x69 << 2)
    ctx->pc = 0x184174u;
    {
        const bool branch_taken_0x184174 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x184178u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184174u;
            // 0x184178: 0x3a0802d  daddu       $s0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184174) {
            ctx->pc = 0x18431Cu;
            goto label_18431c;
        }
    }
    ctx->pc = 0x18417Cu;
label_18417c:
    // 0x18417c: 0x12400047  beqz        $s2, . + 4 + (0x47 << 2)
    ctx->pc = 0x18417Cu;
    {
        const bool branch_taken_0x18417c = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x184180u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18417Cu;
            // 0x184180: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18417c) {
            ctx->pc = 0x18429Cu;
            goto label_18429c;
        }
    }
    ctx->pc = 0x184184u;
    // 0x184184: 0x96020000  lhu         $v0, 0x0($s0)
    ctx->pc = 0x184184u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
label_184188:
    // 0x184188: 0x30428000  andi        $v0, $v0, 0x8000
    ctx->pc = 0x184188u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)32768);
    // 0x18418c: 0x1040003a  beqz        $v0, . + 4 + (0x3A << 2)
    ctx->pc = 0x18418Cu;
    {
        const bool branch_taken_0x18418c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x184190u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18418Cu;
            // 0x184190: 0x26050040  addiu       $a1, $s0, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 64));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18418c) {
            ctx->pc = 0x184278u;
            goto label_184278;
        }
    }
    ctx->pc = 0x184194u;
    // 0x184194: 0xa200005f  sb          $zero, 0x5F($s0)
    ctx->pc = 0x184194u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 95), (uint8_t)GPR_U32(ctx, 0));
    // 0x184198: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x184198u;
    SET_GPR_U32(ctx, 31, 0x1841A0u);
    ctx->pc = 0x18419Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x184198u;
            // 0x18419c: 0x2c0202d  daddu       $a0, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1841A0u; }
        if (ctx->pc != 0x1841A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1841A0u; }
        if (ctx->pc != 0x1841A0u) { return; }
    }
    ctx->pc = 0x1841A0u;
label_1841a0:
    // 0x1841a0: 0x14400036  bnez        $v0, . + 4 + (0x36 << 2)
    ctx->pc = 0x1841A0u;
    {
        const bool branch_taken_0x1841a0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1841A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1841A0u;
            // 0x1841a4: 0x12102a  slt         $v0, $zero, $s2 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1841a0) {
            ctx->pc = 0x18427Cu;
            goto label_18427c;
        }
    }
    ctx->pc = 0x1841A8u;
    // 0x1841a8: 0x13c0002e  beqz        $fp, . + 4 + (0x2E << 2)
    ctx->pc = 0x1841A8u;
    {
        const bool branch_taken_0x1841a8 = (GPR_U64(ctx, 30) == GPR_U64(ctx, 0));
        ctx->pc = 0x1841ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1841A8u;
            // 0x1841ac: 0x8fa70404  lw          $a3, 0x404($sp) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 1028)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1841a8) {
            ctx->pc = 0x184264u;
            goto label_184264;
        }
    }
    ctx->pc = 0x1841B0u;
    // 0x1841b0: 0x3c0282d  daddu       $a1, $fp, $zero
    ctx->pc = 0x1841b0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1841b4: 0x2051025  or          $v0, $s0, $a1
    ctx->pc = 0x1841b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) | GPR_U64(ctx, 5));
    // 0x1841b8: 0x30420007  andi        $v0, $v0, 0x7
    ctx->pc = 0x1841b8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)7);
    // 0x1841bc: 0x1040001a  beqz        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x1841BCu;
    {
        const bool branch_taken_0x1841bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1841C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1841BCu;
            // 0x1841c0: 0x200182d  daddu       $v1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1841bc) {
            ctx->pc = 0x184228u;
            goto label_184228;
        }
    }
    ctx->pc = 0x1841C4u;
    // 0x1841c4: 0x26020200  addiu       $v0, $s0, 0x200
    ctx->pc = 0x1841c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 512));
label_1841c8:
    // 0x1841c8: 0x68670007  ldl         $a3, 0x7($v1)
    ctx->pc = 0x1841c8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem << shift)); }
    // 0x1841cc: 0x6c670000  ldr         $a3, 0x0($v1)
    ctx->pc = 0x1841ccu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem >> shift)); }
    // 0x1841d0: 0x6868000f  ldl         $t0, 0xF($v1)
    ctx->pc = 0x1841d0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x1841d4: 0x6c680008  ldr         $t0, 0x8($v1)
    ctx->pc = 0x1841d4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x1841d8: 0x68640017  ldl         $a0, 0x17($v1)
    ctx->pc = 0x1841d8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x1841dc: 0x6c640010  ldr         $a0, 0x10($v1)
    ctx->pc = 0x1841dcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x1841e0: 0x6866001f  ldl         $a2, 0x1F($v1)
    ctx->pc = 0x1841e0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x1841e4: 0x6c660018  ldr         $a2, 0x18($v1)
    ctx->pc = 0x1841e4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x1841e8: 0xb0a70007  sdl         $a3, 0x7($a1)
    ctx->pc = 0x1841e8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1841ec: 0xb4a70000  sdr         $a3, 0x0($a1)
    ctx->pc = 0x1841ecu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1841f0: 0xb0a8000f  sdl         $t0, 0xF($a1)
    ctx->pc = 0x1841f0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1841f4: 0xb4a80008  sdr         $t0, 0x8($a1)
    ctx->pc = 0x1841f4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1841f8: 0xb0a40017  sdl         $a0, 0x17($a1)
    ctx->pc = 0x1841f8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1841fc: 0xb4a40010  sdr         $a0, 0x10($a1)
    ctx->pc = 0x1841fcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x184200: 0xb0a6001f  sdl         $a2, 0x1F($a1)
    ctx->pc = 0x184200u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x184204: 0xb4a60018  sdr         $a2, 0x18($a1)
    ctx->pc = 0x184204u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x184208: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x184208u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x18420c: 0x0  nop
    ctx->pc = 0x18420cu;
    // NOP
    // 0x184210: 0x0  nop
    ctx->pc = 0x184210u;
    // NOP
    // 0x184214: 0x1462ffec  bne         $v1, $v0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x184214u;
    {
        const bool branch_taken_0x184214 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x184218u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184214u;
            // 0x184218: 0x24a50020  addiu       $a1, $a1, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184214) {
            ctx->pc = 0x1841C8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1841c8;
        }
    }
    ctx->pc = 0x18421Cu;
    // 0x18421c: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x18421Cu;
    {
        const bool branch_taken_0x18421c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x184220u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18421Cu;
            // 0x184220: 0x8fa70404  lw          $a3, 0x404($sp) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 1028)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18421c) {
            ctx->pc = 0x184264u;
            goto label_184264;
        }
    }
    ctx->pc = 0x184224u;
    // 0x184224: 0x0  nop
    ctx->pc = 0x184224u;
    // NOP
label_184228:
    // 0x184228: 0x26020200  addiu       $v0, $s0, 0x200
    ctx->pc = 0x184228u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 512));
label_18422c:
    // 0x18422c: 0xdc670000  ld          $a3, 0x0($v1)
    ctx->pc = 0x18422cu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x184230: 0xdc680008  ld          $t0, 0x8($v1)
    ctx->pc = 0x184230u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x184234: 0xdc640010  ld          $a0, 0x10($v1)
    ctx->pc = 0x184234u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x184238: 0xdc660018  ld          $a2, 0x18($v1)
    ctx->pc = 0x184238u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x18423c: 0xfca70000  sd          $a3, 0x0($a1)
    ctx->pc = 0x18423cu;
    WRITE64(ADD32(GPR_U32(ctx, 5), 0), GPR_U64(ctx, 7));
    // 0x184240: 0xfca80008  sd          $t0, 0x8($a1)
    ctx->pc = 0x184240u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 8), GPR_U64(ctx, 8));
    // 0x184244: 0xfca40010  sd          $a0, 0x10($a1)
    ctx->pc = 0x184244u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 16), GPR_U64(ctx, 4));
    // 0x184248: 0xfca60018  sd          $a2, 0x18($a1)
    ctx->pc = 0x184248u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 24), GPR_U64(ctx, 6));
    // 0x18424c: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x18424cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x184250: 0x0  nop
    ctx->pc = 0x184250u;
    // NOP
    // 0x184254: 0x0  nop
    ctx->pc = 0x184254u;
    // NOP
    // 0x184258: 0x1462fff4  bne         $v1, $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x184258u;
    {
        const bool branch_taken_0x184258 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x18425Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184258u;
            // 0x18425c: 0x24a50020  addiu       $a1, $a1, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184258) {
            ctx->pc = 0x18422Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18422c;
        }
    }
    ctx->pc = 0x184260u;
    // 0x184260: 0x8fa70404  lw          $a3, 0x404($sp)
    ctx->pc = 0x184260u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 1028)));
label_184264:
    // 0x184264: 0x54e00001  bnel        $a3, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x184264u;
    {
        const bool branch_taken_0x184264 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        if (branch_taken_0x184264) {
            ctx->pc = 0x184268u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x184264u;
            // 0x184268: 0xacf40000  sw          $s4, 0x0($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 20));
        ctx->in_delay_slot = false;
            ctx->pc = 0x18426Cu;
            goto label_18426c;
        }
    }
    ctx->pc = 0x18426Cu;
label_18426c:
    // 0x18426c: 0x10000030  b           . + 4 + (0x30 << 2)
    ctx->pc = 0x18426Cu;
    {
        const bool branch_taken_0x18426c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x184270u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18426Cu;
            // 0x184270: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18426c) {
            ctx->pc = 0x184330u;
            goto label_184330;
        }
    }
    ctx->pc = 0x184274u;
    // 0x184274: 0x0  nop
    ctx->pc = 0x184274u;
    // NOP
label_184278:
    // 0x184278: 0x12102a  slt         $v0, $zero, $s2
    ctx->pc = 0x184278u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
label_18427c:
    // 0x18427c: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x18427cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x184280: 0x2429023  subu        $s2, $s2, $v0
    ctx->pc = 0x184280u;
    SET_GPR_S32(ctx, 18, (int32_t)SUB32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
    // 0x184284: 0x2a220002  slti        $v0, $s1, 0x2
    ctx->pc = 0x184284u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x184288: 0x26100200  addiu       $s0, $s0, 0x200
    ctx->pc = 0x184288u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 512));
    // 0x18428c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x18428Cu;
    {
        const bool branch_taken_0x18428c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x184290u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18428Cu;
            // 0x184290: 0x26940001  addiu       $s4, $s4, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18428c) {
            ctx->pc = 0x18429Cu;
            goto label_18429c;
        }
    }
    ctx->pc = 0x184294u;
    // 0x184294: 0x5640ffbc  bnel        $s2, $zero, . + 4 + (-0x44 << 2)
    ctx->pc = 0x184294u;
    {
        const bool branch_taken_0x184294 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        if (branch_taken_0x184294) {
            ctx->pc = 0x184298u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x184294u;
            // 0x184298: 0x96020000  lhu         $v0, 0x0($s0) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x184188u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_184188;
        }
    }
    ctx->pc = 0x18429Cu;
label_18429c:
    // 0x18429c: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x18429cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1842a0: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x1842a0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1842a4: 0xc060b02  jal         func_182C08
    ctx->pc = 0x1842A4u;
    SET_GPR_U32(ctx, 31, 0x1842ACu);
    ctx->pc = 0x1842A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1842A4u;
            // 0x1842a8: 0x27a60400  addiu       $a2, $sp, 0x400 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 1024));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182C08u;
    if (runtime->hasFunction(0x182C08u)) {
        auto targetFn = runtime->lookupFunction(0x182C08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1842ACu; }
        if (ctx->pc != 0x1842ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182C08_0x182c08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1842ACu; }
        if (ctx->pc != 0x1842ACu) { return; }
    }
    ctx->pc = 0x1842ACu;
label_1842ac:
    // 0x1842ac: 0x8fa30400  lw          $v1, 0x400($sp)
    ctx->pc = 0x1842acu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 1024)));
    // 0x1842b0: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x1842b0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1842b4: 0x1460001e  bnez        $v1, . + 4 + (0x1E << 2)
    ctx->pc = 0x1842B4u;
    {
        const bool branch_taken_0x1842b4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1842B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1842B4u;
            // 0x1842b8: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1842b4) {
            ctx->pc = 0x184330u;
            goto label_184330;
        }
    }
    ctx->pc = 0x1842BCu;
    // 0x1842bc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1842bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1842c0: 0x12620019  beq         $s3, $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x1842C0u;
    {
        const bool branch_taken_0x1842c0 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 2));
        ctx->pc = 0x1842C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1842C0u;
            // 0x1842c4: 0x3c027fff  lui         $v0, 0x7FFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1842c0) {
            ctx->pc = 0x184328u;
            goto label_184328;
        }
    }
    ctx->pc = 0x1842C8u;
    // 0x1842c8: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x1842c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x1842cc: 0x2629824  and         $s3, $s3, $v0
    ctx->pc = 0x1842ccu;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 19) & GPR_U64(ctx, 2));
label_1842d0:
    // 0x1842d0: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x1842d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1842d4: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x1842d4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1842d8: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x1842d8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1842dc: 0xc061d1e  jal         func_187478
    ctx->pc = 0x1842DCu;
    SET_GPR_U32(ctx, 31, 0x1842E4u);
    ctx->pc = 0x1842E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1842DCu;
            // 0x1842e0: 0x24070001  addiu       $a3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x187478u;
    if (runtime->hasFunction(0x187478u)) {
        auto targetFn = runtime->lookupFunction(0x187478u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1842E4u; }
        if (ctx->pc != 0x1842E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187478_0x187478(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1842E4u; }
        if (ctx->pc != 0x1842E4u) { return; }
    }
    ctx->pc = 0x1842E4u;
label_1842e4:
    // 0x1842e4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1842E4u;
    {
        const bool branch_taken_0x1842e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1842e4) {
            ctx->pc = 0x1842F8u;
            goto label_1842f8;
        }
    }
    ctx->pc = 0x1842ECu;
    // 0x1842ec: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1842ecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x1842f0: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1842F0u;
    {
        const bool branch_taken_0x1842f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1842F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1842F0u;
            // 0x1842f4: 0x3442006f  ori         $v0, $v0, 0x6F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)111);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1842f0) {
            ctx->pc = 0x184330u;
            goto label_184330;
        }
    }
    ctx->pc = 0x1842F8u;
label_1842f8:
    // 0x1842f8: 0x12e0ffa0  beqz        $s7, . + 4 + (-0x60 << 2)
    ctx->pc = 0x1842F8u;
    {
        const bool branch_taken_0x1842f8 = (GPR_U64(ctx, 23) == GPR_U64(ctx, 0));
        ctx->pc = 0x1842FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1842F8u;
            // 0x1842fc: 0x3a0802d  daddu       $s0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1842f8) {
            ctx->pc = 0x18417Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18417c;
        }
    }
    ctx->pc = 0x184300u;
    // 0x184300: 0x27b00040  addiu       $s0, $sp, 0x40
    ctx->pc = 0x184300u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x184304: 0xb82d  daddu       $s7, $zero, $zero
    ctx->pc = 0x184304u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184308: 0xc042c56  jal         func_10B158
    ctx->pc = 0x184308u;
    SET_GPR_U32(ctx, 31, 0x184310u);
    ctx->pc = 0x18430Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x184308u;
            // 0x18430c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184310u; }
        if (ctx->pc != 0x184310u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184310u; }
        if (ctx->pc != 0x184310u) { return; }
    }
    ctx->pc = 0x184310u;
label_184310:
    // 0x184310: 0x2c420020  sltiu       $v0, $v0, 0x20
    ctx->pc = 0x184310u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)32) ? 1 : 0);
    // 0x184314: 0x5440ff88  bnel        $v0, $zero, . + 4 + (-0x78 << 2)
    ctx->pc = 0x184314u;
    {
        const bool branch_taken_0x184314 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x184314) {
            ctx->pc = 0x184318u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x184314u;
            // 0x184318: 0x3c020024  lui         $v0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x184138u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_184138;
        }
    }
    ctx->pc = 0x18431Cu;
label_18431c:
    // 0x18431c: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x18431cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x184320: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x184320u;
    {
        const bool branch_taken_0x184320 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x184324u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184320u;
            // 0x184324: 0x34429002  ori         $v0, $v0, 0x9002 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)36866);
        ctx->in_delay_slot = false;
        if (branch_taken_0x184320) {
            ctx->pc = 0x184330u;
            goto label_184330;
        }
    }
    ctx->pc = 0x184328u;
label_184328:
    // 0x184328: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x184328u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x18432c: 0x34420002  ori         $v0, $v0, 0x2
    ctx->pc = 0x18432cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)2);
label_184330:
    // 0x184330: 0xdfb00410  ld          $s0, 0x410($sp)
    ctx->pc = 0x184330u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 1040)));
    // 0x184334: 0xdfb10418  ld          $s1, 0x418($sp)
    ctx->pc = 0x184334u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 1048)));
    // 0x184338: 0xdfb20420  ld          $s2, 0x420($sp)
    ctx->pc = 0x184338u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 1056)));
    // 0x18433c: 0xdfb30428  ld          $s3, 0x428($sp)
    ctx->pc = 0x18433cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 1064)));
    // 0x184340: 0xdfb40430  ld          $s4, 0x430($sp)
    ctx->pc = 0x184340u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 1072)));
    // 0x184344: 0xdfb50438  ld          $s5, 0x438($sp)
    ctx->pc = 0x184344u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 1080)));
    // 0x184348: 0xdfb60440  ld          $s6, 0x440($sp)
    ctx->pc = 0x184348u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 1088)));
    // 0x18434c: 0xdfb70448  ld          $s7, 0x448($sp)
    ctx->pc = 0x18434cu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 1096)));
    // 0x184350: 0xdfbe0450  ld          $fp, 0x450($sp)
    ctx->pc = 0x184350u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 1104)));
    // 0x184354: 0xdfbf0458  ld          $ra, 0x458($sp)
    ctx->pc = 0x184354u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 1112)));
    // 0x184358: 0x3e00008  jr          $ra
    ctx->pc = 0x184358u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18435Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184358u;
            // 0x18435c: 0x27bd0460  addiu       $sp, $sp, 0x460 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 1120));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x184138u: goto label_184138;
            case 0x184144u: goto label_184144;
            case 0x184154u: goto label_184154;
            case 0x184174u: goto label_184174;
            case 0x18417Cu: goto label_18417c;
            case 0x184188u: goto label_184188;
            case 0x1841A0u: goto label_1841a0;
            case 0x1841C8u: goto label_1841c8;
            case 0x184228u: goto label_184228;
            case 0x18422Cu: goto label_18422c;
            case 0x184264u: goto label_184264;
            case 0x18426Cu: goto label_18426c;
            case 0x184278u: goto label_184278;
            case 0x18427Cu: goto label_18427c;
            case 0x18429Cu: goto label_18429c;
            case 0x1842ACu: goto label_1842ac;
            case 0x1842D0u: goto label_1842d0;
            case 0x1842E4u: goto label_1842e4;
            case 0x1842F8u: goto label_1842f8;
            case 0x184310u: goto label_184310;
            case 0x18431Cu: goto label_18431c;
            case 0x184328u: goto label_184328;
            case 0x184330u: goto label_184330;
            default: break;
        }
        return;
    }
    ctx->pc = 0x184360u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
