#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015FC18
// Address: 0x15fc18 - 0x15fe88
void sub_0015FC18_0x15fc18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015FC18_0x15fc18");
#endif

    switch (ctx->pc) {
        case 0x15fc2cu: goto label_15fc2c;
        case 0x15fc40u: goto label_15fc40;
        case 0x15fc50u: goto label_15fc50;
        case 0x15fc5cu: goto label_15fc5c;
        case 0x15fc94u: goto label_15fc94;
        case 0x15fcf4u: goto label_15fcf4;
        case 0x15fd20u: goto label_15fd20;
        case 0x15fd6cu: goto label_15fd6c;
        case 0x15fd84u: goto label_15fd84;
        case 0x15fd98u: goto label_15fd98;
        case 0x15fdccu: goto label_15fdcc;
        case 0x15fdf8u: goto label_15fdf8;
        case 0x15fe44u: goto label_15fe44;
        case 0x15fe5cu: goto label_15fe5c;
        case 0x15fe70u: goto label_15fe70;
        default: break;
    }

    ctx->pc = 0x15fc18u;

    // 0x15fc18: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x15fc18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x15fc1c: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x15fc1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x15fc20: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x15fc20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x15fc24: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x15FC24u;
    SET_GPR_U32(ctx, 31, 0x15FC2Cu);
    ctx->pc = 0x15FC28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FC24u;
            // 0x15fc28: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FC2Cu; }
        if (ctx->pc != 0x15FC2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FC2Cu; }
        if (ctx->pc != 0x15FC2Cu) { return; }
    }
    ctx->pc = 0x15FC2Cu;
label_15fc2c:
    // 0x15fc2c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x15FC2Cu;
    {
        const bool branch_taken_0x15fc2c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15FC30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FC2Cu;
            // 0x15fc30: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15fc2c) {
            ctx->pc = 0x15FC48u;
            goto label_15fc48;
        }
    }
    ctx->pc = 0x15FC34u;
    // 0x15fc34: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15fc34u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15fc38: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15FC38u;
    SET_GPR_U32(ctx, 31, 0x15FC40u);
    ctx->pc = 0x15FC3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FC38u;
            // 0x15fc3c: 0x2484f368  addiu       $a0, $a0, -0xC98 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294964072));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FC40u; }
        if (ctx->pc != 0x15FC40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FC40u; }
        if (ctx->pc != 0x15FC40u) { return; }
    }
    ctx->pc = 0x15FC40u;
label_15fc40:
    // 0x15fc40: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x15FC40u;
    {
        const bool branch_taken_0x15fc40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15FC44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FC40u;
            // 0x15fc44: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15fc40) {
            ctx->pc = 0x15FC68u;
            goto label_15fc68;
        }
    }
    ctx->pc = 0x15FC48u;
label_15fc48:
    // 0x15fc48: 0xc057ec8  jal         func_15FB20
    ctx->pc = 0x15FC48u;
    SET_GPR_U32(ctx, 31, 0x15FC50u);
    ctx->pc = 0x15FB20u;
    if (runtime->hasFunction(0x15FB20u)) {
        auto targetFn = runtime->lookupFunction(0x15FB20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FC50u; }
        if (ctx->pc != 0x15FC50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FB20_0x15fb20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FC50u; }
        if (ctx->pc != 0x15FC50u) { return; }
    }
    ctx->pc = 0x15FC50u;
