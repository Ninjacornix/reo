#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00184D88
// Address: 0x184d88 - 0x185280
void sub_00184D88_0x184d88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00184D88_0x184d88");
#endif

    switch (ctx->pc) {
        case 0x184de8u: goto label_184de8;
        case 0x184e00u: goto label_184e00;
        case 0x184e28u: goto label_184e28;
        case 0x184e48u: goto label_184e48;
        case 0x184e64u: goto label_184e64;
        case 0x184ec4u: goto label_184ec4;
        case 0x184f28u: goto label_184f28;
        case 0x184f8cu: goto label_184f8c;
        case 0x184fd8u: goto label_184fd8;
        case 0x185078u: goto label_185078;
        case 0x1850a0u: goto label_1850a0;
        case 0x1850c8u: goto label_1850c8;
        case 0x1850e8u: goto label_1850e8;
        case 0x185114u: goto label_185114;
        case 0x185174u: goto label_185174;
        case 0x1851c4u: goto label_1851c4;
        case 0x1851f8u: goto label_1851f8;
        case 0x185220u: goto label_185220;
        default: break;
    }

    ctx->pc = 0x184d88u;

    // 0x184d88: 0x27bdfba0  addiu       $sp, $sp, -0x460
    ctx->pc = 0x184d88u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966176));
    // 0x184d8c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x184d8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x184d90: 0xffb10418  sd          $s1, 0x418($sp)
    ctx->pc = 0x184d90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1048), GPR_U64(ctx, 17));
    // 0x184d94: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x184d94u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184d98: 0xafa20210  sw          $v0, 0x210($sp)
    ctx->pc = 0x184d98u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 528), GPR_U32(ctx, 2));
    // 0x184d9c: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x184d9cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x184da0: 0x2e230001  sltiu       $v1, $s1, 0x1
    ctx->pc = 0x184da0u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x184da4: 0x3442006f  ori         $v0, $v0, 0x6F
    ctx->pc = 0x184da4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)111);
    // 0x184da8: 0xffb00410  sd          $s0, 0x410($sp)
    ctx->pc = 0x184da8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1040), GPR_U64(ctx, 16));
    // 0x184dac: 0xffb40430  sd          $s4, 0x430($sp)
    ctx->pc = 0x184dacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1072), GPR_U64(ctx, 20));
    // 0x184db0: 0xffb60440  sd          $s6, 0x440($sp)
    ctx->pc = 0x184db0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1088), GPR_U64(ctx, 22));
    // 0x184db4: 0xffbf0458  sd          $ra, 0x458($sp)
    ctx->pc = 0x184db4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1112), GPR_U64(ctx, 31));
    // 0x184db8: 0xafa30400  sw          $v1, 0x400($sp)
    ctx->pc = 0x184db8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 1024), GPR_U32(ctx, 3));
    // 0x184dbc: 0xafa20404  sw          $v0, 0x404($sp)
    ctx->pc = 0x184dbcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 1028), GPR_U32(ctx, 2));
    // 0x184dc0: 0xffb20420  sd          $s2, 0x420($sp)
    ctx->pc = 0x184dc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1056), GPR_U64(ctx, 18));
    // 0x184dc4: 0xe0902d  daddu       $s2, $a3, $zero
    ctx->pc = 0x184dc4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184dc8: 0xffb30428  sd          $s3, 0x428($sp)
    ctx->pc = 0x184dc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1064), GPR_U64(ctx, 19));
    // 0x184dcc: 0x100982d  daddu       $s3, $t0, $zero
    ctx->pc = 0x184dccu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184dd0: 0xffb50438  sd          $s5, 0x438($sp)
    ctx->pc = 0x184dd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1080), GPR_U64(ctx, 21));
    // 0x184dd4: 0x80a82d  daddu       $s5, $a0, $zero
    ctx->pc = 0x184dd4u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184dd8: 0xffb70448  sd          $s7, 0x448($sp)
    ctx->pc = 0x184dd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1096), GPR_U64(ctx, 23));
    // 0x184ddc: 0xa0b82d  daddu       $s7, $a1, $zero
    ctx->pc = 0x184ddcu;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184de0: 0xffbe0450  sd          $fp, 0x450($sp)
    ctx->pc = 0x184de0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1104), GPR_U64(ctx, 30));
    // 0x184de4: 0xf02d  daddu       $fp, $zero, $zero
    ctx->pc = 0x184de4u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_184de8:
    // 0x184de8: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x184de8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184dec: 0x3c050028  lui         $a1, 0x28
    ctx->pc = 0x184decu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)40 << 16));
    // 0x184df0: 0x24a56c80  addiu       $a1, $a1, 0x6C80
    ctx->pc = 0x184df0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 27776));
    // 0x184df4: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x184df4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184df8: 0xc061d1e  jal         func_187478
    ctx->pc = 0x184DF8u;
    SET_GPR_U32(ctx, 31, 0x184E00u);
    ctx->pc = 0x184DFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x184DF8u;
            // 0x184dfc: 0x24070001  addiu       $a3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x187478u;
    if (runtime->hasFunction(0x187478u)) {
        auto targetFn = runtime->lookupFunction(0x187478u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184E00u; }
        if (ctx->pc != 0x184E00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187478_0x187478(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184E00u; }
        if (ctx->pc != 0x184E00u) { return; }
    }
    ctx->pc = 0x184E00u;
label_184e00:
    // 0x184e00: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x184E00u;
    {
        const bool branch_taken_0x184e00 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x184E04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184E00u;
            // 0x184e04: 0xa02d  daddu       $s4, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184e00) {
            ctx->pc = 0x184E18u;
            goto label_184e18;
        }
    }
    ctx->pc = 0x184E08u;
    // 0x184e08: 0x8fa40404  lw          $a0, 0x404($sp)
    ctx->pc = 0x184e08u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 1028)));
    // 0x184e0c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x184e0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x184e10: 0x1000010f  b           . + 4 + (0x10F << 2)
    ctx->pc = 0x184E10u;
    {
        const bool branch_taken_0x184e10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x184E14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184E10u;
            // 0x184e14: 0xae640000  sw          $a0, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184e10) {
            ctx->pc = 0x185250u;
            goto label_185250;
        }
    }
    ctx->pc = 0x184E18u;
