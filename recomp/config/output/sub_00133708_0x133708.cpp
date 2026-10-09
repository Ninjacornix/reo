#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00133708
// Address: 0x133708 - 0x133870
void sub_00133708_0x133708(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00133708_0x133708");
#endif

    switch (ctx->pc) {
        case 0x133770u: goto label_133770;
        case 0x1337b4u: goto label_1337b4;
        case 0x1337f0u: goto label_1337f0;
        case 0x133804u: goto label_133804;
        case 0x133830u: goto label_133830;
        default: break;
    }

    ctx->pc = 0x133708u;

    // 0x133708: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x133708u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x13370c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13370cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x133710: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x133710u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133714: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x133714u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x133718: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x133718u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13371c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13371cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x133720: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x133720u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133724: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x133724u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x133728: 0x12400005  beqz        $s2, . + 4 + (0x5 << 2)
    ctx->pc = 0x133728u;
    {
        const bool branch_taken_0x133728 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x13372Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133728u;
            // 0x13372c: 0xffbf0020  sd          $ra, 0x20($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x133728) {
            ctx->pc = 0x133740u;
            goto label_133740;
        }
    }
    ctx->pc = 0x133730u;
    // 0x133730: 0x52200004  beql        $s1, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x133730u;
    {
        const bool branch_taken_0x133730 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        if (branch_taken_0x133730) {
            ctx->pc = 0x133734u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x133730u;
            // 0x133734: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x133744u;
            goto label_133744;
        }
    }
    ctx->pc = 0x133738u;
    // 0x133738: 0x601000b  bgez        $s0, . + 4 + (0xB << 2)
    ctx->pc = 0x133738u;
    {
        const bool branch_taken_0x133738 = (GPR_S64(ctx, 16) >= 0);
        if (branch_taken_0x133738) {
            ctx->pc = 0x133768u;
            goto label_133768;
        }
    }
    ctx->pc = 0x133740u;
label_133740:
    // 0x133740: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x133740u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
label_133744:
    // 0x133744: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x133744u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x133748: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x133748u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13374c: 0x2484b660  addiu       $a0, $a0, -0x49A0
    ctx->pc = 0x13374cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948448));
    // 0x133750: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x133750u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x133754: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x133754u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x133758: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x133758u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13375c: 0x804a034  j           func_1280D0
    ctx->pc = 0x13375Cu;
    ctx->pc = 0x133760u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13375Cu;
            // 0x133760: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x133764u;
    // 0x133764: 0x0  nop
    ctx->pc = 0x133764u;
    // NOP
label_133768:
    // 0x133768: 0xc04c78e  jal         func_131E38
    ctx->pc = 0x133768u;
    SET_GPR_U32(ctx, 31, 0x133770u);
    ctx->pc = 0x13376Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133768u;
            // 0x13376c: 0x3c1300ff  lui         $s3, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)255 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x131E38u;
    if (runtime->hasFunction(0x131E38u)) {
        auto targetFn = runtime->lookupFunction(0x131E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133770u; }
        if (ctx->pc != 0x133770u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131E38_0x131e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133770u; }
        if (ctx->pc != 0x133770u) { return; }
    }
    ctx->pc = 0x133770u;
label_133770:
    // 0x133770: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x133770u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x133774: 0x32a03  sra         $a1, $v1, 8
    ctx->pc = 0x133774u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 3), 8));
    // 0x133778: 0x32200  sll         $a0, $v1, 8
    ctx->pc = 0x133778u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x13377c: 0x31602  srl         $v0, $v1, 24
    ctx->pc = 0x13377cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 24));
    // 0x133780: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x133780u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x133784: 0x932024  and         $a0, $a0, $s3
    ctx->pc = 0x133784u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 19));
    // 0x133788: 0x30a5ff00  andi        $a1, $a1, 0xFF00
    ctx->pc = 0x133788u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65280);
    // 0x13378c: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x13378cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x133790: 0x852025  or          $a0, $a0, $a1
    ctx->pc = 0x133790u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 5));
    // 0x133794: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x133794u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x133798: 0x202102a  slt         $v0, $s0, $v0
    ctx->pc = 0x133798u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x13379c: 0x5040002e  beql        $v0, $zero, . + 4 + (0x2E << 2)
    ctx->pc = 0x13379Cu;
    {
        const bool branch_taken_0x13379c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x13379c) {
            ctx->pc = 0x1337A0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13379Cu;
            // 0x1337a0: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x133858u;
            goto label_133858;
        }
    }
    ctx->pc = 0x1337A4u;
    // 0x1337a4: 0x602002c  bltzl       $s0, . + 4 + (0x2C << 2)
    ctx->pc = 0x1337A4u;
    {
        const bool branch_taken_0x1337a4 = (GPR_S64(ctx, 16) < 0);
        if (branch_taken_0x1337a4) {
            ctx->pc = 0x1337A8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1337A4u;
            // 0x1337a8: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x133858u;
            goto label_133858;
        }
    }
    ctx->pc = 0x1337ACu;
    // 0x1337ac: 0xc049938  jal         func_1264E0
    ctx->pc = 0x1337ACu;
    SET_GPR_U32(ctx, 31, 0x1337B4u);
    ctx->pc = 0x1264E0u;
    if (runtime->hasFunction(0x1264E0u)) {
        auto targetFn = runtime->lookupFunction(0x1264E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1337B4u; }
        if (ctx->pc != 0x1337B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264E0_0x1264e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1337B4u; }
        if (ctx->pc != 0x1337B4u) { return; }
    }
    ctx->pc = 0x1337B4u;
