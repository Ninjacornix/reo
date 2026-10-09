#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00141280
// Address: 0x141280 - 0x141418
void sub_00141280_0x141280(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00141280_0x141280");
#endif

    switch (ctx->pc) {
        case 0x1412d0u: goto label_1412d0;
        case 0x1412d8u: goto label_1412d8;
        case 0x141300u: goto label_141300;
        case 0x141314u: goto label_141314;
        case 0x141318u: goto label_141318;
        case 0x141368u: goto label_141368;
        case 0x14137cu: goto label_14137c;
        case 0x141380u: goto label_141380;
        case 0x1413b8u: goto label_1413b8;
        case 0x1413ccu: goto label_1413cc;
        case 0x1413e4u: goto label_1413e4;
        default: break;
    }

    ctx->pc = 0x141280u;

    // 0x141280: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x141280u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x141284: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x141284u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x141288: 0x3c150023  lui         $s5, 0x23
    ctx->pc = 0x141288u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)35 << 16));
    // 0x14128c: 0x8ea29a7c  lw          $v0, -0x6584($s5)
    ctx->pc = 0x14128cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 4294941308)));
    // 0x141290: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x141290u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x141294: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x141294u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x141298: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x141298u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x14129c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x14129cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x1412a0: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x1412a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x1412a4: 0x1440004f  bnez        $v0, . + 4 + (0x4F << 2)
    ctx->pc = 0x1412A4u;
    {
        const bool branch_taken_0x1412a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1412A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1412A4u;
            // 0x1412a8: 0xffbf0030  sd          $ra, 0x30($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1412a4) {
            ctx->pc = 0x1413E4u;
            goto label_1413e4;
        }
    }
    ctx->pc = 0x1412ACu;
    // 0x1412ac: 0x3c100023  lui         $s0, 0x23
    ctx->pc = 0x1412acu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)35 << 16));
    // 0x1412b0: 0x3c140023  lui         $s4, 0x23
    ctx->pc = 0x1412b0u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)35 << 16));
    // 0x1412b4: 0x26109d18  addiu       $s0, $s0, -0x62E8
    ctx->pc = 0x1412b4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294941976));
    // 0x1412b8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1412b8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1412bc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1412bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1412c0: 0x26100040  addiu       $s0, $s0, 0x40
    ctx->pc = 0x1412c0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 64));
    // 0x1412c4: 0x240608d0  addiu       $a2, $zero, 0x8D0
    ctx->pc = 0x1412c4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2256));
    // 0x1412c8: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1412C8u;
    SET_GPR_U32(ctx, 31, 0x1412D0u);
    ctx->pc = 0x1412CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1412C8u;
            // 0x1412cc: 0x26939a84  addiu       $s3, $s4, -0x657C (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 20), 4294941316));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1412D0u; }
        if (ctx->pc != 0x1412D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1412D0u; }
        if (ctx->pc != 0x1412D0u) { return; }
    }
    ctx->pc = 0x1412D0u;
label_1412d0:
    // 0x1412d0: 0xc04e4be  jal         func_1392F8
    ctx->pc = 0x1412D0u;
    SET_GPR_U32(ctx, 31, 0x1412D8u);
    ctx->pc = 0x1412D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1412D0u;
            // 0x1412d4: 0x3c120023  lui         $s2, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1392F8u;
    if (runtime->hasFunction(0x1392F8u)) {
        auto targetFn = runtime->lookupFunction(0x1392F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1412D8u; }
        if (ctx->pc != 0x1412D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001392F8_0x1392f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1412D8u; }
        if (ctx->pc != 0x1412D8u) { return; }
    }
    ctx->pc = 0x1412D8u;
label_1412d8:
    // 0x1412d8: 0x2402ffc0  addiu       $v0, $zero, -0x40
    ctx->pc = 0x1412d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x1412dc: 0x8e630000  lw          $v1, 0x0($s3)
    ctx->pc = 0x1412dcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1412e0: 0x24040880  addiu       $a0, $zero, 0x880
    ctx->pc = 0x1412e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2176));
    // 0x1412e4: 0x2028024  and         $s0, $s0, $v0
    ctx->pc = 0x1412e4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) & GPR_U64(ctx, 2));
    // 0x1412e8: 0x3c110023  lui         $s1, 0x23
    ctx->pc = 0x1412e8u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)35 << 16));
    // 0x1412ec: 0xae449d14  sw          $a0, -0x62EC($s2)
    ctx->pc = 0x1412ecu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4294941972), GPR_U32(ctx, 4));
    // 0x1412f0: 0x14600011  bnez        $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x1412F0u;
    {
        const bool branch_taken_0x1412f0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1412F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1412F0u;
            // 0x1412f4: 0xae309a80  sw          $s0, -0x6580($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 4294941312), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1412f0) {
            ctx->pc = 0x141338u;
            goto label_141338;
        }
    }
    ctx->pc = 0x1412F8u;
    // 0x1412f8: 0xc046e2c  jal         func_11B8B0
    ctx->pc = 0x1412F8u;
    SET_GPR_U32(ctx, 31, 0x141300u);
    ctx->pc = 0x1412FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1412F8u;
            // 0x1412fc: 0x240408d0  addiu       $a0, $zero, 0x8D0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11B8B0u;
    if (runtime->hasFunction(0x11B8B0u)) {
        auto targetFn = runtime->lookupFunction(0x11B8B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141300u; }
        if (ctx->pc != 0x141300u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011B8B0_0x11b8b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141300u; }
        if (ctx->pc != 0x141300u) { return; }
    }
    ctx->pc = 0x141300u;