label_184e18:
    // 0x184e18: 0x3c100028  lui         $s0, 0x28
    ctx->pc = 0x184e18u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)40 << 16));
    // 0x184e1c: 0x26106c80  addiu       $s0, $s0, 0x6C80
    ctx->pc = 0x184e1cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 27776));
    // 0x184e20: 0x3c160024  lui         $s6, 0x24
    ctx->pc = 0x184e20u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)36 << 16));
    // 0x184e24: 0x0  nop
    ctx->pc = 0x184e24u;
    // NOP
label_184e28:
    // 0x184e28: 0x96030000  lhu         $v1, 0x0($s0)
    ctx->pc = 0x184e28u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x184e2c: 0x30620001  andi        $v0, $v1, 0x1
    ctx->pc = 0x184e2cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
    // 0x184e30: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x184e30u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x184e34: 0x50400032  beql        $v0, $zero, . + 4 + (0x32 << 2)
    ctx->pc = 0x184E34u;
    {
        const bool branch_taken_0x184e34 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x184e34) {
            ctx->pc = 0x184E38u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x184E34u;
            // 0x184e38: 0x30628000  andi        $v0, $v1, 0x8000 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)32768);
        ctx->in_delay_slot = false;
            ctx->pc = 0x184F00u;
            goto label_184f00;
        }
    }
    ctx->pc = 0x184E3Cu;
    // 0x184e3c: 0x26040040  addiu       $a0, $s0, 0x40
    ctx->pc = 0x184e3cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 64));
    // 0x184e40: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x184E40u;
    SET_GPR_U32(ctx, 31, 0x184E48u);
    ctx->pc = 0x184E44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x184E40u;
            // 0x184e44: 0x26c517b0  addiu       $a1, $s6, 0x17B0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 22), 6064));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184E48u; }
        if (ctx->pc != 0x184E48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184E48u; }
        if (ctx->pc != 0x184E48u) { return; }
    }
    ctx->pc = 0x184E48u;
label_184e48:
    // 0x184e48: 0x5440002c  bnel        $v0, $zero, . + 4 + (0x2C << 2)
    ctx->pc = 0x184E48u;
    {
        const bool branch_taken_0x184e48 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x184e48) {
            ctx->pc = 0x184E4Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x184E48u;
            // 0x184e4c: 0x96030000  lhu         $v1, 0x0($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x184EFCu;
            goto label_184efc;
        }
    }
    ctx->pc = 0x184E50u;
    // 0x184e50: 0x32020007  andi        $v0, $s0, 0x7
    ctx->pc = 0x184e50u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)7);
    // 0x184e54: 0x27a40200  addiu       $a0, $sp, 0x200
    ctx->pc = 0x184e54u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 512));
    // 0x184e58: 0x10400019  beqz        $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x184E58u;
    {
        const bool branch_taken_0x184e58 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x184E5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184E58u;
            // 0x184e5c: 0x200182d  daddu       $v1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184e58) {
            ctx->pc = 0x184EC0u;
            goto label_184ec0;
        }
    }
    ctx->pc = 0x184E60u;
    // 0x184e60: 0x26020200  addiu       $v0, $s0, 0x200
    ctx->pc = 0x184e60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 512));
label_184e64:
    // 0x184e64: 0x68650007  ldl         $a1, 0x7($v1)
    ctx->pc = 0x184e64u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x184e68: 0x6c650000  ldr         $a1, 0x0($v1)
    ctx->pc = 0x184e68u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x184e6c: 0x6866000f  ldl         $a2, 0xF($v1)
    ctx->pc = 0x184e6cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x184e70: 0x6c660008  ldr         $a2, 0x8($v1)
    ctx->pc = 0x184e70u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x184e74: 0x68670017  ldl         $a3, 0x17($v1)
    ctx->pc = 0x184e74u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem << shift)); }
    // 0x184e78: 0x6c670010  ldr         $a3, 0x10($v1)
    ctx->pc = 0x184e78u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem >> shift)); }
    // 0x184e7c: 0x6868001f  ldl         $t0, 0x1F($v1)
    ctx->pc = 0x184e7cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x184e80: 0x6c680018  ldr         $t0, 0x18($v1)
    ctx->pc = 0x184e80u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x184e84: 0xb0850007  sdl         $a1, 0x7($a0)
    ctx->pc = 0x184e84u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x184e88: 0xb4850000  sdr         $a1, 0x0($a0)
    ctx->pc = 0x184e88u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x184e8c: 0xb086000f  sdl         $a2, 0xF($a0)
    ctx->pc = 0x184e8cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x184e90: 0xb4860008  sdr         $a2, 0x8($a0)
    ctx->pc = 0x184e90u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x184e94: 0xb0870017  sdl         $a3, 0x17($a0)
    ctx->pc = 0x184e94u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x184e98: 0xb4870010  sdr         $a3, 0x10($a0)
    ctx->pc = 0x184e98u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x184e9c: 0xb088001f  sdl         $t0, 0x1F($a0)
    ctx->pc = 0x184e9cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x184ea0: 0xb4880018  sdr         $t0, 0x18($a0)
    ctx->pc = 0x184ea0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x184ea4: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x184ea4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x184ea8: 0x0  nop
    ctx->pc = 0x184ea8u;
    // NOP
    // 0x184eac: 0x0  nop
    ctx->pc = 0x184eacu;
    // NOP
    // 0x184eb0: 0x1462ffec  bne         $v1, $v0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x184EB0u;
    {
        const bool branch_taken_0x184eb0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x184EB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184EB0u;
            // 0x184eb4: 0x24840020  addiu       $a0, $a0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184eb0) {
            ctx->pc = 0x184E64u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_184e64;
        }
    }
    ctx->pc = 0x184EB8u;
    // 0x184eb8: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x184EB8u;
    {
        const bool branch_taken_0x184eb8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x184EBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184EB8u;
            // 0x184ebc: 0x96030000  lhu         $v1, 0x0($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184eb8) {
            ctx->pc = 0x184EFCu;
            goto label_184efc;
        }
    }
    ctx->pc = 0x184EC0u;
label_184ec0:
    // 0x184ec0: 0x26020200  addiu       $v0, $s0, 0x200
    ctx->pc = 0x184ec0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 512));
