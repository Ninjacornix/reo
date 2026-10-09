#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A1FD0
// Address: 0x1a1fd0 - 0x1a21f4
void sub_001A1FD0_0x1a1fd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A1FD0_0x1a1fd0");
#endif

    switch (ctx->pc) {
        case 0x1a2010u: goto label_1a2010;
        case 0x1a2024u: goto label_1a2024;
        case 0x1a203cu: goto label_1a203c;
        case 0x1a2050u: goto label_1a2050;
        case 0x1a205cu: goto label_1a205c;
        case 0x1a207cu: goto label_1a207c;
        case 0x1a20a0u: goto label_1a20a0;
        case 0x1a20b0u: goto label_1a20b0;
        case 0x1a20c4u: goto label_1a20c4;
        case 0x1a20ccu: goto label_1a20cc;
        case 0x1a20e4u: goto label_1a20e4;
        case 0x1a211cu: goto label_1a211c;
        case 0x1a2154u: goto label_1a2154;
        case 0x1a219cu: goto label_1a219c;
        default: break;
    }

    ctx->pc = 0x1a1fd0u;

    // 0x1a1fd0: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x1a1fd0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x1a1fd4: 0xffbf0080  sd          $ra, 0x80($sp)
    ctx->pc = 0x1a1fd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 31));
    // 0x1a1fd8: 0x7fb60070  sq          $s6, 0x70($sp)
    ctx->pc = 0x1a1fd8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 112), GPR_VEC(ctx, 22));
    // 0x1a1fdc: 0x7fb50060  sq          $s5, 0x60($sp)
    ctx->pc = 0x1a1fdcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 21));
    // 0x1a1fe0: 0x7fb40050  sq          $s4, 0x50($sp)
    ctx->pc = 0x1a1fe0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 20));
    // 0x1a1fe4: 0x7fb30040  sq          $s3, 0x40($sp)
    ctx->pc = 0x1a1fe4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 19));
    // 0x1a1fe8: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x1a1fe8u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a1fec: 0x7fb20030  sq          $s2, 0x30($sp)
    ctx->pc = 0x1a1fecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 18));
    // 0x1a1ff0: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x1a1ff0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a1ff4: 0x7fb10020  sq          $s1, 0x20($sp)
    ctx->pc = 0x1a1ff4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 17));
    // 0x1a1ff8: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x1a1ff8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a1ffc: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x1a1ffcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x1a2000: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1a2000u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a2004: 0xe7b50004  swc1        $f21, 0x4($sp)
    ctx->pc = 0x1a2004u;
    { float f = ctx->f[21]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 4), bits); }
    // 0x1a2008: 0xc068790  jal         func_1A1E40
    ctx->pc = 0x1A2008u;
    SET_GPR_U32(ctx, 31, 0x1A2010u);
    ctx->pc = 0x1A200Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2008u;
            // 0x1a200c: 0xe7b40000  swc1        $f20, 0x0($sp) (Delay Slot)
        { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A1E40u;
    if (runtime->hasFunction(0x1A1E40u)) {
        auto targetFn = runtime->lookupFunction(0x1A1E40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2010u; }
        if (ctx->pc != 0x1A2010u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A1E40_0x1a1e40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2010u; }
        if (ctx->pc != 0x1A2010u) { return; }
    }
    ctx->pc = 0x1A2010u;
label_1a2010:
    // 0x1a2010: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a2010u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a2014: 0x40a82d  daddu       $s5, $v0, $zero
    ctx->pc = 0x1a2014u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a2018: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1a2018u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a201c: 0xc069368  jal         func_1A4DA0
    ctx->pc = 0x1A201Cu;
    SET_GPR_U32(ctx, 31, 0x1A2024u);
    ctx->pc = 0x1A2020u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A201Cu;
            // 0x1a2020: 0xac33ffb0  sw          $s3, -0x50($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294967216), GPR_U32(ctx, 19));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A4DA0u;
    if (runtime->hasFunction(0x1A4DA0u)) {
        auto targetFn = runtime->lookupFunction(0x1A4DA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2024u; }
        if (ctx->pc != 0x1A2024u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A4DA0_0x1a4da0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2024u; }
        if (ctx->pc != 0x1A2024u) { return; }
    }
    ctx->pc = 0x1A2024u;
label_1a2024:
    // 0x1a2024: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a2024u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a2028: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1a2028u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a202c: 0x2484ffc0  addiu       $a0, $a0, -0x40
    ctx->pc = 0x1a202cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967232));
    // 0x1a2030: 0x2a0302d  daddu       $a2, $s5, $zero
    ctx->pc = 0x1a2030u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a2034: 0xc06265c  jal         func_189970
    ctx->pc = 0x1A2034u;
    SET_GPR_U32(ctx, 31, 0x1A203Cu);
    ctx->pc = 0x1A2038u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2034u;
            // 0x1a2038: 0x24070001  addiu       $a3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189970u;
    if (runtime->hasFunction(0x189970u)) {
        auto targetFn = runtime->lookupFunction(0x189970u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A203Cu; }
        if (ctx->pc != 0x1A203Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189970_0x189970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A203Cu; }
        if (ctx->pc != 0x1A203Cu) { return; }
    }
    ctx->pc = 0x1A203Cu;