label_141300:
    // 0x141300: 0x1440000d  bnez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x141300u;
    {
        const bool branch_taken_0x141300 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x141304u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141300u;
            // 0x141304: 0xae620000  sw          $v0, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x141300) {
            ctx->pc = 0x141338u;
            goto label_141338;
        }
    }
    ctx->pc = 0x141308u;
    // 0x141308: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x141308u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x14130c: 0xc045a12  jal         func_116848
    ctx->pc = 0x14130Cu;
    SET_GPR_U32(ctx, 31, 0x141314u);
    ctx->pc = 0x141310u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14130Cu;
            // 0x141310: 0x2484daf8  addiu       $a0, $a0, -0x2508 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957816));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141314u; }
        if (ctx->pc != 0x141314u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141314u; }
        if (ctx->pc != 0x141314u) { return; }
    }
    ctx->pc = 0x141314u;
label_141314:
    // 0x141314: 0x0  nop
    ctx->pc = 0x141314u;
    // NOP
label_141318:
    // 0x141318: 0x0  nop
    ctx->pc = 0x141318u;
    // NOP
    // 0x14131c: 0x0  nop
    ctx->pc = 0x14131cu;
    // NOP
    // 0x141320: 0x0  nop
    ctx->pc = 0x141320u;
    // NOP
    // 0x141324: 0x0  nop
    ctx->pc = 0x141324u;
    // NOP
    // 0x141328: 0x0  nop
    ctx->pc = 0x141328u;
    // NOP
    // 0x14132c: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x14132Cu;
    {
        const bool branch_taken_0x14132c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x14132c) {
            ctx->pc = 0x141318u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_141318;
        }
    }
    ctx->pc = 0x141334u;
    // 0x141334: 0x0  nop
    ctx->pc = 0x141334u;
    // NOP
label_141338:
    // 0x141338: 0x8e829a84  lw          $v0, -0x657C($s4)
    ctx->pc = 0x141338u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 4294941316)));
    // 0x14133c: 0x2403ffc0  addiu       $v1, $zero, -0x40
    ctx->pc = 0x14133cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x141340: 0x8e259a80  lw          $a1, -0x6580($s1)
    ctx->pc = 0x141340u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4294941312)));
    // 0x141344: 0x3c080023  lui         $t0, 0x23
    ctx->pc = 0x141344u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)35 << 16));
    // 0x141348: 0x24420040  addiu       $v0, $v0, 0x40
    ctx->pc = 0x141348u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 64));
    // 0x14134c: 0x8e479d14  lw          $a3, -0x62EC($s2)
    ctx->pc = 0x14134cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4294941972)));
    // 0x141350: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x141350u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x141354: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x141354u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x141358: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x141358u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14135c: 0xad029a88  sw          $v0, -0x6578($t0)
    ctx->pc = 0x14135cu;
    WRITE32(ADD32(GPR_U32(ctx, 8), 4294941320), GPR_U32(ctx, 2));
    // 0x141360: 0xc04e3de  jal         func_138F78
    ctx->pc = 0x141360u;
    SET_GPR_U32(ctx, 31, 0x141368u);
    ctx->pc = 0x141364u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x141360u;
            // 0x141364: 0x3c100023  lui         $s0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138F78u;
    if (runtime->hasFunction(0x138F78u)) {
        auto targetFn = runtime->lookupFunction(0x138F78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141368u; }
        if (ctx->pc != 0x141368u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138F78_0x138f78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141368u; }
        if (ctx->pc != 0x141368u) { return; }
    }
    ctx->pc = 0x141368u;
label_141368:
    // 0x141368: 0x1440000d  bnez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x141368u;
    {
        const bool branch_taken_0x141368 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x14136Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141368u;
            // 0x14136c: 0xae029d10  sw          $v0, -0x62F0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4294941968), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x141368) {
            ctx->pc = 0x1413A0u;
            goto label_1413a0;
        }
    }
    ctx->pc = 0x141370u;
    // 0x141370: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x141370u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x141374: 0xc045a12  jal         func_116848
    ctx->pc = 0x141374u;
    SET_GPR_U32(ctx, 31, 0x14137Cu);
    ctx->pc = 0x141378u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x141374u;
            // 0x141378: 0x2484db28  addiu       $a0, $a0, -0x24D8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957864));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14137Cu; }
        if (ctx->pc != 0x14137Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14137Cu; }
        if (ctx->pc != 0x14137Cu) { return; }
    }
    ctx->pc = 0x14137Cu;