label_184ec4:
    // 0x184ec4: 0xdc650000  ld          $a1, 0x0($v1)
    ctx->pc = 0x184ec4u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x184ec8: 0xdc660008  ld          $a2, 0x8($v1)
    ctx->pc = 0x184ec8u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x184ecc: 0xdc670010  ld          $a3, 0x10($v1)
    ctx->pc = 0x184eccu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x184ed0: 0xdc680018  ld          $t0, 0x18($v1)
    ctx->pc = 0x184ed0u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x184ed4: 0xfc850000  sd          $a1, 0x0($a0)
    ctx->pc = 0x184ed4u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 0), GPR_U64(ctx, 5));
    // 0x184ed8: 0xfc860008  sd          $a2, 0x8($a0)
    ctx->pc = 0x184ed8u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 8), GPR_U64(ctx, 6));
    // 0x184edc: 0xfc870010  sd          $a3, 0x10($a0)
    ctx->pc = 0x184edcu;
    WRITE64(ADD32(GPR_U32(ctx, 4), 16), GPR_U64(ctx, 7));
    // 0x184ee0: 0xfc880018  sd          $t0, 0x18($a0)
    ctx->pc = 0x184ee0u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 24), GPR_U64(ctx, 8));
    // 0x184ee4: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x184ee4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x184ee8: 0x0  nop
    ctx->pc = 0x184ee8u;
    // NOP
    // 0x184eec: 0x0  nop
    ctx->pc = 0x184eecu;
    // NOP
    // 0x184ef0: 0x1462fff4  bne         $v1, $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x184EF0u;
    {
        const bool branch_taken_0x184ef0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x184EF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184EF0u;
            // 0x184ef4: 0x24840020  addiu       $a0, $a0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184ef0) {
            ctx->pc = 0x184EC4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_184ec4;
        }
    }
    ctx->pc = 0x184EF8u;
    // 0x184ef8: 0x96030000  lhu         $v1, 0x0($s0)
    ctx->pc = 0x184ef8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
label_184efc:
    // 0x184efc: 0x30628000  andi        $v0, $v1, 0x8000
    ctx->pc = 0x184efcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)32768);
label_184f00:
    // 0x184f00: 0x50400004  beql        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x184F00u;
    {
        const bool branch_taken_0x184f00 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x184f00) {
            ctx->pc = 0x184F04u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x184F00u;
            // 0x184f04: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x184F14u;
            goto label_184f14;
        }
    }
    ctx->pc = 0x184F08u;
    // 0x184f08: 0x56400045  bnel        $s2, $zero, . + 4 + (0x45 << 2)
    ctx->pc = 0x184F08u;
    {
        const bool branch_taken_0x184f08 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        if (branch_taken_0x184f08) {
            ctx->pc = 0x184F0Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x184F08u;
            // 0x184f0c: 0x26940001  addiu       $s4, $s4, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x185020u;
            goto label_185020;
        }
    }
    ctx->pc = 0x184F10u;
    // 0x184f10: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x184f10u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_184f14:
    // 0x184f14: 0x2e41025  or          $v0, $s7, $a0
    ctx->pc = 0x184f14u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) | GPR_U64(ctx, 4));
    // 0x184f18: 0x30420007  andi        $v0, $v0, 0x7
    ctx->pc = 0x184f18u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)7);
    // 0x184f1c: 0x1040001a  beqz        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x184F1Cu;
    {
        const bool branch_taken_0x184f1c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x184F20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184F1Cu;
            // 0x184f20: 0x2e0182d  daddu       $v1, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184f1c) {
            ctx->pc = 0x184F88u;
            goto label_184f88;
        }
    }
    ctx->pc = 0x184F24u;
    // 0x184f24: 0x26e20200  addiu       $v0, $s7, 0x200
    ctx->pc = 0x184f24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 23), 512));
label_184f28:
    // 0x184f28: 0x68650007  ldl         $a1, 0x7($v1)
    ctx->pc = 0x184f28u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x184f2c: 0x6c650000  ldr         $a1, 0x0($v1)
    ctx->pc = 0x184f2cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x184f30: 0x6866000f  ldl         $a2, 0xF($v1)
    ctx->pc = 0x184f30u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x184f34: 0x6c660008  ldr         $a2, 0x8($v1)
    ctx->pc = 0x184f34u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x184f38: 0x68670017  ldl         $a3, 0x17($v1)
    ctx->pc = 0x184f38u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem << shift)); }
    // 0x184f3c: 0x6c670010  ldr         $a3, 0x10($v1)
    ctx->pc = 0x184f3cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem >> shift)); }
    // 0x184f40: 0x6868001f  ldl         $t0, 0x1F($v1)
    ctx->pc = 0x184f40u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x184f44: 0x6c680018  ldr         $t0, 0x18($v1)
    ctx->pc = 0x184f44u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x184f48: 0xb0850007  sdl         $a1, 0x7($a0)
    ctx->pc = 0x184f48u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x184f4c: 0xb4850000  sdr         $a1, 0x0($a0)
    ctx->pc = 0x184f4cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x184f50: 0xb086000f  sdl         $a2, 0xF($a0)
    ctx->pc = 0x184f50u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x184f54: 0xb4860008  sdr         $a2, 0x8($a0)
    ctx->pc = 0x184f54u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x184f58: 0xb0870017  sdl         $a3, 0x17($a0)
    ctx->pc = 0x184f58u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x184f5c: 0xb4870010  sdr         $a3, 0x10($a0)
    ctx->pc = 0x184f5cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x184f60: 0xb088001f  sdl         $t0, 0x1F($a0)
    ctx->pc = 0x184f60u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x184f64: 0xb4880018  sdr         $t0, 0x18($a0)
    ctx->pc = 0x184f64u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x184f68: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x184f68u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x184f6c: 0x0  nop
    ctx->pc = 0x184f6cu;
    // NOP
    // 0x184f70: 0x0  nop
    ctx->pc = 0x184f70u;
    // NOP
    // 0x184f74: 0x1462ffec  bne         $v1, $v0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x184F74u;
    {
        const bool branch_taken_0x184f74 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x184F78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184F74u;
            // 0x184f78: 0x24840020  addiu       $a0, $a0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184f74) {
            ctx->pc = 0x184F28u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_184f28;
        }
    }
    ctx->pc = 0x184F7Cu;
    // 0x184f7c: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x184F7Cu;
    {
        const bool branch_taken_0x184f7c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x184F80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184F7Cu;
            // 0x184f80: 0x3c020028  lui         $v0, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)40 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184f7c) {
            ctx->pc = 0x184FC4u;
            goto label_184fc4;
        }
    }
    ctx->pc = 0x184F84u;
    // 0x184f84: 0x0  nop
    ctx->pc = 0x184f84u;
    // NOP
