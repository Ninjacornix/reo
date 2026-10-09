#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F2F98
// Address: 0x1f2f98 - 0x1f304c
void sub_001F2F98_0x1f2f98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F2F98_0x1f2f98");
#endif

    switch (ctx->pc) {
        case 0x1f2fdcu: goto label_1f2fdc;
        case 0x1f3008u: goto label_1f3008;
        default: break;
    }

    ctx->pc = 0x1f2f98u;

    // 0x1f2f98: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1f2f98u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1f2f9c: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1f2f9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1f2fa0: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1f2fa0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1f2fa4: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f2fa4u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2fa8: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f2fa8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f2fac: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1f2facu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1f2fb0: 0xc0102d  daddu       $v0, $a2, $zero
    ctx->pc = 0x1f2fb0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2fb4: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1f2fb4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1f2fb8: 0xa7c20008  sh          $v0, 0x8($fp)
    ctx->pc = 0x1f2fb8u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 8), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f2fbc: 0xafc00010  sw          $zero, 0x10($fp)
    ctx->pc = 0x1f2fbcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 0));
    // 0x1f2fc0: 0x27c20014  addiu       $v0, $fp, 0x14
    ctx->pc = 0x1f2fc0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 20));
    // 0x1f2fc4: 0x97c30008  lhu         $v1, 0x8($fp)
    ctx->pc = 0x1f2fc4u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f2fc8: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f2fc8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2fcc: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x1f2fccu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2fd0: 0x8fc6000c  lw          $a2, 0xC($fp)
    ctx->pc = 0x1f2fd0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f2fd4: 0xc07cbbb  jal         func_1F2EEC
    ctx->pc = 0x1F2FD4u;
    SET_GPR_U32(ctx, 31, 0x1F2FDCu);
    ctx->pc = 0x1F2EECu;
    if (runtime->hasFunction(0x1F2EECu)) {
        auto targetFn = runtime->lookupFunction(0x1F2EECu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2FDCu; }
        if (ctx->pc != 0x1F2FDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2EEC_0x1f2eec(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2FDCu; }
        if (ctx->pc != 0x1F2FDCu) { return; }
    }
    ctx->pc = 0x1F2FDCu;
label_1f2fdc:
    // 0x1f2fdc: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1f2fdcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1f2fe0: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f2fe0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f2fe4: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F2FE4u;
    {
        const bool branch_taken_0x1f2fe4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f2fe4) {
            ctx->pc = 0x1F2FF8u;
            goto label_1f2ff8;
        }
    }
    ctx->pc = 0x1F2FECu;
    // 0x1f2fec: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f2fecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f2ff0: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1F2FF0u;
    {
        const bool branch_taken_0x1f2ff0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f2ff0) {
            ctx->pc = 0x1F3034u;
            goto label_1f3034;
        }
    }
    ctx->pc = 0x1F2FF8u;
label_1f2ff8:
    // 0x1f2ff8: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f2ff8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2ffc: 0x8fc50014  lw          $a1, 0x14($fp)
    ctx->pc = 0x1f2ffcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1f3000: 0xc07c47a  jal         func_1F11E8
    ctx->pc = 0x1F3000u;
    SET_GPR_U32(ctx, 31, 0x1F3008u);
    ctx->pc = 0x1F11E8u;
    if (runtime->hasFunction(0x1F11E8u)) {
        auto targetFn = runtime->lookupFunction(0x1F11E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3008u; }
        if (ctx->pc != 0x1F3008u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F11E8_0x1f11e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3008u; }
        if (ctx->pc != 0x1F3008u) { return; }
    }
    ctx->pc = 0x1F3008u;
label_1f3008:
    // 0x1f3008: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1f3008u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1f300c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f300cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f3010: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F3010u;
    {
        const bool branch_taken_0x1f3010 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f3010) {
            ctx->pc = 0x1F3024u;
            goto label_1f3024;
        }
    }
    ctx->pc = 0x1F3018u;
    // 0x1f3018: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f3018u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f301c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1F301Cu;
    {
        const bool branch_taken_0x1f301c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f301c) {
            ctx->pc = 0x1F3034u;
            goto label_1f3034;
        }
    }
    ctx->pc = 0x1F3024u;
label_1f3024:
    // 0x1f3024: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f3024u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f3028: 0x8fc30014  lw          $v1, 0x14($fp)
    ctx->pc = 0x1f3028u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1f302c: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x1f302cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1f3030: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f3030u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
label_1f3034:
    // 0x1f3034: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f3034u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3038: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1f3038u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1f303c: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1f303cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1f3040: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1f3040u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1f3044: 0x3e00008  jr          $ra
    ctx->pc = 0x1F3044u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F2FDCu: goto label_1f2fdc;
            case 0x1F2FF8u: goto label_1f2ff8;
            case 0x1F3008u: goto label_1f3008;
            case 0x1F3024u: goto label_1f3024;
            case 0x1F3034u: goto label_1f3034;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F304Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