label_1a203c:
    // 0x1a203c: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a203cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a2040: 0x24050020  addiu       $a1, $zero, 0x20
    ctx->pc = 0x1a2040u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1a2044: 0x2484ffc0  addiu       $a0, $a0, -0x40
    ctx->pc = 0x1a2044u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967232));
    // 0x1a2048: 0xc06267c  jal         func_1899F0
    ctx->pc = 0x1A2048u;
    SET_GPR_U32(ctx, 31, 0x1A2050u);
    ctx->pc = 0x1A204Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2048u;
            // 0x1a204c: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1899F0u;
    if (runtime->hasFunction(0x1899F0u)) {
        auto targetFn = runtime->lookupFunction(0x1899F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2050u; }
        if (ctx->pc != 0x1A2050u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001899F0_0x1899f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2050u; }
        if (ctx->pc != 0x1A2050u) { return; }
    }
    ctx->pc = 0x1A2050u;
label_1a2050:
    // 0x1a2050: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1a2050u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a2054: 0xc068ab4  jal         func_1A2AD0
    ctx->pc = 0x1A2054u;
    SET_GPR_U32(ctx, 31, 0x1A205Cu);
    ctx->pc = 0x1A2058u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2054u;
            // 0x1a2058: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A2AD0u;
    if (runtime->hasFunction(0x1A2AD0u)) {
        auto targetFn = runtime->lookupFunction(0x1A2AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A205Cu; }
        if (ctx->pc != 0x1A205Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A2AD0_0x1a2ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A205Cu; }
        if (ctx->pc != 0x1A205Cu) { return; }
    }
    ctx->pc = 0x1A205Cu;
label_1a205c:
    // 0x1a205c: 0xa6000000  sh          $zero, 0x0($s0)
    ctx->pc = 0x1a205cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1a2060: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a2060u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a2064: 0x40b02d  daddu       $s6, $v0, $zero
    ctx->pc = 0x1a2064u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a2068: 0xa6020002  sh          $v0, 0x2($s0)
    ctx->pc = 0x1a2068u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x1a206c: 0x22880  sll         $a1, $v0, 2
    ctx->pc = 0x1a206cu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1a2070: 0x2484ffc0  addiu       $a0, $a0, -0x40
    ctx->pc = 0x1a2070u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967232));
    // 0x1a2074: 0xc06267c  jal         func_1899F0
    ctx->pc = 0x1A2074u;
    SET_GPR_U32(ctx, 31, 0x1A207Cu);
    ctx->pc = 0x1A2078u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2074u;
            // 0x1a2078: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1899F0u;
    if (runtime->hasFunction(0x1899F0u)) {
        auto targetFn = runtime->lookupFunction(0x1899F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A207Cu; }
        if (ctx->pc != 0x1A207Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001899F0_0x1899f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A207Cu; }
        if (ctx->pc != 0x1A207Cu) { return; }
    }
    ctx->pc = 0x1A207Cu;