label_184f88:
    // 0x184f88: 0x26e20200  addiu       $v0, $s7, 0x200
    ctx->pc = 0x184f88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 23), 512));
label_184f8c:
    // 0x184f8c: 0xdc650000  ld          $a1, 0x0($v1)
    ctx->pc = 0x184f8cu;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x184f90: 0xdc660008  ld          $a2, 0x8($v1)
    ctx->pc = 0x184f90u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x184f94: 0xdc670010  ld          $a3, 0x10($v1)
    ctx->pc = 0x184f94u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x184f98: 0xdc680018  ld          $t0, 0x18($v1)
    ctx->pc = 0x184f98u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x184f9c: 0xfc850000  sd          $a1, 0x0($a0)
    ctx->pc = 0x184f9cu;
    WRITE64(ADD32(GPR_U32(ctx, 4), 0), GPR_U64(ctx, 5));
    // 0x184fa0: 0xfc860008  sd          $a2, 0x8($a0)
    ctx->pc = 0x184fa0u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 8), GPR_U64(ctx, 6));
    // 0x184fa4: 0xfc870010  sd          $a3, 0x10($a0)
    ctx->pc = 0x184fa4u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 16), GPR_U64(ctx, 7));
    // 0x184fa8: 0xfc880018  sd          $t0, 0x18($a0)
    ctx->pc = 0x184fa8u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 24), GPR_U64(ctx, 8));
    // 0x184fac: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x184facu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x184fb0: 0x0  nop
    ctx->pc = 0x184fb0u;
    // NOP
    // 0x184fb4: 0x0  nop
    ctx->pc = 0x184fb4u;
    // NOP
    // 0x184fb8: 0x1462fff4  bne         $v1, $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x184FB8u;
    {
        const bool branch_taken_0x184fb8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x184FBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184FB8u;
            // 0x184fbc: 0x24840020  addiu       $a0, $a0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184fb8) {
            ctx->pc = 0x184F8Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_184f8c;
        }
    }
    ctx->pc = 0x184FC0u;
    // 0x184fc0: 0x3c020028  lui         $v0, 0x28
    ctx->pc = 0x184fc0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)40 << 16));
label_184fc4:
    // 0x184fc4: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x184fc4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184fc8: 0x24456c80  addiu       $a1, $v0, 0x6C80
    ctx->pc = 0x184fc8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 27776));
    // 0x184fcc: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x184fccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184fd0: 0xc061d24  jal         func_187490
    ctx->pc = 0x184FD0u;
    SET_GPR_U32(ctx, 31, 0x184FD8u);
    ctx->pc = 0x184FD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x184FD0u;
            // 0x184fd4: 0x24070001  addiu       $a3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x187490u;
    if (runtime->hasFunction(0x187490u)) {
        auto targetFn = runtime->lookupFunction(0x187490u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184FD8u; }
        if (ctx->pc != 0x184FD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187490_0x187490(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184FD8u; }
        if (ctx->pc != 0x184FD8u) { return; }
    }
    ctx->pc = 0x184FD8u;
label_184fd8:
    // 0x184fd8: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x184FD8u;
    {
        const bool branch_taken_0x184fd8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x184FDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184FD8u;
            // 0x184fdc: 0x8fa30404  lw          $v1, 0x404($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 1028)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184fd8) {
            ctx->pc = 0x184FF0u;
            goto label_184ff0;
        }
    }
    ctx->pc = 0x184FE0u;
    // 0x184fe0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x184fe0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x184fe4: 0x1000009a  b           . + 4 + (0x9A << 2)
    ctx->pc = 0x184FE4u;
    {
        const bool branch_taken_0x184fe4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x184FE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184FE4u;
            // 0x184fe8: 0xae630000  sw          $v1, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184fe4) {
            ctx->pc = 0x185250u;
            goto label_185250;
        }
    }
    ctx->pc = 0x184FECu;
    // 0x184fec: 0x0  nop
    ctx->pc = 0x184fecu;
    // NOP
label_184ff0:
    // 0x184ff0: 0x56400091  bnel        $s2, $zero, . + 4 + (0x91 << 2)
    ctx->pc = 0x184FF0u;
    {
        const bool branch_taken_0x184ff0 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        if (branch_taken_0x184ff0) {
            ctx->pc = 0x184FF4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x184FF0u;
            // 0x184ff4: 0xae600000  sw          $zero, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x185238u;
            goto label_185238;
        }
    }
    ctx->pc = 0x184FF8u;
    // 0x184ff8: 0x8fa60210  lw          $a2, 0x210($sp)
    ctx->pc = 0x184ff8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 528)));
    // 0x184ffc: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x184ffcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x185000: 0x14c4007a  bne         $a2, $a0, . + 4 + (0x7A << 2)
    ctx->pc = 0x185000u;
    {
        const bool branch_taken_0x185000 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 4));
        ctx->pc = 0x185004u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x185000u;
            // 0x185004: 0x8fa70214  lw          $a3, 0x214($sp) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 532)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x185000) {
            ctx->pc = 0x1851ECu;
            goto label_1851ec;
        }
    }
    ctx->pc = 0x185008u;
    // 0x185008: 0x3c038101  lui         $v1, 0x8101
    ctx->pc = 0x185008u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33025 << 16));
    // 0x18500c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x18500cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x185010: 0x34639002  ori         $v1, $v1, 0x9002
    ctx->pc = 0x185010u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)36866);
    // 0x185014: 0x1000008e  b           . + 4 + (0x8E << 2)
    ctx->pc = 0x185014u;
    {
        const bool branch_taken_0x185014 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x185018u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x185014u;
            // 0x185018: 0xae630000  sw          $v1, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x185014) {
            ctx->pc = 0x185250u;
            goto label_185250;
        }
    }
    ctx->pc = 0x18501Cu;
    // 0x18501c: 0x0  nop
    ctx->pc = 0x18501cu;
    // NOP
