#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00116FD0
// Address: 0x116fd0 - 0x117080
void sub_00116FD0_0x116fd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00116FD0_0x116fd0");
#endif

    switch (ctx->pc) {
        case 0x117004u: goto label_117004;
        case 0x117024u: goto label_117024;
        default: break;
    }

    ctx->pc = 0x116fd0u;

    // 0x116fd0: 0x3c19ffff  lui         $t9, 0xFFFF
    ctx->pc = 0x116fd0u;
    SET_GPR_S32(ctx, 25, (int32_t)((uint32_t)65535 << 16));
    // 0x116fd4: 0x3739ffc0  ori         $t9, $t9, 0xFFC0
    ctx->pc = 0x116fd4u;
    SET_GPR_U64(ctx, 25, GPR_U64(ctx, 25) | (uint64_t)(uint16_t)65472);
    // 0x116fd8: 0x18a00026  blez        $a1, . + 4 + (0x26 << 2)
    ctx->pc = 0x116FD8u;
    {
        const bool branch_taken_0x116fd8 = (GPR_S64(ctx, 5) <= 0);
        ctx->pc = 0x116FDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116FD8u;
            // 0x116fdc: 0x855021  addu        $t2, $a0, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116fd8) {
            ctx->pc = 0x117074u;
            goto label_117074;
        }
    }
    ctx->pc = 0x116FE0u;
    // 0x116fe0: 0x994024  and         $t0, $a0, $t9
    ctx->pc = 0x116fe0u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 4) & GPR_U64(ctx, 25));
    // 0x116fe4: 0x254affff  addiu       $t2, $t2, -0x1
    ctx->pc = 0x116fe4u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 4294967295));
    // 0x116fe8: 0x1594824  and         $t1, $t2, $t9
    ctx->pc = 0x116fe8u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 10) & GPR_U64(ctx, 25));
    // 0x116fec: 0x1285023  subu        $t2, $t1, $t0
    ctx->pc = 0x116fecu;
    SET_GPR_S32(ctx, 10, (int32_t)SUB32(GPR_U32(ctx, 9), GPR_U32(ctx, 8)));
    // 0x116ff0: 0xa5982  srl         $t3, $t2, 6
    ctx->pc = 0x116ff0u;
    SET_GPR_S32(ctx, 11, (int32_t)SRL32(GPR_U32(ctx, 10), 6));
    // 0x116ff4: 0x256b0001  addiu       $t3, $t3, 0x1
    ctx->pc = 0x116ff4u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 1));
    // 0x116ff8: 0x31690007  andi        $t1, $t3, 0x7
    ctx->pc = 0x116ff8u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 11) & (uint64_t)(uint16_t)7);
    // 0x116ffc: 0x11200008  beqz        $t1, . + 4 + (0x8 << 2)
    ctx->pc = 0x116FFCu;
    {
        const bool branch_taken_0x116ffc = (GPR_U64(ctx, 9) == GPR_U64(ctx, 0));
        ctx->pc = 0x117000u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116FFCu;
            // 0x117000: 0xb50c2  srl         $t2, $t3, 3 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)SRL32(GPR_U32(ctx, 11), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116ffc) {
            ctx->pc = 0x117020u;
            goto label_117020;
        }
    }
    ctx->pc = 0x117004u;
label_117004:
    // 0x117004: 0xf  sync
    ctx->pc = 0x117004u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x117008: 0xbd180000  cache       0x18, 0x0($t0)
    ctx->pc = 0x117008u;
    // CACHE instruction (ignored)
    // 0x11700c: 0xf  sync
    ctx->pc = 0x11700cu;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x117010: 0x0  nop
    ctx->pc = 0x117010u;
    // NOP
    // 0x117014: 0x2529ffff  addiu       $t1, $t1, -0x1
    ctx->pc = 0x117014u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4294967295));
    // 0x117018: 0x1d20fffa  bgtz        $t1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x117018u;
    {
        const bool branch_taken_0x117018 = (GPR_S64(ctx, 9) > 0);
        ctx->pc = 0x11701Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117018u;
            // 0x11701c: 0x25080040  addiu       $t0, $t0, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 64));
        ctx->in_delay_slot = false;
        if (branch_taken_0x117018) {
            ctx->pc = 0x117004u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_117004;
        }
    }
    ctx->pc = 0x117020u;
