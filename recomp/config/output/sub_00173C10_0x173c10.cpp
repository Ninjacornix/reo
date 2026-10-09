#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00173C10
// Address: 0x173c10 - 0x173c70
void sub_00173C10_0x173c10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00173C10_0x173c10");
#endif

    switch (ctx->pc) {
        case 0x173c44u: goto label_173c44;
        default: break;
    }

    ctx->pc = 0x173c10u;

    // 0x173c10: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x173c10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x173c14: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x173c14u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x173c18: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x173c18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x173c1c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x173c1cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173c20: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x173c20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x173c24: 0x8e020048  lw          $v0, 0x48($s0)
    ctx->pc = 0x173c24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x173c28: 0x54430009  bnel        $v0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x173C28u;
    {
        const bool branch_taken_0x173c28 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x173c28) {
            ctx->pc = 0x173C2Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x173C28u;
            // 0x173c2c: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x173C50u;
            goto label_173c50;
        }
    }
    ctx->pc = 0x173C30u;
    // 0x173c30: 0x24050007  addiu       $a1, $zero, 0x7
    ctx->pc = 0x173c30u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x173c34: 0x24060007  addiu       $a2, $zero, 0x7
    ctx->pc = 0x173c34u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x173c38: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x173c38u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173c3c: 0xc05def8  jal         func_177BE0
    ctx->pc = 0x173C3Cu;
    SET_GPR_U32(ctx, 31, 0x173C44u);
    ctx->pc = 0x173C40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173C3Cu;
            // 0x173c40: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177BE0u;
    if (runtime->hasFunction(0x177BE0u)) {
        auto targetFn = runtime->lookupFunction(0x177BE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173C44u; }
        if (ctx->pc != 0x173C44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177BE0_0x177be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173C44u; }
        if (ctx->pc != 0x173C44u) { return; }
    }
    ctx->pc = 0x173C44u;
label_173c44:
    // 0x173c44: 0x54400006  bnel        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x173C44u;
    {
        const bool branch_taken_0x173c44 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x173c44) {
            ctx->pc = 0x173C48u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x173C44u;
            // 0x173c48: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x173C60u;
            goto label_173c60;
        }
    }
    ctx->pc = 0x173C4Cu;
    // 0x173c4c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x173c4cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_173c50:
    // 0x173c50: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x173c50u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173c54: 0xae03004c  sw          $v1, 0x4C($s0)
    ctx->pc = 0x173c54u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 76), GPR_U32(ctx, 3));
    // 0x173c58: 0xae030048  sw          $v1, 0x48($s0)
    ctx->pc = 0x173c58u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 72), GPR_U32(ctx, 3));
    // 0x173c5c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x173c5cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_173c60:
    // 0x173c60: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x173c60u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x173c64: 0x3e00008  jr          $ra
    ctx->pc = 0x173C64u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x173C68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173C64u;
            // 0x173c68: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x173C44u: goto label_173c44;
            case 0x173C50u: goto label_173c50;
            case 0x173C60u: goto label_173c60;
            default: break;
        }
        return;
    }
    ctx->pc = 0x173C6Cu;
    // 0x173c6c: 0x0  nop
    ctx->pc = 0x173c6cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
