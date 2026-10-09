#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00135730
// Address: 0x135730 - 0x1357f8
void sub_00135730_0x135730(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00135730_0x135730");
#endif

    switch (ctx->pc) {
        case 0x135770u: goto label_135770;
        case 0x1357a0u: goto label_1357a0;
        case 0x1357acu: goto label_1357ac;
        default: break;
    }

    ctx->pc = 0x135730u;

    // 0x135730: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x135730u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x135734: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x135734u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x135738: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x135738u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13573c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13573cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x135740: 0x16000009  bnez        $s0, . + 4 + (0x9 << 2)
    ctx->pc = 0x135740u;
    {
        const bool branch_taken_0x135740 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x135744u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135740u;
            // 0x135744: 0xffbf0010  sd          $ra, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135740) {
            ctx->pc = 0x135768u;
            goto label_135768;
        }
    }
    ctx->pc = 0x135748u;
    // 0x135748: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x135748u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13574c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13574cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x135750: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x135750u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x135754: 0x2484b850  addiu       $a0, $a0, -0x47B0
    ctx->pc = 0x135754u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948944));
    // 0x135758: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x135758u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13575c: 0x804d480  j           func_135200
    ctx->pc = 0x13575Cu;
    ctx->pc = 0x135760u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13575Cu;
            // 0x135760: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00135200_0x135200(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x135764u;
    // 0x135764: 0x0  nop
    ctx->pc = 0x135764u;
    // NOP
label_135768:
    // 0x135768: 0xc042c56  jal         func_10B158
    ctx->pc = 0x135768u;
    SET_GPR_U32(ctx, 31, 0x135770u);
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135770u; }
        if (ctx->pc != 0x135770u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135770u; }
        if (ctx->pc != 0x135770u) { return; }
    }
    ctx->pc = 0x135770u;
label_135770:
    // 0x135770: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x135770u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x135774: 0x16200008  bnez        $s1, . + 4 + (0x8 << 2)
    ctx->pc = 0x135774u;
    {
        const bool branch_taken_0x135774 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x135778u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135774u;
            // 0x135778: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135774) {
            ctx->pc = 0x135798u;
            goto label_135798;
        }
    }
    ctx->pc = 0x13577Cu;
    // 0x13577c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13577cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x135780: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x135780u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x135784: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x135784u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x135788: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x135788u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13578c: 0xa0402268  sb          $zero, 0x2268($v0)
    ctx->pc = 0x13578cu;
    WRITE8(ADD32(GPR_U32(ctx, 2), 8808), (uint8_t)GPR_U32(ctx, 0));
    // 0x135790: 0x3e00008  jr          $ra
    ctx->pc = 0x135790u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x135794u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135790u;
            // 0x135794: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135768u: goto label_135768;
            case 0x135770u: goto label_135770;
            case 0x135798u: goto label_135798;
            case 0x1357A0u: goto label_1357a0;
            case 0x1357ACu: goto label_1357ac;
            case 0x1357D8u: goto label_1357d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x135798u;
label_135798:
    // 0x135798: 0xc04d57e  jal         func_1355F8
    ctx->pc = 0x135798u;
    SET_GPR_U32(ctx, 31, 0x1357A0u);
    ctx->pc = 0x1355F8u;
    if (runtime->hasFunction(0x1355F8u)) {
        auto targetFn = runtime->lookupFunction(0x1355F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1357A0u; }
        if (ctx->pc != 0x1357A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001355F8_0x1355f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1357A0u; }
        if (ctx->pc != 0x1357A0u) { return; }
    }
    ctx->pc = 0x1357A0u;
label_1357a0:
    // 0x1357a0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1357a0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1357a4: 0xc04d5fe  jal         func_1357F8
    ctx->pc = 0x1357A4u;
    SET_GPR_U32(ctx, 31, 0x1357ACu);
    ctx->pc = 0x1357A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1357A4u;
            // 0x1357a8: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1357F8u;
    if (runtime->hasFunction(0x1357F8u)) {
        auto targetFn = runtime->lookupFunction(0x1357F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1357ACu; }
        if (ctx->pc != 0x1357ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001357F8_0x1357f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1357ACu; }
        if (ctx->pc != 0x1357ACu) { return; }
    }
    ctx->pc = 0x1357ACu;
label_1357ac:
    // 0x1357ac: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x1357acu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x1357b0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1357b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1357b4: 0x24842268  addiu       $a0, $a0, 0x2268
    ctx->pc = 0x1357b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8808));
    // 0x1357b8: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1357b8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1357bc: 0x14430006  bne         $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1357BCu;
    {
        const bool branch_taken_0x1357bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1357C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1357BCu;
            // 0x1357c0: 0x26260001  addiu       $a2, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1357bc) {
            ctx->pc = 0x1357D8u;
            goto label_1357d8;
        }
    }
    ctx->pc = 0x1357C4u;
    // 0x1357c4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1357c4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1357c8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1357c8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1357cc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1357ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1357d0: 0x8041eac  j           func_107AB0
    ctx->pc = 0x1357D0u;
    ctx->pc = 0x1357D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1357D0u;
            // 0x1357d4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107AB0_0x107ab0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1357D8u;
label_1357d8:
    // 0x1357d8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1357d8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1357dc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1357dcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1357e0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1357e0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1357e4: 0x2484b878  addiu       $a0, $a0, -0x4788
    ctx->pc = 0x1357e4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948984));
    // 0x1357e8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1357e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1357ec: 0x804d480  j           func_135200
    ctx->pc = 0x1357ECu;
    ctx->pc = 0x1357F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1357ECu;
            // 0x1357f0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00135200_0x135200(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1357F4u;
    // 0x1357f4: 0x0  nop
    ctx->pc = 0x1357f4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