label_1a207c:
    // 0x1a207c: 0xae020010  sw          $v0, 0x10($s0)
    ctx->pc = 0x1a207cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
    // 0x1a2080: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x1a2080u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x1a2084: 0xae000014  sw          $zero, 0x14($s0)
    ctx->pc = 0x1a2084u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
    // 0x1a2088: 0x4480a000  mtc1        $zero, $f20
    ctx->pc = 0x1a2088u;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[20], &bits, sizeof(bits)); }
    // 0x1a208c: 0xae150018  sw          $s5, 0x18($s0)
    ctx->pc = 0x1a208cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 21));
    // 0x1a2090: 0x8e150010  lw          $s5, 0x10($s0)
    ctx->pc = 0x1a2090u;
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1a2094: 0xc4351e90  lwc1        $f21, 0x1E90($at)
    ctx->pc = 0x1a2094u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 7824)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[21] = f; }
    // 0x1a2098: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1A2098u;
    {
        const bool branch_taken_0x1a2098 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A209Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2098u;
            // 0x1a209c: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2098) {
            ctx->pc = 0x1A20FCu;
            goto label_1a20fc;
        }
    }
    ctx->pc = 0x1A20A0u;
label_1a20a0:
    // 0x1a20a0: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x1a20a0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1a20a4: 0x2484ffc0  addiu       $a0, $a0, -0x40
    ctx->pc = 0x1a20a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967232));
    // 0x1a20a8: 0xc06267c  jal         func_1899F0
    ctx->pc = 0x1A20A8u;
    SET_GPR_U32(ctx, 31, 0x1A20B0u);
    ctx->pc = 0x1A20ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A20A8u;
            // 0x1a20ac: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1899F0u;
    if (runtime->hasFunction(0x1899F0u)) {
        auto targetFn = runtime->lookupFunction(0x1899F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A20B0u; }
        if (ctx->pc != 0x1A20B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001899F0_0x1899f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A20B0u; }
        if (ctx->pc != 0x1A20B0u) { return; }
    }
    ctx->pc = 0x1A20B0u;
label_1a20b0:
    // 0x1a20b0: 0xaea20000  sw          $v0, 0x0($s5)
    ctx->pc = 0x1a20b0u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 2));
    // 0x1a20b4: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1a20b4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a20b8: 0x8ea40000  lw          $a0, 0x0($s5)
    ctx->pc = 0x1a20b8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1a20bc: 0xc068880  jal         func_1A2200
    ctx->pc = 0x1A20BCu;
    SET_GPR_U32(ctx, 31, 0x1A20C4u);
    ctx->pc = 0x1A20C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A20BCu;
            // 0x1a20c0: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A2200u;
    if (runtime->hasFunction(0x1A2200u)) {
        auto targetFn = runtime->lookupFunction(0x1A2200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A20C4u; }
        if (ctx->pc != 0x1A20C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A2200_0x1a2200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A20C4u; }
        if (ctx->pc != 0x1A20C4u) { return; }
    }
    ctx->pc = 0x1A20C4u;
label_1a20c4:
    // 0x1a20c4: 0xc068a74  jal         func_1A29D0
    ctx->pc = 0x1A20C4u;
    SET_GPR_U32(ctx, 31, 0x1A20CCu);
    ctx->pc = 0x1A20C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A20C4u;
            // 0x1a20c8: 0x8ea40000  lw          $a0, 0x0($s5) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A29D0u;
    if (runtime->hasFunction(0x1A29D0u)) {
        auto targetFn = runtime->lookupFunction(0x1A29D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A20CCu; }
        if (ctx->pc != 0x1A20CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A29D0_0x1a29d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A20CCu; }
        if (ctx->pc != 0x1A20CCu) { return; }
    }
    ctx->pc = 0x1A20CCu;
