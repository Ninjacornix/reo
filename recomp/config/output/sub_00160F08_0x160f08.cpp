#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00160F08
// Address: 0x160f08 - 0x1614e8
void sub_00160F08_0x160f08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00160F08_0x160f08");
#endif

    switch (ctx->pc) {
        case 0x160f40u: goto label_160f40;
        case 0x160fb0u: goto label_160fb0;
        case 0x160fc4u: goto label_160fc4;
        case 0x160fe0u: goto label_160fe0;
        case 0x160ff0u: goto label_160ff0;
        case 0x161004u: goto label_161004;
        case 0x161014u: goto label_161014;
        case 0x161058u: goto label_161058;
        case 0x16106cu: goto label_16106c;
        case 0x161088u: goto label_161088;
        case 0x161098u: goto label_161098;
        case 0x1610acu: goto label_1610ac;
        case 0x1610bcu: goto label_1610bc;
        case 0x161108u: goto label_161108;
        case 0x16111cu: goto label_16111c;
        case 0x16113cu: goto label_16113c;
        case 0x161150u: goto label_161150;
        case 0x161164u: goto label_161164;
        case 0x161178u: goto label_161178;
        case 0x1611c0u: goto label_1611c0;
        case 0x1611d4u: goto label_1611d4;
        case 0x1611f0u: goto label_1611f0;
        case 0x161200u: goto label_161200;
        case 0x161214u: goto label_161214;
        case 0x161224u: goto label_161224;
        case 0x161268u: goto label_161268;
        case 0x16127cu: goto label_16127c;
        case 0x161298u: goto label_161298;
        case 0x1612a8u: goto label_1612a8;
        case 0x1612bcu: goto label_1612bc;
        case 0x1612ccu: goto label_1612cc;
        case 0x161310u: goto label_161310;
        case 0x161324u: goto label_161324;
        case 0x161340u: goto label_161340;
        case 0x161350u: goto label_161350;
        case 0x161364u: goto label_161364;
        case 0x161374u: goto label_161374;
        case 0x1613b8u: goto label_1613b8;
        case 0x1613ccu: goto label_1613cc;
        case 0x1613e8u: goto label_1613e8;
        case 0x1613f8u: goto label_1613f8;
        case 0x16140cu: goto label_16140c;
        case 0x16141cu: goto label_16141c;
        case 0x161454u: goto label_161454;
        default: break;
    }

    ctx->pc = 0x160f08u;

    // 0x160f08: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x160f08u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x160f0c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x160f0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x160f10: 0x24100001  addiu       $s0, $zero, 0x1
    ctx->pc = 0x160f10u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x160f14: 0x10800006  beqz        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x160F14u;
    {
        const bool branch_taken_0x160f14 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x160F18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160F14u;
            // 0x160f18: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160f14) {
            ctx->pc = 0x160F30u;
            goto label_160f30;
        }
    }
    ctx->pc = 0x160F1Cu;
    // 0x160f1c: 0x10900009  beq         $a0, $s0, . + 4 + (0x9 << 2)
    ctx->pc = 0x160F1Cu;
    {
        const bool branch_taken_0x160f1c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 16));
        ctx->pc = 0x160F20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160F1Cu;
            // 0x160f20: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160f1c) {
            ctx->pc = 0x160F44u;
            goto label_160f44;
        }
    }
    ctx->pc = 0x160F24u;
    // 0x160f24: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x160F24u;
    {
        const bool branch_taken_0x160f24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x160F28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160F24u;
            // 0x160f28: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160f24) {
            ctx->pc = 0x160F38u;
            goto label_160f38;
        }
    }
    ctx->pc = 0x160F2Cu;
    // 0x160f2c: 0x0  nop
    ctx->pc = 0x160f2cu;
    // NOP
label_160f30:
    // 0x160f30: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x160F30u;
    {
        const bool branch_taken_0x160f30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x160F34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160F30u;
            // 0x160f34: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160f30) {
            ctx->pc = 0x160F40u;
            goto label_160f40;
        }
    }
    ctx->pc = 0x160F38u;
label_160f38:
    // 0x160f38: 0xc058dd4  jal         func_163750
    ctx->pc = 0x160F38u;
    SET_GPR_U32(ctx, 31, 0x160F40u);
    ctx->pc = 0x160F3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160F38u;
            // 0x160f3c: 0x2484f920  addiu       $a0, $a0, -0x6E0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294965536));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160F40u; }
        if (ctx->pc != 0x160F40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160F40u; }
        if (ctx->pc != 0x160F40u) { return; }
    }
    ctx->pc = 0x160F40u;
label_160f40:
    // 0x160f40: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x160f40u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_160f44:
    // 0x160f44: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x160f44u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160f48: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x160f48u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x160f4c: 0x3e00008  jr          $ra
    ctx->pc = 0x160F4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x160F50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160F4Cu;
            // 0x160f50: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x160F30u: goto label_160f30;
            case 0x160F38u: goto label_160f38;
            case 0x160F40u: goto label_160f40;
            case 0x160F44u: goto label_160f44;
            case 0x160FB0u: goto label_160fb0;
            case 0x160FC4u: goto label_160fc4;
            case 0x160FD0u: goto label_160fd0;
            case 0x160FE0u: goto label_160fe0;
            case 0x160FE8u: goto label_160fe8;
            case 0x160FF0u: goto label_160ff0;
            case 0x161004u: goto label_161004;
            case 0x161014u: goto label_161014;
            case 0x161018u: goto label_161018;
            case 0x161058u: goto label_161058;
            case 0x16106Cu: goto label_16106c;
            case 0x161078u: goto label_161078;
            case 0x161088u: goto label_161088;
            case 0x161090u: goto label_161090;
            case 0x161098u: goto label_161098;
            case 0x1610ACu: goto label_1610ac;
            case 0x1610BCu: goto label_1610bc;
            case 0x1610C0u: goto label_1610c0;
            case 0x161108u: goto label_161108;
            case 0x16111Cu: goto label_16111c;
            case 0x161128u: goto label_161128;
            case 0x16113Cu: goto label_16113c;
            case 0x161148u: goto label_161148;
            case 0x161150u: goto label_161150;
            case 0x161164u: goto label_161164;
            case 0x161178u: goto label_161178;
            case 0x16117Cu: goto label_16117c;
            case 0x1611C0u: goto label_1611c0;
            case 0x1611D4u: goto label_1611d4;
            case 0x1611E0u: goto label_1611e0;
            case 0x1611F0u: goto label_1611f0;
            case 0x1611F8u: goto label_1611f8;
            case 0x161200u: goto label_161200;
            case 0x161214u: goto label_161214;
            case 0x161224u: goto label_161224;
            case 0x161228u: goto label_161228;
            case 0x161268u: goto label_161268;
            case 0x16127Cu: goto label_16127c;
            case 0x161288u: goto label_161288;
            case 0x161298u: goto label_161298;
            case 0x1612A0u: goto label_1612a0;
            case 0x1612A8u: goto label_1612a8;
            case 0x1612BCu: goto label_1612bc;
            case 0x1612CCu: goto label_1612cc;
            case 0x1612D0u: goto label_1612d0;
            case 0x161310u: goto label_161310;
            case 0x161324u: goto label_161324;
            case 0x161330u: goto label_161330;
            case 0x161340u: goto label_161340;
            case 0x161348u: goto label_161348;
            case 0x161350u: goto label_161350;
            case 0x161364u: goto label_161364;
            case 0x161374u: goto label_161374;
            case 0x161378u: goto label_161378;
            case 0x1613B8u: goto label_1613b8;
            case 0x1613CCu: goto label_1613cc;
            case 0x1613D8u: goto label_1613d8;
            case 0x1613E8u: goto label_1613e8;
            case 0x1613F0u: goto label_1613f0;
            case 0x1613F8u: goto label_1613f8;
            case 0x16140Cu: goto label_16140c;
            case 0x16141Cu: goto label_16141c;
            case 0x161420u: goto label_161420;
            case 0x161454u: goto label_161454;
            case 0x161478u: goto label_161478;
            case 0x1614A8u: goto label_1614a8;
            case 0x1614D0u: goto label_1614d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x160F54u;
    // 0x160f54: 0x0  nop
    ctx->pc = 0x160f54u;
    // NOP
    // 0x160f58: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x160f58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x160f5c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x160f5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x160f60: 0x8c8400a8  lw          $a0, 0xA8($a0)
    ctx->pc = 0x160f60u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 168)));
    // 0x160f64: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x160f64u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160f68: 0x805f4a2  j           func_17D288
    ctx->pc = 0x160F68u;
    ctx->pc = 0x160F6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160F68u;
            // 0x160f6c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D288u;
    if (runtime->hasFunction(0x17D288u)) {
        auto targetFn = runtime->lookupFunction(0x17D288u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D288_0x17d288(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x160F70u;
    // 0x160f70: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x160f70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x160f74: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x160f74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x160f78: 0x8c8400a8  lw          $a0, 0xA8($a0)
    ctx->pc = 0x160f78u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 168)));
    // 0x160f7c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x160f7cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160f80: 0x805f4b6  j           func_17D2D8
    ctx->pc = 0x160F80u;
    ctx->pc = 0x160F84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160F80u;
            // 0x160f84: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D2D8u;
    if (runtime->hasFunction(0x17D2D8u)) {
        auto targetFn = runtime->lookupFunction(0x17D2D8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D2D8_0x17d2d8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x160F88u;
    // 0x160f88: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x160f88u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x160f8c: 0xffb10098  sd          $s1, 0x98($sp)
    ctx->pc = 0x160f8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 17));
    // 0x160f90: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x160f90u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160f94: 0xffb200a0  sd          $s2, 0xA0($sp)
    ctx->pc = 0x160f94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 18));
    // 0x160f98: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x160f98u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160f9c: 0xffb300a8  sd          $s3, 0xA8($sp)
    ctx->pc = 0x160f9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 168), GPR_U64(ctx, 19));
    // 0x160fa0: 0xffb00090  sd          $s0, 0x90($sp)
    ctx->pc = 0x160fa0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 16));
    // 0x160fa4: 0xffbf00b0  sd          $ra, 0xB0($sp)
    ctx->pc = 0x160fa4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 31));
    // 0x160fa8: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x160FA8u;
    SET_GPR_U32(ctx, 31, 0x160FB0u);
    ctx->pc = 0x160FACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160FA8u;
            // 0x160fac: 0xc0982d  daddu       $s3, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160FB0u; }
        if (ctx->pc != 0x160FB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160FB0u; }
        if (ctx->pc != 0x160FB0u) { return; }
    }
    ctx->pc = 0x160FB0u;
