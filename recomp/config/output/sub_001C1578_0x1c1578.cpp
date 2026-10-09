#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C1578
// Address: 0x1c1578 - 0x1c15e8
void sub_001C1578_0x1c1578(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C1578_0x1c1578");
#endif

    switch (ctx->pc) {
        case 0x1c15acu: goto label_1c15ac;
        case 0x1c15c4u: goto label_1c15c4;
        case 0x1c15ccu: goto label_1c15cc;
        default: break;
    }

    ctx->pc = 0x1c1578u;

    // 0x1c1578: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1c1578u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1c157c: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x1c157cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x1c1580: 0x3c110023  lui         $s1, 0x23
    ctx->pc = 0x1c1580u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)35 << 16));
    // 0x1c1584: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x1c1584u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x1c1588: 0x822252d8  lb          $v0, 0x52D8($s1)
    ctx->pc = 0x1c1588u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 21208)));
    // 0x1c158c: 0x263252d8  addiu       $s2, $s1, 0x52D8
    ctx->pc = 0x1c158cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 17), 21208));
    // 0x1c1590: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1c1590u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1c1594: 0x1440000d  bnez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1C1594u;
    {
        const bool branch_taken_0x1c1594 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C1598u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1594u;
            // 0x1c1598: 0xffb00000  sd          $s0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1594) {
            ctx->pc = 0x1C15CCu;
            goto label_1c15cc;
        }
    }
    ctx->pc = 0x1C159Cu;
    // 0x1c159c: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1c159cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1c15a0: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1c15a0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c15a4: 0xc04629c  jal         func_118A70
    ctx->pc = 0x1C15A4u;
    SET_GPR_U32(ctx, 31, 0x1C15ACu);
    ctx->pc = 0x1C15A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C15A4u;
            // 0x1c15a8: 0x24840678  addiu       $a0, $a0, 0x678 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1656));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118A70u;
    if (runtime->hasFunction(0x118A70u)) {
        auto targetFn = runtime->lookupFunction(0x118A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C15ACu; }
        if (ctx->pc != 0x1C15ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118A70_0x118a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C15ACu; }
        if (ctx->pc != 0x1C15ACu) { return; }
    }
    ctx->pc = 0x1C15ACu;
label_1c15ac:
    // 0x1c15ac: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1c15acu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c15b0: 0x6000006  bltz        $s0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1C15B0u;
    {
        const bool branch_taken_0x1c15b0 = (GPR_S64(ctx, 16) < 0);
        ctx->pc = 0x1C15B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C15B0u;
            // 0x1c15b4: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c15b0) {
            ctx->pc = 0x1C15CCu;
            goto label_1c15cc;
        }
    }
    ctx->pc = 0x1C15B8u;
    // 0x1c15b8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1c15b8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c15bc: 0xc04642c  jal         func_1190B0
    ctx->pc = 0x1C15BCu;
    SET_GPR_U32(ctx, 31, 0x1C15C4u);
    ctx->pc = 0x1C15C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C15BCu;
            // 0x1c15c0: 0x2406000e  addiu       $a2, $zero, 0xE (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1190B0u;
    if (runtime->hasFunction(0x1190B0u)) {
        auto targetFn = runtime->lookupFunction(0x1190B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C15C4u; }
        if (ctx->pc != 0x1C15C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001190B0_0x1190b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C15C4u; }
        if (ctx->pc != 0x1C15C4u) { return; }
    }
    ctx->pc = 0x1C15C4u;
label_1c15c4:
    // 0x1c15c4: 0xc04633e  jal         func_118CF8
    ctx->pc = 0x1C15C4u;
    SET_GPR_U32(ctx, 31, 0x1C15CCu);
    ctx->pc = 0x1C15C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C15C4u;
            // 0x1c15c8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118CF8u;
    if (runtime->hasFunction(0x118CF8u)) {
        auto targetFn = runtime->lookupFunction(0x118CF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C15CCu; }
        if (ctx->pc != 0x1C15CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118CF8_0x118cf8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C15CCu; }
        if (ctx->pc != 0x1C15CCu) { return; }
    }
    ctx->pc = 0x1C15CCu;
label_1c15cc:
    // 0x1c15cc: 0x262252d8  addiu       $v0, $s1, 0x52D8
    ctx->pc = 0x1c15ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 21208));
    // 0x1c15d0: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1c15d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1c15d4: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x1c15d4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c15d8: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x1c15d8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c15dc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1c15dcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c15e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1C15E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C15E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C15E0u;
            // 0x1c15e4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C15ACu: goto label_1c15ac;
            case 0x1C15C4u: goto label_1c15c4;
            case 0x1C15CCu: goto label_1c15cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C15E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
