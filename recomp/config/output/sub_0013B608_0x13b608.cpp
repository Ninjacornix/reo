#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013B608
// Address: 0x13b608 - 0x13b790
void sub_0013B608_0x13b608(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013B608_0x13b608");
#endif

    switch (ctx->pc) {
        case 0x13b658u: goto label_13b658;
        case 0x13b678u: goto label_13b678;
        case 0x13b688u: goto label_13b688;
        case 0x13b6a8u: goto label_13b6a8;
        case 0x13b6c4u: goto label_13b6c4;
        case 0x13b6ccu: goto label_13b6cc;
        case 0x13b6e4u: goto label_13b6e4;
        case 0x13b6f4u: goto label_13b6f4;
        case 0x13b700u: goto label_13b700;
        case 0x13b71cu: goto label_13b71c;
        case 0x13b724u: goto label_13b724;
        default: break;
    }

    ctx->pc = 0x13b608u;

    // 0x13b608: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x13b608u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x13b60c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x13b60cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x13b610: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x13b610u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b614: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x13b614u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x13b618: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x13b618u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x13b61c: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x13b61cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x13b620: 0x16200005  bnez        $s1, . + 4 + (0x5 << 2)
    ctx->pc = 0x13B620u;
    {
        const bool branch_taken_0x13b620 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x13B624u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B620u;
            // 0x13b624: 0xffa00000  sd          $zero, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b620) {
            ctx->pc = 0x13B638u;
            goto label_13b638;
        }
    }
    ctx->pc = 0x13B628u;
    // 0x13b628: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x13b628u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x13b62c: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x13B62Cu;
    {
        const bool branch_taken_0x13b62c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13B630u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B62Cu;
            // 0x13b630: 0x24a5cfc8  addiu       $a1, $a1, -0x3038 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294954952));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b62c) {
            ctx->pc = 0x13B670u;
            goto label_13b670;
        }
    }
    ctx->pc = 0x13B634u;
    // 0x13b634: 0x0  nop
    ctx->pc = 0x13b634u;
    // NOP
label_13b638:
    // 0x13b638: 0x10c00005  beqz        $a2, . + 4 + (0x5 << 2)
    ctx->pc = 0x13B638u;
    {
        const bool branch_taken_0x13b638 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x13B63Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B638u;
            // 0x13b63c: 0x3c050024  lui         $a1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b638) {
            ctx->pc = 0x13B650u;
            goto label_13b650;
        }
    }
    ctx->pc = 0x13B640u;
    // 0x13b640: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x13b640u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b644: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x13B644u;
    {
        const bool branch_taken_0x13b644 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13B648u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B644u;
            // 0x13b648: 0x24a5cff0  addiu       $a1, $a1, -0x3010 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294954992));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b644) {
            ctx->pc = 0x13B670u;
            goto label_13b670;
        }
    }
    ctx->pc = 0x13B64Cu;
    // 0x13b64c: 0x0  nop
    ctx->pc = 0x13b64cu;
    // NOP
label_13b650:
    // 0x13b650: 0xc04ed6c  jal         func_13B5B0
    ctx->pc = 0x13B650u;
    SET_GPR_U32(ctx, 31, 0x13B658u);
    ctx->pc = 0x13B5B0u;
    if (runtime->hasFunction(0x13B5B0u)) {
        auto targetFn = runtime->lookupFunction(0x13B5B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B658u; }
        if (ctx->pc != 0x13B658u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013B5B0_0x13b5b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B658u; }
        if (ctx->pc != 0x13B658u) { return; }
    }
    ctx->pc = 0x13B658u;
label_13b658:
    // 0x13b658: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x13b658u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b65c: 0x16000008  bnez        $s0, . + 4 + (0x8 << 2)
    ctx->pc = 0x13B65Cu;
    {
        const bool branch_taken_0x13b65c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x13B660u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B65Cu;
            // 0x13b660: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b65c) {
            ctx->pc = 0x13B680u;
            goto label_13b680;
        }
    }
    ctx->pc = 0x13B664u;
    // 0x13b664: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x13b664u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x13b668: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x13b668u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b66c: 0x24a5d018  addiu       $a1, $a1, -0x2FE8
    ctx->pc = 0x13b66cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294955032));