label_160fb0:
    // 0x160fb0: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x160FB0u;
    {
        const bool branch_taken_0x160fb0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x160fb0) {
            ctx->pc = 0x160FB4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x160FB0u;
            // 0x160fb4: 0x8e420000  lw          $v0, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x160FD0u;
            goto label_160fd0;
        }
    }
    ctx->pc = 0x160FB8u;
    // 0x160fb8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x160fb8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x160fbc: 0xc058dd4  jal         func_163750
    ctx->pc = 0x160FBCu;
    SET_GPR_U32(ctx, 31, 0x160FC4u);
    ctx->pc = 0x160FC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160FBCu;
            // 0x160fc0: 0x2484f940  addiu       $a0, $a0, -0x6C0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294965568));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160FC4u; }
        if (ctx->pc != 0x160FC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160FC4u; }
        if (ctx->pc != 0x160FC4u) { return; }
    }
    ctx->pc = 0x160FC4u;
label_160fc4:
    // 0x160fc4: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x160FC4u;
    {
        const bool branch_taken_0x160fc4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x160FC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160FC4u;
            // 0x160fc8: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160fc4) {
            ctx->pc = 0x161018u;
            goto label_161018;
        }
    }
    ctx->pc = 0x160FCCu;
    // 0x160fcc: 0x0  nop
    ctx->pc = 0x160fccu;
    // NOP
label_160fd0:
    // 0x160fd0: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x160FD0u;
    {
        const bool branch_taken_0x160fd0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x160FD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160FD0u;
            // 0x160fd4: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160fd0) {
            ctx->pc = 0x160FE8u;
            goto label_160fe8;
        }
    }
    ctx->pc = 0x160FD8u;
    // 0x160fd8: 0xc058dd4  jal         func_163750
    ctx->pc = 0x160FD8u;
    SET_GPR_U32(ctx, 31, 0x160FE0u);
    ctx->pc = 0x160FDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160FD8u;
            // 0x160fdc: 0x2484f978  addiu       $a0, $a0, -0x688 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294965624));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160FE0u; }
        if (ctx->pc != 0x160FE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160FE0u; }
        if (ctx->pc != 0x160FE0u) { return; }
    }
    ctx->pc = 0x160FE0u;
label_160fe0:
    // 0x160fe0: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x160FE0u;
    {
        const bool branch_taken_0x160fe0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x160FE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160FE0u;
            // 0x160fe4: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160fe0) {
            ctx->pc = 0x161018u;
            goto label_161018;
        }
    }
    ctx->pc = 0x160FE8u;
label_160fe8:
    // 0x160fe8: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x160FE8u;
    SET_GPR_U32(ctx, 31, 0x160FF0u);
    ctx->pc = 0x160FECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160FE8u;
            // 0x160fec: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160FF0u; }
        if (ctx->pc != 0x160FF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160FF0u; }
        if (ctx->pc != 0x160FF0u) { return; }
    }
    ctx->pc = 0x160FF0u;
label_160ff0:
    // 0x160ff0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x160ff0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160ff4: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x160ff4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160ff8: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x160ff8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160ffc: 0xc0582ee  jal         func_160BB8
    ctx->pc = 0x160FFCu;
    SET_GPR_U32(ctx, 31, 0x161004u);
    ctx->pc = 0x161000u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160FFCu;
            // 0x161000: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160BB8u;
    if (runtime->hasFunction(0x160BB8u)) {
        auto targetFn = runtime->lookupFunction(0x160BB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161004u; }
        if (ctx->pc != 0x161004u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160BB8_0x160bb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161004u; }
        if (ctx->pc != 0x161004u) { return; }
    }
    ctx->pc = 0x161004u;
label_161004:
    // 0x161004: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x161004u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161008: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x161008u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16100c: 0xc05ea06  jal         func_17A818
    ctx->pc = 0x16100Cu;
    SET_GPR_U32(ctx, 31, 0x161014u);
    ctx->pc = 0x161010u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16100Cu;
            // 0x161010: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17A818u;
    if (runtime->hasFunction(0x17A818u)) {
        auto targetFn = runtime->lookupFunction(0x17A818u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161014u; }
        if (ctx->pc != 0x161014u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A818_0x17a818(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161014u; }
        if (ctx->pc != 0x161014u) { return; }
    }
    ctx->pc = 0x161014u;
label_161014:
    // 0x161014: 0xdfb00090  ld          $s0, 0x90($sp)
    ctx->pc = 0x161014u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
label_161018:
    // 0x161018: 0xdfb10098  ld          $s1, 0x98($sp)
    ctx->pc = 0x161018u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x16101c: 0xdfb200a0  ld          $s2, 0xA0($sp)
    ctx->pc = 0x16101cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x161020: 0xdfb300a8  ld          $s3, 0xA8($sp)
    ctx->pc = 0x161020u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x161024: 0xdfbf00b0  ld          $ra, 0xB0($sp)
    ctx->pc = 0x161024u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x161028: 0x3e00008  jr          $ra
    ctx->pc = 0x161028u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16102Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161028u;
            // 0x16102c: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x160F30u: goto label_160f30;
            case 0x160F38u: goto label_160f38;
            case 0x160F40u: goto label_160f40;
            case 0x160F44u: goto label_160f44;
            case 0x160FB0u: goto label_160fb0;
            case 0x160FC4u: goto label_160fc4;
            case 0x160FD0u: goto label_160fd0;
            case 0x160FE0u: goto label_160fe0;
            case 0x160FE8u: goto label_160fe8;
            case 0x160FF0u: goto label_160ff0;
            case 0x161004u: goto label_161004;
            case 0x161014u: goto label_161014;
            case 0x161018u: goto label_161018;
            case 0x161058u: goto label_161058;
            case 0x16106Cu: goto label_16106c;
            case 0x161078u: goto label_161078;
            case 0x161088u: goto label_161088;
            case 0x161090u: goto label_161090;
            case 0x161098u: goto label_161098;
            case 0x1610ACu: goto label_1610ac;
            case 0x1610BCu: goto label_1610bc;
            case 0x1610C0u: goto label_1610c0;
            case 0x161108u: goto label_161108;
            case 0x16111Cu: goto label_16111c;
            case 0x161128u: goto label_161128;
            case 0x16113Cu: goto label_16113c;
            case 0x161148u: goto label_161148;
            case 0x161150u: goto label_161150;
            case 0x161164u: goto label_161164;
            case 0x161178u: goto label_161178;
            case 0x16117Cu: goto label_16117c;
            case 0x1611C0u: goto label_1611c0;
            case 0x1611D4u: goto label_1611d4;
            case 0x1611E0u: goto label_1611e0;
            case 0x1611F0u: goto label_1611f0;
            case 0x1611F8u: goto label_1611f8;
            case 0x161200u: goto label_161200;
            case 0x161214u: goto label_161214;
            case 0x161224u: goto label_161224;
            case 0x161228u: goto label_161228;
            case 0x161268u: goto label_161268;
            case 0x16127Cu: goto label_16127c;
            case 0x161288u: goto label_161288;
            case 0x161298u: goto label_161298;
            case 0x1612A0u: goto label_1612a0;
            case 0x1612A8u: goto label_1612a8;
            case 0x1612BCu: goto label_1612bc;
            case 0x1612CCu: goto label_1612cc;
            case 0x1612D0u: goto label_1612d0;
            case 0x161310u: goto label_161310;
            case 0x161324u: goto label_161324;
            case 0x161330u: goto label_161330;
            case 0x161340u: goto label_161340;
            case 0x161348u: goto label_161348;
            case 0x161350u: goto label_161350;
            case 0x161364u: goto label_161364;
            case 0x161374u: goto label_161374;
            case 0x161378u: goto label_161378;
            case 0x1613B8u: goto label_1613b8;
            case 0x1613CCu: goto label_1613cc;
            case 0x1613D8u: goto label_1613d8;
            case 0x1613E8u: goto label_1613e8;
            case 0x1613F0u: goto label_1613f0;
            case 0x1613F8u: goto label_1613f8;
            case 0x16140Cu: goto label_16140c;
            case 0x16141Cu: goto label_16141c;
            case 0x161420u: goto label_161420;
            case 0x161454u: goto label_161454;
            case 0x161478u: goto label_161478;
            case 0x1614A8u: goto label_1614a8;
            case 0x1614D0u: goto label_1614d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x161030u;
    // 0x161030: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x161030u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x161034: 0xffb10098  sd          $s1, 0x98($sp)
    ctx->pc = 0x161034u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 17));
    // 0x161038: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x161038u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16103c: 0xffb200a0  sd          $s2, 0xA0($sp)
    ctx->pc = 0x16103cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 18));
    // 0x161040: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x161040u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161044: 0xffb300a8  sd          $s3, 0xA8($sp)
    ctx->pc = 0x161044u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 168), GPR_U64(ctx, 19));
    // 0x161048: 0xffb00090  sd          $s0, 0x90($sp)
    ctx->pc = 0x161048u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 16));
    // 0x16104c: 0xffbf00b0  sd          $ra, 0xB0($sp)
    ctx->pc = 0x16104cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 31));
    // 0x161050: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x161050u;
    SET_GPR_U32(ctx, 31, 0x161058u);
    ctx->pc = 0x161054u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161050u;
            // 0x161054: 0xc0982d  daddu       $s3, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161058u; }
        if (ctx->pc != 0x161058u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161058u; }
        if (ctx->pc != 0x161058u) { return; }
    }
    ctx->pc = 0x161058u;
