#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001348F0
// Address: 0x1348f0 - 0x134b3c
void sub_001348F0_0x1348f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001348F0_0x1348f0");
#endif

    switch (ctx->pc) {
        case 0x134928u: goto label_134928;
        case 0x134938u: goto label_134938;
        case 0x1349a0u: goto label_1349a0;
        case 0x1349d8u: goto label_1349d8;
        case 0x134a00u: goto label_134a00;
        case 0x134a8cu: goto label_134a8c;
        case 0x134aacu: goto label_134aac;
        case 0x134ad4u: goto label_134ad4;
        case 0x134af8u: goto label_134af8;
        case 0x134b14u: goto label_134b14;
        default: break;
    }

    ctx->pc = 0x1348f0u;

    // 0x1348f0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1348f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1348f4: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1348f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1348f8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1348f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1348fc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1348fcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x134900: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x134900u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x134904: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x134904u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x134908: 0x82110001  lb          $s1, 0x1($s0)
    ctx->pc = 0x134908u;
    SET_GPR_S32(ctx, 17, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x13490c: 0x56220029  bnel        $s1, $v0, . + 4 + (0x29 << 2)
    ctx->pc = 0x13490Cu;
    {
        const bool branch_taken_0x13490c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        if (branch_taken_0x13490c) {
            ctx->pc = 0x134910u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13490Cu;
            // 0x134910: 0xa6000068  sh          $zero, 0x68($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 104), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1349B4u;
            goto label_1349b4;
        }
    }
    ctx->pc = 0x134914u;
    // 0x134914: 0x82020072  lb          $v0, 0x72($s0)
    ctx->pc = 0x134914u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 114)));
    // 0x134918: 0x54400026  bnel        $v0, $zero, . + 4 + (0x26 << 2)
    ctx->pc = 0x134918u;
    {
        const bool branch_taken_0x134918 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x134918) {
            ctx->pc = 0x13491Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x134918u;
            // 0x13491c: 0xa6000068  sh          $zero, 0x68($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 104), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1349B4u;
            goto label_1349b4;
        }
    }
    ctx->pc = 0x134920u;
    // 0x134920: 0xc04b2ee  jal         func_12CBB8
    ctx->pc = 0x134920u;
    SET_GPR_U32(ctx, 31, 0x134928u);
    ctx->pc = 0x134924u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134920u;
            // 0x134924: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12CBB8u;
    if (runtime->hasFunction(0x12CBB8u)) {
        auto targetFn = runtime->lookupFunction(0x12CBB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134928u; }
        if (ctx->pc != 0x134928u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012CBB8_0x12cbb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134928u; }
        if (ctx->pc != 0x134928u) { return; }
    }
    ctx->pc = 0x134928u;
label_134928:
    // 0x134928: 0x50510022  beql        $v0, $s1, . + 4 + (0x22 << 2)
    ctx->pc = 0x134928u;
    {
        const bool branch_taken_0x134928 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 17));
        if (branch_taken_0x134928) {
            ctx->pc = 0x13492Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x134928u;
            // 0x13492c: 0xa6000068  sh          $zero, 0x68($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 104), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1349B4u;
            goto label_1349b4;
        }
    }
    ctx->pc = 0x134930u;
    // 0x134930: 0xc04b5b8  jal         func_12D6E0
    ctx->pc = 0x134930u;
    SET_GPR_U32(ctx, 31, 0x134938u);
    ctx->pc = 0x134934u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134930u;
            // 0x134934: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D6E0u;
    if (runtime->hasFunction(0x12D6E0u)) {
        auto targetFn = runtime->lookupFunction(0x12D6E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134938u; }
        if (ctx->pc != 0x134938u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D6E0_0x12d6e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134938u; }
        if (ctx->pc != 0x134938u) { return; }
    }
    ctx->pc = 0x134938u;