label_15fc50:
    // 0x15fc50: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x15fc50u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15fc54: 0xc05d5c4  jal         func_175710
    ctx->pc = 0x15FC54u;
    SET_GPR_U32(ctx, 31, 0x15FC5Cu);
    ctx->pc = 0x15FC58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FC54u;
            // 0x15fc58: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175710u;
    if (runtime->hasFunction(0x175710u)) {
        auto targetFn = runtime->lookupFunction(0x175710u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FC5Cu; }
        if (ctx->pc != 0x15FC5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175710_0x175710(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FC5Cu; }
        if (ctx->pc != 0x15FC5Cu) { return; }
    }
    ctx->pc = 0x15FC5Cu;
label_15fc5c:
    // 0x15fc5c: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x15fc5cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x15fc60: 0x8fa20010  lw          $v0, 0x10($sp)
    ctx->pc = 0x15fc60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15fc64: 0x621023  subu        $v0, $v1, $v0
    ctx->pc = 0x15fc64u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_15fc68:
    // 0x15fc68: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x15fc68u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x15fc6c: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x15fc6cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x15fc70: 0x3e00008  jr          $ra
    ctx->pc = 0x15FC70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15FC74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FC70u;
            // 0x15fc74: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15FC2Cu: goto label_15fc2c;
            case 0x15FC40u: goto label_15fc40;
            case 0x15FC48u: goto label_15fc48;
            case 0x15FC50u: goto label_15fc50;
            case 0x15FC5Cu: goto label_15fc5c;
            case 0x15FC68u: goto label_15fc68;
            case 0x15FC94u: goto label_15fc94;
            case 0x15FCC0u: goto label_15fcc0;
            case 0x15FCF4u: goto label_15fcf4;
            case 0x15FD18u: goto label_15fd18;
            case 0x15FD20u: goto label_15fd20;
            case 0x15FD40u: goto label_15fd40;
            case 0x15FD6Cu: goto label_15fd6c;
            case 0x15FD84u: goto label_15fd84;
            case 0x15FD90u: goto label_15fd90;
            case 0x15FD98u: goto label_15fd98;
            case 0x15FD9Cu: goto label_15fd9c;
            case 0x15FDCCu: goto label_15fdcc;
            case 0x15FDF0u: goto label_15fdf0;
            case 0x15FDF8u: goto label_15fdf8;
            case 0x15FE18u: goto label_15fe18;
            case 0x15FE44u: goto label_15fe44;
            case 0x15FE5Cu: goto label_15fe5c;
            case 0x15FE68u: goto label_15fe68;
            case 0x15FE70u: goto label_15fe70;
            case 0x15FE74u: goto label_15fe74;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15FC78u;
    // 0x15fc78: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15fc78u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15fc7c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15fc7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15fc80: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x15fc80u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15fc84: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15fc84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15fc88: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x15fc88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x15fc8c: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x15FC8Cu;
    SET_GPR_U32(ctx, 31, 0x15FC94u);
    ctx->pc = 0x15FC90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FC8Cu;
            // 0x15fc90: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FC94u; }
        if (ctx->pc != 0x15FC94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FC94u; }
        if (ctx->pc != 0x15FC94u) { return; }
    }
    ctx->pc = 0x15FC94u;
label_15fc94:
    // 0x15fc94: 0x3a100001  xori        $s0, $s0, 0x1
    ctx->pc = 0x15fc94u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) ^ (uint64_t)(uint16_t)1);
    // 0x15fc98: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15fc98u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15fc9c: 0x2484f3a0  addiu       $a0, $a0, -0xC60
    ctx->pc = 0x15fc9cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294964128));
    // 0x15fca0: 0x10302b  sltu        $a2, $zero, $s0
    ctx->pc = 0x15fca0u;
    SET_GPR_U64(ctx, 6, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
    // 0x15fca4: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x15FCA4u;
    {
        const bool branch_taken_0x15fca4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15FCA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FCA4u;
            // 0x15fca8: 0x24050004  addiu       $a1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15fca4) {
            ctx->pc = 0x15FCC0u;
            goto label_15fcc0;
        }
    }
    ctx->pc = 0x15FCACu;
    // 0x15fcac: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15fcacu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15fcb0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15fcb0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15fcb4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15fcb4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15fcb8: 0x8058dd4  j           func_163750
    ctx->pc = 0x15FCB8u;
    ctx->pc = 0x15FCBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FCB8u;
            // 0x15fcbc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15FCC0u;
