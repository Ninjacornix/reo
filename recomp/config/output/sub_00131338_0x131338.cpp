#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00131338
// Address: 0x131338 - 0x131428
void sub_00131338_0x131338(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00131338_0x131338");
#endif

    switch (ctx->pc) {
        case 0x131360u: goto label_131360;
        case 0x131378u: goto label_131378;
        case 0x131380u: goto label_131380;
        case 0x131390u: goto label_131390;
        case 0x131398u: goto label_131398;
        case 0x1313acu: goto label_1313ac;
        case 0x1313c0u: goto label_1313c0;
        case 0x131400u: goto label_131400;
        case 0x131408u: goto label_131408;
        case 0x131410u: goto label_131410;
        default: break;
    }

    ctx->pc = 0x131338u;

    // 0x131338: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x131338u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13133c: 0x3c020013  lui         $v0, 0x13
    ctx->pc = 0x13133cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)19 << 16));
    // 0x131340: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x131340u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x131344: 0x3c100024  lui         $s0, 0x24
    ctx->pc = 0x131344u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)36 << 16));
    // 0x131348: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x131348u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13134c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x13134cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131350: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x131350u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131354: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x131354u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x131358: 0xc04daa0  jal         func_136A80
    ctx->pc = 0x131358u;
    SET_GPR_U32(ctx, 31, 0x131360u);
    ctx->pc = 0x13135Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131358u;
            // 0x13135c: 0x24441320  addiu       $a0, $v0, 0x1320 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 4896));
        ctx->in_delay_slot = false;
    ctx->pc = 0x136A80u;
    if (runtime->hasFunction(0x136A80u)) {
        auto targetFn = runtime->lookupFunction(0x136A80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131360u; }
        if (ctx->pc != 0x131360u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00136A80_0x136a80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131360u; }
        if (ctx->pc != 0x131360u) { return; }
    }
    ctx->pc = 0x131360u;
label_131360:
    // 0x131360: 0x2610ae48  addiu       $s0, $s0, -0x51B8
    ctx->pc = 0x131360u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294946376));
    // 0x131364: 0x3c050014  lui         $a1, 0x14
    ctx->pc = 0x131364u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)20 << 16));
    // 0x131368: 0x24a5af60  addiu       $a1, $a1, -0x50A0
    ctx->pc = 0x131368u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294946656));
    // 0x13136c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x13136cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131370: 0xc04d4fe  jal         func_1353F8
    ctx->pc = 0x131370u;
    SET_GPR_U32(ctx, 31, 0x131378u);
    ctx->pc = 0x131374u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131370u;
            // 0x131374: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1353F8u;
    if (runtime->hasFunction(0x1353F8u)) {
        auto targetFn = runtime->lookupFunction(0x1353F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131378u; }
        if (ctx->pc != 0x131378u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001353F8_0x1353f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131378u; }
        if (ctx->pc != 0x131378u) { return; }
    }
    ctx->pc = 0x131378u;
label_131378:
    // 0x131378: 0xc04d5cc  jal         func_135730
    ctx->pc = 0x131378u;
    SET_GPR_U32(ctx, 31, 0x131380u);
    ctx->pc = 0x13137Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131378u;
            // 0x13137c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135730u;
    if (runtime->hasFunction(0x135730u)) {
        auto targetFn = runtime->lookupFunction(0x135730u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131380u; }
        if (ctx->pc != 0x131380u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135730_0x135730(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131380u; }
        if (ctx->pc != 0x131380u) { return; }
    }
    ctx->pc = 0x131380u;
label_131380:
    // 0x131380: 0x1220001d  beqz        $s1, . + 4 + (0x1D << 2)
    ctx->pc = 0x131380u;
    {
        const bool branch_taken_0x131380 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x131384u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131380u;
            // 0x131384: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x131380) {
            ctx->pc = 0x1313F8u;
            goto label_1313f8;
        }
    }
    ctx->pc = 0x131388u;
    // 0x131388: 0xc04f27a  jal         func_13C9E8
    ctx->pc = 0x131388u;
    SET_GPR_U32(ctx, 31, 0x131390u);
    ctx->pc = 0x13138Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131388u;
            // 0x13138c: 0x8e240004  lw          $a0, 0x4($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13C9E8u;
    if (runtime->hasFunction(0x13C9E8u)) {
        auto targetFn = runtime->lookupFunction(0x13C9E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131390u; }
        if (ctx->pc != 0x131390u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013C9E8_0x13c9e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131390u; }
        if (ctx->pc != 0x131390u) { return; }
    }
    ctx->pc = 0x131390u;
label_131390:
    // 0x131390: 0xc04f286  jal         func_13CA18
    ctx->pc = 0x131390u;
    SET_GPR_U32(ctx, 31, 0x131398u);
    ctx->pc = 0x131394u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131390u;
            // 0x131394: 0x8e240000  lw          $a0, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13CA18u;
    if (runtime->hasFunction(0x13CA18u)) {
        auto targetFn = runtime->lookupFunction(0x13CA18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131398u; }
        if (ctx->pc != 0x131398u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013CA18_0x13ca18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131398u; }
        if (ctx->pc != 0x131398u) { return; }
    }
    ctx->pc = 0x131398u;