label_134938:
    // 0x134938: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x134938u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13493c: 0x8e020064  lw          $v0, 0x64($s0)
    ctx->pc = 0x13493cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 100)));
    // 0x134940: 0x5446000d  bnel        $v0, $a2, . + 4 + (0xD << 2)
    ctx->pc = 0x134940u;
    {
        const bool branch_taken_0x134940 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 6));
        if (branch_taken_0x134940) {
            ctx->pc = 0x134944u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x134940u;
            // 0x134944: 0xa6000068  sh          $zero, 0x68($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 104), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x134978u;
            goto label_134978;
        }
    }
    ctx->pc = 0x134948u;
    // 0x134948: 0x96040068  lhu         $a0, 0x68($s0)
    ctx->pc = 0x134948u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 104)));
    // 0x13494c: 0x8e050038  lw          $a1, 0x38($s0)
    ctx->pc = 0x13494cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x134950: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x134950u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x134954: 0x41c00  sll         $v1, $a0, 16
    ctx->pc = 0x134954u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x134958: 0x51080  sll         $v0, $a1, 2
    ctx->pc = 0x134958u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x13495c: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x13495cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x134960: 0x31c03  sra         $v1, $v1, 16
    ctx->pc = 0x134960u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 16));
    // 0x134964: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x134964u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x134968: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x134968u;
    {
        const bool branch_taken_0x134968 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13496Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134968u;
            // 0x13496c: 0xa6040068  sh          $a0, 0x68($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 104), (uint16_t)GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134968) {
            ctx->pc = 0x134978u;
            goto label_134978;
        }
    }
    ctx->pc = 0x134970u;
    // 0x134970: 0x2402fffe  addiu       $v0, $zero, -0x2
    ctx->pc = 0x134970u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x134974: 0xa6020060  sh          $v0, 0x60($s0)
    ctx->pc = 0x134974u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 96), (uint16_t)GPR_U32(ctx, 2));
label_134978:
    // 0x134978: 0x86020060  lh          $v0, 0x60($s0)
    ctx->pc = 0x134978u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 96)));
    // 0x13497c: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x13497Cu;
    {
        const bool branch_taken_0x13497c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x134980u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13497Cu;
            // 0x134980: 0xae060064  sw          $a2, 0x64($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 100), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13497c) {
            ctx->pc = 0x1349B4u;
            goto label_1349b4;
        }
    }
    ctx->pc = 0x134984u;
    // 0x134984: 0x9203006d  lbu         $v1, 0x6D($s0)
    ctx->pc = 0x134984u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 109)));
    // 0x134988: 0x2462ffff  addiu       $v0, $v1, -0x1
    ctx->pc = 0x134988u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x13498c: 0x2c420002  sltiu       $v0, $v0, 0x2
    ctx->pc = 0x13498cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x134990: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x134990u;
    {
        const bool branch_taken_0x134990 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x134990) {
            ctx->pc = 0x1349A4u;
            goto label_1349a4;
        }
    }
    ctx->pc = 0x134998u;
    // 0x134998: 0xc04c78e  jal         func_131E38
    ctx->pc = 0x134998u;
    SET_GPR_U32(ctx, 31, 0x1349A0u);
    ctx->pc = 0x13499Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134998u;
            // 0x13499c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x131E38u;
    if (runtime->hasFunction(0x131E38u)) {
        auto targetFn = runtime->lookupFunction(0x131E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1349A0u; }
        if (ctx->pc != 0x1349A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131E38_0x131e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1349A0u; }
        if (ctx->pc != 0x1349A0u) { return; }
    }
    ctx->pc = 0x1349A0u;
label_1349a0:
    // 0x1349a0: 0x9203006d  lbu         $v1, 0x6D($s0)
    ctx->pc = 0x1349a0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 109)));
