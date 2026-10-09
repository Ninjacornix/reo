#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00167680
// Address: 0x167680 - 0x167828
void sub_00167680_0x167680(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00167680_0x167680");
#endif

    switch (ctx->pc) {
        case 0x1676e0u: goto label_1676e0;
        case 0x1676f4u: goto label_1676f4;
        case 0x16772cu: goto label_16772c;
        default: break;
    }

    ctx->pc = 0x167680u;

    // 0x167680: 0x510c0  sll         $v0, $a1, 3
    ctx->pc = 0x167680u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x167684: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x167684u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x167688: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x167688u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x16768c: 0xffb50048  sd          $s5, 0x48($sp)
    ctx->pc = 0x16768cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 21));
    // 0x167690: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x167690u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x167694: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x167694u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x167698: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x167698u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x16769c: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x16769cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x1676a0: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x1676a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x1676a4: 0x24871140  addiu       $a3, $a0, 0x1140
    ctx->pc = 0x1676a4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 4), 4416));
    // 0x1676a8: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x1676a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x1676ac: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1676acu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1676b0: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x1676b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x1676b4: 0xe23821  addu        $a3, $a3, $v0
    ctx->pc = 0x1676b4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x1676b8: 0xffb60050  sd          $s6, 0x50($sp)
    ctx->pc = 0x1676b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 22));
    // 0x1676bc: 0xffb70058  sd          $s7, 0x58($sp)
    ctx->pc = 0x1676bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 23));
    // 0x1676c0: 0xffbe0060  sd          $fp, 0x60($sp)
    ctx->pc = 0x1676c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 30));
    // 0x1676c4: 0xffbf0068  sd          $ra, 0x68($sp)
    ctx->pc = 0x1676c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 31));
    // 0x1676c8: 0x8ce30004  lw          $v1, 0x4($a3)
    ctx->pc = 0x1676c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x1676cc: 0x14600006  bnez        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1676CCu;
    {
        const bool branch_taken_0x1676cc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1676D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1676CCu;
            // 0x1676d0: 0xc0a82d  daddu       $s5, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1676cc) {
            ctx->pc = 0x1676E8u;
            goto label_1676e8;
        }
    }
    ctx->pc = 0x1676D4u;
    // 0x1676d4: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1676d4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1676d8: 0xc05a704  jal         func_169C10
    ctx->pc = 0x1676D8u;
    SET_GPR_U32(ctx, 31, 0x1676E0u);
    ctx->pc = 0x1676DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1676D8u;
            // 0x1676dc: 0x34a50401  ori         $a1, $a1, 0x401 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1025);
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1676E0u; }
        if (ctx->pc != 0x1676E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1676E0u; }
        if (ctx->pc != 0x1676E0u) { return; }
    }
    ctx->pc = 0x1676E0u;
label_1676e0:
    // 0x1676e0: 0x10000046  b           . + 4 + (0x46 << 2)
    ctx->pc = 0x1676E0u;
    {
        const bool branch_taken_0x1676e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1676E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1676E0u;
            // 0x1676e4: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1676e0) {
            ctx->pc = 0x1677FCu;
            goto label_1677fc;
        }
    }
    ctx->pc = 0x1676E8u;
label_1676e8:
    // 0x1676e8: 0x24f00010  addiu       $s0, $a3, 0x10
    ctx->pc = 0x1676e8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 7), 16));
    // 0x1676ec: 0xc05a7b2  jal         func_169EC8
    ctx->pc = 0x1676ECu;
    SET_GPR_U32(ctx, 31, 0x1676F4u);
    ctx->pc = 0x1676F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1676ECu;
            // 0x1676f0: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EC8u;
    if (runtime->hasFunction(0x169EC8u)) {
        auto targetFn = runtime->lookupFunction(0x169EC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1676F4u; }
        if (ctx->pc != 0x1676F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EC8_0x169ec8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1676F4u; }
        if (ctx->pc != 0x1676F4u) { return; }
    }
    ctx->pc = 0x1676F4u;
