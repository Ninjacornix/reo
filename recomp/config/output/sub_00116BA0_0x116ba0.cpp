#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00116BA0
// Address: 0x116ba0 - 0x116c08
void sub_00116BA0_0x116ba0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00116BA0_0x116ba0");
#endif

    switch (ctx->pc) {
        case 0x116bb0u: goto label_116bb0;
        case 0x116bc0u: goto label_116bc0;
        default: break;
    }

    ctx->pc = 0x116ba0u;

    // 0x116ba0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x116ba0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x116ba4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x116ba4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x116ba8: 0xc045474  jal         func_1151D0
    ctx->pc = 0x116BA8u;
    SET_GPR_U32(ctx, 31, 0x116BB0u);
    ctx->pc = 0x116BACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x116BA8u;
            // 0x116bac: 0x24040005  addiu       $a0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1151D0u;
    if (runtime->hasFunction(0x1151D0u)) {
        auto targetFn = runtime->lookupFunction(0x1151D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116BB0u; }
        if (ctx->pc != 0x116BB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001151D0_0x1151d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116BB0u; }
        if (ctx->pc != 0x116BB0u) { return; }
    }
    ctx->pc = 0x116BB0u;
label_116bb0:
    // 0x116bb0: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x116bb0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x116bb4: 0x24040005  addiu       $a0, $zero, 0x5
    ctx->pc = 0x116bb4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x116bb8: 0xc0450d4  jal         func_114350
    ctx->pc = 0x116BB8u;
    SET_GPR_U32(ctx, 31, 0x116BC0u);
    ctx->pc = 0x116BBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x116BB8u;
            // 0x116bbc: 0x8c65af94  lw          $a1, -0x506C($v1) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294946708)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114350u;
    if (runtime->hasFunction(0x114350u)) {
        auto targetFn = runtime->lookupFunction(0x114350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116BC0u; }
        if (ctx->pc != 0x116BC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114350_0x114350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116BC0u; }
        if (ctx->pc != 0x116BC0u) { return; }
    }
    ctx->pc = 0x116BC0u;
label_116bc0:
    // 0x116bc0: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x116bc0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x116bc4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x116bc4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x116bc8: 0xac609d48  sw          $zero, -0x62B8($v1)
    ctx->pc = 0x116bc8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294942024), GPR_U32(ctx, 0));
    // 0x116bcc: 0x3e00008  jr          $ra
    ctx->pc = 0x116BCCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x116BD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116BCCu;
            // 0x116bd0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x116BB0u: goto label_116bb0;
            case 0x116BC0u: goto label_116bc0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x116BD4u;
    // 0x116bd4: 0x0  nop
    ctx->pc = 0x116bd4u;
    // NOP
    // 0x116bd8: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x116bd8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x116bdc: 0x2463af98  addiu       $v1, $v1, -0x5068
    ctx->pc = 0x116bdcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294946712));
    // 0x116be0: 0x8c620014  lw          $v0, 0x14($v1)
    ctx->pc = 0x116be0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 20)));
    // 0x116be4: 0xac650018  sw          $a1, 0x18($v1)
    ctx->pc = 0x116be4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 24), GPR_U32(ctx, 5));
    // 0x116be8: 0x3e00008  jr          $ra
    ctx->pc = 0x116BE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x116BECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116BE8u;
            // 0x116bec: 0xac640014  sw          $a0, 0x14($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 20), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x116BB0u: goto label_116bb0;
            case 0x116BC0u: goto label_116bc0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x116BF0u;
    // 0x116bf0: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x116bf0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x116bf4: 0x2463af98  addiu       $v1, $v1, -0x5068
    ctx->pc = 0x116bf4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294946712));
    // 0x116bf8: 0x8c62000c  lw          $v0, 0xC($v1)
    ctx->pc = 0x116bf8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x116bfc: 0xac650010  sw          $a1, 0x10($v1)
    ctx->pc = 0x116bfcu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 16), GPR_U32(ctx, 5));
    // 0x116c00: 0x3e00008  jr          $ra
    ctx->pc = 0x116C00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x116C04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116C00u;
            // 0x116c04: 0xac64000c  sw          $a0, 0xC($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 12), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x116BB0u: goto label_116bb0;
            case 0x116BC0u: goto label_116bc0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x116C08u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
