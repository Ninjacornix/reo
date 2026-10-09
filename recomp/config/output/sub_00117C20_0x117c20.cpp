#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00117C20
// Address: 0x117c20 - 0x117cb8
void sub_00117C20_0x117c20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00117C20_0x117c20");
#endif

    switch (ctx->pc) {
        case 0x117c3cu: goto label_117c3c;
        case 0x117c80u: goto label_117c80;
        default: break;
    }

    ctx->pc = 0x117c20u;

    // 0x117c20: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x117c20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x117c24: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x117c24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x117c28: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x117c28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x117c2c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x117c2cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117c30: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x117c30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x117c34: 0xc047598  jal         func_11D660
    ctx->pc = 0x117C34u;
    SET_GPR_U32(ctx, 31, 0x117C3Cu);
    ctx->pc = 0x117C38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117C34u;
            // 0x117c38: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117C3Cu; }
        if (ctx->pc != 0x117C3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117C3Cu; }
        if (ctx->pc != 0x117C3Cu) { return; }
    }
    ctx->pc = 0x117C3Cu;
label_117c3c:
    // 0x117c3c: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x117c3cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x117c40: 0xae300000  sw          $s0, 0x0($s1)
    ctx->pc = 0x117c40u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 16));
    // 0x117c44: 0x2463c9c0  addiu       $v1, $v1, -0x3640
    ctx->pc = 0x117c44u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294953408));
    // 0x117c48: 0xae200004  sw          $zero, 0x4($s1)
    ctx->pc = 0x117c48u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
    // 0x117c4c: 0x8c620028  lw          $v0, 0x28($v1)
    ctx->pc = 0x117c4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 40)));
    // 0x117c50: 0xae200008  sw          $zero, 0x8($s1)
    ctx->pc = 0x117c50u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 0));
    // 0x117c54: 0xae20000c  sw          $zero, 0xC($s1)
    ctx->pc = 0x117c54u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 0));
    // 0x117c58: 0xae200010  sw          $zero, 0x10($s1)
    ctx->pc = 0x117c58u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 0));
    // 0x117c5c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x117C5Cu;
    {
        const bool branch_taken_0x117c5c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x117C60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117C5Cu;
            // 0x117c60: 0xae200014  sw          $zero, 0x14($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 20), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x117c5c) {
            ctx->pc = 0x117C6Cu;
            goto label_117c6c;
        }
    }
    ctx->pc = 0x117C64u;
    // 0x117c64: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x117C64u;
    {
        const bool branch_taken_0x117c64 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x117C68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117C64u;
            // 0x117c68: 0xac710028  sw          $s1, 0x28($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 40), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x117c64) {
            ctx->pc = 0x117CA0u;
            goto label_117ca0;
        }
    }
    ctx->pc = 0x117C6Cu;
label_117c6c:
    // 0x117c6c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x117c6cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117c70: 0x8c830014  lw          $v1, 0x14($a0)
    ctx->pc = 0x117c70u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x117c74: 0x5060000a  beql        $v1, $zero, . + 4 + (0xA << 2)
    ctx->pc = 0x117C74u;
    {
        const bool branch_taken_0x117c74 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x117c74) {
            ctx->pc = 0x117C78u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x117C74u;
            // 0x117c78: 0xac910014  sw          $s1, 0x14($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
            ctx->pc = 0x117CA0u;
            goto label_117ca0;
        }
    }
    ctx->pc = 0x117C7Cu;
    // 0x117c7c: 0x0  nop
    ctx->pc = 0x117c7cu;
    // NOP
label_117c80:
    // 0x117c80: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x117c80u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117c84: 0x8c820014  lw          $v0, 0x14($a0)
    ctx->pc = 0x117c84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x117c88: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x117c88u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117c8c: 0x0  nop
    ctx->pc = 0x117c8cu;
    // NOP
    // 0x117c90: 0x0  nop
    ctx->pc = 0x117c90u;
    // NOP
    // 0x117c94: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x117C94u;
    {
        const bool branch_taken_0x117c94 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x117c94) {
            ctx->pc = 0x117C80u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_117c80;
        }
    }
    ctx->pc = 0x117C9Cu;
    // 0x117c9c: 0xac910014  sw          $s1, 0x14($a0)
    ctx->pc = 0x117c9cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 17));
label_117ca0:
    // 0x117ca0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x117ca0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x117ca4: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x117ca4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x117ca8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x117ca8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x117cac: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x117CACu;
    ctx->pc = 0x117CB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117CACu;
            // 0x117cb0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x117CB4u;
    // 0x117cb4: 0x0  nop
    ctx->pc = 0x117cb4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
