#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00180170
// Address: 0x180170 - 0x1801f0
void sub_00180170_0x180170(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00180170_0x180170");
#endif

    switch (ctx->pc) {
        case 0x180180u: goto label_180180;
        default: break;
    }

    ctx->pc = 0x180170u;

    // 0x180170: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x180170u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x180174: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x180174u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x180178: 0xc047598  jal         func_11D660
    ctx->pc = 0x180178u;
    SET_GPR_U32(ctx, 31, 0x180180u);
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180180u; }
        if (ctx->pc != 0x180180u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180180u; }
        if (ctx->pc != 0x180180u) { return; }
    }
    ctx->pc = 0x180180u;
label_180180:
    // 0x180180: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x180180u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x180184: 0x3c041000  lui         $a0, 0x1000
    ctx->pc = 0x180184u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4096 << 16));
    // 0x180188: 0x34633830  ori         $v1, $v1, 0x3830
    ctx->pc = 0x180188u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)14384);
    // 0x18018c: 0x34843820  ori         $a0, $a0, 0x3820
    ctx->pc = 0x18018cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)14368);
    // 0x180190: 0xac600000  sw          $zero, 0x0($v1)
    ctx->pc = 0x180190u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0)); // MMIO: 0x10000000
    // 0x180194: 0x3c051000  lui         $a1, 0x1000
    ctx->pc = 0x180194u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4096 << 16));
    // 0x180198: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x180198u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0)); // MMIO: 0x10000000
    // 0x18019c: 0x34a53810  ori         $a1, $a1, 0x3810
    ctx->pc = 0x18019cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)14352);
    // 0x1801a0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1801a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1801a4: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x1801a4u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x1801a8: 0x4848e000  cfc2.ni     $t0, $vi28
    ctx->pc = 0x1801a8u;
    SET_GPR_U32(ctx, 8, ctx->vu0_itop);
    // 0x1801ac: 0x35080002  ori         $t0, $t0, 0x2
    ctx->pc = 0x1801acu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | (uint64_t)(uint16_t)2);
    // 0x1801b0: 0x48c8e000  ctc2.ni     $t0, $vi28
    ctx->pc = 0x1801b0u;
    ctx->vu0_itop = GPR_U32(ctx, 8) & 0x3FF;
    // 0x1801b4: 0x40f  sync.p
    ctx->pc = 0x1801b4u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x1801b8: 0x3c050023  lui         $a1, 0x23
    ctx->pc = 0x1801b8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)35 << 16));
    // 0x1801bc: 0x3c061000  lui         $a2, 0x1000
    ctx->pc = 0x1801bcu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)4096 << 16));
    // 0x1801c0: 0x24a5f9b0  addiu       $a1, $a1, -0x650
    ctx->pc = 0x1801c0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294965680));
    // 0x1801c4: 0x34c64000  ori         $a2, $a2, 0x4000
    ctx->pc = 0x1801c4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)16384);
    // 0x1801c8: 0x78a30000  lq          $v1, 0x0($a1)
    ctx->pc = 0x1801c8u;
    SET_GPR_VEC(ctx, 3, READ128(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1801cc: 0x7cc30000  sq          $v1, 0x0($a2)
    ctx->pc = 0x1801ccu;
    WRITE128(ADD32(GPR_U32(ctx, 6), 0), GPR_VEC(ctx, 3));
    // 0x1801d0: 0x78a40010  lq          $a0, 0x10($a1)
    ctx->pc = 0x1801d0u;
    SET_GPR_VEC(ctx, 4, READ128(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x1801d4: 0x7cc40000  sq          $a0, 0x0($a2)
    ctx->pc = 0x1801d4u;
    WRITE128(ADD32(GPR_U32(ctx, 6), 0), GPR_VEC(ctx, 4));
    // 0x1801d8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1801D8u;
    {
        const bool branch_taken_0x1801d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1801DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1801D8u;
            // 0x1801dc: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1801d8) {
            ctx->pc = 0x1801E8u;
            goto label_1801e8;
        }
    }
    ctx->pc = 0x1801E0u;
    // 0x1801e0: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x1801E0u;
    ctx->pc = 0x1801E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1801E0u;
            // 0x1801e4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1801E8u;
label_1801e8:
    // 0x1801e8: 0x3e00008  jr          $ra
    ctx->pc = 0x1801E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1801ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1801E8u;
            // 0x1801ec: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x180180u: goto label_180180;
            case 0x1801E8u: goto label_1801e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1801F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