label_13b670:
    // 0x13b670: 0xc04ebf2  jal         func_13AFC8
    ctx->pc = 0x13B670u;
    SET_GPR_U32(ctx, 31, 0x13B678u);
    ctx->pc = 0x13AFC8u;
    if (runtime->hasFunction(0x13AFC8u)) {
        auto targetFn = runtime->lookupFunction(0x13AFC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B678u; }
        if (ctx->pc != 0x13B678u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013AFC8_0x13afc8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B678u; }
        if (ctx->pc != 0x13B678u) { return; }
    }
    ctx->pc = 0x13B678u;
label_13b678:
    // 0x13b678: 0x1000003f  b           . + 4 + (0x3F << 2)
    ctx->pc = 0x13B678u;
    {
        const bool branch_taken_0x13b678 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13B67Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B678u;
            // 0x13b67c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b678) {
            ctx->pc = 0x13B778u;
            goto label_13b778;
        }
    }
    ctx->pc = 0x13B680u;
label_13b680:
    // 0x13b680: 0xc04f1fa  jal         func_13C7E8
    ctx->pc = 0x13B680u;
    SET_GPR_U32(ctx, 31, 0x13B688u);
    ctx->pc = 0x13B684u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B680u;
            // 0x13b684: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13C7E8u;
    if (runtime->hasFunction(0x13C7E8u)) {
        auto targetFn = runtime->lookupFunction(0x13C7E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B688u; }
        if (ctx->pc != 0x13B688u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013C7E8_0x13c7e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B688u; }
        if (ctx->pc != 0x13B688u) { return; }
    }
    ctx->pc = 0x13B688u;
label_13b688:
    // 0x13b688: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x13b688u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x13b68c: 0x14400028  bnez        $v0, . + 4 + (0x28 << 2)
    ctx->pc = 0x13B68Cu;
    {
        const bool branch_taken_0x13b68c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13B690u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B68Cu;
            // 0x13b690: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b68c) {
            ctx->pc = 0x13B730u;
            goto label_13b730;
        }
    }
    ctx->pc = 0x13B694u;
    // 0x13b694: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13b694u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13b698: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x13b698u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b69c: 0x2452dd60  addiu       $s2, $v0, -0x22A0
    ctx->pc = 0x13b69cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 2), 4294958432));
    // 0x13b6a0: 0xc04efa0  jal         func_13BE80
    ctx->pc = 0x13B6A0u;
    SET_GPR_U32(ctx, 31, 0x13B6A8u);
    ctx->pc = 0x13B6A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B6A0u;
            // 0x13b6a4: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13BE80u;
    if (runtime->hasFunction(0x13BE80u)) {
        auto targetFn = runtime->lookupFunction(0x13BE80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B6A8u; }
        if (ctx->pc != 0x13B6A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013BE80_0x13be80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B6A8u; }
        if (ctx->pc != 0x13B6A8u) { return; }
    }
    ctx->pc = 0x13B6A8u;
label_13b6a8:
    // 0x13b6a8: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13b6a8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13b6ac: 0x8c43dea4  lw          $v1, -0x215C($v0)
    ctx->pc = 0x13b6acu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294958756)));
    // 0x13b6b0: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x13B6B0u;
    {
        const bool branch_taken_0x13b6b0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x13B6B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B6B0u;
            // 0x13b6b4: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b6b0) {
            ctx->pc = 0x13B6C4u;
            goto label_13b6c4;
        }
    }
    ctx->pc = 0x13B6B8u;
    // 0x13b6b8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x13b6b8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b6bc: 0xc045a12  jal         func_116848
    ctx->pc = 0x13B6BCu;
    SET_GPR_U32(ctx, 31, 0x13B6C4u);
    ctx->pc = 0x13B6C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B6BCu;
            // 0x13b6c0: 0x2484d048  addiu       $a0, $a0, -0x2FB8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955080));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B6C4u; }
        if (ctx->pc != 0x13B6C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B6C4u; }
        if (ctx->pc != 0x13B6C4u) { return; }
    }
    ctx->pc = 0x13B6C4u;
