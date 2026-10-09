#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001EB4F8
// Address: 0x1eb4f8 - 0x1eb684
void sub_001EB4F8_0x1eb4f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001EB4F8_0x1eb4f8");
#endif

    switch (ctx->pc) {
        case 0x1eb528u: goto label_1eb528;
        case 0x1eb540u: goto label_1eb540;
        case 0x1eb57cu: goto label_1eb57c;
        case 0x1eb5c0u: goto label_1eb5c0;
        case 0x1eb5d0u: goto label_1eb5d0;
        case 0x1eb5f0u: goto label_1eb5f0;
        case 0x1eb5fcu: goto label_1eb5fc;
        case 0x1eb60cu: goto label_1eb60c;
        case 0x1eb664u: goto label_1eb664;
        default: break;
    }

    ctx->pc = 0x1eb4f8u;

    // 0x1eb4f8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1eb4f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1eb4fc: 0xffbe0030  sd          $fp, 0x30($sp)
    ctx->pc = 0x1eb4fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 30));
    // 0x1eb500: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x1eb500u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x1eb504: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1eb504u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1eb508: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1eb508u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1eb50c: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1eb50cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1eb510: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1eb510u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1eb514: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1eb514u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1eb518: 0xafc80010  sw          $t0, 0x10($fp)
    ctx->pc = 0x1eb518u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 8));
    // 0x1eb51c: 0x24041048  addiu       $a0, $zero, 0x1048
    ctx->pc = 0x1eb51cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4168));
    // 0x1eb520: 0xc041bb8  jal         func_106EE0
    ctx->pc = 0x1EB520u;
    SET_GPR_U32(ctx, 31, 0x1EB528u);
    ctx->pc = 0x106EE0u;
    if (runtime->hasFunction(0x106EE0u)) {
        auto targetFn = runtime->lookupFunction(0x106EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EB528u; }
        if (ctx->pc != 0x1EB528u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00106EE0_0x106ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EB528u; }
        if (ctx->pc != 0x1EB528u) { return; }
    }
    ctx->pc = 0x1EB528u;
label_1eb528:
    // 0x1eb528: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1eb528u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1eb52c: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1eb52cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1eb530: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1eb530u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1eb534: 0x8fc60010  lw          $a2, 0x10($fp)
    ctx->pc = 0x1eb534u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1eb538: 0xc07ac19  jal         func_1EB064
    ctx->pc = 0x1EB538u;
    SET_GPR_U32(ctx, 31, 0x1EB540u);
    ctx->pc = 0x1EB064u;
    if (runtime->hasFunction(0x1EB064u)) {
        auto targetFn = runtime->lookupFunction(0x1EB064u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EB540u; }
        if (ctx->pc != 0x1EB540u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001EB064_0x1eb064(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EB540u; }
        if (ctx->pc != 0x1EB540u) { return; }
    }
    ctx->pc = 0x1EB540u;
label_1eb540:
    // 0x1eb540: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1eb540u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1eb544: 0x24420007  addiu       $v0, $v0, 0x7
    ctx->pc = 0x1eb544u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 7));
    // 0x1eb548: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1eb548u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1eb54c: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1eb54cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1eb550: 0x4410004  bgez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1EB550u;
    {
        const bool branch_taken_0x1eb550 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1eb550) {
            ctx->pc = 0x1EB564u;
            goto label_1eb564;
        }
    }
    ctx->pc = 0x1EB558u;
    // 0x1eb558: 0x8fc3002c  lw          $v1, 0x2C($fp)
    ctx->pc = 0x1eb558u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1eb55c: 0x24630007  addiu       $v1, $v1, 0x7
    ctx->pc = 0x1eb55cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 7));
    // 0x1eb560: 0xafc3002c  sw          $v1, 0x2C($fp)
    ctx->pc = 0x1eb560u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 3));
