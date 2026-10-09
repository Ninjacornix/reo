#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00179A18
// Address: 0x179a18 - 0x179a60
void sub_00179A18_0x179a18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00179A18_0x179a18");
#endif

    switch (ctx->pc) {
        case 0x179a38u: goto label_179a38;
        default: break;
    }

    ctx->pc = 0x179a18u;

    // 0x179a18: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x179a18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x179a1c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x179a1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x179a20: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x179a20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x179a24: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x179a24u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179a28: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x179a28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x179a2c: 0x8c820004  lw          $v0, 0x4($a0)
    ctx->pc = 0x179a2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x179a30: 0xc05e4a6  jal         func_179298
    ctx->pc = 0x179A30u;
    SET_GPR_U32(ctx, 31, 0x179A38u);
    ctx->pc = 0x179A34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179A30u;
            // 0x179a34: 0x245000b0  addiu       $s0, $v0, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 176));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179298u;
    if (runtime->hasFunction(0x179298u)) {
        auto targetFn = runtime->lookupFunction(0x179298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179A38u; }
        if (ctx->pc != 0x179A38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179298_0x179298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179A38u; }
        if (ctx->pc != 0x179A38u) { return; }
    }
    ctx->pc = 0x179A38u;
label_179a38:
    // 0x179a38: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x179A38u;
    {
        const bool branch_taken_0x179a38 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x179a38) {
            ctx->pc = 0x179A3Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x179A38u;
            // 0x179a3c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x179A50u;
            goto label_179a50;
        }
    }
    ctx->pc = 0x179A40u;
    // 0x179a40: 0x92030000  lbu         $v1, 0x0($s0)
    ctx->pc = 0x179a40u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x179a44: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x179a44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x179a48: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x179a48u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x179a4c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x179a4cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_179a50:
    // 0x179a50: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x179a50u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x179a54: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x179a54u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x179a58: 0x3e00008  jr          $ra
    ctx->pc = 0x179A58u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x179A5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179A58u;
            // 0x179a5c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179A38u: goto label_179a38;
            case 0x179A50u: goto label_179a50;
            default: break;
        }
        return;
    }
    ctx->pc = 0x179A60u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