label_15fcc0:
    // 0x15fcc0: 0x8e240040  lw          $a0, 0x40($s1)
    ctx->pc = 0x15fcc0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 64)));
    // 0x15fcc4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15fcc4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15fcc8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15fcc8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15fccc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15fcccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15fcd0: 0x805d4ce  j           func_175338
    ctx->pc = 0x15FCD0u;
    ctx->pc = 0x15FCD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FCD0u;
            // 0x15fcd4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175338u;
    if (runtime->hasFunction(0x175338u)) {
        auto targetFn = runtime->lookupFunction(0x175338u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00175338_0x175338(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15FCD8u;
    // 0x15fcd8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15fcd8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15fcdc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15fcdcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15fce0: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x15fce0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15fce4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15fce4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15fce8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x15fce8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x15fcec: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x15FCECu;
    SET_GPR_U32(ctx, 31, 0x15FCF4u);
    ctx->pc = 0x15FCF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FCECu;
            // 0x15fcf0: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FCF4u; }
        if (ctx->pc != 0x15FCF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FCF4u; }
        if (ctx->pc != 0x15FCF4u) { return; }
    }
    ctx->pc = 0x15FCF4u;
label_15fcf4:
    // 0x15fcf4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15fcf4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15fcf8: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x15fcf8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15fcfc: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x15FCFCu;
    {
        const bool branch_taken_0x15fcfc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15FD00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FCFCu;
            // 0x15fd00: 0x2484f3d0  addiu       $a0, $a0, -0xC30 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294964176));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15fcfc) {
            ctx->pc = 0x15FD18u;
            goto label_15fd18;
        }
    }
    ctx->pc = 0x15FD04u;
    // 0x15fd04: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15fd04u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15fd08: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15fd08u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15fd0c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15fd0cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15fd10: 0x8058dd4  j           func_163750
    ctx->pc = 0x15FD10u;
    ctx->pc = 0x15FD14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FD10u;
            // 0x15fd14: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15FD18u;
label_15fd18:
    // 0x15fd18: 0xc05c8d0  jal         func_172340
    ctx->pc = 0x15FD18u;
    SET_GPR_U32(ctx, 31, 0x15FD20u);
    ctx->pc = 0x15FD1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FD18u;
            // 0x15fd1c: 0x8e240040  lw          $a0, 0x40($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 64)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x172340u;
    if (runtime->hasFunction(0x172340u)) {
        auto targetFn = runtime->lookupFunction(0x172340u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FD20u; }
        if (ctx->pc != 0x15FD20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00172340_0x172340(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FD20u; }
        if (ctx->pc != 0x15FD20u) { return; }
    }
    ctx->pc = 0x15FD20u;
label_15fd20:
    // 0x15fd20: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15fd20u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15fd24: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x15FD24u;
    {
        const bool branch_taken_0x15fd24 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15FD28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FD24u;
            // 0x15fd28: 0x2484f400  addiu       $a0, $a0, -0xC00 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294964224));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15fd24) {
            ctx->pc = 0x15FD40u;
            goto label_15fd40;
        }
    }
    ctx->pc = 0x15FD2Cu;
    // 0x15fd2c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15fd2cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15fd30: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15fd30u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15fd34: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15fd34u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15fd38: 0x8058dd4  j           func_163750
    ctx->pc = 0x15FD38u;
    ctx->pc = 0x15FD3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FD38u;
            // 0x15fd3c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15FD40u;
label_15fd40:
    // 0x15fd40: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15fd40u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15fd44: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15fd44u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15fd48: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15fd48u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15fd4c: 0x3e00008  jr          $ra
    ctx->pc = 0x15FD4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15FD50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FD4Cu;
            // 0x15fd50: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15FC2Cu: goto label_15fc2c;
            case 0x15FC40u: goto label_15fc40;
            case 0x15FC48u: goto label_15fc48;
            case 0x15FC50u: goto label_15fc50;
            case 0x15FC5Cu: goto label_15fc5c;
            case 0x15FC68u: goto label_15fc68;
            case 0x15FC94u: goto label_15fc94;
            case 0x15FCC0u: goto label_15fcc0;
            case 0x15FCF4u: goto label_15fcf4;
            case 0x15FD18u: goto label_15fd18;
            case 0x15FD20u: goto label_15fd20;
            case 0x15FD40u: goto label_15fd40;
            case 0x15FD6Cu: goto label_15fd6c;
            case 0x15FD84u: goto label_15fd84;
            case 0x15FD90u: goto label_15fd90;
            case 0x15FD98u: goto label_15fd98;
            case 0x15FD9Cu: goto label_15fd9c;
            case 0x15FDCCu: goto label_15fdcc;
            case 0x15FDF0u: goto label_15fdf0;
            case 0x15FDF8u: goto label_15fdf8;
            case 0x15FE18u: goto label_15fe18;
            case 0x15FE44u: goto label_15fe44;
            case 0x15FE5Cu: goto label_15fe5c;
            case 0x15FE68u: goto label_15fe68;
            case 0x15FE70u: goto label_15fe70;
            case 0x15FE74u: goto label_15fe74;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15FD54u;
    // 0x15fd54: 0x0  nop
    ctx->pc = 0x15fd54u;
    // NOP
    // 0x15fd58: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x15fd58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x15fd5c: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x15fd5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x15fd60: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x15fd60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x15fd64: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x15FD64u;
    SET_GPR_U32(ctx, 31, 0x15FD6Cu);
    ctx->pc = 0x15FD68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FD64u;
            // 0x15fd68: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FD6Cu; }
        if (ctx->pc != 0x15FD6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FD6Cu; }
        if (ctx->pc != 0x15FD6Cu) { return; }
    }
    ctx->pc = 0x15FD6Cu;
