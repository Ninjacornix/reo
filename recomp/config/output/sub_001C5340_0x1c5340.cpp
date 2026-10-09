#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C5340
// Address: 0x1c5340 - 0x1c53b0
void sub_001C5340_0x1c5340(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C5340_0x1c5340");
#endif

    switch (ctx->pc) {
        case 0x1c5380u: goto label_1c5380;
        case 0x1c5398u: goto label_1c5398;
        default: break;
    }

    ctx->pc = 0x1c5340u;

    // 0x1c5340: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c5340u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c5344: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x1c5344u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x1c5348: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c5348u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c534c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c534cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c5350: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c5350u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c5354: 0x3446fbc0  ori         $a2, $v0, 0xFBC0
    ctx->pc = 0x1c5354u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)64448);
    // 0x1c5358: 0x90234488  lbu         $v1, 0x4488($at)
    ctx->pc = 0x1c5358u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17544)));
    // 0x1c535c: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1c535cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5360: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1c5360u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5364: 0xa0830019  sb          $v1, 0x19($a0)
    ctx->pc = 0x1c5364u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 25), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c5368: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c5368u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c536c: 0x9022448d  lbu         $v0, 0x448D($at)
    ctx->pc = 0x1c536cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17549)));
    // 0x1c5370: 0xa082001b  sb          $v0, 0x1B($a0)
    ctx->pc = 0x1c5370u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 27), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c5374: 0x3c010001  lui         $at, 0x1
    ctx->pc = 0x1c5374u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)1 << 16));
    // 0x1c5378: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1C5378u;
    SET_GPR_U32(ctx, 31, 0x1C5380u);
    ctx->pc = 0x1C537Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5378u;
            // 0x1c537c: 0x2012021  addu        $a0, $s0, $at (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 1)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5380u; }
        if (ctx->pc != 0x1C5380u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5380u; }
        if (ctx->pc != 0x1C5380u) { return; }
    }
    ctx->pc = 0x1C5380u;
label_1c5380:
    // 0x1c5380: 0x3c010001  lui         $at, 0x1
    ctx->pc = 0x1c5380u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)1 << 16));
    // 0x1c5384: 0x3c050032  lui         $a1, 0x32
    ctx->pc = 0x1c5384u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)50 << 16));
    // 0x1c5388: 0x2012021  addu        $a0, $s0, $at
    ctx->pc = 0x1c5388u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 1)));
    // 0x1c538c: 0x24a58b60  addiu       $a1, $a1, -0x74A0
    ctx->pc = 0x1c538cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294937440));
    // 0x1c5390: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1C5390u;
    SET_GPR_U32(ctx, 31, 0x1C5398u);
    ctx->pc = 0x1C5394u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5390u;
            // 0x1c5394: 0x24067000  addiu       $a2, $zero, 0x7000 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 28672));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5398u; }
        if (ctx->pc != 0x1C5398u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5398u; }
        if (ctx->pc != 0x1C5398u) { return; }
    }
    ctx->pc = 0x1C5398u;
label_1c5398:
    // 0x1c5398: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c5398u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c539c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c539cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c53a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1C53A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C53A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C53A0u;
            // 0x1c53a4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C5380u: goto label_1c5380;
            case 0x1C5398u: goto label_1c5398;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C53A8u;
    // 0x1c53a8: 0x0  nop
    ctx->pc = 0x1c53a8u;
    // NOP
    // 0x1c53ac: 0x0  nop
    ctx->pc = 0x1c53acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
