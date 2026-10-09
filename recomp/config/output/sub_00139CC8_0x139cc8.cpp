#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00139CC8
// Address: 0x139cc8 - 0x139d00
void sub_00139CC8_0x139cc8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00139CC8_0x139cc8");
#endif

    switch (ctx->pc) {
        case 0x139ce4u: goto label_139ce4;
        default: break;
    }

    ctx->pc = 0x139cc8u;

    // 0x139cc8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x139cc8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x139ccc: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x139cccu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139cd0: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x139CD0u;
    {
        const bool branch_taken_0x139cd0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x139CD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139CD0u;
            // 0x139cd4: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139cd0) {
            ctx->pc = 0x139CF0u;
            goto label_139cf0;
        }
    }
    ctx->pc = 0x139CD8u;
    // 0x139cd8: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x139cd8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x139cdc: 0xc04e57e  jal         func_1395F8
    ctx->pc = 0x139CDCu;
    SET_GPR_U32(ctx, 31, 0x139CE4u);
    ctx->pc = 0x139CE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x139CDCu;
            // 0x139ce0: 0x24a5cbe8  addiu       $a1, $a1, -0x3418 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294953960));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1395F8u;
    if (runtime->hasFunction(0x1395F8u)) {
        auto targetFn = runtime->lookupFunction(0x1395F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139CE4u; }
        if (ctx->pc != 0x139CE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001395F8_0x1395f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139CE4u; }
        if (ctx->pc != 0x139CE4u) { return; }
    }
    ctx->pc = 0x139CE4u;
label_139ce4:
    // 0x139ce4: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x139CE4u;
    {
        const bool branch_taken_0x139ce4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x139CE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139CE4u;
            // 0x139ce8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139ce4) {
            ctx->pc = 0x139CF4u;
            goto label_139cf4;
        }
    }
    ctx->pc = 0x139CECu;
    // 0x139cec: 0x0  nop
    ctx->pc = 0x139cecu;
    // NOP
label_139cf0:
    // 0x139cf0: 0x8c42000c  lw          $v0, 0xC($v0)
    ctx->pc = 0x139cf0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
label_139cf4:
    // 0x139cf4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x139cf4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x139cf8: 0x3e00008  jr          $ra
    ctx->pc = 0x139CF8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x139CFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139CF8u;
            // 0x139cfc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x139CE4u: goto label_139ce4;
            case 0x139CF0u: goto label_139cf0;
            case 0x139CF4u: goto label_139cf4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x139D00u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