label_15fd6c:
    // 0x15fd6c: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x15fd6cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15fd70: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x15FD70u;
    {
        const bool branch_taken_0x15fd70 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15FD74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FD70u;
            // 0x15fd74: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15fd70) {
            ctx->pc = 0x15FD90u;
            goto label_15fd90;
        }
    }
    ctx->pc = 0x15FD78u;
    // 0x15fd78: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15fd78u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15fd7c: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15FD7Cu;
    SET_GPR_U32(ctx, 31, 0x15FD84u);
    ctx->pc = 0x15FD80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FD7Cu;
            // 0x15fd80: 0x2484f428  addiu       $a0, $a0, -0xBD8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294964264));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FD84u; }
        if (ctx->pc != 0x15FD84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FD84u; }
        if (ctx->pc != 0x15FD84u) { return; }
    }
    ctx->pc = 0x15FD84u;
label_15fd84:
    // 0x15fd84: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x15FD84u;
    {
        const bool branch_taken_0x15fd84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15FD88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FD84u;
            // 0x15fd88: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15fd84) {
            ctx->pc = 0x15FD9Cu;
            goto label_15fd9c;
        }
    }
    ctx->pc = 0x15FD8Cu;
    // 0x15fd8c: 0x0  nop
    ctx->pc = 0x15fd8cu;
    // NOP
label_15fd90:
    // 0x15fd90: 0xc057fa8  jal         func_15FEA0
    ctx->pc = 0x15FD90u;
    SET_GPR_U32(ctx, 31, 0x15FD98u);
    ctx->pc = 0x15FEA0u;
    if (runtime->hasFunction(0x15FEA0u)) {
        auto targetFn = runtime->lookupFunction(0x15FEA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FD98u; }
        if (ctx->pc != 0x15FD98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FEA0_0x15fea0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FD98u; }
        if (ctx->pc != 0x15FD98u) { return; }
    }
    ctx->pc = 0x15FD98u;
label_15fd98:
    // 0x15fd98: 0x8fa20024  lw          $v0, 0x24($sp)
    ctx->pc = 0x15fd98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
label_15fd9c:
    // 0x15fd9c: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x15fd9cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x15fda0: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x15fda0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x15fda4: 0x3e00008  jr          $ra
    ctx->pc = 0x15FDA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15FDA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FDA4u;
            // 0x15fda8: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15FC2Cu: goto label_15fc2c;
            case 0x15FC40u: goto label_15fc40;
            case 0x15FC48u: goto label_15fc48;
            case 0x15FC50u: goto label_15fc50;
            case 0x15FC5Cu: goto label_15fc5c;
            case 0x15FC68u: goto label_15fc68;
            case 0x15FC94u: goto label_15fc94;
            case 0x15FCC0u: goto label_15fcc0;
            case 0x15FCF4u: goto label_15fcf4;
            case 0x15FD18u: goto label_15fd18;
            case 0x15FD20u: goto label_15fd20;
            case 0x15FD40u: goto label_15fd40;
            case 0x15FD6Cu: goto label_15fd6c;
            case 0x15FD84u: goto label_15fd84;
            case 0x15FD90u: goto label_15fd90;
            case 0x15FD98u: goto label_15fd98;
            case 0x15FD9Cu: goto label_15fd9c;
            case 0x15FDCCu: goto label_15fdcc;
            case 0x15FDF0u: goto label_15fdf0;
            case 0x15FDF8u: goto label_15fdf8;
            case 0x15FE18u: goto label_15fe18;
            case 0x15FE44u: goto label_15fe44;
            case 0x15FE5Cu: goto label_15fe5c;
            case 0x15FE68u: goto label_15fe68;
            case 0x15FE70u: goto label_15fe70;
            case 0x15FE74u: goto label_15fe74;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15FDACu;
    // 0x15fdac: 0x0  nop
    ctx->pc = 0x15fdacu;
    // NOP
    // 0x15fdb0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15fdb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15fdb4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15fdb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15fdb8: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x15fdb8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15fdbc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15fdbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15fdc0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x15fdc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x15fdc4: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x15FDC4u;
    SET_GPR_U32(ctx, 31, 0x15FDCCu);
    ctx->pc = 0x15FDC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FDC4u;
            // 0x15fdc8: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FDCCu; }
        if (ctx->pc != 0x15FDCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FDCCu; }
        if (ctx->pc != 0x15FDCCu) { return; }
    }
    ctx->pc = 0x15FDCCu;
