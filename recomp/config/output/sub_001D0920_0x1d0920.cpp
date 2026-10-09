#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D0920
// Address: 0x1d0920 - 0x1d0a6c
void sub_001D0920_0x1d0920(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D0920_0x1d0920");
#endif

    switch (ctx->pc) {
        case 0x1d0998u: goto label_1d0998;
        case 0x1d09c8u: goto label_1d09c8;
        case 0x1d09d8u: goto label_1d09d8;
        case 0x1d09fcu: goto label_1d09fc;
        case 0x1d0a3cu: goto label_1d0a3c;
        case 0x1d0a4cu: goto label_1d0a4c;
        default: break;
    }

    ctx->pc = 0x1d0920u;

    // 0x1d0920: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1d0920u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1d0924: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0924u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0928: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1d0928u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1d092c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d092cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d0930: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d0930u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d0934: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d0934u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d0938: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x1d0938u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d093c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d093cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d0940: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d0940u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d0944: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1d0944u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0948: 0x84234200  lh          $v1, 0x4200($at)
    ctx->pc = 0x1d0948u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 16896)));
    // 0x1d094c: 0x10620004  beq         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D094Cu;
    {
        const bool branch_taken_0x1d094c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1D0950u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D094Cu;
            // 0x1d0950: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d094c) {
            ctx->pc = 0x1D0960u;
            goto label_1d0960;
        }
    }
    ctx->pc = 0x1D0954u;
    // 0x1d0954: 0x11000003  beqz        $t0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D0954u;
    {
        const bool branch_taken_0x1d0954 = (GPR_U64(ctx, 8) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D0958u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0954u;
            // 0x1d0958: 0x308300ff  andi        $v1, $a0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0954) {
            ctx->pc = 0x1D0964u;
            goto label_1d0964;
        }
    }
    ctx->pc = 0x1D095Cu;
    // 0x1d095c: 0x3c108000  lui         $s0, 0x8000
    ctx->pc = 0x1d095cu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)32768 << 16));
label_1d0960:
    // 0x1d0960: 0x308300ff  andi        $v1, $a0, 0xFF
    ctx->pc = 0x1d0960u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
label_1d0964:
    // 0x1d0964: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d0964u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d0968: 0x1062000e  beq         $v1, $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1D0968u;
    {
        const bool branch_taken_0x1d0968 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1D096Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0968u;
            // 0x1d096c: 0x30c200ff  andi        $v0, $a2, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0968) {
            ctx->pc = 0x1D09A4u;
            goto label_1d09a4;
        }
    }
    ctx->pc = 0x1D0970u;
    // 0x1d0970: 0x30c200ff  andi        $v0, $a2, 0xFF
    ctx->pc = 0x1d0970u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
    // 0x1d0974: 0x3c030038  lui         $v1, 0x38
    ctx->pc = 0x1d0974u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)56 << 16));
    // 0x1d0978: 0x220c0  sll         $a0, $v0, 3
    ctx->pc = 0x1d0978u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1d097c: 0x24637e90  addiu       $v1, $v1, 0x7E90
    ctx->pc = 0x1d097cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32400));
    // 0x1d0980: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1d0980u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1d0984: 0x322200ff  andi        $v0, $s1, 0xFF
    ctx->pc = 0x1d0984u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)255);
    // 0x1d0988: 0x8c720000  lw          $s2, 0x0($v1)
    ctx->pc = 0x1d0988u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1d098c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1d098cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1d0990: 0xc073470  jal         func_1CD1C0
    ctx->pc = 0x1D0990u;
    SET_GPR_U32(ctx, 31, 0x1D0998u);
    ctx->pc = 0x1D0994u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0990u;
            // 0x1d0994: 0x24441200  addiu       $a0, $v0, 0x1200 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 4608));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD1C0u;
    if (runtime->hasFunction(0x1CD1C0u)) {
        auto targetFn = runtime->lookupFunction(0x1CD1C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0998u; }
        if (ctx->pc != 0x1D0998u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD1C0_0x1cd1c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0998u; }
        if (ctx->pc != 0x1D0998u) { return; }
    }
    ctx->pc = 0x1D0998u;
label_1d0998:
    // 0x1d0998: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1D0998u;
    {
        const bool branch_taken_0x1d0998 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d0998) {
            ctx->pc = 0x1D09D0u;
            goto label_1d09d0;
        }
    }
    ctx->pc = 0x1D09A0u;
    // 0x1d09a0: 0x30c200ff  andi        $v0, $a2, 0xFF
    ctx->pc = 0x1d09a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
