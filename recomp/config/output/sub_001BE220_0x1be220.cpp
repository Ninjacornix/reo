#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BE220
// Address: 0x1be220 - 0x1be280
void sub_001BE220_0x1be220(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BE220_0x1be220");
#endif

    switch (ctx->pc) {
        case 0x1be234u: goto label_1be234;
        default: break;
    }

    ctx->pc = 0x1be220u;

    // 0x1be220: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1be220u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1be224: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1be224u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1be228: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1be228u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1be22c: 0xc06f8e0  jal         func_1BE380
    ctx->pc = 0x1BE22Cu;
    SET_GPR_U32(ctx, 31, 0x1BE234u);
    ctx->pc = 0x1BE230u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE22Cu;
            // 0x1be230: 0xac2044e0  sw          $zero, 0x44E0($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 17632), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BE380u;
    if (runtime->hasFunction(0x1BE380u)) {
        auto targetFn = runtime->lookupFunction(0x1BE380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE234u; }
        if (ctx->pc != 0x1BE234u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BE380_0x1be380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE234u; }
        if (ctx->pc != 0x1BE234u) { return; }
    }
    ctx->pc = 0x1BE234u;
label_1be234:
    // 0x1be234: 0x2403ffed  addiu       $v1, $zero, -0x13
    ctx->pc = 0x1be234u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967277));
    // 0x1be238: 0x10430009  beq         $v0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1BE238u;
    {
        const bool branch_taken_0x1be238 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1BE23Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE238u;
            // 0x1be23c: 0x2403fffe  addiu       $v1, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1be238) {
            ctx->pc = 0x1BE260u;
            goto label_1be260;
        }
    }
    ctx->pc = 0x1BE240u;
    // 0x1be240: 0x10430005  beq         $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1BE240u;
    {
        const bool branch_taken_0x1be240 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1be240) {
            ctx->pc = 0x1BE258u;
            goto label_1be258;
        }
    }
    ctx->pc = 0x1BE248u;
    // 0x1be248: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1BE248u;
    {
        const bool branch_taken_0x1be248 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1be248) {
            ctx->pc = 0x1BE270u;
            goto label_1be270;
        }
    }
    ctx->pc = 0x1BE250u;
    // 0x1be250: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1BE250u;
    {
        const bool branch_taken_0x1be250 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BE254u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE250u;
            // 0x1be254: 0x2402ff9d  addiu       $v0, $zero, -0x63 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967197));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1be250) {
            ctx->pc = 0x1BE268u;
            goto label_1be268;
        }
    }
    ctx->pc = 0x1BE258u;
label_1be258:
    // 0x1be258: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1BE258u;
    {
        const bool branch_taken_0x1be258 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BE25Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE258u;
            // 0x1be25c: 0x2402fffc  addiu       $v0, $zero, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1be258) {
            ctx->pc = 0x1BE274u;
            goto label_1be274;
        }
    }
    ctx->pc = 0x1BE260u;
label_1be260:
    // 0x1be260: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1BE260u;
    {
        const bool branch_taken_0x1be260 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BE264u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE260u;
            // 0x1be264: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1be260) {
            ctx->pc = 0x1BE274u;
            goto label_1be274;
        }
    }
    ctx->pc = 0x1BE268u;
label_1be268:
    // 0x1be268: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1BE268u;
    {
        const bool branch_taken_0x1be268 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BE26Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE268u;
            // 0x1be26c: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1be268) {
            ctx->pc = 0x1BE278u;
            goto label_1be278;
        }
    }
    ctx->pc = 0x1BE270u;
label_1be270:
    // 0x1be270: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1be270u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1be274:
    // 0x1be274: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1be274u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1be278:
    // 0x1be278: 0x3e00008  jr          $ra
    ctx->pc = 0x1BE278u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BE27Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE278u;
            // 0x1be27c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BE234u: goto label_1be234;
            case 0x1BE258u: goto label_1be258;
            case 0x1BE260u: goto label_1be260;
            case 0x1BE268u: goto label_1be268;
            case 0x1BE270u: goto label_1be270;
            case 0x1BE274u: goto label_1be274;
            case 0x1BE278u: goto label_1be278;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BE280u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
