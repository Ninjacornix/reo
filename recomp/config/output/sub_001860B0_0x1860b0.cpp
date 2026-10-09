#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001860B0
// Address: 0x1860b0 - 0x186230
void sub_001860B0_0x1860b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001860B0_0x1860b0");
#endif

    switch (ctx->pc) {
        case 0x1860e0u: goto label_1860e0;
        case 0x18612cu: goto label_18612c;
        case 0x18613cu: goto label_18613c;
        case 0x186158u: goto label_186158;
        case 0x186180u: goto label_186180;
        case 0x186198u: goto label_186198;
        case 0x1861b4u: goto label_1861b4;
        case 0x1861ecu: goto label_1861ec;
        case 0x1861f8u: goto label_1861f8;
        case 0x186208u: goto label_186208;
        default: break;
    }

    ctx->pc = 0x1860b0u;

    // 0x1860b0: 0x27bdfd40  addiu       $sp, $sp, -0x2C0
    ctx->pc = 0x1860b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966592));
    // 0x1860b4: 0xffb00280  sd          $s0, 0x280($sp)
    ctx->pc = 0x1860b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 640), GPR_U64(ctx, 16));
    // 0x1860b8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1860b8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1860bc: 0xffb30298  sd          $s3, 0x298($sp)
    ctx->pc = 0x1860bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 664), GPR_U64(ctx, 19));
    // 0x1860c0: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x1860c0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1860c4: 0xffb402a0  sd          $s4, 0x2A0($sp)
    ctx->pc = 0x1860c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 672), GPR_U64(ctx, 20));
    // 0x1860c8: 0xffb10288  sd          $s1, 0x288($sp)
    ctx->pc = 0x1860c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 648), GPR_U64(ctx, 17));
    // 0x1860cc: 0xffb20290  sd          $s2, 0x290($sp)
    ctx->pc = 0x1860ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 656), GPR_U64(ctx, 18));
    // 0x1860d0: 0xffb502a8  sd          $s5, 0x2A8($sp)
    ctx->pc = 0x1860d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 680), GPR_U64(ctx, 21));
    // 0x1860d4: 0xffbf02b0  sd          $ra, 0x2B0($sp)
    ctx->pc = 0x1860d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 688), GPR_U64(ctx, 31));
    // 0x1860d8: 0xc062210  jal         func_188840
    ctx->pc = 0x1860D8u;
    SET_GPR_U32(ctx, 31, 0x1860E0u);
    ctx->pc = 0x1860DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1860D8u;
            // 0x1860dc: 0xa0a02d  daddu       $s4, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x188840u;
    if (runtime->hasFunction(0x188840u)) {
        auto targetFn = runtime->lookupFunction(0x188840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1860E0u; }
        if (ctx->pc != 0x1860E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00188840_0x188840(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1860E0u; }
        if (ctx->pc != 0x1860E0u) { return; }
    }
    ctx->pc = 0x1860E0u;
label_1860e0:
    // 0x1860e0: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x1860E0u;
    {
        const bool branch_taken_0x1860e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1860e0) {
            ctx->pc = 0x1860E4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1860E0u;
            // 0x1860e4: 0x24020898  addiu       $v0, $zero, 0x898 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2200));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1860F8u;
            goto label_1860f8;
        }
    }
    ctx->pc = 0x1860E8u;
    // 0x1860e8: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1860e8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x1860ec: 0x10000047  b           . + 4 + (0x47 << 2)
    ctx->pc = 0x1860ECu;
    {
        const bool branch_taken_0x1860ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1860F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1860ECu;
            // 0x1860f0: 0x34420013  ori         $v0, $v0, 0x13 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)19);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1860ec) {
            ctx->pc = 0x18620Cu;
            goto label_18620c;
        }
    }
    ctx->pc = 0x1860F4u;
    // 0x1860f4: 0x0  nop
    ctx->pc = 0x1860f4u;
    // NOP