label_161058:
    // 0x161058: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x161058u;
    {
        const bool branch_taken_0x161058 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x161058) {
            ctx->pc = 0x16105Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x161058u;
            // 0x16105c: 0x8e420000  lw          $v0, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x161078u;
            goto label_161078;
        }
    }
    ctx->pc = 0x161060u;
    // 0x161060: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x161060u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x161064: 0xc058dd4  jal         func_163750
    ctx->pc = 0x161064u;
    SET_GPR_U32(ctx, 31, 0x16106Cu);
    ctx->pc = 0x161068u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161064u;
            // 0x161068: 0x2484f9b0  addiu       $a0, $a0, -0x650 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294965680));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16106Cu; }
        if (ctx->pc != 0x16106Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16106Cu; }
        if (ctx->pc != 0x16106Cu) { return; }
    }
    ctx->pc = 0x16106Cu;
label_16106c:
    // 0x16106c: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x16106Cu;
    {
        const bool branch_taken_0x16106c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x161070u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16106Cu;
            // 0x161070: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16106c) {
            ctx->pc = 0x1610C0u;
            goto label_1610c0;
        }
    }
    ctx->pc = 0x161074u;
    // 0x161074: 0x0  nop
    ctx->pc = 0x161074u;
    // NOP
label_161078:
    // 0x161078: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x161078u;
    {
        const bool branch_taken_0x161078 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16107Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161078u;
            // 0x16107c: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161078) {
            ctx->pc = 0x161090u;
            goto label_161090;
        }
    }
    ctx->pc = 0x161080u;
    // 0x161080: 0xc058dd4  jal         func_163750
    ctx->pc = 0x161080u;
    SET_GPR_U32(ctx, 31, 0x161088u);
    ctx->pc = 0x161084u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161080u;
            // 0x161084: 0x2484f9e8  addiu       $a0, $a0, -0x618 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294965736));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161088u; }
        if (ctx->pc != 0x161088u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161088u; }
        if (ctx->pc != 0x161088u) { return; }
    }
    ctx->pc = 0x161088u;
label_161088:
    // 0x161088: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x161088u;
    {
        const bool branch_taken_0x161088 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16108Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161088u;
            // 0x16108c: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161088) {
            ctx->pc = 0x1610C0u;
            goto label_1610c0;
        }
    }
    ctx->pc = 0x161090u;
label_161090:
    // 0x161090: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x161090u;
    SET_GPR_U32(ctx, 31, 0x161098u);
    ctx->pc = 0x161094u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161090u;
            // 0x161094: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161098u; }
        if (ctx->pc != 0x161098u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161098u; }
        if (ctx->pc != 0x161098u) { return; }
    }
    ctx->pc = 0x161098u;
label_161098:
    // 0x161098: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x161098u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16109c: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x16109cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1610a0: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x1610a0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1610a4: 0xc0582ee  jal         func_160BB8
    ctx->pc = 0x1610A4u;
    SET_GPR_U32(ctx, 31, 0x1610ACu);
    ctx->pc = 0x1610A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1610A4u;
            // 0x1610a8: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160BB8u;
    if (runtime->hasFunction(0x160BB8u)) {
        auto targetFn = runtime->lookupFunction(0x160BB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1610ACu; }
        if (ctx->pc != 0x1610ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160BB8_0x160bb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1610ACu; }
        if (ctx->pc != 0x1610ACu) { return; }
    }
    ctx->pc = 0x1610ACu;
label_1610ac:
    // 0x1610ac: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x1610acu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1610b0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1610b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1610b4: 0xc05ee88  jal         func_17BA20
    ctx->pc = 0x1610B4u;
    SET_GPR_U32(ctx, 31, 0x1610BCu);
    ctx->pc = 0x1610B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1610B4u;
            // 0x1610b8: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17BA20u;
    if (runtime->hasFunction(0x17BA20u)) {
        auto targetFn = runtime->lookupFunction(0x17BA20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1610BCu; }
        if (ctx->pc != 0x1610BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017BA20_0x17ba20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1610BCu; }
        if (ctx->pc != 0x1610BCu) { return; }
    }
    ctx->pc = 0x1610BCu;
label_1610bc:
    // 0x1610bc: 0xdfb00090  ld          $s0, 0x90($sp)
    ctx->pc = 0x1610bcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
label_1610c0:
    // 0x1610c0: 0xdfb10098  ld          $s1, 0x98($sp)
    ctx->pc = 0x1610c0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x1610c4: 0xdfb200a0  ld          $s2, 0xA0($sp)
    ctx->pc = 0x1610c4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x1610c8: 0xdfb300a8  ld          $s3, 0xA8($sp)
    ctx->pc = 0x1610c8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x1610cc: 0xdfbf00b0  ld          $ra, 0xB0($sp)
    ctx->pc = 0x1610ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x1610d0: 0x3e00008  jr          $ra
    ctx->pc = 0x1610D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1610D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1610D0u;
            // 0x1610d4: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x160F30u: goto label_160f30;
            case 0x160F38u: goto label_160f38;
            case 0x160F40u: goto label_160f40;
            case 0x160F44u: goto label_160f44;
            case 0x160FB0u: goto label_160fb0;
            case 0x160FC4u: goto label_160fc4;
            case 0x160FD0u: goto label_160fd0;
            case 0x160FE0u: goto label_160fe0;
            case 0x160FE8u: goto label_160fe8;
            case 0x160FF0u: goto label_160ff0;
            case 0x161004u: goto label_161004;
            case 0x161014u: goto label_161014;
            case 0x161018u: goto label_161018;
            case 0x161058u: goto label_161058;
            case 0x16106Cu: goto label_16106c;
            case 0x161078u: goto label_161078;
            case 0x161088u: goto label_161088;
            case 0x161090u: goto label_161090;
            case 0x161098u: goto label_161098;
            case 0x1610ACu: goto label_1610ac;
            case 0x1610BCu: goto label_1610bc;
            case 0x1610C0u: goto label_1610c0;
            case 0x161108u: goto label_161108;
            case 0x16111Cu: goto label_16111c;
            case 0x161128u: goto label_161128;
            case 0x16113Cu: goto label_16113c;
            case 0x161148u: goto label_161148;
            case 0x161150u: goto label_161150;
            case 0x161164u: goto label_161164;
            case 0x161178u: goto label_161178;
            case 0x16117Cu: goto label_16117c;
            case 0x1611C0u: goto label_1611c0;
            case 0x1611D4u: goto label_1611d4;
            case 0x1611E0u: goto label_1611e0;
            case 0x1611F0u: goto label_1611f0;
            case 0x1611F8u: goto label_1611f8;
            case 0x161200u: goto label_161200;
            case 0x161214u: goto label_161214;
            case 0x161224u: goto label_161224;
            case 0x161228u: goto label_161228;
            case 0x161268u: goto label_161268;
            case 0x16127Cu: goto label_16127c;
            case 0x161288u: goto label_161288;
            case 0x161298u: goto label_161298;
            case 0x1612A0u: goto label_1612a0;
            case 0x1612A8u: goto label_1612a8;
            case 0x1612BCu: goto label_1612bc;
            case 0x1612CCu: goto label_1612cc;
            case 0x1612D0u: goto label_1612d0;
            case 0x161310u: goto label_161310;
            case 0x161324u: goto label_161324;
            case 0x161330u: goto label_161330;
            case 0x161340u: goto label_161340;
            case 0x161348u: goto label_161348;
            case 0x161350u: goto label_161350;
            case 0x161364u: goto label_161364;
            case 0x161374u: goto label_161374;
            case 0x161378u: goto label_161378;
            case 0x1613B8u: goto label_1613b8;
            case 0x1613CCu: goto label_1613cc;
            case 0x1613D8u: goto label_1613d8;
            case 0x1613E8u: goto label_1613e8;
            case 0x1613F0u: goto label_1613f0;
            case 0x1613F8u: goto label_1613f8;
            case 0x16140Cu: goto label_16140c;
            case 0x16141Cu: goto label_16141c;
            case 0x161420u: goto label_161420;
            case 0x161454u: goto label_161454;
            case 0x161478u: goto label_161478;
            case 0x1614A8u: goto label_1614a8;
            case 0x1614D0u: goto label_1614d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1610D8u;
    // 0x1610d8: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x1610d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x1610dc: 0xffb10098  sd          $s1, 0x98($sp)
    ctx->pc = 0x1610dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 17));
    // 0x1610e0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1610e0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1610e4: 0xffb200a0  sd          $s2, 0xA0($sp)
    ctx->pc = 0x1610e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 18));
    // 0x1610e8: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1610e8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1610ec: 0xffb300a8  sd          $s3, 0xA8($sp)
    ctx->pc = 0x1610ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 168), GPR_U64(ctx, 19));
    // 0x1610f0: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x1610f0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1610f4: 0xffb400b0  sd          $s4, 0xB0($sp)
    ctx->pc = 0x1610f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 20));
    // 0x1610f8: 0xffb00090  sd          $s0, 0x90($sp)
    ctx->pc = 0x1610f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 16));
    // 0x1610fc: 0xffbf00b8  sd          $ra, 0xB8($sp)
    ctx->pc = 0x1610fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 184), GPR_U64(ctx, 31));
    // 0x161100: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x161100u;
    SET_GPR_U32(ctx, 31, 0x161108u);
    ctx->pc = 0x161104u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161100u;
            // 0x161104: 0xe0a02d  daddu       $s4, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161108u; }
        if (ctx->pc != 0x161108u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161108u; }
        if (ctx->pc != 0x161108u) { return; }
    }
    ctx->pc = 0x161108u;