label_1676f4:
    // 0x1676f4: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x1676f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1676f8: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1676f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1676fc: 0xafa20004  sw          $v0, 0x4($sp)
    ctx->pc = 0x1676fcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
    // 0x167700: 0x8e050018  lw          $a1, 0x18($s0)
    ctx->pc = 0x167700u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x167704: 0x8e13002c  lw          $s3, 0x2C($s0)
    ctx->pc = 0x167704u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x167708: 0x8e14001c  lw          $s4, 0x1C($s0)
    ctx->pc = 0x167708u;
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x16770c: 0x8e110028  lw          $s1, 0x28($s0)
    ctx->pc = 0x16770cu;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x167710: 0x8e17000c  lw          $s7, 0xC($s0)
    ctx->pc = 0x167710u;
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x167714: 0x8e120010  lw          $s2, 0x10($s0)
    ctx->pc = 0x167714u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x167718: 0x8e1e0014  lw          $fp, 0x14($s0)
    ctx->pc = 0x167718u;
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x16771c: 0x8e160020  lw          $s6, 0x20($s0)
    ctx->pc = 0x16771cu;
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x167720: 0x7fa50010  sq          $a1, 0x10($sp)
    ctx->pc = 0x167720u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 5));
    // 0x167724: 0xc05a7b8  jal         func_169EE0
    ctx->pc = 0x167724u;
    SET_GPR_U32(ctx, 31, 0x16772Cu);
    ctx->pc = 0x167728u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x167724u;
            // 0x167728: 0x8e100024  lw          $s0, 0x24($s0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EE0u;
    if (runtime->hasFunction(0x169EE0u)) {
        auto targetFn = runtime->lookupFunction(0x169EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16772Cu; }
        if (ctx->pc != 0x16772Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EE0_0x169ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16772Cu; }
        if (ctx->pc != 0x16772Cu) { return; }
    }
    ctx->pc = 0x16772Cu;
label_16772c:
    // 0x16772c: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x16772cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x167730: 0x2741021  addu        $v0, $s3, $s4
    ctx->pc = 0x167730u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 20)));
    // 0x167734: 0x222102a  slt         $v0, $s1, $v0
    ctx->pc = 0x167734u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x167738: 0xaeb20008  sw          $s2, 0x8($s5)
    ctx->pc = 0x167738u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 8), GPR_U32(ctx, 18));
    // 0x16773c: 0xaea30000  sw          $v1, 0x0($s5)
    ctx->pc = 0x16773cu;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 3));
    // 0x167740: 0xaeb70004  sw          $s7, 0x4($s5)
    ctx->pc = 0x167740u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 4), GPR_U32(ctx, 23));
    // 0x167744: 0xaeb10024  sw          $s1, 0x24($s5)
    ctx->pc = 0x167744u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 36), GPR_U32(ctx, 17));
    // 0x167748: 0xaeb30028  sw          $s3, 0x28($s5)
    ctx->pc = 0x167748u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 40), GPR_U32(ctx, 19));
    // 0x16774c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x16774Cu;
    {
        const bool branch_taken_0x16774c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x167750u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16774Cu;
            // 0x167750: 0x7ba50010  lq          $a1, 0x10($sp) (Delay Slot)
        SET_GPR_VEC(ctx, 5, READ128(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16774c) {
            ctx->pc = 0x167768u;
            goto label_167768;
        }
    }
    ctx->pc = 0x167754u;
    // 0x167754: 0xaea00020  sw          $zero, 0x20($s5)
    ctx->pc = 0x167754u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 32), GPR_U32(ctx, 0));
    // 0x167758: 0xaea0000c  sw          $zero, 0xC($s5)
    ctx->pc = 0x167758u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 12), GPR_U32(ctx, 0));
    // 0x16775c: 0xaea00014  sw          $zero, 0x14($s5)
    ctx->pc = 0x16775cu;
    WRITE32(ADD32(GPR_U32(ctx, 21), 20), GPR_U32(ctx, 0));
    // 0x167760: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x167760u;
    {
        const bool branch_taken_0x167760 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x167764u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167760u;
            // 0x167764: 0xaea00018  sw          $zero, 0x18($s5) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 21), 24), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167760) {
            ctx->pc = 0x1677ACu;
            goto label_1677ac;
        }
    }
    ctx->pc = 0x167768u;
