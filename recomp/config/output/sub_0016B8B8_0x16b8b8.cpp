#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016B8B8
// Address: 0x16b8b8 - 0x16b990
void sub_0016B8B8_0x16b8b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016B8B8_0x16b8b8");
#endif

    switch (ctx->pc) {
        case 0x16b900u: goto label_16b900;
        case 0x16b95cu: goto label_16b95c;
        default: break;
    }

    ctx->pc = 0x16b8b8u;

    // 0x16b8b8: 0x3c027fff  lui         $v0, 0x7FFF
    ctx->pc = 0x16b8b8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
    // 0x16b8bc: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x16b8bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x16b8c0: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x16b8c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x16b8c4: 0xac83002c  sw          $v1, 0x2C($a0)
    ctx->pc = 0x16b8c4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 44), GPR_U32(ctx, 3));
    // 0x16b8c8: 0xac82001c  sw          $v0, 0x1C($a0)
    ctx->pc = 0x16b8c8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 2));
    // 0x16b8cc: 0x24060043  addiu       $a2, $zero, 0x43
    ctx->pc = 0x16b8ccu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 67));
    // 0x16b8d0: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x16b8d0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x16b8d4: 0x24850140  addiu       $a1, $a0, 0x140
    ctx->pc = 0x16b8d4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), 320));
    // 0x16b8d8: 0xac800004  sw          $zero, 0x4($a0)
    ctx->pc = 0x16b8d8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
    // 0x16b8dc: 0xac800008  sw          $zero, 0x8($a0)
    ctx->pc = 0x16b8dcu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 0));
    // 0x16b8e0: 0xac82000c  sw          $v0, 0xC($a0)
    ctx->pc = 0x16b8e0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 2));
    // 0x16b8e4: 0xac820010  sw          $v0, 0x10($a0)
    ctx->pc = 0x16b8e4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 2));
    // 0x16b8e8: 0xac800014  sw          $zero, 0x14($a0)
    ctx->pc = 0x16b8e8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 0));
    // 0x16b8ec: 0xac820018  sw          $v0, 0x18($a0)
    ctx->pc = 0x16b8ecu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 2));
    // 0x16b8f0: 0xac830020  sw          $v1, 0x20($a0)
    ctx->pc = 0x16b8f0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 32), GPR_U32(ctx, 3));
    // 0x16b8f4: 0xac830024  sw          $v1, 0x24($a0)
    ctx->pc = 0x16b8f4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 36), GPR_U32(ctx, 3));
    // 0x16b8f8: 0xac830028  sw          $v1, 0x28($a0)
    ctx->pc = 0x16b8f8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 40), GPR_U32(ctx, 3));
    // 0x16b8fc: 0xac800030  sw          $zero, 0x30($a0)
    ctx->pc = 0x16b8fcu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 48), GPR_U32(ctx, 0));
label_16b900:
    // 0x16b900: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x16b900u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x16b904: 0xaca00000  sw          $zero, 0x0($a1)
    ctx->pc = 0x16b904u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 0));
    // 0x16b908: 0x0  nop
    ctx->pc = 0x16b908u;
    // NOP
    // 0x16b90c: 0x0  nop
    ctx->pc = 0x16b90cu;
    // NOP
    // 0x16b910: 0x0  nop
    ctx->pc = 0x16b910u;
    // NOP
    // 0x16b914: 0x4c1fffa  bgez        $a2, . + 4 + (-0x6 << 2)
    ctx->pc = 0x16B914u;
    {
        const bool branch_taken_0x16b914 = (GPR_S64(ctx, 6) >= 0);
        ctx->pc = 0x16B918u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B914u;
            // 0x16b918: 0x24a5fffc  addiu       $a1, $a1, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967292));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16b914) {
            ctx->pc = 0x16B900u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_16b900;
        }
    }
    ctx->pc = 0x16B91Cu;
    // 0x16b91c: 0xac800148  sw          $zero, 0x148($a0)
    ctx->pc = 0x16b91cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 328), GPR_U32(ctx, 0));
    // 0x16b920: 0x3e00008  jr          $ra
    ctx->pc = 0x16B920u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16B924u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B920u;
            // 0x16b924: 0xac800144  sw          $zero, 0x144($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 324), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16B900u: goto label_16b900;
            case 0x16B95Cu: goto label_16b95c;
            case 0x16B980u: goto label_16b980;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16B928u;
    // 0x16b928: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x16b928u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16b92c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16b92cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x16b930: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16b930u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16b934: 0x805a704  j           func_169C10
    ctx->pc = 0x16B934u;
    ctx->pc = 0x16B938u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B934u;
            // 0x16b938: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16B93Cu;
    // 0x16b93c: 0x0  nop
    ctx->pc = 0x16b93cu;
    // NOP
    // 0x16b940: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x16b940u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16b944: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16b944u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16b948: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x16b948u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b94c: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x16b94cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x16b950: 0x8e021aec  lw          $v0, 0x1AEC($s0)
    ctx->pc = 0x16b950u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 6892)));
    // 0x16b954: 0xc05ae64  jal         func_16B990
    ctx->pc = 0x16B954u;
    SET_GPR_U32(ctx, 31, 0x16B95Cu);
    ctx->pc = 0x16B958u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B954u;
            // 0x16b958: 0x8c440000  lw          $a0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16B990u;
    if (runtime->hasFunction(0x16B990u)) {
        auto targetFn = runtime->lookupFunction(0x16B990u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B95Cu; }
        if (ctx->pc != 0x16B95Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016B990_0x16b990(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B95Cu; }
        if (ctx->pc != 0x16B95Cu) { return; }
    }
    ctx->pc = 0x16B95Cu;
label_16b95c:
    // 0x16b95c: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16b95cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x16b960: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x16B960u;
    {
        const bool branch_taken_0x16b960 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16B964u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B960u;
            // 0x16b964: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16b960) {
            ctx->pc = 0x16B980u;
            goto label_16b980;
        }
    }
    ctx->pc = 0x16B968u;
    // 0x16b968: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16b968u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16b96c: 0x34a50d0a  ori         $a1, $a1, 0xD0A
    ctx->pc = 0x16b96cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3338);
    // 0x16b970: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x16b970u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16b974: 0x805a704  j           func_169C10
    ctx->pc = 0x16B974u;
    ctx->pc = 0x16B978u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B974u;
            // 0x16b978: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16B97Cu;
    // 0x16b97c: 0x0  nop
    ctx->pc = 0x16b97cu;
    // NOP
label_16b980:
    // 0x16b980: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16b980u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16b984: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x16b984u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16b988: 0x3e00008  jr          $ra
    ctx->pc = 0x16B988u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16B98Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B988u;
            // 0x16b98c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16B900u: goto label_16b900;
            case 0x16B95Cu: goto label_16b95c;
            case 0x16B980u: goto label_16b980;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16B990u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