label_15fdcc:
    // 0x15fdcc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15fdccu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15fdd0: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x15fdd0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15fdd4: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x15FDD4u;
    {
        const bool branch_taken_0x15fdd4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15FDD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FDD4u;
            // 0x15fdd8: 0x2484f458  addiu       $a0, $a0, -0xBA8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294964312));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15fdd4) {
            ctx->pc = 0x15FDF0u;
            goto label_15fdf0;
        }
    }
    ctx->pc = 0x15FDDCu;
    // 0x15fddc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15fddcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15fde0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15fde0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15fde4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15fde4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15fde8: 0x8058dd4  j           func_163750
    ctx->pc = 0x15FDE8u;
    ctx->pc = 0x15FDECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FDE8u;
            // 0x15fdec: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15FDF0u;
label_15fdf0:
    // 0x15fdf0: 0xc05c8ec  jal         func_1723B0
    ctx->pc = 0x15FDF0u;
    SET_GPR_U32(ctx, 31, 0x15FDF8u);
    ctx->pc = 0x15FDF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FDF0u;
            // 0x15fdf4: 0x8e240040  lw          $a0, 0x40($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 64)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1723B0u;
    if (runtime->hasFunction(0x1723B0u)) {
        auto targetFn = runtime->lookupFunction(0x1723B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FDF8u; }
        if (ctx->pc != 0x15FDF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001723B0_0x1723b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FDF8u; }
        if (ctx->pc != 0x15FDF8u) { return; }
    }
    ctx->pc = 0x15FDF8u;
label_15fdf8:
    // 0x15fdf8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15fdf8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15fdfc: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x15FDFCu;
    {
        const bool branch_taken_0x15fdfc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15FE00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FDFCu;
            // 0x15fe00: 0x2484f488  addiu       $a0, $a0, -0xB78 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294964360));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15fdfc) {
            ctx->pc = 0x15FE18u;
            goto label_15fe18;
        }
    }
    ctx->pc = 0x15FE04u;
    // 0x15fe04: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15fe04u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15fe08: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15fe08u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15fe0c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15fe0cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15fe10: 0x8058dd4  j           func_163750
    ctx->pc = 0x15FE10u;
    ctx->pc = 0x15FE14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FE10u;
            // 0x15fe14: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15FE18u;
label_15fe18:
    // 0x15fe18: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15fe18u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15fe1c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15fe1cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15fe20: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15fe20u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15fe24: 0x3e00008  jr          $ra
    ctx->pc = 0x15FE24u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15FE28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FE24u;
            // 0x15fe28: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15FC2Cu: goto label_15fc2c;
            case 0x15FC40u: goto label_15fc40;
            case 0x15FC48u: goto label_15fc48;
            case 0x15FC50u: goto label_15fc50;
            case 0x15FC5Cu: goto label_15fc5c;
            case 0x15FC68u: goto label_15fc68;
            case 0x15FC94u: goto label_15fc94;
            case 0x15FCC0u: goto label_15fcc0;
            case 0x15FCF4u: goto label_15fcf4;
            case 0x15FD18u: goto label_15fd18;
            case 0x15FD20u: goto label_15fd20;
            case 0x15FD40u: goto label_15fd40;
            case 0x15FD6Cu: goto label_15fd6c;
            case 0x15FD84u: goto label_15fd84;
            case 0x15FD90u: goto label_15fd90;
            case 0x15FD98u: goto label_15fd98;
            case 0x15FD9Cu: goto label_15fd9c;
            case 0x15FDCCu: goto label_15fdcc;
            case 0x15FDF0u: goto label_15fdf0;
            case 0x15FDF8u: goto label_15fdf8;
            case 0x15FE18u: goto label_15fe18;
            case 0x15FE44u: goto label_15fe44;
            case 0x15FE5Cu: goto label_15fe5c;
            case 0x15FE68u: goto label_15fe68;
            case 0x15FE70u: goto label_15fe70;
            case 0x15FE74u: goto label_15fe74;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15FE2Cu;
    // 0x15fe2c: 0x0  nop
    ctx->pc = 0x15fe2cu;
    // NOP
    // 0x15fe30: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x15fe30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x15fe34: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x15fe34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x15fe38: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x15fe38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x15fe3c: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x15FE3Cu;
    SET_GPR_U32(ctx, 31, 0x15FE44u);
    ctx->pc = 0x15FE40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FE3Cu;
            // 0x15fe40: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FE44u; }
        if (ctx->pc != 0x15FE44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FE44u; }
        if (ctx->pc != 0x15FE44u) { return; }
    }
    ctx->pc = 0x15FE44u;
