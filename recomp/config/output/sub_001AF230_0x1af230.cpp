#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AF230
// Address: 0x1af230 - 0x1af278
void sub_001AF230_0x1af230(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AF230_0x1af230");
#endif

    switch (ctx->pc) {
        case 0x1af26cu: goto label_1af26c;
        default: break;
    }

    ctx->pc = 0x1af230u;

    // 0x1af230: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1af230u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1af234: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1af234u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1af238: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1af238u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1af23c: 0x90234402  lbu         $v1, 0x4402($at)
    ctx->pc = 0x1af23cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17410)));
    // 0x1af240: 0x1064000a  beq         $v1, $a0, . + 4 + (0xA << 2)
    ctx->pc = 0x1AF240u;
    {
        const bool branch_taken_0x1af240 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x1af240) {
            ctx->pc = 0x1AF26Cu;
            goto label_1af26c;
        }
    }
    ctx->pc = 0x1AF248u;
    // 0x1af248: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1af248u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1af24c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1af24cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1af250: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1af250u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1af254: 0x24424348  addiu       $v0, $v0, 0x4348
    ctx->pc = 0x1af254u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 17224));
    // 0x1af258: 0xa0244402  sb          $a0, 0x4402($at)
    ctx->pc = 0x1af258u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17410), (uint8_t)GPR_U32(ctx, 4));
    // 0x1af25c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1af25cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1af260: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1af260u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1af264: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1AF264u;
    SET_GPR_U32(ctx, 31, 0x1AF26Cu);
    ctx->pc = 0x1AF268u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF264u;
            // 0x1af268: 0x24040063  addiu       $a0, $zero, 0x63 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF26Cu; }
        if (ctx->pc != 0x1AF26Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF26Cu; }
        if (ctx->pc != 0x1AF26Cu) { return; }
    }
    ctx->pc = 0x1AF26Cu;
label_1af26c:
    // 0x1af26c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1af26cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1af270: 0x3e00008  jr          $ra
    ctx->pc = 0x1AF270u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AF274u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF270u;
            // 0x1af274: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AF26Cu: goto label_1af26c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AF278u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
