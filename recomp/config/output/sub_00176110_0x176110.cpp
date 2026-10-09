#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00176110
// Address: 0x176110 - 0x176188
void sub_00176110_0x176110(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00176110_0x176110");
#endif

    switch (ctx->pc) {
        case 0x176168u: goto label_176168;
        default: break;
    }

    ctx->pc = 0x176110u;

    // 0x176110: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x176110u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x176114: 0x248300e4  addiu       $v1, $a0, 0xE4
    ctx->pc = 0x176114u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 228));
    // 0x176118: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x176118u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17611c: 0x248400bc  addiu       $a0, $a0, 0xBC
    ctx->pc = 0x17611cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 188));
    // 0x176120: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x176120u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x176124: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x176124u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x176128: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x176128u;
    {
        const bool branch_taken_0x176128 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17612Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176128u;
            // 0x17612c: 0xacc20000  sw          $v0, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x176128) {
            ctx->pc = 0x176140u;
            goto label_176140;
        }
    }
    ctx->pc = 0x176130u;
    // 0x176130: 0x8c660024  lw          $a2, 0x24($v1)
    ctx->pc = 0x176130u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x176134: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x176134u;
    {
        const bool branch_taken_0x176134 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x176138u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176134u;
            // 0x176138: 0x8c700020  lw          $s0, 0x20($v1) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x176134) {
            ctx->pc = 0x176160u;
            goto label_176160;
        }
    }
    ctx->pc = 0x17613Cu;
    // 0x17613c: 0x0  nop
    ctx->pc = 0x17613cu;
    // NOP
label_176140:
    // 0x176140: 0x8c820020  lw          $v0, 0x20($a0)
    ctx->pc = 0x176140u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 32)));
    // 0x176144: 0x4400004  bltz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x176144u;
    {
        const bool branch_taken_0x176144 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x176148u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176144u;
            // 0x176148: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x176144) {
            ctx->pc = 0x176158u;
            goto label_176158;
        }
    }
    ctx->pc = 0x17614Cu;
    // 0x17614c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x17614Cu;
    {
        const bool branch_taken_0x17614c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x176150u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17614Cu;
            // 0x176150: 0x8c860024  lw          $a2, 0x24($a0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 36)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17614c) {
            ctx->pc = 0x176160u;
            goto label_176160;
        }
    }
    ctx->pc = 0x176154u;
    // 0x176154: 0x0  nop
    ctx->pc = 0x176154u;
    // NOP
label_176158:
    // 0x176158: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x176158u;
    {
        const bool branch_taken_0x176158 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17615Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176158u;
            // 0x17615c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x176158) {
            ctx->pc = 0x176178u;
            goto label_176178;
        }
    }
    ctx->pc = 0x176160u;
label_176160:
    // 0x176160: 0xc056ea0  jal         func_15BA80
    ctx->pc = 0x176160u;
    SET_GPR_U32(ctx, 31, 0x176168u);
    ctx->pc = 0x176164u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x176160u;
            // 0x176164: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15BA80u;
    if (runtime->hasFunction(0x15BA80u)) {
        auto targetFn = runtime->lookupFunction(0x15BA80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176168u; }
        if (ctx->pc != 0x176168u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015BA80_0x15ba80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176168u; }
        if (ctx->pc != 0x176168u) { return; }
    }
    ctx->pc = 0x176168u;
label_176168:
    // 0x176168: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x176168u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x17616c: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x17616cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x176170: 0xac70f1d0  sw          $s0, -0xE30($v1)
    ctx->pc = 0x176170u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294963664), GPR_U32(ctx, 16));
    // 0x176174: 0xac82f1d4  sw          $v0, -0xE2C($a0)
    ctx->pc = 0x176174u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4294963668), GPR_U32(ctx, 2));
label_176178:
    // 0x176178: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x176178u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17617c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x17617cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x176180: 0x3e00008  jr          $ra
    ctx->pc = 0x176180u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x176184u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176180u;
            // 0x176184: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x176140u: goto label_176140;
            case 0x176158u: goto label_176158;
            case 0x176160u: goto label_176160;
            case 0x176168u: goto label_176168;
            case 0x176178u: goto label_176178;
            default: break;
        }
        return;
    }
    ctx->pc = 0x176188u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