label_185020:
    // 0x185020: 0x12102a  slt         $v0, $zero, $s2
    ctx->pc = 0x185020u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x185024: 0x2a830002  slti        $v1, $s4, 0x2
    ctx->pc = 0x185024u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 20) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x185028: 0x2429023  subu        $s2, $s2, $v0
    ctx->pc = 0x185028u;
    SET_GPR_S32(ctx, 18, (int32_t)SUB32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
    // 0x18502c: 0x26100200  addiu       $s0, $s0, 0x200
    ctx->pc = 0x18502cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 512));
    // 0x185030: 0x1460ff7d  bnez        $v1, . + 4 + (-0x83 << 2)
    ctx->pc = 0x185030u;
    {
        const bool branch_taken_0x185030 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x185034u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x185030u;
            // 0x185034: 0x27de0001  addiu       $fp, $fp, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 30), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x185030) {
            ctx->pc = 0x184E28u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_184e28;
        }
    }
    ctx->pc = 0x185038u;
    // 0x185038: 0x8fa50400  lw          $a1, 0x400($sp)
    ctx->pc = 0x185038u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 1024)));
    // 0x18503c: 0x14a0000a  bnez        $a1, . + 4 + (0xA << 2)
    ctx->pc = 0x18503Cu;
    {
        const bool branch_taken_0x18503c = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x185040u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18503Cu;
            // 0x185040: 0x220802d  daddu       $s0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18503c) {
            ctx->pc = 0x185068u;
            goto label_185068;
        }
    }
    ctx->pc = 0x185044u;
    // 0x185044: 0x2bc20014  slti        $v0, $fp, 0x14
    ctx->pc = 0x185044u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 30) < (int64_t)(int32_t)20) ? 1 : 0);
    // 0x185048: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x185048u;
    {
        const bool branch_taken_0x185048 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x18504Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x185048u;
            // 0x18504c: 0x2a0202d  daddu       $a0, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x185048) {
            ctx->pc = 0x18506Cu;
            goto label_18506c;
        }
    }
    ctx->pc = 0x185050u;
    // 0x185050: 0x3c038101  lui         $v1, 0x8101
    ctx->pc = 0x185050u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33025 << 16));
    // 0x185054: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x185054u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x185058: 0x34630017  ori         $v1, $v1, 0x17
    ctx->pc = 0x185058u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)23);
    // 0x18505c: 0x1000007c  b           . + 4 + (0x7C << 2)
    ctx->pc = 0x18505Cu;
    {
        const bool branch_taken_0x18505c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x185060u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18505Cu;
            // 0x185060: 0xae630000  sw          $v1, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18505c) {
            ctx->pc = 0x185250u;
            goto label_185250;
        }
    }
    ctx->pc = 0x185064u;
    // 0x185064: 0x0  nop
    ctx->pc = 0x185064u;
    // NOP
label_185068:
    // 0x185068: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x185068u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
label_18506c:
    // 0x18506c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x18506cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185070: 0xc060b02  jal         func_182C08
    ctx->pc = 0x185070u;
    SET_GPR_U32(ctx, 31, 0x185078u);
    ctx->pc = 0x185074u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x185070u;
            // 0x185074: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182C08u;
    if (runtime->hasFunction(0x182C08u)) {
        auto targetFn = runtime->lookupFunction(0x182C08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185078u; }
        if (ctx->pc != 0x185078u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182C08_0x182c08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185078u; }
        if (ctx->pc != 0x185078u) { return; }
    }
    ctx->pc = 0x185078u;
label_185078:
    // 0x185078: 0x8e630000  lw          $v1, 0x0($s3)
    ctx->pc = 0x185078u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x18507c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x18507cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185080: 0x14600073  bnez        $v1, . + 4 + (0x73 << 2)
    ctx->pc = 0x185080u;
    {
        const bool branch_taken_0x185080 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x185084u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x185080u;
            // 0x185084: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x185080) {
            ctx->pc = 0x185250u;
            goto label_185250;
        }
    }
    ctx->pc = 0x185088u;
    // 0x185088: 0x2406ffff  addiu       $a2, $zero, -0x1
    ctx->pc = 0x185088u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x18508c: 0x5626006c  bnel        $s1, $a2, . + 4 + (0x6C << 2)
    ctx->pc = 0x18508Cu;
    {
        const bool branch_taken_0x18508c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 6));
        if (branch_taken_0x18508c) {
            ctx->pc = 0x185090u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x18508Cu;
            // 0x185090: 0x3c027fff  lui         $v0, 0x7FFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x185240u;
            goto label_185240;
        }
    }
    ctx->pc = 0x185094u;
    // 0x185094: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x185094u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185098: 0xc060b7a  jal         func_182DE8
    ctx->pc = 0x185098u;
    SET_GPR_U32(ctx, 31, 0x1850A0u);
    ctx->pc = 0x18509Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x185098u;
            // 0x18509c: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182DE8u;
    if (runtime->hasFunction(0x182DE8u)) {
        auto targetFn = runtime->lookupFunction(0x182DE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1850A0u; }
        if (ctx->pc != 0x1850A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182DE8_0x182de8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1850A0u; }
        if (ctx->pc != 0x1850A0u) { return; }
    }
    ctx->pc = 0x1850A0u;
label_1850a0:
    // 0x1850a0: 0x8e630000  lw          $v1, 0x0($s3)
    ctx->pc = 0x1850a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1850a4: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x1850a4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1850a8: 0x14600069  bnez        $v1, . + 4 + (0x69 << 2)
    ctx->pc = 0x1850A8u;
    {
        const bool branch_taken_0x1850a8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1850ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1850A8u;
            // 0x1850ac: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1850a8) {
            ctx->pc = 0x185250u;
            goto label_185250;
        }
    }
    ctx->pc = 0x1850B0u;
    // 0x1850b0: 0x3c068000  lui         $a2, 0x8000
    ctx->pc = 0x1850b0u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)32768 << 16));
    // 0x1850b4: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1850b4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1850b8: 0x2263025  or          $a2, $s1, $a2
    ctx->pc = 0x1850b8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 17) | GPR_U64(ctx, 6));
    // 0x1850bc: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x1850bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1850c0: 0xc060b28  jal         func_182CA0
    ctx->pc = 0x1850C0u;
    SET_GPR_U32(ctx, 31, 0x1850C8u);
    ctx->pc = 0x1850C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1850C0u;
            // 0x1850c4: 0x260382d  daddu       $a3, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182CA0u;
    if (runtime->hasFunction(0x182CA0u)) {
        auto targetFn = runtime->lookupFunction(0x182CA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1850C8u; }
        if (ctx->pc != 0x1850C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182CA0_0x182ca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1850C8u; }
        if (ctx->pc != 0x1850C8u) { return; }
    }
    ctx->pc = 0x1850C8u;
