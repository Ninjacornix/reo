#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D76C0
// Address: 0x1d76c0 - 0x1d7730
void sub_001D76C0_0x1d76c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D76C0_0x1d76c0");
#endif

    switch (ctx->pc) {
        case 0x1d76f8u: goto label_1d76f8;
        default: break;
    }

    ctx->pc = 0x1d76c0u;

    // 0x1d76c0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1d76c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1d76c4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d76c4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d76c8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d76c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d76cc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d76ccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d76d0: 0x902245d8  lbu         $v0, 0x45D8($at)
    ctx->pc = 0x1d76d0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17880)));
    // 0x1d76d4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D76D4u;
    {
        const bool branch_taken_0x1d76d4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D76D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D76D4u;
            // 0x1d76d8: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d76d4) {
            ctx->pc = 0x1D76F0u;
            goto label_1d76f0;
        }
    }
    ctx->pc = 0x1D76DCu;
    // 0x1d76dc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d76dcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d76e0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d76e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d76e4: 0x8c2345e0  lw          $v1, 0x45E0($at)
    ctx->pc = 0x1d76e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17888)));
    // 0x1d76e8: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1D76E8u;
    {
        const bool branch_taken_0x1d76e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D76ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D76E8u;
            // 0x1d76ec: 0xae030000  sw          $v1, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d76e8) {
            ctx->pc = 0x1D7720u;
            goto label_1d7720;
        }
    }
    ctx->pc = 0x1D76F0u;
label_1d76f0:
    // 0x1d76f0: 0xc0764a0  jal         func_1D9280
    ctx->pc = 0x1D76F0u;
    SET_GPR_U32(ctx, 31, 0x1D76F8u);
    ctx->pc = 0x1D9280u;
    if (runtime->hasFunction(0x1D9280u)) {
        auto targetFn = runtime->lookupFunction(0x1D9280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D76F8u; }
        if (ctx->pc != 0x1D76F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9280_0x1d9280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D76F8u; }
        if (ctx->pc != 0x1D76F8u) { return; }
    }
    ctx->pc = 0x1D76F8u;
label_1d76f8:
    // 0x1d76f8: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1d76f8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d76fc: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d76fcu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d7700: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1D7700u;
    {
        const bool branch_taken_0x1d7700 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D7704u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7700u;
            // 0x1d7704: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d7700) {
            ctx->pc = 0x1D7720u;
            goto label_1d7720;
        }
    }
    ctx->pc = 0x1D7708u;
    // 0x1d7708: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d7708u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d770c: 0xa02345d8  sb          $v1, 0x45D8($at)
    ctx->pc = 0x1d770cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17880), (uint8_t)GPR_U32(ctx, 3));
    // 0x1d7710: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x1d7710u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1d7714: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d7714u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d7718: 0xac2345e0  sw          $v1, 0x45E0($at)
    ctx->pc = 0x1d7718u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17888), GPR_U32(ctx, 3));
    // 0x1d771c: 0x0  nop
    ctx->pc = 0x1d771cu;
    // NOP
label_1d7720:
    // 0x1d7720: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d7720u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d7724: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d7724u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d7728: 0x3e00008  jr          $ra
    ctx->pc = 0x1D7728u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D772Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7728u;
            // 0x1d772c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D76F0u: goto label_1d76f0;
            case 0x1D76F8u: goto label_1d76f8;
            case 0x1D7720u: goto label_1d7720;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D7730u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
