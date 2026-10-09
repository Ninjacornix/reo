#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00186230
// Address: 0x186230 - 0x186798
void sub_00186230_0x186230(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00186230_0x186230");
#endif

    switch (ctx->pc) {
        case 0x18627cu: goto label_18627c;
        case 0x1862bcu: goto label_1862bc;
        case 0x1862d4u: goto label_1862d4;
        case 0x1862f4u: goto label_1862f4;
        case 0x186300u: goto label_186300;
        case 0x18630cu: goto label_18630c;
        case 0x186320u: goto label_186320;
        case 0x186328u: goto label_186328;
        case 0x18634cu: goto label_18634c;
        case 0x186380u: goto label_186380;
        case 0x1863bcu: goto label_1863bc;
        case 0x1863f0u: goto label_1863f0;
        case 0x18640cu: goto label_18640c;
        case 0x186464u: goto label_186464;
        case 0x1864d0u: goto label_1864d0;
        case 0x186500u: goto label_186500;
        case 0x186510u: goto label_186510;
        case 0x186524u: goto label_186524;
        case 0x186538u: goto label_186538;
        case 0x186550u: goto label_186550;
        case 0x1865b4u: goto label_1865b4;
        case 0x186614u: goto label_186614;
        case 0x186674u: goto label_186674;
        case 0x186684u: goto label_186684;
        case 0x1866a4u: goto label_1866a4;
        case 0x1866e8u: goto label_1866e8;
        case 0x186704u: goto label_186704;
        default: break;
    }

    ctx->pc = 0x186230u;

    // 0x186230: 0x27bdfa60  addiu       $sp, $sp, -0x5A0
    ctx->pc = 0x186230u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294965856));
    // 0x186234: 0xffb00550  sd          $s0, 0x550($sp)
    ctx->pc = 0x186234u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1360), GPR_U64(ctx, 16));
    // 0x186238: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x186238u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18623c: 0xffb10558  sd          $s1, 0x558($sp)
    ctx->pc = 0x18623cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1368), GPR_U64(ctx, 17));
    // 0x186240: 0x100882d  daddu       $s1, $t0, $zero
    ctx->pc = 0x186240u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186244: 0xffb40570  sd          $s4, 0x570($sp)
    ctx->pc = 0x186244u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1392), GPR_U64(ctx, 20));
    // 0x186248: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x186248u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18624c: 0xffb60580  sd          $s6, 0x580($sp)
    ctx->pc = 0x18624cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1408), GPR_U64(ctx, 22));
    // 0x186250: 0xc0b02d  daddu       $s6, $a2, $zero
    ctx->pc = 0x186250u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186254: 0xffbe0590  sd          $fp, 0x590($sp)
    ctx->pc = 0x186254u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1424), GPR_U64(ctx, 30));
    // 0x186258: 0xe0f02d  daddu       $fp, $a3, $zero
    ctx->pc = 0x186258u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18625c: 0xffb20560  sd          $s2, 0x560($sp)
    ctx->pc = 0x18625cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1376), GPR_U64(ctx, 18));
    // 0x186260: 0xffb30568  sd          $s3, 0x568($sp)
    ctx->pc = 0x186260u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1384), GPR_U64(ctx, 19));
    // 0x186264: 0xffb50578  sd          $s5, 0x578($sp)
    ctx->pc = 0x186264u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1400), GPR_U64(ctx, 21));
    // 0x186268: 0xffb70588  sd          $s7, 0x588($sp)
    ctx->pc = 0x186268u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1416), GPR_U64(ctx, 23));
    // 0x18626c: 0xffbf0598  sd          $ra, 0x598($sp)
    ctx->pc = 0x18626cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1432), GPR_U64(ctx, 31));
    // 0x186270: 0xafa90544  sw          $t1, 0x544($sp)
    ctx->pc = 0x186270u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 1348), GPR_U32(ctx, 9));
    // 0x186274: 0xc062210  jal         func_188840
    ctx->pc = 0x186274u;
    SET_GPR_U32(ctx, 31, 0x18627Cu);
    ctx->pc = 0x186278u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186274u;
            // 0x186278: 0xafa00548  sw          $zero, 0x548($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 1352), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x188840u;
    if (runtime->hasFunction(0x188840u)) {
        auto targetFn = runtime->lookupFunction(0x188840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18627Cu; }
        if (ctx->pc != 0x18627Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00188840_0x188840(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18627Cu; }
        if (ctx->pc != 0x18627Cu) { return; }
    }
    ctx->pc = 0x18627Cu;
label_18627c:
    // 0x18627c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x18627Cu;
    {
        const bool branch_taken_0x18627c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x186280u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18627Cu;
            // 0x186280: 0x24030898  addiu       $v1, $zero, 0x898 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2200));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18627c) {
            ctx->pc = 0x186290u;
            goto label_186290;
        }
    }
    ctx->pc = 0x186284u;
    // 0x186284: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x186284u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x186288: 0x10000137  b           . + 4 + (0x137 << 2)
    ctx->pc = 0x186288u;
    {
        const bool branch_taken_0x186288 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18628Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186288u;
            // 0x18628c: 0x34420013  ori         $v0, $v0, 0x13 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)19);
        ctx->in_delay_slot = false;
        if (branch_taken_0x186288) {
            ctx->pc = 0x186768u;
            goto label_186768;
        }
    }
    ctx->pc = 0x186290u;
label_186290:
    // 0x186290: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x186290u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x186294: 0x2831818  mult        $v1, $s4, $v1
    ctx->pc = 0x186294u;
    { int64_t result = (int64_t)GPR_S32(ctx, 20) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x186298: 0x3c040028  lui         $a0, 0x28
    ctx->pc = 0x186298u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)40 << 16));
    // 0x18629c: 0x832021  addu        $a0, $a0, $v1
    ctx->pc = 0x18629cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1862a0: 0x8c8463d4  lw          $a0, 0x63D4($a0)
    ctx->pc = 0x1862a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 25556)));
    // 0x1862a4: 0x10800130  beqz        $a0, . + 4 + (0x130 << 2)
    ctx->pc = 0x1862A4u;
    {
        const bool branch_taken_0x1862a4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1862A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1862A4u;
            // 0x1862a8: 0x3442006f  ori         $v0, $v0, 0x6F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)111);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1862a4) {
            ctx->pc = 0x186768u;
            goto label_186768;
        }
    }
    ctx->pc = 0x1862ACu;
    // 0x1862ac: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1862acu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1862b0: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1862b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1862b4: 0xc0609a2  jal         func_182688
    ctx->pc = 0x1862B4u;
    SET_GPR_U32(ctx, 31, 0x1862BCu);
    ctx->pc = 0x1862B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1862B4u;
            // 0x1862b8: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182688u;
    if (runtime->hasFunction(0x182688u)) {
        auto targetFn = runtime->lookupFunction(0x182688u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1862BCu; }
        if (ctx->pc != 0x1862BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182688_0x182688(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1862BCu; }
        if (ctx->pc != 0x1862BCu) { return; }
    }
    ctx->pc = 0x1862BCu;
label_1862bc:
    // 0x1862bc: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1862BCu;
    {
        const bool branch_taken_0x1862bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1862C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1862BCu;
            // 0x1862c0: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1862bc) {
            ctx->pc = 0x1862DCu;
            goto label_1862dc;
        }
    }
    ctx->pc = 0x1862C4u;
    // 0x1862c4: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x1862c4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x1862c8: 0x245217c8  addiu       $s2, $v0, 0x17C8
    ctx->pc = 0x1862c8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 2), 6088));
    // 0x1862cc: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x1862CCu;
    SET_GPR_U32(ctx, 31, 0x1862D4u);
    ctx->pc = 0x1862D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1862CCu;
            // 0x1862d0: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1862D4u; }
        if (ctx->pc != 0x1862D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1862D4u; }
        if (ctx->pc != 0x1862D4u) { return; }
    }
    ctx->pc = 0x1862D4u;