label_1337b4:
    // 0x1337b4: 0x3c054000  lui         $a1, 0x4000
    ctx->pc = 0x1337b4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)16384 << 16));
    // 0x1337b8: 0x1010c0  sll         $v0, $s0, 3
    ctx->pc = 0x1337b8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 3));
    // 0x1337bc: 0x511021  addu        $v0, $v0, $s1
    ctx->pc = 0x1337bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x1337c0: 0x8c430008  lw          $v1, 0x8($v0)
    ctx->pc = 0x1337c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1337c4: 0x33203  sra         $a2, $v1, 8
    ctx->pc = 0x1337c4u;
    SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 3), 8));
    // 0x1337c8: 0x31200  sll         $v0, $v1, 8
    ctx->pc = 0x1337c8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x1337cc: 0x30c6ff00  andi        $a2, $a2, 0xFF00
    ctx->pc = 0x1337ccu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)65280);
    // 0x1337d0: 0x32602  srl         $a0, $v1, 24
    ctx->pc = 0x1337d0u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 3), 24));
    // 0x1337d4: 0x531024  and         $v0, $v0, $s3
    ctx->pc = 0x1337d4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 19));
    // 0x1337d8: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x1337d8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x1337dc: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x1337dcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1337e0: 0x461025  or          $v0, $v0, $a2
    ctx->pc = 0x1337e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 6));
    // 0x1337e4: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1337e4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1337e8: 0xc04fcd8  jal         func_13F360
    ctx->pc = 0x1337E8u;
    SET_GPR_U32(ctx, 31, 0x1337F0u);
    ctx->pc = 0x1337ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1337E8u;
            // 0x1337ec: 0x2242021  addu        $a0, $s1, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F360u;
    if (runtime->hasFunction(0x13F360u)) {
        auto targetFn = runtime->lookupFunction(0x13F360u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1337F0u; }
        if (ctx->pc != 0x1337F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F360_0x13f360(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1337F0u; }
        if (ctx->pc != 0x1337F0u) { return; }
    }
    ctx->pc = 0x1337F0u;
label_1337f0:
    // 0x1337f0: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1337f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1337f4: 0x1440000c  bnez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1337F4u;
    {
        const bool branch_taken_0x1337f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1337F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1337F4u;
            // 0x1337f8: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1337f4) {
            ctx->pc = 0x133828u;
            goto label_133828;
        }
    }
    ctx->pc = 0x1337FCu;
    // 0x1337fc: 0xc04993e  jal         func_1264F8
    ctx->pc = 0x1337FCu;
    SET_GPR_U32(ctx, 31, 0x133804u);
    ctx->pc = 0x1264F8u;
    if (runtime->hasFunction(0x1264F8u)) {
        auto targetFn = runtime->lookupFunction(0x1264F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133804u; }
        if (ctx->pc != 0x133804u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264F8_0x1264f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133804u; }
        if (ctx->pc != 0x133804u) { return; }
    }
    ctx->pc = 0x133804u;
label_133804:
    // 0x133804: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x133804u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x133808: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x133808u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13380c: 0x2484b690  addiu       $a0, $a0, -0x4970
    ctx->pc = 0x13380cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948496));
    // 0x133810: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x133810u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x133814: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x133814u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x133818: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x133818u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13381c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x13381cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x133820: 0x804a034  j           func_1280D0
    ctx->pc = 0x133820u;
    ctx->pc = 0x133824u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133820u;
            // 0x133824: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x133828u;
label_133828:
    // 0x133828: 0xc04c6d8  jal         func_131B60
    ctx->pc = 0x133828u;
    SET_GPR_U32(ctx, 31, 0x133830u);
    ctx->pc = 0x131B60u;
    if (runtime->hasFunction(0x131B60u)) {
        auto targetFn = runtime->lookupFunction(0x131B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133830u; }
        if (ctx->pc != 0x133830u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131B60_0x131b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133830u; }
        if (ctx->pc != 0x133830u) { return; }
    }
    ctx->pc = 0x133830u;
label_133830:
    // 0x133830: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x133830u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x133834: 0xa2420002  sb          $v0, 0x2($s2)
    ctx->pc = 0x133834u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 2), (uint8_t)GPR_U32(ctx, 2));
    // 0x133838: 0xa2400098  sb          $zero, 0x98($s2)
    ctx->pc = 0x133838u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 152), (uint8_t)GPR_U32(ctx, 0));
    // 0x13383c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13383cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x133840: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x133840u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x133844: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x133844u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x133848: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x133848u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13384c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x13384cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x133850: 0x804993e  j           func_1264F8
    ctx->pc = 0x133850u;
    ctx->pc = 0x133854u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133850u;
            // 0x133854: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1264F8u;
    if (runtime->hasFunction(0x1264F8u)) {
        auto targetFn = runtime->lookupFunction(0x1264F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001264F8_0x1264f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x133858u;
label_133858:
    // 0x133858: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x133858u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13385c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13385cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x133860: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x133860u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x133864: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x133864u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x133868: 0x3e00008  jr          $ra
    ctx->pc = 0x133868u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13386Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133868u;
            // 0x13386c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x133740u: goto label_133740;
            case 0x133744u: goto label_133744;
            case 0x133768u: goto label_133768;
            case 0x133770u: goto label_133770;
            case 0x1337B4u: goto label_1337b4;
            case 0x1337F0u: goto label_1337f0;
            case 0x133804u: goto label_133804;
            case 0x133828u: goto label_133828;
            case 0x133830u: goto label_133830;
            case 0x133858u: goto label_133858;
            default: break;
        }
        return;
    }
    ctx->pc = 0x133870u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
