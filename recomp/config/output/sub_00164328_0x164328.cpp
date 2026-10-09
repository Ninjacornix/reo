#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00164328
// Address: 0x164328 - 0x164368
void sub_00164328_0x164328(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00164328_0x164328");
#endif

    switch (ctx->pc) {
        case 0x164344u: goto label_164344;
        default: break;
    }

    ctx->pc = 0x164328u;

    // 0x164328: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x164328u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16432c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16432cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x164330: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x164330u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164334: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x164334u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x164338: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x164338u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x16433c: 0xc05799e  jal         func_15E678
    ctx->pc = 0x16433Cu;
    SET_GPR_U32(ctx, 31, 0x164344u);
    ctx->pc = 0x164340u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16433Cu;
            // 0x164340: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15E678u;
    if (runtime->hasFunction(0x15E678u)) {
        auto targetFn = runtime->lookupFunction(0x15E678u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164344u; }
        if (ctx->pc != 0x164344u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E678_0x15e678(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164344u; }
        if (ctx->pc != 0x164344u) { return; }
    }
    ctx->pc = 0x164344u;
label_164344:
    // 0x164344: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x164344u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x164348: 0xae11005c  sw          $s1, 0x5C($s0)
    ctx->pc = 0x164348u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 92), GPR_U32(ctx, 17));
    // 0x16434c: 0xac510024  sw          $s1, 0x24($v0)
    ctx->pc = 0x16434cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 36), GPR_U32(ctx, 17));
    // 0x164350: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x164350u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x164354: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x164354u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x164358: 0x3e00008  jr          $ra
    ctx->pc = 0x164358u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16435Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164358u;
            // 0x16435c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x164344u: goto label_164344;
            default: break;
        }
        return;
    }
    ctx->pc = 0x164360u;
    // 0x164360: 0x3e00008  jr          $ra
    ctx->pc = 0x164360u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x164364u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164360u;
            // 0x164364: 0x8c82005c  lw          $v0, 0x5C($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 92)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x164344u: goto label_164344;
            default: break;
        }
        return;
    }
    ctx->pc = 0x164368u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