label_1862d4:
    // 0x1862d4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1862D4u;
    {
        const bool branch_taken_0x1862d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1862D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1862D4u;
            // 0x1862d8: 0x27b00080  addiu       $s0, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1862d4) {
            ctx->pc = 0x1862E8u;
            goto label_1862e8;
        }
    }
    ctx->pc = 0x1862DCu;
label_1862dc:
    // 0x1862dc: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1862dcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x1862e0: 0x10000121  b           . + 4 + (0x121 << 2)
    ctx->pc = 0x1862E0u;
    {
        const bool branch_taken_0x1862e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1862E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1862E0u;
            // 0x1862e4: 0x34420016  ori         $v0, $v0, 0x16 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)22);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1862e0) {
            ctx->pc = 0x186768u;
            goto label_186768;
        }
    }
    ctx->pc = 0x1862E8u;
label_1862e8:
    // 0x1862e8: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x1862e8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1862ec: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1862ECu;
    SET_GPR_U32(ctx, 31, 0x1862F4u);
    ctx->pc = 0x1862F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1862ECu;
            // 0x1862f0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1862F4u; }
        if (ctx->pc != 0x1862F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1862F4u; }
        if (ctx->pc != 0x1862F4u) { return; }
    }
    ctx->pc = 0x1862F4u;
label_1862f4:
    // 0x1862f4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1862f4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1862f8: 0xc042dee  jal         func_10B7B8
    ctx->pc = 0x1862F8u;
    SET_GPR_U32(ctx, 31, 0x186300u);
    ctx->pc = 0x1862FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1862F8u;
            // 0x1862fc: 0x2405002f  addiu       $a1, $zero, 0x2F (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B7B8u;
    if (runtime->hasFunction(0x10B7B8u)) {
        auto targetFn = runtime->lookupFunction(0x10B7B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186300u; }
        if (ctx->pc != 0x186300u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B7B8_0x10b7b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186300u; }
        if (ctx->pc != 0x186300u) { return; }
    }
    ctx->pc = 0x186300u;
label_186300:
    // 0x186300: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x186300u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186304: 0xc042c56  jal         func_10B158
    ctx->pc = 0x186304u;
    SET_GPR_U32(ctx, 31, 0x18630Cu);
    ctx->pc = 0x186308u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186304u;
            // 0x186308: 0xa0400000  sb          $zero, 0x0($v0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18630Cu; }
        if (ctx->pc != 0x18630Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18630Cu; }
        if (ctx->pc != 0x18630Cu) { return; }
    }
    ctx->pc = 0x18630Cu;
label_18630c:
    // 0x18630c: 0x2021021  addu        $v0, $s0, $v0
    ctx->pc = 0x18630cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x186310: 0x24450001  addiu       $a1, $v0, 0x1
    ctx->pc = 0x186310u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x186314: 0x27a20100  addiu       $v0, $sp, 0x100
    ctx->pc = 0x186314u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 256));
    // 0x186318: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x186318u;
    SET_GPR_U32(ctx, 31, 0x186320u);
    ctx->pc = 0x18631Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186318u;
            // 0x18631c: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186320u; }
        if (ctx->pc != 0x186320u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186320u; }
        if (ctx->pc != 0x186320u) { return; }
    }
    ctx->pc = 0x186320u;
label_186320:
    // 0x186320: 0xc042c56  jal         func_10B158
    ctx->pc = 0x186320u;
    SET_GPR_U32(ctx, 31, 0x186328u);
    ctx->pc = 0x186324u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186320u;
            // 0x186324: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186328u; }
        if (ctx->pc != 0x186328u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186328u; }
        if (ctx->pc != 0x186328u) { return; }
    }
    ctx->pc = 0x186328u;
label_186328:
    // 0x186328: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x186328u;
    {
        const bool branch_taken_0x186328 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x18632Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186328u;
            // 0x18632c: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x186328) {
            ctx->pc = 0x186368u;
            goto label_186368;
        }
    }
    ctx->pc = 0x186330u;
    // 0x186330: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x186330u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186334: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x186334u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186338: 0x27a60340  addiu       $a2, $sp, 0x340
    ctx->pc = 0x186338u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 832));
    // 0x18633c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x18633cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186340: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x186340u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186344: 0xc0610d8  jal         func_184360
    ctx->pc = 0x186344u;
    SET_GPR_U32(ctx, 31, 0x18634Cu);
    ctx->pc = 0x186348u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186344u;
            // 0x186348: 0x24100001  addiu       $s0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x184360u;
    if (runtime->hasFunction(0x184360u)) {
        auto targetFn = runtime->lookupFunction(0x184360u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18634Cu; }
        if (ctx->pc != 0x18634Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00184360_0x184360(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18634Cu; }
        if (ctx->pc != 0x18634Cu) { return; }
    }
    ctx->pc = 0x18634Cu;
label_18634c:
    // 0x18634c: 0x3c038101  lui         $v1, 0x8101
    ctx->pc = 0x18634cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33025 << 16));
    // 0x186350: 0x34630011  ori         $v1, $v1, 0x11
    ctx->pc = 0x186350u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)17);
    // 0x186354: 0x1043000e  beq         $v0, $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x186354u;
    {
        const bool branch_taken_0x186354 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x186358u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186354u;
            // 0x186358: 0xafa20540  sw          $v0, 0x540($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 1344), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x186354) {
            ctx->pc = 0x186390u;
            goto label_186390;
        }
    }
    ctx->pc = 0x18635Cu;
    // 0x18635c: 0x10000103  b           . + 4 + (0x103 << 2)
    ctx->pc = 0x18635Cu;
    {
        const bool branch_taken_0x18635c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x186360u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18635Cu;
            // 0x186360: 0xdfb00550  ld          $s0, 0x550($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 1360)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18635c) {
            ctx->pc = 0x18676Cu;
            goto label_18676c;
        }
    }
    ctx->pc = 0x186364u;
    // 0x186364: 0x0  nop
    ctx->pc = 0x186364u;
    // NOP
label_186368:
    // 0x186368: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x186368u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18636c: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x18636cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186370: 0x27a60340  addiu       $a2, $sp, 0x340
    ctx->pc = 0x186370u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 832));
    // 0x186374: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x186374u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186378: 0xc0610d8  jal         func_184360
    ctx->pc = 0x186378u;
    SET_GPR_U32(ctx, 31, 0x186380u);
    ctx->pc = 0x18637Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186378u;
            // 0x18637c: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x184360u;
    if (runtime->hasFunction(0x184360u)) {
        auto targetFn = runtime->lookupFunction(0x184360u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186380u; }
        if (ctx->pc != 0x186380u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00184360_0x184360(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186380u; }
        if (ctx->pc != 0x186380u) { return; }
    }
    ctx->pc = 0x186380u;
label_186380:
    // 0x186380: 0x3c038101  lui         $v1, 0x8101
    ctx->pc = 0x186380u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33025 << 16));
    // 0x186384: 0x34630011  ori         $v1, $v1, 0x11
    ctx->pc = 0x186384u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)17);
    // 0x186388: 0x144300f7  bne         $v0, $v1, . + 4 + (0xF7 << 2)
    ctx->pc = 0x186388u;
    {
        const bool branch_taken_0x186388 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x18638Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186388u;
            // 0x18638c: 0xafa20540  sw          $v0, 0x540($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 1344), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x186388) {
            ctx->pc = 0x186768u;
            goto label_186768;
        }
    }
    ctx->pc = 0x186390u;
