#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011C908
// Address: 0x11c908 - 0x11c9f4
void sub_0011C908_0x11c908(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011C908_0x11c908");
#endif

    switch (ctx->pc) {
        case 0x11c930u: goto label_11c930;
        case 0x11c980u: goto label_11c980;
        default: break;
    }

    ctx->pc = 0x11c908u;

    // 0x11c908: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x11c908u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x11c90c: 0xffb30040  sd          $s3, 0x40($sp)
    ctx->pc = 0x11c90cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 19));
    // 0x11c910: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x11c910u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x11c914: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x11c914u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c918: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x11c918u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x11c91c: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x11c91cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c920: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x11c920u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x11c924: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x11c924u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c928: 0xc046f5e  jal         func_11BD78
    ctx->pc = 0x11C928u;
    SET_GPR_U32(ctx, 31, 0x11C930u);
    ctx->pc = 0x11C92Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11C928u;
            // 0x11c92c: 0xffb10020  sd          $s1, 0x20($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11BD78u;
    if (runtime->hasFunction(0x11BD78u)) {
        auto targetFn = runtime->lookupFunction(0x11BD78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C930u; }
        if (ctx->pc != 0x11C930u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011BD78_0x11bd78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C930u; }
        if (ctx->pc != 0x11C930u) { return; }
    }
    ctx->pc = 0x11C930u;
label_11c930:
    // 0x11c930: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11C930u;
    {
        const bool branch_taken_0x11c930 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x11C934u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C930u;
            // 0x11c934: 0x2e020003  sltiu       $v0, $s0, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)3) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c930) {
            ctx->pc = 0x11C940u;
            goto label_11c940;
        }
    }
    ctx->pc = 0x11C938u;
    // 0x11c938: 0x10000027  b           . + 4 + (0x27 << 2)
    ctx->pc = 0x11C938u;
    {
        const bool branch_taken_0x11c938 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11C93Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C938u;
            // 0x11c93c: 0x3c02ffff  lui         $v0, 0xFFFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c938) {
            ctx->pc = 0x11C9D8u;
            goto label_11c9d8;
        }
    }
    ctx->pc = 0x11C940u;
label_11c940:
    // 0x11c940: 0x10400020  beqz        $v0, . + 4 + (0x20 << 2)
    ctx->pc = 0x11C940u;
    {
        const bool branch_taken_0x11c940 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11C944u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C940u;
            // 0x11c944: 0x3c110026  lui         $s1, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c940) {
            ctx->pc = 0x11C9C4u;
            goto label_11c9c4;
        }
    }
    ctx->pc = 0x11C948u;
    // 0x11c948: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x11c948u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x11c94c: 0x2622e400  addiu       $v0, $s1, -0x1C00
    ctx->pc = 0x11c94cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 4294960128));
    // 0x11c950: 0xae33e400  sw          $s3, -0x1C00($s1)
    ctx->pc = 0x11c950u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4294960128), GPR_U32(ctx, 19));
    // 0x11c954: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x11c954u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c958: 0xac500004  sw          $s0, 0x4($v0)
    ctx->pc = 0x11c958u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x11c95c: 0x2484e600  addiu       $a0, $a0, -0x1A00
    ctx->pc = 0x11c95cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294960640));
    // 0x11c960: 0x24050003  addiu       $a1, $zero, 0x3
    ctx->pc = 0x11c960u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x11c964: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11c964u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11c968: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11c968u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c96c: 0x24080020  addiu       $t0, $zero, 0x20
    ctx->pc = 0x11c96cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x11c970: 0xe0482d  daddu       $t1, $a3, $zero
    ctx->pc = 0x11c970u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c974: 0x240a0020  addiu       $t2, $zero, 0x20
    ctx->pc = 0x11c974u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x11c978: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11C978u;
    SET_GPR_U32(ctx, 31, 0x11C980u);
    ctx->pc = 0x11C97Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11C978u;
            // 0x11c97c: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C980u; }
        if (ctx->pc != 0x11C980u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C980u; }
        if (ctx->pc != 0x11C980u) { return; }
    }
    ctx->pc = 0x11C980u;