label_1a20cc:
    // 0x1a20cc: 0x46140036  c.le.s      $f0, $f20
    ctx->pc = 0x1a20ccu;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[20])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1a20d0: 0x45010002  bc1t        . + 4 + (0x2 << 2)
    ctx->pc = 0x1A20D0u;
    {
        const bool branch_taken_0x1a20d0 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1a20d0) {
            ctx->pc = 0x1A20DCu;
            goto label_1a20dc;
        }
    }
    ctx->pc = 0x1A20D8u;
    // 0x1a20d8: 0x46000506  mov.s       $f20, $f0
    ctx->pc = 0x1a20d8u;
    ctx->f[20] = FPU_MOV_S(ctx->f[0]);
label_1a20dc:
    // 0x1a20dc: 0xc068a94  jal         func_1A2A50
    ctx->pc = 0x1A20DCu;
    SET_GPR_U32(ctx, 31, 0x1A20E4u);
    ctx->pc = 0x1A20E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A20DCu;
            // 0x1a20e0: 0x8ea40000  lw          $a0, 0x0($s5) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A2A50u;
    if (runtime->hasFunction(0x1A2A50u)) {
        auto targetFn = runtime->lookupFunction(0x1A2A50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A20E4u; }
        if (ctx->pc != 0x1A20E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A2A50_0x1a2a50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A20E4u; }
        if (ctx->pc != 0x1A20E4u) { return; }
    }
    ctx->pc = 0x1A20E4u;
label_1a20e4:
    // 0x1a20e4: 0x46150034  c.lt.s      $f0, $f21
    ctx->pc = 0x1a20e4u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[0], ctx->f[21])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1a20e8: 0x45000002  bc1f        . + 4 + (0x2 << 2)
    ctx->pc = 0x1A20E8u;
    {
        const bool branch_taken_0x1a20e8 = (!(ctx->fcr31 & 0x800000));
        if (branch_taken_0x1a20e8) {
            ctx->pc = 0x1A20F4u;
            goto label_1a20f4;
        }
    }
    ctx->pc = 0x1A20F0u;
    // 0x1a20f0: 0x46000546  mov.s       $f21, $f0
    ctx->pc = 0x1a20f0u;
    ctx->f[21] = FPU_MOV_S(ctx->f[0]);
label_1a20f4:
    // 0x1a20f4: 0x26b50004  addiu       $s5, $s5, 0x4
    ctx->pc = 0x1a20f4u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 4));
    // 0x1a20f8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1a20f8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
label_1a20fc:
    // 0x1a20fc: 0x236102a  slt         $v0, $s1, $s6
    ctx->pc = 0x1a20fcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 22)) ? 1 : 0);
    // 0x1a2100: 0x1440ffe7  bnez        $v0, . + 4 + (-0x19 << 2)
    ctx->pc = 0x1A2100u;
    {
        const bool branch_taken_0x1a2100 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A2104u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2100u;
            // 0x1a2104: 0x3c04002b  lui         $a0, 0x2B (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2100) {
            ctx->pc = 0x1A20A0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a20a0;
        }
    }
    ctx->pc = 0x1A2108u;
    // 0x1a2108: 0xe6150004  swc1        $f21, 0x4($s0)
    ctx->pc = 0x1a2108u;
    { float f = ctx->f[21]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 4), bits); }
    // 0x1a210c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1a210cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a2110: 0x27a5009c  addiu       $a1, $sp, 0x9C
    ctx->pc = 0x1a2110u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 156));
    // 0x1a2114: 0xc068780  jal         func_1A1E00
    ctx->pc = 0x1A2114u;
    SET_GPR_U32(ctx, 31, 0x1A211Cu);
    ctx->pc = 0x1A2118u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2114u;
            // 0x1a2118: 0xe6140008  swc1        $f20, 0x8($s0) (Delay Slot)
        { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 8), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A1E00u;
    if (runtime->hasFunction(0x1A1E00u)) {
        auto targetFn = runtime->lookupFunction(0x1A1E00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A211Cu; }
        if (ctx->pc != 0x1A211Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A1E00_0x1a1e00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A211Cu; }
        if (ctx->pc != 0x1A211Cu) { return; }
    }
    ctx->pc = 0x1A211Cu;