label_186390:
    // 0x186390: 0x97a30340  lhu         $v1, 0x340($sp)
    ctx->pc = 0x186390u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 832)));
    // 0x186394: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x186394u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x186398: 0x30630020  andi        $v1, $v1, 0x20
    ctx->pc = 0x186398u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)32);
    // 0x18639c: 0x106000f2  beqz        $v1, . + 4 + (0xF2 << 2)
    ctx->pc = 0x18639Cu;
    {
        const bool branch_taken_0x18639c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1863A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18639Cu;
            // 0x1863a0: 0x34420014  ori         $v0, $v0, 0x14 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)20);
        ctx->in_delay_slot = false;
        if (branch_taken_0x18639c) {
            ctx->pc = 0x186768u;
            goto label_186768;
        }
    }
    ctx->pc = 0x1863A4u;
    // 0x1863a4: 0x27a30140  addiu       $v1, $sp, 0x140
    ctx->pc = 0x1863a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 320));
    // 0x1863a8: 0x8fa60350  lw          $a2, 0x350($sp)
    ctx->pc = 0x1863a8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 848)));
    // 0x1863ac: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x1863acu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1863b0: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1863b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1863b4: 0xc060c02  jal         func_183008
    ctx->pc = 0x1863B4u;
    SET_GPR_U32(ctx, 31, 0x1863BCu);
    ctx->pc = 0x1863B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1863B4u;
            // 0x1863b8: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x183008u;
    if (runtime->hasFunction(0x183008u)) {
        auto targetFn = runtime->lookupFunction(0x183008u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1863BCu; }
        if (ctx->pc != 0x1863BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00183008_0x183008(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1863BCu; }
        if (ctx->pc != 0x1863BCu) { return; }
    }
    ctx->pc = 0x1863BCu;
label_1863bc:
    // 0x1863bc: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1863bcu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1863c0: 0x14600015  bnez        $v1, . + 4 + (0x15 << 2)
    ctx->pc = 0x1863C0u;
    {
        const bool branch_taken_0x1863c0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1863C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1863C0u;
            // 0x1863c4: 0xafa20540  sw          $v0, 0x540($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 1344), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1863c0) {
            ctx->pc = 0x186418u;
            goto label_186418;
        }
    }
    ctx->pc = 0x1863C8u;
    // 0x1863c8: 0x97a30140  lhu         $v1, 0x140($sp)
    ctx->pc = 0x1863c8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 320)));
    // 0x1863cc: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1863ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x1863d0: 0x30638000  andi        $v1, $v1, 0x8000
    ctx->pc = 0x1863d0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)32768);
    // 0x1863d4: 0x106000e4  beqz        $v1, . + 4 + (0xE4 << 2)
    ctx->pc = 0x1863D4u;
    {
        const bool branch_taken_0x1863d4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1863D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1863D4u;
            // 0x1863d8: 0x34429002  ori         $v0, $v0, 0x9002 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)36866);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1863d4) {
            ctx->pc = 0x186768u;
            goto label_186768;
        }
    }
    ctx->pc = 0x1863DCu;
    // 0x1863dc: 0x27b50180  addiu       $s5, $sp, 0x180
    ctx->pc = 0x1863dcu;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 29), 384));
    // 0x1863e0: 0x3c060024  lui         $a2, 0x24
    ctx->pc = 0x1863e0u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
    // 0x1863e4: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x1863e4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1863e8: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x1863E8u;
    SET_GPR_U32(ctx, 31, 0x1863F0u);
    ctx->pc = 0x1863ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1863E8u;
            // 0x1863ec: 0x24c517b0  addiu       $a1, $a2, 0x17B0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 6), 6064));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1863F0u; }
        if (ctx->pc != 0x1863F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1863F0u; }
        if (ctx->pc != 0x1863F0u) { return; }
    }
    ctx->pc = 0x1863F0u;
label_1863f0:
    // 0x1863f0: 0x144000ca  bnez        $v0, . + 4 + (0xCA << 2)
    ctx->pc = 0x1863F0u;
    {
        const bool branch_taken_0x1863f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1863F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1863F0u;
            // 0x1863f4: 0x27a70140  addiu       $a3, $sp, 0x140 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 320));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1863f0) {
            ctx->pc = 0x18671Cu;
            goto label_18671c;
        }
    }
    ctx->pc = 0x1863F8u;
    // 0x1863f8: 0x8fa60350  lw          $a2, 0x350($sp)
    ctx->pc = 0x1863f8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 848)));
    // 0x1863fc: 0xe0282d  daddu       $a1, $a3, $zero
    ctx->pc = 0x1863fcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186400: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x186400u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x186404: 0xc060c02  jal         func_183008
    ctx->pc = 0x186404u;
    SET_GPR_U32(ctx, 31, 0x18640Cu);
    ctx->pc = 0x186408u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186404u;
            // 0x186408: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x183008u;
    if (runtime->hasFunction(0x183008u)) {
        auto targetFn = runtime->lookupFunction(0x183008u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18640Cu; }
        if (ctx->pc != 0x18640Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00183008_0x183008(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18640Cu; }
        if (ctx->pc != 0x18640Cu) { return; }
    }
    ctx->pc = 0x18640Cu;
label_18640c:
    // 0x18640c: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x18640cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186410: 0x1060000b  beqz        $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x186410u;
    {
        const bool branch_taken_0x186410 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x186414u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186410u;
            // 0x186414: 0xafa20540  sw          $v0, 0x540($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 1344), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x186410) {
            ctx->pc = 0x186440u;
            goto label_186440;
        }
    }
    ctx->pc = 0x186418u;
label_186418:
    // 0x186418: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x186418u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x18641c: 0x34420002  ori         $v0, $v0, 0x2
    ctx->pc = 0x18641cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)2);
    // 0x186420: 0x546200d1  bnel        $v1, $v0, . + 4 + (0xD1 << 2)
    ctx->pc = 0x186420u;
    {
        const bool branch_taken_0x186420 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x186420) {
            ctx->pc = 0x186424u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x186420u;
            // 0x186424: 0x8fa20540  lw          $v0, 0x540($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 1344)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x186768u;
            goto label_186768;
        }
    }
    ctx->pc = 0x186428u;
    // 0x186428: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x186428u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x18642c: 0x34429002  ori         $v0, $v0, 0x9002
    ctx->pc = 0x18642cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)36866);
    // 0x186430: 0xafa20540  sw          $v0, 0x540($sp)
    ctx->pc = 0x186430u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 1344), GPR_U32(ctx, 2));
    // 0x186434: 0x100000cc  b           . + 4 + (0xCC << 2)
    ctx->pc = 0x186434u;
    {
        const bool branch_taken_0x186434 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x186438u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186434u;
            // 0x186438: 0x8fa20540  lw          $v0, 0x540($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 1344)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x186434) {
            ctx->pc = 0x186768u;
            goto label_186768;
        }
    }
    ctx->pc = 0x18643Cu;
    // 0x18643c: 0x0  nop
    ctx->pc = 0x18643cu;
    // NOP