label_161108:
    // 0x161108: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x161108u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x16110c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x16110Cu;
    {
        const bool branch_taken_0x16110c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x161110u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16110Cu;
            // 0x161110: 0x2484fa18  addiu       $a0, $a0, -0x5E8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294965784));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16110c) {
            ctx->pc = 0x161128u;
            goto label_161128;
        }
    }
    ctx->pc = 0x161114u;
    // 0x161114: 0xc058dd4  jal         func_163750
    ctx->pc = 0x161114u;
    SET_GPR_U32(ctx, 31, 0x16111Cu);
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16111Cu; }
        if (ctx->pc != 0x16111Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16111Cu; }
        if (ctx->pc != 0x16111Cu) { return; }
    }
    ctx->pc = 0x16111Cu;
label_16111c:
    // 0x16111c: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x16111Cu;
    {
        const bool branch_taken_0x16111c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x161120u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16111Cu;
            // 0x161120: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16111c) {
            ctx->pc = 0x16117Cu;
            goto label_16117c;
        }
    }
    ctx->pc = 0x161124u;
    // 0x161124: 0x0  nop
    ctx->pc = 0x161124u;
    // NOP
label_161128:
    // 0x161128: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x161128u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x16112c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x16112Cu;
    {
        const bool branch_taken_0x16112c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x161130u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16112Cu;
            // 0x161130: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16112c) {
            ctx->pc = 0x161148u;
            goto label_161148;
        }
    }
    ctx->pc = 0x161134u;
    // 0x161134: 0xc058dd4  jal         func_163750
    ctx->pc = 0x161134u;
    SET_GPR_U32(ctx, 31, 0x16113Cu);
    ctx->pc = 0x161138u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161134u;
            // 0x161138: 0x2484fa50  addiu       $a0, $a0, -0x5B0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294965840));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16113Cu; }
        if (ctx->pc != 0x16113Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16113Cu; }
        if (ctx->pc != 0x16113Cu) { return; }
    }
    ctx->pc = 0x16113Cu;
label_16113c:
    // 0x16113c: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x16113Cu;
    {
        const bool branch_taken_0x16113c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x161140u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16113Cu;
            // 0x161140: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16113c) {
            ctx->pc = 0x16117Cu;
            goto label_16117c;
        }
    }
    ctx->pc = 0x161144u;
    // 0x161144: 0x0  nop
    ctx->pc = 0x161144u;
    // NOP
label_161148:
    // 0x161148: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x161148u;
    SET_GPR_U32(ctx, 31, 0x161150u);
    ctx->pc = 0x16114Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161148u;
            // 0x16114c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161150u; }
        if (ctx->pc != 0x161150u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161150u; }
        if (ctx->pc != 0x161150u) { return; }
    }
    ctx->pc = 0x161150u;
label_161150:
    // 0x161150: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x161150u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161154: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x161154u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161158: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x161158u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16115c: 0xc0582ee  jal         func_160BB8
    ctx->pc = 0x16115Cu;
    SET_GPR_U32(ctx, 31, 0x161164u);
    ctx->pc = 0x161160u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16115Cu;
            // 0x161160: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160BB8u;
    if (runtime->hasFunction(0x160BB8u)) {
        auto targetFn = runtime->lookupFunction(0x160BB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161164u; }
        if (ctx->pc != 0x161164u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160BB8_0x160bb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161164u; }
        if (ctx->pc != 0x161164u) { return; }
    }
    ctx->pc = 0x161164u;
label_161164:
    // 0x161164: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x161164u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161168: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x161168u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16116c: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x16116cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161170: 0xc05efb6  jal         func_17BED8
    ctx->pc = 0x161170u;
    SET_GPR_U32(ctx, 31, 0x161178u);
    ctx->pc = 0x161174u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161170u;
            // 0x161174: 0x280382d  daddu       $a3, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17BED8u;
    if (runtime->hasFunction(0x17BED8u)) {
        auto targetFn = runtime->lookupFunction(0x17BED8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161178u; }
        if (ctx->pc != 0x161178u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017BED8_0x17bed8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161178u; }
        if (ctx->pc != 0x161178u) { return; }
    }
    ctx->pc = 0x161178u;
label_161178:
    // 0x161178: 0xdfb00090  ld          $s0, 0x90($sp)
    ctx->pc = 0x161178u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
label_16117c:
    // 0x16117c: 0xdfb10098  ld          $s1, 0x98($sp)
    ctx->pc = 0x16117cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x161180: 0xdfb200a0  ld          $s2, 0xA0($sp)
    ctx->pc = 0x161180u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x161184: 0xdfb300a8  ld          $s3, 0xA8($sp)
    ctx->pc = 0x161184u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x161188: 0xdfb400b0  ld          $s4, 0xB0($sp)
    ctx->pc = 0x161188u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x16118c: 0xdfbf00b8  ld          $ra, 0xB8($sp)
    ctx->pc = 0x16118cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 184)));
    // 0x161190: 0x3e00008  jr          $ra
    ctx->pc = 0x161190u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x161194u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161190u;
            // 0x161194: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x160F30u: goto label_160f30;
            case 0x160F38u: goto label_160f38;
            case 0x160F40u: goto label_160f40;
            case 0x160F44u: goto label_160f44;
            case 0x160FB0u: goto label_160fb0;
            case 0x160FC4u: goto label_160fc4;
            case 0x160FD0u: goto label_160fd0;
            case 0x160FE0u: goto label_160fe0;
            case 0x160FE8u: goto label_160fe8;
            case 0x160FF0u: goto label_160ff0;
            case 0x161004u: goto label_161004;
            case 0x161014u: goto label_161014;
            case 0x161018u: goto label_161018;
            case 0x161058u: goto label_161058;
            case 0x16106Cu: goto label_16106c;
            case 0x161078u: goto label_161078;
            case 0x161088u: goto label_161088;
            case 0x161090u: goto label_161090;
            case 0x161098u: goto label_161098;
            case 0x1610ACu: goto label_1610ac;
            case 0x1610BCu: goto label_1610bc;
            case 0x1610C0u: goto label_1610c0;
            case 0x161108u: goto label_161108;
            case 0x16111Cu: goto label_16111c;
            case 0x161128u: goto label_161128;
            case 0x16113Cu: goto label_16113c;
            case 0x161148u: goto label_161148;
            case 0x161150u: goto label_161150;
            case 0x161164u: goto label_161164;
            case 0x161178u: goto label_161178;
            case 0x16117Cu: goto label_16117c;
            case 0x1611C0u: goto label_1611c0;
            case 0x1611D4u: goto label_1611d4;
            case 0x1611E0u: goto label_1611e0;
            case 0x1611F0u: goto label_1611f0;
            case 0x1611F8u: goto label_1611f8;
            case 0x161200u: goto label_161200;
            case 0x161214u: goto label_161214;
            case 0x161224u: goto label_161224;
            case 0x161228u: goto label_161228;
            case 0x161268u: goto label_161268;
            case 0x16127Cu: goto label_16127c;
            case 0x161288u: goto label_161288;
            case 0x161298u: goto label_161298;
            case 0x1612A0u: goto label_1612a0;
            case 0x1612A8u: goto label_1612a8;
            case 0x1612BCu: goto label_1612bc;
            case 0x1612CCu: goto label_1612cc;
            case 0x1612D0u: goto label_1612d0;
            case 0x161310u: goto label_161310;
            case 0x161324u: goto label_161324;
            case 0x161330u: goto label_161330;
            case 0x161340u: goto label_161340;
            case 0x161348u: goto label_161348;
            case 0x161350u: goto label_161350;
            case 0x161364u: goto label_161364;
            case 0x161374u: goto label_161374;
            case 0x161378u: goto label_161378;
            case 0x1613B8u: goto label_1613b8;
            case 0x1613CCu: goto label_1613cc;
            case 0x1613D8u: goto label_1613d8;
            case 0x1613E8u: goto label_1613e8;
            case 0x1613F0u: goto label_1613f0;
            case 0x1613F8u: goto label_1613f8;
            case 0x16140Cu: goto label_16140c;
            case 0x16141Cu: goto label_16141c;
            case 0x161420u: goto label_161420;
            case 0x161454u: goto label_161454;
            case 0x161478u: goto label_161478;
            case 0x1614A8u: goto label_1614a8;
            case 0x1614D0u: goto label_1614d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x161198u;
    // 0x161198: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x161198u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x16119c: 0xffb10098  sd          $s1, 0x98($sp)
    ctx->pc = 0x16119cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 17));
    // 0x1611a0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1611a0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1611a4: 0xffb200a0  sd          $s2, 0xA0($sp)
    ctx->pc = 0x1611a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 18));
    // 0x1611a8: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1611a8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1611ac: 0xffb300a8  sd          $s3, 0xA8($sp)
    ctx->pc = 0x1611acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 168), GPR_U64(ctx, 19));
    // 0x1611b0: 0xffb00090  sd          $s0, 0x90($sp)
    ctx->pc = 0x1611b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 16));
    // 0x1611b4: 0xffbf00b0  sd          $ra, 0xB0($sp)
    ctx->pc = 0x1611b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 31));
    // 0x1611b8: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x1611B8u;
    SET_GPR_U32(ctx, 31, 0x1611C0u);
    ctx->pc = 0x1611BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1611B8u;
            // 0x1611bc: 0xc0982d  daddu       $s3, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1611C0u; }
        if (ctx->pc != 0x1611C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1611C0u; }
        if (ctx->pc != 0x1611C0u) { return; }
    }
    ctx->pc = 0x1611C0u;
label_1611c0:
    // 0x1611c0: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x1611C0u;
    {
        const bool branch_taken_0x1611c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1611c0) {
            ctx->pc = 0x1611C4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1611C0u;
            // 0x1611c4: 0x8e420000  lw          $v0, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1611E0u;
            goto label_1611e0;
        }
    }
    ctx->pc = 0x1611C8u;
    // 0x1611c8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1611c8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1611cc: 0xc058dd4  jal         func_163750
    ctx->pc = 0x1611CCu;
    SET_GPR_U32(ctx, 31, 0x1611D4u);
    ctx->pc = 0x1611D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1611CCu;
            // 0x1611d0: 0x2484fa88  addiu       $a0, $a0, -0x578 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294965896));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1611D4u; }
        if (ctx->pc != 0x1611D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1611D4u; }
        if (ctx->pc != 0x1611D4u) { return; }
    }
    ctx->pc = 0x1611D4u;