label_11c980:
    // 0x11c980: 0x4410004  bgez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11C980u;
    {
        const bool branch_taken_0x11c980 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x11c980) {
            ctx->pc = 0x11C994u;
            goto label_11c994;
        }
    }
    ctx->pc = 0x11C988u;
    // 0x11c988: 0x3c02fffe  lui         $v0, 0xFFFE
    ctx->pc = 0x11c988u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65534 << 16));
    // 0x11c98c: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x11C98Cu;
    {
        const bool branch_taken_0x11c98c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11C990u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C98Cu;
            // 0x11c990: 0x3442ffff  ori         $v0, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c98c) {
            ctx->pc = 0x11C9D8u;
            goto label_11c9d8;
        }
    }
    ctx->pc = 0x11C994u;
label_11c994:
    // 0x11c994: 0x16000004  bnez        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11C994u;
    {
        const bool branch_taken_0x11c994 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x11C998u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C994u;
            // 0x11c998: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c994) {
            ctx->pc = 0x11C9A8u;
            goto label_11c9a8;
        }
    }
    ctx->pc = 0x11C99Cu;
    // 0x11c99c: 0x9222e400  lbu         $v0, -0x1C00($s1)
    ctx->pc = 0x11c99cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 4294960128)));
    // 0x11c9a0: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x11C9A0u;
    {
        const bool branch_taken_0x11c9a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11C9A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C9A0u;
            // 0x11c9a4: 0xa2420000  sb          $v0, 0x0($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c9a0) {
            ctx->pc = 0x11C9D4u;
            goto label_11c9d4;
        }
    }
    ctx->pc = 0x11C9A8u;
label_11c9a8:
    // 0x11c9a8: 0x16020004  bne         $s0, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11C9A8u;
    {
        const bool branch_taken_0x11c9a8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        ctx->pc = 0x11C9ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C9A8u;
            // 0x11c9ac: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c9a8) {
            ctx->pc = 0x11C9BCu;
            goto label_11c9bc;
        }
    }
    ctx->pc = 0x11C9B0u;
    // 0x11c9b0: 0x9622e400  lhu         $v0, -0x1C00($s1)
    ctx->pc = 0x11c9b0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 4294960128)));
    // 0x11c9b4: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x11C9B4u;
    {
        const bool branch_taken_0x11c9b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11C9B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C9B4u;
            // 0x11c9b8: 0xa6420000  sh          $v0, 0x0($s2) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c9b4) {
            ctx->pc = 0x11C9D4u;
            goto label_11c9d4;
        }
    }
    ctx->pc = 0x11C9BCu;
label_11c9bc:
    // 0x11c9bc: 0x52020004  beql        $s0, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11C9BCu;
    {
        const bool branch_taken_0x11c9bc = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        if (branch_taken_0x11c9bc) {
            ctx->pc = 0x11C9C0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11C9BCu;
            // 0x11c9c0: 0x8e22e400  lw          $v0, -0x1C00($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4294960128)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11C9D0u;
            goto label_11c9d0;
        }
    }
    ctx->pc = 0x11C9C4u;
label_11c9c4:
    // 0x11c9c4: 0x3c02fffe  lui         $v0, 0xFFFE
    ctx->pc = 0x11c9c4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65534 << 16));
    // 0x11c9c8: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x11C9C8u;
    {
        const bool branch_taken_0x11c9c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11C9CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C9C8u;
            // 0x11c9cc: 0x3442fffe  ori         $v0, $v0, 0xFFFE (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65534);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c9c8) {
            ctx->pc = 0x11C9D8u;
            goto label_11c9d8;
        }
    }
    ctx->pc = 0x11C9D0u;
label_11c9d0:
    // 0x11c9d0: 0xae420000  sw          $v0, 0x0($s2)
    ctx->pc = 0x11c9d0u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
label_11c9d4:
    // 0x11c9d4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x11c9d4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_11c9d8:
    // 0x11c9d8: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x11c9d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x11c9dc: 0xdfb30040  ld          $s3, 0x40($sp)
    ctx->pc = 0x11c9dcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11c9e0: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x11c9e0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11c9e4: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x11c9e4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11c9e8: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x11c9e8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11c9ec: 0x3e00008  jr          $ra
    ctx->pc = 0x11C9ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11C9F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C9ECu;
            // 0x11c9f0: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11C930u: goto label_11c930;
            case 0x11C940u: goto label_11c940;
            case 0x11C980u: goto label_11c980;
            case 0x11C994u: goto label_11c994;
            case 0x11C9A8u: goto label_11c9a8;
            case 0x11C9BCu: goto label_11c9bc;
            case 0x11C9C4u: goto label_11c9c4;
            case 0x11C9D0u: goto label_11c9d0;
            case 0x11C9D4u: goto label_11c9d4;
            case 0x11C9D8u: goto label_11c9d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11C9F4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