label_186440:
    // 0x186440: 0x97a30140  lhu         $v1, 0x140($sp)
    ctx->pc = 0x186440u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 320)));
    // 0x186444: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x186444u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x186448: 0x30638000  andi        $v1, $v1, 0x8000
    ctx->pc = 0x186448u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)32768);
    // 0x18644c: 0x106000c6  beqz        $v1, . + 4 + (0xC6 << 2)
    ctx->pc = 0x18644Cu;
    {
        const bool branch_taken_0x18644c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x186450u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18644Cu;
            // 0x186450: 0x34429002  ori         $v0, $v0, 0x9002 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)36866);
        ctx->in_delay_slot = false;
        if (branch_taken_0x18644c) {
            ctx->pc = 0x186768u;
            goto label_186768;
        }
    }
    ctx->pc = 0x186454u;
    // 0x186454: 0x3c080024  lui         $t0, 0x24
    ctx->pc = 0x186454u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)36 << 16));
    // 0x186458: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x186458u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18645c: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x18645Cu;
    SET_GPR_U32(ctx, 31, 0x186464u);
    ctx->pc = 0x186460u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18645Cu;
            // 0x186460: 0x250517b8  addiu       $a1, $t0, 0x17B8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 8), 6072));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186464u; }
        if (ctx->pc != 0x186464u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186464u; }
        if (ctx->pc != 0x186464u) { return; }
    }
    ctx->pc = 0x186464u;
label_186464:
    // 0x186464: 0x144000ad  bnez        $v0, . + 4 + (0xAD << 2)
    ctx->pc = 0x186464u;
    {
        const bool branch_taken_0x186464 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x186468u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186464u;
            // 0x186468: 0x8fa40344  lw          $a0, 0x344($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 836)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x186464) {
            ctx->pc = 0x18671Cu;
            goto label_18671c;
        }
    }
    ctx->pc = 0x18646Cu;
    // 0x18646c: 0x28830002  slti        $v1, $a0, 0x2
    ctx->pc = 0x18646cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x186470: 0x146000aa  bnez        $v1, . + 4 + (0xAA << 2)
    ctx->pc = 0x186470u;
    {
        const bool branch_taken_0x186470 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x186470) {
            ctx->pc = 0x18671Cu;
            goto label_18671c;
        }
    }
    ctx->pc = 0x186478u;
    // 0x186478: 0x2c4182a  slt         $v1, $s6, $a0
    ctx->pc = 0x186478u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 22) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x18647c: 0x14600006  bnez        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x18647Cu;
    {
        const bool branch_taken_0x18647c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x186480u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18647Cu;
            // 0x186480: 0xb82d  daddu       $s7, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18647c) {
            ctx->pc = 0x186498u;
            goto label_186498;
        }
    }
    ctx->pc = 0x186484u;
    // 0x186484: 0x8fa90544  lw          $t1, 0x544($sp)
    ctx->pc = 0x186484u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 1348)));
    // 0x186488: 0x552000b7  bnel        $t1, $zero, . + 4 + (0xB7 << 2)
    ctx->pc = 0x186488u;
    {
        const bool branch_taken_0x186488 = (GPR_U64(ctx, 9) != GPR_U64(ctx, 0));
        if (branch_taken_0x186488) {
            ctx->pc = 0x18648Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x186488u;
            // 0x18648c: 0xad200000  sw          $zero, 0x0($t1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 9), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x186768u;
            goto label_186768;
        }
    }
    ctx->pc = 0x186490u;
    // 0x186490: 0x100000b6  b           . + 4 + (0xB6 << 2)
    ctx->pc = 0x186490u;
    {
        const bool branch_taken_0x186490 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x186494u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186490u;
            // 0x186494: 0xdfb00550  ld          $s0, 0x550($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 1360)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x186490) {
            ctx->pc = 0x18676Cu;
            goto label_18676c;
        }
    }
    ctx->pc = 0x186498u;
label_186498:
    // 0x186498: 0x120000ac  beqz        $s0, . + 4 + (0xAC << 2)
    ctx->pc = 0x186498u;
    {
        const bool branch_taken_0x186498 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x18649Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186498u;
            // 0x18649c: 0x8fb20350  lw          $s2, 0x350($sp) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 848)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x186498) {
            ctx->pc = 0x18674Cu;
            goto label_18674c;
        }
    }
    ctx->pc = 0x1864A0u;
    // 0x1864a0: 0x2483fffe  addiu       $v1, $a0, -0x2
    ctx->pc = 0x1864a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967294));
    // 0x1864a4: 0x14600006  bnez        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1864A4u;
    {
        const bool branch_taken_0x1864a4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1864A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1864A4u;
            // 0x1864a8: 0xafa30344  sw          $v1, 0x344($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 836), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1864a4) {
            ctx->pc = 0x1864C0u;
            goto label_1864c0;
        }
    }
    ctx->pc = 0x1864ACu;
    // 0x1864ac: 0x8fa30544  lw          $v1, 0x544($sp)
    ctx->pc = 0x1864acu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 1348)));
    // 0x1864b0: 0x546000ad  bnel        $v1, $zero, . + 4 + (0xAD << 2)
    ctx->pc = 0x1864B0u;
    {
        const bool branch_taken_0x1864b0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1864b0) {
            ctx->pc = 0x1864B4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1864B0u;
            // 0x1864b4: 0xac600000  sw          $zero, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x186768u;
            goto label_186768;
        }
    }
    ctx->pc = 0x1864B8u;
    // 0x1864b8: 0x100000ac  b           . + 4 + (0xAC << 2)
    ctx->pc = 0x1864B8u;
    {
        const bool branch_taken_0x1864b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1864BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1864B8u;
            // 0x1864bc: 0xdfb00550  ld          $s0, 0x550($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 1360)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1864b8) {
            ctx->pc = 0x18676Cu;
            goto label_18676c;
        }
    }
    ctx->pc = 0x1864C0u;
label_1864c0:
    // 0x1864c0: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1864c0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1864c4: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1864c4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1864c8: 0xc060b12  jal         func_182C48
    ctx->pc = 0x1864C8u;
    SET_GPR_U32(ctx, 31, 0x1864D0u);
    ctx->pc = 0x1864CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1864C8u;
            // 0x1864cc: 0x27a60540  addiu       $a2, $sp, 0x540 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 1344));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182C48u;
    if (runtime->hasFunction(0x182C48u)) {
        auto targetFn = runtime->lookupFunction(0x182C48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1864D0u; }
        if (ctx->pc != 0x1864D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182C48_0x182c48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1864D0u; }
        if (ctx->pc != 0x1864D0u) { return; }
    }
    ctx->pc = 0x1864D0u;
