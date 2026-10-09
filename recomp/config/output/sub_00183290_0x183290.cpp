#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00183290
// Address: 0x183290 - 0x183670
void sub_00183290_0x183290(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00183290_0x183290");
#endif

    switch (ctx->pc) {
        case 0x1832e4u: goto label_1832e4;
        case 0x183314u: goto label_183314;
        case 0x183374u: goto label_183374;
        case 0x1833e4u: goto label_1833e4;
        case 0x183414u: goto label_183414;
        case 0x183464u: goto label_183464;
        case 0x18346cu: goto label_18346c;
        case 0x1834b8u: goto label_1834b8;
        case 0x1834dcu: goto label_1834dc;
        case 0x18350cu: goto label_18350c;
        case 0x18353cu: goto label_18353c;
        case 0x183554u: goto label_183554;
        case 0x183580u: goto label_183580;
        case 0x1835b8u: goto label_1835b8;
        case 0x1835f0u: goto label_1835f0;
        default: break;
    }

    ctx->pc = 0x183290u;

    // 0x183290: 0x27bdfd90  addiu       $sp, $sp, -0x270
    ctx->pc = 0x183290u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966672));
    // 0x183294: 0xffb20230  sd          $s2, 0x230($sp)
    ctx->pc = 0x183294u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 560), GPR_U64(ctx, 18));
    // 0x183298: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x183298u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18329c: 0x121040  sll         $v0, $s2, 1
    ctx->pc = 0x18329cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x1832a0: 0xffb10228  sd          $s1, 0x228($sp)
    ctx->pc = 0x1832a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 552), GPR_U64(ctx, 17));
    // 0x1832a4: 0x521021  addu        $v0, $v0, $s2
    ctx->pc = 0x1832a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x1832a8: 0xffb50248  sd          $s5, 0x248($sp)
    ctx->pc = 0x1832a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 584), GPR_U64(ctx, 21));
    // 0x1832ac: 0x21140  sll         $v0, $v0, 5
    ctx->pc = 0x1832acu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1832b0: 0xffb00220  sd          $s0, 0x220($sp)
    ctx->pc = 0x1832b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 544), GPR_U64(ctx, 16));
    // 0x1832b4: 0x521021  addu        $v0, $v0, $s2
    ctx->pc = 0x1832b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x1832b8: 0xffb30238  sd          $s3, 0x238($sp)
    ctx->pc = 0x1832b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 568), GPR_U64(ctx, 19));
    // 0x1832bc: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1832bcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1832c0: 0xffb40240  sd          $s4, 0x240($sp)
    ctx->pc = 0x1832c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 576), GPR_U64(ctx, 20));
    // 0x1832c4: 0xffb60250  sd          $s6, 0x250($sp)
    ctx->pc = 0x1832c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 592), GPR_U64(ctx, 22));
    // 0x1832c8: 0xffb70258  sd          $s7, 0x258($sp)
    ctx->pc = 0x1832c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 600), GPR_U64(ctx, 23));
    // 0x1832cc: 0x3c110023  lui         $s1, 0x23
    ctx->pc = 0x1832ccu;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)35 << 16));
    // 0x1832d0: 0x2631fa18  addiu       $s1, $s1, -0x5E8
    ctx->pc = 0x1832d0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294965784));
    // 0x1832d4: 0x2228821  addu        $s1, $s1, $v0
    ctx->pc = 0x1832d4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x1832d8: 0xffbf0260  sd          $ra, 0x260($sp)
    ctx->pc = 0x1832d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 608), GPR_U64(ctx, 31));
    // 0x1832dc: 0xc062210  jal         func_188840
    ctx->pc = 0x1832DCu;
    SET_GPR_U32(ctx, 31, 0x1832E4u);
    ctx->pc = 0x1832E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1832DCu;
            // 0x1832e0: 0xa0a82d  daddu       $s5, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x188840u;
    if (runtime->hasFunction(0x188840u)) {
        auto targetFn = runtime->lookupFunction(0x188840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1832E4u; }
        if (ctx->pc != 0x1832E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00188840_0x188840(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1832E4u; }
        if (ctx->pc != 0x1832E4u) { return; }
    }
    ctx->pc = 0x1832E4u;
label_1832e4:
    // 0x1832e4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1832E4u;
    {
        const bool branch_taken_0x1832e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1832e4) {
            ctx->pc = 0x1832F8u;
            goto label_1832f8;
        }
    }
    ctx->pc = 0x1832ECu;
    // 0x1832ec: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1832ecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x1832f0: 0x100000d3  b           . + 4 + (0xD3 << 2)
    ctx->pc = 0x1832F0u;
    {
        const bool branch_taken_0x1832f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1832F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1832F0u;
            // 0x1832f4: 0x34420013  ori         $v0, $v0, 0x13 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)19);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1832f0) {
            ctx->pc = 0x183640u;
            goto label_183640;
        }
    }
    ctx->pc = 0x1832F8u;
