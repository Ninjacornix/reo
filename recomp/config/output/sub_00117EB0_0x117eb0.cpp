#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00117EB0
// Address: 0x117eb0 - 0x117f08
void sub_00117EB0_0x117eb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00117EB0_0x117eb0");
#endif

    switch (ctx->pc) {
        case 0x117ec8u: goto label_117ec8;
        case 0x117ef0u: goto label_117ef0;
        default: break;
    }

    ctx->pc = 0x117eb0u;

    // 0x117eb0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x117eb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x117eb4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x117eb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x117eb8: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x117eb8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x117ebc: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x117ebcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x117ec0: 0xc047598  jal         func_11D660
    ctx->pc = 0x117EC0u;
    SET_GPR_U32(ctx, 31, 0x117EC8u);
    ctx->pc = 0x117EC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117EC0u;
            // 0x117ec4: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117EC8u; }
        if (ctx->pc != 0x117EC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117EC8u; }
        if (ctx->pc != 0x117EC8u) { return; }
    }
    ctx->pc = 0x117EC8u;
label_117ec8:
    // 0x117ec8: 0x8e11000c  lw          $s1, 0xC($s0)
    ctx->pc = 0x117ec8u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x117ecc: 0x56200003  bnel        $s1, $zero, . + 4 + (0x3 << 2)
    ctx->pc = 0x117ECCu;
    {
        const bool branch_taken_0x117ecc = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0x117ecc) {
            ctx->pc = 0x117ED0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x117ECCu;
            // 0x117ed0: 0x8e23003c  lw          $v1, 0x3C($s1) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 60)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x117EDCu;
            goto label_117edc;
        }
    }
    ctx->pc = 0x117ED4u;
    // 0x117ed4: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x117ED4u;
    {
        const bool branch_taken_0x117ed4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x117ED8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117ED4u;
            // 0x117ed8: 0xae000004  sw          $zero, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x117ed4) {
            ctx->pc = 0x117EE8u;
            goto label_117ee8;
        }
    }
    ctx->pc = 0x117EDCu;
label_117edc:
    // 0x117edc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x117edcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x117ee0: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x117ee0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x117ee4: 0xae03000c  sw          $v1, 0xC($s0)
    ctx->pc = 0x117ee4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 3));
label_117ee8:
    // 0x117ee8: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x117EE8u;
    SET_GPR_U32(ctx, 31, 0x117EF0u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117EF0u; }
        if (ctx->pc != 0x117EF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117EF0u; }
        if (ctx->pc != 0x117EF0u) { return; }
    }
    ctx->pc = 0x117EF0u;
label_117ef0:
    // 0x117ef0: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x117ef0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117ef4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x117ef4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x117ef8: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x117ef8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x117efc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x117efcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x117f00: 0x3e00008  jr          $ra
    ctx->pc = 0x117F00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x117F04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117F00u;
            // 0x117f04: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x117EC8u: goto label_117ec8;
            case 0x117EDCu: goto label_117edc;
            case 0x117EE8u: goto label_117ee8;
            case 0x117EF0u: goto label_117ef0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x117F08u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