label_1611d4:
    // 0x1611d4: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1611D4u;
    {
        const bool branch_taken_0x1611d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1611D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1611D4u;
            // 0x1611d8: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1611d4) {
            ctx->pc = 0x161228u;
            goto label_161228;
        }
    }
    ctx->pc = 0x1611DCu;
    // 0x1611dc: 0x0  nop
    ctx->pc = 0x1611dcu;
    // NOP
label_1611e0:
    // 0x1611e0: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1611E0u;
    {
        const bool branch_taken_0x1611e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1611E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1611E0u;
            // 0x1611e4: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1611e0) {
            ctx->pc = 0x1611F8u;
            goto label_1611f8;
        }
    }
    ctx->pc = 0x1611E8u;
    // 0x1611e8: 0xc058dd4  jal         func_163750
    ctx->pc = 0x1611E8u;
    SET_GPR_U32(ctx, 31, 0x1611F0u);
    ctx->pc = 0x1611ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1611E8u;
            // 0x1611ec: 0x2484fac0  addiu       $a0, $a0, -0x540 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294965952));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1611F0u; }
        if (ctx->pc != 0x1611F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1611F0u; }
        if (ctx->pc != 0x1611F0u) { return; }
    }
    ctx->pc = 0x1611F0u;
label_1611f0:
    // 0x1611f0: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1611F0u;
    {
        const bool branch_taken_0x1611f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1611F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1611F0u;
            // 0x1611f4: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1611f0) {
            ctx->pc = 0x161228u;
            goto label_161228;
        }
    }
    ctx->pc = 0x1611F8u;
label_1611f8:
    // 0x1611f8: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x1611F8u;
    SET_GPR_U32(ctx, 31, 0x161200u);
    ctx->pc = 0x1611FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1611F8u;
            // 0x1611fc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161200u; }
        if (ctx->pc != 0x161200u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161200u; }
        if (ctx->pc != 0x161200u) { return; }
    }
    ctx->pc = 0x161200u;
label_161200:
    // 0x161200: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x161200u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161204: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x161204u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161208: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x161208u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16120c: 0xc0582ee  jal         func_160BB8
    ctx->pc = 0x16120Cu;
    SET_GPR_U32(ctx, 31, 0x161214u);
    ctx->pc = 0x161210u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16120Cu;
            // 0x161210: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160BB8u;
    if (runtime->hasFunction(0x160BB8u)) {
        auto targetFn = runtime->lookupFunction(0x160BB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161214u; }
        if (ctx->pc != 0x161214u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160BB8_0x160bb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161214u; }
        if (ctx->pc != 0x161214u) { return; }
    }
    ctx->pc = 0x161214u;
label_161214:
    // 0x161214: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x161214u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161218: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x161218u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16121c: 0xc05ed4c  jal         func_17B530
    ctx->pc = 0x16121Cu;
    SET_GPR_U32(ctx, 31, 0x161224u);
    ctx->pc = 0x161220u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16121Cu;
            // 0x161220: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17B530u;
    if (runtime->hasFunction(0x17B530u)) {
        auto targetFn = runtime->lookupFunction(0x17B530u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161224u; }
        if (ctx->pc != 0x161224u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017B530_0x17b530(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161224u; }
        if (ctx->pc != 0x161224u) { return; }
    }
    ctx->pc = 0x161224u;
label_161224:
    // 0x161224: 0xdfb00090  ld          $s0, 0x90($sp)
    ctx->pc = 0x161224u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
label_161228:
    // 0x161228: 0xdfb10098  ld          $s1, 0x98($sp)
    ctx->pc = 0x161228u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x16122c: 0xdfb200a0  ld          $s2, 0xA0($sp)
    ctx->pc = 0x16122cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x161230: 0xdfb300a8  ld          $s3, 0xA8($sp)
    ctx->pc = 0x161230u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x161234: 0xdfbf00b0  ld          $ra, 0xB0($sp)
    ctx->pc = 0x161234u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x161238: 0x3e00008  jr          $ra
    ctx->pc = 0x161238u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16123Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161238u;
            // 0x16123c: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x160F30u: goto label_160f30;
            case 0x160F38u: goto label_160f38;
            case 0x160F40u: goto label_160f40;
            case 0x160F44u: goto label_160f44;
            case 0x160FB0u: goto label_160fb0;
            case 0x160FC4u: goto label_160fc4;
            case 0x160FD0u: goto label_160fd0;
            case 0x160FE0u: goto label_160fe0;
            case 0x160FE8u: goto label_160fe8;
            case 0x160FF0u: goto label_160ff0;
            case 0x161004u: goto label_161004;
            case 0x161014u: goto label_161014;
            case 0x161018u: goto label_161018;
            case 0x161058u: goto label_161058;
            case 0x16106Cu: goto label_16106c;
            case 0x161078u: goto label_161078;
            case 0x161088u: goto label_161088;
            case 0x161090u: goto label_161090;
            case 0x161098u: goto label_161098;
            case 0x1610ACu: goto label_1610ac;
            case 0x1610BCu: goto label_1610bc;
            case 0x1610C0u: goto label_1610c0;
            case 0x161108u: goto label_161108;
            case 0x16111Cu: goto label_16111c;
            case 0x161128u: goto label_161128;
            case 0x16113Cu: goto label_16113c;
            case 0x161148u: goto label_161148;
            case 0x161150u: goto label_161150;
            case 0x161164u: goto label_161164;
            case 0x161178u: goto label_161178;
            case 0x16117Cu: goto label_16117c;
            case 0x1611C0u: goto label_1611c0;
            case 0x1611D4u: goto label_1611d4;
            case 0x1611E0u: goto label_1611e0;
            case 0x1611F0u: goto label_1611f0;
            case 0x1611F8u: goto label_1611f8;
            case 0x161200u: goto label_161200;
            case 0x161214u: goto label_161214;
            case 0x161224u: goto label_161224;
            case 0x161228u: goto label_161228;
            case 0x161268u: goto label_161268;
            case 0x16127Cu: goto label_16127c;
            case 0x161288u: goto label_161288;
            case 0x161298u: goto label_161298;
            case 0x1612A0u: goto label_1612a0;
            case 0x1612A8u: goto label_1612a8;
            case 0x1612BCu: goto label_1612bc;
            case 0x1612CCu: goto label_1612cc;
            case 0x1612D0u: goto label_1612d0;
            case 0x161310u: goto label_161310;
            case 0x161324u: goto label_161324;
            case 0x161330u: goto label_161330;
            case 0x161340u: goto label_161340;
            case 0x161348u: goto label_161348;
            case 0x161350u: goto label_161350;
            case 0x161364u: goto label_161364;
            case 0x161374u: goto label_161374;
            case 0x161378u: goto label_161378;
            case 0x1613B8u: goto label_1613b8;
            case 0x1613CCu: goto label_1613cc;
            case 0x1613D8u: goto label_1613d8;
            case 0x1613E8u: goto label_1613e8;
            case 0x1613F0u: goto label_1613f0;
            case 0x1613F8u: goto label_1613f8;
            case 0x16140Cu: goto label_16140c;
            case 0x16141Cu: goto label_16141c;
            case 0x161420u: goto label_161420;
            case 0x161454u: goto label_161454;
            case 0x161478u: goto label_161478;
            case 0x1614A8u: goto label_1614a8;
            case 0x1614D0u: goto label_1614d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x161240u;
    // 0x161240: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x161240u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x161244: 0xffb10098  sd          $s1, 0x98($sp)
    ctx->pc = 0x161244u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 17));
    // 0x161248: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x161248u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16124c: 0xffb200a0  sd          $s2, 0xA0($sp)
    ctx->pc = 0x16124cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 18));
    // 0x161250: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x161250u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161254: 0xffb300a8  sd          $s3, 0xA8($sp)
    ctx->pc = 0x161254u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 168), GPR_U64(ctx, 19));
    // 0x161258: 0xffb00090  sd          $s0, 0x90($sp)
    ctx->pc = 0x161258u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 16));
    // 0x16125c: 0xffbf00b0  sd          $ra, 0xB0($sp)
    ctx->pc = 0x16125cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 31));
    // 0x161260: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x161260u;
    SET_GPR_U32(ctx, 31, 0x161268u);
    ctx->pc = 0x161264u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161260u;
            // 0x161264: 0xc0982d  daddu       $s3, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161268u; }
        if (ctx->pc != 0x161268u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161268u; }
        if (ctx->pc != 0x161268u) { return; }
    }
    ctx->pc = 0x161268u;
label_161268:
    // 0x161268: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x161268u;
    {
        const bool branch_taken_0x161268 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x161268) {
            ctx->pc = 0x16126Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x161268u;
            // 0x16126c: 0x8e420000  lw          $v0, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x161288u;
            goto label_161288;
        }
    }
    ctx->pc = 0x161270u;
    // 0x161270: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x161270u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x161274: 0xc058dd4  jal         func_163750
    ctx->pc = 0x161274u;
    SET_GPR_U32(ctx, 31, 0x16127Cu);
    ctx->pc = 0x161278u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161274u;
            // 0x161278: 0x2484faf8  addiu       $a0, $a0, -0x508 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966008));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16127Cu; }
        if (ctx->pc != 0x16127Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16127Cu; }
        if (ctx->pc != 0x16127Cu) { return; }
    }
    ctx->pc = 0x16127Cu;