label_1832f8:
    // 0x1832f8: 0x12a00004  beqz        $s5, . + 4 + (0x4 << 2)
    ctx->pc = 0x1832F8u;
    {
        const bool branch_taken_0x1832f8 = (GPR_U64(ctx, 21) == GPR_U64(ctx, 0));
        if (branch_taken_0x1832f8) {
            ctx->pc = 0x18330Cu;
            goto label_18330c;
        }
    }
    ctx->pc = 0x183300u;
    // 0x183300: 0xaea00004  sw          $zero, 0x4($s5)
    ctx->pc = 0x183300u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 4), GPR_U32(ctx, 0));
    // 0x183304: 0xaea00000  sw          $zero, 0x0($s5)
    ctx->pc = 0x183304u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 0));
    // 0x183308: 0xaea00008  sw          $zero, 0x8($s5)
    ctx->pc = 0x183308u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 8), GPR_U32(ctx, 0));
label_18330c:
    // 0x18330c: 0xc061f4e  jal         func_187D38
    ctx->pc = 0x18330Cu;
    SET_GPR_U32(ctx, 31, 0x183314u);
    ctx->pc = 0x183310u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18330Cu;
            // 0x183310: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x187D38u;
    if (runtime->hasFunction(0x187D38u)) {
        auto targetFn = runtime->lookupFunction(0x187D38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183314u; }
        if (ctx->pc != 0x183314u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187D38_0x187d38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183314u; }
        if (ctx->pc != 0x183314u) { return; }
    }
    ctx->pc = 0x183314u;
label_183314:
    // 0x183314: 0xafa20210  sw          $v0, 0x210($sp)
    ctx->pc = 0x183314u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 528), GPR_U32(ctx, 2));
    // 0x183318: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x183318u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18331c: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x18331cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x183320: 0x106000c7  beqz        $v1, . + 4 + (0xC7 << 2)
    ctx->pc = 0x183320u;
    {
        const bool branch_taken_0x183320 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x183324u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x183320u;
            // 0x183324: 0x3442006f  ori         $v0, $v0, 0x6F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)111);
        ctx->in_delay_slot = false;
        if (branch_taken_0x183320) {
            ctx->pc = 0x183640u;
            goto label_183640;
        }
    }
    ctx->pc = 0x183328u;
    // 0x183328: 0x24140002  addiu       $s4, $zero, 0x2
    ctx->pc = 0x183328u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x18332c: 0x14740007  bne         $v1, $s4, . + 4 + (0x7 << 2)
    ctx->pc = 0x18332Cu;
    {
        const bool branch_taken_0x18332c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 20));
        ctx->pc = 0x183330u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18332Cu;
            // 0x183330: 0x3c170028  lui         $s7, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)40 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18332c) {
            ctx->pc = 0x18334Cu;
            goto label_18334c;
        }
    }
    ctx->pc = 0x183334u;
    // 0x183334: 0x24020898  addiu       $v0, $zero, 0x898
    ctx->pc = 0x183334u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2200));
    // 0x183338: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x183338u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18333c: 0x2421018  mult        $v0, $s2, $v0
    ctx->pc = 0x18333cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x183340: 0x3c010028  lui         $at, 0x28
    ctx->pc = 0x183340u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)40 << 16));
    // 0x183344: 0x220821  addu        $at, $at, $v0
    ctx->pc = 0x183344u;
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x183348: 0xac2363d0  sw          $v1, 0x63D0($at)
    ctx->pc = 0x183348u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 25552), GPR_U32(ctx, 3));
label_18334c:
    // 0x18334c: 0x24030898  addiu       $v1, $zero, 0x898
    ctx->pc = 0x18334cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2200));
    // 0x183350: 0x26f35b48  addiu       $s3, $s7, 0x5B48
    ctx->pc = 0x183350u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 23), 23368));
    // 0x183354: 0x2438018  mult        $s0, $s2, $v1
    ctx->pc = 0x183354u;
    { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 16, (int32_t)result); }
    // 0x183358: 0x2131021  addu        $v0, $s0, $s3
    ctx->pc = 0x183358u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 19)));
    // 0x18335c: 0x8c430888  lw          $v1, 0x888($v0)
    ctx->pc = 0x18335cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 2184)));
    // 0x183360: 0x10600093  beqz        $v1, . + 4 + (0x93 << 2)
    ctx->pc = 0x183360u;
    {
        const bool branch_taken_0x183360 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x183360) {
            ctx->pc = 0x1835B0u;
            goto label_1835b0;
        }
    }
    ctx->pc = 0x183368u;
    // 0x183368: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x183368u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18336c: 0xc061af8  jal         func_186BE0
    ctx->pc = 0x18336Cu;
    SET_GPR_U32(ctx, 31, 0x183374u);
    ctx->pc = 0x183370u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18336Cu;
            // 0x183370: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x186BE0u;
    if (runtime->hasFunction(0x186BE0u)) {
        auto targetFn = runtime->lookupFunction(0x186BE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183374u; }
        if (ctx->pc != 0x183374u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00186BE0_0x186be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183374u; }
        if (ctx->pc != 0x183374u) { return; }
    }
    ctx->pc = 0x183374u;
