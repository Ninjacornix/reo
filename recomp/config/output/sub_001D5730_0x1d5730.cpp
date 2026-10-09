#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D5730
// Address: 0x1d5730 - 0x1d5830
void sub_001D5730_0x1d5730(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D5730_0x1d5730");
#endif

    switch (ctx->pc) {
        case 0x1d57b0u: goto label_1d57b0;
        case 0x1d57e4u: goto label_1d57e4;
        case 0x1d57f8u: goto label_1d57f8;
        default: break;
    }

    ctx->pc = 0x1d5730u;

    // 0x1d5730: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1d5730u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1d5734: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1d5734u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1d5738: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x1d5738u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x1d573c: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x1d573cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5740: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1d5740u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5744: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1d5744u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1d5748: 0x8c446998  lw          $a0, 0x6998($v0)
    ctx->pc = 0x1d5748u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 27032)));
    // 0x1d574c: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x1d574cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x1d5750: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d5750u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d5754: 0x1082002f  beq         $a0, $v0, . + 4 + (0x2F << 2)
    ctx->pc = 0x1D5754u;
    {
        const bool branch_taken_0x1d5754 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1D5758u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5754u;
            // 0x1d5758: 0xffb00010  sd          $s0, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5754) {
            ctx->pc = 0x1D5814u;
            goto label_1d5814;
        }
    }
    ctx->pc = 0x1D575Cu;
    // 0x1d575c: 0x3c030034  lui         $v1, 0x34
    ctx->pc = 0x1d575cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)52 << 16));
    // 0x1d5760: 0x8c622840  lw          $v0, 0x2840($v1)
    ctx->pc = 0x1d5760u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 10304)));
    // 0x1d5764: 0x222102a  slt         $v0, $s1, $v0
    ctx->pc = 0x1d5764u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1d5768: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D5768u;
    {
        const bool branch_taken_0x1d5768 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D576Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5768u;
            // 0x1d576c: 0x24722840  addiu       $s2, $v1, 0x2840 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 3), 10304));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5768) {
            ctx->pc = 0x1D5778u;
            goto label_1d5778;
        }
    }
    ctx->pc = 0x1D5770u;
    // 0x1d5770: 0x10000028  b           . + 4 + (0x28 << 2)
    ctx->pc = 0x1D5770u;
    {
        const bool branch_taken_0x1d5770 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5774u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5770u;
            // 0x1d5774: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5770) {
            ctx->pc = 0x1D5814u;
            goto label_1d5814;
        }
    }
    ctx->pc = 0x1D5778u;
label_1d5778:
    // 0x1d5778: 0x2cc20003  sltiu       $v0, $a2, 0x3
    ctx->pc = 0x1d5778u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)3) ? 1 : 0);
    // 0x1d577c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D577Cu;
    {
        const bool branch_taken_0x1d577c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D5780u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D577Cu;
            // 0x1d5780: 0x24020038  addiu       $v0, $zero, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 56));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d577c) {
            ctx->pc = 0x1D578Cu;
            goto label_1d578c;
        }
    }
    ctx->pc = 0x1D5784u;
    // 0x1d5784: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x1D5784u;
    {
        const bool branch_taken_0x1d5784 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5788u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5784u;
            // 0x1d5788: 0x2402fff4  addiu       $v0, $zero, -0xC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967284));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5784) {
            ctx->pc = 0x1D5814u;
            goto label_1d5814;
        }
    }
    ctx->pc = 0x1D578Cu;
label_1d578c:
    // 0x1d578c: 0x8e450004  lw          $a1, 0x4($s2)
    ctx->pc = 0x1d578cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x1d5790: 0x2221018  mult        $v0, $s1, $v0
    ctx->pc = 0x1d5790u;
    { int64_t result = (int64_t)GPR_S32(ctx, 17) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x1d5794: 0x3c030034  lui         $v1, 0x34
    ctx->pc = 0x1d5794u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)52 << 16));
    // 0x1d5798: 0x24702940  addiu       $s0, $v1, 0x2940
    ctx->pc = 0x1d5798u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 10560));
    // 0x1d579c: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x1d579cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1d57a0: 0xac460000  sw          $a2, 0x0($v0)
    ctx->pc = 0x1d57a0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 6));
    // 0x1d57a4: 0xa0712940  sb          $s1, 0x2940($v1)
    ctx->pc = 0x1d57a4u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 10560), (uint8_t)GPR_U32(ctx, 17));
    // 0x1d57a8: 0xc045198  jal         func_114660
    ctx->pc = 0x1D57A8u;
    SET_GPR_U32(ctx, 31, 0x1D57B0u);
    ctx->pc = 0x1D57ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D57A8u;
            // 0x1d57ac: 0xa2060001  sb          $a2, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D57B0u; }
        if (ctx->pc != 0x1D57B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D57B0u; }
        if (ctx->pc != 0x1D57B0u) { return; }
    }
    ctx->pc = 0x1D57B0u;
