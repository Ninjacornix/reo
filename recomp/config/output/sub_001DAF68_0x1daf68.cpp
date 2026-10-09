#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DAF68
// Address: 0x1daf68 - 0x1db010
void sub_001DAF68_0x1daf68(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DAF68_0x1daf68");
#endif

    switch (ctx->pc) {
        case 0x1daf84u: goto label_1daf84;
        case 0x1dafa0u: goto label_1dafa0;
        case 0x1dafe4u: goto label_1dafe4;
        case 0x1daff8u: goto label_1daff8;
        default: break;
    }

    ctx->pc = 0x1daf68u;

    // 0x1daf68: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1daf68u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1daf6c: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1daf6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1daf70: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1daf70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1daf74: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1daf74u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1daf78: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1daf78u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1daf7c: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1daf7cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1daf80: 0xafc0000c  sw          $zero, 0xC($fp)
    ctx->pc = 0x1daf80u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 0));
label_1daf84:
    // 0x1daf84: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1daf84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1daf88: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1daf88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1daf8c: 0x27c3000c  addiu       $v1, $fp, 0xC
    ctx->pc = 0x1daf8cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 12));
    // 0x1daf90: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1daf90u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1daf94: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x1daf94u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1daf98: 0xc07c499  jal         func_1F1264
    ctx->pc = 0x1DAF98u;
    SET_GPR_U32(ctx, 31, 0x1DAFA0u);
    ctx->pc = 0x1F1264u;
    if (runtime->hasFunction(0x1F1264u)) {
        auto targetFn = runtime->lookupFunction(0x1F1264u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DAFA0u; }
        if (ctx->pc != 0x1DAFA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1264_0x1f1264(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DAFA0u; }
        if (ctx->pc != 0x1DAFA0u) { return; }
    }
    ctx->pc = 0x1DAFA0u;
label_1dafa0:
    // 0x1dafa0: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1dafa0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1dafa4: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x1dafa4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dafa8: 0x2402e4aa  addiu       $v0, $zero, -0x1B56
    ctx->pc = 0x1dafa8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294960298));
    // 0x1dafac: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DAFACu;
    {
        const bool branch_taken_0x1dafac = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1dafac) {
            ctx->pc = 0x1DAFBCu;
            goto label_1dafbc;
        }
    }
    ctx->pc = 0x1DAFB4u;
    // 0x1dafb4: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1DAFB4u;
    {
        const bool branch_taken_0x1dafb4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dafb4) {
            ctx->pc = 0x1DAFECu;
            goto label_1dafec;
        }
    }
    ctx->pc = 0x1DAFBCu;
label_1dafbc:
    // 0x1dafbc: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1dafbcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1dafc0: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DAFC0u;
    {
        const bool branch_taken_0x1dafc0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1dafc0) {
            ctx->pc = 0x1DAFD0u;
            goto label_1dafd0;
        }
    }
    ctx->pc = 0x1DAFC8u;
    // 0x1dafc8: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1DAFC8u;
    {
        const bool branch_taken_0x1dafc8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dafc8) {
            ctx->pc = 0x1DAFECu;
            goto label_1dafec;
        }
    }
    ctx->pc = 0x1DAFD0u;
label_1dafd0:
    // 0x1dafd0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dafd0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dafd4: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1dafd4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1dafd8: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1dafd8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1dafdc: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1DAFDCu;
    SET_GPR_U32(ctx, 31, 0x1DAFE4u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DAFE4u; }
        if (ctx->pc != 0x1DAFE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DAFE4u; }
        if (ctx->pc != 0x1DAFE4u) { return; }
    }
    ctx->pc = 0x1DAFE4u;
label_1dafe4:
    // 0x1dafe4: 0x1000ffe7  b           . + 4 + (-0x19 << 2)
    ctx->pc = 0x1DAFE4u;
    {
        const bool branch_taken_0x1dafe4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dafe4) {
            ctx->pc = 0x1DAF84u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1daf84;
        }
    }
    ctx->pc = 0x1DAFECu;
label_1dafec:
    // 0x1dafec: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1dafecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1daff0: 0xc079f90  jal         func_1E7E40
    ctx->pc = 0x1DAFF0u;
    SET_GPR_U32(ctx, 31, 0x1DAFF8u);
    ctx->pc = 0x1E7E40u;
    if (runtime->hasFunction(0x1E7E40u)) {
        auto targetFn = runtime->lookupFunction(0x1E7E40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DAFF8u; }
        if (ctx->pc != 0x1DAFF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E7E40_0x1e7e40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DAFF8u; }
        if (ctx->pc != 0x1DAFF8u) { return; }
    }
    ctx->pc = 0x1DAFF8u;
label_1daff8:
    // 0x1daff8: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1daff8u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1daffc: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1daffcu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1db000: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1db000u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1db004: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1db004u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1db008: 0x3e00008  jr          $ra
    ctx->pc = 0x1DB008u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DAF84u: goto label_1daf84;
            case 0x1DAFA0u: goto label_1dafa0;
            case 0x1DAFBCu: goto label_1dafbc;
            case 0x1DAFD0u: goto label_1dafd0;
            case 0x1DAFE4u: goto label_1dafe4;
            case 0x1DAFECu: goto label_1dafec;
            case 0x1DAFF8u: goto label_1daff8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DB010u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