label_1a211c:
    // 0x1a211c: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1A211Cu;
    {
        const bool branch_taken_0x1a211c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a211c) {
            ctx->pc = 0x1A213Cu;
            goto label_1a213c;
        }
    }
    ctx->pc = 0x1A2124u;
    // 0x1a2124: 0x96020000  lhu         $v0, 0x0($s0)
    ctx->pc = 0x1a2124u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1a2128: 0x34428000  ori         $v0, $v0, 0x8000
    ctx->pc = 0x1a2128u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32768);
    // 0x1a212c: 0xa6020000  sh          $v0, 0x0($s0)
    ctx->pc = 0x1a212cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1a2130: 0xc7a0009c  lwc1        $f0, 0x9C($sp)
    ctx->pc = 0x1a2130u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 156)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a2134: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1A2134u;
    {
        const bool branch_taken_0x1a2134 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A2138u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2134u;
            // 0x1a2138: 0xe600000c  swc1        $f0, 0xC($s0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 12), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2134) {
            ctx->pc = 0x1A214Cu;
            goto label_1a214c;
        }
    }
    ctx->pc = 0x1A213Cu;
label_1a213c:
    // 0x1a213c: 0x96020000  lhu         $v0, 0x0($s0)
    ctx->pc = 0x1a213cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1a2140: 0x30427fff  andi        $v0, $v0, 0x7FFF
    ctx->pc = 0x1a2140u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)32767);
    // 0x1a2144: 0xa6020000  sh          $v0, 0x0($s0)
    ctx->pc = 0x1a2144u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1a2148: 0xae00000c  sw          $zero, 0xC($s0)
    ctx->pc = 0x1a2148u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 0));
label_1a214c:
    // 0x1a214c: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1A214Cu;
    {
        const bool branch_taken_0x1a214c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A2150u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A214Cu;
            // 0x1a2150: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a214c) {
            ctx->pc = 0x1A2178u;
            goto label_1a2178;
        }
    }
    ctx->pc = 0x1A2154u;
label_1a2154:
    // 0x1a2154: 0x8e030010  lw          $v1, 0x10($s0)
    ctx->pc = 0x1a2154u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1a2158: 0x52080  sll         $a0, $a1, 2
    ctx->pc = 0x1a2158u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x1a215c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a215cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a2160: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1a2160u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1a2164: 0x8c22ffb0  lw          $v0, -0x50($at)
    ctx->pc = 0x1a2164u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967216)));
    // 0x1a2168: 0x642021  addu        $a0, $v1, $a0
    ctx->pc = 0x1a2168u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1a216c: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1a216cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1a2170: 0x621023  subu        $v0, $v1, $v0
    ctx->pc = 0x1a2170u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a2174: 0xac820000  sw          $v0, 0x0($a0)
    ctx->pc = 0x1a2174u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
label_1a2178:
    // 0x1a2178: 0xb6102a  slt         $v0, $a1, $s6
    ctx->pc = 0x1a2178u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 22)) ? 1 : 0);
    // 0x1a217c: 0x1440fff5  bnez        $v0, . + 4 + (-0xB << 2)
    ctx->pc = 0x1A217Cu;
    {
        const bool branch_taken_0x1a217c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A2180u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A217Cu;
            // 0x1a2180: 0x3c01002b  lui         $at, 0x2B (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a217c) {
            ctx->pc = 0x1A2154u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a2154;
        }
    }
    ctx->pc = 0x1A2184u;
    // 0x1a2184: 0x8e030010  lw          $v1, 0x10($s0)
    ctx->pc = 0x1a2184u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1a2188: 0x8c22ffb0  lw          $v0, -0x50($at)
    ctx->pc = 0x1a2188u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967216)));
    // 0x1a218c: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x1a218cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1a2190: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x1a2190u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a2194: 0x621023  subu        $v0, $v1, $v0
    ctx->pc = 0x1a2194u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a2198: 0xae020010  sw          $v0, 0x10($s0)
    ctx->pc = 0x1a2198u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