label_183374:
    // 0x183374: 0x1040001d  beqz        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x183374u;
    {
        const bool branch_taken_0x183374 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x183378u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x183374u;
            // 0x183378: 0xafa20210  sw          $v0, 0x210($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 528), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x183374) {
            ctx->pc = 0x1833ECu;
            goto label_1833ec;
        }
    }
    ctx->pc = 0x18337Cu;
    // 0x18337c: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x18337cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x183380: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x183380u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x183384: 0x106000ae  beqz        $v1, . + 4 + (0xAE << 2)
    ctx->pc = 0x183384u;
    {
        const bool branch_taken_0x183384 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x183388u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x183384u;
            // 0x183388: 0x3442006f  ori         $v0, $v0, 0x6F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)111);
        ctx->in_delay_slot = false;
        if (branch_taken_0x183384) {
            ctx->pc = 0x183640u;
            goto label_183640;
        }
    }
    ctx->pc = 0x18338Cu;
    // 0x18338c: 0x26640004  addiu       $a0, $s3, 0x4
    ctx->pc = 0x18338cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 4));
    // 0x183390: 0x26030890  addiu       $v1, $s0, 0x890
    ctx->pc = 0x183390u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 2192));
    // 0x183394: 0x26020800  addiu       $v0, $s0, 0x800
    ctx->pc = 0x183394u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 2048));
    // 0x183398: 0x26660808  addiu       $a2, $s3, 0x808
    ctx->pc = 0x183398u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 19), 2056));
    // 0x18339c: 0x444821  addu        $t1, $v0, $a0
    ctx->pc = 0x18339cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1833a0: 0x531021  addu        $v0, $v0, $s3
    ctx->pc = 0x1833a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x1833a4: 0x734021  addu        $t0, $v1, $s3
    ctx->pc = 0x1833a4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 19)));
    // 0x1833a8: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1833a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1833ac: 0x2405ffff  addiu       $a1, $zero, -0x1
    ctx->pc = 0x1833acu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1833b0: 0x2063021  addu        $a2, $s0, $a2
    ctx->pc = 0x1833b0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 6)));
    // 0x1833b4: 0x3c070024  lui         $a3, 0x24
    ctx->pc = 0x1833b4u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)36 << 16));
    // 0x1833b8: 0xac600000  sw          $zero, 0x0($v1)
    ctx->pc = 0x1833b8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
    // 0x1833bc: 0xac450000  sw          $a1, 0x0($v0)
    ctx->pc = 0x1833bcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 5));
    // 0x1833c0: 0xad250000  sw          $a1, 0x0($t1)
    ctx->pc = 0x1833c0u;
    WRITE32(ADD32(GPR_U32(ctx, 9), 0), GPR_U32(ctx, 5));
    // 0x1833c4: 0xad000000  sw          $zero, 0x0($t0)
    ctx->pc = 0x1833c4u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 0), GPR_U32(ctx, 0));
    // 0x1833c8: 0x24e817c8  addiu       $t0, $a3, 0x17C8
    ctx->pc = 0x1833c8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), 6088));
    // 0x1833cc: 0x81020000  lb          $v0, 0x0($t0)
    ctx->pc = 0x1833ccu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1833d0: 0x81030001  lb          $v1, 0x1($t0)
    ctx->pc = 0x1833d0u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 1)));
    // 0x1833d4: 0xa0c20000  sb          $v0, 0x0($a2)
    ctx->pc = 0x1833d4u;
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1833d8: 0xa0c30001  sb          $v1, 0x1($a2)
    ctx->pc = 0x1833d8u;
    WRITE8(ADD32(GPR_U32(ctx, 6), 1), (uint8_t)GPR_U32(ctx, 3));
    // 0x1833dc: 0xc061b04  jal         func_186C10
    ctx->pc = 0x1833DCu;
    SET_GPR_U32(ctx, 31, 0x1833E4u);
    ctx->pc = 0x1833E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1833DCu;
            // 0x1833e0: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x186C10u;
    if (runtime->hasFunction(0x186C10u)) {
        auto targetFn = runtime->lookupFunction(0x186C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1833E4u; }
        if (ctx->pc != 0x1833E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00186C10_0x186c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1833E4u; }
        if (ctx->pc != 0x1833E4u) { return; }
    }
    ctx->pc = 0x1833E4u;
label_1833e4:
    // 0x1833e4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1833E4u;
    {
        const bool branch_taken_0x1833e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1833E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1833E4u;
            // 0x1833e8: 0xafa20210  sw          $v0, 0x210($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 528), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1833e4) {
            ctx->pc = 0x1833F8u;
            goto label_1833f8;
        }
    }
    ctx->pc = 0x1833ECu;
label_1833ec:
    // 0x1833ec: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1833ecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x1833f0: 0x10000093  b           . + 4 + (0x93 << 2)
    ctx->pc = 0x1833F0u;
    {
        const bool branch_taken_0x1833f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1833F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1833F0u;
            // 0x1833f4: 0x3442006f  ori         $v0, $v0, 0x6F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)111);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1833f0) {
            ctx->pc = 0x183640u;
            goto label_183640;
        }
    }
    ctx->pc = 0x1833F8u;
