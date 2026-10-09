#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00179AA8
// Address: 0x179aa8 - 0x179af0
void sub_00179AA8_0x179aa8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00179AA8_0x179aa8");
#endif

    switch (ctx->pc) {
        case 0x179ac8u: goto label_179ac8;
        default: break;
    }

    ctx->pc = 0x179aa8u;

    // 0x179aa8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x179aa8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x179aac: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x179aacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x179ab0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x179ab0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x179ab4: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x179ab4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179ab8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x179ab8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x179abc: 0x8c820004  lw          $v0, 0x4($a0)
    ctx->pc = 0x179abcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x179ac0: 0xc05e4a6  jal         func_179298
    ctx->pc = 0x179AC0u;
    SET_GPR_U32(ctx, 31, 0x179AC8u);
    ctx->pc = 0x179AC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179AC0u;
            // 0x179ac4: 0x245000b0  addiu       $s0, $v0, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 176));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179298u;
    if (runtime->hasFunction(0x179298u)) {
        auto targetFn = runtime->lookupFunction(0x179298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179AC8u; }
        if (ctx->pc != 0x179AC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179298_0x179298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179AC8u; }
        if (ctx->pc != 0x179AC8u) { return; }
    }
    ctx->pc = 0x179AC8u;
label_179ac8:
    // 0x179ac8: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x179AC8u;
    {
        const bool branch_taken_0x179ac8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x179ac8) {
            ctx->pc = 0x179ACCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x179AC8u;
            // 0x179acc: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x179AE0u;
            goto label_179ae0;
        }
    }
    ctx->pc = 0x179AD0u;
    // 0x179ad0: 0x92030002  lbu         $v1, 0x2($s0)
    ctx->pc = 0x179ad0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x179ad4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x179ad4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x179ad8: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x179ad8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x179adc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x179adcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_179ae0:
    // 0x179ae0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x179ae0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x179ae4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x179ae4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x179ae8: 0x3e00008  jr          $ra
    ctx->pc = 0x179AE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x179AECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179AE8u;
            // 0x179aec: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179AC8u: goto label_179ac8;
            case 0x179AE0u: goto label_179ae0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x179AF0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
