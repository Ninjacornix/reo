#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011BC08
// Address: 0x11bc08 - 0x11bc78
void sub_0011BC08_0x11bc08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011BC08_0x11bc08");
#endif

    switch (ctx->pc) {
        case 0x11bc58u: goto label_11bc58;
        default: break;
    }

    ctx->pc = 0x11bc08u;

    // 0x11bc08: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11bc08u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11bc0c: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x11bc0cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11bc10: 0x8c439df8  lw          $v1, -0x6208($v0)
    ctx->pc = 0x11bc10u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294942200)));
    // 0x11bc14: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11bc14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x11bc18: 0x4610003  bgez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x11BC18u;
    {
        const bool branch_taken_0x11bc18 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x11BC1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BC18u;
            // 0x11bc1c: 0xffb00010  sd          $s0, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11bc18) {
            ctx->pc = 0x11BC28u;
            goto label_11bc28;
        }
    }
    ctx->pc = 0x11BC20u;
    // 0x11bc20: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x11BC20u;
    {
        const bool branch_taken_0x11bc20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11BC24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BC20u;
            // 0x11bc24: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11bc20) {
            ctx->pc = 0x11BC68u;
            goto label_11bc68;
        }
    }
    ctx->pc = 0x11BC28u;
label_11bc28:
    // 0x11bc28: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x11bc28u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x11bc2c: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x11bc2cu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x11bc30: 0x2484e240  addiu       $a0, $a0, -0x1DC0
    ctx->pc = 0x11bc30u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294959680));
    // 0x11bc34: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11bc34u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11bc38: 0x24050007  addiu       $a1, $zero, 0x7
    ctx->pc = 0x11bc38u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x11bc3c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11bc3cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bc40: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x11bc40u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bc44: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x11bc44u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bc48: 0x2609e280  addiu       $t1, $s0, -0x1D80
    ctx->pc = 0x11bc48u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), 4294959744));
    // 0x11bc4c: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x11bc4cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11bc50: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11BC50u;
    SET_GPR_U32(ctx, 31, 0x11BC58u);
    ctx->pc = 0x11BC54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11BC50u;
            // 0x11bc54: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11BC58u; }
        if (ctx->pc != 0x11BC58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11BC58u; }
        if (ctx->pc != 0x11BC58u) { return; }
    }
    ctx->pc = 0x11BC58u;
label_11bc58:
    // 0x11bc58: 0x4430003  bgezl       $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11BC58u;
    {
        const bool branch_taken_0x11bc58 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x11bc58) {
            ctx->pc = 0x11BC5Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11BC58u;
            // 0x11bc5c: 0x8e02e280  lw          $v0, -0x1D80($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294959744)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11BC68u;
            goto label_11bc68;
        }
    }
    ctx->pc = 0x11BC60u;
    // 0x11bc60: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x11bc60u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x11bc64: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x11bc64u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
label_11bc68:
    // 0x11bc68: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x11bc68u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11bc6c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x11bc6cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11bc70: 0x3e00008  jr          $ra
    ctx->pc = 0x11BC70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11BC74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BC70u;
            // 0x11bc74: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11BC28u: goto label_11bc28;
            case 0x11BC58u: goto label_11bc58;
            case 0x11BC68u: goto label_11bc68;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11BC78u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