label_1864d0:
    // 0x1864d0: 0x3c038101  lui         $v1, 0x8101
    ctx->pc = 0x1864d0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33025 << 16));
    // 0x1864d4: 0x8fa40540  lw          $a0, 0x540($sp)
    ctx->pc = 0x1864d4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 1344)));
    // 0x1864d8: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x1864d8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1864dc: 0x34630059  ori         $v1, $v1, 0x59
    ctx->pc = 0x1864dcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)89);
    // 0x1864e0: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1864e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x1864e4: 0x108300a0  beq         $a0, $v1, . + 4 + (0xA0 << 2)
    ctx->pc = 0x1864E4u;
    {
        const bool branch_taken_0x1864e4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1864E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1864E4u;
            // 0x1864e8: 0x34429002  ori         $v0, $v0, 0x9002 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)36866);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1864e4) {
            ctx->pc = 0x186768u;
            goto label_186768;
        }
    }
    ctx->pc = 0x1864ECu;
    // 0x1864ec: 0x10800097  beqz        $a0, . + 4 + (0x97 << 2)
    ctx->pc = 0x1864ECu;
    {
        const bool branch_taken_0x1864ec = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1864F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1864ECu;
            // 0x1864f0: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1864ec) {
            ctx->pc = 0x18674Cu;
            goto label_18674c;
        }
    }
    ctx->pc = 0x1864F4u;
    // 0x1864f4: 0x1000009d  b           . + 4 + (0x9D << 2)
    ctx->pc = 0x1864F4u;
    {
        const bool branch_taken_0x1864f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1864F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1864F4u;
            // 0x1864f8: 0xdfb00550  ld          $s0, 0x550($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 1360)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1864f4) {
            ctx->pc = 0x18676Cu;
            goto label_18676c;
        }
    }
    ctx->pc = 0x1864FCu;
    // 0x1864fc: 0x0  nop
    ctx->pc = 0x1864fcu;
    // NOP
label_186500:
    // 0x186500: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x186500u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x186504: 0x10000098  b           . + 4 + (0x98 << 2)
    ctx->pc = 0x186504u;
    {
        const bool branch_taken_0x186504 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x186508u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186504u;
            // 0x186508: 0x3442006f  ori         $v0, $v0, 0x6F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)111);
        ctx->in_delay_slot = false;
        if (branch_taken_0x186504) {
            ctx->pc = 0x186768u;
            goto label_186768;
        }
    }
    ctx->pc = 0x18650Cu;
    // 0x18650c: 0x0  nop
    ctx->pc = 0x18650cu;
    // NOP
label_186510:
    // 0x186510: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x186510u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186514: 0x24c56c80  addiu       $a1, $a2, 0x6C80
    ctx->pc = 0x186514u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 6), 27776));
    // 0x186518: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x186518u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18651c: 0xc061d1e  jal         func_187478
    ctx->pc = 0x18651Cu;
    SET_GPR_U32(ctx, 31, 0x186524u);
    ctx->pc = 0x186520u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18651Cu;
            // 0x186520: 0x24070001  addiu       $a3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x187478u;
    if (runtime->hasFunction(0x187478u)) {
        auto targetFn = runtime->lookupFunction(0x187478u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186524u; }
        if (ctx->pc != 0x186524u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187478_0x187478(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186524u; }
        if (ctx->pc != 0x186524u) { return; }
    }
    ctx->pc = 0x186524u;
label_186524:
    // 0x186524: 0x1040fff6  beqz        $v0, . + 4 + (-0xA << 2)
    ctx->pc = 0x186524u;
    {
        const bool branch_taken_0x186524 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x186528u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186524u;
            // 0x186528: 0x982d  daddu       $s3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x186524) {
            ctx->pc = 0x186500u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_186500;
        }
    }
    ctx->pc = 0x18652Cu;
    // 0x18652c: 0x3c020028  lui         $v0, 0x28
    ctx->pc = 0x18652cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)40 << 16));
    // 0x186530: 0x24506c80  addiu       $s0, $v0, 0x6C80
    ctx->pc = 0x186530u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 27776));
    // 0x186534: 0x0  nop
    ctx->pc = 0x186534u;
    // NOP
label_186538:
    // 0x186538: 0x27a70140  addiu       $a3, $sp, 0x140
    ctx->pc = 0x186538u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 320));
    // 0x18653c: 0x32020007  andi        $v0, $s0, 0x7
    ctx->pc = 0x18653cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)7);
    // 0x186540: 0xe0202d  daddu       $a0, $a3, $zero
    ctx->pc = 0x186540u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186544: 0x1040001a  beqz        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x186544u;
    {
        const bool branch_taken_0x186544 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x186548u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186544u;
            // 0x186548: 0x200182d  daddu       $v1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x186544) {
            ctx->pc = 0x1865B0u;
            goto label_1865b0;
        }
    }
    ctx->pc = 0x18654Cu;
    // 0x18654c: 0x26020200  addiu       $v0, $s0, 0x200
    ctx->pc = 0x18654cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 512));
label_186550:
    // 0x186550: 0x68680007  ldl         $t0, 0x7($v1)
    ctx->pc = 0x186550u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x186554: 0x6c680000  ldr         $t0, 0x0($v1)
    ctx->pc = 0x186554u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x186558: 0x6869000f  ldl         $t1, 0xF($v1)
    ctx->pc = 0x186558u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 9, (GPR_U64(ctx, 9) & keepMask) | (mem << shift)); }
    // 0x18655c: 0x6c690008  ldr         $t1, 0x8($v1)
    ctx->pc = 0x18655cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 9, (GPR_U64(ctx, 9) & keepMask) | (mem >> shift)); }
    // 0x186560: 0x68650017  ldl         $a1, 0x17($v1)
    ctx->pc = 0x186560u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x186564: 0x6c650010  ldr         $a1, 0x10($v1)
    ctx->pc = 0x186564u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x186568: 0x6866001f  ldl         $a2, 0x1F($v1)
    ctx->pc = 0x186568u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x18656c: 0x6c660018  ldr         $a2, 0x18($v1)
    ctx->pc = 0x18656cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x186570: 0xb0880007  sdl         $t0, 0x7($a0)
    ctx->pc = 0x186570u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x186574: 0xb4880000  sdr         $t0, 0x0($a0)
    ctx->pc = 0x186574u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x186578: 0xb089000f  sdl         $t1, 0xF($a0)
    ctx->pc = 0x186578u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 9); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x18657c: 0xb4890008  sdr         $t1, 0x8($a0)
    ctx->pc = 0x18657cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 9); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x186580: 0xb0850017  sdl         $a1, 0x17($a0)
    ctx->pc = 0x186580u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x186584: 0xb4850010  sdr         $a1, 0x10($a0)
    ctx->pc = 0x186584u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x186588: 0xb086001f  sdl         $a2, 0x1F($a0)
    ctx->pc = 0x186588u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x18658c: 0xb4860018  sdr         $a2, 0x18($a0)
    ctx->pc = 0x18658cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x186590: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x186590u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x186594: 0x0  nop
    ctx->pc = 0x186594u;
    // NOP
    // 0x186598: 0x0  nop
    ctx->pc = 0x186598u;
    // NOP
    // 0x18659c: 0x1462ffec  bne         $v1, $v0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x18659Cu;
    {
        const bool branch_taken_0x18659c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1865A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18659Cu;
            // 0x1865a0: 0x24840020  addiu       $a0, $a0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18659c) {
            ctx->pc = 0x186550u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_186550;
        }
    }
    ctx->pc = 0x1865A4u;
    // 0x1865a4: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1865A4u;
    {
        const bool branch_taken_0x1865a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1865A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1865A4u;
            // 0x1865a8: 0x97a30140  lhu         $v1, 0x140($sp) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 320)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1865a4) {
            ctx->pc = 0x1865ECu;
            goto label_1865ec;
        }
    }
    ctx->pc = 0x1865ACu;
    // 0x1865ac: 0x0  nop
    ctx->pc = 0x1865acu;
    // NOP