label_1349a4:
    // 0x1349a4: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1349A4u;
    {
        const bool branch_taken_0x1349a4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1349A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1349A4u;
            // 0x1349a8: 0x2622ffff  addiu       $v0, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1349a4) {
            ctx->pc = 0x1349B8u;
            goto label_1349b8;
        }
    }
    ctx->pc = 0x1349ACu;
    // 0x1349ac: 0xa6000060  sh          $zero, 0x60($s0)
    ctx->pc = 0x1349acu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 96), (uint16_t)GPR_U32(ctx, 0));
    // 0x1349b0: 0xa6000068  sh          $zero, 0x68($s0)
    ctx->pc = 0x1349b0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 104), (uint16_t)GPR_U32(ctx, 0));
label_1349b4:
    // 0x1349b4: 0x2622ffff  addiu       $v0, $s1, -0x1
    ctx->pc = 0x1349b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_1349b8:
    // 0x1349b8: 0x2c420003  sltiu       $v0, $v0, 0x3
    ctx->pc = 0x1349b8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)3) ? 1 : 0);
    // 0x1349bc: 0x50400040  beql        $v0, $zero, . + 4 + (0x40 << 2)
    ctx->pc = 0x1349BCu;
    {
        const bool branch_taken_0x1349bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1349bc) {
            ctx->pc = 0x1349C0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1349BCu;
            // 0x1349c0: 0xa600006a  sh          $zero, 0x6A($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 106), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x134AC0u;
            goto label_134ac0;
        }
    }
    ctx->pc = 0x1349C4u;
    // 0x1349c4: 0x82020072  lb          $v0, 0x72($s0)
    ctx->pc = 0x1349c4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 114)));
    // 0x1349c8: 0x5440003d  bnel        $v0, $zero, . + 4 + (0x3D << 2)
    ctx->pc = 0x1349C8u;
    {
        const bool branch_taken_0x1349c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1349c8) {
            ctx->pc = 0x1349CCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1349C8u;
            // 0x1349cc: 0xa600006a  sh          $zero, 0x6A($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 106), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x134AC0u;
            goto label_134ac0;
        }
    }
    ctx->pc = 0x1349D0u;
    // 0x1349d0: 0xc04b2ee  jal         func_12CBB8
    ctx->pc = 0x1349D0u;
    SET_GPR_U32(ctx, 31, 0x1349D8u);
    ctx->pc = 0x1349D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1349D0u;
            // 0x1349d4: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12CBB8u;
    if (runtime->hasFunction(0x12CBB8u)) {
        auto targetFn = runtime->lookupFunction(0x12CBB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1349D8u; }
        if (ctx->pc != 0x1349D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012CBB8_0x12cbb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1349D8u; }
        if (ctx->pc != 0x1349D8u) { return; }
    }
    ctx->pc = 0x1349D8u;
