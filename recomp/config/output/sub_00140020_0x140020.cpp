#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00140020
// Address: 0x140020 - 0x140070
void sub_00140020_0x140020(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00140020_0x140020");
#endif

    switch (ctx->pc) {
        case 0x140050u: goto label_140050;
        default: break;
    }

    ctx->pc = 0x140020u;

    // 0x140020: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x140020u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x140024: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x140024u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x140028: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x140028u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x14002c: 0x24508c90  addiu       $s0, $v0, -0x7370
    ctx->pc = 0x14002cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937744));
    // 0x140030: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x140030u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x140034: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x140034u;
    {
        const bool branch_taken_0x140034 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x140038u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140034u;
            // 0x140038: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140034) {
            ctx->pc = 0x140054u;
            goto label_140054;
        }
    }
    ctx->pc = 0x14003Cu;
    // 0x14003c: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x14003cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x140040: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x140040u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140044: 0x24848c98  addiu       $a0, $a0, -0x7368
    ctx->pc = 0x140044u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294937752));
    // 0x140048: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x140048u;
    SET_GPR_U32(ctx, 31, 0x140050u);
    ctx->pc = 0x14004Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x140048u;
            // 0x14004c: 0x24060c00  addiu       $a2, $zero, 0xC00 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3072));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140050u; }
        if (ctx->pc != 0x140050u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140050u; }
        if (ctx->pc != 0x140050u) { return; }
    }
    ctx->pc = 0x140050u;
label_140050:
    // 0x140050: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x140050u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_140054:
    // 0x140054: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x140054u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x140058: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x140058u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x14005c: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x14005cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x140060: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x140060u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x140064: 0x3e00008  jr          $ra
    ctx->pc = 0x140064u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x140068u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140064u;
            // 0x140068: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140050u: goto label_140050;
            case 0x140054u: goto label_140054;
            default: break;
        }
        return;
    }
    ctx->pc = 0x14006Cu;
    // 0x14006c: 0x0  nop
    ctx->pc = 0x14006cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