label_1d09a4:
    // 0x1d09a4: 0x3c030039  lui         $v1, 0x39
    ctx->pc = 0x1d09a4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)57 << 16));
    // 0x1d09a8: 0x220c0  sll         $a0, $v0, 3
    ctx->pc = 0x1d09a8u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1d09ac: 0x246387f0  addiu       $v1, $v1, -0x7810
    ctx->pc = 0x1d09acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294936560));
    // 0x1d09b0: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1d09b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1d09b4: 0x322200ff  andi        $v0, $s1, 0xFF
    ctx->pc = 0x1d09b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)255);
    // 0x1d09b8: 0x8c720000  lw          $s2, 0x0($v1)
    ctx->pc = 0x1d09b8u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1d09bc: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1d09bcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1d09c0: 0xc073470  jal         func_1CD1C0
    ctx->pc = 0x1D09C0u;
    SET_GPR_U32(ctx, 31, 0x1D09C8u);
    ctx->pc = 0x1D09C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D09C0u;
            // 0x1d09c4: 0x24441300  addiu       $a0, $v0, 0x1300 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 4864));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD1C0u;
    if (runtime->hasFunction(0x1CD1C0u)) {
        auto targetFn = runtime->lookupFunction(0x1CD1C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D09C8u; }
        if (ctx->pc != 0x1D09C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD1C0_0x1cd1c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D09C8u; }
        if (ctx->pc != 0x1D09C8u) { return; }
    }
    ctx->pc = 0x1D09C8u;
label_1d09c8:
    // 0x1d09c8: 0x3c022000  lui         $v0, 0x2000
    ctx->pc = 0x1d09c8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
    // 0x1d09cc: 0x2028025  or          $s0, $s0, $v0
    ctx->pc = 0x1d09ccu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
label_1d09d0:
    // 0x1d09d0: 0xc0740e8  jal         func_1D03A0
    ctx->pc = 0x1D09D0u;
    SET_GPR_U32(ctx, 31, 0x1D09D8u);
    ctx->pc = 0x1D03A0u;
    if (runtime->hasFunction(0x1D03A0u)) {
        auto targetFn = runtime->lookupFunction(0x1D03A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D09D8u; }
        if (ctx->pc != 0x1D09D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D03A0_0x1d03a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D09D8u; }
        if (ctx->pc != 0x1D09D8u) { return; }
    }
    ctx->pc = 0x1D09D8u;
label_1d09d8:
    // 0x1d09d8: 0x322300ff  andi        $v1, $s1, 0xFF
    ctx->pc = 0x1d09d8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)255);
    // 0x1d09dc: 0x24021468  addiu       $v0, $zero, 0x1468
    ctx->pc = 0x1d09dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5224));
    // 0x1d09e0: 0x621818  mult        $v1, $v1, $v0
    ctx->pc = 0x1d09e0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1d09e4: 0x24040020  addiu       $a0, $zero, 0x20
    ctx->pc = 0x1d09e4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1d09e8: 0x24050009  addiu       $a1, $zero, 0x9
    ctx->pc = 0x1d09e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1d09ec: 0x3c020046  lui         $v0, 0x46
    ctx->pc = 0x1d09ecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)70 << 16));
    // 0x1d09f0: 0x24429120  addiu       $v0, $v0, -0x6EE0
    ctx->pc = 0x1d09f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294938912));
    // 0x1d09f4: 0xc06ca9c  jal         func_1B2A70
    ctx->pc = 0x1D09F4u;
    SET_GPR_U32(ctx, 31, 0x1D09FCu);
    ctx->pc = 0x1D09F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D09F4u;
            // 0x1d09f8: 0x438821  addu        $s1, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2A70u;
    if (runtime->hasFunction(0x1B2A70u)) {
        auto targetFn = runtime->lookupFunction(0x1B2A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D09FCu; }
        if (ctx->pc != 0x1D09FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2A70_0x1b2a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D09FCu; }
        if (ctx->pc != 0x1D09FCu) { return; }
    }
    ctx->pc = 0x1D09FCu;