label_1833f8:
    // 0x1833f8: 0x56a00001  bnel        $s5, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x1833F8u;
    {
        const bool branch_taken_0x1833f8 = (GPR_U64(ctx, 21) != GPR_U64(ctx, 0));
        if (branch_taken_0x1833f8) {
            ctx->pc = 0x1833FCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1833F8u;
            // 0x1833fc: 0xaeb40000  sw          $s4, 0x0($s5) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 20));
        ctx->in_delay_slot = false;
            ctx->pc = 0x183400u;
            goto label_183400;
        }
    }
    ctx->pc = 0x183400u;
label_183400:
    // 0x183400: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x183400u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x183404: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x183404u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x183408: 0x24a517d0  addiu       $a1, $a1, 0x17D0
    ctx->pc = 0x183408u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 6096));
    // 0x18340c: 0xc042d10  jal         func_10B440
    ctx->pc = 0x18340Cu;
    SET_GPR_U32(ctx, 31, 0x183414u);
    ctx->pc = 0x183410u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18340Cu;
            // 0x183410: 0x2406001b  addiu       $a2, $zero, 0x1B (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 27));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B440u;
    if (runtime->hasFunction(0x10B440u)) {
        auto targetFn = runtime->lookupFunction(0x10B440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183414u; }
        if (ctx->pc != 0x183414u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B440_0x10b440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183414u; }
        if (ctx->pc != 0x183414u) { return; }
    }
    ctx->pc = 0x183414u;
label_183414:
    // 0x183414: 0x50400006  beql        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x183414u;
    {
        const bool branch_taken_0x183414 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x183414) {
            ctx->pc = 0x183418u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x183414u;
            // 0x183418: 0x8224001c  lb          $a0, 0x1C($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 28)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x183430u;
            goto label_183430;
        }
    }
    ctx->pc = 0x18341Cu;
    // 0x18341c: 0x56a0005a  bnel        $s5, $zero, . + 4 + (0x5A << 2)
    ctx->pc = 0x18341Cu;
    {
        const bool branch_taken_0x18341c = (GPR_U64(ctx, 21) != GPR_U64(ctx, 0));
        if (branch_taken_0x18341c) {
            ctx->pc = 0x183420u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x18341Cu;
            // 0x183420: 0xaea00004  sw          $zero, 0x4($s5) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 21), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x183588u;
            goto label_183588;
        }
    }
    ctx->pc = 0x183424u;
    // 0x183424: 0x10000058  b           . + 4 + (0x58 << 2)
    ctx->pc = 0x183424u;
    {
        const bool branch_taken_0x183424 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x183424) {
            ctx->pc = 0x183588u;
            goto label_183588;
        }
    }
    ctx->pc = 0x18342Cu;
    // 0x18342c: 0x0  nop
    ctx->pc = 0x18342cu;
    // NOP
label_183430:
    // 0x183430: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x183430u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x183434: 0x8225001e  lb          $a1, 0x1E($s1)
    ctx->pc = 0x183434u;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 30)));
    // 0x183438: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x183438u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x18343c: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x18343cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x183440: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x183440u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x183444: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x183444u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x183448: 0x2464fdf0  addiu       $a0, $v1, -0x210
    ctx->pc = 0x183448u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 4294966768));
    // 0x18344c: 0x2884000b  slti        $a0, $a0, 0xB
    ctx->pc = 0x18344cu;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)11) ? 1 : 0);
    // 0x183450: 0x1480007b  bnez        $a0, . + 4 + (0x7B << 2)
    ctx->pc = 0x183450u;
    {
        const bool branch_taken_0x183450 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x183454u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x183450u;
            // 0x183454: 0x34420086  ori         $v0, $v0, 0x86 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)134);
        ctx->in_delay_slot = false;
        if (branch_taken_0x183450) {
            ctx->pc = 0x183640u;
            goto label_183640;
        }
    }
    ctx->pc = 0x183458u;
    // 0x183458: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x183458u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18345c: 0xc060c8e  jal         func_183238
    ctx->pc = 0x18345Cu;
    SET_GPR_U32(ctx, 31, 0x183464u);
    ctx->pc = 0x183460u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18345Cu;
            // 0x183460: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x183238u;
    if (runtime->hasFunction(0x183238u)) {
        auto targetFn = runtime->lookupFunction(0x183238u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183464u; }
        if (ctx->pc != 0x183464u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00183238_0x183238(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183464u; }
        if (ctx->pc != 0x183464u) { return; }
    }
    ctx->pc = 0x183464u;
label_183464:
    // 0x183464: 0xc061f94  jal         func_187E50
    ctx->pc = 0x183464u;
    SET_GPR_U32(ctx, 31, 0x18346Cu);
    ctx->pc = 0x183468u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x183464u;
            // 0x183468: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x187E50u;
    if (runtime->hasFunction(0x187E50u)) {
        auto targetFn = runtime->lookupFunction(0x187E50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18346Cu; }
        if (ctx->pc != 0x18346Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187E50_0x187e50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18346Cu; }
        if (ctx->pc != 0x18346Cu) { return; }
    }
    ctx->pc = 0x18346Cu;
label_18346c:
    // 0x18346c: 0x8e300034  lw          $s0, 0x34($s1)
    ctx->pc = 0x18346cu;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 52)));
    // 0x183470: 0x8e240030  lw          $a0, 0x30($s1)
    ctx->pc = 0x183470u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 48)));
    // 0x183474: 0x240303e8  addiu       $v1, $zero, 0x3E8
    ctx->pc = 0x183474u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1000));
    // 0x183478: 0xafa20210  sw          $v0, 0x210($sp)
    ctx->pc = 0x183478u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 528), GPR_U32(ctx, 2));
    // 0x18347c: 0x50600001  beql        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x18347Cu;
    {
        const bool branch_taken_0x18347c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x18347c) {
            ctx->pc = 0x183480u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x18347Cu;
            // 0x183480: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x183484u;
            goto label_183484;
        }
    }
    ctx->pc = 0x183484u;