label_117020:
    // 0x117020: 0x11400014  beqz        $t2, . + 4 + (0x14 << 2)
label_117024:
    if (ctx->pc == 0x117024u) {
        ctx->pc = 0x117024u;
            // 0x117024: 0x254affff  addiu       $t2, $t2, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 4294967295));
        ctx->pc = 0x117028u;
        goto label_fallthrough_0x117020;
    }
    ctx->pc = 0x117020u;
    {
        const bool branch_taken_0x117020 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 0));
        ctx->pc = 0x117024u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117020u;
            // 0x117024: 0x254affff  addiu       $t2, $t2, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x117020) {
            ctx->pc = 0x117074u;
            goto label_117074;
        }
    }
label_fallthrough_0x117020:
    ctx->pc = 0x117028u;
    // 0x117028: 0xf  sync
    ctx->pc = 0x117028u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11702c: 0xbd180000  cache       0x18, 0x0($t0)
    ctx->pc = 0x11702cu;
    // CACHE instruction (ignored)
    // 0x117030: 0xf  sync
    ctx->pc = 0x117030u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x117034: 0xbd180040  cache       0x18, 0x40($t0)
    ctx->pc = 0x117034u;
    // CACHE instruction (ignored)
    // 0x117038: 0xf  sync
    ctx->pc = 0x117038u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11703c: 0xbd180080  cache       0x18, 0x80($t0)
    ctx->pc = 0x11703cu;
    // CACHE instruction (ignored)
    // 0x117040: 0xf  sync
    ctx->pc = 0x117040u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x117044: 0xbd1800c0  cache       0x18, 0xC0($t0)
    ctx->pc = 0x117044u;
    // CACHE instruction (ignored)
    // 0x117048: 0xf  sync
    ctx->pc = 0x117048u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11704c: 0xbd180100  cache       0x18, 0x100($t0)
    ctx->pc = 0x11704cu;
    // CACHE instruction (ignored)
    // 0x117050: 0xf  sync
    ctx->pc = 0x117050u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x117054: 0xbd180140  cache       0x18, 0x140($t0)
    ctx->pc = 0x117054u;
    // CACHE instruction (ignored)
    // 0x117058: 0xf  sync
    ctx->pc = 0x117058u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11705c: 0xbd180180  cache       0x18, 0x180($t0)
    ctx->pc = 0x11705cu;
    // CACHE instruction (ignored)
    // 0x117060: 0xf  sync
    ctx->pc = 0x117060u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x117064: 0xbd1801c0  cache       0x18, 0x1C0($t0)
    ctx->pc = 0x117064u;
    // CACHE instruction (ignored)
    // 0x117068: 0xf  sync
    ctx->pc = 0x117068u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11706c: 0x1d40ffed  bgtz        $t2, . + 4 + (-0x13 << 2)
    ctx->pc = 0x11706Cu;
    {
        const bool branch_taken_0x11706c = (GPR_S64(ctx, 10) > 0);
        ctx->pc = 0x117070u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11706Cu;
            // 0x117070: 0x25080200  addiu       $t0, $t0, 0x200 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 512));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11706c) {
            ctx->pc = 0x117024u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_117024;
        }
    }
    ctx->pc = 0x117074u;
label_117074:
    // 0x117074: 0x3e00008  jr          $ra
    ctx->pc = 0x117074u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x117004u: goto label_117004;
            case 0x117020u: goto label_117020;
            case 0x117024u: goto label_117024;
            case 0x117074u: goto label_117074;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11707Cu;
    // 0x11707c: 0x3e00008  jr          $ra
    ctx->pc = 0x11707Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x117004u: goto label_117004;
            case 0x117020u: goto label_117020;
            case 0x117024u: goto label_117024;
            case 0x117074u: goto label_117074;
            default: break;
        }
        return;
    }
    ctx->pc = 0x117084u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
