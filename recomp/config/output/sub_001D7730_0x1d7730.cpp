#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D7730
// Address: 0x1d7730 - 0x1d77b0
void sub_001D7730_0x1d7730(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D7730_0x1d7730");
#endif

    switch (ctx->pc) {
        case 0x1d7768u: goto label_1d7768;
        default: break;
    }

    ctx->pc = 0x1d7730u;

    // 0x1d7730: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1d7730u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1d7734: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d7734u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d7738: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1d7738u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1d773c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d773cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d7740: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d7740u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d7744: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1d7744u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d7748: 0xa02045d8  sb          $zero, 0x45D8($at)
    ctx->pc = 0x1d7748u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17880), (uint8_t)GPR_U32(ctx, 0));
    // 0x1d774c: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1d774cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d7750: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1d7750u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1d7754: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d7754u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d7758: 0x24844610  addiu       $a0, $a0, 0x4610
    ctx->pc = 0x1d7758u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17936));
    // 0x1d775c: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1d775cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1d7760: 0xc0764b8  jal         func_1D92E0
    ctx->pc = 0x1D7760u;
    SET_GPR_U32(ctx, 31, 0x1D7768u);
    ctx->pc = 0x1D7764u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7760u;
            // 0x1d7764: 0xac2045e0  sw          $zero, 0x45E0($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 17888), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D92E0u;
    if (runtime->hasFunction(0x1D92E0u)) {
        auto targetFn = runtime->lookupFunction(0x1D92E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7768u; }
        if (ctx->pc != 0x1D7768u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D92E0_0x1d92e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7768u; }
        if (ctx->pc != 0x1D7768u) { return; }
    }
    ctx->pc = 0x1D7768u;
label_1d7768:
    // 0x1d7768: 0x111980  sll         $v1, $s1, 6
    ctx->pc = 0x1d7768u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 6));
    // 0x1d776c: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1d776cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d7770: 0x712821  addu        $a1, $v1, $s1
    ctx->pc = 0x1d7770u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1d7774: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d7774u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d7778: 0x52080  sll         $a0, $a1, 2
    ctx->pc = 0x1d7778u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x1d777c: 0x3c030034  lui         $v1, 0x34
    ctx->pc = 0x1d777cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)52 << 16));
    // 0x1d7780: 0x852023  subu        $a0, $a0, $a1
    ctx->pc = 0x1d7780u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x1d7784: 0x24634610  addiu       $v1, $v1, 0x4610
    ctx->pc = 0x1d7784u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 17936));
    // 0x1d7788: 0x42080  sll         $a0, $a0, 2
    ctx->pc = 0x1d7788u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1d778c: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1d778cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1d7790: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1d7790u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1d7794: 0xae030000  sw          $v1, 0x0($s0)
    ctx->pc = 0x1d7794u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    // 0x1d7798: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1d7798u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d779c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d779cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d77a0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d77a0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d77a4: 0x3e00008  jr          $ra
    ctx->pc = 0x1D77A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D77A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D77A4u;
            // 0x1d77a8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D7768u: goto label_1d7768;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D77ACu;
    // 0x1d77ac: 0x0  nop
    ctx->pc = 0x1d77acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