label_167768:
    // 0x167768: 0x2d0102a  slt         $v0, $s6, $s0
    ctx->pc = 0x167768u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 22) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x16776c: 0x50400012  beql        $v0, $zero, . + 4 + (0x12 << 2)
    ctx->pc = 0x16776Cu;
    {
        const bool branch_taken_0x16776c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x16776c) {
            ctx->pc = 0x167770u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16776Cu;
            // 0x167770: 0x2961023  subu        $v0, $s4, $s6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 20), GPR_U32(ctx, 22)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1677B8u;
            goto label_1677b8;
        }
    }
    ctx->pc = 0x167774u;
    // 0x167774: 0x2161023  subu        $v0, $s0, $s6
    ctx->pc = 0x167774u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 22)));
    // 0x167778: 0x2ae30009  slti        $v1, $s7, 0x9
    ctx->pc = 0x167778u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 23) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0x16777c: 0xaea2000c  sw          $v0, 0xC($s5)
    ctx->pc = 0x16777cu;
    WRITE32(ADD32(GPR_U32(ctx, 21), 12), GPR_U32(ctx, 2));
    // 0x167780: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x167780u;
    {
        const bool branch_taken_0x167780 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x167784u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167780u;
            // 0x167784: 0x3d61021  addu        $v0, $fp, $s6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 22)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167780) {
            ctx->pc = 0x167790u;
            goto label_167790;
        }
    }
    ctx->pc = 0x167788u;
    // 0x167788: 0x161040  sll         $v0, $s6, 1
    ctx->pc = 0x167788u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 22), 1));
    // 0x16778c: 0x3c21021  addu        $v0, $fp, $v0
    ctx->pc = 0x16778cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 2)));
label_167790:
    // 0x167790: 0xaea20014  sw          $v0, 0x14($s5)
    ctx->pc = 0x167790u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 20), GPR_U32(ctx, 2));
    // 0x167794: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x167794u;
    {
        const bool branch_taken_0x167794 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x167798u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167794u;
            // 0x167798: 0xb61021  addu        $v0, $a1, $s6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 22)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167794) {
            ctx->pc = 0x1677A4u;
            goto label_1677a4;
        }
    }
    ctx->pc = 0x16779Cu;
    // 0x16779c: 0x161040  sll         $v0, $s6, 1
    ctx->pc = 0x16779cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 22), 1));
    // 0x1677a0: 0xa21021  addu        $v0, $a1, $v0
    ctx->pc = 0x1677a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
label_1677a4:
    // 0x1677a4: 0xaea20018  sw          $v0, 0x18($s5)
    ctx->pc = 0x1677a4u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 24), GPR_U32(ctx, 2));
    // 0x1677a8: 0xaea00020  sw          $zero, 0x20($s5)
    ctx->pc = 0x1677a8u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 32), GPR_U32(ctx, 0));
label_1677ac:
    // 0x1677ac: 0xaea00010  sw          $zero, 0x10($s5)
    ctx->pc = 0x1677acu;
    WRITE32(ADD32(GPR_U32(ctx, 21), 16), GPR_U32(ctx, 0));
    // 0x1677b0: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1677B0u;
    {
        const bool branch_taken_0x1677b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1677B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1677B0u;
            // 0x1677b4: 0xaea0001c  sw          $zero, 0x1C($s5) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 21), 28), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1677b0) {
            ctx->pc = 0x1677F4u;
            goto label_1677f4;
        }
    }
    ctx->pc = 0x1677B8u;