label_13b6c4:
    // 0x13b6c4: 0xc04eccc  jal         func_13B330
    ctx->pc = 0x13B6C4u;
    SET_GPR_U32(ctx, 31, 0x13B6CCu);
    ctx->pc = 0x13B6C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B6C4u;
            // 0x13b6c8: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13B330u;
    if (runtime->hasFunction(0x13B330u)) {
        auto targetFn = runtime->lookupFunction(0x13B330u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B6CCu; }
        if (ctx->pc != 0x13B6CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013B330_0x13b330(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B6CCu; }
        if (ctx->pc != 0x13B6CCu) { return; }
    }
    ctx->pc = 0x13B6CCu;
label_13b6cc:
    // 0x13b6cc: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x13b6ccu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b6d0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x13b6d0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b6d4: 0x10600028  beqz        $v1, . + 4 + (0x28 << 2)
    ctx->pc = 0x13B6D4u;
    {
        const bool branch_taken_0x13b6d4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x13B6D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B6D4u;
            // 0x13b6d8: 0xfe030008  sd          $v1, 0x8($s0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 16), 8), GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b6d4) {
            ctx->pc = 0x13B778u;
            goto label_13b778;
        }
    }
    ctx->pc = 0x13B6DCu;
    // 0x13b6dc: 0xc04e082  jal         func_138208
    ctx->pc = 0x13B6DCu;
    SET_GPR_U32(ctx, 31, 0x13B6E4u);
    ctx->pc = 0x13B6E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B6DCu;
            // 0x13b6e0: 0x24044900  addiu       $a0, $zero, 0x4900 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 18688));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B6E4u; }
        if (ctx->pc != 0x13B6E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B6E4u; }
        if (ctx->pc != 0x13B6E4u) { return; }
    }
    ctx->pc = 0x13B6E4u;
label_13b6e4:
    // 0x13b6e4: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13b6e4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13b6e8: 0x8c45dea0  lw          $a1, -0x2160($v0)
    ctx->pc = 0x13b6e8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294958752)));
    // 0x13b6ec: 0xc04e146  jal         func_138518
    ctx->pc = 0x13B6ECu;
    SET_GPR_U32(ctx, 31, 0x13B6F4u);
    ctx->pc = 0x13B6F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B6ECu;
            // 0x13b6f0: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138518u;
    if (runtime->hasFunction(0x138518u)) {
        auto targetFn = runtime->lookupFunction(0x138518u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B6F4u; }
        if (ctx->pc != 0x13B6F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138518_0x138518(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B6F4u; }
        if (ctx->pc != 0x13B6F4u) { return; }
    }
    ctx->pc = 0x13B6F4u;
label_13b6f4:
    // 0x13b6f4: 0x24044901  addiu       $a0, $zero, 0x4901
    ctx->pc = 0x13b6f4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 18689));
    // 0x13b6f8: 0xc04e082  jal         func_138208
    ctx->pc = 0x13B6F8u;
    SET_GPR_U32(ctx, 31, 0x13B700u);
    ctx->pc = 0x13B6FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B6F8u;
            // 0x13b6fc: 0xae020018  sw          $v0, 0x18($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B700u; }
        if (ctx->pc != 0x13B700u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B700u; }
        if (ctx->pc != 0x13B700u) { return; }
    }
    ctx->pc = 0x13B700u;
label_13b700:
    // 0x13b700: 0x8e020018  lw          $v0, 0x18($s0)
    ctx->pc = 0x13b700u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x13b704: 0x443000f  bgezl       $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x13B704u;
    {
        const bool branch_taken_0x13b704 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x13b704) {
            ctx->pc = 0x13B708u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13B704u;
            // 0x13b708: 0xa2000001  sb          $zero, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13B744u;
            goto label_13b744;
        }
    }
    ctx->pc = 0x13B70Cu;
    // 0x13b70c: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x13b70cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x13b710: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x13b710u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b714: 0xc04ebf2  jal         func_13AFC8
    ctx->pc = 0x13B714u;
    SET_GPR_U32(ctx, 31, 0x13B71Cu);
    ctx->pc = 0x13B718u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B714u;
            // 0x13b718: 0x24a5d070  addiu       $a1, $a1, -0x2F90 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294955120));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13AFC8u;
    if (runtime->hasFunction(0x13AFC8u)) {
        auto targetFn = runtime->lookupFunction(0x13AFC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B71Cu; }
        if (ctx->pc != 0x13B71Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013AFC8_0x13afc8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B71Cu; }
        if (ctx->pc != 0x13B71Cu) { return; }
    }
    ctx->pc = 0x13B71Cu;