label_1860f8:
    // 0x1860f8: 0x3c030028  lui         $v1, 0x28
    ctx->pc = 0x1860f8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)40 << 16));
    // 0x1860fc: 0x2029018  mult        $s2, $s0, $v0
    ctx->pc = 0x1860fcu;
    { int64_t result = (int64_t)GPR_S32(ctx, 16) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 18, (int32_t)result); }
    // 0x186100: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x186100u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x186104: 0x24755b48  addiu       $s5, $v1, 0x5B48
    ctx->pc = 0x186104u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 3), 23368));
    // 0x186108: 0x2551821  addu        $v1, $s2, $s5
    ctx->pc = 0x186108u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 21)));
    // 0x18610c: 0x8c64088c  lw          $a0, 0x88C($v1)
    ctx->pc = 0x18610cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 2188)));
    // 0x186110: 0x1080003e  beqz        $a0, . + 4 + (0x3E << 2)
    ctx->pc = 0x186110u;
    {
        const bool branch_taken_0x186110 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x186114u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186110u;
            // 0x186114: 0x3442006f  ori         $v0, $v0, 0x6F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)111);
        ctx->in_delay_slot = false;
        if (branch_taken_0x186110) {
            ctx->pc = 0x18620Cu;
            goto label_18620c;
        }
    }
    ctx->pc = 0x186118u;
    // 0x186118: 0x27b10200  addiu       $s1, $sp, 0x200
    ctx->pc = 0x186118u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 512));
    // 0x18611c: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x18611cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186120: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x186120u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186124: 0xc0609a2  jal         func_182688
    ctx->pc = 0x186124u;
    SET_GPR_U32(ctx, 31, 0x18612Cu);
    ctx->pc = 0x186128u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186124u;
            // 0x186128: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182688u;
    if (runtime->hasFunction(0x182688u)) {
        auto targetFn = runtime->lookupFunction(0x182688u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18612Cu; }
        if (ctx->pc != 0x18612Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182688_0x182688(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18612Cu; }
        if (ctx->pc != 0x18612Cu) { return; }
    }
    ctx->pc = 0x18612Cu;
label_18612c:
    // 0x18612c: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x18612Cu;
    {
        const bool branch_taken_0x18612c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x18612c) {
            ctx->pc = 0x186144u;
            goto label_186144;
        }
    }
    ctx->pc = 0x186134u;
    // 0x186134: 0xc06089c  jal         func_182270
    ctx->pc = 0x186134u;
    SET_GPR_U32(ctx, 31, 0x18613Cu);
    ctx->pc = 0x186138u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186134u;
            // 0x186138: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182270u;
    if (runtime->hasFunction(0x182270u)) {
        auto targetFn = runtime->lookupFunction(0x182270u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18613Cu; }
        if (ctx->pc != 0x18613Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182270_0x182270(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18613Cu; }
        if (ctx->pc != 0x18613Cu) { return; }
    }
    ctx->pc = 0x18613Cu;
label_18613c:
    // 0x18613c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x18613Cu;
    {
        const bool branch_taken_0x18613c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x18613c) {
            ctx->pc = 0x186150u;
            goto label_186150;
        }
    }
    ctx->pc = 0x186144u;
label_186144:
    // 0x186144: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x186144u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x186148: 0x10000030  b           . + 4 + (0x30 << 2)
    ctx->pc = 0x186148u;
    {
        const bool branch_taken_0x186148 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18614Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186148u;
            // 0x18614c: 0x34420016  ori         $v0, $v0, 0x16 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)22);
        ctx->in_delay_slot = false;
        if (branch_taken_0x186148) {
            ctx->pc = 0x18620Cu;
            goto label_18620c;
        }
    }
    ctx->pc = 0x186150u;
label_186150:
    // 0x186150: 0xc060880  jal         func_182200
    ctx->pc = 0x186150u;
    SET_GPR_U32(ctx, 31, 0x186158u);
    ctx->pc = 0x186154u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186150u;
            // 0x186154: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182200u;
    if (runtime->hasFunction(0x182200u)) {
        auto targetFn = runtime->lookupFunction(0x182200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186158u; }
        if (ctx->pc != 0x186158u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182200_0x182200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186158u; }
        if (ctx->pc != 0x186158u) { return; }
    }
    ctx->pc = 0x186158u;
