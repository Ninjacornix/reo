#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011B8B0
// Address: 0x11b8b0 - 0x11b9a0
void sub_0011B8B0_0x11b8b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011B8B0_0x11b8b0");
#endif

    switch (ctx->pc) {
        case 0x11b904u: goto label_11b904;
        case 0x11b984u: goto label_11b984;
        default: break;
    }

    ctx->pc = 0x11b8b0u;

    // 0x11b8b0: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x11b8b0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x11b8b4: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x11b8b4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11b8b8: 0x8c629df8  lw          $v0, -0x6208($v1)
    ctx->pc = 0x11b8b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294942200)));
    // 0x11b8bc: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x11b8bcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b8c0: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11b8c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x11b8c4: 0x4400011  bltz        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x11B8C4u;
    {
        const bool branch_taken_0x11b8c4 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x11B8C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B8C4u;
            // 0x11b8c8: 0xffb00010  sd          $s0, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b8c4) {
            ctx->pc = 0x11B90Cu;
            goto label_11b90c;
        }
    }
    ctx->pc = 0x11B8CCu;
    // 0x11b8cc: 0x3c070026  lui         $a3, 0x26
    ctx->pc = 0x11b8ccu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)38 << 16));
    // 0x11b8d0: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x11b8d0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x11b8d4: 0xace5e2c0  sw          $a1, -0x1D40($a3)
    ctx->pc = 0x11b8d4u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 4294959808), GPR_U32(ctx, 5));
    // 0x11b8d8: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x11b8d8u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x11b8dc: 0x2484e240  addiu       $a0, $a0, -0x1DC0
    ctx->pc = 0x11b8dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294959680));
    // 0x11b8e0: 0x24e7e2c0  addiu       $a3, $a3, -0x1D40
    ctx->pc = 0x11b8e0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294959808));
    // 0x11b8e4: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11b8e4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11b8e8: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x11b8e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x11b8ec: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11b8ecu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b8f0: 0x24080004  addiu       $t0, $zero, 0x4
    ctx->pc = 0x11b8f0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11b8f4: 0x2609e280  addiu       $t1, $s0, -0x1D80
    ctx->pc = 0x11b8f4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), 4294959744));
    // 0x11b8f8: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x11b8f8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11b8fc: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11B8FCu;
    SET_GPR_U32(ctx, 31, 0x11B904u);
    ctx->pc = 0x11B900u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B8FCu;
            // 0x11b900: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B904u; }
        if (ctx->pc != 0x11B904u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B904u; }
        if (ctx->pc != 0x11B904u) { return; }
    }
    ctx->pc = 0x11B904u;
label_11b904:
    // 0x11b904: 0x4410002  bgez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x11B904u;
    {
        const bool branch_taken_0x11b904 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x11B908u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B904u;
            // 0x11b908: 0x8e02e280  lw          $v0, -0x1D80($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294959744)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b904) {
            ctx->pc = 0x11B910u;
            goto label_11b910;
        }
    }
    ctx->pc = 0x11B90Cu;
label_11b90c:
    // 0x11b90c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x11b90cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_11b910:
    // 0x11b910: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x11b910u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11b914: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x11b914u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11b918: 0x3e00008  jr          $ra
    ctx->pc = 0x11B918u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11B91Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B918u;
            // 0x11b91c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11B904u: goto label_11b904;
            case 0x11B90Cu: goto label_11b90c;
            case 0x11B910u: goto label_11b910;
            case 0x11B984u: goto label_11b984;
            case 0x11B990u: goto label_11b990;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11B920u;
    // 0x11b920: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11b920u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11b924: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x11b924u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11b928: 0x8c439df8  lw          $v1, -0x6208($v0)
    ctx->pc = 0x11b928u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294942200)));
    // 0x11b92c: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x11b92cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b930: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11b930u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x11b934: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x11b934u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x11b938: 0x4600015  bltz        $v1, . + 4 + (0x15 << 2)
    ctx->pc = 0x11B938u;
    {
        const bool branch_taken_0x11b938 = (GPR_S64(ctx, 3) < 0);
        ctx->pc = 0x11B93Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B938u;
            // 0x11b93c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b938) {
            ctx->pc = 0x11B990u;
            goto label_11b990;
        }
    }
    ctx->pc = 0x11B940u;
    // 0x11b940: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x11b940u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x11b944: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x11b944u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x11b948: 0x2443e2c0  addiu       $v1, $v0, -0x1D40
    ctx->pc = 0x11b948u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 4294959808));
    // 0x11b94c: 0xac45e2c0  sw          $a1, -0x1D40($v0)
    ctx->pc = 0x11b94cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294959808), GPR_U32(ctx, 5));
    // 0x11b950: 0xac670004  sw          $a3, 0x4($v1)
    ctx->pc = 0x11b950u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 7));
    // 0x11b954: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x11b954u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x11b958: 0xac660008  sw          $a2, 0x8($v1)
    ctx->pc = 0x11b958u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 6));
    // 0x11b95c: 0x2484e240  addiu       $a0, $a0, -0x1DC0
    ctx->pc = 0x11b95cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294959680));
    // 0x11b960: 0x60382d  daddu       $a3, $v1, $zero
    ctx->pc = 0x11b960u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b964: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x11b964u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11b968: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11b968u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11b96c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11b96cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b970: 0x2408000c  addiu       $t0, $zero, 0xC
    ctx->pc = 0x11b970u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x11b974: 0x2609e280  addiu       $t1, $s0, -0x1D80
    ctx->pc = 0x11b974u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), 4294959744));
    // 0x11b978: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x11b978u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11b97c: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11B97Cu;
    SET_GPR_U32(ctx, 31, 0x11B984u);
    ctx->pc = 0x11B980u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B97Cu;
            // 0x11b980: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B984u; }
        if (ctx->pc != 0x11B984u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B984u; }
        if (ctx->pc != 0x11B984u) { return; }
    }
    ctx->pc = 0x11B984u;
label_11b984:
    // 0x11b984: 0x4410002  bgez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x11B984u;
    {
        const bool branch_taken_0x11b984 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x11B988u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B984u;
            // 0x11b988: 0x8e02e280  lw          $v0, -0x1D80($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294959744)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b984) {
            ctx->pc = 0x11B990u;
            goto label_11b990;
        }
    }
    ctx->pc = 0x11B98Cu;
    // 0x11b98c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x11b98cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_11b990:
    // 0x11b990: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x11b990u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11b994: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x11b994u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11b998: 0x3e00008  jr          $ra
    ctx->pc = 0x11B998u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11B99Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B998u;
            // 0x11b99c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11B904u: goto label_11b904;
            case 0x11B90Cu: goto label_11b90c;
            case 0x11B910u: goto label_11b910;
            case 0x11B984u: goto label_11b984;
            case 0x11B990u: goto label_11b990;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11B9A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