label_15fe44:
    // 0x15fe44: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x15fe44u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15fe48: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x15FE48u;
    {
        const bool branch_taken_0x15fe48 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15FE4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FE48u;
            // 0x15fe4c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15fe48) {
            ctx->pc = 0x15FE68u;
            goto label_15fe68;
        }
    }
    ctx->pc = 0x15FE50u;
    // 0x15fe50: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15fe50u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15fe54: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15FE54u;
    SET_GPR_U32(ctx, 31, 0x15FE5Cu);
    ctx->pc = 0x15FE58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FE54u;
            // 0x15fe58: 0x2484f4b8  addiu       $a0, $a0, -0xB48 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294964408));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FE5Cu; }
        if (ctx->pc != 0x15FE5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FE5Cu; }
        if (ctx->pc != 0x15FE5Cu) { return; }
    }
    ctx->pc = 0x15FE5Cu;
label_15fe5c:
    // 0x15fe5c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x15FE5Cu;
    {
        const bool branch_taken_0x15fe5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15FE60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FE5Cu;
            // 0x15fe60: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15fe5c) {
            ctx->pc = 0x15FE74u;
            goto label_15fe74;
        }
    }
    ctx->pc = 0x15FE64u;
    // 0x15fe64: 0x0  nop
    ctx->pc = 0x15fe64u;
    // NOP
label_15fe68:
    // 0x15fe68: 0xc057fa8  jal         func_15FEA0
    ctx->pc = 0x15FE68u;
    SET_GPR_U32(ctx, 31, 0x15FE70u);
    ctx->pc = 0x15FEA0u;
    if (runtime->hasFunction(0x15FEA0u)) {
        auto targetFn = runtime->lookupFunction(0x15FEA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FE70u; }
        if (ctx->pc != 0x15FE70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FEA0_0x15fea0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FE70u; }
        if (ctx->pc != 0x15FE70u) { return; }
    }
    ctx->pc = 0x15FE70u;
label_15fe70:
    // 0x15fe70: 0x8fa20028  lw          $v0, 0x28($sp)
    ctx->pc = 0x15fe70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
label_15fe74:
    // 0x15fe74: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x15fe74u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x15fe78: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x15fe78u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x15fe7c: 0x3e00008  jr          $ra
    ctx->pc = 0x15FE7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15FE80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FE7Cu;
            // 0x15fe80: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15FC2Cu: goto label_15fc2c;
            case 0x15FC40u: goto label_15fc40;
            case 0x15FC48u: goto label_15fc48;
            case 0x15FC50u: goto label_15fc50;
            case 0x15FC5Cu: goto label_15fc5c;
            case 0x15FC68u: goto label_15fc68;
            case 0x15FC94u: goto label_15fc94;
            case 0x15FCC0u: goto label_15fcc0;
            case 0x15FCF4u: goto label_15fcf4;
            case 0x15FD18u: goto label_15fd18;
            case 0x15FD20u: goto label_15fd20;
            case 0x15FD40u: goto label_15fd40;
            case 0x15FD6Cu: goto label_15fd6c;
            case 0x15FD84u: goto label_15fd84;
            case 0x15FD90u: goto label_15fd90;
            case 0x15FD98u: goto label_15fd98;
            case 0x15FD9Cu: goto label_15fd9c;
            case 0x15FDCCu: goto label_15fdcc;
            case 0x15FDF0u: goto label_15fdf0;
            case 0x15FDF8u: goto label_15fdf8;
            case 0x15FE18u: goto label_15fe18;
            case 0x15FE44u: goto label_15fe44;
            case 0x15FE5Cu: goto label_15fe5c;
            case 0x15FE68u: goto label_15fe68;
            case 0x15FE70u: goto label_15fe70;
            case 0x15FE74u: goto label_15fe74;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15FE84u;
    // 0x15fe84: 0x0  nop
    ctx->pc = 0x15fe84u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