label_1677b8:
    // 0x1677b8: 0x2ae30009  slti        $v1, $s7, 0x9
    ctx->pc = 0x1677b8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 23) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0x1677bc: 0xaea2000c  sw          $v0, 0xC($s5)
    ctx->pc = 0x1677bcu;
    WRITE32(ADD32(GPR_U32(ctx, 21), 12), GPR_U32(ctx, 2));
    // 0x1677c0: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1677C0u;
    {
        const bool branch_taken_0x1677c0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1677C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1677C0u;
            // 0x1677c4: 0x3d61021  addu        $v0, $fp, $s6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 22)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1677c0) {
            ctx->pc = 0x1677D0u;
            goto label_1677d0;
        }
    }
    ctx->pc = 0x1677C8u;
    // 0x1677c8: 0x161040  sll         $v0, $s6, 1
    ctx->pc = 0x1677c8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 22), 1));
    // 0x1677cc: 0x3c21021  addu        $v0, $fp, $v0
    ctx->pc = 0x1677ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 2)));
label_1677d0:
    // 0x1677d0: 0xaea20014  sw          $v0, 0x14($s5)
    ctx->pc = 0x1677d0u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 20), GPR_U32(ctx, 2));
    // 0x1677d4: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1677D4u;
    {
        const bool branch_taken_0x1677d4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1677D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1677D4u;
            // 0x1677d8: 0xb61021  addu        $v0, $a1, $s6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 22)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1677d4) {
            ctx->pc = 0x1677E4u;
            goto label_1677e4;
        }
    }
    ctx->pc = 0x1677DCu;
    // 0x1677dc: 0x161040  sll         $v0, $s6, 1
    ctx->pc = 0x1677dcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 22), 1));
    // 0x1677e0: 0xa21021  addu        $v0, $a1, $v0
    ctx->pc = 0x1677e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
label_1677e4:
    // 0x1677e4: 0xaea50020  sw          $a1, 0x20($s5)
    ctx->pc = 0x1677e4u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 32), GPR_U32(ctx, 5));
    // 0x1677e8: 0xaea20018  sw          $v0, 0x18($s5)
    ctx->pc = 0x1677e8u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 24), GPR_U32(ctx, 2));
    // 0x1677ec: 0xaeb00010  sw          $s0, 0x10($s5)
    ctx->pc = 0x1677ecu;
    WRITE32(ADD32(GPR_U32(ctx, 21), 16), GPR_U32(ctx, 16));
    // 0x1677f0: 0xaebe001c  sw          $fp, 0x1C($s5)
    ctx->pc = 0x1677f0u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 28), GPR_U32(ctx, 30));
label_1677f4:
    // 0x1677f4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1677f4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1677f8: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x1677f8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_1677fc:
    // 0x1677fc: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x1677fcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x167800: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x167800u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x167804: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x167804u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x167808: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x167808u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x16780c: 0xdfb50048  ld          $s5, 0x48($sp)
    ctx->pc = 0x16780cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x167810: 0xdfb60050  ld          $s6, 0x50($sp)
    ctx->pc = 0x167810u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x167814: 0xdfb70058  ld          $s7, 0x58($sp)
    ctx->pc = 0x167814u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x167818: 0xdfbe0060  ld          $fp, 0x60($sp)
    ctx->pc = 0x167818u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x16781c: 0xdfbf0068  ld          $ra, 0x68($sp)
    ctx->pc = 0x16781cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x167820: 0x3e00008  jr          $ra
    ctx->pc = 0x167820u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x167824u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167820u;
            // 0x167824: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1676E0u: goto label_1676e0;
            case 0x1676E8u: goto label_1676e8;
            case 0x1676F4u: goto label_1676f4;
            case 0x16772Cu: goto label_16772c;
            case 0x167768u: goto label_167768;
            case 0x167790u: goto label_167790;
            case 0x1677A4u: goto label_1677a4;
            case 0x1677ACu: goto label_1677ac;
            case 0x1677B8u: goto label_1677b8;
            case 0x1677D0u: goto label_1677d0;
            case 0x1677E4u: goto label_1677e4;
            case 0x1677F4u: goto label_1677f4;
            case 0x1677FCu: goto label_1677fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x167828u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
