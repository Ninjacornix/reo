#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00130748
// Address: 0x130748 - 0x130798
void sub_00130748_0x130748(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00130748_0x130748");
#endif

    switch (ctx->pc) {
        case 0x130764u: goto label_130764;
        case 0x130768u: goto label_130768;
        case 0x130770u: goto label_130770;
        default: break;
    }

    ctx->pc = 0x130748u;

    // 0x130748: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x130748u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13074c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13074cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x130750: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x130750u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130754: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x130754u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x130758: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x130758u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x13075c: 0xc04c1b8  jal         func_1306E0
    ctx->pc = 0x13075Cu;
    SET_GPR_U32(ctx, 31, 0x130764u);
    ctx->pc = 0x130760u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13075Cu;
            // 0x130760: 0x24110001  addiu       $s1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1306E0u;
    if (runtime->hasFunction(0x1306E0u)) {
        auto targetFn = runtime->lookupFunction(0x1306E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130764u; }
        if (ctx->pc != 0x130764u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001306E0_0x1306e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130764u; }
        if (ctx->pc != 0x130764u) { return; }
    }
    ctx->pc = 0x130764u;
label_130764:
    // 0x130764: 0x0  nop
    ctx->pc = 0x130764u;
    // NOP
label_130768:
    // 0x130768: 0xc04a808  jal         func_12A020
    ctx->pc = 0x130768u;
    SET_GPR_U32(ctx, 31, 0x130770u);
    ctx->pc = 0x12A020u;
    if (runtime->hasFunction(0x12A020u)) {
        auto targetFn = runtime->lookupFunction(0x12A020u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130770u; }
        if (ctx->pc != 0x130770u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012A020_0x12a020(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130770u; }
        if (ctx->pc != 0x130770u) { return; }
    }
    ctx->pc = 0x130770u;
label_130770:
    // 0x130770: 0x82020001  lb          $v0, 0x1($s0)
    ctx->pc = 0x130770u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x130774: 0x1451fffc  bne         $v0, $s1, . + 4 + (-0x4 << 2)
    ctx->pc = 0x130774u;
    {
        const bool branch_taken_0x130774 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 17));
        if (branch_taken_0x130774) {
            ctx->pc = 0x130768u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_130768;
        }
    }
    ctx->pc = 0x13077Cu;
    // 0x13077c: 0x8e020020  lw          $v0, 0x20($s0)
    ctx->pc = 0x13077cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x130780: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x130780u;
    {
        const bool branch_taken_0x130780 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x130784u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130780u;
            // 0x130784: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x130780) {
            ctx->pc = 0x130768u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_130768;
        }
    }
    ctx->pc = 0x130788u;
    // 0x130788: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x130788u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13078c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13078cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x130790: 0x3e00008  jr          $ra
    ctx->pc = 0x130790u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130794u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130790u;
            // 0x130794: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130764u: goto label_130764;
            case 0x130768u: goto label_130768;
            case 0x130770u: goto label_130770;
            default: break;
        }
        return;
    }
    ctx->pc = 0x130798u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