label_1349d8:
    // 0x1349d8: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1349d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1349dc: 0x50430038  beql        $v0, $v1, . + 4 + (0x38 << 2)
    ctx->pc = 0x1349DCu;
    {
        const bool branch_taken_0x1349dc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1349dc) {
            ctx->pc = 0x1349E0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1349DCu;
            // 0x1349e0: 0xa600006a  sh          $zero, 0x6A($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 106), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x134AC0u;
            goto label_134ac0;
        }
    }
    ctx->pc = 0x1349E4u;
    // 0x1349e4: 0x8e040014  lw          $a0, 0x14($s0)
    ctx->pc = 0x1349e4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1349e8: 0x10800007  beqz        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1349E8u;
    {
        const bool branch_taken_0x1349e8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1349ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1349E8u;
            // 0x1349ec: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1349e8) {
            ctx->pc = 0x134A08u;
            goto label_134a08;
        }
    }
    ctx->pc = 0x1349F0u;
    // 0x1349f0: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1349f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1349f4: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x1349f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x1349f8: 0x40f809  jalr        $v0
    ctx->pc = 0x1349F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x134A00u);
        ctx->pc = 0x1349FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1349F8u;
            // 0x1349fc: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x134A00u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x134928u: goto label_134928;
            case 0x134938u: goto label_134938;
            case 0x134978u: goto label_134978;
            case 0x1349A0u: goto label_1349a0;
            case 0x1349A4u: goto label_1349a4;
            case 0x1349B4u: goto label_1349b4;
            case 0x1349B8u: goto label_1349b8;
            case 0x1349D8u: goto label_1349d8;
            case 0x134A00u: goto label_134a00;
            case 0x134A08u: goto label_134a08;
            case 0x134A0Cu: goto label_134a0c;
            case 0x134A40u: goto label_134a40;
            case 0x134A58u: goto label_134a58;
            case 0x134A70u: goto label_134a70;
            case 0x134A8Cu: goto label_134a8c;
            case 0x134A98u: goto label_134a98;
            case 0x134AACu: goto label_134aac;
            case 0x134AB0u: goto label_134ab0;
            case 0x134AC0u: goto label_134ac0;
            case 0x134AC4u: goto label_134ac4;
            case 0x134AD4u: goto label_134ad4;
            case 0x134AF8u: goto label_134af8;
            case 0x134B00u: goto label_134b00;
            case 0x134B14u: goto label_134b14;
            case 0x134B18u: goto label_134b18;
            case 0x134B2Cu: goto label_134b2c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x134A00u; }
            if (ctx->pc != 0x134A00u) { return; }
        }
        }
    }
    ctx->pc = 0x134A00u;
label_134a00:
    // 0x134a00: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x134A00u;
    {
        const bool branch_taken_0x134a00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x134A04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134A00u;
            // 0x134a04: 0x28420040  slti        $v0, $v0, 0x40 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)64) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x134a00) {
            ctx->pc = 0x134A0Cu;
            goto label_134a0c;
        }
    }
    ctx->pc = 0x134A08u;
label_134a08:
    // 0x134a08: 0x28420040  slti        $v0, $v0, 0x40
    ctx->pc = 0x134a08u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)64) ? 1 : 0);
label_134a0c:
    // 0x134a0c: 0x5040002c  beql        $v0, $zero, . + 4 + (0x2C << 2)
    ctx->pc = 0x134A0Cu;
    {
        const bool branch_taken_0x134a0c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x134a0c) {
            ctx->pc = 0x134A10u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x134A0Cu;
            // 0x134a10: 0xa600006a  sh          $zero, 0x6A($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 106), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x134AC0u;
            goto label_134ac0;
        }
    }
    ctx->pc = 0x134A14u;
    // 0x134a14: 0x9602006a  lhu         $v0, 0x6A($s0)
    ctx->pc = 0x134a14u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 106)));
    // 0x134a18: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x134a18u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x134a1c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x134a1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x134a20: 0x16230007  bne         $s1, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x134A20u;
    {
        const bool branch_taken_0x134a20 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 3));
        ctx->pc = 0x134A24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134A20u;
            // 0x134a24: 0xa602006a  sh          $v0, 0x6A($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 106), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134a20) {
            ctx->pc = 0x134A40u;
            goto label_134a40;
        }
    }
    ctx->pc = 0x134A28u;
    // 0x134a28: 0x8e040038  lw          $a0, 0x38($s0)
    ctx->pc = 0x134a28u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x134a2c: 0x21c00  sll         $v1, $v0, 16
    ctx->pc = 0x134a2cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x134a30: 0x31c03  sra         $v1, $v1, 16
    ctx->pc = 0x134a30u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 16));
    // 0x134a34: 0x41080  sll         $v0, $a0, 2
    ctx->pc = 0x134a34u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x134a38: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x134A38u;
    {
        const bool branch_taken_0x134a38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x134A3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134A38u;
            // 0x134a3c: 0x441021  addu        $v0, $v0, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134a38) {
            ctx->pc = 0x134A58u;
            goto label_134a58;
        }
    }
    ctx->pc = 0x134A40u;