label_1850c8:
    // 0x1850c8: 0x8e630000  lw          $v1, 0x0($s3)
    ctx->pc = 0x1850c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1850cc: 0x14600060  bnez        $v1, . + 4 + (0x60 << 2)
    ctx->pc = 0x1850CCu;
    {
        const bool branch_taken_0x1850cc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1850D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1850CCu;
            // 0x1850d0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1850cc) {
            ctx->pc = 0x185250u;
            goto label_185250;
        }
    }
    ctx->pc = 0x1850D4u;
    // 0x1850d4: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x1850d4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1850d8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1850d8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1850dc: 0x2406ffff  addiu       $a2, $zero, -0x1
    ctx->pc = 0x1850dcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1850e0: 0xc060b28  jal         func_182CA0
    ctx->pc = 0x1850E0u;
    SET_GPR_U32(ctx, 31, 0x1850E8u);
    ctx->pc = 0x1850E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1850E0u;
            // 0x1850e4: 0x260382d  daddu       $a3, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182CA0u;
    if (runtime->hasFunction(0x182CA0u)) {
        auto targetFn = runtime->lookupFunction(0x182CA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1850E8u; }
        if (ctx->pc != 0x1850E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182CA0_0x182ca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1850E8u; }
        if (ctx->pc != 0x1850E8u) { return; }
    }
    ctx->pc = 0x1850E8u;
label_1850e8:
    // 0x1850e8: 0x8e630000  lw          $v1, 0x0($s3)
    ctx->pc = 0x1850e8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1850ec: 0x14600058  bnez        $v1, . + 4 + (0x58 << 2)
    ctx->pc = 0x1850ECu;
    {
        const bool branch_taken_0x1850ec = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1850F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1850ECu;
            // 0x1850f0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1850ec) {
            ctx->pc = 0x185250u;
            goto label_185250;
        }
    }
    ctx->pc = 0x1850F4u;
    // 0x1850f4: 0x3c070028  lui         $a3, 0x28
    ctx->pc = 0x1850f4u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)40 << 16));
    // 0x1850f8: 0x2e0282d  daddu       $a1, $s7, $zero
    ctx->pc = 0x1850f8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1850fc: 0x24f06c80  addiu       $s0, $a3, 0x6C80
    ctx->pc = 0x1850fcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 7), 27776));
    // 0x185100: 0xb01025  or          $v0, $a1, $s0
    ctx->pc = 0x185100u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) | GPR_U64(ctx, 16));
    // 0x185104: 0x30420007  andi        $v0, $v0, 0x7
    ctx->pc = 0x185104u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)7);
    // 0x185108: 0x10400019  beqz        $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x185108u;
    {
        const bool branch_taken_0x185108 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x18510Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x185108u;
            // 0x18510c: 0x200182d  daddu       $v1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x185108) {
            ctx->pc = 0x185170u;
            goto label_185170;
        }
    }
    ctx->pc = 0x185110u;
    // 0x185110: 0x24a20200  addiu       $v0, $a1, 0x200
    ctx->pc = 0x185110u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 512));
label_185114:
    // 0x185114: 0x68a80007  ldl         $t0, 0x7($a1)
    ctx->pc = 0x185114u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x185118: 0x6ca80000  ldr         $t0, 0x0($a1)
    ctx->pc = 0x185118u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x18511c: 0x68a4000f  ldl         $a0, 0xF($a1)
    ctx->pc = 0x18511cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x185120: 0x6ca40008  ldr         $a0, 0x8($a1)
    ctx->pc = 0x185120u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x185124: 0x68a60017  ldl         $a2, 0x17($a1)
    ctx->pc = 0x185124u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x185128: 0x6ca60010  ldr         $a2, 0x10($a1)
    ctx->pc = 0x185128u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x18512c: 0x68a7001f  ldl         $a3, 0x1F($a1)
    ctx->pc = 0x18512cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem << shift)); }
    // 0x185130: 0x6ca70018  ldr         $a3, 0x18($a1)
    ctx->pc = 0x185130u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem >> shift)); }
    // 0x185134: 0xb0680007  sdl         $t0, 0x7($v1)
    ctx->pc = 0x185134u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x185138: 0xb4680000  sdr         $t0, 0x0($v1)
    ctx->pc = 0x185138u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x18513c: 0xb064000f  sdl         $a0, 0xF($v1)
    ctx->pc = 0x18513cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x185140: 0xb4640008  sdr         $a0, 0x8($v1)
    ctx->pc = 0x185140u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x185144: 0xb0660017  sdl         $a2, 0x17($v1)
    ctx->pc = 0x185144u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x185148: 0xb4660010  sdr         $a2, 0x10($v1)
    ctx->pc = 0x185148u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x18514c: 0xb067001f  sdl         $a3, 0x1F($v1)
    ctx->pc = 0x18514cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x185150: 0xb4670018  sdr         $a3, 0x18($v1)
    ctx->pc = 0x185150u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x185154: 0x24a50020  addiu       $a1, $a1, 0x20
    ctx->pc = 0x185154u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 32));
    // 0x185158: 0x0  nop
    ctx->pc = 0x185158u;
    // NOP
    // 0x18515c: 0x0  nop
    ctx->pc = 0x18515cu;
    // NOP
    // 0x185160: 0x14a2ffec  bne         $a1, $v0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x185160u;
    {
        const bool branch_taken_0x185160 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        ctx->pc = 0x185164u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x185160u;
            // 0x185164: 0x24630020  addiu       $v1, $v1, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x185160) {
            ctx->pc = 0x185114u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_185114;
        }
    }
    ctx->pc = 0x185168u;
    // 0x185168: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x185168u;
    {
        const bool branch_taken_0x185168 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18516Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x185168u;
            // 0x18516c: 0x3c080028  lui         $t0, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)40 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x185168) {
            ctx->pc = 0x1851ACu;
            goto label_1851ac;
        }
    }
    ctx->pc = 0x185170u;