label_16127c:
    // 0x16127c: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x16127Cu;
    {
        const bool branch_taken_0x16127c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x161280u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16127Cu;
            // 0x161280: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16127c) {
            ctx->pc = 0x1612D0u;
            goto label_1612d0;
        }
    }
    ctx->pc = 0x161284u;
    // 0x161284: 0x0  nop
    ctx->pc = 0x161284u;
    // NOP
label_161288:
    // 0x161288: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x161288u;
    {
        const bool branch_taken_0x161288 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16128Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161288u;
            // 0x16128c: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161288) {
            ctx->pc = 0x1612A0u;
            goto label_1612a0;
        }
    }
    ctx->pc = 0x161290u;
    // 0x161290: 0xc058dd4  jal         func_163750
    ctx->pc = 0x161290u;
    SET_GPR_U32(ctx, 31, 0x161298u);
    ctx->pc = 0x161294u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161290u;
            // 0x161294: 0x2484fb30  addiu       $a0, $a0, -0x4D0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966064));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161298u; }
        if (ctx->pc != 0x161298u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161298u; }
        if (ctx->pc != 0x161298u) { return; }
    }
    ctx->pc = 0x161298u;
label_161298:
    // 0x161298: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x161298u;
    {
        const bool branch_taken_0x161298 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16129Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161298u;
            // 0x16129c: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161298) {
            ctx->pc = 0x1612D0u;
            goto label_1612d0;
        }
    }
    ctx->pc = 0x1612A0u;
label_1612a0:
    // 0x1612a0: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x1612A0u;
    SET_GPR_U32(ctx, 31, 0x1612A8u);
    ctx->pc = 0x1612A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1612A0u;
            // 0x1612a4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1612A8u; }
        if (ctx->pc != 0x1612A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1612A8u; }
        if (ctx->pc != 0x1612A8u) { return; }
    }
    ctx->pc = 0x1612A8u;
label_1612a8:
    // 0x1612a8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1612a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1612ac: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1612acu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1612b0: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x1612b0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1612b4: 0xc0582ee  jal         func_160BB8
    ctx->pc = 0x1612B4u;
    SET_GPR_U32(ctx, 31, 0x1612BCu);
    ctx->pc = 0x1612B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1612B4u;
            // 0x1612b8: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160BB8u;
    if (runtime->hasFunction(0x160BB8u)) {
        auto targetFn = runtime->lookupFunction(0x160BB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1612BCu; }
        if (ctx->pc != 0x1612BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160BB8_0x160bb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1612BCu; }
        if (ctx->pc != 0x1612BCu) { return; }
    }
    ctx->pc = 0x1612BCu;
label_1612bc:
    // 0x1612bc: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x1612bcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1612c0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1612c0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1612c4: 0xc05f284  jal         func_17CA10
    ctx->pc = 0x1612C4u;
    SET_GPR_U32(ctx, 31, 0x1612CCu);
    ctx->pc = 0x1612C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1612C4u;
            // 0x1612c8: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17CA10u;
    if (runtime->hasFunction(0x17CA10u)) {
        auto targetFn = runtime->lookupFunction(0x17CA10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1612CCu; }
        if (ctx->pc != 0x1612CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017CA10_0x17ca10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1612CCu; }
        if (ctx->pc != 0x1612CCu) { return; }
    }
    ctx->pc = 0x1612CCu;
label_1612cc:
    // 0x1612cc: 0xdfb00090  ld          $s0, 0x90($sp)
    ctx->pc = 0x1612ccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
label_1612d0:
    // 0x1612d0: 0xdfb10098  ld          $s1, 0x98($sp)
    ctx->pc = 0x1612d0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x1612d4: 0xdfb200a0  ld          $s2, 0xA0($sp)
    ctx->pc = 0x1612d4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x1612d8: 0xdfb300a8  ld          $s3, 0xA8($sp)
    ctx->pc = 0x1612d8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x1612dc: 0xdfbf00b0  ld          $ra, 0xB0($sp)
    ctx->pc = 0x1612dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x1612e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1612E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1612E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1612E0u;
            // 0x1612e4: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x160F30u: goto label_160f30;
            case 0x160F38u: goto label_160f38;
            case 0x160F40u: goto label_160f40;
            case 0x160F44u: goto label_160f44;
            case 0x160FB0u: goto label_160fb0;
            case 0x160FC4u: goto label_160fc4;
            case 0x160FD0u: goto label_160fd0;
            case 0x160FE0u: goto label_160fe0;
            case 0x160FE8u: goto label_160fe8;
            case 0x160FF0u: goto label_160ff0;
            case 0x161004u: goto label_161004;
            case 0x161014u: goto label_161014;
            case 0x161018u: goto label_161018;
            case 0x161058u: goto label_161058;
            case 0x16106Cu: goto label_16106c;
            case 0x161078u: goto label_161078;
            case 0x161088u: goto label_161088;
            case 0x161090u: goto label_161090;
            case 0x161098u: goto label_161098;
            case 0x1610ACu: goto label_1610ac;
            case 0x1610BCu: goto label_1610bc;
            case 0x1610C0u: goto label_1610c0;
            case 0x161108u: goto label_161108;
            case 0x16111Cu: goto label_16111c;
            case 0x161128u: goto label_161128;
            case 0x16113Cu: goto label_16113c;
            case 0x161148u: goto label_161148;
            case 0x161150u: goto label_161150;
            case 0x161164u: goto label_161164;
            case 0x161178u: goto label_161178;
            case 0x16117Cu: goto label_16117c;
            case 0x1611C0u: goto label_1611c0;
            case 0x1611D4u: goto label_1611d4;
            case 0x1611E0u: goto label_1611e0;
            case 0x1611F0u: goto label_1611f0;
            case 0x1611F8u: goto label_1611f8;
            case 0x161200u: goto label_161200;
            case 0x161214u: goto label_161214;
            case 0x161224u: goto label_161224;
            case 0x161228u: goto label_161228;
            case 0x161268u: goto label_161268;
            case 0x16127Cu: goto label_16127c;
            case 0x161288u: goto label_161288;
            case 0x161298u: goto label_161298;
            case 0x1612A0u: goto label_1612a0;
            case 0x1612A8u: goto label_1612a8;
            case 0x1612BCu: goto label_1612bc;
            case 0x1612CCu: goto label_1612cc;
            case 0x1612D0u: goto label_1612d0;
            case 0x161310u: goto label_161310;
            case 0x161324u: goto label_161324;
            case 0x161330u: goto label_161330;
            case 0x161340u: goto label_161340;
            case 0x161348u: goto label_161348;
            case 0x161350u: goto label_161350;
            case 0x161364u: goto label_161364;
            case 0x161374u: goto label_161374;
            case 0x161378u: goto label_161378;
            case 0x1613B8u: goto label_1613b8;
            case 0x1613CCu: goto label_1613cc;
            case 0x1613D8u: goto label_1613d8;
            case 0x1613E8u: goto label_1613e8;
            case 0x1613F0u: goto label_1613f0;
            case 0x1613F8u: goto label_1613f8;
            case 0x16140Cu: goto label_16140c;
            case 0x16141Cu: goto label_16141c;
            case 0x161420u: goto label_161420;
            case 0x161454u: goto label_161454;
            case 0x161478u: goto label_161478;
            case 0x1614A8u: goto label_1614a8;
            case 0x1614D0u: goto label_1614d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1612E8u;
    // 0x1612e8: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x1612e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x1612ec: 0xffb10098  sd          $s1, 0x98($sp)
    ctx->pc = 0x1612ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 17));
    // 0x1612f0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1612f0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1612f4: 0xffb200a0  sd          $s2, 0xA0($sp)
    ctx->pc = 0x1612f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 18));
    // 0x1612f8: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1612f8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1612fc: 0xffb300a8  sd          $s3, 0xA8($sp)
    ctx->pc = 0x1612fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 168), GPR_U64(ctx, 19));
    // 0x161300: 0xffb00090  sd          $s0, 0x90($sp)
    ctx->pc = 0x161300u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 16));
    // 0x161304: 0xffbf00b0  sd          $ra, 0xB0($sp)
    ctx->pc = 0x161304u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 31));
    // 0x161308: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x161308u;
    SET_GPR_U32(ctx, 31, 0x161310u);
    ctx->pc = 0x16130Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161308u;
            // 0x16130c: 0xc0982d  daddu       $s3, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161310u; }
        if (ctx->pc != 0x161310u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161310u; }
        if (ctx->pc != 0x161310u) { return; }
    }
    ctx->pc = 0x161310u;
label_161310:
    // 0x161310: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x161310u;
    {
        const bool branch_taken_0x161310 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x161310) {
            ctx->pc = 0x161314u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x161310u;
            // 0x161314: 0x8e420000  lw          $v0, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x161330u;
            goto label_161330;
        }
    }
    ctx->pc = 0x161318u;
    // 0x161318: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x161318u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x16131c: 0xc058dd4  jal         func_163750
    ctx->pc = 0x16131Cu;
    SET_GPR_U32(ctx, 31, 0x161324u);
    ctx->pc = 0x161320u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16131Cu;
            // 0x161320: 0x2484fb60  addiu       $a0, $a0, -0x4A0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966112));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161324u; }
        if (ctx->pc != 0x161324u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161324u; }
        if (ctx->pc != 0x161324u) { return; }
    }
    ctx->pc = 0x161324u;
label_161324:
    // 0x161324: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x161324u;
    {
        const bool branch_taken_0x161324 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x161328u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161324u;
            // 0x161328: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161324) {
            ctx->pc = 0x161378u;
            goto label_161378;
        }
    }
    ctx->pc = 0x16132Cu;
    // 0x16132c: 0x0  nop
    ctx->pc = 0x16132cu;
    // NOP