label_134a40:
    // 0x134a40: 0x8e040038  lw          $a0, 0x38($s0)
    ctx->pc = 0x134a40u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x134a44: 0x21c00  sll         $v1, $v0, 16
    ctx->pc = 0x134a44u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x134a48: 0x31c03  sra         $v1, $v1, 16
    ctx->pc = 0x134a48u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 16));
    // 0x134a4c: 0x41080  sll         $v0, $a0, 2
    ctx->pc = 0x134a4cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x134a50: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x134a50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x134a54: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x134a54u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
label_134a58:
    // 0x134a58: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x134a58u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x134a5c: 0x50400004  beql        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x134A5Cu;
    {
        const bool branch_taken_0x134a5c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x134a5c) {
            ctx->pc = 0x134A60u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x134A5Cu;
            // 0x134a60: 0x86020060  lh          $v0, 0x60($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 96)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x134A70u;
            goto label_134a70;
        }
    }
    ctx->pc = 0x134A64u;
    // 0x134a64: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x134a64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x134a68: 0xa6020060  sh          $v0, 0x60($s0)
    ctx->pc = 0x134a68u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 96), (uint16_t)GPR_U32(ctx, 2));
    // 0x134a6c: 0x86020060  lh          $v0, 0x60($s0)
    ctx->pc = 0x134a6cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 96)));
label_134a70:
    // 0x134a70: 0x10400013  beqz        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x134A70u;
    {
        const bool branch_taken_0x134a70 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x134A74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134A70u;
            // 0x134a74: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134a70) {
            ctx->pc = 0x134AC0u;
            goto label_134ac0;
        }
    }
    ctx->pc = 0x134A78u;
    // 0x134a78: 0x8204006d  lb          $a0, 0x6D($s0)
    ctx->pc = 0x134a78u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 109)));
    // 0x134a7c: 0x14820006  bne         $a0, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x134A7Cu;
    {
        const bool branch_taken_0x134a7c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        ctx->pc = 0x134A80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134A7Cu;
            // 0x134a80: 0x9203006d  lbu         $v1, 0x6D($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 109)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134a7c) {
            ctx->pc = 0x134A98u;
            goto label_134a98;
        }
    }
    ctx->pc = 0x134A84u;
    // 0x134a84: 0xc04c78e  jal         func_131E38
    ctx->pc = 0x134A84u;
    SET_GPR_U32(ctx, 31, 0x134A8Cu);
    ctx->pc = 0x134A88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134A84u;
            // 0x134a88: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x131E38u;
    if (runtime->hasFunction(0x131E38u)) {
        auto targetFn = runtime->lookupFunction(0x131E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134A8Cu; }
        if (ctx->pc != 0x134A8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131E38_0x131e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134A8Cu; }
        if (ctx->pc != 0x134A8Cu) { return; }
    }
    ctx->pc = 0x134A8Cu;
label_134a8c:
    // 0x134a8c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x134A8Cu;
    {
        const bool branch_taken_0x134a8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x134A90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134A8Cu;
            // 0x134a90: 0x9203006d  lbu         $v1, 0x6D($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 109)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134a8c) {
            ctx->pc = 0x134AB0u;
            goto label_134ab0;
        }
    }
    ctx->pc = 0x134A94u;
    // 0x134a94: 0x0  nop
    ctx->pc = 0x134a94u;
    // NOP
label_134a98:
    // 0x134a98: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x134a98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x134a9c: 0x14820004  bne         $a0, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x134A9Cu;
    {
        const bool branch_taken_0x134a9c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x134a9c) {
            ctx->pc = 0x134AB0u;
            goto label_134ab0;
        }
    }
    ctx->pc = 0x134AA4u;
    // 0x134aa4: 0xc04d200  jal         func_134800
    ctx->pc = 0x134AA4u;
    SET_GPR_U32(ctx, 31, 0x134AACu);
    ctx->pc = 0x134AA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134AA4u;
            // 0x134aa8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134800u;
    if (runtime->hasFunction(0x134800u)) {
        auto targetFn = runtime->lookupFunction(0x134800u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134AACu; }
        if (ctx->pc != 0x134AACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134800_0x134800(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134AACu; }
        if (ctx->pc != 0x134AACu) { return; }
    }
    ctx->pc = 0x134AACu;
label_134aac:
    // 0x134aac: 0x9203006d  lbu         $v1, 0x6D($s0)
    ctx->pc = 0x134aacu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 109)));
