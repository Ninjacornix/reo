#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016B410
// Address: 0x16b410 - 0x16b470
void sub_0016B410_0x16b410(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016B410_0x16b410");
#endif

    switch (ctx->pc) {
        case 0x16b424u: goto label_16b424;
        case 0x16b458u: goto label_16b458;
        default: break;
    }

    ctx->pc = 0x16b410u;

    // 0x16b410: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x16b410u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16b414: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16b414u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16b418: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x16b418u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x16b41c: 0xc05a98e  jal         func_16A638
    ctx->pc = 0x16B41Cu;
    SET_GPR_U32(ctx, 31, 0x16B424u);
    ctx->pc = 0x16B420u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B41Cu;
            // 0x16b420: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16A638u;
    if (runtime->hasFunction(0x16A638u)) {
        auto targetFn = runtime->lookupFunction(0x16A638u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B424u; }
        if (ctx->pc != 0x16B424u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016A638_0x16a638(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B424u; }
        if (ctx->pc != 0x16B424u) { return; }
    }
    ctx->pc = 0x16B424u;
label_16b424:
    // 0x16b424: 0x8e060008  lw          $a2, 0x8($s0)
    ctx->pc = 0x16b424u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x16b428: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16b428u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b42c: 0x261009a0  addiu       $s0, $s0, 0x9A0
    ctx->pc = 0x16b42cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 2464));
    // 0x16b430: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x16b430u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b434: 0x1cc00002  bgtz        $a2, . + 4 + (0x2 << 2)
    ctx->pc = 0x16B434u;
    {
        const bool branch_taken_0x16b434 = (GPR_S64(ctx, 6) > 0);
        ctx->pc = 0x16B438u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B434u;
            // 0x16b438: 0x8e070058  lw          $a3, 0x58($s0) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 88)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16b434) {
            ctx->pc = 0x16B440u;
            goto label_16b440;
        }
    }
    ctx->pc = 0x16B43Cu;
    // 0x16b43c: 0x8c46000c  lw          $a2, 0xC($v0)
    ctx->pc = 0x16b43cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
label_16b440:
    // 0x16b440: 0x6102a  slt         $v0, $zero, $a2
    ctx->pc = 0x16b440u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x16b444: 0xe2300a  movz        $a2, $a3, $v0
    ctx->pc = 0x16b444u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 7));
    // 0x16b448: 0xc7182a  slt         $v1, $a2, $a3
    ctx->pc = 0x16b448u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 7)) ? 1 : 0);
    // 0x16b44c: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x16b44cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b450: 0xc059d52  jal         func_167548
    ctx->pc = 0x16B450u;
    SET_GPR_U32(ctx, 31, 0x16B458u);
    ctx->pc = 0x16B454u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B450u;
            // 0x16b454: 0xe3800a  movz        $s0, $a3, $v1 (Delay Slot)
        if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167548u;
    if (runtime->hasFunction(0x167548u)) {
        auto targetFn = runtime->lookupFunction(0x167548u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B458u; }
        if (ctx->pc != 0x16B458u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167548_0x167548(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B458u; }
        if (ctx->pc != 0x16B458u) { return; }
    }
    ctx->pc = 0x16B458u;
label_16b458:
    // 0x16b458: 0x50102a  slt         $v0, $v0, $s0
    ctx->pc = 0x16b458u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x16b45c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16b45cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16b460: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x16b460u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16b464: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x16b464u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x16b468: 0x3e00008  jr          $ra
    ctx->pc = 0x16B468u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16B46Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B468u;
            // 0x16b46c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16B424u: goto label_16b424;
            case 0x16B440u: goto label_16b440;
            case 0x16B458u: goto label_16b458;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16B470u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
