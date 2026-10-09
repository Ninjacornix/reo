#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001811B0
// Address: 0x1811b0 - 0x18122c
void sub_001811B0_0x1811b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001811B0_0x1811b0");
#endif

    switch (ctx->pc) {
        case 0x1811dcu: goto label_1811dc;
        case 0x181218u: goto label_181218;
        default: break;
    }

    ctx->pc = 0x1811b0u;

    // 0x1811b0: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x1811b0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x1811b4: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1811b4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1811b8: 0x8c65fa10  lw          $a1, -0x5F0($v1)
    ctx->pc = 0x1811b8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294965776)));
    // 0x1811bc: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1811bcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x1811c0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1811c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1811c4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1811c4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1811c8: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1811c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1811cc: 0x10a00013  beqz        $a1, . + 4 + (0x13 << 2)
    ctx->pc = 0x1811CCu;
    {
        const bool branch_taken_0x1811cc = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x1811D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1811CCu;
            // 0x1811d0: 0x34428001  ori         $v0, $v0, 0x8001 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32769);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1811cc) {
            ctx->pc = 0x18121Cu;
            goto label_18121c;
        }
    }
    ctx->pc = 0x1811D4u;
    // 0x1811d4: 0xc061e90  jal         func_187A40
    ctx->pc = 0x1811D4u;
    SET_GPR_U32(ctx, 31, 0x1811DCu);
    ctx->pc = 0x187A40u;
    if (runtime->hasFunction(0x187A40u)) {
        auto targetFn = runtime->lookupFunction(0x187A40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1811DCu; }
        if (ctx->pc != 0x1811DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187A40_0x187a40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1811DCu; }
        if (ctx->pc != 0x1811DCu) { return; }
    }
    ctx->pc = 0x1811DCu;
label_1811dc:
    // 0x1811dc: 0x3c030028  lui         $v1, 0x28
    ctx->pc = 0x1811dcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)40 << 16));
    // 0x1811e0: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1811E0u;
    {
        const bool branch_taken_0x1811e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1811E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1811E0u;
            // 0x1811e4: 0x24649500  addiu       $a0, $v1, -0x6B00 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 4294939904));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1811e0) {
            ctx->pc = 0x1811F8u;
            goto label_1811f8;
        }
    }
    ctx->pc = 0x1811E8u;
    // 0x1811e8: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1811e8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x1811ec: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1811ECu;
    {
        const bool branch_taken_0x1811ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1811F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1811ECu;
            // 0x1811f0: 0x34428002  ori         $v0, $v0, 0x8002 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32770);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1811ec) {
            ctx->pc = 0x18121Cu;
            goto label_18121c;
        }
    }
    ctx->pc = 0x1811F4u;
    // 0x1811f4: 0x0  nop
    ctx->pc = 0x1811f4u;
    // NOP
label_1811f8:
    // 0x1811f8: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x1811f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1811fc: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1811fcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x181200: 0x14600006  bnez        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x181200u;
    {
        const bool branch_taken_0x181200 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x181204u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181200u;
            // 0x181204: 0x34420010  ori         $v0, $v0, 0x10 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16);
        ctx->in_delay_slot = false;
        if (branch_taken_0x181200) {
            ctx->pc = 0x18121Cu;
            goto label_18121c;
        }
    }
    ctx->pc = 0x181208u;
    // 0x181208: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x181208u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x18120c: 0xac900000  sw          $s0, 0x0($a0)
    ctx->pc = 0x18120cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 16));
    // 0x181210: 0xc062228  jal         func_1888A0
    ctx->pc = 0x181210u;
    SET_GPR_U32(ctx, 31, 0x181218u);
    ctx->pc = 0x181214u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181210u;
            // 0x181214: 0xac820004  sw          $v0, 0x4($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1888A0u;
    if (runtime->hasFunction(0x1888A0u)) {
        auto targetFn = runtime->lookupFunction(0x1888A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181218u; }
        if (ctx->pc != 0x181218u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001888A0_0x1888a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181218u; }
        if (ctx->pc != 0x181218u) { return; }
    }
    ctx->pc = 0x181218u;
label_181218:
    // 0x181218: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x181218u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_18121c:
    // 0x18121c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x18121cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x181220: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x181220u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x181224: 0x3e00008  jr          $ra
    ctx->pc = 0x181224u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x181228u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181224u;
            // 0x181228: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1811DCu: goto label_1811dc;
            case 0x1811F8u: goto label_1811f8;
            case 0x181218u: goto label_181218;
            case 0x18121Cu: goto label_18121c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18122Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
