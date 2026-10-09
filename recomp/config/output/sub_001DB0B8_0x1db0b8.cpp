#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DB0B8
// Address: 0x1db0b8 - 0x1db16c
void sub_001DB0B8_0x1db0b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DB0B8_0x1db0b8");
#endif

    switch (ctx->pc) {
        case 0x1db0fcu: goto label_1db0fc;
        case 0x1db128u: goto label_1db128;
        case 0x1db144u: goto label_1db144;
        default: break;
    }

    ctx->pc = 0x1db0b8u;

    // 0x1db0b8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1db0b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1db0bc: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1db0bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1db0c0: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1db0c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1db0c4: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1db0c4u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db0c8: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1db0c8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1db0cc: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1db0ccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1db0d0: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1db0d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1db0d4: 0x27c5000c  addiu       $a1, $fp, 0xC
    ctx->pc = 0x1db0d4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 30), 12));
    // 0x1db0d8: 0x97c20004  lhu         $v0, 0x4($fp)
    ctx->pc = 0x1db0d8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1db0dc: 0x24420014  addiu       $v0, $v0, 0x14
    ctx->pc = 0x1db0dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 20));
    // 0x1db0e0: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1db0e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1db0e4: 0x8c640520  lw          $a0, 0x520($v1)
    ctx->pc = 0x1db0e4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 1312)));
    // 0x1db0e8: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1db0e8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db0ec: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x1db0ecu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1db0f0: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x1db0f0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1db0f4: 0xc07c80a  jal         func_1F2028
    ctx->pc = 0x1DB0F4u;
    SET_GPR_U32(ctx, 31, 0x1DB0FCu);
    ctx->pc = 0x1F2028u;
    if (runtime->hasFunction(0x1F2028u)) {
        auto targetFn = runtime->lookupFunction(0x1F2028u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DB0FCu; }
        if (ctx->pc != 0x1DB0FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2028_0x1f2028(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DB0FCu; }
        if (ctx->pc != 0x1DB0FCu) { return; }
    }
    ctx->pc = 0x1DB0FCu;
label_1db0fc:
    // 0x1db0fc: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1db0fcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1db100: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1db100u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1db104: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1DB104u;
    {
        const bool branch_taken_0x1db104 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1db104) {
            ctx->pc = 0x1DB118u;
            goto label_1db118;
        }
    }
    ctx->pc = 0x1DB10Cu;
    // 0x1db10c: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1db10cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1db110: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1DB110u;
    {
        const bool branch_taken_0x1db110 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1db110) {
            ctx->pc = 0x1DB154u;
            goto label_1db154;
        }
    }
    ctx->pc = 0x1DB118u;
label_1db118:
    // 0x1db118: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1db118u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1db11c: 0x24050010  addiu       $a1, $zero, 0x10
    ctx->pc = 0x1db11cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1db120: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1DB120u;
    SET_GPR_U32(ctx, 31, 0x1DB128u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DB128u; }
        if (ctx->pc != 0x1DB128u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DB128u; }
        if (ctx->pc != 0x1DB128u) { return; }
    }
    ctx->pc = 0x1DB128u;
label_1db128:
    // 0x1db128: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1DB128u;
    {
        const bool branch_taken_0x1db128 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1db128) {
            ctx->pc = 0x1DB150u;
            goto label_1db150;
        }
    }
    ctx->pc = 0x1DB130u;
    // 0x1db130: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1db130u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1db134: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1db134u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1db138: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1db138u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1db13c: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1DB13Cu;
    SET_GPR_U32(ctx, 31, 0x1DB144u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DB144u; }
        if (ctx->pc != 0x1DB144u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DB144u; }
        if (ctx->pc != 0x1DB144u) { return; }
    }
    ctx->pc = 0x1DB144u;
label_1db144:
    // 0x1db144: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1db144u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db148: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1DB148u;
    {
        const bool branch_taken_0x1db148 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1db148) {
            ctx->pc = 0x1DB154u;
            goto label_1db154;
        }
    }
    ctx->pc = 0x1DB150u;
label_1db150:
    // 0x1db150: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1db150u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
label_1db154:
    // 0x1db154: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1db154u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db158: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1db158u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1db15c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1db15cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1db160: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1db160u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1db164: 0x3e00008  jr          $ra
    ctx->pc = 0x1DB164u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DB0FCu: goto label_1db0fc;
            case 0x1DB118u: goto label_1db118;
            case 0x1DB128u: goto label_1db128;
            case 0x1DB144u: goto label_1db144;
            case 0x1DB150u: goto label_1db150;
            case 0x1DB154u: goto label_1db154;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DB16Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