label_161330:
    // 0x161330: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x161330u;
    {
        const bool branch_taken_0x161330 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x161334u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161330u;
            // 0x161334: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161330) {
            ctx->pc = 0x161348u;
            goto label_161348;
        }
    }
    ctx->pc = 0x161338u;
    // 0x161338: 0xc058dd4  jal         func_163750
    ctx->pc = 0x161338u;
    SET_GPR_U32(ctx, 31, 0x161340u);
    ctx->pc = 0x16133Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161338u;
            // 0x16133c: 0x2484fb90  addiu       $a0, $a0, -0x470 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966160));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161340u; }
        if (ctx->pc != 0x161340u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161340u; }
        if (ctx->pc != 0x161340u) { return; }
    }
    ctx->pc = 0x161340u;
label_161340:
    // 0x161340: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x161340u;
    {
        const bool branch_taken_0x161340 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x161344u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161340u;
            // 0x161344: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161340) {
            ctx->pc = 0x161378u;
            goto label_161378;
        }
    }
    ctx->pc = 0x161348u;
label_161348:
    // 0x161348: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x161348u;
    SET_GPR_U32(ctx, 31, 0x161350u);
    ctx->pc = 0x16134Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161348u;
            // 0x16134c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161350u; }
        if (ctx->pc != 0x161350u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161350u; }
        if (ctx->pc != 0x161350u) { return; }
    }
    ctx->pc = 0x161350u;
label_161350:
    // 0x161350: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x161350u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161354: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x161354u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161358: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x161358u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16135c: 0xc0582ee  jal         func_160BB8
    ctx->pc = 0x16135Cu;
    SET_GPR_U32(ctx, 31, 0x161364u);
    ctx->pc = 0x161360u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16135Cu;
            // 0x161360: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160BB8u;
    if (runtime->hasFunction(0x160BB8u)) {
        auto targetFn = runtime->lookupFunction(0x160BB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161364u; }
        if (ctx->pc != 0x161364u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160BB8_0x160bb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161364u; }
        if (ctx->pc != 0x161364u) { return; }
    }
    ctx->pc = 0x161364u;
label_161364:
    // 0x161364: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x161364u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161368: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x161368u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16136c: 0xc05f040  jal         func_17C100
    ctx->pc = 0x16136Cu;
    SET_GPR_U32(ctx, 31, 0x161374u);
    ctx->pc = 0x161370u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16136Cu;
            // 0x161370: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C100u;
    if (runtime->hasFunction(0x17C100u)) {
        auto targetFn = runtime->lookupFunction(0x17C100u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161374u; }
        if (ctx->pc != 0x161374u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C100_0x17c100(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161374u; }
        if (ctx->pc != 0x161374u) { return; }
    }
    ctx->pc = 0x161374u;
label_161374:
    // 0x161374: 0xdfb00090  ld          $s0, 0x90($sp)
    ctx->pc = 0x161374u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
label_161378:
    // 0x161378: 0xdfb10098  ld          $s1, 0x98($sp)
    ctx->pc = 0x161378u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x16137c: 0xdfb200a0  ld          $s2, 0xA0($sp)
    ctx->pc = 0x16137cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x161380: 0xdfb300a8  ld          $s3, 0xA8($sp)
    ctx->pc = 0x161380u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x161384: 0xdfbf00b0  ld          $ra, 0xB0($sp)
    ctx->pc = 0x161384u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x161388: 0x3e00008  jr          $ra
    ctx->pc = 0x161388u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16138Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161388u;
            // 0x16138c: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x160F30u: goto label_160f30;
            case 0x160F38u: goto label_160f38;
            case 0x160F40u: goto label_160f40;
            case 0x160F44u: goto label_160f44;
            case 0x160FB0u: goto label_160fb0;
            case 0x160FC4u: goto label_160fc4;
            case 0x160FD0u: goto label_160fd0;
            case 0x160FE0u: goto label_160fe0;
            case 0x160FE8u: goto label_160fe8;
            case 0x160FF0u: goto label_160ff0;
            case 0x161004u: goto label_161004;
            case 0x161014u: goto label_161014;
            case 0x161018u: goto label_161018;
            case 0x161058u: goto label_161058;
            case 0x16106Cu: goto label_16106c;
            case 0x161078u: goto label_161078;
            case 0x161088u: goto label_161088;
            case 0x161090u: goto label_161090;
            case 0x161098u: goto label_161098;
            case 0x1610ACu: goto label_1610ac;
            case 0x1610BCu: goto label_1610bc;
            case 0x1610C0u: goto label_1610c0;
            case 0x161108u: goto label_161108;
            case 0x16111Cu: goto label_16111c;
            case 0x161128u: goto label_161128;
            case 0x16113Cu: goto label_16113c;
            case 0x161148u: goto label_161148;
            case 0x161150u: goto label_161150;
            case 0x161164u: goto label_161164;
            case 0x161178u: goto label_161178;
            case 0x16117Cu: goto label_16117c;
            case 0x1611C0u: goto label_1611c0;
            case 0x1611D4u: goto label_1611d4;
            case 0x1611E0u: goto label_1611e0;
            case 0x1611F0u: goto label_1611f0;
            case 0x1611F8u: goto label_1611f8;
            case 0x161200u: goto label_161200;
            case 0x161214u: goto label_161214;
            case 0x161224u: goto label_161224;
            case 0x161228u: goto label_161228;
            case 0x161268u: goto label_161268;
            case 0x16127Cu: goto label_16127c;
            case 0x161288u: goto label_161288;
            case 0x161298u: goto label_161298;
            case 0x1612A0u: goto label_1612a0;
            case 0x1612A8u: goto label_1612a8;
            case 0x1612BCu: goto label_1612bc;
            case 0x1612CCu: goto label_1612cc;
            case 0x1612D0u: goto label_1612d0;
            case 0x161310u: goto label_161310;
            case 0x161324u: goto label_161324;
            case 0x161330u: goto label_161330;
            case 0x161340u: goto label_161340;
            case 0x161348u: goto label_161348;
            case 0x161350u: goto label_161350;
            case 0x161364u: goto label_161364;
            case 0x161374u: goto label_161374;
            case 0x161378u: goto label_161378;
            case 0x1613B8u: goto label_1613b8;
            case 0x1613CCu: goto label_1613cc;
            case 0x1613D8u: goto label_1613d8;
            case 0x1613E8u: goto label_1613e8;
            case 0x1613F0u: goto label_1613f0;
            case 0x1613F8u: goto label_1613f8;
            case 0x16140Cu: goto label_16140c;
            case 0x16141Cu: goto label_16141c;
            case 0x161420u: goto label_161420;
            case 0x161454u: goto label_161454;
            case 0x161478u: goto label_161478;
            case 0x1614A8u: goto label_1614a8;
            case 0x1614D0u: goto label_1614d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x161390u;
    // 0x161390: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x161390u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x161394: 0xffb10098  sd          $s1, 0x98($sp)
    ctx->pc = 0x161394u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 17));
    // 0x161398: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x161398u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16139c: 0xffb200a0  sd          $s2, 0xA0($sp)
    ctx->pc = 0x16139cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 18));
    // 0x1613a0: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1613a0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1613a4: 0xffb300a8  sd          $s3, 0xA8($sp)
    ctx->pc = 0x1613a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 168), GPR_U64(ctx, 19));
    // 0x1613a8: 0xffb00090  sd          $s0, 0x90($sp)
    ctx->pc = 0x1613a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 16));
    // 0x1613ac: 0xffbf00b0  sd          $ra, 0xB0($sp)
    ctx->pc = 0x1613acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 31));
    // 0x1613b0: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x1613B0u;
    SET_GPR_U32(ctx, 31, 0x1613B8u);
    ctx->pc = 0x1613B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1613B0u;
            // 0x1613b4: 0xc0982d  daddu       $s3, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1613B8u; }
        if (ctx->pc != 0x1613B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1613B8u; }
        if (ctx->pc != 0x1613B8u) { return; }
    }
    ctx->pc = 0x1613B8u;
label_1613b8:
    // 0x1613b8: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x1613B8u;
    {
        const bool branch_taken_0x1613b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1613b8) {
            ctx->pc = 0x1613BCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1613B8u;
            // 0x1613bc: 0x8e420000  lw          $v0, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1613D8u;
            goto label_1613d8;
        }
    }
    ctx->pc = 0x1613C0u;
    // 0x1613c0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1613c0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1613c4: 0xc058dd4  jal         func_163750
    ctx->pc = 0x1613C4u;
    SET_GPR_U32(ctx, 31, 0x1613CCu);
    ctx->pc = 0x1613C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1613C4u;
            // 0x1613c8: 0x2484fbc0  addiu       $a0, $a0, -0x440 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966208));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1613CCu; }
        if (ctx->pc != 0x1613CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1613CCu; }
        if (ctx->pc != 0x1613CCu) { return; }
    }
    ctx->pc = 0x1613CCu;
label_1613cc:
    // 0x1613cc: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1613CCu;
    {
        const bool branch_taken_0x1613cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1613D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1613CCu;
            // 0x1613d0: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1613cc) {
            ctx->pc = 0x161420u;
            goto label_161420;
        }
    }
    ctx->pc = 0x1613D4u;
    // 0x1613d4: 0x0  nop
    ctx->pc = 0x1613d4u;
    // NOP
label_1613d8:
    // 0x1613d8: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1613D8u;
    {
        const bool branch_taken_0x1613d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1613DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1613D8u;
            // 0x1613dc: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1613d8) {
            ctx->pc = 0x1613F0u;
            goto label_1613f0;
        }
    }
    ctx->pc = 0x1613E0u;
    // 0x1613e0: 0xc058dd4  jal         func_163750
    ctx->pc = 0x1613E0u;
    SET_GPR_U32(ctx, 31, 0x1613E8u);
    ctx->pc = 0x1613E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1613E0u;
            // 0x1613e4: 0x2484fbf0  addiu       $a0, $a0, -0x410 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1613E8u; }
        if (ctx->pc != 0x1613E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1613E8u; }
        if (ctx->pc != 0x1613E8u) { return; }
    }
    ctx->pc = 0x1613E8u;