label_1eb564:
    // 0x1eb564: 0x8fc3002c  lw          $v1, 0x2C($fp)
    ctx->pc = 0x1eb564u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1eb568: 0x310c3  sra         $v0, $v1, 3
    ctx->pc = 0x1eb568u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 3));
    // 0x1eb56c: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1eb56cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1eb570: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1eb570u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb574: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1eb574u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1eb578: 0xafc00018  sw          $zero, 0x18($fp)
    ctx->pc = 0x1eb578u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 0));
label_1eb57c:
    // 0x1eb57c: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1eb57cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1eb580: 0x8fc3001c  lw          $v1, 0x1C($fp)
    ctx->pc = 0x1eb580u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1eb584: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x1eb584u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1eb588: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1EB588u;
    {
        const bool branch_taken_0x1eb588 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1eb588) {
            ctx->pc = 0x1EB598u;
            goto label_1eb598;
        }
    }
    ctx->pc = 0x1EB590u;
    // 0x1eb590: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x1EB590u;
    {
        const bool branch_taken_0x1eb590 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1eb590) {
            ctx->pc = 0x1EB658u;
            goto label_1eb658;
        }
    }
    ctx->pc = 0x1EB598u;
label_1eb598:
    // 0x1eb598: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1eb598u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1eb59c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1eb59cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1eb5a0: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1eb5a0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1eb5a4: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1eb5a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1eb5a8: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1eb5a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1eb5ac: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1eb5acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1eb5b0: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1eb5b0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1eb5b4: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1eb5b4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1eb5b8: 0xc07a071  jal         func_1E81C4
    ctx->pc = 0x1EB5B8u;
    SET_GPR_U32(ctx, 31, 0x1EB5C0u);
    ctx->pc = 0x1E81C4u;
    if (runtime->hasFunction(0x1E81C4u)) {
        auto targetFn = runtime->lookupFunction(0x1E81C4u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EB5C0u; }
        if (ctx->pc != 0x1EB5C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E81C4_0x1e81c4(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EB5C0u; }
        if (ctx->pc != 0x1EB5C0u) { return; }
    }
    ctx->pc = 0x1EB5C0u;
label_1eb5c0:
    // 0x1eb5c0: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1eb5c0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1eb5c4: 0x8fc40024  lw          $a0, 0x24($fp)
    ctx->pc = 0x1eb5c4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1eb5c8: 0xc07a071  jal         func_1E81C4
    ctx->pc = 0x1EB5C8u;
    SET_GPR_U32(ctx, 31, 0x1EB5D0u);
    ctx->pc = 0x1E81C4u;
    if (runtime->hasFunction(0x1E81C4u)) {
        auto targetFn = runtime->lookupFunction(0x1E81C4u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EB5D0u; }
        if (ctx->pc != 0x1EB5D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E81C4_0x1e81c4(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EB5D0u; }
        if (ctx->pc != 0x1EB5D0u) { return; }
    }
    ctx->pc = 0x1EB5D0u;
label_1eb5d0:
    // 0x1eb5d0: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1eb5d0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1eb5d4: 0x27c20020  addiu       $v0, $fp, 0x20
    ctx->pc = 0x1eb5d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 32));
    // 0x1eb5d8: 0x27c30024  addiu       $v1, $fp, 0x24
    ctx->pc = 0x1eb5d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 36));
    // 0x1eb5dc: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1eb5dcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1eb5e0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1eb5e0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1eb5e4: 0x60302d  daddu       $a2, $v1, $zero
    ctx->pc = 0x1eb5e4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1eb5e8: 0xc07ab82  jal         func_1EAE08
    ctx->pc = 0x1EB5E8u;
    SET_GPR_U32(ctx, 31, 0x1EB5F0u);
    ctx->pc = 0x1EAE08u;
    if (runtime->hasFunction(0x1EAE08u)) {
        auto targetFn = runtime->lookupFunction(0x1EAE08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EB5F0u; }
        if (ctx->pc != 0x1EB5F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001EAE08_0x1eae08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EB5F0u; }
        if (ctx->pc != 0x1EB5F0u) { return; }
    }
    ctx->pc = 0x1EB5F0u;