label_183484:
    // 0x183484: 0x83001a  div         $zero, $a0, $v1
    ctx->pc = 0x183484u;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 4);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x183488: 0x8e250038  lw          $a1, 0x38($s1)
    ctx->pc = 0x183488u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 56)));
    // 0x18348c: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x18348cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x183490: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x183490u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x183494: 0x2012  mflo        $a0
    ctx->pc = 0x183494u;
    SET_GPR_U64(ctx, 4, ctx->lo);
    // 0x183498: 0x41140  sll         $v0, $a0, 5
    ctx->pc = 0x183498u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 5));
    // 0x18349c: 0x441023  subu        $v0, $v0, $a0
    ctx->pc = 0x18349cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1834a0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1834a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1834a4: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1834a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1834a8: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1834a8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1834ac: 0x18a00011  blez        $a1, . + 4 + (0x11 << 2)
    ctx->pc = 0x1834ACu;
    {
        const bool branch_taken_0x1834ac = (GPR_S64(ctx, 5) <= 0);
        ctx->pc = 0x1834B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1834ACu;
            // 0x1834b0: 0x24560001  addiu       $s6, $v0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1834ac) {
            ctx->pc = 0x1834F4u;
            goto label_1834f4;
        }
    }
    ctx->pc = 0x1834B4u;
    // 0x1834b4: 0x0  nop
    ctx->pc = 0x1834b4u;
    // NOP
label_1834b8:
    // 0x1834b8: 0x16760004  bne         $s3, $s6, . + 4 + (0x4 << 2)
    ctx->pc = 0x1834B8u;
    {
        const bool branch_taken_0x1834b8 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 22));
        ctx->pc = 0x1834BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1834B8u;
            // 0x1834bc: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1834b8) {
            ctx->pc = 0x1834CCu;
            goto label_1834cc;
        }
    }
    ctx->pc = 0x1834C0u;
    // 0x1834c0: 0x8e220034  lw          $v0, 0x34($s1)
    ctx->pc = 0x1834c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 52)));
    // 0x1834c4: 0x2021023  subu        $v0, $s0, $v0
    ctx->pc = 0x1834c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1834c8: 0xae220170  sw          $v0, 0x170($s1)
    ctx->pc = 0x1834c8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 368), GPR_U32(ctx, 2));
label_1834cc:
    // 0x1834cc: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1834ccu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1834d0: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1834d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1834d4: 0xc061d2a  jal         func_1874A8
    ctx->pc = 0x1834D4u;
    SET_GPR_U32(ctx, 31, 0x1834DCu);
    ctx->pc = 0x1834D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1834D4u;
            // 0x1834d8: 0x26940001  addiu       $s4, $s4, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1874A8u;
    if (runtime->hasFunction(0x1874A8u)) {
        auto targetFn = runtime->lookupFunction(0x1874A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1834DCu; }
        if (ctx->pc != 0x1834DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001874A8_0x1874a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1834DCu; }
        if (ctx->pc != 0x1834DCu) { return; }
    }
    ctx->pc = 0x1834DCu;
label_1834dc:
    // 0x1834dc: 0x26640001  addiu       $a0, $s3, 0x1
    ctx->pc = 0x1834dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x1834e0: 0x8e230038  lw          $v1, 0x38($s1)
    ctx->pc = 0x1834e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 56)));
    // 0x1834e4: 0x82980a  movz        $s3, $a0, $v0
    ctx->pc = 0x1834e4u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 19, GPR_VEC(ctx, 4));
    // 0x1834e8: 0x283182a  slt         $v1, $s4, $v1
    ctx->pc = 0x1834e8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 20) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1834ec: 0x1460fff2  bnez        $v1, . + 4 + (-0xE << 2)
    ctx->pc = 0x1834ECu;
    {
        const bool branch_taken_0x1834ec = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1834F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1834ECu;
            // 0x1834f0: 0xafa20210  sw          $v0, 0x210($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 528), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1834ec) {
            ctx->pc = 0x1834B8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1834b8;
        }
    }
    ctx->pc = 0x1834F4u;
