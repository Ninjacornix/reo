#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013EF80
// Address: 0x13ef80 - 0x13f038
void sub_0013EF80_0x13ef80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013EF80_0x13ef80");
#endif

    switch (ctx->pc) {
        case 0x13efb4u: goto label_13efb4;
        case 0x13efb8u: goto label_13efb8;
        case 0x13f008u: goto label_13f008;
        default: break;
    }

    ctx->pc = 0x13ef80u;

    // 0x13ef80: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x13ef80u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ef84: 0x3402bb80  ori         $v0, $zero, 0xBB80
    ctx->pc = 0x13ef84u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)48000);
    // 0x13ef88: 0x46001a  div         $zero, $v0, $a2
    ctx->pc = 0x13ef88u;
    { int32_t divisor = GPR_S32(ctx, 6);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x13ef8c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13ef8cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13ef90: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13ef90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13ef94: 0x50c00001  beql        $a2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x13EF94u;
    {
        const bool branch_taken_0x13ef94 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x13ef94) {
            ctx->pc = 0x13EF98u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13EF94u;
            // 0x13ef98: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x13EF9Cu;
            goto label_13ef9c;
        }
    }
    ctx->pc = 0x13EF9Cu;
label_13ef9c:
    // 0x13ef9c: 0x1810  mfhi        $v1
    ctx->pc = 0x13ef9cu;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x13efa0: 0x5060000d  beql        $v1, $zero, . + 4 + (0xD << 2)
    ctx->pc = 0x13EFA0u;
    {
        const bool branch_taken_0x13efa0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x13efa0) {
            ctx->pc = 0x13EFA4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13EFA0u;
            // 0x13efa4: 0x3402bb80  ori         $v0, $zero, 0xBB80 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)48000);
        ctx->in_delay_slot = false;
            ctx->pc = 0x13EFD8u;
            goto label_13efd8;
        }
    }
    ctx->pc = 0x13EFA8u;
    // 0x13efa8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13efa8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13efac: 0xc045a12  jal         func_116848
    ctx->pc = 0x13EFACu;
    SET_GPR_U32(ctx, 31, 0x13EFB4u);
    ctx->pc = 0x13EFB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13EFACu;
            // 0x13efb0: 0x2484d8c0  addiu       $a0, $a0, -0x2740 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957248));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EFB4u; }
        if (ctx->pc != 0x13EFB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EFB4u; }
        if (ctx->pc != 0x13EFB4u) { return; }
    }
    ctx->pc = 0x13EFB4u;
label_13efb4:
    // 0x13efb4: 0x0  nop
    ctx->pc = 0x13efb4u;
    // NOP
label_13efb8:
    // 0x13efb8: 0x0  nop
    ctx->pc = 0x13efb8u;
    // NOP
    // 0x13efbc: 0x0  nop
    ctx->pc = 0x13efbcu;
    // NOP
    // 0x13efc0: 0x0  nop
    ctx->pc = 0x13efc0u;
    // NOP
    // 0x13efc4: 0x0  nop
    ctx->pc = 0x13efc4u;
    // NOP
    // 0x13efc8: 0x0  nop
    ctx->pc = 0x13efc8u;
    // NOP
    // 0x13efcc: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x13EFCCu;
    {
        const bool branch_taken_0x13efcc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x13efcc) {
            ctx->pc = 0x13EFB8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13efb8;
        }
    }
    ctx->pc = 0x13EFD4u;
    // 0x13efd4: 0x0  nop
    ctx->pc = 0x13efd4u;
    // NOP
label_13efd8:
    // 0x13efd8: 0x10c20014  beq         $a2, $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x13EFD8u;
    {
        const bool branch_taken_0x13efd8 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 2));
        ctx->pc = 0x13EFDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EFD8u;
            // 0x13efdc: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13efd8) {
            ctx->pc = 0x13F02Cu;
            goto label_13f02c;
        }
    }
    ctx->pc = 0x13EFE0u;
    // 0x13efe0: 0x46001a  div         $zero, $v0, $a2
    ctx->pc = 0x13efe0u;
    { int32_t divisor = GPR_S32(ctx, 6);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x13efe4: 0x50c00001  beql        $a2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x13EFE4u;
    {
        const bool branch_taken_0x13efe4 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x13efe4) {
            ctx->pc = 0x13EFE8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13EFE4u;
            // 0x13efe8: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x13EFECu;
            goto label_13efec;
        }
    }
    ctx->pc = 0x13EFECu;
label_13efec:
    // 0x13efec: 0x1012  mflo        $v0
    ctx->pc = 0x13efecu;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x13eff0: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x13eff0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x13eff4: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x13EFF4u;
    {
        const bool branch_taken_0x13eff4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13EFF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EFF4u;
            // 0x13eff8: 0xc0282d  daddu       $a1, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13eff4) {
            ctx->pc = 0x13F028u;
            goto label_13f028;
        }
    }
    ctx->pc = 0x13EFFCu;
    // 0x13effc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13effcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13f000: 0xc045a12  jal         func_116848
    ctx->pc = 0x13F000u;
    SET_GPR_U32(ctx, 31, 0x13F008u);
    ctx->pc = 0x13F004u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F000u;
            // 0x13f004: 0x2484d8c0  addiu       $a0, $a0, -0x2740 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957248));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F008u; }
        if (ctx->pc != 0x13F008u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F008u; }
        if (ctx->pc != 0x13F008u) { return; }
    }
    ctx->pc = 0x13F008u;
label_13f008:
    // 0x13f008: 0x0  nop
    ctx->pc = 0x13f008u;
    // NOP
    // 0x13f00c: 0x0  nop
    ctx->pc = 0x13f00cu;
    // NOP
    // 0x13f010: 0x0  nop
    ctx->pc = 0x13f010u;
    // NOP
    // 0x13f014: 0x0  nop
    ctx->pc = 0x13f014u;
    // NOP
    // 0x13f018: 0x0  nop
    ctx->pc = 0x13f018u;
    // NOP
    // 0x13f01c: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x13F01Cu;
    {
        const bool branch_taken_0x13f01c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x13f01c) {
            ctx->pc = 0x13F008u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13f008;
        }
    }
    ctx->pc = 0x13F024u;
    // 0x13f024: 0x0  nop
    ctx->pc = 0x13f024u;
    // NOP
label_13f028:
    // 0x13f028: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13f028u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_13f02c:
    // 0x13f02c: 0xac860028  sw          $a2, 0x28($a0)
    ctx->pc = 0x13f02cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 40), GPR_U32(ctx, 6));
    // 0x13f030: 0x3e00008  jr          $ra
    ctx->pc = 0x13F030u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F034u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F030u;
            // 0x13f034: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13EF9Cu: goto label_13ef9c;
            case 0x13EFB4u: goto label_13efb4;
            case 0x13EFB8u: goto label_13efb8;
            case 0x13EFD8u: goto label_13efd8;
            case 0x13EFECu: goto label_13efec;
            case 0x13F008u: goto label_13f008;
            case 0x13F028u: goto label_13f028;
            case 0x13F02Cu: goto label_13f02c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F038u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
