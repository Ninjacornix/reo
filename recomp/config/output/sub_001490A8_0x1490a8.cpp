#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001490A8
// Address: 0x1490a8 - 0x149134
void sub_001490A8_0x1490a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001490A8_0x1490a8");
#endif

    switch (ctx->pc) {
        case 0x1490c0u: goto label_1490c0;
        case 0x1490ccu: goto label_1490cc;
        case 0x1490dcu: goto label_1490dc;
        case 0x1490e8u: goto label_1490e8;
        case 0x1490f4u: goto label_1490f4;
        case 0x149104u: goto label_149104;
        case 0x149114u: goto label_149114;
        case 0x149120u: goto label_149120;
        default: break;
    }

    ctx->pc = 0x1490a8u;

    // 0x1490a8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1490a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1490ac: 0x24050003  addiu       $a1, $zero, 0x3
    ctx->pc = 0x1490acu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1490b0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1490b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1490b4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1490b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1490b8: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x1490B8u;
    SET_GPR_U32(ctx, 31, 0x1490C0u);
    ctx->pc = 0x1490BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1490B8u;
            // 0x1490bc: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1490C0u; }
        if (ctx->pc != 0x1490C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1490C0u; }
        if (ctx->pc != 0x1490C0u) { return; }
    }
    ctx->pc = 0x1490C0u;
label_1490c0:
    // 0x1490c0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1490c0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1490c4: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x1490C4u;
    SET_GPR_U32(ctx, 31, 0x1490CCu);
    ctx->pc = 0x1490C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1490C4u;
            // 0x1490c8: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1490CCu; }
        if (ctx->pc != 0x1490CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1490CCu; }
        if (ctx->pc != 0x1490CCu) { return; }
    }
    ctx->pc = 0x1490CCu;
label_1490cc:
    // 0x1490cc: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1490CCu;
    {
        const bool branch_taken_0x1490cc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1490D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1490CCu;
            // 0x1490d0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1490cc) {
            ctx->pc = 0x1490F8u;
            goto label_1490f8;
        }
    }
    ctx->pc = 0x1490D4u;
    // 0x1490d4: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x1490D4u;
    SET_GPR_U32(ctx, 31, 0x1490DCu);
    ctx->pc = 0x1490D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1490D4u;
            // 0x1490d8: 0x24050008  addiu       $a1, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1490DCu; }
        if (ctx->pc != 0x1490DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1490DCu; }
        if (ctx->pc != 0x1490DCu) { return; }
    }
    ctx->pc = 0x1490DCu;
label_1490dc:
    // 0x1490dc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1490dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1490e0: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x1490E0u;
    SET_GPR_U32(ctx, 31, 0x1490E8u);
    ctx->pc = 0x1490E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1490E0u;
            // 0x1490e4: 0x24050008  addiu       $a1, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1490E8u; }
        if (ctx->pc != 0x1490E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1490E8u; }
        if (ctx->pc != 0x1490E8u) { return; }
    }
    ctx->pc = 0x1490E8u;
label_1490e8:
    // 0x1490e8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1490e8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1490ec: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x1490ECu;
    SET_GPR_U32(ctx, 31, 0x1490F4u);
    ctx->pc = 0x1490F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1490ECu;
            // 0x1490f0: 0x24050008  addiu       $a1, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1490F4u; }
        if (ctx->pc != 0x1490F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1490F4u; }
        if (ctx->pc != 0x1490F4u) { return; }
    }
    ctx->pc = 0x1490F4u;
label_1490f4:
    // 0x1490f4: 0xae02015c  sw          $v0, 0x15C($s0)
    ctx->pc = 0x1490f4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 348), GPR_U32(ctx, 2));
label_1490f8:
    // 0x1490f8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1490f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1490fc: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x1490FCu;
    SET_GPR_U32(ctx, 31, 0x149104u);
    ctx->pc = 0x149100u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1490FCu;
            // 0x149100: 0x2405000e  addiu       $a1, $zero, 0xE (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x149104u; }
        if (ctx->pc != 0x149104u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x149104u; }
        if (ctx->pc != 0x149104u) { return; }
    }
    ctx->pc = 0x149104u;
label_149104:
    // 0x149104: 0xae020160  sw          $v0, 0x160($s0)
    ctx->pc = 0x149104u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 352), GPR_U32(ctx, 2));
    // 0x149108: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x149108u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14910c: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x14910Cu;
    SET_GPR_U32(ctx, 31, 0x149114u);
    ctx->pc = 0x149110u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14910Cu;
            // 0x149110: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x149114u; }
        if (ctx->pc != 0x149114u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x149114u; }
        if (ctx->pc != 0x149114u) { return; }
    }
    ctx->pc = 0x149114u;
label_149114:
    // 0x149114: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x149114u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x149118: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x149118u;
    SET_GPR_U32(ctx, 31, 0x149120u);
    ctx->pc = 0x14911Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x149118u;
            // 0x14911c: 0x2405000e  addiu       $a1, $zero, 0xE (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x149120u; }
        if (ctx->pc != 0x149120u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x149120u; }
        if (ctx->pc != 0x149120u) { return; }
    }
    ctx->pc = 0x149120u;
label_149120:
    // 0x149120: 0xae020164  sw          $v0, 0x164($s0)
    ctx->pc = 0x149120u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 356), GPR_U32(ctx, 2));
    // 0x149124: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x149124u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x149128: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x149128u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x14912c: 0x3e00008  jr          $ra
    ctx->pc = 0x14912Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x149130u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14912Cu;
            // 0x149130: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1490C0u: goto label_1490c0;
            case 0x1490CCu: goto label_1490cc;
            case 0x1490DCu: goto label_1490dc;
            case 0x1490E8u: goto label_1490e8;
            case 0x1490F4u: goto label_1490f4;
            case 0x1490F8u: goto label_1490f8;
            case 0x149104u: goto label_149104;
            case 0x149114u: goto label_149114;
            case 0x149120u: goto label_149120;
            default: break;
        }
        return;
    }
    ctx->pc = 0x149134u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