label_1d57b0:
    // 0x1d57b0: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1d57b0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1d57b4: 0x3c090034  lui         $t1, 0x34
    ctx->pc = 0x1d57b4u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)52 << 16));
    // 0x1d57b8: 0x3c0b001d  lui         $t3, 0x1D
    ctx->pc = 0x1d57b8u;
    SET_GPR_S32(ctx, 11, (int32_t)((uint32_t)29 << 16));
    // 0x1d57bc: 0x248428e0  addiu       $a0, $a0, 0x28E0
    ctx->pc = 0x1d57bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 10464));
    // 0x1d57c0: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x1d57c0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d57c4: 0x25292980  addiu       $t1, $t1, 0x2980
    ctx->pc = 0x1d57c4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 10624));
    // 0x1d57c8: 0x256b59b8  addiu       $t3, $t3, 0x59B8
    ctx->pc = 0x1d57c8u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 22968));
    // 0x1d57cc: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x1d57ccu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x1d57d0: 0x24050005  addiu       $a1, $zero, 0x5
    ctx->pc = 0x1d57d0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1d57d4: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1d57d4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d57d8: 0x24080010  addiu       $t0, $zero, 0x10
    ctx->pc = 0x1d57d8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1d57dc: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x1D57DCu;
    SET_GPR_U32(ctx, 31, 0x1D57E4u);
    ctx->pc = 0x1D57E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D57DCu;
            // 0x1d57e0: 0x240a0010  addiu       $t2, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D57E4u; }
        if (ctx->pc != 0x1D57E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D57E4u; }
        if (ctx->pc != 0x1D57E4u) { return; }
    }
    ctx->pc = 0x1D57E4u;
label_1d57e4:
    // 0x1d57e4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D57E4u;
    {
        const bool branch_taken_0x1d57e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D57E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D57E4u;
            // 0x1d57e8: 0x3c040025  lui         $a0, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d57e4) {
            ctx->pc = 0x1D5800u;
            goto label_1d5800;
        }
    }
    ctx->pc = 0x1D57ECu;
    // 0x1d57ec: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1d57ecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d57f0: 0xc045a12  jal         func_116848
    ctx->pc = 0x1D57F0u;
    SET_GPR_U32(ctx, 31, 0x1D57F8u);
    ctx->pc = 0x1D57F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D57F0u;
            // 0x1d57f4: 0x24846f10  addiu       $a0, $a0, 0x6F10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 28432));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D57F8u; }
        if (ctx->pc != 0x1D57F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D57F8u; }
        if (ctx->pc != 0x1D57F8u) { return; }
    }
    ctx->pc = 0x1D57F8u;
label_1d57f8:
    // 0x1d57f8: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1D57F8u;
    {
        const bool branch_taken_0x1d57f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D57FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D57F8u;
            // 0x1d57fc: 0x2402fffe  addiu       $v0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d57f8) {
            ctx->pc = 0x1D5814u;
            goto label_1d5814;
        }
    }
    ctx->pc = 0x1D5800u;
label_1d5800:
    // 0x1d5800: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1d5800u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1d5804: 0xae510094  sw          $s1, 0x94($s2)
    ctx->pc = 0x1d5804u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 148), GPR_U32(ctx, 17));
    // 0x1d5808: 0xae420090  sw          $v0, 0x90($s2)
    ctx->pc = 0x1d5808u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 144), GPR_U32(ctx, 2));
    // 0x1d580c: 0xae400098  sw          $zero, 0x98($s2)
    ctx->pc = 0x1d580cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 152), GPR_U32(ctx, 0));
    // 0x1d5810: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1d5810u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1d5814:
    // 0x1d5814: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1d5814u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d5818: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x1d5818u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d581c: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x1d581cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d5820: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1d5820u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d5824: 0x3e00008  jr          $ra
    ctx->pc = 0x1D5824u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D5828u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5824u;
            // 0x1d5828: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D5778u: goto label_1d5778;
            case 0x1D578Cu: goto label_1d578c;
            case 0x1D57B0u: goto label_1d57b0;
            case 0x1D57E4u: goto label_1d57e4;
            case 0x1D57F8u: goto label_1d57f8;
            case 0x1D5800u: goto label_1d5800;
            case 0x1D5814u: goto label_1d5814;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D582Cu;
    // 0x1d582c: 0x0  nop
    ctx->pc = 0x1d582cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