label_185170:
    // 0x185170: 0x24a20200  addiu       $v0, $a1, 0x200
    ctx->pc = 0x185170u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 512));
label_185174:
    // 0x185174: 0xdca80000  ld          $t0, 0x0($a1)
    ctx->pc = 0x185174u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x185178: 0xdca40008  ld          $a0, 0x8($a1)
    ctx->pc = 0x185178u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x18517c: 0xdca60010  ld          $a2, 0x10($a1)
    ctx->pc = 0x18517cu;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x185180: 0xdca70018  ld          $a3, 0x18($a1)
    ctx->pc = 0x185180u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 5), 24)));
    // 0x185184: 0xfc680000  sd          $t0, 0x0($v1)
    ctx->pc = 0x185184u;
    WRITE64(ADD32(GPR_U32(ctx, 3), 0), GPR_U64(ctx, 8));
    // 0x185188: 0xfc640008  sd          $a0, 0x8($v1)
    ctx->pc = 0x185188u;
    WRITE64(ADD32(GPR_U32(ctx, 3), 8), GPR_U64(ctx, 4));
    // 0x18518c: 0xfc660010  sd          $a2, 0x10($v1)
    ctx->pc = 0x18518cu;
    WRITE64(ADD32(GPR_U32(ctx, 3), 16), GPR_U64(ctx, 6));
    // 0x185190: 0xfc670018  sd          $a3, 0x18($v1)
    ctx->pc = 0x185190u;
    WRITE64(ADD32(GPR_U32(ctx, 3), 24), GPR_U64(ctx, 7));
    // 0x185194: 0x24a50020  addiu       $a1, $a1, 0x20
    ctx->pc = 0x185194u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 32));
    // 0x185198: 0x0  nop
    ctx->pc = 0x185198u;
    // NOP
    // 0x18519c: 0x0  nop
    ctx->pc = 0x18519cu;
    // NOP
    // 0x1851a0: 0x14a2fff4  bne         $a1, $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x1851A0u;
    {
        const bool branch_taken_0x1851a0 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        ctx->pc = 0x1851A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1851A0u;
            // 0x1851a4: 0x24630020  addiu       $v1, $v1, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1851a0) {
            ctx->pc = 0x185174u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_185174;
        }
    }
    ctx->pc = 0x1851A8u;
    // 0x1851a8: 0x3c080028  lui         $t0, 0x28
    ctx->pc = 0x1851a8u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)40 << 16));
label_1851ac:
    // 0x1851ac: 0xa6000200  sh          $zero, 0x200($s0)
    ctx->pc = 0x1851acu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 512), (uint16_t)GPR_U32(ctx, 0));
    // 0x1851b0: 0x25056c80  addiu       $a1, $t0, 0x6C80
    ctx->pc = 0x1851b0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 8), 27776));
    // 0x1851b4: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1851b4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1851b8: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x1851b8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1851bc: 0xc061d24  jal         func_187490
    ctx->pc = 0x1851BCu;
    SET_GPR_U32(ctx, 31, 0x1851C4u);
    ctx->pc = 0x1851C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1851BCu;
            // 0x1851c0: 0x24070001  addiu       $a3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x187490u;
    if (runtime->hasFunction(0x187490u)) {
        auto targetFn = runtime->lookupFunction(0x187490u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1851C4u; }
        if (ctx->pc != 0x1851C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187490_0x187490(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1851C4u; }
        if (ctx->pc != 0x1851C4u) { return; }
    }
    ctx->pc = 0x1851C4u;
label_1851c4:
    // 0x1851c4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1851C4u;
    {
        const bool branch_taken_0x1851c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1851C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1851C4u;
            // 0x1851c8: 0x8fa60210  lw          $a2, 0x210($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 528)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1851c4) {
            ctx->pc = 0x1851D8u;
            goto label_1851d8;
        }
    }
    ctx->pc = 0x1851CCu;
    // 0x1851cc: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x1851CCu;
    {
        const bool branch_taken_0x1851cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1851D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1851CCu;
            // 0x1851d0: 0x8fa20404  lw          $v0, 0x404($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 1028)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1851cc) {
            ctx->pc = 0x185228u;
            goto label_185228;
        }
    }
    ctx->pc = 0x1851D4u;
    // 0x1851d4: 0x0  nop
    ctx->pc = 0x1851d4u;
    // NOP
label_1851d8:
    // 0x1851d8: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1851d8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x1851dc: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1851dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1851e0: 0x10c3001b  beq         $a2, $v1, . + 4 + (0x1B << 2)
    ctx->pc = 0x1851E0u;
    {
        const bool branch_taken_0x1851e0 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 3));
        ctx->pc = 0x1851E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1851E0u;
            // 0x1851e4: 0x34429002  ori         $v0, $v0, 0x9002 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)36866);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1851e0) {
            ctx->pc = 0x185250u;
            goto label_185250;
        }
    }
    ctx->pc = 0x1851E8u;
    // 0x1851e8: 0x8fa70214  lw          $a3, 0x214($sp)
    ctx->pc = 0x1851e8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 532)));