label_1eb5f0:
    // 0x1eb5f0: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1eb5f0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1eb5f4: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1EB5F4u;
    SET_GPR_U32(ctx, 31, 0x1EB5FCu);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EB5FCu; }
        if (ctx->pc != 0x1EB5FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EB5FCu; }
        if (ctx->pc != 0x1EB5FCu) { return; }
    }
    ctx->pc = 0x1EB5FCu;
label_1eb5fc:
    // 0x1eb5fc: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1eb5fcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1eb600: 0x8fc40024  lw          $a0, 0x24($fp)
    ctx->pc = 0x1eb600u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1eb604: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1EB604u;
    SET_GPR_U32(ctx, 31, 0x1EB60Cu);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EB60Cu; }
        if (ctx->pc != 0x1EB60Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EB60Cu; }
        if (ctx->pc != 0x1EB60Cu) { return; }
    }
    ctx->pc = 0x1EB60Cu;
label_1eb60c:
    // 0x1eb60c: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1eb60cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1eb610: 0x8fc30028  lw          $v1, 0x28($fp)
    ctx->pc = 0x1eb610u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1eb614: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1eb614u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1eb618: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1eb618u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1eb61c: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1eb61cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1eb620: 0x24430004  addiu       $v1, $v0, 0x4
    ctx->pc = 0x1eb620u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1eb624: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1eb624u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1eb628: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1eb628u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1eb62c: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1eb62cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1eb630: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1eb630u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1eb634: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1eb634u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1eb638: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1eb638u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1eb63c: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1eb63cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1eb640: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1eb640u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1eb644: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1eb644u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1eb648: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1eb648u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1eb64c: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1eb64cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1eb650: 0x1000ffca  b           . + 4 + (-0x36 << 2)
    ctx->pc = 0x1EB650u;
    {
        const bool branch_taken_0x1eb650 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1eb650) {
            ctx->pc = 0x1EB57Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1eb57c;
        }
    }
    ctx->pc = 0x1EB658u;
label_1eb658:
    // 0x1eb658: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1eb658u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1eb65c: 0xc041bce  jal         func_106F38
    ctx->pc = 0x1EB65Cu;
    SET_GPR_U32(ctx, 31, 0x1EB664u);
    ctx->pc = 0x106F38u;
    if (runtime->hasFunction(0x106F38u)) {
        auto targetFn = runtime->lookupFunction(0x106F38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EB664u; }
        if (ctx->pc != 0x1EB664u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00106F38_0x106f38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EB664u; }
        if (ctx->pc != 0x1EB664u) { return; }
    }
    ctx->pc = 0x1EB664u;
label_1eb664:
    // 0x1eb664: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1eb664u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1eb668: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1eb668u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1eb66c: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1eb66cu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1eb670: 0xdfbe0030  ld          $fp, 0x30($sp)
    ctx->pc = 0x1eb670u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1eb674: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x1eb674u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1eb678: 0x27bd0040  addiu       $sp, $sp, 0x40
    ctx->pc = 0x1eb678u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1eb67c: 0x3e00008  jr          $ra
    ctx->pc = 0x1EB67Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1EB528u: goto label_1eb528;
            case 0x1EB540u: goto label_1eb540;
            case 0x1EB564u: goto label_1eb564;
            case 0x1EB57Cu: goto label_1eb57c;
            case 0x1EB598u: goto label_1eb598;
            case 0x1EB5C0u: goto label_1eb5c0;
            case 0x1EB5D0u: goto label_1eb5d0;
            case 0x1EB5F0u: goto label_1eb5f0;
            case 0x1EB5FCu: goto label_1eb5fc;
            case 0x1EB60Cu: goto label_1eb60c;
            case 0x1EB658u: goto label_1eb658;
            case 0x1EB664u: goto label_1eb664;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1EB684u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