label_1865b0:
    // 0x1865b0: 0x26020200  addiu       $v0, $s0, 0x200
    ctx->pc = 0x1865b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 512));
label_1865b4:
    // 0x1865b4: 0xdc670000  ld          $a3, 0x0($v1)
    ctx->pc = 0x1865b4u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1865b8: 0xdc680008  ld          $t0, 0x8($v1)
    ctx->pc = 0x1865b8u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x1865bc: 0xdc690010  ld          $t1, 0x10($v1)
    ctx->pc = 0x1865bcu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x1865c0: 0xdc650018  ld          $a1, 0x18($v1)
    ctx->pc = 0x1865c0u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x1865c4: 0xfc870000  sd          $a3, 0x0($a0)
    ctx->pc = 0x1865c4u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 0), GPR_U64(ctx, 7));
    // 0x1865c8: 0xfc880008  sd          $t0, 0x8($a0)
    ctx->pc = 0x1865c8u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 8), GPR_U64(ctx, 8));
    // 0x1865cc: 0xfc890010  sd          $t1, 0x10($a0)
    ctx->pc = 0x1865ccu;
    WRITE64(ADD32(GPR_U32(ctx, 4), 16), GPR_U64(ctx, 9));
    // 0x1865d0: 0xfc850018  sd          $a1, 0x18($a0)
    ctx->pc = 0x1865d0u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 24), GPR_U64(ctx, 5));
    // 0x1865d4: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x1865d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x1865d8: 0x0  nop
    ctx->pc = 0x1865d8u;
    // NOP
    // 0x1865dc: 0x0  nop
    ctx->pc = 0x1865dcu;
    // NOP
    // 0x1865e0: 0x1462fff4  bne         $v1, $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x1865E0u;
    {
        const bool branch_taken_0x1865e0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1865E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1865E0u;
            // 0x1865e4: 0x24840020  addiu       $a0, $a0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1865e0) {
            ctx->pc = 0x1865B4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1865b4;
        }
    }
    ctx->pc = 0x1865E8u;
    // 0x1865e8: 0x97a30140  lhu         $v1, 0x140($sp)
    ctx->pc = 0x1865e8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 320)));
label_1865ec:
    // 0x1865ec: 0x30628000  andi        $v0, $v1, 0x8000
    ctx->pc = 0x1865ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)32768);
    // 0x1865f0: 0x10400035  beqz        $v0, . + 4 + (0x35 << 2)
    ctx->pc = 0x1865F0u;
    {
        const bool branch_taken_0x1865f0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1865F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1865F0u;
            // 0x1865f4: 0xa3a0019f  sb          $zero, 0x19F($sp) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 29), 415), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1865f0) {
            ctx->pc = 0x1866C8u;
            goto label_1866c8;
        }
    }
    ctx->pc = 0x1865F8u;
    // 0x1865f8: 0x30622000  andi        $v0, $v1, 0x2000
    ctx->pc = 0x1865f8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)8192);
    // 0x1865fc: 0x14400033  bnez        $v0, . + 4 + (0x33 << 2)
    ctx->pc = 0x1865FCu;
    {
        const bool branch_taken_0x1865fc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x186600u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1865FCu;
            // 0x186600: 0x8fa20344  lw          $v0, 0x344($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 836)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1865fc) {
            ctx->pc = 0x1866CCu;
            goto label_1866cc;
        }
    }
    ctx->pc = 0x186604u;
    // 0x186604: 0x27a60100  addiu       $a2, $sp, 0x100
    ctx->pc = 0x186604u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 256));
    // 0x186608: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x186608u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18660c: 0xc0608e6  jal         func_182398
    ctx->pc = 0x18660Cu;
    SET_GPR_U32(ctx, 31, 0x186614u);
    ctx->pc = 0x186610u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18660Cu;
            // 0x186610: 0xc0282d  daddu       $a1, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182398u;
    if (runtime->hasFunction(0x182398u)) {
        auto targetFn = runtime->lookupFunction(0x182398u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186614u; }
        if (ctx->pc != 0x186614u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182398_0x182398(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186614u; }
        if (ctx->pc != 0x186614u) { return; }
    }
    ctx->pc = 0x186614u;
label_186614:
    // 0x186614: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x186614u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x186618: 0x5447002c  bnel        $v0, $a3, . + 4 + (0x2C << 2)
    ctx->pc = 0x186618u;
    {
        const bool branch_taken_0x186618 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 7));
        if (branch_taken_0x186618) {
            ctx->pc = 0x18661Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x186618u;
            // 0x18661c: 0x8fa20344  lw          $v0, 0x344($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 836)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1866CCu;
            goto label_1866cc;
        }
    }
    ctx->pc = 0x186620u;
    // 0x186620: 0x56c00029  bnel        $s6, $zero, . + 4 + (0x29 << 2)
    ctx->pc = 0x186620u;
    {
        const bool branch_taken_0x186620 = (GPR_U64(ctx, 22) != GPR_U64(ctx, 0));
        if (branch_taken_0x186620) {
            ctx->pc = 0x186624u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x186620u;
            // 0x186624: 0x26d6ffff  addiu       $s6, $s6, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1866C8u;
            goto label_1866c8;
        }
    }
    ctx->pc = 0x186628u;
    // 0x186628: 0x1220001e  beqz        $s1, . + 4 + (0x1E << 2)
    ctx->pc = 0x186628u;
    {
        const bool branch_taken_0x186628 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        if (branch_taken_0x186628) {
            ctx->pc = 0x1866A4u;
            goto label_1866a4;
        }
    }
    ctx->pc = 0x186630u;
    // 0x186630: 0x5bc00025  blezl       $fp, . + 4 + (0x25 << 2)
    ctx->pc = 0x186630u;
    {
        const bool branch_taken_0x186630 = (GPR_S64(ctx, 30) <= 0);
        if (branch_taken_0x186630) {
            ctx->pc = 0x186634u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x186630u;
            // 0x186634: 0x26f70001  addiu       $s7, $s7, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 23), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1866C8u;
            goto label_1866c8;
        }
    }
    ctx->pc = 0x186638u;
    // 0x186638: 0x97a20140  lhu         $v0, 0x140($sp)
    ctx->pc = 0x186638u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 320)));
    // 0x18663c: 0x2a0282d  daddu       $a1, $s5, $zero
    ctx->pc = 0x18663cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186640: 0x6ba8014f  ldl         $t0, 0x14F($sp)
    ctx->pc = 0x186640u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 335); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x186644: 0x6fa80148  ldr         $t0, 0x148($sp)
    ctx->pc = 0x186644u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 328); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x186648: 0xb2280007  sdl         $t0, 0x7($s1)
    ctx->pc = 0x186648u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x18664c: 0xb6280000  sdr         $t0, 0x0($s1)
    ctx->pc = 0x18664cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x186650: 0x26240018  addiu       $a0, $s1, 0x18
    ctx->pc = 0x186650u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 24));
    // 0x186654: 0x8fa30144  lw          $v1, 0x144($sp)
    ctx->pc = 0x186654u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 324)));
    // 0x186658: 0x6ba8015f  ldl         $t0, 0x15F($sp)
    ctx->pc = 0x186658u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 351); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x18665c: 0x6fa80158  ldr         $t0, 0x158($sp)
    ctx->pc = 0x18665cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 344); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x186660: 0xb228000f  sdl         $t0, 0xF($s1)
    ctx->pc = 0x186660u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x186664: 0xb6280008  sdr         $t0, 0x8($s1)
    ctx->pc = 0x186664u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x186668: 0xae230010  sw          $v1, 0x10($s1)
    ctx->pc = 0x186668u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 3));
    // 0x18666c: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x18666Cu;
    SET_GPR_U32(ctx, 31, 0x186674u);
    ctx->pc = 0x186670u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18666Cu;
            // 0x186670: 0xa6220014  sh          $v0, 0x14($s1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 17), 20), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186674u; }
        if (ctx->pc != 0x186674u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186674u; }
        if (ctx->pc != 0x186674u) { return; }
    }
    ctx->pc = 0x186674u;
