#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00140AF0
// Address: 0x140af0 - 0x140b44
void sub_00140AF0_0x140af0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00140AF0_0x140af0");
#endif

    switch (ctx->pc) {
        case 0x140b30u: goto label_140b30;
        default: break;
    }

    ctx->pc = 0x140af0u;

    // 0x140af0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x140af0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x140af4: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x140af4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x140af8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x140af8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x140afc: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x140afcu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x140b00: 0x24424600  addiu       $v0, $v0, 0x4600
    ctx->pc = 0x140b00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 17920));
    // 0x140b04: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x140b04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x140b08: 0x26104700  addiu       $s0, $s0, 0x4700
    ctx->pc = 0x140b08u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 18176));
    // 0x140b0c: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x140b0cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x140b10: 0xac450004  sw          $a1, 0x4($v0)
    ctx->pc = 0x140b10u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 5));
    // 0x140b14: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x140b14u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140b18: 0xac460008  sw          $a2, 0x8($v0)
    ctx->pc = 0x140b18u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 6));
    // 0x140b1c: 0x24060003  addiu       $a2, $zero, 0x3
    ctx->pc = 0x140b1cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x140b20: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x140b20u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140b24: 0x24040020  addiu       $a0, $zero, 0x20
    ctx->pc = 0x140b24u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x140b28: 0xc04e518  jal         func_139460
    ctx->pc = 0x140B28u;
    SET_GPR_U32(ctx, 31, 0x140B30u);
    ctx->pc = 0x140B2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x140B28u;
            // 0x140b2c: 0x24080001  addiu       $t0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139460u;
    if (runtime->hasFunction(0x139460u)) {
        auto targetFn = runtime->lookupFunction(0x139460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140B30u; }
        if (ctx->pc != 0x140B30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139460_0x139460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140B30u; }
        if (ctx->pc != 0x140B30u) { return; }
    }
    ctx->pc = 0x140B30u;
label_140b30:
    // 0x140b30: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x140b30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x140b34: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x140b34u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x140b38: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x140b38u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x140b3c: 0x3e00008  jr          $ra
    ctx->pc = 0x140B3Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x140B40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140B3Cu;
            // 0x140b40: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140B30u: goto label_140b30;
            default: break;
        }
        return;
    }
    ctx->pc = 0x140B44u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