label_134ab0:
    // 0x134ab0: 0x50600004  beql        $v1, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x134AB0u;
    {
        const bool branch_taken_0x134ab0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x134ab0) {
            ctx->pc = 0x134AB4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x134AB0u;
            // 0x134ab4: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x134AC4u;
            goto label_134ac4;
        }
    }
    ctx->pc = 0x134AB8u;
    // 0x134ab8: 0xa6000060  sh          $zero, 0x60($s0)
    ctx->pc = 0x134ab8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 96), (uint16_t)GPR_U32(ctx, 0));
    // 0x134abc: 0xa600006a  sh          $zero, 0x6A($s0)
    ctx->pc = 0x134abcu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 106), (uint16_t)GPR_U32(ctx, 0));
label_134ac0:
    // 0x134ac0: 0x8e040008  lw          $a0, 0x8($s0)
    ctx->pc = 0x134ac0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
label_134ac4:
    // 0x134ac4: 0x50800019  beql        $a0, $zero, . + 4 + (0x19 << 2)
    ctx->pc = 0x134AC4u;
    {
        const bool branch_taken_0x134ac4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x134ac4) {
            ctx->pc = 0x134AC8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x134AC4u;
            // 0x134ac8: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x134B2Cu;
            goto label_134b2c;
        }
    }
    ctx->pc = 0x134ACCu;
    // 0x134acc: 0xc04c16e  jal         func_1305B8
    ctx->pc = 0x134ACCu;
    SET_GPR_U32(ctx, 31, 0x134AD4u);
    ctx->pc = 0x1305B8u;
    if (runtime->hasFunction(0x1305B8u)) {
        auto targetFn = runtime->lookupFunction(0x1305B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134AD4u; }
        if (ctx->pc != 0x134AD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001305B8_0x1305b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134AD4u; }
        if (ctx->pc != 0x134AD4u) { return; }
    }
    ctx->pc = 0x134AD4u;
label_134ad4:
    // 0x134ad4: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x134ad4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x134ad8: 0x54430014  bnel        $v0, $v1, . + 4 + (0x14 << 2)
    ctx->pc = 0x134AD8u;
    {
        const bool branch_taken_0x134ad8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x134ad8) {
            ctx->pc = 0x134ADCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x134AD8u;
            // 0x134adc: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x134B2Cu;
            goto label_134b2c;
        }
    }
    ctx->pc = 0x134AE0u;
    // 0x134ae0: 0x8204006d  lb          $a0, 0x6D($s0)
    ctx->pc = 0x134ae0u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 109)));
    // 0x134ae4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x134ae4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x134ae8: 0x14820005  bne         $a0, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x134AE8u;
    {
        const bool branch_taken_0x134ae8 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        ctx->pc = 0x134AECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134AE8u;
            // 0x134aec: 0x9203006d  lbu         $v1, 0x6D($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 109)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134ae8) {
            ctx->pc = 0x134B00u;
            goto label_134b00;
        }
    }
    ctx->pc = 0x134AF0u;
    // 0x134af0: 0xc04c78e  jal         func_131E38
    ctx->pc = 0x134AF0u;
    SET_GPR_U32(ctx, 31, 0x134AF8u);
    ctx->pc = 0x134AF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134AF0u;
            // 0x134af4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x131E38u;
    if (runtime->hasFunction(0x131E38u)) {
        auto targetFn = runtime->lookupFunction(0x131E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134AF8u; }
        if (ctx->pc != 0x134AF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131E38_0x131e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134AF8u; }
        if (ctx->pc != 0x134AF8u) { return; }
    }
    ctx->pc = 0x134AF8u;