label_1a219c:
    // 0x1a219c: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x1a219cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1a21a0: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x1a21a0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x1a21a4: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x1a21a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1a21a8: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x1a21a8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x1a21ac: 0x26100008  addiu       $s0, $s0, 0x8
    ctx->pc = 0x1a21acu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
    // 0x1a21b0: 0xaca20004  sw          $v0, 0x4($a1)
    ctx->pc = 0x1a21b0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
    // 0x1a21b4: 0x1c80fff9  bgtz        $a0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1A21B4u;
    {
        const bool branch_taken_0x1a21b4 = (GPR_S64(ctx, 4) > 0);
        ctx->pc = 0x1A21B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A21B4u;
            // 0x1a21b8: 0x24a50008  addiu       $a1, $a1, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a21b4) {
            ctx->pc = 0x1A219Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a219c;
        }
    }
    ctx->pc = 0x1A21BCu;
    // 0x1a21bc: 0xae930014  sw          $s3, 0x14($s4)
    ctx->pc = 0x1a21bcu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 20), GPR_U32(ctx, 19));
    // 0x1a21c0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1a21c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a21c4: 0xdfbf0080  ld          $ra, 0x80($sp)
    ctx->pc = 0x1a21c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x1a21c8: 0xc7b50004  lwc1        $f21, 0x4($sp)
    ctx->pc = 0x1a21c8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[21] = f; }
    // 0x1a21cc: 0x7bb60070  lq          $s6, 0x70($sp)
    ctx->pc = 0x1a21ccu;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1a21d0: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x1a21d0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x1a21d4: 0x7bb50060  lq          $s5, 0x60($sp)
    ctx->pc = 0x1a21d4u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1a21d8: 0x7bb40050  lq          $s4, 0x50($sp)
    ctx->pc = 0x1a21d8u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1a21dc: 0x7bb30040  lq          $s3, 0x40($sp)
    ctx->pc = 0x1a21dcu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1a21e0: 0x7bb20030  lq          $s2, 0x30($sp)
    ctx->pc = 0x1a21e0u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1a21e4: 0x7bb10020  lq          $s1, 0x20($sp)
    ctx->pc = 0x1a21e4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1a21e8: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x1a21e8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a21ec: 0x3e00008  jr          $ra
    ctx->pc = 0x1A21ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A21F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A21ECu;
            // 0x1a21f0: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A2010u: goto label_1a2010;
            case 0x1A2024u: goto label_1a2024;
            case 0x1A203Cu: goto label_1a203c;
            case 0x1A2050u: goto label_1a2050;
            case 0x1A205Cu: goto label_1a205c;
            case 0x1A207Cu: goto label_1a207c;
            case 0x1A20A0u: goto label_1a20a0;
            case 0x1A20B0u: goto label_1a20b0;
            case 0x1A20C4u: goto label_1a20c4;
            case 0x1A20CCu: goto label_1a20cc;
            case 0x1A20DCu: goto label_1a20dc;
            case 0x1A20E4u: goto label_1a20e4;
            case 0x1A20F4u: goto label_1a20f4;
            case 0x1A20FCu: goto label_1a20fc;
            case 0x1A211Cu: goto label_1a211c;
            case 0x1A213Cu: goto label_1a213c;
            case 0x1A214Cu: goto label_1a214c;
            case 0x1A2154u: goto label_1a2154;
            case 0x1A2178u: goto label_1a2178;
            case 0x1A219Cu: goto label_1a219c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A21F4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