label_1834f4:
    // 0x1834f4: 0x27b30010  addiu       $s3, $sp, 0x10
    ctx->pc = 0x1834f4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1834f8: 0x8e26003c  lw          $a2, 0x3C($s1)
    ctx->pc = 0x1834f8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 60)));
    // 0x1834fc: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1834fcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x183500: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x183500u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x183504: 0xc060c02  jal         func_183008
    ctx->pc = 0x183504u;
    SET_GPR_U32(ctx, 31, 0x18350Cu);
    ctx->pc = 0x183508u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x183504u;
            // 0x183508: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x183008u;
    if (runtime->hasFunction(0x183008u)) {
        auto targetFn = runtime->lookupFunction(0x183008u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18350Cu; }
        if (ctx->pc != 0x18350Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00183008_0x183008(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18350Cu; }
        if (ctx->pc != 0x18350Cu) { return; }
    }
    ctx->pc = 0x18350Cu;
label_18350c:
    // 0x18350c: 0x1440004c  bnez        $v0, . + 4 + (0x4C << 2)
    ctx->pc = 0x18350Cu;
    {
        const bool branch_taken_0x18350c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x183510u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18350Cu;
            // 0x183510: 0xafa20210  sw          $v0, 0x210($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 528), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18350c) {
            ctx->pc = 0x183640u;
            goto label_183640;
        }
    }
    ctx->pc = 0x183514u;
    // 0x183514: 0x97a30010  lhu         $v1, 0x10($sp)
    ctx->pc = 0x183514u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x183518: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x183518u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x18351c: 0x30638000  andi        $v1, $v1, 0x8000
    ctx->pc = 0x18351cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)32768);
    // 0x183520: 0x10600047  beqz        $v1, . + 4 + (0x47 << 2)
    ctx->pc = 0x183520u;
    {
        const bool branch_taken_0x183520 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x183524u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x183520u;
            // 0x183524: 0x3442002f  ori         $v0, $v0, 0x2F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)47);
        ctx->in_delay_slot = false;
        if (branch_taken_0x183520) {
            ctx->pc = 0x183640u;
            goto label_183640;
        }
    }
    ctx->pc = 0x183528u;
    // 0x183528: 0x27b00050  addiu       $s0, $sp, 0x50
    ctx->pc = 0x183528u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x18352c: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x18352cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x183530: 0x24a517b0  addiu       $a1, $a1, 0x17B0
    ctx->pc = 0x183530u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 6064));
    // 0x183534: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x183534u;
    SET_GPR_U32(ctx, 31, 0x18353Cu);
    ctx->pc = 0x183538u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x183534u;
            // 0x183538: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18353Cu; }
        if (ctx->pc != 0x18353Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18353Cu; }
        if (ctx->pc != 0x18353Cu) { return; }
    }
    ctx->pc = 0x18353Cu;
label_18353c:
    // 0x18353c: 0x14400012  bnez        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x18353Cu;
    {
        const bool branch_taken_0x18353c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x183540u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18353Cu;
            // 0x183540: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18353c) {
            ctx->pc = 0x183588u;
            goto label_183588;
        }
    }
    ctx->pc = 0x183544u;
    // 0x183544: 0x8e26003c  lw          $a2, 0x3C($s1)
    ctx->pc = 0x183544u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 60)));
    // 0x183548: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x183548u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18354c: 0xc060c02  jal         func_183008
    ctx->pc = 0x18354Cu;
    SET_GPR_U32(ctx, 31, 0x183554u);
    ctx->pc = 0x183550u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18354Cu;
            // 0x183550: 0x24070001  addiu       $a3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x183008u;
    if (runtime->hasFunction(0x183008u)) {
        auto targetFn = runtime->lookupFunction(0x183008u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183554u; }
        if (ctx->pc != 0x183554u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00183008_0x183008(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183554u; }
        if (ctx->pc != 0x183554u) { return; }
    }
    ctx->pc = 0x183554u;
label_183554:
    // 0x183554: 0x1440003a  bnez        $v0, . + 4 + (0x3A << 2)
    ctx->pc = 0x183554u;
    {
        const bool branch_taken_0x183554 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x183558u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x183554u;
            // 0x183558: 0xafa20210  sw          $v0, 0x210($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 528), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x183554) {
            ctx->pc = 0x183640u;
            goto label_183640;
        }
    }
    ctx->pc = 0x18355Cu;
    // 0x18355c: 0x97a30010  lhu         $v1, 0x10($sp)
    ctx->pc = 0x18355cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x183560: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x183560u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x183564: 0x30638000  andi        $v1, $v1, 0x8000
    ctx->pc = 0x183564u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)32768);
    // 0x183568: 0x10600035  beqz        $v1, . + 4 + (0x35 << 2)
    ctx->pc = 0x183568u;
    {
        const bool branch_taken_0x183568 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x18356Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x183568u;
            // 0x18356c: 0x3442002f  ori         $v0, $v0, 0x2F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)47);
        ctx->in_delay_slot = false;
        if (branch_taken_0x183568) {
            ctx->pc = 0x183640u;
            goto label_183640;
        }
    }
    ctx->pc = 0x183570u;
    // 0x183570: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x183570u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x183574: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x183574u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x183578: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x183578u;
    SET_GPR_U32(ctx, 31, 0x183580u);
    ctx->pc = 0x18357Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x183578u;
            // 0x18357c: 0x24a517b8  addiu       $a1, $a1, 0x17B8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 6072));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183580u; }
        if (ctx->pc != 0x183580u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x183580u; }
        if (ctx->pc != 0x183580u) { return; }
    }
    ctx->pc = 0x183580u;
