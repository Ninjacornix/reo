#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CDDA0
// Address: 0x1cdda0 - 0x1cde10
void sub_001CDDA0_0x1cdda0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CDDA0_0x1cdda0");
#endif

    switch (ctx->pc) {
        case 0x1cddb0u: goto label_1cddb0;
        case 0x1cddbcu: goto label_1cddbc;
        case 0x1cddc4u: goto label_1cddc4;
        case 0x1cddd4u: goto label_1cddd4;
        case 0x1cddf0u: goto label_1cddf0;
        default: break;
    }

    ctx->pc = 0x1cdda0u;

    // 0x1cdda0: 0x27bdfef0  addiu       $sp, $sp, -0x110
    ctx->pc = 0x1cdda0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967024));
    // 0x1cdda4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1cdda4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1cdda8: 0xc042dee  jal         func_10B7B8
    ctx->pc = 0x1CDDA8u;
    SET_GPR_U32(ctx, 31, 0x1CDDB0u);
    ctx->pc = 0x1CDDACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDDA8u;
            // 0x1cddac: 0x2405005c  addiu       $a1, $zero, 0x5C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 92));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B7B8u;
    if (runtime->hasFunction(0x10B7B8u)) {
        auto targetFn = runtime->lookupFunction(0x10B7B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDDB0u; }
        if (ctx->pc != 0x1CDDB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B7B8_0x10b7b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDDB0u; }
        if (ctx->pc != 0x1CDDB0u) { return; }
    }
    ctx->pc = 0x1CDDB0u;
label_1cddb0:
    // 0x1cddb0: 0x24450001  addiu       $a1, $v0, 0x1
    ctx->pc = 0x1cddb0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1cddb4: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1CDDB4u;
    SET_GPR_U32(ctx, 31, 0x1CDDBCu);
    ctx->pc = 0x1CDDB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDDB4u;
            // 0x1cddb8: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDDBCu; }
        if (ctx->pc != 0x1CDDBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDDBCu; }
        if (ctx->pc != 0x1CDDBCu) { return; }
    }
    ctx->pc = 0x1CDDBCu;
label_1cddbc:
    // 0x1cddbc: 0xc04336a  jal         func_10CDA8
    ctx->pc = 0x1CDDBCu;
    SET_GPR_U32(ctx, 31, 0x1CDDC4u);
    ctx->pc = 0x1CDDC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDDBCu;
            // 0x1cddc0: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10CDA8u;
    if (runtime->hasFunction(0x10CDA8u)) {
        auto targetFn = runtime->lookupFunction(0x10CDA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDDC4u; }
        if (ctx->pc != 0x1CDDC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010CDA8_0x10cda8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDDC4u; }
        if (ctx->pc != 0x1CDDC4u) { return; }
    }
    ctx->pc = 0x1CDDC4u;
label_1cddc4:
    // 0x1cddc4: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1cddc4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1cddc8: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x1cddc8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1cddcc: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x1CDDCCu;
    SET_GPR_U32(ctx, 31, 0x1CDDD4u);
    ctx->pc = 0x1CDDD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDDCCu;
            // 0x1cddd0: 0x24a560a0  addiu       $a1, $a1, 0x60A0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24736));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDDD4u; }
        if (ctx->pc != 0x1CDDD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDDD4u; }
        if (ctx->pc != 0x1CDDD4u) { return; }
    }
    ctx->pc = 0x1CDDD4u;
label_1cddd4:
    // 0x1cddd4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CDDD4u;
    {
        const bool branch_taken_0x1cddd4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CDDD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDDD4u;
            // 0x1cddd8: 0x3c050025  lui         $a1, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cddd4) {
            ctx->pc = 0x1CDDE4u;
            goto label_1cdde4;
        }
    }
    ctx->pc = 0x1CDDDCu;
    // 0x1cdddc: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1CDDDCu;
    {
        const bool branch_taken_0x1cdddc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CDDE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDDDCu;
            // 0x1cdde0: 0x24020040  addiu       $v0, $zero, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cdddc) {
            ctx->pc = 0x1CDE00u;
            goto label_1cde00;
        }
    }
    ctx->pc = 0x1CDDE4u;
label_1cdde4:
    // 0x1cdde4: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x1cdde4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1cdde8: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x1CDDE8u;
    SET_GPR_U32(ctx, 31, 0x1CDDF0u);
    ctx->pc = 0x1CDDECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDDE8u;
            // 0x1cddec: 0x24a560b0  addiu       $a1, $a1, 0x60B0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24752));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDDF0u; }
        if (ctx->pc != 0x1CDDF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CDDF0u; }
        if (ctx->pc != 0x1CDDF0u) { return; }
    }
    ctx->pc = 0x1CDDF0u;
label_1cddf0:
    // 0x1cddf0: 0x24040080  addiu       $a0, $zero, 0x80
    ctx->pc = 0x1cddf0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x1cddf4: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1cddf4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1cddf8: 0x62200b  movn        $a0, $v1, $v0
    ctx->pc = 0x1cddf8u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 3));
    // 0x1cddfc: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1cddfcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_1cde00:
    // 0x1cde00: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1cde00u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cde04: 0x3e00008  jr          $ra
    ctx->pc = 0x1CDE04u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CDE08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CDE04u;
            // 0x1cde08: 0x27bd0110  addiu       $sp, $sp, 0x110 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 272));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CDDB0u: goto label_1cddb0;
            case 0x1CDDBCu: goto label_1cddbc;
            case 0x1CDDC4u: goto label_1cddc4;
            case 0x1CDDD4u: goto label_1cddd4;
            case 0x1CDDE4u: goto label_1cdde4;
            case 0x1CDDF0u: goto label_1cddf0;
            case 0x1CDE00u: goto label_1cde00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CDE0Cu;
    // 0x1cde0c: 0x0  nop
    ctx->pc = 0x1cde0cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