label_1613e8:
    // 0x1613e8: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1613E8u;
    {
        const bool branch_taken_0x1613e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1613ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1613E8u;
            // 0x1613ec: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1613e8) {
            ctx->pc = 0x161420u;
            goto label_161420;
        }
    }
    ctx->pc = 0x1613F0u;
label_1613f0:
    // 0x1613f0: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x1613F0u;
    SET_GPR_U32(ctx, 31, 0x1613F8u);
    ctx->pc = 0x1613F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1613F0u;
            // 0x1613f4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1613F8u; }
        if (ctx->pc != 0x1613F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1613F8u; }
        if (ctx->pc != 0x1613F8u) { return; }
    }
    ctx->pc = 0x1613F8u;
label_1613f8:
    // 0x1613f8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1613f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1613fc: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1613fcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161400: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x161400u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161404: 0xc0582ee  jal         func_160BB8
    ctx->pc = 0x161404u;
    SET_GPR_U32(ctx, 31, 0x16140Cu);
    ctx->pc = 0x161408u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161404u;
            // 0x161408: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160BB8u;
    if (runtime->hasFunction(0x160BB8u)) {
        auto targetFn = runtime->lookupFunction(0x160BB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16140Cu; }
        if (ctx->pc != 0x16140Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160BB8_0x160bb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16140Cu; }
        if (ctx->pc != 0x16140Cu) { return; }
    }
    ctx->pc = 0x16140Cu;
label_16140c:
    // 0x16140c: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x16140cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161410: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x161410u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161414: 0xc05f050  jal         func_17C140
    ctx->pc = 0x161414u;
    SET_GPR_U32(ctx, 31, 0x16141Cu);
    ctx->pc = 0x161418u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161414u;
            // 0x161418: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C140u;
    if (runtime->hasFunction(0x17C140u)) {
        auto targetFn = runtime->lookupFunction(0x17C140u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16141Cu; }
        if (ctx->pc != 0x16141Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C140_0x17c140(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16141Cu; }
        if (ctx->pc != 0x16141Cu) { return; }
    }
    ctx->pc = 0x16141Cu;
label_16141c:
    // 0x16141c: 0xdfb00090  ld          $s0, 0x90($sp)
    ctx->pc = 0x16141cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
label_161420:
    // 0x161420: 0xdfb10098  ld          $s1, 0x98($sp)
    ctx->pc = 0x161420u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x161424: 0xdfb200a0  ld          $s2, 0xA0($sp)
    ctx->pc = 0x161424u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x161428: 0xdfb300a8  ld          $s3, 0xA8($sp)
    ctx->pc = 0x161428u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x16142c: 0xdfbf00b0  ld          $ra, 0xB0($sp)
    ctx->pc = 0x16142cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x161430: 0x3e00008  jr          $ra
    ctx->pc = 0x161430u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x161434u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161430u;
            // 0x161434: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x160F30u: goto label_160f30;
            case 0x160F38u: goto label_160f38;
            case 0x160F40u: goto label_160f40;
            case 0x160F44u: goto label_160f44;
            case 0x160FB0u: goto label_160fb0;
            case 0x160FC4u: goto label_160fc4;
            case 0x160FD0u: goto label_160fd0;
            case 0x160FE0u: goto label_160fe0;
            case 0x160FE8u: goto label_160fe8;
            case 0x160FF0u: goto label_160ff0;
            case 0x161004u: goto label_161004;
            case 0x161014u: goto label_161014;
            case 0x161018u: goto label_161018;
            case 0x161058u: goto label_161058;
            case 0x16106Cu: goto label_16106c;
            case 0x161078u: goto label_161078;
            case 0x161088u: goto label_161088;
            case 0x161090u: goto label_161090;
            case 0x161098u: goto label_161098;
            case 0x1610ACu: goto label_1610ac;
            case 0x1610BCu: goto label_1610bc;
            case 0x1610C0u: goto label_1610c0;
            case 0x161108u: goto label_161108;
            case 0x16111Cu: goto label_16111c;
            case 0x161128u: goto label_161128;
            case 0x16113Cu: goto label_16113c;
            case 0x161148u: goto label_161148;
            case 0x161150u: goto label_161150;
            case 0x161164u: goto label_161164;
            case 0x161178u: goto label_161178;
            case 0x16117Cu: goto label_16117c;
            case 0x1611C0u: goto label_1611c0;
            case 0x1611D4u: goto label_1611d4;
            case 0x1611E0u: goto label_1611e0;
            case 0x1611F0u: goto label_1611f0;
            case 0x1611F8u: goto label_1611f8;
            case 0x161200u: goto label_161200;
            case 0x161214u: goto label_161214;
            case 0x161224u: goto label_161224;
            case 0x161228u: goto label_161228;
            case 0x161268u: goto label_161268;
            case 0x16127Cu: goto label_16127c;
            case 0x161288u: goto label_161288;
            case 0x161298u: goto label_161298;
            case 0x1612A0u: goto label_1612a0;
            case 0x1612A8u: goto label_1612a8;
            case 0x1612BCu: goto label_1612bc;
            case 0x1612CCu: goto label_1612cc;
            case 0x1612D0u: goto label_1612d0;
            case 0x161310u: goto label_161310;
            case 0x161324u: goto label_161324;
            case 0x161330u: goto label_161330;
            case 0x161340u: goto label_161340;
            case 0x161348u: goto label_161348;
            case 0x161350u: goto label_161350;
            case 0x161364u: goto label_161364;
            case 0x161374u: goto label_161374;
            case 0x161378u: goto label_161378;
            case 0x1613B8u: goto label_1613b8;
            case 0x1613CCu: goto label_1613cc;
            case 0x1613D8u: goto label_1613d8;
            case 0x1613E8u: goto label_1613e8;
            case 0x1613F0u: goto label_1613f0;
            case 0x1613F8u: goto label_1613f8;
            case 0x16140Cu: goto label_16140c;
            case 0x16141Cu: goto label_16141c;
            case 0x161420u: goto label_161420;
            case 0x161454u: goto label_161454;
            case 0x161478u: goto label_161478;
            case 0x1614A8u: goto label_1614a8;
            case 0x1614D0u: goto label_1614d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x161438u;
    // 0x161438: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x161438u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16143c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16143cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x161440: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x161440u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161444: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x161444u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x161448: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x161448u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x16144c: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x16144Cu;
    SET_GPR_U32(ctx, 31, 0x161454u);
    ctx->pc = 0x161450u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16144Cu;
            // 0x161450: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161454u; }
        if (ctx->pc != 0x161454u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161454u; }
        if (ctx->pc != 0x161454u) { return; }
    }
    ctx->pc = 0x161454u;
label_161454:
    // 0x161454: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x161454u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x161458: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x161458u;
    {
        const bool branch_taken_0x161458 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16145Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161458u;
            // 0x16145c: 0x2484fc20  addiu       $a0, $a0, -0x3E0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966304));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161458) {
            ctx->pc = 0x161478u;
            goto label_161478;
        }
    }
    ctx->pc = 0x161460u;
    // 0x161460: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x161460u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x161464: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x161464u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x161468: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x161468u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16146c: 0x8058dd4  j           func_163750
    ctx->pc = 0x16146Cu;
    ctx->pc = 0x161470u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16146Cu;
            // 0x161470: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x161474u;
    // 0x161474: 0x0  nop
    ctx->pc = 0x161474u;
    // NOP
label_161478:
    // 0x161478: 0x8e2200e8  lw          $v0, 0xE8($s1)
    ctx->pc = 0x161478u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 232)));
    // 0x16147c: 0x14400014  bnez        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x16147Cu;
    {
        const bool branch_taken_0x16147c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x161480u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16147Cu;
            // 0x161480: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16147c) {
            ctx->pc = 0x1614D0u;
            goto label_1614d0;
        }
    }
    ctx->pc = 0x161484u;
    // 0x161484: 0x24020101  addiu       $v0, $zero, 0x101
    ctx->pc = 0x161484u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 257));
    // 0x161488: 0x16020007  bne         $s0, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x161488u;
    {
        const bool branch_taken_0x161488 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        ctx->pc = 0x16148Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161488u;
            // 0x16148c: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161488) {
            ctx->pc = 0x1614A8u;
            goto label_1614a8;
        }
    }
    ctx->pc = 0x161490u;
    // 0x161490: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x161490u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x161494: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x161494u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x161498: 0x2484fc58  addiu       $a0, $a0, -0x3A8
    ctx->pc = 0x161498u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966360));
    // 0x16149c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x16149cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1614a0: 0x8058dd4  j           func_163750
    ctx->pc = 0x1614A0u;
    ctx->pc = 0x1614A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1614A0u;
            // 0x1614a4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1614A8u;
label_1614a8:
    // 0x1614a8: 0x16000009  bnez        $s0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1614A8u;
    {
        const bool branch_taken_0x1614a8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x1614ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1614A8u;
            // 0x1614ac: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1614a8) {
            ctx->pc = 0x1614D0u;
            goto label_1614d0;
        }
    }
    ctx->pc = 0x1614B0u;
    // 0x1614b0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1614b0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1614b4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1614b4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1614b8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1614b8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1614bc: 0x2484fca0  addiu       $a0, $a0, -0x360
    ctx->pc = 0x1614bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966432));
    // 0x1614c0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1614c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1614c4: 0x8058dd4  j           func_163750
    ctx->pc = 0x1614C4u;
    ctx->pc = 0x1614C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1614C4u;
            // 0x1614c8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1614CCu;
    // 0x1614cc: 0x0  nop
    ctx->pc = 0x1614ccu;
    // NOP
label_1614d0:
    // 0x1614d0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1614d0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1614d4: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1614d4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1614d8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1614d8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1614dc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1614dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1614e0: 0x805853a  j           func_1614E8
    ctx->pc = 0x1614E0u;
    ctx->pc = 0x1614E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1614E0u;
            // 0x1614e4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1614E8u;
    if (runtime->hasFunction(0x1614E8u)) {
        auto targetFn = runtime->lookupFunction(0x1614E8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001614E8_0x1614e8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1614E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