label_134af8:
    // 0x134af8: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x134AF8u;
    {
        const bool branch_taken_0x134af8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x134AFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134AF8u;
            // 0x134afc: 0x9203006d  lbu         $v1, 0x6D($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 109)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134af8) {
            ctx->pc = 0x134B18u;
            goto label_134b18;
        }
    }
    ctx->pc = 0x134B00u;
label_134b00:
    // 0x134b00: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x134b00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x134b04: 0x14820004  bne         $a0, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x134B04u;
    {
        const bool branch_taken_0x134b04 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x134b04) {
            ctx->pc = 0x134B18u;
            goto label_134b18;
        }
    }
    ctx->pc = 0x134B0Cu;
    // 0x134b0c: 0xc04d200  jal         func_134800
    ctx->pc = 0x134B0Cu;
    SET_GPR_U32(ctx, 31, 0x134B14u);
    ctx->pc = 0x134B10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134B0Cu;
            // 0x134b10: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134800u;
    if (runtime->hasFunction(0x134800u)) {
        auto targetFn = runtime->lookupFunction(0x134800u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134B14u; }
        if (ctx->pc != 0x134B14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134800_0x134800(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x134B14u; }
        if (ctx->pc != 0x134B14u) { return; }
    }
    ctx->pc = 0x134B14u;
label_134b14:
    // 0x134b14: 0x9203006d  lbu         $v1, 0x6D($s0)
    ctx->pc = 0x134b14u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 109)));
label_134b18:
    // 0x134b18: 0x50600004  beql        $v1, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x134B18u;
    {
        const bool branch_taken_0x134b18 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x134b18) {
            ctx->pc = 0x134B1Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x134B18u;
            // 0x134b1c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x134B2Cu;
            goto label_134b2c;
        }
    }
    ctx->pc = 0x134B20u;
    // 0x134b20: 0xa600006a  sh          $zero, 0x6A($s0)
    ctx->pc = 0x134b20u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 106), (uint16_t)GPR_U32(ctx, 0));
    // 0x134b24: 0xa6000060  sh          $zero, 0x60($s0)
    ctx->pc = 0x134b24u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 96), (uint16_t)GPR_U32(ctx, 0));
    // 0x134b28: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x134b28u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_134b2c:
    // 0x134b2c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x134b2cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x134b30: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x134b30u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x134b34: 0x3e00008  jr          $ra
    ctx->pc = 0x134B34u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x134B38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134B34u;
            // 0x134b38: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x134928u: goto label_134928;
            case 0x134938u: goto label_134938;
            case 0x134978u: goto label_134978;
            case 0x1349A0u: goto label_1349a0;
            case 0x1349A4u: goto label_1349a4;
            case 0x1349B4u: goto label_1349b4;
            case 0x1349B8u: goto label_1349b8;
            case 0x1349D8u: goto label_1349d8;
            case 0x134A00u: goto label_134a00;
            case 0x134A08u: goto label_134a08;
            case 0x134A0Cu: goto label_134a0c;
            case 0x134A40u: goto label_134a40;
            case 0x134A58u: goto label_134a58;
            case 0x134A70u: goto label_134a70;
            case 0x134A8Cu: goto label_134a8c;
            case 0x134A98u: goto label_134a98;
            case 0x134AACu: goto label_134aac;
            case 0x134AB0u: goto label_134ab0;
            case 0x134AC0u: goto label_134ac0;
            case 0x134AC4u: goto label_134ac4;
            case 0x134AD4u: goto label_134ad4;
            case 0x134AF8u: goto label_134af8;
            case 0x134B00u: goto label_134b00;
            case 0x134B14u: goto label_134b14;
            case 0x134B18u: goto label_134b18;
            case 0x134B2Cu: goto label_134b2c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x134B3Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