label_13b71c:
    // 0x13b71c: 0xc04ed7a  jal         func_13B5E8
    ctx->pc = 0x13B71Cu;
    SET_GPR_U32(ctx, 31, 0x13B724u);
    ctx->pc = 0x13B720u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B71Cu;
            // 0x13b720: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13B5E8u;
    if (runtime->hasFunction(0x13B5E8u)) {
        auto targetFn = runtime->lookupFunction(0x13B5E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B724u; }
        if (ctx->pc != 0x13B724u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013B5E8_0x13b5e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B724u; }
        if (ctx->pc != 0x13B724u) { return; }
    }
    ctx->pc = 0x13B724u;
label_13b724:
    // 0x13b724: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x13B724u;
    {
        const bool branch_taken_0x13b724 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13B728u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B724u;
            // 0x13b728: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b724) {
            ctx->pc = 0x13B778u;
            goto label_13b778;
        }
    }
    ctx->pc = 0x13B72Cu;
    // 0x13b72c: 0x0  nop
    ctx->pc = 0x13b72cu;
    // NOP
label_13b730:
    // 0x13b730: 0xa2020001  sb          $v0, 0x1($s0)
    ctx->pc = 0x13b730u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0x13b734: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x13b734u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13b738: 0xae030018  sw          $v1, 0x18($s0)
    ctx->pc = 0x13b738u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 3));
    // 0x13b73c: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x13b73cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x13b740: 0xfe020008  sd          $v0, 0x8($s0)
    ctx->pc = 0x13b740u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 8), GPR_U64(ctx, 2));
label_13b744:
    // 0x13b744: 0xde030008  ld          $v1, 0x8($s0)
    ctx->pc = 0x13b744u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x13b748: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x13b748u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13b74c: 0xae00001c  sw          $zero, 0x1C($s0)
    ctx->pc = 0x13b74cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 0));
    // 0x13b750: 0x646307ff  daddiu      $v1, $v1, 0x7FF
    ctx->pc = 0x13b750u;
    SET_GPR_S64(ctx, 3, (int64_t)GPR_S64(ctx, 3) + (int64_t)(int32_t)2047);
    // 0x13b754: 0xae000020  sw          $zero, 0x20($s0)
    ctx->pc = 0x13b754u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 0));
    // 0x13b758: 0x31d78  dsll        $v1, $v1, 21
    ctx->pc = 0x13b758u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 21);
    // 0x13b75c: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x13b75cu;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x13b760: 0xae000024  sw          $zero, 0x24($s0)
    ctx->pc = 0x13b760u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 0));
    // 0x13b764: 0xae030010  sw          $v1, 0x10($s0)
    ctx->pc = 0x13b764u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 3));
    // 0x13b768: 0xae000014  sw          $zero, 0x14($s0)
    ctx->pc = 0x13b768u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
    // 0x13b76c: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x13b76cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x13b770: 0xa2020000  sb          $v0, 0x0($s0)
    ctx->pc = 0x13b770u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x13b774: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x13b774u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_13b778:
    // 0x13b778: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x13b778u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13b77c: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x13b77cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13b780: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x13b780u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13b784: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x13b784u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x13b788: 0x3e00008  jr          $ra
    ctx->pc = 0x13B788u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13B78Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B788u;
            // 0x13b78c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13B638u: goto label_13b638;
            case 0x13B650u: goto label_13b650;
            case 0x13B658u: goto label_13b658;
            case 0x13B670u: goto label_13b670;
            case 0x13B678u: goto label_13b678;
            case 0x13B680u: goto label_13b680;
            case 0x13B688u: goto label_13b688;
            case 0x13B6A8u: goto label_13b6a8;
            case 0x13B6C4u: goto label_13b6c4;
            case 0x13B6CCu: goto label_13b6cc;
            case 0x13B6E4u: goto label_13b6e4;
            case 0x13B6F4u: goto label_13b6f4;
            case 0x13B700u: goto label_13b700;
            case 0x13B71Cu: goto label_13b71c;
            case 0x13B724u: goto label_13b724;
            case 0x13B730u: goto label_13b730;
            case 0x13B744u: goto label_13b744;
            case 0x13B778u: goto label_13b778;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13B790u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