label_131398:
    // 0x131398: 0x8e220008  lw          $v0, 0x8($s1)
    ctx->pc = 0x131398u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x13139c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x13139Cu;
    {
        const bool branch_taken_0x13139c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1313A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13139Cu;
            // 0x1313a0: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13139c) {
            ctx->pc = 0x1313B8u;
            goto label_1313b8;
        }
    }
    ctx->pc = 0x1313A4u;
    // 0x1313a4: 0xc04ebc0  jal         func_13AF00
    ctx->pc = 0x1313A4u;
    SET_GPR_U32(ctx, 31, 0x1313ACu);
    ctx->pc = 0x1313A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1313A4u;
            // 0x1313a8: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13AF00u;
    if (runtime->hasFunction(0x13AF00u)) {
        auto targetFn = runtime->lookupFunction(0x13AF00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1313ACu; }
        if (ctx->pc != 0x1313ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013AF00_0x13af00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1313ACu; }
        if (ctx->pc != 0x1313ACu) { return; }
    }
    ctx->pc = 0x1313ACu;
label_1313ac:
    // 0x1313ac: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1313ACu;
    {
        const bool branch_taken_0x1313ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1313B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1313ACu;
            // 0x1313b0: 0x8e22000c  lw          $v0, 0xC($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1313ac) {
            ctx->pc = 0x1313C4u;
            goto label_1313c4;
        }
    }
    ctx->pc = 0x1313B4u;
    // 0x1313b4: 0x0  nop
    ctx->pc = 0x1313b4u;
    // NOP
label_1313b8:
    // 0x1313b8: 0xc04ebc0  jal         func_13AF00
    ctx->pc = 0x1313B8u;
    SET_GPR_U32(ctx, 31, 0x1313C0u);
    ctx->pc = 0x13AF00u;
    if (runtime->hasFunction(0x13AF00u)) {
        auto targetFn = runtime->lookupFunction(0x13AF00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1313C0u; }
        if (ctx->pc != 0x1313C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013AF00_0x13af00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1313C0u; }
        if (ctx->pc != 0x1313C0u) { return; }
    }
    ctx->pc = 0x1313C0u;
label_1313c0:
    // 0x1313c0: 0x8e22000c  lw          $v0, 0xC($s1)
    ctx->pc = 0x1313c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
label_1313c4:
    // 0x1313c4: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1313C4u;
    {
        const bool branch_taken_0x1313c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1313C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1313C4u;
            // 0x1313c8: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1313c4) {
            ctx->pc = 0x1313E0u;
            goto label_1313e0;
        }
    }
    ctx->pc = 0x1313CCu;
    // 0x1313cc: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1313ccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1313d0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1313d0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1313d4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1313d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1313d8: 0x804ebcc  j           func_13AF30
    ctx->pc = 0x1313D8u;
    ctx->pc = 0x1313DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1313D8u;
            // 0x1313dc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13AF30u;
    if (runtime->hasFunction(0x13AF30u)) {
        auto targetFn = runtime->lookupFunction(0x13AF30u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013AF30_0x13af30(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1313E0u;
label_1313e0:
    // 0x1313e0: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1313e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1313e4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1313e4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1313e8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1313e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1313ec: 0x804ebcc  j           func_13AF30
    ctx->pc = 0x1313ECu;
    ctx->pc = 0x1313F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1313ECu;
            // 0x1313f0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13AF30u;
    if (runtime->hasFunction(0x13AF30u)) {
        auto targetFn = runtime->lookupFunction(0x13AF30u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013AF30_0x13af30(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1313F4u;
    // 0x1313f4: 0x0  nop
    ctx->pc = 0x1313f4u;
    // NOP
label_1313f8:
    // 0x1313f8: 0xc04f27a  jal         func_13C9E8
    ctx->pc = 0x1313F8u;
    SET_GPR_U32(ctx, 31, 0x131400u);
    ctx->pc = 0x13C9E8u;
    if (runtime->hasFunction(0x13C9E8u)) {
        auto targetFn = runtime->lookupFunction(0x13C9E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131400u; }
        if (ctx->pc != 0x131400u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013C9E8_0x13c9e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131400u; }
        if (ctx->pc != 0x131400u) { return; }
    }
    ctx->pc = 0x131400u;
label_131400:
    // 0x131400: 0xc04f286  jal         func_13CA18
    ctx->pc = 0x131400u;
    SET_GPR_U32(ctx, 31, 0x131408u);
    ctx->pc = 0x131404u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131400u;
            // 0x131404: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13CA18u;
    if (runtime->hasFunction(0x13CA18u)) {
        auto targetFn = runtime->lookupFunction(0x13CA18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131408u; }
        if (ctx->pc != 0x131408u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013CA18_0x13ca18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131408u; }
        if (ctx->pc != 0x131408u) { return; }
    }
    ctx->pc = 0x131408u;
label_131408:
    // 0x131408: 0xc04ebc0  jal         func_13AF00
    ctx->pc = 0x131408u;
    SET_GPR_U32(ctx, 31, 0x131410u);
    ctx->pc = 0x13140Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131408u;
            // 0x13140c: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13AF00u;
    if (runtime->hasFunction(0x13AF00u)) {
        auto targetFn = runtime->lookupFunction(0x13AF00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131410u; }
        if (ctx->pc != 0x131410u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013AF00_0x13af00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131410u; }
        if (ctx->pc != 0x131410u) { return; }
    }
    ctx->pc = 0x131410u;
label_131410:
    // 0x131410: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x131410u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131414: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x131414u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x131418: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x131418u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13141c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x13141cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x131420: 0x804ebcc  j           func_13AF30
    ctx->pc = 0x131420u;
    ctx->pc = 0x131424u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131420u;
            // 0x131424: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13AF30u;
    if (runtime->hasFunction(0x13AF30u)) {
        auto targetFn = runtime->lookupFunction(0x13AF30u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013AF30_0x13af30(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x131428u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