label_186158:
    // 0x186158: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x186158u;
    {
        const bool branch_taken_0x186158 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x186158) {
            ctx->pc = 0x18615Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x186158u;
            // 0x18615c: 0x3c020024  lui         $v0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x186170u;
            goto label_186170;
        }
    }
    ctx->pc = 0x186160u;
    // 0x186160: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x186160u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x186164: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x186164u;
    {
        const bool branch_taken_0x186164 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x186168u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186164u;
            // 0x186168: 0x3442005b  ori         $v0, $v0, 0x5B (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)91);
        ctx->in_delay_slot = false;
        if (branch_taken_0x186164) {
            ctx->pc = 0x18620Cu;
            goto label_18620c;
        }
    }
    ctx->pc = 0x18616Cu;
    // 0x18616c: 0x0  nop
    ctx->pc = 0x18616cu;
    // NOP
label_186170:
    // 0x186170: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x186170u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186174: 0x245417c8  addiu       $s4, $v0, 0x17C8
    ctx->pc = 0x186174u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), 6088));
    // 0x186178: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x186178u;
    SET_GPR_U32(ctx, 31, 0x186180u);
    ctx->pc = 0x18617Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186178u;
            // 0x18617c: 0x280282d  daddu       $a1, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186180u; }
        if (ctx->pc != 0x186180u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186180u; }
        if (ctx->pc != 0x186180u) { return; }
    }
    ctx->pc = 0x186180u;
label_186180:
    // 0x186180: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x186180u;
    {
        const bool branch_taken_0x186180 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x186180) {
            ctx->pc = 0x186184u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x186180u;
            // 0x186184: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1861A0u;
            goto label_1861a0;
        }
    }
    ctx->pc = 0x186188u;
    // 0x186188: 0x26a40808  addiu       $a0, $s5, 0x808
    ctx->pc = 0x186188u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), 2056));
    // 0x18618c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x18618cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186190: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x186190u;
    SET_GPR_U32(ctx, 31, 0x186198u);
    ctx->pc = 0x186194u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186190u;
            // 0x186194: 0x2442021  addu        $a0, $s2, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186198u; }
        if (ctx->pc != 0x186198u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186198u; }
        if (ctx->pc != 0x186198u) { return; }
    }
    ctx->pc = 0x186198u;
label_186198:
    // 0x186198: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x186198u;
    {
        const bool branch_taken_0x186198 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x186198) {
            ctx->pc = 0x1861F8u;
            goto label_1861f8;
        }
    }
    ctx->pc = 0x1861A0u;
label_1861a0:
    // 0x1861a0: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1861a0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1861a4: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x1861a4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1861a8: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1861a8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1861ac: 0xc0610d8  jal         func_184360
    ctx->pc = 0x1861ACu;
    SET_GPR_U32(ctx, 31, 0x1861B4u);
    ctx->pc = 0x1861B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1861ACu;
            // 0x1861b0: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x184360u;
    if (runtime->hasFunction(0x184360u)) {
        auto targetFn = runtime->lookupFunction(0x184360u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1861B4u; }
        if (ctx->pc != 0x1861B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00184360_0x184360(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1861B4u; }
        if (ctx->pc != 0x1861B4u) { return; }
    }
    ctx->pc = 0x1861B4u;
label_1861b4:
    // 0x1861b4: 0x3c038101  lui         $v1, 0x8101
    ctx->pc = 0x1861b4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33025 << 16));
    // 0x1861b8: 0x34630011  ori         $v1, $v1, 0x11
    ctx->pc = 0x1861b8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)17);
    // 0x1861bc: 0x14430014  bne         $v0, $v1, . + 4 + (0x14 << 2)
    ctx->pc = 0x1861BCu;
    {
        const bool branch_taken_0x1861bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1861C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1861BCu;
            // 0x1861c0: 0xdfb00280  ld          $s0, 0x280($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 640)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1861bc) {
            ctx->pc = 0x186210u;
            goto label_186210;
        }
    }
    ctx->pc = 0x1861C4u;
    // 0x1861c4: 0x97a30000  lhu         $v1, 0x0($sp)
    ctx->pc = 0x1861c4u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1861c8: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1861c8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x1861cc: 0x30630020  andi        $v1, $v1, 0x20
    ctx->pc = 0x1861ccu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)32);
    // 0x1861d0: 0x1060000f  beqz        $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x1861D0u;
    {
        const bool branch_taken_0x1861d0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1861D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1861D0u;
            // 0x1861d4: 0x34420014  ori         $v0, $v0, 0x14 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)20);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1861d0) {
            ctx->pc = 0x186210u;
            goto label_186210;
        }
    }
    ctx->pc = 0x1861D8u;
    // 0x1861d8: 0x26b00808  addiu       $s0, $s5, 0x808
    ctx->pc = 0x1861d8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 21), 2056));
    // 0x1861dc: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1861dcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1861e0: 0x2508021  addu        $s0, $s2, $s0
    ctx->pc = 0x1861e0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 16)));
    // 0x1861e4: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1861E4u;
    SET_GPR_U32(ctx, 31, 0x1861ECu);
    ctx->pc = 0x1861E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1861E4u;
            // 0x1861e8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1861ECu; }
        if (ctx->pc != 0x1861ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1861ECu; }
        if (ctx->pc != 0x1861ECu) { return; }
    }
    ctx->pc = 0x1861ECu;