label_1851ec:
    // 0x1851ec: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x1851ecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1851f0: 0xc060c02  jal         func_183008
    ctx->pc = 0x1851F0u;
    SET_GPR_U32(ctx, 31, 0x1851F8u);
    ctx->pc = 0x1851F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1851F0u;
            // 0x1851f4: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x183008u;
    if (runtime->hasFunction(0x183008u)) {
        auto targetFn = runtime->lookupFunction(0x183008u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1851F8u; }
        if (ctx->pc != 0x1851F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00183008_0x183008(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1851F8u; }
        if (ctx->pc != 0x1851F8u) { return; }
    }
    ctx->pc = 0x1851F8u;
label_1851f8:
    // 0x1851f8: 0x5440000c  bnel        $v0, $zero, . + 4 + (0xC << 2)
    ctx->pc = 0x1851F8u;
    {
        const bool branch_taken_0x1851f8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1851f8) {
            ctx->pc = 0x1851FCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1851F8u;
            // 0x1851fc: 0xae620000  sw          $v0, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x18522Cu;
            goto label_18522c;
        }
    }
    ctx->pc = 0x185200u;
    // 0x185200: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x185200u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x185204: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x185204u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185208: 0x8fa60210  lw          $a2, 0x210($sp)
    ctx->pc = 0x185208u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 528)));
    // 0x18520c: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x18520cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185210: 0x8fa70214  lw          $a3, 0x214($sp)
    ctx->pc = 0x185210u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 532)));
    // 0x185214: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x185214u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x185218: 0xc0612a8  jal         func_184AA0
    ctx->pc = 0x185218u;
    SET_GPR_U32(ctx, 31, 0x185220u);
    ctx->pc = 0x18521Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x185218u;
            // 0x18521c: 0xafa20004  sw          $v0, 0x4($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x184AA0u;
    if (runtime->hasFunction(0x184AA0u)) {
        auto targetFn = runtime->lookupFunction(0x184AA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185220u; }
        if (ctx->pc != 0x185220u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00184AA0_0x184aa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185220u; }
        if (ctx->pc != 0x185220u) { return; }
    }
    ctx->pc = 0x185220u;
label_185220:
    // 0x185220: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x185220u;
    {
        const bool branch_taken_0x185220 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x185220) {
            ctx->pc = 0x185224u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x185220u;
            // 0x185224: 0xae600000  sw          $zero, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x185238u;
            goto label_185238;
        }
    }
    ctx->pc = 0x185228u;
label_185228:
    // 0x185228: 0xae620000  sw          $v0, 0x0($s3)
    ctx->pc = 0x185228u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
label_18522c:
    // 0x18522c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x18522Cu;
    {
        const bool branch_taken_0x18522c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x185230u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18522Cu;
            // 0x185230: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18522c) {
            ctx->pc = 0x185250u;
            goto label_185250;
        }
    }
    ctx->pc = 0x185234u;
    // 0x185234: 0x0  nop
    ctx->pc = 0x185234u;
    // NOP
label_185238:
    // 0x185238: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x185238u;
    {
        const bool branch_taken_0x185238 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18523Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x185238u;
            // 0x18523c: 0x3c0102d  daddu       $v0, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x185238) {
            ctx->pc = 0x185250u;
            goto label_185250;
        }
    }
    ctx->pc = 0x185240u;
label_185240:
    // 0x185240: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x185240u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x185244: 0x1000fee8  b           . + 4 + (-0x118 << 2)
    ctx->pc = 0x185244u;
    {
        const bool branch_taken_0x185244 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x185248u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x185244u;
            // 0x185248: 0x2228824  and         $s1, $s1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) & GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x185244) {
            ctx->pc = 0x184DE8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_184de8;
        }
    }
    ctx->pc = 0x18524Cu;
    // 0x18524c: 0x0  nop
    ctx->pc = 0x18524cu;
    // NOP
label_185250:
    // 0x185250: 0xdfb00410  ld          $s0, 0x410($sp)
    ctx->pc = 0x185250u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 1040)));
    // 0x185254: 0xdfb10418  ld          $s1, 0x418($sp)
    ctx->pc = 0x185254u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 1048)));
    // 0x185258: 0xdfb20420  ld          $s2, 0x420($sp)
    ctx->pc = 0x185258u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 1056)));
    // 0x18525c: 0xdfb30428  ld          $s3, 0x428($sp)
    ctx->pc = 0x18525cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 1064)));
    // 0x185260: 0xdfb40430  ld          $s4, 0x430($sp)
    ctx->pc = 0x185260u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 1072)));
    // 0x185264: 0xdfb50438  ld          $s5, 0x438($sp)
    ctx->pc = 0x185264u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 1080)));
    // 0x185268: 0xdfb60440  ld          $s6, 0x440($sp)
    ctx->pc = 0x185268u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 1088)));
    // 0x18526c: 0xdfb70448  ld          $s7, 0x448($sp)
    ctx->pc = 0x18526cu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 1096)));
    // 0x185270: 0xdfbe0450  ld          $fp, 0x450($sp)
    ctx->pc = 0x185270u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 1104)));
    // 0x185274: 0xdfbf0458  ld          $ra, 0x458($sp)
    ctx->pc = 0x185274u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 1112)));
    // 0x185278: 0x3e00008  jr          $ra
    ctx->pc = 0x185278u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18527Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x185278u;
            // 0x18527c: 0x27bd0460  addiu       $sp, $sp, 0x460 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 1120));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x184DE8u: goto label_184de8;
            case 0x184E00u: goto label_184e00;
            case 0x184E18u: goto label_184e18;
            case 0x184E28u: goto label_184e28;
            case 0x184E48u: goto label_184e48;
            case 0x184E64u: goto label_184e64;
            case 0x184EC0u: goto label_184ec0;
            case 0x184EC4u: goto label_184ec4;
            case 0x184EFCu: goto label_184efc;
            case 0x184F00u: goto label_184f00;
            case 0x184F14u: goto label_184f14;
            case 0x184F28u: goto label_184f28;
            case 0x184F88u: goto label_184f88;
            case 0x184F8Cu: goto label_184f8c;
            case 0x184FC4u: goto label_184fc4;
            case 0x184FD8u: goto label_184fd8;
            case 0x184FF0u: goto label_184ff0;
            case 0x185020u: goto label_185020;
            case 0x185068u: goto label_185068;
            case 0x18506Cu: goto label_18506c;
            case 0x185078u: goto label_185078;
            case 0x1850A0u: goto label_1850a0;
            case 0x1850C8u: goto label_1850c8;
            case 0x1850E8u: goto label_1850e8;
            case 0x185114u: goto label_185114;
            case 0x185170u: goto label_185170;
            case 0x185174u: goto label_185174;
            case 0x1851ACu: goto label_1851ac;
            case 0x1851C4u: goto label_1851c4;
            case 0x1851D8u: goto label_1851d8;
            case 0x1851ECu: goto label_1851ec;
            case 0x1851F8u: goto label_1851f8;
            case 0x185220u: goto label_185220;
            case 0x185228u: goto label_185228;
            case 0x18522Cu: goto label_18522c;
            case 0x185238u: goto label_185238;
            case 0x185240u: goto label_185240;
            case 0x185250u: goto label_185250;
            default: break;
        }
        return;
    }
    ctx->pc = 0x185280u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