label_14137c:
    // 0x14137c: 0x0  nop
    ctx->pc = 0x14137cu;
    // NOP
label_141380:
    // 0x141380: 0x0  nop
    ctx->pc = 0x141380u;
    // NOP
    // 0x141384: 0x0  nop
    ctx->pc = 0x141384u;
    // NOP
    // 0x141388: 0x0  nop
    ctx->pc = 0x141388u;
    // NOP
    // 0x14138c: 0x0  nop
    ctx->pc = 0x14138cu;
    // NOP
    // 0x141390: 0x0  nop
    ctx->pc = 0x141390u;
    // NOP
    // 0x141394: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x141394u;
    {
        const bool branch_taken_0x141394 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x141394) {
            ctx->pc = 0x141380u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_141380;
        }
    }
    ctx->pc = 0x14139Cu;
    // 0x14139c: 0x0  nop
    ctx->pc = 0x14139cu;
    // NOP
label_1413a0:
    // 0x1413a0: 0x26109d10  addiu       $s0, $s0, -0x62F0
    ctx->pc = 0x1413a0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294941968));
    // 0x1413a4: 0x3c050014  lui         $a1, 0x14
    ctx->pc = 0x1413a4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)20 << 16));
    // 0x1413a8: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x1413a8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1413ac: 0x24a50f18  addiu       $a1, $a1, 0xF18
    ctx->pc = 0x1413acu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 3864));
    // 0x1413b0: 0xc04e45e  jal         func_139178
    ctx->pc = 0x1413B0u;
    SET_GPR_U32(ctx, 31, 0x1413B8u);
    ctx->pc = 0x1413B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1413B0u;
            // 0x1413b4: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139178u;
    if (runtime->hasFunction(0x139178u)) {
        auto targetFn = runtime->lookupFunction(0x139178u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1413B8u; }
        if (ctx->pc != 0x1413B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139178_0x139178(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1413B8u; }
        if (ctx->pc != 0x1413B8u) { return; }
    }
    ctx->pc = 0x1413B8u;
label_1413b8:
    // 0x1413b8: 0x3c050014  lui         $a1, 0x14
    ctx->pc = 0x1413b8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)20 << 16));
    // 0x1413bc: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x1413bcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1413c0: 0x24a50fb8  addiu       $a1, $a1, 0xFB8
    ctx->pc = 0x1413c0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4024));
    // 0x1413c4: 0xc04e462  jal         func_139188
    ctx->pc = 0x1413C4u;
    SET_GPR_U32(ctx, 31, 0x1413CCu);
    ctx->pc = 0x1413C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1413C4u;
            // 0x1413c8: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139188u;
    if (runtime->hasFunction(0x139188u)) {
        auto targetFn = runtime->lookupFunction(0x139188u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1413CCu; }
        if (ctx->pc != 0x1413CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139188_0x139188(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1413CCu; }
        if (ctx->pc != 0x1413CCu) { return; }
    }
    ctx->pc = 0x1413CCu;
label_1413cc:
    // 0x1413cc: 0x24040003  addiu       $a0, $zero, 0x3
    ctx->pc = 0x1413ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1413d0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1413d0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1413d4: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1413d4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1413d8: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1413d8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1413dc: 0xc04e518  jal         func_139460
    ctx->pc = 0x1413DCu;
    SET_GPR_U32(ctx, 31, 0x1413E4u);
    ctx->pc = 0x1413E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1413DCu;
            // 0x1413e0: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139460u;
    if (runtime->hasFunction(0x139460u)) {
        auto targetFn = runtime->lookupFunction(0x139460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1413E4u; }
        if (ctx->pc != 0x1413E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139460_0x139460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1413E4u; }
        if (ctx->pc != 0x1413E4u) { return; }
    }
    ctx->pc = 0x1413E4u;
label_1413e4:
    // 0x1413e4: 0x26a39a7c  addiu       $v1, $s5, -0x6584
    ctx->pc = 0x1413e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 21), 4294941308));
    // 0x1413e8: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x1413e8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1413ec: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1413ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1413f0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1413f0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1413f4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1413f4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1413f8: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1413f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1413fc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1413fcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x141400: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x141400u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x141404: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x141404u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x141408: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x141408u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x14140c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x14140cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x141410: 0x3e00008  jr          $ra
    ctx->pc = 0x141410u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x141414u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141410u;
            // 0x141414: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1412D0u: goto label_1412d0;
            case 0x1412D8u: goto label_1412d8;
            case 0x141300u: goto label_141300;
            case 0x141314u: goto label_141314;
            case 0x141318u: goto label_141318;
            case 0x141338u: goto label_141338;
            case 0x141368u: goto label_141368;
            case 0x14137Cu: goto label_14137c;
            case 0x141380u: goto label_141380;
            case 0x1413A0u: goto label_1413a0;
            case 0x1413B8u: goto label_1413b8;
            case 0x1413CCu: goto label_1413cc;
            case 0x1413E4u: goto label_1413e4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x141418u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