label_1d09fc:
    // 0x1d09fc: 0x326300ff  andi        $v1, $s3, 0xFF
    ctx->pc = 0x1d09fcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)255);
    // 0x1d0a00: 0xae220808  sw          $v0, 0x808($s1)
    ctx->pc = 0x1d0a00u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2056), GPR_U32(ctx, 2));
    // 0x1d0a04: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x1d0a04u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1d0a08: 0x36070002  ori         $a3, $s0, 0x2
    ctx->pc = 0x1d0a08u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 16) | (uint64_t)(uint16_t)2);
    // 0x1d0a0c: 0x2431021  addu        $v0, $s2, $v1
    ctx->pc = 0x1d0a0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 3)));
    // 0x1d0a10: 0x26230820  addiu       $v1, $s1, 0x820
    ctx->pc = 0x1d0a10u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 2080));
    // 0x1d0a14: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x1d0a14u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x1d0a18: 0x26230a20  addiu       $v1, $s1, 0xA20
    ctx->pc = 0x1d0a18u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 2592));
    // 0x1d0a1c: 0xae230004  sw          $v1, 0x4($s1)
    ctx->pc = 0x1d0a1cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 3));
    // 0x1d0a20: 0x26230c20  addiu       $v1, $s1, 0xC20
    ctx->pc = 0x1d0a20u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 3104));
    // 0x1d0a24: 0xae230818  sw          $v1, 0x818($s1)
    ctx->pc = 0x1d0a24u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2072), GPR_U32(ctx, 3));
    // 0x1d0a28: 0x90450000  lbu         $a1, 0x0($v0)
    ctx->pc = 0x1d0a28u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1d0a2c: 0x90460001  lbu         $a2, 0x1($v0)
    ctx->pc = 0x1d0a2cu;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1)));
    // 0x1d0a30: 0x90480004  lbu         $t0, 0x4($v0)
    ctx->pc = 0x1d0a30u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1d0a34: 0xc073c24  jal         func_1CF090
    ctx->pc = 0x1D0A34u;
    SET_GPR_U32(ctx, 31, 0x1D0A3Cu);
    ctx->pc = 0x1D0A38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0A34u;
            // 0x1d0a38: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CF090u;
    if (runtime->hasFunction(0x1CF090u)) {
        auto targetFn = runtime->lookupFunction(0x1CF090u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0A3Cu; }
        if (ctx->pc != 0x1D0A3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CF090_0x1cf090(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0A3Cu; }
        if (ctx->pc != 0x1D0A3Cu) { return; }
    }
    ctx->pc = 0x1D0A3Cu;
label_1d0a3c:
    // 0x1d0a3c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D0A3Cu;
    {
        const bool branch_taken_0x1d0a3c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d0a3c) {
            ctx->pc = 0x1D0A50u;
            goto label_1d0a50;
        }
    }
    ctx->pc = 0x1D0A44u;
    // 0x1d0a44: 0xc06cae4  jal         func_1B2B90
    ctx->pc = 0x1D0A44u;
    SET_GPR_U32(ctx, 31, 0x1D0A4Cu);
    ctx->pc = 0x1D0A48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0A44u;
            // 0x1d0a48: 0x8e240808  lw          $a0, 0x808($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 2056)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2B90u;
    if (runtime->hasFunction(0x1B2B90u)) {
        auto targetFn = runtime->lookupFunction(0x1B2B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0A4Cu; }
        if (ctx->pc != 0x1D0A4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2B90_0x1b2b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0A4Cu; }
        if (ctx->pc != 0x1D0A4Cu) { return; }
    }
    ctx->pc = 0x1D0A4Cu;
label_1d0a4c:
    // 0x1d0a4c: 0xae200808  sw          $zero, 0x808($s1)
    ctx->pc = 0x1d0a4cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2056), GPR_U32(ctx, 0));
label_1d0a50:
    // 0x1d0a50: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1d0a50u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d0a54: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d0a54u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d0a58: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d0a58u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d0a5c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d0a5cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d0a60: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d0a60u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d0a64: 0x3e00008  jr          $ra
    ctx->pc = 0x1D0A64u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D0A68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0A64u;
            // 0x1d0a68: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D0960u: goto label_1d0960;
            case 0x1D0964u: goto label_1d0964;
            case 0x1D0998u: goto label_1d0998;
            case 0x1D09A4u: goto label_1d09a4;
            case 0x1D09C8u: goto label_1d09c8;
            case 0x1D09D0u: goto label_1d09d0;
            case 0x1D09D8u: goto label_1d09d8;
            case 0x1D09FCu: goto label_1d09fc;
            case 0x1D0A3Cu: goto label_1d0a3c;
            case 0x1D0A4Cu: goto label_1d0a4c;
            case 0x1D0A50u: goto label_1d0a50;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D0A6Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