label_183580:
    // 0x183580: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x183580u;
    {
        const bool branch_taken_0x183580 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x183580) {
            ctx->pc = 0x183584u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x183580u;
            // 0x183584: 0x24020898  addiu       $v0, $zero, 0x898 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2200));
        ctx->in_delay_slot = false;
            ctx->pc = 0x183598u;
            goto label_183598;
        }
    }
    ctx->pc = 0x183588u;
label_183588:
    // 0x183588: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x183588u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x18358c: 0x1000002c  b           . + 4 + (0x2C << 2)
    ctx->pc = 0x18358Cu;
    {
        const bool branch_taken_0x18358c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x183590u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18358Cu;
            // 0x183590: 0x3442002f  ori         $v0, $v0, 0x2F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)47);
        ctx->in_delay_slot = false;
        if (branch_taken_0x18358c) {
            ctx->pc = 0x183640u;
            goto label_183640;
        }
    }
    ctx->pc = 0x183594u;
    // 0x183594: 0x0  nop
    ctx->pc = 0x183594u;
    // NOP
label_183598:
    // 0x183598: 0x26e45b48  addiu       $a0, $s7, 0x5B48
    ctx->pc = 0x183598u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 23), 23368));
    // 0x18359c: 0x2421018  mult        $v0, $s2, $v0
    ctx->pc = 0x18359cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x1835a0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1835a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1835a4: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1835a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1835a8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1835A8u;
    {
        const bool branch_taken_0x1835a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1835ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1835A8u;
            // 0x1835ac: 0xac43088c  sw          $v1, 0x88C($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 2188), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1835a8) {
            ctx->pc = 0x1835BCu;
            goto label_1835bc;
        }
    }
    ctx->pc = 0x1835B0u;
label_1835b0:
    // 0x1835b0: 0xc061f94  jal         func_187E50
    ctx->pc = 0x1835B0u;
    SET_GPR_U32(ctx, 31, 0x1835B8u);
    ctx->pc = 0x1835B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1835B0u;
            // 0x1835b4: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x187E50u;
    if (runtime->hasFunction(0x187E50u)) {
        auto targetFn = runtime->lookupFunction(0x187E50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1835B8u; }
        if (ctx->pc != 0x1835B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187E50_0x187e50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1835B8u; }
        if (ctx->pc != 0x1835B8u) { return; }
    }
    ctx->pc = 0x1835B8u;
label_1835b8:
    // 0x1835b8: 0xafa20210  sw          $v0, 0x210($sp)
    ctx->pc = 0x1835b8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 528), GPR_U32(ctx, 2));
label_1835bc:
    // 0x1835bc: 0x24030898  addiu       $v1, $zero, 0x898
    ctx->pc = 0x1835bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2200));
    // 0x1835c0: 0x26e45b48  addiu       $a0, $s7, 0x5B48
    ctx->pc = 0x1835c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 23), 23368));
    // 0x1835c4: 0x2431818  mult        $v1, $s2, $v1
    ctx->pc = 0x1835c4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1835c8: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1835c8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x1835cc: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1835ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1835d0: 0x2470088c  addiu       $s0, $v1, 0x88C
    ctx->pc = 0x1835d0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 2188));
    // 0x1835d4: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x1835d4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1835d8: 0x10800019  beqz        $a0, . + 4 + (0x19 << 2)
    ctx->pc = 0x1835D8u;
    {
        const bool branch_taken_0x1835d8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1835DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1835D8u;
            // 0x1835dc: 0x3442002f  ori         $v0, $v0, 0x2F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)47);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1835d8) {
            ctx->pc = 0x183640u;
            goto label_183640;
        }
    }
    ctx->pc = 0x1835E0u;
    // 0x1835e0: 0x12a0000c  beqz        $s5, . + 4 + (0xC << 2)
    ctx->pc = 0x1835E0u;
    {
        const bool branch_taken_0x1835e0 = (GPR_U64(ctx, 21) == GPR_U64(ctx, 0));
        ctx->pc = 0x1835E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1835E0u;
            // 0x1835e4: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1835e0) {
            ctx->pc = 0x183614u;
            goto label_183614;
        }
    }
    ctx->pc = 0x1835E8u;
    // 0x1835e8: 0xc060bcc  jal         func_182F30
    ctx->pc = 0x1835E8u;
    SET_GPR_U32(ctx, 31, 0x1835F0u);
    ctx->pc = 0x1835ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1835E8u;
            // 0x1835ec: 0x27a50210  addiu       $a1, $sp, 0x210 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 528));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182F30u;
    if (runtime->hasFunction(0x182F30u)) {
        auto targetFn = runtime->lookupFunction(0x182F30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1835F0u; }
        if (ctx->pc != 0x1835F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182F30_0x182f30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1835F0u; }
        if (ctx->pc != 0x1835F0u) { return; }
    }
    ctx->pc = 0x1835F0u;