label_186674:
    // 0x186674: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x186674u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186678: 0x3c080024  lui         $t0, 0x24
    ctx->pc = 0x186678u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)36 << 16));
    // 0x18667c: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x18667Cu;
    SET_GPR_U32(ctx, 31, 0x186684u);
    ctx->pc = 0x186680u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18667Cu;
            // 0x186680: 0x250517b0  addiu       $a1, $t0, 0x17B0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 8), 6064));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186684u; }
        if (ctx->pc != 0x186684u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186684u; }
        if (ctx->pc != 0x186684u) { return; }
    }
    ctx->pc = 0x186684u;
label_186684:
    // 0x186684: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x186684u;
    {
        const bool branch_taken_0x186684 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x186688u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186684u;
            // 0x186688: 0x3c090024  lui         $t1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x186684) {
            ctx->pc = 0x186694u;
            goto label_186694;
        }
    }
    ctx->pc = 0x18668Cu;
    // 0x18668c: 0x97a20340  lhu         $v0, 0x340($sp)
    ctx->pc = 0x18668cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 832)));
    // 0x186690: 0xa6220014  sh          $v0, 0x14($s1)
    ctx->pc = 0x186690u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 20), (uint16_t)GPR_U32(ctx, 2));
label_186694:
    // 0x186694: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x186694u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186698: 0x252517b8  addiu       $a1, $t1, 0x17B8
    ctx->pc = 0x186698u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 9), 6072));
    // 0x18669c: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x18669Cu;
    SET_GPR_U32(ctx, 31, 0x1866A4u);
    ctx->pc = 0x1866A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18669Cu;
            // 0x1866a0: 0x26310038  addiu       $s1, $s1, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 56));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1866A4u; }
        if (ctx->pc != 0x1866A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1866A4u; }
        if (ctx->pc != 0x1866A4u) { return; }
    }
    ctx->pc = 0x1866A4u;
label_1866a4:
    // 0x1866a4: 0x1bc00008  blez        $fp, . + 4 + (0x8 << 2)
    ctx->pc = 0x1866A4u;
    {
        const bool branch_taken_0x1866a4 = (GPR_S64(ctx, 30) <= 0);
        ctx->pc = 0x1866A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1866A4u;
            // 0x1866a8: 0x26f70001  addiu       $s7, $s7, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 23), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1866a4) {
            ctx->pc = 0x1866C8u;
            goto label_1866c8;
        }
    }
    ctx->pc = 0x1866ACu;
    // 0x1866ac: 0x2fe102a  slt         $v0, $s7, $fp
    ctx->pc = 0x1866acu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 23) < (int64_t)GPR_S64(ctx, 30)) ? 1 : 0);
    // 0x1866b0: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1866B0u;
    {
        const bool branch_taken_0x1866b0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1866B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1866B0u;
            // 0x1866b4: 0x8fa20344  lw          $v0, 0x344($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 836)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1866b0) {
            ctx->pc = 0x1866CCu;
            goto label_1866cc;
        }
    }
    ctx->pc = 0x1866B8u;
    // 0x1866b8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1866b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1866bc: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1866BCu;
    {
        const bool branch_taken_0x1866bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1866C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1866BCu;
            // 0x1866c0: 0xafa20548  sw          $v0, 0x548($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 1352), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1866bc) {
            ctx->pc = 0x1866E8u;
            goto label_1866e8;
        }
    }
    ctx->pc = 0x1866C4u;
    // 0x1866c4: 0x0  nop
    ctx->pc = 0x1866c4u;
    // NOP
label_1866c8:
    // 0x1866c8: 0x8fa20344  lw          $v0, 0x344($sp)
    ctx->pc = 0x1866c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 836)));
label_1866cc:
    // 0x1866cc: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1866ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1866d0: 0x10400015  beqz        $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x1866D0u;
    {
        const bool branch_taken_0x1866d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1866D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1866D0u;
            // 0x1866d4: 0xafa20344  sw          $v0, 0x344($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 836), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1866d0) {
            ctx->pc = 0x186728u;
            goto label_186728;
        }
    }
    ctx->pc = 0x1866D8u;
    // 0x1866d8: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x1866d8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x1866dc: 0x2a620002  slti        $v0, $s3, 0x2
    ctx->pc = 0x1866dcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1866e0: 0x1440ff95  bnez        $v0, . + 4 + (-0x6B << 2)
    ctx->pc = 0x1866E0u;
    {
        const bool branch_taken_0x1866e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1866E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1866E0u;
            // 0x1866e4: 0x26100200  addiu       $s0, $s0, 0x200 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 512));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1866e0) {
            ctx->pc = 0x186538u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_186538;
        }
    }
    ctx->pc = 0x1866E8u;
label_1866e8:
    // 0x1866e8: 0x8fa30548  lw          $v1, 0x548($sp)
    ctx->pc = 0x1866e8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 1352)));
    // 0x1866ec: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1866ecu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1866f0: 0x10650019  beq         $v1, $a1, . + 4 + (0x19 << 2)
    ctx->pc = 0x1866F0u;
    {
        const bool branch_taken_0x1866f0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        ctx->pc = 0x1866F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1866F0u;
            // 0x1866f4: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1866f0) {
            ctx->pc = 0x186758u;
            goto label_186758;
        }
    }
    ctx->pc = 0x1866F8u;
    // 0x1866f8: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1866f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1866fc: 0xc060b12  jal         func_182C48
    ctx->pc = 0x1866FCu;
    SET_GPR_U32(ctx, 31, 0x186704u);
    ctx->pc = 0x186700u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1866FCu;
            // 0x186700: 0x27a60540  addiu       $a2, $sp, 0x540 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 1344));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182C48u;
    if (runtime->hasFunction(0x182C48u)) {
        auto targetFn = runtime->lookupFunction(0x182C48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186704u; }
        if (ctx->pc != 0x186704u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182C48_0x182c48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186704u; }
        if (ctx->pc != 0x186704u) { return; }
    }
    ctx->pc = 0x186704u;
label_186704:
    // 0x186704: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x186704u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186708: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x186708u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x18670c: 0x8fa30540  lw          $v1, 0x540($sp)
    ctx->pc = 0x18670cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 1344)));
    // 0x186710: 0x34420059  ori         $v0, $v0, 0x59
    ctx->pc = 0x186710u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)89);
    // 0x186714: 0x14620008  bne         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x186714u;
    {
        const bool branch_taken_0x186714 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x186714) {
            ctx->pc = 0x186738u;
            goto label_186738;
        }
    }
    ctx->pc = 0x18671Cu;