label_1861ec:
    // 0x1861ec: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1861ecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1861f0: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x1861F0u;
    SET_GPR_U32(ctx, 31, 0x1861F8u);
    ctx->pc = 0x1861F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1861F0u;
            // 0x1861f4: 0x280282d  daddu       $a1, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1861F8u; }
        if (ctx->pc != 0x1861F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1861F8u; }
        if (ctx->pc != 0x1861F8u) { return; }
    }
    ctx->pc = 0x1861F8u;
label_1861f8:
    // 0x1861f8: 0x12600003  beqz        $s3, . + 4 + (0x3 << 2)
    ctx->pc = 0x1861F8u;
    {
        const bool branch_taken_0x1861f8 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x1861FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1861F8u;
            // 0x1861fc: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1861f8) {
            ctx->pc = 0x186208u;
            goto label_186208;
        }
    }
    ctx->pc = 0x186200u;
    // 0x186200: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x186200u;
    SET_GPR_U32(ctx, 31, 0x186208u);
    ctx->pc = 0x186204u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186200u;
            // 0x186204: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186208u; }
        if (ctx->pc != 0x186208u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186208u; }
        if (ctx->pc != 0x186208u) { return; }
    }
    ctx->pc = 0x186208u;
label_186208:
    // 0x186208: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x186208u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_18620c:
    // 0x18620c: 0xdfb00280  ld          $s0, 0x280($sp)
    ctx->pc = 0x18620cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 640)));
label_186210:
    // 0x186210: 0xdfb10288  ld          $s1, 0x288($sp)
    ctx->pc = 0x186210u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 648)));
    // 0x186214: 0xdfb20290  ld          $s2, 0x290($sp)
    ctx->pc = 0x186214u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 656)));
    // 0x186218: 0xdfb30298  ld          $s3, 0x298($sp)
    ctx->pc = 0x186218u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 664)));
    // 0x18621c: 0xdfb402a0  ld          $s4, 0x2A0($sp)
    ctx->pc = 0x18621cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 672)));
    // 0x186220: 0xdfb502a8  ld          $s5, 0x2A8($sp)
    ctx->pc = 0x186220u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 680)));
    // 0x186224: 0xdfbf02b0  ld          $ra, 0x2B0($sp)
    ctx->pc = 0x186224u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 688)));
    // 0x186228: 0x3e00008  jr          $ra
    ctx->pc = 0x186228u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18622Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186228u;
            // 0x18622c: 0x27bd02c0  addiu       $sp, $sp, 0x2C0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 704));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1860E0u: goto label_1860e0;
            case 0x1860F8u: goto label_1860f8;
            case 0x18612Cu: goto label_18612c;
            case 0x18613Cu: goto label_18613c;
            case 0x186144u: goto label_186144;
            case 0x186150u: goto label_186150;
            case 0x186158u: goto label_186158;
            case 0x186170u: goto label_186170;
            case 0x186180u: goto label_186180;
            case 0x186198u: goto label_186198;
            case 0x1861A0u: goto label_1861a0;
            case 0x1861B4u: goto label_1861b4;
            case 0x1861ECu: goto label_1861ec;
            case 0x1861F8u: goto label_1861f8;
            case 0x186208u: goto label_186208;
            case 0x18620Cu: goto label_18620c;
            case 0x186210u: goto label_186210;
            default: break;
        }
        return;
    }
    ctx->pc = 0x186230u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