label_1835f0:
    // 0x1835f0: 0x8fa30210  lw          $v1, 0x210($sp)
    ctx->pc = 0x1835f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 528)));
    // 0x1835f4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1835f4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1835f8: 0x14600011  bnez        $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x1835F8u;
    {
        const bool branch_taken_0x1835f8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1835FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1835F8u;
            // 0x1835fc: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1835f8) {
            ctx->pc = 0x183640u;
            goto label_183640;
        }
    }
    ctx->pc = 0x183600u;
    // 0x183600: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x183600u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x183604: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x183604u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x183608: 0xaea20000  sw          $v0, 0x0($s5)
    ctx->pc = 0x183608u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 2));
    // 0x18360c: 0xaea30004  sw          $v1, 0x4($s5)
    ctx->pc = 0x18360cu;
    WRITE32(ADD32(GPR_U32(ctx, 21), 4), GPR_U32(ctx, 3));
    // 0x183610: 0xaea40008  sw          $a0, 0x8($s5)
    ctx->pc = 0x183610u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 8), GPR_U32(ctx, 4));
label_183614:
    // 0x183614: 0x24020898  addiu       $v0, $zero, 0x898
    ctx->pc = 0x183614u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2200));
    // 0x183618: 0x26e35b48  addiu       $v1, $s7, 0x5B48
    ctx->pc = 0x183618u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 23), 23368));
    // 0x18361c: 0x2421018  mult        $v0, $s2, $v0
    ctx->pc = 0x18361cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x183620: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x183620u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x183624: 0x24440888  addiu       $a0, $v0, 0x888
    ctx->pc = 0x183624u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 2184));
    // 0x183628: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x183628u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x18362c: 0x50600004  beql        $v1, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x18362Cu;
    {
        const bool branch_taken_0x18362c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x18362c) {
            ctx->pc = 0x183630u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x18362Cu;
            // 0x183630: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x183640u;
            goto label_183640;
        }
    }
    ctx->pc = 0x183634u;
    // 0x183634: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x183634u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x183638: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x183638u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x18363c: 0x34429003  ori         $v0, $v0, 0x9003
    ctx->pc = 0x18363cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)36867);
label_183640:
    // 0x183640: 0xdfb00220  ld          $s0, 0x220($sp)
    ctx->pc = 0x183640u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 544)));
    // 0x183644: 0xdfb10228  ld          $s1, 0x228($sp)
    ctx->pc = 0x183644u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 552)));
    // 0x183648: 0xdfb20230  ld          $s2, 0x230($sp)
    ctx->pc = 0x183648u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 560)));
    // 0x18364c: 0xdfb30238  ld          $s3, 0x238($sp)
    ctx->pc = 0x18364cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 568)));
    // 0x183650: 0xdfb40240  ld          $s4, 0x240($sp)
    ctx->pc = 0x183650u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 576)));
    // 0x183654: 0xdfb50248  ld          $s5, 0x248($sp)
    ctx->pc = 0x183654u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 584)));
    // 0x183658: 0xdfb60250  ld          $s6, 0x250($sp)
    ctx->pc = 0x183658u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 592)));
    // 0x18365c: 0xdfb70258  ld          $s7, 0x258($sp)
    ctx->pc = 0x18365cu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 600)));
    // 0x183660: 0xdfbf0260  ld          $ra, 0x260($sp)
    ctx->pc = 0x183660u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 608)));
    // 0x183664: 0x3e00008  jr          $ra
    ctx->pc = 0x183664u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x183668u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x183664u;
            // 0x183668: 0x27bd0270  addiu       $sp, $sp, 0x270 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 624));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1832E4u: goto label_1832e4;
            case 0x1832F8u: goto label_1832f8;
            case 0x18330Cu: goto label_18330c;
            case 0x183314u: goto label_183314;
            case 0x18334Cu: goto label_18334c;
            case 0x183374u: goto label_183374;
            case 0x1833E4u: goto label_1833e4;
            case 0x1833ECu: goto label_1833ec;
            case 0x1833F8u: goto label_1833f8;
            case 0x183400u: goto label_183400;
            case 0x183414u: goto label_183414;
            case 0x183430u: goto label_183430;
            case 0x183464u: goto label_183464;
            case 0x18346Cu: goto label_18346c;
            case 0x183484u: goto label_183484;
            case 0x1834B8u: goto label_1834b8;
            case 0x1834CCu: goto label_1834cc;
            case 0x1834DCu: goto label_1834dc;
            case 0x1834F4u: goto label_1834f4;
            case 0x18350Cu: goto label_18350c;
            case 0x18353Cu: goto label_18353c;
            case 0x183554u: goto label_183554;
            case 0x183580u: goto label_183580;
            case 0x183588u: goto label_183588;
            case 0x183598u: goto label_183598;
            case 0x1835B0u: goto label_1835b0;
            case 0x1835B8u: goto label_1835b8;
            case 0x1835BCu: goto label_1835bc;
            case 0x1835F0u: goto label_1835f0;
            case 0x183614u: goto label_183614;
            case 0x183640u: goto label_183640;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18366Cu;
    // 0x18366c: 0x0  nop
    ctx->pc = 0x18366cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