label_18671c:
    // 0x18671c: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x18671cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x186720: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x186720u;
    {
        const bool branch_taken_0x186720 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x186724u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186720u;
            // 0x186724: 0x34429002  ori         $v0, $v0, 0x9002 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)36866);
        ctx->in_delay_slot = false;
        if (branch_taken_0x186720) {
            ctx->pc = 0x186768u;
            goto label_186768;
        }
    }
    ctx->pc = 0x186728u;
label_186728:
    // 0x186728: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x186728u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18672c: 0x1000ffee  b           . + 4 + (-0x12 << 2)
    ctx->pc = 0x18672Cu;
    {
        const bool branch_taken_0x18672c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x186730u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18672Cu;
            // 0x186730: 0xafa60548  sw          $a2, 0x548($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 1352), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18672c) {
            ctx->pc = 0x1866E8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1866e8;
        }
    }
    ctx->pc = 0x186734u;
    // 0x186734: 0x0  nop
    ctx->pc = 0x186734u;
    // NOP
label_186738:
    // 0x186738: 0x1460000b  bnez        $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x186738u;
    {
        const bool branch_taken_0x186738 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x18673Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186738u;
            // 0x18673c: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x186738) {
            ctx->pc = 0x186768u;
            goto label_186768;
        }
    }
    ctx->pc = 0x186740u;
    // 0x186740: 0x8fa70548  lw          $a3, 0x548($sp)
    ctx->pc = 0x186740u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 1352)));
    // 0x186744: 0x14e00005  bnez        $a3, . + 4 + (0x5 << 2)
    ctx->pc = 0x186744u;
    {
        const bool branch_taken_0x186744 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        ctx->pc = 0x186748u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186744u;
            // 0x186748: 0x8fa80544  lw          $t0, 0x544($sp) (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 1348)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x186744) {
            ctx->pc = 0x18675Cu;
            goto label_18675c;
        }
    }
    ctx->pc = 0x18674Cu;
label_18674c:
    // 0x18674c: 0x8fa20344  lw          $v0, 0x344($sp)
    ctx->pc = 0x18674cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 836)));
    // 0x186750: 0x1440ff6f  bnez        $v0, . + 4 + (-0x91 << 2)
    ctx->pc = 0x186750u;
    {
        const bool branch_taken_0x186750 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x186754u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186750u;
            // 0x186754: 0x3c060028  lui         $a2, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)40 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x186750) {
            ctx->pc = 0x186510u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_186510;
        }
    }
    ctx->pc = 0x186758u;
label_186758:
    // 0x186758: 0x8fa80544  lw          $t0, 0x544($sp)
    ctx->pc = 0x186758u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 1348)));
label_18675c:
    // 0x18675c: 0x55000001  bnel        $t0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x18675Cu;
    {
        const bool branch_taken_0x18675c = (GPR_U64(ctx, 8) != GPR_U64(ctx, 0));
        if (branch_taken_0x18675c) {
            ctx->pc = 0x186760u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x18675Cu;
            // 0x186760: 0xad170000  sw          $s7, 0x0($t0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 8), 0), GPR_U32(ctx, 23));
        ctx->in_delay_slot = false;
            ctx->pc = 0x186764u;
            goto label_186764;
        }
    }
    ctx->pc = 0x186764u;
label_186764:
    // 0x186764: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x186764u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_186768:
    // 0x186768: 0xdfb00550  ld          $s0, 0x550($sp)
    ctx->pc = 0x186768u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 1360)));
label_18676c:
    // 0x18676c: 0xdfb10558  ld          $s1, 0x558($sp)
    ctx->pc = 0x18676cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 1368)));
    // 0x186770: 0xdfb20560  ld          $s2, 0x560($sp)
    ctx->pc = 0x186770u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 1376)));
    // 0x186774: 0xdfb30568  ld          $s3, 0x568($sp)
    ctx->pc = 0x186774u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 1384)));
    // 0x186778: 0xdfb40570  ld          $s4, 0x570($sp)
    ctx->pc = 0x186778u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 1392)));
    // 0x18677c: 0xdfb50578  ld          $s5, 0x578($sp)
    ctx->pc = 0x18677cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 1400)));
    // 0x186780: 0xdfb60580  ld          $s6, 0x580($sp)
    ctx->pc = 0x186780u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 1408)));
    // 0x186784: 0xdfb70588  ld          $s7, 0x588($sp)
    ctx->pc = 0x186784u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 1416)));
    // 0x186788: 0xdfbe0590  ld          $fp, 0x590($sp)
    ctx->pc = 0x186788u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 1424)));
    // 0x18678c: 0xdfbf0598  ld          $ra, 0x598($sp)
    ctx->pc = 0x18678cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 1432)));
    // 0x186790: 0x3e00008  jr          $ra
    ctx->pc = 0x186790u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x186794u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186790u;
            // 0x186794: 0x27bd05a0  addiu       $sp, $sp, 0x5A0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 1440));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18627Cu: goto label_18627c;
            case 0x186290u: goto label_186290;
            case 0x1862BCu: goto label_1862bc;
            case 0x1862D4u: goto label_1862d4;
            case 0x1862DCu: goto label_1862dc;
            case 0x1862E8u: goto label_1862e8;
            case 0x1862F4u: goto label_1862f4;
            case 0x186300u: goto label_186300;
            case 0x18630Cu: goto label_18630c;
            case 0x186320u: goto label_186320;
            case 0x186328u: goto label_186328;
            case 0x18634Cu: goto label_18634c;
            case 0x186368u: goto label_186368;
            case 0x186380u: goto label_186380;
            case 0x186390u: goto label_186390;
            case 0x1863BCu: goto label_1863bc;
            case 0x1863F0u: goto label_1863f0;
            case 0x18640Cu: goto label_18640c;
            case 0x186418u: goto label_186418;
            case 0x186440u: goto label_186440;
            case 0x186464u: goto label_186464;
            case 0x186498u: goto label_186498;
            case 0x1864C0u: goto label_1864c0;
            case 0x1864D0u: goto label_1864d0;
            case 0x186500u: goto label_186500;
            case 0x186510u: goto label_186510;
            case 0x186524u: goto label_186524;
            case 0x186538u: goto label_186538;
            case 0x186550u: goto label_186550;
            case 0x1865B0u: goto label_1865b0;
            case 0x1865B4u: goto label_1865b4;
            case 0x1865ECu: goto label_1865ec;
            case 0x186614u: goto label_186614;
            case 0x186674u: goto label_186674;
            case 0x186684u: goto label_186684;
            case 0x186694u: goto label_186694;
            case 0x1866A4u: goto label_1866a4;
            case 0x1866C8u: goto label_1866c8;
            case 0x1866CCu: goto label_1866cc;
            case 0x1866E8u: goto label_1866e8;
            case 0x186704u: goto label_186704;
            case 0x18671Cu: goto label_18671c;
            case 0x186728u: goto label_186728;
            case 0x186738u: goto label_186738;
            case 0x18674Cu: goto label_18674c;
            case 0x186758u: goto label_186758;
            case 0x18675Cu: goto label_18675c;
            case 0x186764u: goto label_186764;
            case 0x186768u: goto label_186768;
            case 0x18676Cu: goto label_18676c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x186798u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
